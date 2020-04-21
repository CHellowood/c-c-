#pragma once
#include <afx.h>

//��������ͼ��
class Graph : public CObject
{
public:
	Graph() noexcept;
	DECLARE_SERIAL(Graph); // �������к�

	Graph(UINT drawType, UINT lineStyle, UINT lineWidth, COLORREF color);

	//���һ������
	void AddPoint(const CPoint& point); 

	//���ֱ��(�����)����������
	void AddPoint(const CPoint& start, const CPoint& end); 

	//��ͼ
	void Draw(CDC* pDC); 

protected:
	UINT m_DrawType;         //��ͼģʽ
	UINT m_nLineStyle;       //������ʽ
	UINT m_nLineWidth;       //���߿��
	COLORREF m_color;        //������ɫ
	CArray<CPoint> m_points; //ͼ������
public:
	virtual void Serialize(CArchive& ar);
};

