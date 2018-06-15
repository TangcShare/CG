// CMDlg2.cpp : implementation file
//

#include "stdafx.h"
#include "CGDraw.h"
#include "CMDlg2.h"
#include "CGDrawView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCMDlg2 dialog


CCMDlg2::CCMDlg2(CWnd* pParent /*=NULL*/)
	: CDialog(CCMDlg2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCMDlg2)
	m_X2 = 0;
	m_Y2 = 0;
	m_ROT = 0;
	//}}AFX_DATA_INIT
}


void CCMDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCMDlg2)
	DDX_Text(pDX, IDC_EDITX2, m_X2);
	DDX_Text(pDX, IDC_EDITY2, m_Y2);
	DDX_Text(pDX, IDC_EDITROT, m_ROT);
	//}}AFX_DATA_MAP
}
BOOL CCMDlg2::Create(){
	return CDialog::Create(CCMDlg2::IDD);
}
BEGIN_MESSAGE_MAP(CCMDlg2, CDialog)
	//{{AFX_MSG_MAP(CCMDlg2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, OnDeltaposSpin1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCMDlg2 message handlers

void CCMDlg2::OnDeltaposSpin1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	this->m_ROT-=1*pNMUpDown->iDelta;
	{
	m_pView2->dbx=1;	
	double angle;
	//int x0,x1,y0,y1;
	double x_ledge,y_ledge;
	double m_Matrix0[3][3];
	x_ledge = this->m_X2;
	y_ledge = this->m_Y2;
	angle=(-1)*pNMUpDown->iDelta;

	this->m_pView2->RotateTransform2D(m_Matrix0,x_ledge,y_ledge,angle);
	this->m_pView2->GetNewPoint(this->m_pView2->m_pt_array4,m_Matrix0);
	this->m_pView2->Invalidate(TRUE);
	}
	UpdateData(FALSE);
	*pResult = 0;
}

void CCMDlg2::OnOK() 
{
	// TODO: Add extra validation here
	
		UpdateData(TRUE);
	CPoint pt;
	pt.x=this->m_X2;
	pt.y=this->m_Y2;
		this->m_pView2->m_pt_rot.Add(pt);
	this->m_pView2->Invalidate();
	
	//CDialog::OnOK();

	//RotateDOT(this->m_pView1->m_line_array,m_angle,m_pView1->m_pt_array.GetAt(0).x,m_pView1->m_pt_array.GetAt(0).y,1);
}
