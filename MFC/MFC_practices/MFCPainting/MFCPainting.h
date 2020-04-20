
// MFCPainting.h: MFCPainting 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"       // 主符号

//绘图模式
enum class DrawType {
	DRAW_LINE,    //画线
	DRAW_RECT,    //画矩形
	DRAW_ELLIPSE, //画椭圆
	DRAW_PEN      //画笔
};

// CMFCPaintingApp:
// 有关此类的实现，请参阅 MFCPainting.cpp
//

class CMFCPaintingApp : public CWinAppEx
{
public:
	CMFCPaintingApp() noexcept;


// 重写
public:
	virtual BOOL InitInstance();

// 实现
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
};

extern CMFCPaintingApp theApp;
