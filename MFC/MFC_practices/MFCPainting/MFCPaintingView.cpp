
// MFCPaintingView.cpp: CMFCPaintingView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCPainting.h"
#endif

#include "MFCPaintingDoc.h"
#include "MFCPaintingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCPaintingView

IMPLEMENT_DYNCREATE(CMFCPaintingView, CView)

//开始消息映射
BEGIN_MESSAGE_MAP(CMFCPaintingView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()  
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_COMMAND(ID_DRAW_LINE, &CMFCPaintingView::OnDrawLine)
	ON_COMMAND(ID_DRAW_RECT, &CMFCPaintingView::OnDrawRect)
	ON_COMMAND(ID_DRAW_ELLIPSE, &CMFCPaintingView::OnDrawEllipse)
	ON_COMMAND(ID_DRAW_PEN, &CMFCPaintingView::OnDrawPen)
	ON_COMMAND(ID_CLS, &CMFCPaintingView::OnCls)
	ON_UPDATE_COMMAND_UI(ID_DRAW_LINE, &CMFCPaintingView::OnUpdateDrawLine)
	ON_UPDATE_COMMAND_UI(ID_DRAW_RECT, &CMFCPaintingView::OnUpdateDrawRect)
	ON_UPDATE_COMMAND_UI(ID_DRAW_ELLIPSE, &CMFCPaintingView::OnUpdateDrawEllipse)
	ON_UPDATE_COMMAND_UI(ID_DRAW_PEN, &CMFCPaintingView::OnUpdateDrawPen)
END_MESSAGE_MAP()

// CMFCPaintingView 构造/析构

CMFCPaintingView::CMFCPaintingView() noexcept
{
	// TODO: 在此处添加构造代码
	m_LButtonDownPoint = 0;
	m_bDown = FALSE;
	m_bGline = FALSE;
	m_MPrevPoint = 0;
	m_Paint = Paint::DRAW_LINE;
}

CMFCPaintingView::~CMFCPaintingView()
{
}

BOOL CMFCPaintingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCPaintingView 绘图

void CMFCPaintingView::OnDraw(CDC* /*pDC*/)
{
	CMFCPaintingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

//鼠标右键点击（弹起）
void CMFCPaintingView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	//将窗口坐标系转成屏幕坐标系
	ClientToScreen(&point);

	//将屏幕坐标系转成窗口坐标系
	//ScreenToClient(&point);

	OnContextMenu(this, point);
}

//显示上下文菜单
void CMFCPaintingView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	//theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_MENU1, point.x, point.y, this, TRUE);
#endif
}


// CMFCPaintingView 诊断

#ifdef _DEBUG
void CMFCPaintingView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCPaintingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCPaintingDoc* CMFCPaintingView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCPaintingDoc)));
	return (CMFCPaintingDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCPaintingView 消息处理程序

//鼠标左键按下处理函数
void CMFCPaintingView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//保存鼠标左键按下时的位置
	m_LButtonDownPoint = point;
	if (m_Paint == Paint::DRAW_PEN) m_bDown = TRUE;

	CView::OnLButtonDown(nFlags, point);
}

