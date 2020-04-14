#include "InputField.h"

template <typename T>
InputField<T>::InputField(Pos pos1, Pos pos2, unsigned inputMaxNum,
	unsigned charSize, const char* font, 
	COLORREF charColor, COLORREF inputFieldColor)
{
	this->pos1            = pos1;
	this->pos2            = pos2;
	this->inputNum        = 0;
	this->inputMaxNum     = inputMaxNum;
	this->charSize        = charSize;
	this->charColor       = charColor;
	this->inputFieldColor = inputFieldColor;
	this->cursor          = {pos1.x, pos1.y, pos2.y, (int)this->inputNum};

	this->font = new char[strlen(font)+1];
	strcpy_s(this->font, strlen(font)+1, font);
	
	this->inputStr = new char[this->inputMaxNum+1];

}

template <typename T>
InputField<T>::~InputField()
{
	if (this->font)     delete[] this->font;
	if (this->inputStr) delete[] this->inputStr;
}

//显示输入框
template <typename T>
void InputField<T>::display()
{
	setfillcolor(inputFieldColor);
	solidrectangle(pos1.x, pos1.y, pos2.x, pos2.y);//画填充矩形

	settextstyle(charSize, 0, font);
	settextcolor(charColor);
}

//显示光标
template<typename T>
void InputField<T>::displayCursor()
{
	setlinecolor(charColor);
	line(cursor.x, cursor.y1, cursor.x, cursor.y2);

	_Sleep(100);

	setlinecolor(inputFieldColor);
	line(cursor.x, cursor.y1, cursor.x, cursor.y2);

	_Sleep(100);
}

//计算光标位置
template<typename T>
void InputField<T>::cursorPos()
{

	cursor.x = msg.x;
	//当前已输入的字符串的宽度
	int strWidth = getStrWidth(inputStr);

	//光标位置大于最后一个字符的下一个的位置
	if (cursor.x > pos1.x + OUT_TEXT_START_X + strWidth) {
		//把光标位置设置为最后一个字符的下一个的位置
		//字符宽度 = 字符高度 / 2 - 1
		cursor.x = pos1.x + OUT_TEXT_START_X + strWidth;
		cursor.num = inputNum;
	}
	//光标位置小于起始位置
	else if (cursor.x < pos1.x + OUT_TEXT_START_X) {
		cursor.x = pos1.x + OUT_TEXT_START_X;
		cursor.num = 0;
	}
	else {
		//计算鼠标的位置是第几个字符
		cursor.num = getCharNum(cursor.x);
		//重新计算光标位置
		cursor.x += pos1.x + OUT_TEXT_START_X;
	}
}

//鼠标在输入框上
template <typename T>
bool InputField<T>::MouseInInputField()
{
	if (MouseHit()) msg = GetMouseMsg();

	if (msg.x > this->pos1.x && msg.x < this->pos2.x &&
		msg.y > this->pos1.y && msg.y < this->pos2.y) {
		
		return true;
	}
	return false;
}

//鼠标左键点击
template <typename T>
bool InputField<T>::MouseCilck()
{
	if (MouseHit()) msg = GetMouseMsg();

	if (msg.uMsg == WM_LBUTTONDOWN) {
		return true;
	}
	return false;
}

//鼠标左键点击输入框
template <typename T>
bool InputField<T>::MouseCilckInputField()
{
	if (MouseInInputField() && MouseCilck()) {
		input(CAN_INPUT_CHAR);
		return true;
	}
	return false;
}

