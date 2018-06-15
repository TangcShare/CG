// CGDrawView.cpp : implementation of the CCGDrawView class
//
#include<stdio.h> 
//#include <conio.h> 
#include <stdlib.h>
#include "stdafx.h"
#include "CGDraw.h"
#include <math.h>
#include "CGDrawDoc.h"
#include "CGDrawView.h"
#include "BasicClass.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////
#define PI 3.1415926
/////////////////////////////////////////////////////////////////////////////
// CCGDrawView

IMPLEMENT_DYNCREATE(CCGDrawView, CView)

BEGIN_MESSAGE_MAP(CCGDrawView, CView)
	//{{AFX_MSG_MAP(CCGDrawView)
	ON_COMMAND(ID_DRAWPOINT, OnDrawpoint)
	ON_COMMAND(ID_DRAWLINE, OnDrawline)
	ON_COMMAND(ID_DRAWPOL, OnDrawpol)
	ON_COMMAND(ID_FILL, OnFill)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_CLEAR, OnClear)
	ON_UPDATE_COMMAND_UI(ID_FILL, OnUpdateFill)
	ON_COMMAND(ID_CUT, OnCut)
	ON_COMMAND(ID_DRAWREC, OnDrawrec)
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_MIRROR, OnMirror)
	ON_COMMAND(ID_ZOOM, OnZoom)
	ON_COMMAND(ID_ROTATE, OnRotate)
	ON_COMMAND(ID_3D, On3d)
	ON_COMMAND(ID_DRAWPOL1, OnDrawpol1)
	ON_COMMAND(ID_MOVE, OnMove)
	ON_COMMAND(ID_DEL, OnDel)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCGDrawView construction/destruction

CCGDrawView::CCGDrawView()
{
	m_isDraw = true;//��ǰ���ڻ�ͼ״̬
	step=0;
	step1=0;
	fillFlag=0;
	//���������Ի���
	this->m_MDlg=new CCMDlg();
	this->m_MDlg->m_pView=this;
	// TODO: add construction code here
	rect.left=0;
	rect.right=0;
	rect.bottom=0;
	rect.top=0;
	xx=0;
	yy=0;
	this->m_MDlg1=new CCMDlg1();
	this->m_MDlg1->m_pView1=this;

	this->m_MDlg2=new CCMDlg2();
	this->m_MDlg2->m_pView2=this;

	this->m_MDlg3=new CCMDlg3();
	this->m_MDlg3->m_pView3=this;

	this->m_MDlg4=new CCMDlg4();
	this->m_MDlg4->m_pView4=this;

	this->m_MDlg5=new CCMDlg5();
	this->m_MDlg5->m_pView5=this;
	this->m_MDlg6=new CCMDlg6();
	//this->m_MDlg6->m_pView6=this;
}

CCGDrawView::~CCGDrawView()
{
	if(this->m_MDlg!=NULL)
	{
		delete this->m_MDlg;
	}
	if(this->m_MDlg1!=NULL)
	{
		delete this->m_MDlg1;
	}
	if(this->m_MDlg2!=NULL)
	{
		delete this->m_MDlg2;
	}
	if(this->m_MDlg3!=NULL)
	{
		delete this->m_MDlg3;
	}
	if(this->m_MDlg4!=NULL)
	{
		delete this->m_MDlg4;
	}
	if(this->m_MDlg5!=NULL)
	{
		delete this->m_MDlg5;
	}
	if(this->m_MDlg6!=NULL)
	{
		delete this->m_MDlg6;
	}
}

BOOL CCGDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCGDrawView drawing