//鼠标左键弹起处理函数
void CMFCPaintingView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	////获取设备上下文
	//CDC* pDC = GetDC();

	////画笔对象(画线样式, 画线宽度, 画线颜色)
	//CPen pen(PS_SOLID, 1, RGB(0, 0, 255));

	////保存旧画笔
	//CPen* pPrewPen = pDC->SelectObject(&pen); //设置新画笔

	////把画笔移动到指定位置
	//pDC->MoveTo(LButtonDownPoint);
	////画线
	//pDC->LineTo(point);

	////恢复旧画笔
	//pDC->SelectObject(pPrewPen);

	////删除(释放)设备上下文
	//ReleaseDC(pDC);

	//设备上下文, 不需要手动删除(释放)设备上下文
	//CClientDC dc(this);

	//画刷
	//CBrush brush(RGB(0, 0, 255));

	//透明画刷
	//GetStockObject() 获取系统已有的画刷对象的句柄
	//FromHandle() 把画刷句柄转成 CBrush 对象
	//CBrush* brush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));

	//CBitmap bitmap;
	////加载Bitmap资源
	//bitmap.LoadBitmap(IDB_BITMAP1);//正常

	////位图画刷
	//CBrush brush(&bitmap);

	////保存旧画刷
	//CBrush* pPrewBrush = dc.SelectObject(&brush); // 设置新画刷

	////画填充矩形
	//dc.Rectangle(CRect(m_LButtonDownPoint, point));

	////恢复旧画刷
	//dc.SelectObject(pPrewBrush);

	//m_bDown = FALSE;

	CClientDC dc(this);
	CPen pen(PS_SOLID, 1, RGB(128, 0, 255));

	//保存旧画笔对象
	CPen* pPrevPen = dc.SelectObject(&pen); //选择新画笔对象

	switch (m_Paint) {
	case Paint::DRAW_LINE:

		//把画笔移动到鼠标左键按下的位置
		dc.MoveTo(m_LButtonDownPoint);
		//在两点之间画线
		dc.LineTo(point);
		
		break;
	case Paint::DRAW_RECT:
		
		//画矩形
		dc.Rectangle(CRect(m_LButtonDownPoint, point));
		
		break;
	case Paint::DRAW_ELLIPSE:
		
		//画椭圆
		dc.Ellipse(CRect(m_LButtonDownPoint, point));
		
		break;
	case Paint::DRAW_PEN:
		//画笔在 OnMouseMove 函数里实现
		m_bDown = FALSE;
		break;
	default: 
		break;
	}

	CView::OnLButtonUp(nFlags, point);
}

//鼠标移动处理函数
void CMFCPaintingView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//CClientDC dc(this);

	//画类似翅膀的图形
	/*if (m_bDown) {
		dc.MoveTo(m_LButtonDownPoint);
		dc.LineTo(point);
	}*/

	//画线(非直线)
	if (m_bDown && m_Paint == Paint::DRAW_PEN) {
		CClientDC dc(this);
		CPen pen(PS_SOLID, 1, RGB(128, 0, 255));

		//保存旧画笔对象
		CPen* pPrevPen = dc.SelectObject(&pen); //选择新画笔对象

		dc.MoveTo(m_LButtonDownPoint);
		dc.LineTo(point);
		m_LButtonDownPoint = point;

		//恢复旧画笔
		dc.SelectObject(pPrevPen);
	}

	////画线(直线) 
	//if (m_bDown) {
	//	if (m_bGline) {
	//		//COLORREF prevPenColor = dc.GetDCPenColor();//保存画笔的颜色
	//		//
	//		////画笔的颜色设置失败
	//		//dc.SetDCPenColor(dc.GetBkColor());         //把画笔的颜色设置为背景色
	//		//
	//		//dc.MoveTo(m_LButtonDownPoint);             //移动到鼠标左键按下的位置
	//		//dc.LineTo(m_MPrevPoint);                   //画线(覆盖上一次的画的线)
	//		//
	//		//dc.SetDCPenColor(prevPenColor);            //恢复画笔颜色

	//		//画笔
	//		CPen pen(PS_SOLID, 1, dc.GetBkColor());
	//		//CBrush* brush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));

	//		//保存旧画笔
	//		CPen* pPrevPen = dc.SelectObject(&pen); //设置新画笔
	//		//CBrush* pPrevBrush = dc.SelectObject(brush);

	//		dc.MoveTo(m_LButtonDownPoint);
	//		dc.LineTo(m_MPrevPoint);

	//		//画矩形
	//		//dc.Rectangle(CRect(m_LButtonDownPoint, m_MPrevPoint));

	//		//恢复旧画笔
	//		dc.SelectObject(pPrevPen);
	//		//dc.SelectObject(pPrevBrush);
	//		
	//	}
	//	dc.MoveTo(m_LButtonDownPoint);
	//	dc.LineTo(point);

	//	m_bGline = TRUE;
	//	m_MPrevPoint = point;
	//	
	//}

	CView::OnMouseMove(nFlags, point);
}


