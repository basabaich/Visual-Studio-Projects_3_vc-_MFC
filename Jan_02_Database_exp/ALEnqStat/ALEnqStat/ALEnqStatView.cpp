
// ALEnqStatView.cpp : implementation of the CALEnqStatView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ALEnqStat.h"
#endif

#include "ALEnqStatSet.h"
#include "ALEnqStatDoc.h"
#include "ALEnqStatView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CALEnqStatView

IMPLEMENT_DYNCREATE(CALEnqStatView, CRecordView)

BEGIN_MESSAGE_MAP(CALEnqStatView, CRecordView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CALEnqStatView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON1, &CALEnqStatView::OnBnClickedButton1)
END_MESSAGE_MAP()

// CALEnqStatView construction/destruction

CALEnqStatView::CALEnqStatView() 
	: CRecordView(IDD_ALENQSTAT_FORM)	
{
	
	// TODO: add construction code here
	m_pSet = NULL;

}

CALEnqStatView::~CALEnqStatView()
{
}

void CALEnqStatView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// you can insert DDX_Field* functions here to 'connect' your controls to the database fields, ex.
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	///////////////////////////////////
	// My code starts here
	DDX_FieldText(pDX, IDC_EDIT1, m_pSet->m_CustName, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT2, m_pSet->m_ID, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT3, m_pSet->m_CustEnqref, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT4, m_pSet->m_EnqDt, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT5, m_pSet->m_emailrefofenq, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT7, m_pSet->m_Quoteref, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT8, m_pSet->m_Quotedt, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT9, m_pSet->m_emailrefofquote, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT10, m_pSet->m_Equipment, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT11, m_pSet->m_Valueofquote, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT12, m_pSet->m_Status, m_pSet);
	// My code ends here 
	///////////////////////////////
	// See MSDN and ODBC samples for more information
	  DDX_Text(pDX, IDC_EDIT1, m_csName);
	  DDX_Text(pDX, IDC_EDIT2, m_iID);
	  DDX_Text(pDX, IDC_EDIT3, m_csEnqRef);
	  DDX_Text(pDX, IDC_EDIT4, m_coldateEnqDate);
	  DDX_Text(pDX, IDC_EDIT5, m_csEmailRefOfEnq);
	  DDX_Text(pDX, IDC_EDIT7, m_csQuoteRef);
	  DDX_Text(pDX, IDC_EDIT8, m_coledateQuoteDate);
	  DDX_Text(pDX, IDC_EDIT9, m_csEmailRefOfQuote);
	  DDX_Text(pDX, IDC_EDIT10, m_csEquipments);
	  DDX_Text(pDX, IDC_EDIT11, m_intQuoteValue);
	  DDX_Text(pDX, IDC_EDIT12, m_csStatus);
	  DDX_Text(pDX, IDC_EDIT4, m_floatEnqDate);
	  DDX_Text(pDX, IDC_EDIT8, m_floatQuoteDate);
}

BOOL CALEnqStatView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void CALEnqStatView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_ALEnqStatSet;
	CRecordView::OnInitialUpdate();

}


// CALEnqStatView printing


void CALEnqStatView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CALEnqStatView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CALEnqStatView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CALEnqStatView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CALEnqStatView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CALEnqStatView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CALEnqStatView diagnostics

#ifdef _DEBUG
void CALEnqStatView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CALEnqStatView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CALEnqStatDoc* CALEnqStatView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CALEnqStatDoc)));
	return (CALEnqStatDoc*)m_pDocument;
}
#endif //_DEBUG


// CALEnqStatView database support
CRecordset* CALEnqStatView::OnGetRecordset()
{
	return m_pSet;
}



// CALEnqStatView message handlers


void CALEnqStatView::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	OnClose();
}
