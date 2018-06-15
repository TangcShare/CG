#if !defined(AFX_CMDLG4_H__B999B4B5_B071_47CE_8286_057EC0608572__INCLUDED_)
#define AFX_CMDLG4_H__B999B4B5_B071_47CE_8286_057EC0608572__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CMDlg4.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCMDlg4 dialog
class CCGDrawView;
class CCMDlg4 : public CDialog
{
// Construction
public:
	CCMDlg4(CWnd* pParent = NULL);   // standard constructor
	BOOL Create();
	CCGDrawView *m_pView4;
	int m_DrawType;
	BOOL m_isDraw;
	int Mflag;
// Dialog Data
	//{{AFX_DATA(CCMDlg4)
	enum { IDD = IDD_MDLG4 };
	CComboBox	m_iRatateAxis;
	int		m_X4;
	int		m_Y4;
	double	m_lashen;
	double	m_xuanzhuan;
	double	m_suofang;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCMDlg4)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCMDlg4)
	afx_msg void On3d();
	afx_msg void OnDeltaposSpin1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpin2(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	afx_msg void OnOutofmemorySpin3(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void Onmir3();
	afx_msg void Onmir4();
	afx_msg void Onmir6();
	afx_msg void Onmir5();
	afx_msg void OnDeltaposSpin3(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMDLG4_H__B999B4B5_B071_47CE_8286_057EC0608572__INCLUDED_)
