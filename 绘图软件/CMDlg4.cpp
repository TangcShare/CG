// CMDlg4.cpp : implementation file
//

#include "stdafx.h"
#include "CGDraw.h"
#include "CMDlg4.h"
#include "CGDrawView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCMDlg4 dialog


CCMDlg4::CCMDlg4(CWnd* pParent /*=NULL*/)
	: CDialog(CCMDlg4::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCMDlg4)
	m_X4 = 0;
	m_Y4 = 0;
	m_lashen = 0.0;
	m_xuanzhuan = 0.0;
	m_suofang = 0.0;
	 Mflag=0;
	//}}AFX_DATA_INIT
}


void CCMDlg4::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCMDlg4)
	DDX_Control(pDX, IDC_COMBO2, m_iRatateAxis);
	DDX_Text(pDX, IDC_EDIT1, m_X4);
	DDX_Text(pDX, IDC_EDIT2, m_Y4);
	DDX_Text(pDX, IDC_EDITlashen, m_lashen);
	DDX_Text(pDX, IDC_EDITxuanzhuan, m_xuanzhuan);
	DDX_Text(pDX, IDC_EDITsuofang, m_suofang);
	//}}AFX_DATA_MAP
}
BOOL CCMDlg4::Create(){
	return CDialog::Create(CCMDlg4::IDD);
}

BEGIN_MESSAGE_MAP(CCMDlg4, CDialog)
	//{{AFX_MSG_MAP(CCMDlg4)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, OnDeltaposSpin1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN2, OnDeltaposSpin2)
	ON_NOTIFY(NM_OUTOFMEMORY, IDC_SPIN3, OnOutofmemorySpin3)
	ON_BN_CLICKED(IDC_mir3, Onmir3)
	ON_BN_CLICKED(IDC_mir4, Onmir4)
	ON_BN_CLICKED(IDC_mir6, Onmir6)
	ON_BN_CLICKED(IDC_mir5, Onmir5)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN3, OnDeltaposSpin3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCMDlg4 message handlers



void CCMDlg4::OnDeltaposSpin1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here

UpdateData(TRUE);
m_pView4->m_DrawType = 10;

this->m_lashen-=1*pNMUpDown->iDelta;
this->m_pView4->m_dblAngle=this->m_xuanzhuan;
this->m_pView4->m_zlength=this->m_lashen;

this->m_pView4->Extern();
*pResult = 0;
UpdateData(FALSE);
}

void CCMDlg4::OnDeltaposSpin2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
UpdateData(TRUE);
	// TODO: Add your control notification handler code here
m_pView4->m_DrawType = 10;

	this->m_xuanzhuan+=(-1)*pNMUpDown->iDelta;
this->m_pView4->m_dblAngle=this->m_xuanzhuan;
int zhou=m_iRatateAxis.GetCurSel();
if(zhou==0)
	this->m_pView4->m_iRatateAxis=3;
else if(zhou==1)
	this->m_pView4->m_iRatateAxis=1;
else if(zhou==2)
	this->m_pView4->m_iRatateAxis=2;
this->m_pView4->m_zlength=this->m_lashen;
this->m_pView4->Rotate();
	*pResult = 0;
UpdateData(FALSE);
}

void CCMDlg4::OnOK() 
{
	
	// TODO: Add your control notification handler code here*/	
	CDialog::OnOK();
}

void CCMDlg4::OnOutofmemorySpin3(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;

	*pResult = 0;

}

void CCMDlg4::Onmir3() 
{
	m_pView4->m_DrawType = 10;
	this->m_pView4->jingxiang1();
	

	// TODO: Add your control notification handler code here*/
	
}

void CCMDlg4::Onmir4() 
{
	// TODO: Add your control notification handler code here
	m_pView4->m_DrawType = 10;
	this->m_pView4->jingxiang2();
}

void CCMDlg4::Onmir5() 
{
	// TODO: Add your control notification handler code here
	m_pView4->m_DrawType = 10;
	this->m_pView4->jingxiang3();
}

void CCMDlg4::Onmir6() 
{
	// TODO: Add your control notification handler code here
	
}



void CCMDlg4::OnDeltaposSpin3(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	double m_matrixx[4][4];
	m_pView4->m_DrawType = 10;

	this->m_suofang-=0.1*pNMUpDown->iDelta;
	this->m_pView4->m_3dk=this->m_suofang;
	this->m_pView4->suofang();
	*pResult = 0;
	UpdateData(FALSE);
	
}