void CCGDrawView::OnDraw(CDC* pDC)
{
	CCGDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
//////����
	if(m_DrawType ==1)
	{
		CPoint pt;
		CString str;
		for(int i=0;i<this->m_pt_array3.GetSize();i++)
		{
			pt=this->m_pt_array3.GetAt(i);//�õ���i����
		//��ʾ�㣬��Ϊһ���ظ�����ʾ�ǳ������ԣ��ʰ��������ĵ�Ҳ���Ƴ���
			pDC->SetPixel(pt.x,pt.y,RGB(255,0,0));
			pDC->SetPixel(pt.x,pt.y-1,RGB(255,0,0));
			pDC->SetPixel(pt.x,pt.y+1,RGB(255,0,0));
			pDC->SetPixel(pt.x-1,pt.y,RGB(255,0,0));
			pDC->SetPixel(pt.x+1,pt.y,RGB(255,0,0));
		//���ֱ�ע�������ֵ
			str.Format("(%d,%d)",pt.x,pt.y);
			pDC->TextOut(pt.x+5,pt.y+5,str);	
		}	
	
	}
//////��ֱ��
	if(m_DrawType ==2)
	{
		if(this->m_line_array.GetSize()>0)
		{
			CLine line1;
			for(int i=0;i<this->m_line_array.GetSize();i++)
			{		
				line1=this->m_line_array.GetAt(i);
				DDA_Line(pDC,line1.pt1,line1.pt2,RGB(255,0,0));
				double m_x0,double m_y0,double m_x1,double m_y1;
				m_x0=line1.pt1.x;
				m_y0=line1.pt1.y;
				m_x1=line1.pt2.x;
				m_y1=line1.pt2.y;
			}
	
		}
	}

	//////�����
	if(m_DrawType ==3)
	{
	
		CPoint startPoint, endPoint;
		if(this->m_pt_array4.GetSize()>1)
		{
		//�������Ͽ�ʼ����
			startPoint=this->m_pt_array4.GetAt(0);//�õ���1����
			for(int i=1;i<this->m_pt_array4.GetSize();i++)
			{//ѭ������		
				endPoint=this->m_pt_array4.GetAt(i);
				DDA_Line(pDC,startPoint,endPoint,RGB(255,0,0));
				startPoint=endPoint;
			}
		}		
		
	}
if(m_DrawType ==11)
	{
		CLine line;	
		for(int i=0;i<this->m_line_array.GetSize();i++)
		{
			line=this->m_line_array.GetAt(i);
			DDA_Line(pDC,line.pt1,line.pt2,RGB(255,0,0));
			//step=0;
		} 
	
		
	}
	/////���
	if(m_DrawType ==4)
	{
		if(fillFlag==1)
		{
			scanTransfer(pDC);
		}
	}
if(m_DrawType ==5)
{
	
}

if(m_DrawType ==6)
	{
		CLine line;	
		for(int i=0;i<this->m_line_array.GetSize();i++)
		{
			line=this->m_line_array.GetAt(i);
			DDA_Line(pDC,line.pt1,line.pt2,RGB(0,255,0));	
		} 
	}

if(m_DrawType ==7)
	{
		CPoint pt;
		CString str;
		for(int i=0;i<this->m_pt_bl.GetSize();i++)
		{
			pt=this->m_pt_bl.GetAt(i);//�õ���i����
		//��ʾ�㣬��Ϊһ���ظ�����ʾ�ǳ������ԣ��ʰ��������ĵ�Ҳ���Ƴ���
			pDC->SetPixel(pt.x,pt.y,RGB(255,0,0));
			pDC->SetPixel(pt.x,pt.y-1,RGB(255,0,0));
			pDC->SetPixel(pt.x,pt.y+1,RGB(255,0,0));
			pDC->SetPixel(pt.x-1,pt.y,RGB(255,0,0));
			pDC->SetPixel(pt.x+1,pt.y,RGB(255,0,0));
		//���ֱ�ע�������ֵ
			str.Format("(%d,%d)",pt.x,pt.y);
			pDC->TextOut(pt.x+5,pt.y+5,str);
			m_pt_bl.RemoveAll();
		}	
	//this->m_pt_array
	}
if(m_DrawType ==9)
	{
		CPoint pt;
		CString str;
		for(int i=0;i<this->m_pt_rot.GetSize();i++)
		{
			pt=this->m_pt_rot.GetAt(i);//�õ���i����
		//��ʾ�㣬��Ϊһ���ظ�����ʾ�ǳ������ԣ��ʰ��������ĵ�Ҳ���Ƴ���
			pDC->SetPixel(pt.x,pt.y,RGB(255,0,0));
			pDC->SetPixel(pt.x,pt.y-1,RGB(255,0,0));
			pDC->SetPixel(pt.x,pt.y+1,RGB(255,0,0));
			pDC->SetPixel(pt.x-1,pt.y,RGB(255,0,0));
			pDC->SetPixel(pt.x+1,pt.y,RGB(255,0,0));
		//���ֱ�ע�������ֵ
			str.Format("(%d,%d)",pt.x,pt.y);
			pDC->TextOut(pt.x+5,pt.y+5,str);
			m_pt_rot.RemoveAll();	
		}	
	
	}
if(dbx==1)
	{
		CPoint startPoint, endPoint;
		if(this->m_pt_array4.GetSize()>1){
		//�������Ͽ�ʼ����
		startPoint=this->m_pt_array4.GetAt(0);//�õ���1����
		for(int i=1;i<this->m_pt_array4.GetSize();i++){//ѭ������		
			endPoint=this->m_pt_array4.GetAt(i);
			DDA_Line(pDC,startPoint,endPoint,RGB(255,0,0));
			startPoint=endPoint;}
	}
	}
	if(dbx==2)
	{
		CPoint startPoint, endPoint;
		if(this->m_pt_array4.GetSize()>1){
		//�������Ͽ�ʼ����
		startPoint=this->m_pt_array4.GetAt(0);//�õ���1����
		for(int i=1;i<this->m_pt_array4.GetSize();i++){//ѭ������		
			endPoint=this->m_pt_array4.GetAt(i);
			DDA_Line(pDC,startPoint,endPoint,RGB(255,0,0));
			startPoint=endPoint;}
	}
	}
		if(duichenzhou==1)
	{
		CPoint jx1, jx2;
		if(this->m_pt_jx.GetSize()>0&&this->m_pt_jx.GetSize()<3)
		{
		//�������Ͽ�ʼ����
		jx1=this->m_pt_jx.GetAt(0);//�õ���1����
		for(int i=1;i<this->m_pt_jx.GetSize();i++)
			{
			//ѭ������		
				jx2=this->m_pt_jx.GetAt(i);
				DDA_Line(pDC,jx1,jx2,RGB(0,255,0));
				jx1=jx2;
		
			}
	
		}
		else
		{
			m_pt_jx.RemoveAll();
		}
		CPoint startPoint, endPoint;
		if(this->m_pt_array4.GetSize()>1){
		//�������Ͽ�ʼ����
		startPoint=this->m_pt_array4.GetAt(0);//�õ���1����
		for(int i=1;i<this->m_pt_array4.GetSize();i++){//ѭ������		
			endPoint=this->m_pt_array4.GetAt(i);
			DDA_Line(pDC,startPoint,endPoint,RGB(255,0,0));
			startPoint=endPoint;}
	}	

	}
	///////3D
if(m_DrawType ==10)
{

	CPoint startPoint,endPoint;
		
		if(this->m_point_Array1.GetSize()>1)
		{
			
			for(int i = 0;i < this->m_point_Array1.GetSize()-1;i++)
			{
				startPoint = this->m_point_Array1.GetAt(i);
				endPoint = this->m_point_Array1.GetAt(i+1);
				DDA_Line(pDC,startPoint,endPoint,RGB(255,0,0));
			}
			
			for(int j = 0;j < this->m_point_Array1.GetSize()-1;j++)
			{
				startPoint = this->m_point_Array.GetAt(j);
				endPoint = this->m_point_Array.GetAt(j+1);
				DDA_Line(pDC,startPoint,endPoint,RGB(255,0,0));
			}
			for(int k = 0;k<this->m_point_Array.GetSize();k++)
			{
				startPoint = this->m_point_Array1.GetAt(k);
				endPoint = this->m_point_Array.GetAt(k);
				DDA_Line(pDC,startPoint,endPoint,RGB(255,0,0));
			}
		}
}
	// TODO: add draw code for native data here
}


void CCGDrawView::DDA_Line(CDC *&pDC,CPoint &startPoint,CPoint &endPoint,COLORREF crColor){
	if(endPoint.x!=startPoint.x&&endPoint.y!=startPoint.y){//������λ��ֱ�ߣ�һ��ֱ��
		double x,y;
		double k;//б��
		k=((float)(endPoint.y-startPoint.y))/((float)(endPoint.x-startPoint.x));
		x=(double)startPoint.x;
		y=(double)startPoint.y;
	pDC->SetPixel((int)x,(int)y,crColor);
		if(abs(k)<=1.0){
		   for(int i=0;i<abs(endPoint.x-startPoint.x);i++){//X����
		   		if(endPoint.x>startPoint.x){
					x+=1;
					y+=k; }
				else	{
					x-=1;
					y-=k; }
				pDC->SetPixel((int)x,(int)(y+0.5),crColor);	}
		}
		else if(abs(k)>1.0)	{			
			for(int i=0;i<abs(endPoint.y-startPoint.y);i++){//Y����
			  	if(endPoint.y>startPoint.y){
	   				y+=1;
					x+=1.0/k; }
				else	{
	   				y-=1;
					x-=1.0/k;	}
				pDC->SetPixel((int)(x+0.5),(int)(y),crColor); }
		}
	}	
	else if(startPoint.x==endPoint.x){//��ֱ����
		if(startPoint.y<endPoint.y){
			for(int i=startPoint.y;i<=endPoint.y;i++){
				pDC->SetPixel(startPoint.x,i,crColor);	}
		}
		else if(startPoint.y>endPoint.y){
  			for(int i=startPoint.y;i>=endPoint.y;i--)	{
				pDC->SetPixel(startPoint.x,i,crColor);	}
		}
	}
	else if(startPoint.y==endPoint.y){//��ˮƽ��
		if(startPoint.x<endPoint.x){
			for(int i=startPoint.x;i<endPoint.x;i++)	{
				pDC->SetPixel(i,startPoint.y,crColor);	}
		}
		else if(startPoint.x>endPoint.x){
			for(int i=startPoint.x;i>=endPoint.x;i--)	{
				pDC->SetPixel(i,startPoint.y,crColor);	}
		}
	}
}
/////////////////////////////////////////////////////////////////////////////
// CCGDrawView printing

BOOL CCGDrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCGDrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCGDrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCGDrawView diagnostics

