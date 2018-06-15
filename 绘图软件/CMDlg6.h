#if !defined(AFX_CMDLG6_H__BE292F38_889E_4B4A_A637_30B3F1492CB0__INCLUDED_)
#define AFX_CMDLG6_H__BE292F38_889E_4B4A_A637_30B3F1492CB0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CMDlg6.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCMDlg6 dialog

class CCMDlg6 : public CDialog
{
// Construction
public:
	CCMDlg6(CWnd* pParent = NULL);   // standard constructor
BOOL Create();
// Dialog Data
	//{{AFX_DATA(CCMDlg6)
	enum { IDD = IDD_MDLG6 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCMDlg6)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCMDlg6)
	afx_msg void OnRadio1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMDLG6_H__BE292F38_889E_4B4A_A637_30B3F1492CB0__INCLUDED_)
