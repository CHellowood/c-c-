#include "Box.h"

template <typename T>int Box<T>::num = 0;

template <typename T>
Box<T>::Box() {
	if (num >= BOX_NUM) {
		this->pos.x = 0;
		this->pos.y = 0;
	}
	else {
		this->pos.x = boxsPos[Box::num].x;
		this->pos.y = boxsPos[Box::num++].y;
	}
	this->box = BOX::Box;
	this->id = Box::num;
}

template<typename T>
Box<T>::~Box()
{
	if (id <= BOX_NUM) num--;
}

template<typename T>
Box<T>& Box<T>::operator=(const Box& box)
{
	this->box = box.box;
	this->pos = box.pos;
	return *this;
}

template <typename T>
void Box<T>::display() {
	putimage(MAP_START_X + this->pos.x * TERRAIN_SIZE,
		MAP_START_Y + this->pos.y * TERRAIN_SIZE,
		&boxs[(int)this->box]);
}

template<typename T>
int Box<T>::getNum()
{
	return Box::num;
}

template<typename T>
Pos& Box<T>::getPos()
{
	return pos;
}

template<typename T>
BOX& Box<T>::getBox()
{
	return box;
}