#ifdef _DEBUG
void CCGDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CCGDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCGDrawDoc* CCGDrawView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCGDrawDoc)));
	return (CCGDrawDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCGDrawView message handlers

void CCGDrawView::OnDrawpoint() 
{
	m_DrawType = 1;
	m_isDraw = true;//��ʼ״̬Ϊ��ͼ״̬
	if(this->m_MDlg->GetSafeHwnd()==NULL){
		this->m_MDlg->Create();}
	else
		this->m_MDlg->ShowWindow(TRUE);


// TODO: Add your command handler code here
	
}

void CCGDrawView::OnDrawline() 
{
	m_DrawType = 2;
	m_isDraw = true;//��ʼ״̬Ϊ��ͼ״̬// TODO: Add your command handler code here
	
}

void CCGDrawView::OnDrawpol() 
{
	m_DrawType = 3;
	m_isDraw = true;//��ʼ״̬Ϊ��ͼ״̬// TODO: Add your command handler code here
	
}

void CCGDrawView::OnFill() 
{
	m_DrawType = 4;
	m_isDraw = true;//��ʼ״̬Ϊ��ͼ״̬// TODO: Add your command handler code here
	if (fillFlag==0)
	{
		fillFlag=1;
	}
	else
	{
		fillFlag=0;
	}
	Invalidate();
}




void CCGDrawView::OnLButtonDown(UINT nFlags, CPoint point) 
{
///////����
	if(m_DrawType == 1)
	{
		this->m_pt_array3.Add(point);//��������ļ��ϣ�thisָ��ͼ�����౾��
		if(this->m_MDlg->GetSafeHwnd()!=NULL)
		{
			this->m_MDlg->m_X=point.x;
			this->m_MDlg->m_Y=point.y;
			this->m_MDlg->UpdateData(FALSE);	
		}
		Invalidate();//����OnDraw()����
	}
///////��ֱ��
	if(m_DrawType == 2)
	{
		if(step1==0)
		{
			this->p1=point;
			step1=1;
		}
		else if (step1==1)
		{
			CLine line1;
			line1.pt1=p1;
			line1.pt2=point;
			this->m_line_array.Add(line1);		
			step1=0;
			Invalidate();
		}
	}
//////////�㼯�������
	if(m_DrawType == 3)
	{
	/*
	if(step==0)
		{
			this->p1=point;
			step=1;
		}
		else
		{
			this->p2=point;
			CLine line;
			line.pt1=p1;
			line.pt2=p2;
			this->m_line_array4.Add(line);
			this->p1=point;
			Invalidate();
			
		//	step=0;
		}
		*/
	this->m_pt_array4.Add(point);//��������ļ��ϣ�thisָ��ͼ�����౾��
		Invalidate();//����OnDraw()����
	}
//�߼��������
if(m_DrawType == 11)
	{
	
	if(step==0)
		{
			this->p1=point;
			step=1;
		}
		else
		{
			this->p2=point;
			CLine line;
			line.pt1=p1;
			line.pt2=p2;
			this->m_line_array.Add(line);
			this->p1=point;
			Invalidate();
			
	
		}
		
	
	}	
///////������
	if(m_DrawType == 5)
	{
		this->m_OrigPoint=point;

	}
	if(m_DrawType == 7)
	{
		this->m_pt_bl.Add(point);//��������ļ��ϣ�thisָ��ͼ�����౾��
		if(this->m_MDlg1->GetSafeHwnd()!=NULL)
		{
			this->m_MDlg1->m_X1=point.x;
			this->m_MDlg1->m_Y1=point.y;
			this->m_MDlg1->UpdateData(FALSE);	
		}
	//	Invalidate();//����OnDraw()����
	}
	if(m_DrawType == 9)
	{
		this->m_pt_array.Add(point);//��������ļ��ϣ�thisָ��ͼ�����౾��
		if(this->m_MDlg2->GetSafeHwnd()!=NULL)
		{
			this->m_MDlg2->m_X2=point.x;
			this->m_MDlg2->m_Y2=point.y;
			this->m_MDlg2->UpdateData(FALSE);	
		}
		//Invalidate();//����OnDraw()����
	}
	if(duichenzhou==1)
		{
			this->m_pt_jx.Add(point);//��������ļ��ϣ�thisָ��ͼ�����౾��
			Invalidate();
		}
	CView::OnLButtonDown(nFlags, point);
}

void CCGDrawView::OnRButtonDown(UINT nFlags, CPoint point) 
{
//////ֱ��
	//if(m_DrawType != 2)
//	{
	//	m_line_array1.RemoveAll();
	//}
//////�������
	if(m_DrawType == 3)	
	{
		
		m_pt_array4.Add(m_pt_array4.GetAt(0));
		Invalidate();
	}
		if(m_DrawType == 11)	
	{
		
		if (step!=-1)
		{
			if(this->m_line_array.GetSize()>=2)
			{
				CLine line;
				line.pt1=m_line_array.GetAt(0).pt1;
				line.pt2=m_line_array.GetAt(m_line_array.GetSize()-1).pt2;
				m_line_array.Add(line);
				Invalidate();
				step=-1;
			}
		}
		else
		{
			step=0;
			m_line_array.RemoveAll();
			Invalidate();	
		}// TODO: Add your message handler code here and/or call default
		
		
	}


	CView::OnRButtonDown(nFlags, point);
}
/////ȫ�����
void CCGDrawView::OnClear() 
{
m_DrawType = 5;
	m_isDraw = true;
	
 // TODO: Add your command handler code here
m_pt_array.RemoveAll();
m_line_array.RemoveAll();
m_line_array.RemoveAll();
m_line_array1.RemoveAll();
m_line_array4.RemoveAll();
m_pt_array.RemoveAll();
m_pt_rot.RemoveAll();
m_pt_bl.RemoveAll();
m_pt_jx.RemoveAll();
m_pt_array1.RemoveAll();
m_pt_array2.RemoveAll();
m_pt_array3.RemoveAll();
m_pt_array4.RemoveAll();
Invalidate(TRUE);	
}

void CCGDrawView::OnUpdateFill(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable((this->m_line_array.GetSize()>3&&step==-1)?true:false);
	
}
/////��ɨ���ߺ��߶ν���
int GetInterPointX(int yx,int x0,int y0,int x1,int y1)
{ 
	int m_x;//����Xֵ
	if(yx==y0)
	{	
		m_x=x0;
	}
	else if(yx==y1)
	{
		m_x=x1;
	}
	else
	{
		int a=y0-y1;
		int b=x1-x0;
		int c=x0*y1-x1*y0;
		double m_dblX;
		m_dblX=(-1)*(double(b*yx+c))/(double)a;
		m_x=(int)(m_dblX+0.5);
	}
	return  m_x;
}
////////����
void InsertPoint_x(CArray<int,int>& m_x_Array,int m_x)
{
	int i_flag=0;
	for(int i=0;i<m_x_Array.GetSize();i++)
	{
		i_flag=0;
		if(m_x<m_x_Array.GetAt(i))	
		{
			m_x_Array.InsertAt(i,m_x);
			i_flag=1;
			break;
		}
	}
	if(i_flag==0)
	{
		m_x_Array.Add(m_x);
	}
}

void CCGDrawView::scanTransfer(CDC* pDC)
{
	int ymin,ymax;
	CLine line;
	line=this->m_line_array.GetAt(0);
//////�õ���С�����ɨ����
	if(line.pt1.y<=line.pt2.y)	
	{
		ymin=line.pt1.y;
		ymax=line.pt2.y;	
	}
	else
	{
		ymin=line.pt2.y;
		ymax=line.pt1.y;
	}
	for(int i=1;i<this->m_line_array.GetSize();i++)	
	{
		line=this->m_line_array.GetAt(i);
		if(line.pt2.y<ymin)
		{
			ymin=line.pt2.y;
		}
		else if(line.pt2.y>ymax)
		{	
			ymax=line.pt2.y;
		}
	}
//////��ymin��ymaxɨ��ת��
	CArray<int,int> m_x_Array;
	int m_x;//����
	int j,k;
	for(int yi=ymin;yi<=ymax;yi++)	
	{
		m_x_Array.RemoveAll();
		for(i=0;i<=m_line_array.GetSize()-1;i++)
		{
			line=m_line_array.GetAt(i);
			if(yi>=line.pt1.y&&yi<line.pt2.y)
			{
				m_x=GetInterPointX(yi,line.pt1.x,line.pt1.y,line.pt2.x,line.pt2.y);
				InsertPoint_x(m_x_Array,m_x);
			}			
			else if(yi>=line.pt2.y&&yi<line.pt1.y)
			{
				m_x=GetInterPointX(yi,line.pt1.x,line.pt1.y,line.pt2.x,line.pt2.y);
				InsertPoint_x(m_x_Array,m_x);
			}
			else if(yi==line.pt1.y&&yi==line.pt2.y)
			{
				InsertPoint_x(m_x_Array,line.pt1.x);
				InsertPoint_x(m_x_Array,line.pt2.x);
			}
		}	
////////��������ɫ
		for(j=0;j<=m_x_Array.GetSize()-2;j++,j++)
		{
			for(k=m_x_Array.GetAt(j);k<=m_x_Array.GetAt(j+1);k++)
			{
				pDC->SetPixel(k,yi,RGB(0,255,0));
			}
		}
	
	}
}

void CCGDrawView::OnCut() 
{    

	m_DrawType = 6;
    PolylineCut(m_line_array,m_cutRect) ;
	Invalidate();

	// TODO: Add your command handler code here
	
}

void CCGDrawView::OnDrawrec() 
{
	m_DrawType = 5;
	m_isDraw = true;// TODO: Add your command handler code here
	
}

void CCGDrawView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	if(m_DrawType == 5)
	{	
	CClientDC dc(this);CBrush *pBrush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	CBrush *pOldBrush=dc.SelectObject(pBrush);
	dc.Rectangle(CRect(m_OrigPoint,point));//���ƾ���
	dc.SelectObject(pOldBrush);

	m_cutRect.xL=m_OrigPoint.x;
	m_cutRect.xR=point.x;
	m_cutRect.yT=m_OrigPoint.y;
	m_cutRect.yB=point.y;
	}// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonUp(nFlags, point);
}


