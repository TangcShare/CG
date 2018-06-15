// CGDrawDoc.h : interface of the CCGDrawDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CGDRAWDOC_H__F97321FA_404B_461F_B754_EAE41B00C944__INCLUDED_)
#define AFX_CGDRAWDOC_H__F97321FA_404B_461F_B754_EAE41B00C944__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCGDrawDoc : public CDocument
{
protected: // create from serialization only
	CCGDrawDoc();
	DECLARE_DYNCREATE(CCGDrawDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCGDrawDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCGDrawDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCGDrawDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CGDRAWDOC_H__F97321FA_404B_461F_B754_EAE41B00C944__INCLUDED_)
