// CMDlg.cpp : implementation file
//
#include "CGDrawView.h"
#include "stdafx.h"
#include "CGDraw.h"
#include "CMDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCMDlg dialog


CCMDlg::CCMDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCMDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCMDlg)
	m_X = 0;
	m_Y = 0;
	//}}AFX_DATA_INIT
}


void CCMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCMDlg)
	DDX_Text(pDX, IDC_EDIT1, m_X);
	DDX_Text(pDX, IDC_EDIT2, m_Y);
	//}}AFX_DATA_MAP
}
BOOL CCMDlg::Create(){
	return CDialog::Create(CCMDlg::IDD);
}


BEGIN_MESSAGE_MAP(CCMDlg, CDialog)
	//{{AFX_MSG_MAP(CCMDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCMDlg message handlers

void CCMDlg::OnOK() 
{
	UpdateData(TRUE);

/*	CPoint pt1;
	pt1.x=this->m_X;
	pt1.y=this->m_Y;
	this->m_pView->m_pt_array.Add(pt1);
	this->m_pView->Invalidate();
*/
	CPoint pt;
	pt.x=this->m_X;
	pt.y=this->m_Y;
	this->m_pView->m_pt_array.Add(pt);
	this->m_pView->Invalidate();
// TODO: Add extra validation here
	
	
}