void CCGDrawView::OnRectCutlines(CArray<CLine,CLine> &m_line_array, CCutRect &m_cutRect)
 {
	CLine line;
	CArray<CLine,CLine> m_line_array_tmp;
//��Ųü������ʱ�߶���
		int code1[4],code2[4];
		while(m_line_array.GetSize()>0)
		{
//m_line_array �߶�����
		line=m_line_array.GetAt(0);
//���߶�����ȡ��һ���߶�
		m_line_array.RemoveAt(0);
//1�߶ζ˵����
		Encode(line,m_cutRect,code1,code2);
//m_cutRect,Ϊ�ü�����
//2,�ж��߶��Ƿ�򵥽��պͷ���	
		if(code1[0]==0&&code1[1]==0&&code1[2]==0&&code1[3]==0&&code2[0]==0&&code2[1]==0&&code2[2]==0&&code2[3]==0)
		{
			m_line_array_tmp.Add(line);
//�򵥽���
			continue;}
		else if((code1[0]&code2[0])||(code1[1]&code2[1])||(code1[2]&code2[2])||(code1[3]&code2[3])){
			continue;
//��ͬһ��,�����
		}
//�Ǽ򵥽��պͼ򵥷��������󽻵㲢��òü������ڵ��߶�
		InterPt(m_line_array_tmp,line,m_cutRect,code1,code2);
		}
	m_line_array.Append(m_line_array_tmp);
//�ü�����߶��鸳��ԭ�߶���
	m_line_array_tmp.RemoveAll();
	Invalidate();//��ʾ
}

/* line ���߶�m_cutRect���ü����δ��� code1���˵�1�ı���, code2���˵�2����*/
void CCGDrawView::Encode(CLine &line,CCutRect m_cutRect,int* code1,int* code2){
	if(line.pt1.y<m_cutRect.yT) code1[0]=1;else code1[0]=0;
	if(line.pt1.y>m_cutRect.yB) code1[1]=1;else code1[1]=0;
	if(line.pt1.x>m_cutRect.xR) code1[2]=1;else code1[2]=0;
	if(line.pt1.x<m_cutRect.xL) code1[3]=1;else code1[3]=0;

	if(line.pt2.y<m_cutRect.yT) code2[0]=1;else code2[0]=0;
	if(line.pt2.y>m_cutRect.yB) code2[1]=1;else code2[1]=0;
	if(line.pt2.x>m_cutRect.xR) code2[2]=1;else code2[2]=0;
	if(line.pt2.x<m_cutRect.xL) code2[3]=1;else code2[3]=0;
}

