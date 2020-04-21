#pragma once
#include <afx.h>

//用来保存图形
class Graph : public CObject
{
public:
	Graph() noexcept;
	DECLARE_SERIAL(Graph); // 声明序列号

	Graph(UINT drawType, UINT lineStyle, UINT lineWidth, COLORREF color);

	//添加一个坐标
	void AddPoint(const CPoint& point); 

	//添加直线(或矩形)的两个坐标
	void AddPoint(const CPoint& start, const CPoint& end); 

	//绘图
	void Draw(CDC* pDC); 

protected:
	UINT m_DrawType;         //绘图模式
	UINT m_nLineStyle;       //画线样式
	UINT m_nLineWidth;       //画线宽度
	COLORREF m_color;        //画线颜色
	CArray<CPoint> m_points; //图形坐标
public:
	virtual void Serialize(CArchive& ar);
};

