
#if !defined(AFX_CMDLG_H__58DD2D53_F9A2_4826_8EC4_6F9291033E69__INCLUDED_)
#define AFX_CMDLG_H__58DD2D53_F9A2_4826_8EC4_6F9291033E69__INCLUDED_
#include "CGDrawView.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CMDlg.h : header file
//
class CCGDrawView;
/////////////////////////////////////////////////////////////////////////////
// CCMDlg dialog

class CCMDlg : public CDialog
{
// Construction
public:
	CCMDlg(CWnd* pParent = NULL);   // standard constructor
	BOOL Create();
	CCGDrawView *m_pView;
// Dialog Data
	//{{AFX_DATA(CCMDlg)
	enum { IDD = IDD_MDLG };
	int		m_X;
	int		m_Y;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCMDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCMDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMDLG_H__58DD2D53_F9A2_4826_8EC4_6F9291033E69__INCLUDED_)
