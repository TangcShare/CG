// CGDraw.h : main header file for the CGDRAW application
//

#if !defined(AFX_CGDRAW_H__31698A5C_6D25_49C0_BFE3_41387A4ED105__INCLUDED_)
#define AFX_CGDRAW_H__31698A5C_6D25_49C0_BFE3_41387A4ED105__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCGDrawApp:
// See CGDraw.cpp for the implementation of this class
//

class CCGDrawApp : public CWinApp
{
public:
	CCGDrawApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCGDrawApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCGDrawApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CGDRAW_H__31698A5C_6D25_49C0_BFE3_41387A4ED105__INCLUDED_)
