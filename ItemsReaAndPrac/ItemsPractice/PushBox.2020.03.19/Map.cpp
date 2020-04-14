#include "Map.h"
#include "Role.cpp"
#include "Box.cpp"
#include "Keypad.cpp"
//#include <fstream>
#include <conio.h>

//template <typename T>
//Map<T>::Map()
//{
//	std::ifstream input;
//
//	input.open(MAP_DATA_FILE, std::ios::in);
//	if (!input.is_open()) {
//		std::cout << MAP_DATA_FILE << "打开失败！\n";
//		system("pause");
//		Sleep(3000);
//		exit(-1);
//	}
//
//	input >> this->length >> this->width;//读取行数和列数
//	
//	//创建二维数组
//	this->map = new int[this->width * this->length];
//
//	//读取地图数据
//	for (int i = 0; i < this->width; i++) {
//		for (int j = 0; j < this->length; j++) {
//			input >> this->map[i * this->length + j];
//		}
//	}
//	input.close();
//}

//鼠标上一次在地图上按下时获取到的鼠标的坐标
template <typename T>Pos Map<T>::mapPos = {0, 0};

template <typename T>
Map<T>::Map(int* map, int length, int width, 
	bool role, bool box, bool keypad) {

	this->width = width;
	this->length = length;
	
	if (map) {
		this->map = new int[this->width * this->length];
		if (!this->map) exit(-1);

		//地图数据拷贝
		for (int i = 0; i < this->width; i++) {
			for (int j = 0; j < this->length; j++) {
				this->map[i * this->length + j] = map[i * this->length + j];
			}
		}
	}
	else this->map = nullptr;

	//是否创建人物
	if (role) this->prole = new Role<>;
	else this->prole = nullptr;

	//是否创建箱子
	if (box) this->pbox = new Box<>[BOX_NUM];
	else this->pbox = nullptr;

	//是否创建按键
	if (keypad) this->pkeypad = new Keypad<>[KEYPAD_NUM];
	else this->pkeypad = nullptr;
}

template <typename T>
Map<T>::~Map()
{
	if (this->map)   delete[] this->map;
	if (this->prole) delete this->prole;
	if (this->pbox)  delete[] this->pbox;
	if (this->pkeypad)delete[] this->pkeypad;
}

//显示地图
template <typename T>
void Map<T>::display()
{
	if (!map) return;

	//cleardevice(); //清屏
	putimage(0, 0, &bgs[(int)BG::BG1]); //显示背景

	//显示地形
	for (int i = 0; i < this->width; i++) {
		for (int j = 0; j < this->length; j++) {
			putimage(MAP_START_X + j * TERRAIN_SIZE,
				MAP_START_Y + i * TERRAIN_SIZE,
				&terrains[map[i * this->length + j]]);
		}
	}

	//显示人物
	this->prole->display();
	
	//显示所有箱子
	for (int i = 0; i < BOX_NUM; i++) {
		this->pbox[i].display();
	}

	//显示所有按键
	for (int i = 0; i < KEYPAD_NUM; i++) {
		this->pkeypad[i].display();
	}
}

template<typename T>
void Map<T>::display(Pos& pos)
{
	if (!map) return;

	putimage(MAP_START_X + pos.x * TERRAIN_SIZE,
		MAP_START_Y + pos.y * TERRAIN_SIZE,
		&terrains[map[pos.y * length + pos.x]]);
}

//输入
template<typename T>
Input Map<T>::input()
{
	while (true) {
		if (_kbhit()) {	     //是否按键
			try {
				return keyboardInput(); //键盘输入
			}
			catch (...) {
				continue;
			}
		}
		else if (MouseHit()) {
			mouseInput();    //鼠标输入
		}
		_Sleep(1);
	}
}