//���ڷǼ򵥽��պͼ򵥷�����������󽻵㲢��òü��������߶εĺ���
/* m_line_array���߶���line ���߶�m_cutRect���ü����δ��� code1���˵�1�ı���, code2���˵�2���� */
void CCGDrawView::InterPt(CArray<CLine,CLine> &m_line_array,CLine &line,CCutRect m_cutRect,int* code1,int* code2)
{
	CPoint pt;
		if(code1[0]||code2[0])	{//�ϱ߽�
		if(code1[0]&&code2[0]) return;//�ڲü�������,��ɾ��
		//��yt�󽻵�
		pt.y=m_cutRect.yT;		pt.x=line.pt1.x+(double)(line.pt2.x-line.pt1.x)/(double)(line.pt2.y-line.pt1.y)*(pt.y -line.pt1.y);
		if(code1[0]==1){
			line.pt1=pt;
			code1[0]=0;
			if(pt.x<m_cutRect.xL) code1[3]=1;
			else if(pt.x>m_cutRect.xR) code1[2]=1;	
		}
		else
		{
			line.pt2=pt;
			code2[0]=0;
			if(pt.x<m_cutRect.xL) code2[3]=1;
			else if(pt.x>m_cutRect.xR) code2[2]=1;	
		}
	}
		if(code1[1]||code2[1])
		{//�±߽�
		if(code1[1]&&code2[1]) return;//�ڲü�������,��ɾ��
		//��yt�󽻵�
		pt.y=m_cutRect.yB;	
		pt.x=line.pt1.x+(double)(line.pt2.x-line.pt1.x)/(double)(line.pt2.y-line.pt1.y)*(pt.y -line.pt1.y);
		if(code1[1]==1)
		{
			line.pt1=pt;
			code1[1]=0;
			if(pt.x<m_cutRect.xL) code1[3]=1;
			else if(pt.x>m_cutRect.xR) code1[2]=1;
		}
		else
		{
			line.pt2=pt;
			code2[1]=0;
			if(pt.x<m_cutRect.xL) code2[3]=1;
			else if(pt.x>m_cutRect.xR) code2[2]=1;	
		}
	}
		if(code1[2]||code2[2])	{//�ұ߽�
		if(code1[2]&&code2[2]) return;//�ڲü�������,��ɾ��	
		pt.x=m_cutRect.xR;//��xL�󽻵�
		pt.y=(int)line.pt1.y+(m_cutRect.xR-line.pt1.x)*(double)(line.pt2.y-line.pt1.y)/(double)(line.pt2.x-line.pt1.x);		
		if(code1[2]==1)
		{
			line.pt1=pt;
			code1[2]=0;
			if(pt.y<m_cutRect.yT) code1[0]=1;
			else if(pt.y>m_cutRect.yB) code1[1]=1;
		}
		else
		{
			line.pt2=pt;
			code2[2]=0;
			if(pt.y<m_cutRect.yT)code2[0]=1;
			else if(pt.y>m_cutRect.yB)code2[1]=1;	
		}
	}
		if(code1[3]||code2[3])	{//��߽�
		if(code1[3]&&code2[3]) return;//�ڲü�������,��ɾ��
		//��xL�󽻵�
		pt.x=m_cutRect.xL;	
		pt.y=(int)line.pt1.y+(m_cutRect.xL-line.pt1.x)*(line.pt2.y-line.pt1.y)/(double)(line.pt2.x-line.pt1.x);		
		if(code1[3]==1)
		{
			line.pt1=pt;
			code1[3]=0;
			if(pt.y<m_cutRect.yT) code1[0]=1;
			else if(pt.y>m_cutRect.yB) code1[1]=1;
		}
		else
		{
			line.pt2=pt;
			code2[3]=0;
			if(pt.y<m_cutRect.yT)code2[0]=1;
			else if(pt.y>m_cutRect.yB)code2[1]=1;	
		}
	}
	//���ж�ͨ���󽻺���߶ε�λ��
	if(code1[0]==0&&code1[1]==0&&code1[2]==0&&code1[3]==0&&code2[0]==0&&code2[1]==0&&code2[2]==0&&code2[3]==0)
	{
		m_line_array.Add(line);//�򵥽���		
	}
	else if((code1[0]&code2[0])||(code1[1]&code2[1])||(code1[2]&code2[2])||(code1[3]&code2[3]))
	{
		return;//��ͬһ��,�����
	}
	else	
	{	
		InterPt(m_line_array,line,m_cutRect,code1,code2);//�ٵݹ���ñ�����
	} 
}
void CCGDrawView::PolylineCut(CArray<CLine,CLine> &m_line_array,CCutRect m_cutRect){
	CArray<CPoint,CPoint> m_point_Array,m_point_Array1,m_point_Array2,m_point_Array3,m_point_Array4;//�����м�����
	//�ѱ߱�ɶ�������
	CLine line;
	for(int j=0;j<m_line_array.GetSize();j++)	{
		line=m_line_array.GetAt(j);
		m_point_Array.Add(line.pt1);
	m_point_Array.Add(line.pt2);}
	m_point_Array.Add(m_point_Array.GetAt(0));//���Ȱ��׵�ӵ����һ�㣬ʹ��β��ӣ����ɾ��	
	int x_ledge,y_ledge;
	x_ledge=m_cutRect.xL;	
	int a, b,c;
	double m_dblX,m_dblY;
	int x0,x1,y0,y1;
	CPoint newPoint;
	//1xmin�ü�
	for(int i=0;i<m_point_Array.GetSize()-1;i++)	{		if(m_point_Array.GetAt(i).x<x_ledge&&m_point_Array.GetAt(i+1).x<x_ledge)
			continue;	//�����������ñ�
		else if(m_point_Array.GetAt(i).x>=x_ledge&&m_point_Array.GetAt(i+1).x>=x_ledge){
			//����
			m_point_Array1.Add(m_point_Array.GetAt(i));}
		else	{
			x0=m_point_Array.GetAt(i).x;//һ��һ��,����㽻�㲢����
			x1=m_point_Array.GetAt(i+1).x;
			y0=m_point_Array.GetAt(i).y;
			y1=m_point_Array.GetAt(i+1).y;
			a=y0-y1;
			b=x1-x0;
			c=x0*y1-x1*y0;			
			m_dblY=(-1)*(double(a*x_ledge+c))/(double)b;
			y_ledge=(int)(m_dblY+0.5);
			newPoint.x=x_ledge;
			newPoint.y=y_ledge;
			//�������˳��
			if(m_point_Array.GetAt(i).x<x_ledge)
				m_point_Array1.Add(newPoint);//���뽻��				
			else	{
				//�Ȳ���˵��ٲ��뽻��
				m_point_Array1.Add(m_point_Array.GetAt(i));
				m_point_Array1.Add(newPoint);}	
			}
	}
	//2ymin�ü�
	y_ledge=m_cutRect.yT;
	m_point_Array1.Add(m_point_Array1.GetAt(0));
	for(i=0;i<m_point_Array1.GetSize()-1;i++){		if(m_point_Array1.GetAt(i).y<y_ledge&&m_point_Array1.GetAt(i+1).y<y_ledge)
			continue;	//�����������ñ�
		else if(m_point_Array1.GetAt(i).y>=y_ledge&&m_point_Array1.GetAt(i+1).y>=y_ledge)
			m_point_Array2.Add(m_point_Array1.GetAt(i));//����
		else	{
			//һ��һ��,����㽻�㲢����
			x0=m_point_Array1.GetAt(i).x;
			x1=m_point_Array1.GetAt(i+1).x;
			y0=m_point_Array1.GetAt(i).y;
			y1=m_point_Array1.GetAt(i+1).y;
			a=y0-y1;
			b=x1-x0;
			c=x0*y1-x1*y0;			
			m_dblX=(-1)*(double(b*y_ledge+c))/(double)a;
			x_ledge=(int)(m_dblX+0.5);
			newPoint.x=x_ledge;
			newPoint.y=y_ledge;
			//�������˳��
			if(m_point_Array1.GetAt(i).y<y_ledge)//�Ȳ��뽻��				
				m_point_Array2.Add(newPoint);
			else	{
				//�Ȳ���˵㣬�ٲ��뽻��
				m_point_Array2.Add(m_point_Array1.GetAt(i));
				m_point_Array2.Add(newPoint); }	
}
	}
	//3xmax�ü�
	x_ledge=m_cutRect.xR;
	m_point_Array2.Add(m_point_Array2.GetAt(0));
	for(i=0;i<m_point_Array2.GetSize()-1;i++){		if(m_point_Array2.GetAt(i).x>x_ledge&&m_point_Array2.GetAt(i+1).x>x_ledge)
			continue;	//�����������ñ�
		else if(m_point_Array2.GetAt(i).x<=x_ledge&&m_point_Array2.GetAt(i+1).x<=x_ledge)
			m_point_Array3.Add(m_point_Array2.GetAt(i));//����
		else	{//һ��һ��,����㽻�㲢����
			x0=m_point_Array2.GetAt(i).x;
			x1=m_point_Array2.GetAt(i+1).x;
			y0=m_point_Array2.GetAt(i).y;
			y1=m_point_Array2.GetAt(i+1).y;
			a=y0-y1;
			b=x1-x0;
			c=x0*y1-x1*y0;			
			m_dblY=(-1)*(double(a*x_ledge+c))/(double)b;
			y_ledge=(int)(m_dblY+0.5);
			newPoint.x=x_ledge;
			newPoint.y=y_ledge;
			//����˳��
			if(m_point_Array2.GetAt(i).x>x_ledge)				
				m_point_Array3.Add(newPoint);//���뽻��
			else	{//�Ȳ���˵�				
				m_point_Array3.Add(m_point_Array2.GetAt(i));
				m_point_Array3.Add(newPoint);}	
}
	}
	//4ymax�ü�
	y_ledge=m_cutRect.yB;
	m_point_Array3.Add(m_point_Array3.GetAt(0));
	for(i=0;i<m_point_Array3.GetSize()-1;i++){		if(m_point_Array3.GetAt(i).y>y_ledge&&m_point_Array3.GetAt(i+1).y>y_ledge)
			continue;	//�����������ñ�
		else if(m_point_Array3.GetAt(i).y<=y_ledge&&m_point_Array3.GetAt(i+1).y<=y_ledge)
			m_point_Array4.Add(m_point_Array3.GetAt(i));//����
		else	{//һ��һ��,����㽻�㲢����
			x0=m_point_Array3.GetAt(i).x;
			x1=m_point_Array3.GetAt(i+1).x;
			y0=m_point_Array3.GetAt(i).y;
			y1=m_point_Array3.GetAt(i+1).y;
			a=y0-y1;
			b=x1-x0;
			c=x0*y1-x1*y0;			
			m_dblX=(-1)*(double(b*y_ledge+c))/(double)a;
			x_ledge=(int)(m_dblX+0.5);
			newPoint.x=x_ledge;
			newPoint.y=y_ledge;
			//����˳��
			if(m_point_Array3.GetAt(i).y>y_ledge)
				m_point_Array4.Add(newPoint);//���뽻��
			else	{//�Ȳ���˵�		
				m_point_Array4.Add(m_point_Array3.GetAt(i));
				m_point_Array4.Add(newPoint);}	
}
	}
	//���¼������α���
	m_line_array.RemoveAll();
	for(j=0;j<m_point_Array4.GetSize()-1;j++){
		line.pt1=m_point_Array4.GetAt(j);
		line.pt2=m_point_Array4.GetAt(j+1);
		m_line_array.Add(line);	}
	//��β���
	line.pt1=m_point_Array4.GetAt(m_point_Array4.GetSize()-1);
	line.pt2=m_point_Array4.GetAt(0);
		m_line_array.Add(line);
}
//////

