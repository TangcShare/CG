#include <afxtempl.h>
#include "BasicClass.h"
#include "CMDlg.h"
#include "CMDlg1.h"
#include "CMDlg2.h"
#include "CMDlg3.h"
#include "CMDlg4.h"
#include "CMDlg5.h"
#include "CMDlg6.h"
class CCGDrawDoc;
// CGDrawView.h : interface of the CCGDrawView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CGDRAWVIEW_H__1CAA9D1A_F589_4086_A405_7D4F0053E0CB__INCLUDED_)
#define AFX_CGDRAWVIEW_H__1CAA9D1A_F589_4086_A405_7D4F0053E0CB__INCLUDED_
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CCMDlg;

class CCGDrawView : public CView
{
protected: // create from serialization only
	CCGDrawView();
	DECLARE_DYNCREATE(CCGDrawView)

// Attributes
public:
	CCGDrawDoc* GetDocument();

// Operations
public:
	int m_DrawType;//绘图类型
	BOOL m_isDraw;//是否正在绘图

	CCMDlg *m_MDlg;
	CCMDlg1 *m_MDlg1;
	CCMDlg2 *m_MDlg2;
	CCMDlg3 *m_MDlg3;
	CCMDlg4 *m_MDlg4;
	CCMDlg5 *m_MDlg5;
	CCMDlg6 *m_MDlg6;
	CArray<CLine,CLine> m_line_array;
	CArray<CLine,CLine> m_line_array1;
	CArray<CLine,CLine> m_line_array4;
	CArray<CPoint,CPoint> m_pt_array,m_pt_rot,m_pt_bl,m_pt_jx;
	CArray<CPoint,CPoint> m_pt_array1;
	CArray<CPoint,CPoint> m_pt_array2;
	CArray<CPoint,CPoint> m_pt_array3;
	CArray<CPoint,CPoint> m_pt_array4,m_pt_array40,m_point_Array1,m_point_Array;
	CPoint p1,p2,p3,p4;
	int step;
	int step1;
	void DDA_Line(CDC *&pDC,CPoint &startPoint,CPoint &endPoint,COLORREF crColor);
	void PolylineCut(CArray<CLine,CLine> &m_PolyLine_array,CCutRect m_cutRect);
	void scanTransfer(CDC* pDC);
	int fillFlag;
	void Rect(CDC *pDC,int color);
	CPoint m_OrigPoint;
	RECT rect;
    void OnRectCutlines(CArray<CLine,CLine> &m_line_array, CCutRect &m_cutRect);
	void Encode(CLine &line,CCutRect m_cutRect,int* code1,int* code2);
	void InterPt(CArray<CLine,CLine> &m_line_array,CLine &line,CCutRect m_cutRect,int* code1,int* code2);
	CCutRect m_cutRect;
//二维变换
//	CPoint RotatePoint;
//	double matrix[][3];
//	double rotateAngle,
//	double d
	double m_Matrix1[4][4];
	double m_Matrix2[4][4];
void jingxiang1();void jingxiang2();void jingxiang3();
int dbx;
	int duichenzhou;
	double m_Matrix[3][3];
	void Get2DMatrix(double matrix[][3],int iFlag,double rotateAngle,double x_dis,double y_dis,double dbl_zoom);
	
void GetNewPoint(CArray<CPoint,CPoint> &m_pt_Array4,double m_Matrix[][3]);
	void MatrixXMatrixFor2D(double matrix0[][3],double matrix1[][3]);
	void RotateTransform2D(double m_Matrix[][3],double& m_x,double& m_y,double& m_Angle);
	void MirrorTransform2D(double m_Matrix[][3],double m_x0,double m_y0,double m_x1,double m_y1);
	void ScaleTransform2D(double m_Matrix[][3],double m_x,double m_y,double m_scale);



/////3d
int m_iPointNum;
int m_iRatateAxis;
int m_iRotateAxis;
int m_i3DFlag;
double m_zlength;
double m_dblAngle;
double m_3dk;
void GetNewPointfor3D(double m_Matrix[][4]);
void GetMatrix(double matrix[][4],int iFlag,double x_dis,double y_dis,double z_dis,double rotateAngle,double dbl_zoom);
void MatrixXMatrix(double matrix0[][4],double matrix1[][4]);
double (*Point0)[4];
double (*Point1)[4];
double (*Point2)[4];
double (*Point3)[4];
void Extern();
void Rotate();
void suofang();
int times;
int xx,yy;
void yidong3D(int x,int y);


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCGDrawView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCGDrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
private:
	CPoint a,b;
	CPoint pointe;
	CPoint point3;
	CPoint point2;
	CPoint point1;
// Generated message map functions
protected:
	//{{AFX_MSG(CCGDrawView)
	afx_msg void OnDrawpoint();
	afx_msg void OnDrawline();
	afx_msg void OnDrawpol();
	afx_msg void OnFill();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnClear();
	afx_msg void OnUpdateFill(CCmdUI* pCmdUI);
	afx_msg void OnCut();
	afx_msg void OnDrawrec();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMirror();
	afx_msg void OnZoom();
	afx_msg void OnRotate();
	afx_msg void On3d();
	afx_msg void OnDrawpol1();
	afx_msg void OnMove();
	afx_msg void OnDel();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CGDrawView.cpp
inline CCGDrawDoc* CCGDrawView::GetDocument()
   { return (CCGDrawDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CGDRAWVIEW_H__1CAA9D1A_F589_4086_A405_7D4F0053E0CB__INCLUDED_)
