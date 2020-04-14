#include "Role.h"
#include <fstream>

//template <typename T>
//Role<T>::Role(ROLE role)
//{
//	this->role = role;
//
//	std::ifstream input;
//
//	input.open(ROLE_POS_FILE, std::ios::in);
//	if (!input.is_open()) {
//		std::cout << ROLE_POS_FILE << "打开失败！\n";
//		system("pause");
//		Sleep(3000);
//		exit(-1);
//	}
//
//	input >> this->x >> this->y;//读取人物坐标
//	input.close();
//}

template <typename T>
Role<T>::Role(ROLE role) {
	this->role = role;
	this->pos.x = rolePos.x;
	this->pos.y = rolePos.y;
}

template <typename T>
void Role<T>::display()
{
	putimage(MAP_START_X + this->pos.x * TERRAIN_SIZE,
		MAP_START_Y + this->pos.y * TERRAIN_SIZE,
		&roles[(int)this->role]);
}

template<typename T>
Pos& Role<T>::getPos()
{
	return pos;
}

template<typename T>
ROLE& Role<T>::getRole()
{
	return role;
}


