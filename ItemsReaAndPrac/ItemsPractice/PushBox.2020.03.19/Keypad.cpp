#include "Keypad.h"

template <typename T>
Keypad<T>::Keypad(Pos pos1, Pos pos2, int textsize,
	const char* text, const char* font, COLORREF color)
{
	this->pos1 = pos1;
	this->pos2 = pos2;
	this->textsize = textsize;

	this->text = new char[strlen(text) + 1];
	strcpy_s(this->text, strlen(text) +1, text);

	this->font = new char[strlen(font) + 1];
	strcpy_s(this->font, strlen(font) + 1, font);

	this->color = color;
}

template <typename T>
Keypad<T>::~Keypad() 
{
	if (text) delete[] text;
	if (font) delete[] font;
}

//显示按键
template<typename T>
void Keypad<T>::display(int addcolor)
{
	setfillcolor(color - RGB(addcolor, addcolor, addcolor));
	solidrectangle(pos1.x, pos1.y, pos2.x, pos2.y);
	settextstyle(20, 0, font);
	setbkmode(TRANSPARENT);
	outtextxy(pos1.x+20, pos1.y +5, text);
}

//鼠标是否在按键上
template<typename T>
bool Keypad<T>::isInKeypad(MOUSEMSG& m)
{
	if (m.x > pos1.x && m.x < pos2.x && m.y > pos1.y && m.y < pos2.y) {
		display(10);
		return true;
	}
	display();
	return false;
}

//鼠标左键是否按下
template<typename T>
bool Keypad<T>::pressKeypad(MOUSEMSG& m)
{
	if (m.uMsg == WM_LBUTTONDOWN) {
		if (isInKeypad(m)) display(50);
		return true;
	}
	return false;
}

template<typename T>
Pos Keypad<T>::getPos1()
{
	return pos1;
}

template<typename T>
Pos Keypad<T>::getPos2()
{
	return pos2;
}

