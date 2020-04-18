#pragma once

#define DEFAULT_LINE_STYLE PS_SOLID     //默认样式
#define DEFAULT_LINE_WIDTH 1            //默认线宽
#define DEFAULT_COLOR      RGB(0, 0, 0) //默认颜色

// SetPen 对话框

//设置画笔
class SetPen : public CDialogEx
{
	DECLARE_DYNAMIC(SetPen)

public:
	SetPen(CWnd* pParent = nullptr);   // 标准构造函数
	SetPen(int lineStyle, int lineWidth, COLORREF color);
	virtual ~SetPen();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SET_PEN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	afx_msg void OnBnClickedPenColor();

	DECLARE_MESSAGE_MAP()
public:
	// 画笔线宽
	int m_nLineWidth;
	// 画笔颜色
	COLORREF m_color;
	// 线的样式
	int m_nLineStyle;
	afx_msg void OnBnClickedLineStyle1();
	afx_msg void OnBnClickedLineStyle2();
	afx_msg void OnBnClickedLineStyle3();
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
