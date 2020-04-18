// SetPen.cpp: 实现文件
//

#include "pch.h"
#include "MFCPainting.h"
#include "SetPen.h"
#include "afxdialogex.h"


// SetPen 对话框

IMPLEMENT_DYNAMIC(SetPen, CDialogEx)

SetPen::SetPen(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SET_PEN, pParent)
	, m_nLineStyle(DEFAULT_LINE_STYLE)
	, m_nLineWidth(DEFAULT_LINE_WIDTH)
	, m_color(DEFAULT_COLOR)
{

}

SetPen::SetPen(int lineStyle, int lineWidth, COLORREF color)
	: CDialogEx(IDD_SET_PEN, nullptr)
	, m_nLineStyle(lineStyle)
	, m_nLineWidth(lineWidth)
	, m_color(color)
{
}

SetPen::~SetPen()
{
}

void SetPen::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Slider(pDX, IDC_LINE_WIDTH, m_nLineWidth);
	//DDV_MinMaxUInt(pDX, m_nLineWidth, 1, 30);
	DDX_Radio(pDX, IDC_LINE_STYLE1, m_nLineStyle);
}


BEGIN_MESSAGE_MAP(SetPen, CDialogEx)
	ON_BN_CLICKED(IDC_PEN_COLOR, &SetPen::OnBnClickedPenColor)
	ON_BN_CLICKED(IDC_LINE_STYLE1, &SetPen::OnBnClickedLineStyle1)
	ON_BN_CLICKED(IDC_LINE_STYLE2, &SetPen::OnBnClickedLineStyle2)
	ON_BN_CLICKED(IDC_LINE_STYLE3, &SetPen::OnBnClickedLineStyle3)
	ON_WM_PAINT()
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// SetPen 消息处理程序


void SetPen::OnBnClickedPenColor()
{
	// TODO: 在此添加控件通知处理程序代码
	CColorDialog colDlg;
	colDlg.m_cc.Flags |= CC_RGBINIT;
	colDlg.m_cc.rgbResult = m_color;

	if (IDOK == colDlg.DoModal()) {
		m_color = colDlg.m_cc.rgbResult;

		//清除当前窗口
		Invalidate();
	}
}


void SetPen::OnBnClickedLineStyle1()
{
	// TODO: 在此添加控件通知处理程序代码
	
	//清除当前窗口
	Invalidate();
}


void SetPen::OnBnClickedLineStyle2()
{
	// TODO: 在此添加控件通知处理程序代码

	//清除当前窗口
	Invalidate();
}


void SetPen::OnBnClickedLineStyle3()
{
	// TODO: 在此添加控件通知处理程序代码

	//清除当前窗口
	Invalidate();
}


void SetPen::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	//更新数据
	UpdateData();

	CPen pen(m_nLineStyle, m_nLineWidth, m_color);

	//选择新画笔返回旧画笔
	CPen* pOldPen = dc.SelectObject(&pen);

	//保存画笔设置里 示例 控件的坐标
	CRect rect;

	//根据控件ID获取控件， 根据获取到的控件获取坐标（屏幕坐标）
	GetDlgItem(IDC_LINE_EXAMPLE)->GetWindowRect(&rect);

	//把屏幕坐标转成窗口坐标（客户区坐标）
	ScreenToClient(&rect);

	dc.MoveTo(rect.left + 10, rect.top + rect.Height() / 2);
	dc.LineTo(rect.right - 10, rect.top + rect.Height() / 2);

	//恢复旧画笔
	dc.SelectObject(pOldPen);
}


BOOL SetPen::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	//获取滑块控件
	CSliderCtrl* slider = (CSliderCtrl*)GetDlgItem(IDC_LINE_WIDTH);

	slider->SetRange(1, 10);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void SetPen::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//保存画笔设置里 示例 控件的坐标
	CRect rect;

	//根据控件ID获取控件， 根据获取到的控件获取坐标（屏幕坐标）
	GetDlgItem(IDC_LINE_EXAMPLE)->GetWindowRect(&rect);

	//把屏幕坐标转成窗口坐标（客户区坐标）
	ScreenToClient(&rect);

	//清除指定区域
	InvalidateRect(&rect);

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}
