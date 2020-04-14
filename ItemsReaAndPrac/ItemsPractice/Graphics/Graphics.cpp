#include <graphics.h>
#include "Graphics.h"

//计算三角形的第三边的边长的平方
#define Triangle_SQUARE(a, b) (((a)*(a))+((b)*(b)))

//实现画圆算法
void _circle(int x, int y, int len) {
	x += len; //计算圆心的x轴
	y += len; //计算圆心的y轴

	COLORREF color = RGB(0, 0, 255);


	//左边部分的上半边弧线
	int presentx = x - len; //当前x轴
	int presenty = y;       //当前y轴

	while (presentx < x && presenty > y - (len / 2)) {
		//计算当前画点到圆心的距离平方
		int temp = Triangle_SQUARE(x - presentx, y - presenty);

		while (temp - len * len >= len && presentx < x) {
			putpixel(presentx, presenty, color);
			presentx++;
			temp = Triangle_SQUARE(x - presentx, y - presenty);
		}
		putpixel(presentx, presenty--, color);
	}

	//左边部分的下半边弧线
	presentx = x - len;
	presenty = y;

	while (presentx < x && presenty < y + (len / 2)) {
		//计算三角形第三边的平方
		int temp = Triangle_SQUARE(x - presentx, presenty - y);

		while (temp - len * len >= len && presentx < x) {
			putpixel(presentx, presenty, color);
			presentx++;
			temp = Triangle_SQUARE(x - presentx, presenty - y);
		}
		putpixel(presentx, presenty++, color);
	}

	//右边部分的上半边弧线
	presentx = x + len;
	presenty = y;

	while (presentx > x&& presenty > y - (len / 2)) {
		//计算当前画点到圆心的距离平方
		int temp = Triangle_SQUARE(presentx - x, y - presenty);

		while (temp - len * len >= len && presentx > x) {
			putpixel(presentx, presenty, color);
			presentx--;
			temp = Triangle_SQUARE(presentx - x, y - presenty);
		}
		putpixel(presentx, presenty--, color);
	}

	//右边部分的下半边弧线
	presentx = x + len;
	presenty = y;

	while (presentx > x&& presenty < y + (len / 2)) {
		//计算当前画点到圆心的距离平方
		int temp = Triangle_SQUARE(presentx - x, presenty - y);

		while (temp - len * len >= len && presentx >= x) {
			putpixel(presentx, presenty, color);
			presentx--;
			temp = Triangle_SQUARE(presentx - x, presenty - y);
		}
		putpixel(presentx, presenty++, color);
	}
	//color = RGB(255, 0, 0);
	//顶部的左半边弧线
	presentx = x;
	presenty = y - len;

	while (presentx > x - len && presenty < y - (len / 2)) {
		//计算当前画点到圆心的距离平方
		int temp = Triangle_SQUARE(x - presentx, y - presenty);

		while (temp - len * len >= len && presenty < y - (len / 2)) {
			putpixel(presentx, presenty, color);
			presenty++;
			temp = Triangle_SQUARE(x - presentx, y - presenty);
		}
		putpixel(presentx--, presenty, color);
	}

	//顶部的右半边弧线
	presentx = x;
	presenty = y - len;

	while (presentx < x + len && presenty < y - (len / 2)) {
		//计算当前画点到圆心的距离平方
		int temp = Triangle_SQUARE(presentx - x, y - presenty);

		while (temp - len * len >= len && presenty < y - (len / 2)) {
			putpixel(presentx, presenty, color);
			presenty++;
			temp = Triangle_SQUARE(presentx - x, y - presenty);
		}
		putpixel(presentx++, presenty, color);
	}

	//底部的左半边弧线
	presentx = x;
	presenty = y + len;

	while (presentx > x - len && presenty > y + (len / 2)) {
		//计算当前画点到圆心的距离平方
		int temp = Triangle_SQUARE(x - presentx, presenty - y);

		while (temp - len * len >= len && presenty > y + (len / 2)) {
			putpixel(presentx, presenty, color);
			presenty--;
			temp = Triangle_SQUARE(x - presentx, presenty - y);
		}
		putpixel(presentx--, presenty, color);
	}

	//底部的右半边弧线
	presentx = x;
	presenty = y + len;

	while (presentx < x + len && presenty > y + (len / 2)) {
		//计算当前画点到圆心的距离平方
		int temp = Triangle_SQUARE(presentx - x, presenty - y);

		while (temp - len * len >= len && presenty > y + (len / 2)) {
			putpixel(presentx, presenty, color);
			presenty--;
			temp = Triangle_SQUARE(presentx - x, presenty - y);
		}
		putpixel(presentx++, presenty, color);
	}
}

//画正方形
void square(int x1, int y1, int x2, int y2) {
	line(x1, y1, x2, y1);
	line(x1, y1, x1, y2);
	line(x1, y2, x2, y2);
	line(x2, y1, x2, y2);
}
