// CGDrawDoc.cpp : implementation of the CCGDrawDoc class
//

#include "stdafx.h"
#include "CGDraw.h"

#include "CGDrawDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCGDrawDoc

IMPLEMENT_DYNCREATE(CCGDrawDoc, CDocument)

BEGIN_MESSAGE_MAP(CCGDrawDoc, CDocument)
	//{{AFX_MSG_MAP(CCGDrawDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCGDrawDoc construction/destruction

CCGDrawDoc::CCGDrawDoc()
{
	// TODO: add one-time construction code here

}

CCGDrawDoc::~CCGDrawDoc()
{
}

BOOL CCGDrawDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCGDrawDoc serialization

void CCGDrawDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CCGDrawDoc diagnostics

#ifdef _DEBUG
void CCGDrawDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCGDrawDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCGDrawDoc commands