//////////////////////////////////////////////////////////////////////////////////////

//������άͼ�ε���λ����任����

void CCGDrawView::Get2DMatrix(double matrix[][3],int iFlag,double rotateAngle,double x_dis,double y_dis,double dbl_zoom){
  for(int i=0;i<3;i++)	{//	���ȴ�����λ��
		for(int j=0;j<3;j++)
			matrix[i][j]=0;	}
	matrix[0][0]=1;
	matrix[1][1]=1;
	matrix[2][2]=1;
	if(iFlag==0){//ƽ�Ʊ任����		
		matrix[2][0]=x_dis;
		matrix[2][1]=y_dis;}
	else if(iFlag==1){//��ת�任����	
		matrix[0][0]=cos(PI/180*rotateAngle);
		matrix[0][1]=sin(PI/180*rotateAngle);
		matrix[1][0]=(-1)*sin(PI/180*rotateAngle);
		matrix[1][1]=cos(PI/180*rotateAngle);	}
	else if(iFlag==2){//X�᾵��	
		matrix[1][1]=-1;	}
	else if(iFlag==3){//Y�᾵��任����
		matrix[0][0]=-1;	}
	else if(iFlag==4){//x_���Ʊ任����
		matrix[1][0]=x_dis;}
	else if(iFlag==5){//y_���Ʊ任����	
		matrix[0][1]=y_dis;}
	else if(iFlag==6){//ȫ�����任����	
		matrix[2][2]=dbl_zoom;}

}

//������άͼ�ε���λ����任����
void CCGDrawView::GetMatrix(double matrix[][4],int iFlag,double x_dis,double y_dis,double z_dis,double rotateAngle,double dbl_zoom){
	for(int i=0;i<4;i++)	{
		for(int j=0;j<4;j++)
			(matrix[i][j])=0;}
	matrix[0][0]=1;matrix[1][1]=1;matrix[2][2]=1;matrix[3][3]=1;
	if(iFlag==0){//�ƶ�	
		matrix[3][0]=x_dis;matrix[3][1]=y_dis;matrix[3][2]=z_dis;}
	else if(iFlag==1){//X��ת	
		matrix[1][1]=cos(PI/180*rotateAngle);
		matrix[1][2]=sin(PI/180*rotateAngle);
		matrix[2][1]=(-1)*sin(PI/180*rotateAngle);
		matrix[2][2]=cos(PI/180*rotateAngle);}
	else if(iFlag==2){//y��ת	
		matrix[0][0]=cos(PI/180*rotateAngle);
		matrix[0][2]=(-1)*sin(PI/180*rotateAngle);
		matrix[2][0]=sin(PI/180*rotateAngle);
		matrix[2][2]=cos(PI/180*rotateAngle);}
	else if(iFlag==3){//z��ת	
		matrix[0][0]=cos(PI/180*rotateAngle);
		matrix[1][0]=(-1)*sin(PI/180*rotateAngle);
		matrix[0][1]=sin(PI/180*rotateAngle);
		matrix[1][1]=cos(PI/180*rotateAngle);}
	else if(iFlag==4){//XOY����	
		matrix[2][2]=-1;}
	else if(iFlag==5){//YOZ����	
		matrix[0][0]=-1;}
	else if(iFlag==6){//ZOX����
		matrix[1][1]=-1;}
	else if(iFlag==7){//X����
		matrix[1][0]=y_dis;
		matrix[2][0]=z_dis;}
	else if(iFlag==8){//y����
		matrix[0][1]=x_dis;
		matrix[2][1]=z_dis;}
	else if(iFlag==9){//z����
		matrix[0][2]=x_dis;
		matrix[1][2]=z_dis;}	
	else if(iFlag==10){//����
		matrix[3][3]=dbl_zoom;}
}

//��άͼ�ε㼸�α任
void CCGDrawView::GetNewPoint(CArray<CPoint,CPoint> &m_pt_Array4,double m_Matrix[][3])
{
	CArray<CPoint,CPoint> m_point_Array_new;
	CPoint point_new;
	double s_dbl;
	for(int i=0;i<m_pt_Array4.GetSize();i++){			
		point_new.x=m_pt_Array4.GetAt(i).x*m_Matrix[0][0]+m_pt_Array4.GetAt(i).y*m_Matrix[1][0]+m_Matrix[2][0];		
		point_new.y=m_pt_Array4.GetAt(i).x*m_Matrix[0][1]+m_pt_Array4.GetAt(i).y*m_Matrix[1][1]+m_Matrix[2][1];
			s_dbl=m_Matrix[0][2]+m_Matrix[1][2]+m_Matrix[2][2];
			point_new.x/=s_dbl;
			point_new.y/=s_dbl;
			m_point_Array_new.Add(point_new);	}
	m_pt_Array4.RemoveAll();
	m_pt_Array4.Append(m_point_Array_new);
}


