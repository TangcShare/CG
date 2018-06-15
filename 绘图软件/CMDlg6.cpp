// CMDlg6.cpp : implementation file
//

#include "stdafx.h"
#include "CGDraw.h"
#include "CMDlg6.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCMDlg6 dialog
BOOL CCMDlg6::Create(){
	return CDialog::Create(CCMDlg6::IDD);
}

CCMDlg6::CCMDlg6(CWnd* pParent /*=NULL*/)
	: CDialog(CCMDlg6::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCMDlg6)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CCMDlg6::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCMDlg6)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCMDlg6, CDialog)
	//{{AFX_MSG_MAP(CCMDlg6)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCMDlg6 message handlers

void CCMDlg6::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	
}
