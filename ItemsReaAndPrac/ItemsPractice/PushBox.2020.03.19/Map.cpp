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
//		std::cout << MAP_DATA_FILE << "��ʧ�ܣ�\n";
//		system("pause");
//		Sleep(3000);
//		exit(-1);
//	}
//
//	input >> this->length >> this->width;//��ȡ����������
//	
//	//������ά����
//	this->map = new int[this->width * this->length];
//
//	//��ȡ��ͼ����
//	for (int i = 0; i < this->width; i++) {
//		for (int j = 0; j < this->length; j++) {
//			input >> this->map[i * this->length + j];
//		}
//	}
//	input.close();
//}

//�����һ���ڵ�ͼ�ϰ���ʱ��ȡ������������
template <typename T>Pos Map<T>::mapPos = {0, 0};

template <typename T>
Map<T>::Map(int* map, int length, int width, 
	bool role, bool box, bool keypad) {

	this->width = width;
	this->length = length;
	
	if (map) {
		this->map = new int[this->width * this->length];
		if (!this->map) exit(-1);

		//��ͼ���ݿ���
		for (int i = 0; i < this->width; i++) {
			for (int j = 0; j < this->length; j++) {
				this->map[i * this->length + j] = map[i * this->length + j];
			}
		}
	}
	else this->map = nullptr;

	//�Ƿ񴴽�����
	if (role) this->prole = new Role<>;
	else this->prole = nullptr;

	//�Ƿ񴴽�����
	if (box) this->pbox = new Box<>[BOX_NUM];
	else this->pbox = nullptr;

	//�Ƿ񴴽�����
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

//��ʾ��ͼ
template <typename T>
void Map<T>::display()
{
	if (!map) return;

	//cleardevice(); //����
	putimage(0, 0, &bgs[(int)BG::BG1]); //��ʾ����

	//��ʾ����
	for (int i = 0; i < this->width; i++) {
		for (int j = 0; j < this->length; j++) {
			putimage(MAP_START_X + j * TERRAIN_SIZE,
				MAP_START_Y + i * TERRAIN_SIZE,
				&terrains[map[i * this->length + j]]);
		}
	}

	//��ʾ����
	this->prole->display();
	
	//��ʾ��������
	for (int i = 0; i < BOX_NUM; i++) {
		this->pbox[i].display();
	}

	//��ʾ���а���
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

//����
template<typename T>
Input Map<T>::input()
{
	while (true) {
		if (_kbhit()) {	     //�Ƿ񰴼�
			try {
				return keyboardInput(); //��������
			}
			catch (...) {
				continue;
			}
		}
		else if (MouseHit()) {
			mouseInput();    //�������
		}
		_Sleep(1);
	}
}

//�ƶ�
template<typename T>
void Map<T>::move()
{
	if (!map) return;

	while (true) {
		Pos tempRolePos = prole->getPos();

		//��ȡ�ƶ�����
		Input result = input();
		
		switch (result) {
		case Input::UP:    tempRolePos.y -= moveDis; break;
		case Input::DOWN:  tempRolePos.y += moveDis; break;
		case Input::LEFT:  tempRolePos.x -= moveDis; break;
		case Input::RIGHT: tempRolePos.x += moveDis; break;
		default: return;
		}

		//�������һ��λ��Խ����
		if (tempRolePos.x < 0 || tempRolePos.x > length ||
			tempRolePos.y < 0 || tempRolePos.y > width)
			continue;

		Box<>* tempBox = nullptr;

		//�������һ��λ���Ƿ�������
		for (int i = 0; i < BOX_NUM; i++) {
			Pos boxPos = pbox[i].getPos();
			if (tempRolePos.x == boxPos.x && tempRolePos.y == boxPos.y) {
				tempBox = &pbox[i];
				break;
			}
		}

		//������Ӵ���
		if (tempBox) {
			Pos tempBoxPos = tempBox->getPos();

			//Ѱ�����ӵ���һ��λ��
			tempBoxPos.x += tempRolePos.x - prole->getPos().x;
			tempBoxPos.y += tempRolePos.y - prole->getPos().y;

			//���ӵ���һ��λ��Խ����
			if (tempBoxPos.x < 0 || tempBoxPos.x > length ||
				tempBoxPos.y < 0 || tempBoxPos.y > width)
				continue;

			//���ӵ���һ��λ�õĵ�������
			int boxNext = map[tempBoxPos.y * length + tempBoxPos.x];

			//ʵ���ƶ�
			if (boxNext == (int)Terrain::Floor ||
				boxNext == (int)Terrain::Box_Goal) {

				//display(tempBox->getPos());    //��������ԭ����λ��
				tempBox->getPos() = tempBoxPos;//��ȡ�µ�λ��

				//�µ�λ�������ӵ�Ŀ�ĵأ������ӻ��ɵ���Ŀ�ĵص�����
				if (boxNext == (int)Terrain::Box_Goal) {
					tempBox->getBox() = BOX::Goal_Box;
				}
				else if (tempBox->getBox() == BOX::Goal_Box) {
					tempBox->getBox() = BOX::Box;
				}
				tempBox->display();            //��ʾ����
				display(prole->getPos());      //��������ԭ����λ��
				prole->getPos() = tempRolePos; //��ȡ�µ�λ��
				prole->display();              //��ʾ����
			}
		}
		else {
			//�������һ��λ�õĵ�������
			int roleNext = map[tempRolePos.y * length + tempRolePos.x];

			//ʵ���ƶ�
			if (roleNext == (int)Terrain::Floor ||
				roleNext == (int)Terrain::Box_Goal) {

				display(prole->getPos());      //��������ԭ����λ��
				prole->getPos() = tempRolePos; //��ȡ�µ�λ��
				prole->display();              //��ʾ����
			}
		}
	}
}

//�������ڵ�ͼ��
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

//��������
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
	char ch = _getch();//���µļ����ַ�

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

	//����ڵ�ͼ��
	if (isInMap(m) && press(m)) {
		//��ȡ��ǰ����ڵ�ͼ�ϵ�����
		mapPos = getPos(m);
	}

	//������ת���ַ���
	char str[10];
	sprintf_s(str, sizeof(str), "x:%d y:%d", mapPos.x, mapPos.y);

	//��ʾ����
	Pos pos = this->pkeypad[0].getPos1();

	setfillcolor(RGB(155, 155, 155));
	solidrectangle(pos.x - 60, pos.y, pos.x, pos.y + 30);
	settextstyle(20, 0, "΢���ź�");
	//setbkmode(TRANSPARENT);
	outtextxy(pos.x - 50, pos.y + 5, str);

	//����ڰ����ϲ�������������
	if (this->pkeypad[0].isInKeypad(m) &&
		this->pkeypad[0].pressKeypad(m)) {
		//���������ϵĵ���
		map[mapPos.y * length + mapPos.x] = (map[mapPos.y * length + mapPos.x] + 1) % TERRAIN_IMAGE_NUM;
		display(mapPos);

	}
}


