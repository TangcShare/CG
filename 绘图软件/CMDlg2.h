#if !defined(AFX_CMDLG2_H__4065C517_9008_48E2_9BBB_E0FCAC87A024__INCLUDED_)
#define AFX_CMDLG2_H__4065C517_9008_48E2_9BBB_E0FCAC87A024__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CMDlg2.h : header file
//
class CCGDrawView;
/////////////////////////////////////////////////////////////////////////////
// CCMDlg2 dialog

class CCMDlg2 : public CDialog
{
// Construction
public:
	CCMDlg2(CWnd* pParent = NULL);   // standard constructor
	BOOL Create();
	CCGDrawView *m_pView2;
// Dialog Data
	//{{AFX_DATA(CCMDlg2)
	enum { IDD = IDD_MDLG2 };
	int		m_X2;
	int		m_Y2;
	int		m_ROT;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCMDlg2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCMDlg2)
	afx_msg void OnDeltaposSpin1(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMDLG2_H__4065C517_9008_48E2_9BBB_E0FCAC87A024__INCLUDED_)