//移动
template<typename T>
void Map<T>::move()
{
	if (!map) return;

	while (true) {
		Pos tempRolePos = prole->getPos();

		//获取移动方向
		Input result = input();
		
		switch (result) {
		case Input::UP:    tempRolePos.y -= moveDis; break;
		case Input::DOWN:  tempRolePos.y += moveDis; break;
		case Input::LEFT:  tempRolePos.x -= moveDis; break;
		case Input::RIGHT: tempRolePos.x += moveDis; break;
		default: return;
		}

		//人物的下一个位置越界了
		if (tempRolePos.x < 0 || tempRolePos.x > length ||
			tempRolePos.y < 0 || tempRolePos.y > width)
			continue;

		Box<>* tempBox = nullptr;

		//人物的下一个位置是否有箱子
		for (int i = 0; i < BOX_NUM; i++) {
			Pos boxPos = pbox[i].getPos();
			if (tempRolePos.x == boxPos.x && tempRolePos.y == boxPos.y) {
				tempBox = &pbox[i];
				break;
			}
		}

		//如果箱子存在
		if (tempBox) {
			Pos tempBoxPos = tempBox->getPos();

			//寻找箱子的下一个位置
			tempBoxPos.x += tempRolePos.x - prole->getPos().x;
			tempBoxPos.y += tempRolePos.y - prole->getPos().y;

			//箱子的下一个位置越界了
			if (tempBoxPos.x < 0 || tempBoxPos.x > length ||
				tempBoxPos.y < 0 || tempBoxPos.y > width)
				continue;

			//箱子的下一个位置的地形数据
			int boxNext = map[tempBoxPos.y * length + tempBoxPos.x];

			//实现移动
			if (boxNext == (int)Terrain::Floor ||
				boxNext == (int)Terrain::Box_Goal) {

				//display(tempBox->getPos());    //覆盖箱子原来的位置
				tempBox->getPos() = tempBoxPos;//获取新的位置

				//新的位置是箱子的目的地，把箱子换成到达目的地的箱子
				if (boxNext == (int)Terrain::Box_Goal) {
					tempBox->getBox() = BOX::Goal_Box;
				}
				else if (tempBox->getBox() == BOX::Goal_Box) {
					tempBox->getBox() = BOX::Box;
				}
				tempBox->display();            //显示箱子
				display(prole->getPos());      //覆盖人物原来的位置
				prole->getPos() = tempRolePos; //获取新的位置
				prole->display();              //显示人物
			}
		}
		else {
			//人物的下一个位置的地形数据
			int roleNext = map[tempRolePos.y * length + tempRolePos.x];

			//实现移动
			if (roleNext == (int)Terrain::Floor ||
				roleNext == (int)Terrain::Box_Goal) {

				display(prole->getPos());      //覆盖人物原来的位置
				prole->getPos() = tempRolePos; //获取新的位置
				prole->display();              //显示人物
			}
		}
	}
}

//鼠标出现在地图上
template<typename T>
bool Map<T>::isInMap(MOUSEMSG& m)
{
	if (m.x > MAP_START_X && 
		m.x < MAP_START_X + length*TERRAIN_SIZE && 
		m.y > MAP_START_Y &&
		m.y < MAP_START_Y + width*TERRAIN_SIZE) {

		return true;
	}
	return false;
}

//鼠标点击左键
template<typename T>
bool Map<T>::press(MOUSEMSG& m)
{
	if (m.uMsg == WM_LBUTTONDOWN) {
		return true;
	}
	return false;
}

template<typename T>
Pos Map<T>::getPos(MOUSEMSG& m)
{
	Pos tempPos = {0, 0};
		tempPos.x = (m.x - MAP_START_X)/TERRAIN_SIZE;
		tempPos.y = (m.y - MAP_START_Y) / TERRAIN_SIZE;
	return tempPos;
}

template<typename T>
void Map<T>::_Sleep(unsigned _time)
{
	for (unsigned i = 0; i < _time; i++) {
		if (_kbhit() || MouseHit()) break;
		Sleep(1);
	}
}

template<typename T>
Input Map<T>::keyboardInput()
{
	char ch = _getch();//按下的键盘字符

	if (ch == up)    return Input::UP;
	if (ch == down)  return Input::DOWN;
	if (ch == left)  return Input::LEFT;
	if (ch == right) return Input::RIGHT;
	if (ch == quit)  return Input::QUIT;

	throw -1;
}

template<typename T>
void Map<T>::mouseInput()
{
	MOUSEMSG m = GetMouseMsg();

	//鼠标在地图上
	if (isInMap(m) && press(m)) {
		//获取当前鼠标在地图上的坐标
		mapPos = getPos(m);
	}

	//把坐标转成字符串
	char str[10];
	sprintf_s(str, sizeof(str), "x:%d y:%d", mapPos.x, mapPos.y);

	//显示坐标
	Pos pos = this->pkeypad[0].getPos1();

	setfillcolor(RGB(155, 155, 155));
	solidrectangle(pos.x - 60, pos.y, pos.x, pos.y + 30);
	settextstyle(20, 0, "微软雅黑");
	//setbkmode(TRANSPARENT);
	outtextxy(pos.x - 50, pos.y + 5, str);

	//鼠标在按键上并且鼠标左键按下
	if (this->pkeypad[0].isInKeypad(m) &&
		this->pkeypad[0].pressKeypad(m)) {
		//更改坐标上的地形
		map[mapPos.y * length + mapPos.x] = (map[mapPos.y * length + mapPos.x] + 1) % TERRAIN_IMAGE_NUM;
		display(mapPos);

	}
}