//��άͼ�εļ��α任
void CCGDrawView::GetNewPointfor3D(double m_Matrix[][4])
{
		CArray <CPoint,CPoint> m_point_Array_new;
	CPoint point_new,point_new1;
	m_point_Array.RemoveAll();
	m_point_Array1.RemoveAll();
	m_iPointNum = m_pt_array4.GetSize();
	//m_extend_array.Append(m_point1_array);

	
	double (*Point0)[4] = new double[m_iPointNum][4];
	double (*Point1)[4] = new double[m_iPointNum][4];
	double (*Point2)[4] = new double[m_iPointNum][4];
	double (*Point3)[4] = new double[m_iPointNum][4];

	for(int i = 0;i < m_iPointNum; i++)
	{
		Point0[i][0] = m_pt_array4.GetAt(i).x;
		Point0[i][1] = m_pt_array4.GetAt(i).y;
		Point0[i][2] = 0;
		Point0[i][3] = 1;

		Point1[i][0] = m_pt_array4.GetAt(i).x;
		Point1[i][1] = m_pt_array4.GetAt(i).y;
		Point1[i][2] = this->m_zlength;
		Point1[i][3] = 1;
	}
	

	for(i = 0;i < m_iPointNum; i++)
	{
		for(int j = 0;j < 4;j++)
		{
			Point2[i][j] = 0;
			Point3[i][j] = 0;
			for(int k = 0;k < 4; k++)
			{
				Point2[i][j] += Point0[i][k] * m_Matrix[k][j];
				Point3[i][j] += Point1[i][k] * m_Matrix[k][j];
				
			}
		}
		point_new.x = Point2[i][0]/Point2[i][3];
		point_new.y = Point2[i][1]/Point2[i][3];
		
		m_point_Array.Add(point_new);
		
		point_new1.x = Point3[i][0]/Point3[i][3];
		point_new1.y = Point3[i][1]/Point3[i][3];
		m_point_Array1.Add(point_new1);

		

	}
}
//
///////////////////////////
//����2D������˵ĺ���
void CCGDrawView::MatrixXMatrixFor2D(double matrix0[][3],double matrix1[][3]){
	double matrix2[3][3];
	for(int i=0;i<3;i++)	{
		for(int j=0;j<3;j++)	{					matrix2[i][j]=matrix0[i][0]*matrix1[0][j]+matrix0[i][1]*matrix1[1][j]+matrix0[i][2]*matrix1[2][j];		}	
}
	for(i=0;i<3;i++)	{
		for(int j=0;j<3;j++)	{
			matrix0[i][j]=matrix2[i][j]; }		
	}
}

//3D������˺���
void CCGDrawView::MatrixXMatrix(double matrix0[][4],double matrix1[][4]){
	double matrix2[4][4];
	for(int i=0;i<4;i++)	{
		for(int j=0;j<4;j++)	{
			matrix2[i][j]=0.;
			for(int k=0;k<4;k++){//�ϵ�				
				matrix2[i][j]+=matrix0[i][k]*matrix1[k][j];}	}
	}
	for(i=0;i<4;i++){
		for(int j=0;j<4;j++)	{
			matrix0[i][j]=matrix2[i][j];}  }
}

//��������������ת�任����ĺ���
void CCGDrawView::RotateTransform2D(double m_Matrix[][3],double& m_x,double& m_y,double& m_Angle){
	double m_Matrix0[3][3];
	Get2DMatrix(m_Matrix,0,0,(-1)*m_x,(-1)*m_y,0);	//��ƽ�Ƶ�����ԭ��	
	Get2DMatrix(m_Matrix0,1,(-1)*m_Angle,0,0,0);//��ת-m_angel		
	MatrixXMatrixFor2D(m_Matrix,m_Matrix0);//�������
	Get2DMatrix(m_Matrix0,0,0,m_x,m_y,0);//������ԭ��ƽ����
	MatrixXMatrixFor2D(m_Matrix,m_Matrix0);//�������
	return;
}

//����ֱ�ߵľ���任������
void CCGDrawView::MirrorTransform2D(double m_Matrix[][3],double m_x0,double m_y0,double m_x1,double m_y1){
	double m_Matrix0[3][3];
	//������������������ˮƽ�߻��ߴ�ֱ��
	if(m_y1==m_y0){//ˮƽ��
		Get2DMatrix(m_Matrix,0,0,0,(-1)*m_y0,0);//1��ƽ�Ƶ���X���غ�		
		Get2DMatrix(m_Matrix0,2,0,0,0,0);//2����
		MatrixXMatrixFor2D(m_Matrix,m_Matrix0);//�������		
		Get2DMatrix(m_Matrix0,0,0,0,m_y0,0);//�ٷ���ƽ��
		MatrixXMatrixFor2D(m_Matrix,m_Matrix0);//�������
	}
	else if(m_x1==m_x0){//��ֱ��
		Get2DMatrix(m_Matrix,0,0,(-1)*m_x0,0,0);//1��ƽ�Ƶ���Y���غ�					
		Get2DMatrix(m_Matrix0,3,0,0,0,0);//2����
		MatrixXMatrixFor2D(m_Matrix,m_Matrix0);//�������
		Get2DMatrix(m_Matrix0,0,0,(-1)*m_x0,0,0);//�ٷ���ƽ��
		MatrixXMatrixFor2D(m_Matrix,m_Matrix0);//�������
	}
	else{//һ��λ��ֱ��	
		//�󽻵�
		int a, b,c;
		double angle,y_ledge;
		a=m_y0-m_y1;
		b=m_x1-m_x0;
		c=m_x0*m_y1-m_x1*m_y0;
		y_ledge=(-1)*c/(double)b;
		angle=atan((-1)*(double(a))/(double)b);// ������
		angle=angle*180/PI;		
		Get2DMatrix(m_Matrix,0,0,0,(-1)*y_ledge,0);//��ƽ�Ƶ�����ԭ��		
		Get2DMatrix(m_Matrix0,1,(-1)*angle,0,0,0);//��ת-angel
		MatrixXMatrixFor2D(m_Matrix,m_Matrix0);
		Get2DMatrix(m_Matrix0,2,0,0,0,0);//����-x
		MatrixXMatrixFor2D(m_Matrix,m_Matrix0);
		Get2DMatrix(m_Matrix0,1,angle,0,0,0);//��ת-angel
		MatrixXMatrixFor2D(m_Matrix,m_Matrix0);
		Get2DMatrix(m_Matrix0,0,0,0,y_ledge,0);//����ƽ��
		MatrixXMatrixFor2D(m_Matrix,m_Matrix0);	}
	return;
}

//������ȫ�����任����
void CCGDrawView::ScaleTransform2D(double m_Matrix[][3],double m_x,double m_y,double m_scale){
	double m_Matrix0[3][3];	
	Get2DMatrix(m_Matrix,0,0,(-1)*m_x,(-1)*m_y,0);//1�����ƶ�������ԭ��	
	Get2DMatrix(m_Matrix0,6,0,0,0,m_scale);//2�����任	
	MatrixXMatrixFor2D(m_Matrix,m_Matrix0);	
	Get2DMatrix(m_Matrix0,0,0,m_x,m_y,0);//3����ƽ��
	MatrixXMatrixFor2D(m_Matrix,m_Matrix0);  }


void CCGDrawView::OnZoom() //����
{
	m_DrawType = 7;
	m_isDraw = true;// TODO: Add your command handler code here
m_pt_jx.RemoveAll();
	m_pt_rot.RemoveAll();
	if(this->m_MDlg1->GetSafeHwnd()==NULL){
		this->m_MDlg1->Create();}
	else
		this->m_MDlg1->ShowWindow(TRUE);

}

void CCGDrawView::OnMirror() //����
{
	m_DrawType = 8;
	m_isDraw = true;// TODO: Add your command handler code here
	m_pt_rot.RemoveAll();
	m_pt_bl.RemoveAll();
if(this->m_MDlg3->GetSafeHwnd()==NULL){
		this->m_MDlg3->Create();}
	else
		this->m_MDlg3->ShowWindow(TRUE);
//	MirrorTransform2D(double m_Matrix[][3],double m_x0,double m_y0,double m_x1,double m_y1);
}

void CCGDrawView::OnRotate() //��ת
{
	m_DrawType = 9;
	m_isDraw = true;// TODO: Add your command handler code here
	
	if(this->m_MDlg2->GetSafeHwnd()==NULL){
		this->m_MDlg2->Create();
this->m_MDlg2->m_ROT=0;
this->m_MDlg2->UpdateData(FALSE);
	}
	else
		this->m_MDlg2->ShowWindow(TRUE);
this->m_MDlg2->m_ROT=0;
}