int CMFCPaintingView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	
	//创建定时器
	//SetTimer(ID_TIMER_TEXT, 200, NULL);

	return 0;
}


void CMFCPaintingView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//static COLORREF color(RGB(255, 255, 255));
	//static int r = 0;
	//static int g = 0;
	//static int b = 0;

	//CClientDC dc(this);
	//CString str("MFCTEST.");
	//
	//dc.SetTextColor(RGB(0, 0, 0));
	//wchar_t rgb[24];
	//swprintf_s(rgb, 24, L"r:%d g:%d b:%d", 255-r, 255-g, 255-b);
	//
	////输出文本
	////dc.TextOut(0, 0, rgb);
	//
	////获取字符串的宽度和高度
	////CSize sz = dc.GetTextExtent(rgb);

	//CPen pen(PS_SOLID, 1, RGB(255, 255, 255));
	//CBrush* brush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));

	////保存旧画笔
	//CPen* pPrevPen = dc.SelectObject(&pen); //设置新画笔

	////画矩形
	//dc.Rectangle(CRect(0, 0, 150, 30));

	////恢复旧画刷
	//dc.SelectObject(pPrevPen);

	////在矩形内输出文本
	//dc.DrawText(rgb, CRect(0, 0, 150, 30), DT_LEFT);

	////设置文本颜色
	//dc.SetTextColor(color);

	//color = RGB(255-r, 255-g, 255-b);



	//if (r < 255) r += 5;
	//else if (g < 255) g += 5;
	//else if (b < 255) b += 5;
	//else {
	//	r = g = b = 0;
	//}

	//switch (nIDEvent) {
	//case ID_TIMER_TEXT:	
	//	//dc.TextOut(100, 100, str);
	//	
	//	//在矩形内输出文本
	//	dc.DrawText(str, CRect(100, 100, 200, 130), DT_LEFT);
	//	break;

	//default: break;
	//}

	CView::OnTimer(nIDEvent);
}


void CMFCPaintingView::OnDrawLine()
{
	// TODO: 在此添加命令处理程序代码
	m_Paint = Paint::DRAW_LINE;
}


void CMFCPaintingView::OnDrawRect()
{
	// TODO: 在此添加命令处理程序代码
	m_Paint = Paint::DRAW_RECT;
}


void CMFCPaintingView::OnDrawEllipse()
{
	// TODO: 在此添加命令处理程序代码
	m_Paint = Paint::DRAW_ELLIPSE;
}


void CMFCPaintingView::OnDrawPen()
{
	// TODO: 在此添加命令处理程序代码
	m_Paint = Paint::DRAW_PEN;
}


void CMFCPaintingView::OnCls()
{
	// TODO: 在此添加命令处理程序代码
	Invalidate();
}


void CMFCPaintingView::OnUpdateDrawLine(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	
	//如果m_Paint等于Paint::DRAW_LINE， 则在画图菜单选项 画线 前打勾
	pCmdUI->SetCheck(m_Paint == Paint::DRAW_LINE);
}


void CMFCPaintingView::OnUpdateDrawRect(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	
	//如果m_Paint等于Paint::DRAW_RECT， 则在画图菜单选项 画矩形 前打勾
	pCmdUI->SetCheck(m_Paint == Paint::DRAW_RECT);
}


void CMFCPaintingView::OnUpdateDrawEllipse(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码

	//如果m_Paint等于Paint::DRAW_ELLIPSE， 则在画图菜单选项 画椭圆 前打勾
	pCmdUI->SetCheck(m_Paint == Paint::DRAW_ELLIPSE);
}


void CMFCPaintingView::OnUpdateDrawPen(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码

	//如果m_Paint等于Paint::DRAW_PEN， 则在画图菜单选项 画笔 前打勾
	pCmdUI->SetCheck(m_Paint == Paint::DRAW_PEN);
}
