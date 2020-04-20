#include "pch.h"
#include "Redraw.h"
#include "MFCPainting.h"

Graph::Graph(UINT drawType, UINT lineStyle, UINT lineWidth, COLORREF color)
	:m_DrawType(drawType), m_nLineStyle(lineStyle), m_nLineWidth(lineWidth)
	,m_color(color)
{
}

void Graph::AddPoint(const CPoint& point)
{
	m_points.Add(point);
}

void Graph::AddPoint(const CPoint& start, const CPoint& end)
{
	m_points.Add(start);
	m_points.Add(end);
}

void Graph::Draw(CDC* pDC)
{
	CPen pen(m_nLineStyle, m_nLineWidth, m_color);

	CPen* pOldPen = pDC->SelectObject(&pen);

	switch ((DrawType)m_DrawType) {
	case DrawType::DRAW_LINE:
		//画线
		pDC->MoveTo(m_points.GetAt(0));
		pDC->LineTo(m_points.GetAt(1));
		break;
	case DrawType::DRAW_RECT:
		//画矩形
		pDC->Rectangle(CRect(m_points.GetAt(0), m_points.GetAt(1)));
		break;
	case DrawType::DRAW_ELLIPSE:
		//画椭圆
		pDC->Ellipse(CRect(m_points.GetAt(0), m_points.GetAt(1)));
		break;
	case DrawType::DRAW_PEN:
	{
		int n = m_points.GetSize();

		//下标从0开始, n-1结束
		//由于 ++i, 是在循环体里实现的, 所以 n-1 是为了防止越界 
		for (int i = 0; i < n-1;) {
			pDC->MoveTo(m_points.GetAt(i));
			pDC->LineTo(m_points.GetAt(++i));
		}
	}
		break;
	default:
		break;
	}
}
