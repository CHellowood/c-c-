
// MFCPaintingView.h: CMFCPaintingView 类的接口
//

#pragma once

#define ID_TIMER_TEXT 2020

//画图菜单
typedef enum class PaintMenu {
	DRAW_LINE,    //画线
	DRAW_RECT,    //画矩形
	DRAW_ELLIPSE, //画椭圆
	DRAW_PEN      //画笔
}Paint; 

class CMFCPaintingView : public CView
{
protected: // 仅从序列化创建
	CMFCPaintingView() noexcept;
	DECLARE_DYNCREATE(CMFCPaintingView)

// 特性
public:
	CMFCPaintingDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCPaintingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
protected:
	CPoint m_LButtonDownPoint; //鼠标左键按下时的位置
	bool   m_bDown;            //鼠标左键按下
	bool   m_bGline;           //鼠标按下后是否有画线
	CPoint m_MPrevPoint;       //保存鼠标按下后画的线的结束位置
	Paint  m_Paint;            //画形

public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDrawLine();
	afx_msg void OnDrawRect();
	afx_msg void OnDrawEllipse();
	afx_msg void OnDrawPen();
	afx_msg void OnCls();
	afx_msg void OnUpdateDrawLine(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDrawRect(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDrawEllipse(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDrawPen(CCmdUI* pCmdUI);
	afx_msg void OnDrawSet();
protected:
	int m_nLineStyle;         //线的样式
	UINT m_nLineWidth;        //画笔线宽
	COLORREF m_color;         //画线颜色
	CMetaFileDC m_dcMetaFile; //元文件DC
public:
	afx_msg void OnLineStyle1();
	afx_msg void OnUpdateLineStyle1(CCmdUI* pCmdUI);
	afx_msg void OnLineStyle2();
	afx_msg void OnUpdateLineStyle2(CCmdUI* pCmdUI);
	afx_msg void OnLineStyle3();
	afx_msg void OnUpdateLineStyle3(CCmdUI* pCmdUI);
};

#ifndef _DEBUG  // MFCPaintingView.cpp 中的调试版本
inline CMFCPaintingDoc* CMFCPaintingView::GetDocument() const
   { return reinterpret_cast<CMFCPaintingDoc*>(m_pDocument); }
#endif

