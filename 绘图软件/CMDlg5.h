#if !defined(AFX_CMDLG5_H__24D10299_D368_44FF_BFAD_F2C39684731E__INCLUDED_)
#define AFX_CMDLG5_H__24D10299_D368_44FF_BFAD_F2C39684731E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CMDlg5.h : header file
//
class CCGDrawView;
/////////////////////////////////////////////////////////////////////////////
// CCMDlg5 dialog

class CCMDlg5 : public CDialog
{
// Construction
public:
	CCMDlg5(CWnd* pParent = NULL);   // standard constructor
BOOL Create();
CCGDrawView *m_pView5;
// Dialog Data
	//{{AFX_DATA(CCMDlg5)
	enum { IDD = IDD_MDLG5 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCMDlg5)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCMDlg5)
	afx_msg void OnMove();
//afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();

	afx_msg void OnButton4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMDLG5_H__24D10299_D368_44FF_BFAD_F2C39684731E__INCLUDED_)
