#pragma once
#ifndef INPUT_FIELD_H
#define INPUT_FIELD_H

#include <graphics.h>
#include <conio.h>

//#define DEFAULT_POS               {0, 0}             //Ĭ��Pos
#define DEFAULT_POS(x, y)         {x, y} 
#define DEFAULT_INPUT_FIELD_COLOR RGB(255, 255, 255) //Ĭ���������ɫ
#define DEFAULT_CHAR_COLOR        RGB(0, 0, 0)       //Ĭ���ַ���ɫ
#define DEFAULT_CHAR_SIZE         24                 //Ĭ���ַ���С
#define DEFAULT_FONT              "΢���ź�"         //Ĭ������
#define DEFAULT_INPUT_MAX_NUM     100                //Ĭ������������

#define CAN_INPUT_CHAR "0123456789abcdefghijklmnopqrstuvwxyz"

#define OUT_TEXT_START_X 1  //����ı�ʱ����ʼx��
#define OUT_TEXT_START_Y 0  //����ı�ʱ����ʼy��

//����
typedef struct {
	int x;
	int y;
}Pos;

//���
typedef struct {
	int x;
	int y1;
	int y2;
	int num;//��굱ǰ���ַ����ĵڼ����ַ���λ��
}Cursor;

template <typename T = void>
class InputField
{
public:
	InputField(Pos pos1 = DEFAULT_POS(0, 0), Pos pos2 = DEFAULT_POS(640, 30),
		unsigned inputMaxNum = DEFAULT_INPUT_MAX_NUM,
		unsigned charSize = DEFAULT_CHAR_SIZE,
		const char* font = DEFAULT_FONT, 
		COLORREF charColor = DEFAULT_CHAR_COLOR,
		COLORREF inputFieldColor = DEFAULT_INPUT_FIELD_COLOR);

	~InputField();

	void display(); //��ʾ�����
	void displayCursor();//��ʾ���
	void cursorPos(); //������λ��

	bool MouseInInputField();   //����������
	bool MouseCilck();          //���������

	bool MouseCilckInputField();//��������������

	void input(const char* canInputChar); //����

	void insertChar(int index, char ch); //���ַ�����ָ��λ�ò���ָ���ַ�
	void killChar(int index);//ɾ���ַ�����ָ��λ�õ��ַ�

	//void outChar(int x, int y, char ch); //���һ���ַ�
	void outStr(int x, int y, char* str);//���һ���ַ���

	void strcopy(char* str1, int len, char* str2);//�ַ�������

	int getCharNum(int& retwidth);//��ȡ������ڵ�λ�����ַ����ĵڼ����ַ�

	int getStrWidth(const char* str);//��ȡ�ַ����Ŀ�ȣ����أ�

	void _Sleep(int time);

protected:
	Pos      pos1;            //��������Ͻ�����
	Pos      pos2;            //��������½�����
	COLORREF inputFieldColor; //�������ɫ
	COLORREF charColor;       //�ַ���ɫ
	unsigned charSize;        //�ַ���С
	char*    font;            //����
	char*    inputStr;        //������ַ���
	unsigned inputNum;        //��ǰ������ַ�����
	unsigned inputMaxNum;     //��������ַ���������
	MOUSEMSG msg;             //�����Ϣ
	Cursor cursor;            //���

};

#endif 