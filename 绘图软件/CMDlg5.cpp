// CMDlg5.cpp : implementation file
//

#include "stdafx.h"
#include "CGDraw.h"
#include "CMDlg5.h"
#include "CGDrawView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCMDlg5 dialog
BOOL CCMDlg5::Create(){
	return CDialog::Create(CCMDlg5::IDD);
}


CCMDlg5::CCMDlg5(CWnd* pParent /*=NULL*/)
	: CDialog(CCMDlg5::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCMDlg5)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CCMDlg5::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCMDlg5)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCMDlg5, CDialog)
	//{{AFX_MSG_MAP(CCMDlg5)
//	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCMDlg5 message handlers


//Æô¶¯¶¯»­
void CCMDlg5::OnButton2() 
{
	// TODO: Add your control notification handler code here
this->m_pView5->SetTimer(1,100,NULL);	
}

void CCMDlg5::OnButton4() 
{
	// TODO: Add your control notification handler code here
	this->m_pView5->KillTimer(1);
}
