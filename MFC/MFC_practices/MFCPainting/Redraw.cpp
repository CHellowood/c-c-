#include "pch.h"
#include "Redraw.h"
#include "MFCPainting.h"

IMPLEMENT_SERIAL(Graph, CObject, 1); // ʵ�����к�

Graph::Graph() noexcept
{
}

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
		//����
		pDC->MoveTo(m_points.GetAt(0));
		pDC->LineTo(m_points.GetAt(1));
		break;
	case DrawType::DRAW_RECT:
		//������
		pDC->Rectangle(CRect(m_points.GetAt(0), m_points.GetAt(1)));
		break;
	case DrawType::DRAW_ELLIPSE:
		//����Բ
		pDC->Ellipse(CRect(m_points.GetAt(0), m_points.GetAt(1)));
		break;
	case DrawType::DRAW_PEN:
	{
		int n = m_points.GetSize();

		//�±��0��ʼ, n-1����
		//���� ++i, ����ѭ������ʵ�ֵ�, ���� n-1 ��Ϊ�˷�ֹԽ�� 
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


void Graph::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{	// storing code ��������
		ar << m_DrawType << m_nLineStyle << m_nLineWidth << m_color;
	}
	else
	{	// loading code ��ȡ����
		ar >> m_DrawType >> m_nLineStyle >> m_nLineWidth >> m_color;
	}
	m_points.Serialize(ar);
}
