// CMDlg1.cpp : implementation file
//

#include "stdafx.h"
#include "CGDraw.h"
#include "CMDlg1.h"
#include "CGDrawView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCMDlg1 dialog


CCMDlg1::CCMDlg1(CWnd* pParent /*=NULL*/)
	: CDialog(CCMDlg1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCMDlg1)
	m_k = 0.0;
	m_X1 = 0.0;
	m_Y1 = 0.0;
	//}}AFX_DATA_INIT
}


void CCMDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCMDlg1)
	DDX_Text(pDX, IDC_EDITK1, m_k);
	DDX_Text(pDX, IDC_EDITX1, m_X1);
	DDX_Text(pDX, IDC_EDITY1, m_Y1);
	//}}AFX_DATA_MAP
}
BOOL CCMDlg1::Create(){
	return CDialog::Create(CCMDlg1::IDD);
}

BEGIN_MESSAGE_MAP(CCMDlg1, CDialog)
	//{{AFX_MSG_MAP(CCMDlg1)
	ON_BN_CLICKED(IDOK, OnOK1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN4, OnDeltaposSpin4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCMDlg1 message handlers

void CCMDlg1::OnOK1() 
{
	UpdateData(TRUE);
	CPoint pt;
	pt.x=this->m_X1;
	pt.y=this->m_Y1;
	this->m_pView1->m_pt_bl.Add(pt);
	this->m_pView1->Invalidate();
	CDialog::OnOK();
// TODO: Add your control notification handler code here
	
}

void CCMDlg1::OnDeltaposSpin4(NMHDR* pNMHDR, LRESULT* pResult) 
{

	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	UpdateData(TRUE);
	this->m_k-=0.1*pNMUpDown->iDelta;
m_pView1->dbx=2;
		double x_ledge,y_ledge;
		x_ledge=this->m_X1;
		y_ledge=this->m_Y1;
	m_pView1->ScaleTransform2D(m_pView1->m_Matrix,x_ledge,y_ledge,1/m_k);
	m_pView1->GetNewPoint(m_pView1->m_pt_array4,m_pView1->m_Matrix);
	m_pView1->Invalidate(TRUE);

	UpdateData(FALSE);
	*pResult = 0;
}
