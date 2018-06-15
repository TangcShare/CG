#if !defined(AFX_CMDLG3_H__A226A89F_C50D_4017_B8A2_2CA75815426E__INCLUDED_)
#define AFX_CMDLG3_H__A226A89F_C50D_4017_B8A2_2CA75815426E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CMDlg3.h : header file
//
class CCGDrawView;
/////////////////////////////////////////////////////////////////////////////
// CCMDlg3 dialog

class CCMDlg3 : public CDialog
{
// Construction
public:
	CCMDlg3(CWnd* pParent = NULL);   // standard constructor
	BOOL Create();
	CCGDrawView *m_pView3;
// Dialog Data
	//{{AFX_DATA(CCMDlg3)
	enum { IDD = IDD_MDLG3 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCMDlg3)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCMDlg3)
	afx_msg void Onmir1();
	afx_msg void Onmir2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMDLG3_H__A226A89F_C50D_4017_B8A2_2CA75815426E__INCLUDED_)
