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

//��ʾ�����
template <typename T>
void InputField<T>::display()
{
	setfillcolor(inputFieldColor);
	solidrectangle(pos1.x, pos1.y, pos2.x, pos2.y);//��������

	settextstyle(charSize, 0, font);
	settextcolor(charColor);
}

//��ʾ���
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

//������λ��
template<typename T>
void InputField<T>::cursorPos()
{

	cursor.x = msg.x;
	//��ǰ��������ַ����Ŀ��
	int strWidth = getStrWidth(inputStr);

	//���λ�ô������һ���ַ�����һ����λ��
	if (cursor.x > pos1.x + OUT_TEXT_START_X + strWidth) {
		//�ѹ��λ������Ϊ���һ���ַ�����һ����λ��
		//�ַ���� = �ַ��߶� / 2 - 1
		cursor.x = pos1.x + OUT_TEXT_START_X + strWidth;
		cursor.num = inputNum;
	}
	//���λ��С����ʼλ��
	else if (cursor.x < pos1.x + OUT_TEXT_START_X) {
		cursor.x = pos1.x + OUT_TEXT_START_X;
		cursor.num = 0;
	}
	else {
		//��������λ���ǵڼ����ַ�
		cursor.num = getCharNum(cursor.x);
		//���¼�����λ��
		cursor.x += pos1.x + OUT_TEXT_START_X;
	}
}

//������������
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

//���������
template <typename T>
bool InputField<T>::MouseCilck()
{
	if (MouseHit()) msg = GetMouseMsg();

	if (msg.uMsg == WM_LBUTTONDOWN) {
		return true;
	}
	return false;
}

//��������������
template <typename T>
bool InputField<T>::MouseCilckInputField()
{
	if (MouseInInputField() && MouseCilck()) {
		input(CAN_INPUT_CHAR);
		return true;
	}
	return false;
}

//����
template <typename T>
void InputField<T>::input(const char* canInputChar)
{
	//����ʾ�ַ�ʱ�ı�����Ϊ͸����
	setbkmode(TRANSPARENT);

	//���û�е�����������ĵط�ʱ
	while (MouseInInputField() || !MouseCilck()) {

		//����������
		if (MouseCilck()) {
			//������λ��
			cursorPos();
		}

		//��������
		if (_kbhit()) {
			char ch = _getch();//��ȡ������ַ�

			switch (ch) {
			//ʵ�ּ����ϵ�Backspace������
			case '\b': 
				if (cursor.num > 0) {
					cursor.x -= textwidth(inputStr[--cursor.num]);
					killChar(cursor.num); //ɾ������ǰһ���ַ�
					display();//���������
					outStr(pos1.x + OUT_TEXT_START_X,
						pos1.y + OUT_TEXT_START_Y, inputStr);
				}

				break;
			case 75: //����� <-
				if (cursor.num > 0) {
					cursor.num--;
					cursor.x -= textwidth(inputStr[cursor.num]);
				}
				break;
			case 77: //����� ->
				if (cursor.num < inputNum) {
					cursor.x += textwidth(inputStr[cursor.num]);
					cursor.num++;
				}
				break;
			default: break;
			}
			

			//������ַ��Ƿ��ǿ������ַ�, ����û�е�����������ʱ
			for (int i = 0; i < strlen(canInputChar) &&
				inputNum < inputMaxNum; i++) {

				if (ch == canInputChar[i]) { //��
					//��ӵ�������ַ�����
					insertChar(cursor.num++, ch);
					display();//���������

					//��ʾ������ַ���
					outStr(pos1.x + OUT_TEXT_START_X,
						pos1.y + OUT_TEXT_START_Y, inputStr);

					//���λ���ƶ�����һ��λ��
					cursor.x += textwidth(ch);
					break;
				}
			}
		}
		else {
			//��ʾ���
			displayCursor();
		}
		//�Ƿ���������Ϣ
		if (MouseHit()) msg = GetMouseMsg();
	}
}

//���ַ�����ָ��λ�ò���ָ���ַ�
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

//ɾ���ַ�����ָ��λ�õ��ַ�
template<typename T>
void InputField<T>::killChar(int index)
{
	if (index < 0 || index >= inputNum) return;

	for (int i = index; i < inputNum; i++) {
		inputStr[i] = inputStr[i+1];
	}
	inputNum--;
}

////���һ���ַ�
//template<typename T>
//void InputField<T>::outChar(int x, int y, char ch)
//{
//	//����������ַ���Ⱥ�λ��
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
//���һ���ַ���
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

//��ȡ������ڵ�λ�����ַ����ĵڼ����ַ�
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