//输入
template <typename T>
void InputField<T>::input(const char* canInputChar)
{
	//把显示字符时的背景设为透明的
	setbkmode(TRANSPARENT);

	//鼠标没有点击输入框以外的地方时
	while (MouseInInputField() || !MouseCilck()) {

		//鼠标点击输入框
		if (MouseCilck()) {
			//计算光标位置
			cursorPos();
		}

		//存在输入
		if (_kbhit()) {
			char ch = _getch();//获取输入的字符

			switch (ch) {
			//实现键盘上的Backspace键功能
			case '\b': 
				if (cursor.num > 0) {
					cursor.x -= textwidth(inputStr[--cursor.num]);
					killChar(cursor.num); //删除光标的前一个字符
					display();//覆盖输入框
					outStr(pos1.x + OUT_TEXT_START_X,
						pos1.y + OUT_TEXT_START_Y, inputStr);
				}

				break;
			case 75: //方向键 <-
				if (cursor.num > 0) {
					cursor.num--;
					cursor.x -= textwidth(inputStr[cursor.num]);
				}
				break;
			case 77: //方向键 ->
				if (cursor.num < inputNum) {
					cursor.x += textwidth(inputStr[cursor.num]);
					cursor.num++;
				}
				break;
			default: break;
			}
			

			//输入的字符是否是可输入字符, 而且没有到达输入上限时
			for (int i = 0; i < strlen(canInputChar) &&
				inputNum < inputMaxNum; i++) {

				if (ch == canInputChar[i]) { //是
					//添加到输入的字符串中
					insertChar(cursor.num++, ch);
					display();//覆盖输入框

					//显示输入的字符串
					outStr(pos1.x + OUT_TEXT_START_X,
						pos1.y + OUT_TEXT_START_Y, inputStr);

					//光标位置移动到下一个位置
					cursor.x += textwidth(ch);
					break;
				}
			}
		}
		else {
			//显示光标
			displayCursor();
		}
		//是否存在鼠标信息
		if (MouseHit()) msg = GetMouseMsg();
	}
}

//在字符串的指定位置插入指定字符
template<typename T>
void InputField<T>::insertChar(int index, char ch)
{
	if (index >= inputMaxNum-1) return;

	if (index == inputNum) {
		inputStr[inputNum++] = ch;
		return;
	}

	inputNum++;
	for (; index < inputNum; index++) {
		char temp = inputStr[index];
		inputStr[index] = ch;
		ch = temp;
	}
}

//删除字符串里指定位置的字符
template<typename T>
void InputField<T>::killChar(int index)
{
	if (index < 0 || index >= inputNum) return;

	for (int i = index; i < inputNum; i++) {
		inputStr[i] = inputStr[i+1];
	}
	inputNum--;
}

////输出一个字符
//template<typename T>
//void InputField<T>::outChar(int x, int y, char ch)
//{
//	//设置输出的字符宽度和位置
//	switch (ch) {
//	case 'b':
//	case 'g':
//	case 'p':
//	case 'h': x -= 2; break;
//
//	case 'd':
//	case 'o':
//	case 'q': x -= 1; break;
//
//	case 'i':
//	case 'j':
//	case 'l': x += (charSize / 2 - 1)/2; break;
//
//	case 'm':
//	case 'w':
//		settextstyle(charSize, (charSize / 2 - 1) / 2, font);
//		outtextxy(x, y, ch);
//		settextstyle(charSize, 0, font);
//		return;
//
//	default:
//		break;
//	}
//	outtextxy(x, y, ch);
//}
//
//输出一个字符串
template<typename T>
void InputField<T>::outStr(int x, int y, char* str)
{
	/*for (int i = 0; i < inputNum; i++) {
		outChar(x + (i * (charSize / 2 - 1)), y, str[i]);
	}*/
	if (inputNum <= 0) return;

	char* p = new char[inputNum + 1];
	strcopy(p, inputNum, str);
	p[inputNum] = '\0';

	outtextxy(x, y, p);
	delete[] p;
}

template<typename T>
void InputField<T>::strcopy(char* str1, int len, char* str2)
{
	for (int i = 0; i < len; i++) {
		str1[i] = str2[i];
	}
}

//获取鼠标所在的位置是字符串的第几个字符
template<typename T>
int InputField<T>::getCharNum(int& retwidth)
{
	int x = 0, i = 0;
	retwidth = 0;

	for (; i < inputNum; i++) {
		x += textwidth(inputStr[i]);
		
		if (x == msg.x - pos1.x - OUT_TEXT_START_X) {
			retwidth = x;
			break;
		}
		else if (x > msg.x - pos1.x - OUT_TEXT_START_X) {
			i--;
			break;
		}
		retwidth = x;
	}

	return i+1;
}

template<typename T>
int InputField<T>::getStrWidth(const char* str)
{
	int width = 0;
	for (int i = 0; i < inputNum; i++) {
		width += textwidth(str[i]);
	}
	return width;
}

template <typename T>
void InputField<T>::_Sleep(int time)
{
	for (int i = 0; i < time; i++) {
		if (_kbhit() || MouseCilck()) return;
		Sleep(1);
	}
}
