#if !defined(AFX_CMDLG1_H__B718E1B1_AF92_4FE7_82B2_6EC72BCF2FAB__INCLUDED_)
#define AFX_CMDLG1_H__B718E1B1_AF92_4FE7_82B2_6EC72BCF2FAB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CMDlg1.h : header file
//
class CCGDrawView;
/////////////////////////////////////////////////////////////////////////////
// CCMDlg1 dialog

class CCMDlg1 : public CDialog
{
// Construction
public:
	CCMDlg1(CWnd* pParent = NULL);   // standard constructor
	BOOL Create();
	CCGDrawView *m_pView1;
// Dialog Data
	//{{AFX_DATA(CCMDlg1)
	enum { IDD = IDD_MDLG1 };
	double	m_k;
	double	m_X1;
	double	m_Y1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCMDlg1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCMDlg1)
	afx_msg void OnOK1();
	afx_msg void OnOutofmemorySpin1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpin4(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMDLG1_H__B718E1B1_AF92_4FE7_82B2_6EC72BCF2FAB__INCLUDED_)
