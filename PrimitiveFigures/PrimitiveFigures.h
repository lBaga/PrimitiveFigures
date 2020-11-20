
// PrimitiveFigures.h : main header file for the PrimitiveFigures application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CPrimitiveFiguresApp:
// See PrimitiveFigures.cpp for the implementation of this class
//

class CPrimitiveFiguresApp : public CWinApp
{
public:
	CPrimitiveFiguresApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPrimitiveFiguresApp theApp;
