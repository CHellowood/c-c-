#pragma once
#ifndef INPUT_FIELD_H
#define INPUT_FIELD_H

#include <graphics.h>
#include <conio.h>

//#define DEFAULT_POS               {0, 0}             //默认Pos
#define DEFAULT_POS(x, y)         {x, y} 
#define DEFAULT_INPUT_FIELD_COLOR RGB(255, 255, 255) //默认输入框颜色
#define DEFAULT_CHAR_COLOR        RGB(0, 0, 0)       //默认字符颜色
#define DEFAULT_CHAR_SIZE         24                 //默认字符大小
#define DEFAULT_FONT              "微软雅黑"         //默认字体
#define DEFAULT_INPUT_MAX_NUM     100                //默认最大输入个数

#define CAN_INPUT_CHAR "0123456789abcdefghijklmnopqrstuvwxyz"

#define OUT_TEXT_START_X 1  //输出文本时的起始x轴
#define OUT_TEXT_START_Y 0  //输出文本时的起始y轴

//坐标
typedef struct {
	int x;
	int y;
}Pos;

//光标
typedef struct {
	int x;
	int y1;
	int y2;
	int num;//光标当前在字符串的第几个字符的位置
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

	void display(); //显示输入框
	void displayCursor();//显示光标
	void cursorPos(); //计算光标位置

	bool MouseInInputField();   //鼠标在输入框
	bool MouseCilck();          //鼠标左键点击

	bool MouseCilckInputField();//鼠标左键点击输入框

	void input(const char* canInputChar); //输入

	void insertChar(int index, char ch); //在字符串的指定位置插入指定字符
	void killChar(int index);//删除字符串里指定位置的字符

	//void outChar(int x, int y, char ch); //输出一个字符
	void outStr(int x, int y, char* str);//输出一个字符串

	void strcopy(char* str1, int len, char* str2);//字符串拷贝

	int getCharNum(int& retwidth);//获取鼠标所在的位置是字符串的第几个字符

	int getStrWidth(const char* str);//获取字符串的宽度（像素）

	void _Sleep(int time);

protected:
	Pos      pos1;            //输入框右上角坐标
	Pos      pos2;            //输入框左下角坐标
	COLORREF inputFieldColor; //输入框颜色
	COLORREF charColor;       //字符颜色
	unsigned charSize;        //字符大小
	char*    font;            //字体
	char*    inputStr;        //输入的字符串
	unsigned inputNum;        //当前输入的字符个数
	unsigned inputMaxNum;     //可输入的字符的最大个数
	MOUSEMSG msg;             //鼠标信息
	Cursor cursor;            //光标

};

#endif 