void CCGDrawView::On3d() 
{
	// TODO: Add your command handler code here
		
	// TODO: Add your command handler code here
	
	if(this->m_MDlg4->GetSafeHwnd()==NULL){
		this->m_MDlg4->Create();

	}
	else
		this->m_MDlg4->ShowWindow(TRUE);

}
void CCGDrawView::OnDrawpol1() 
{
	m_DrawType = 11;
	m_isDraw = true;// TODO: Add your command handler code here
	
}
void CCGDrawView::Extern()
{
	double m_Matrix[4][4];
	double m_Matrix0[4][4];


	GetMatrix(m_Matrix,0,m_pt_array4.GetAt(0).x*(-1),m_pt_array4.GetAt(0).y*(-1),0,0,1);

	GetMatrix(m_Matrix0,7,0,0,0.5,0,1);
	//MatrixXMatrix(m_Matrix,m_Matrix0);
	GetMatrix(m_Matrix0,8,0,0,0.5,0,1);
	MatrixXMatrix(m_Matrix,m_Matrix0);

	GetMatrix(m_Matrix0,0,m_pt_array4.GetAt(0).x,m_pt_array4.GetAt(0).y,0,0,1);
	MatrixXMatrix(m_Matrix,m_Matrix0);
	
	GetNewPointfor3D(m_Matrix);
	Invalidate(TRUE);
}
//

void CCGDrawView::Rotate()
{
	double m_Matrix[4][4];
	double m_Matrix0[4][4];
	
	GetMatrix(m_Matrix,0,m_pt_array4.GetAt(0).x*(-1),m_pt_array4.GetAt(0).y*(-1),0,0,1);
	GetMatrix(m_Matrix0,this->m_iRatateAxis,0,0,0,this->m_dblAngle,1);
	MatrixXMatrix(m_Matrix,m_Matrix0);

	GetMatrix(m_Matrix0,0,m_pt_array4.GetAt(0).x,m_pt_array4.GetAt(0).y,0,0,1);
	MatrixXMatrix(m_Matrix,m_Matrix0);

	GetMatrix(m_Matrix0,7,0,0,0.5,0,1);
	MatrixXMatrix(m_Matrix,m_Matrix0);
	GetMatrix(m_Matrix0,8,0,0,0.5,0,1);
	MatrixXMatrix(m_Matrix,m_Matrix0);
	GetNewPointfor3D(m_Matrix);
	Invalidate(TRUE);
}
//
void CCGDrawView::suofang()
{
	double m_Matrix[4][4];
	double m_Matrix0[4][4];
	
	GetMatrix(m_Matrix,0,m_pt_array4.GetAt(0).x*(-1),m_pt_array4.GetAt(0).y*(-1),0,0,0);
	GetMatrix(m_Matrix0,10,0,0,0,0,1/m_3dk);
	MatrixXMatrix(m_Matrix,m_Matrix0);

	GetMatrix(m_Matrix0,0,m_pt_array4.GetAt(0).x,m_pt_array4.GetAt(0).y,0,0,0);
	MatrixXMatrix(m_Matrix,m_Matrix0);

	GetMatrix(m_Matrix0,7,0,0,0.5,0,1);
	MatrixXMatrix(m_Matrix,m_Matrix0);
	GetMatrix(m_Matrix0,8,0,0,0.5,0,1);
	MatrixXMatrix(m_Matrix,m_Matrix0);
	GetNewPointfor3D(m_Matrix);
	Invalidate(TRUE);
}

void CCGDrawView::jingxiang1()
{
	m_DrawType = 10;
	GetMatrix(m_Matrix1,0,m_pt_array4.GetAt(0).x*(-1),m_pt_array4.GetAt(0).y*(-1),0,0,1);
	GetMatrix(m_Matrix2,4,0,0,0,0,1);
	MatrixXMatrix(m_Matrix1,m_Matrix2);

	GetMatrix(m_Matrix2,0,m_pt_array4.GetAt(0).x*1,m_pt_array4.GetAt(0).y*1,0,0,1);
	MatrixXMatrix(m_Matrix1,m_Matrix2);

	GetMatrix(m_Matrix2,7,0,0,0.5,0,1);
	MatrixXMatrix(m_Matrix1,m_Matrix2);
GetMatrix(m_Matrix2,8,0,0,0.5,0,1);
	MatrixXMatrix(m_Matrix1,m_Matrix2);
	GetNewPointfor3D(m_Matrix1);
	Invalidate(TRUE);
}
//
void CCGDrawView::jingxiang2()
{
	m_DrawType = 10;
	GetMatrix(m_Matrix1,0,m_pt_array4.GetAt(0).x*(-1),m_pt_array4.GetAt(0).y*(-1),0,0,1);
	GetMatrix(m_Matrix2,5,0,0,0,0,1);
	MatrixXMatrix(m_Matrix1,m_Matrix2);

	GetMatrix(m_Matrix2,0,m_pt_array4.GetAt(0).x,m_pt_array4.GetAt(0).y,0,0,1);
	MatrixXMatrix(m_Matrix1,m_Matrix2);

	GetMatrix(m_Matrix2,7,0,0,0.5,0,1);
	MatrixXMatrix(m_Matrix1,m_Matrix2);
GetMatrix(m_Matrix2,8,0,0,0.5,0,1);
	MatrixXMatrix(m_Matrix1,m_Matrix2);
	GetNewPointfor3D(m_Matrix1);
	Invalidate(TRUE);
}

void CCGDrawView::jingxiang3()
{
	m_DrawType = 10;
	GetMatrix(m_Matrix1,0,m_pt_array4.GetAt(0).x*(-1),m_pt_array4.GetAt(0).y*(-1),0,0,1);
	GetMatrix(m_Matrix2,6,0,0,0,0,1);
	MatrixXMatrix(m_Matrix1,m_Matrix2);

	GetMatrix(m_Matrix2,0,m_pt_array4.GetAt(0).x,m_pt_array4.GetAt(0).y,0,0,1);
	MatrixXMatrix(m_Matrix1,m_Matrix2);

	GetMatrix(m_Matrix2,7,0,0,0.5,0,1);
	MatrixXMatrix(m_Matrix1,m_Matrix2);
GetMatrix(m_Matrix2,8,0,0,0.5,0,1);
	MatrixXMatrix(m_Matrix1,m_Matrix2);
	GetNewPointfor3D(m_Matrix1);
	Invalidate(TRUE);
}

void CCGDrawView::OnMove() 
{
if(this->m_MDlg5->GetSafeHwnd()==NULL){
		this->m_MDlg5->Create();}
	else
		this->m_MDlg5->ShowWindow(TRUE);
	// TODO: Add your command handler code here
	
}

void CCGDrawView::OnDel() 
{
	// TODO: Add your command handler code here
if(this->m_MDlg6->GetSafeHwnd()==NULL){
		this->m_MDlg6->Create();}
	else
		this->m_MDlg6->ShowWindow(TRUE);	
}
//��ʱ��ѭ���Ĳ���
void CCGDrawView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	 xx+=5;
	 yy+=5;
	yidong3D(xx,yy);
	CView::OnTimer(nIDEvent);
}
void CCGDrawView::yidong3D(int x,int y){
	m_DrawType = 10;
	double m_Matrix1[4][4];
	GetMatrix(m_Matrix1,0,x,y,0,0,1);
	GetNewPointfor3D(m_Matrix1);
	Invalidate(TRUE);
}