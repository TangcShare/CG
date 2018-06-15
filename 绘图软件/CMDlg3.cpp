// CMDlg3.cpp : implementation file
//

#include "stdafx.h"
#include "CGDraw.h"
#include "CMDlg3.h"
#include "CGDrawView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCMDlg3 dialog


CCMDlg3::CCMDlg3(CWnd* pParent /*=NULL*/)
	: CDialog(CCMDlg3::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCMDlg3)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CCMDlg3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCMDlg3)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}
BOOL CCMDlg3::Create(){
	return CDialog::Create(CCMDlg3::IDD);
}

BEGIN_MESSAGE_MAP(CCMDlg3, CDialog)
	//{{AFX_MSG_MAP(CCMDlg3)
	ON_BN_CLICKED(IDC_mir1, Onmir1)
	ON_BN_CLICKED(IDC_mir2, Onmir2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCMDlg3 message handlers

void CCMDlg3::Onmir1() 
{
	m_pView3->duichenzhou=1;
	// TODO: Add your control notification handler code here
	
}

void CCMDlg3::Onmir2() 
{
	m_pView3->MirrorTransform2D(m_pView3->m_Matrix,m_pView3->m_pt_jx.GetAt(0).x,m_pView3->m_pt_jx.GetAt(0).y,m_pView3->m_pt_jx.GetAt(1).x,m_pView3->m_pt_jx.GetAt(1).y);
	m_pView3->GetNewPoint(m_pView3->m_pt_array4,m_pView3->m_Matrix);
	m_pView3->Invalidate(TRUE);// TODO: Add your control notification handler code here
	
}
