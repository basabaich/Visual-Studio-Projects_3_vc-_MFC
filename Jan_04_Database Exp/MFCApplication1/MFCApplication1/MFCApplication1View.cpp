
// MFCApplication1View.cpp : implementation of the CMFCApplication1View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Set.h"
#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CRecordView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CRecordView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplication1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_RECORD_NEXT, &CMFCApplication1View::OnRecordNext)
	ON_COMMAND(ID_RECORD_PREV, &CMFCApplication1View::OnRecordPrev)
//	ON_COMMAND(ID_OLE_INSERT_NEW, &CMFCApplication1View::OnOleInsertNew)
//	ON_BN_CLICKED(IDC_BTNNEWRECORD, &CMFCApplication1View::OnBnClickedBtnnewrecord)
ON_BN_CLICKED(IDC_RECORD_ADD_NEW, &CMFCApplication1View::OnRecordAddNew)
ON_BN_CLICKED(IDC_BTN_ADDRECORD, &CMFCApplication1View::OnBnClickedBtnAddrecord)
END_MESSAGE_MAP()

// CMFCApplication1View construction/destruction

CMFCApplication1View::CMFCApplication1View()
	: CRecordView(IDD_MFCAPPLICATION1_FORM)
	, m_cID()
	, m_cNameOfStudent()
	, m_cMarksInMaths()	
{
	m_pSet = NULL;
	// TODO: add construction code here

}

CMFCApplication1View::~CMFCApplication1View()
{
}

void CMFCApplication1View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// you can insert DDX_Field* functions here to 'connect' your controls to the database fields, ex.
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// See MSDN and ODBC samples for more information
	DDX_FieldText(pDX, IDC_EDIT1, m_pSet->m_ID, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT2, m_pSet->m_StudentsName, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT3, m_pSet->m_MarksinMaths, m_pSet);

	DDX_Control(pDX, IDC_EDIT1, m_cID);
	DDX_Control(pDX, IDC_EDIT2, m_cNameOfStudent);
	DDX_Control(pDX, IDC_EDIT3, m_cMarksInMaths);
	//  DDX_Text(pDX, IDC_EDIT1, m_iID);
	//  DDX_Text(pDX, IDC_EDIT2, m_csName);
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void CMFCApplication1View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCApplication1Set;
	CRecordView::OnInitialUpdate();

}


// CMFCApplication1View printing


void CMFCApplication1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplication1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCApplication1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCApplication1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMFCApplication1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication1View diagnostics

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1View database support
CRecordset* CMFCApplication1View::OnGetRecordset()
{
	return m_pSet;
}



// CMFCApplication1View message handlers


void CMFCApplication1View::OnRecordNext()
{
	// TODO: Add your command handler code here
	if (!m_pSet->IsEOF())
	{
		m_pSet->MoveNext();
		UpdateData(FALSE);
	}
}


void CMFCApplication1View::OnRecordPrev()
{
	// TODO: Add your command handler code here
	if (!m_pSet->IsBOF())
	{
		m_pSet->MovePrev();
		UpdateData(FALSE);
	}
}


//void CMFCApplication1View::OnOleInsertNew()
//{
//	// TODO: Add your command handler code here
//
//	
//}


//void CMFCApplication1View::OnBnClickedBtnnewrecord()
//{
//	// TODO: Add your control notification handler code here
//
//
//}


void CMFCApplication1View::OnRecordAddNew()
{
	// TODO: Add your control notification handler code here

	// We create a new variable "pSet" which is a pointer to CRecordset
	CRecordset* pSet = OnGetRecordset();
	if (pSet->CanUpdate() && !pSet->IsDeleted())
	{
			pSet->Edit();
			if (!UpdateData())
				return;

			pSet->Update();
		
		
	}

	////////////////////
	
		
		m_lNewID = m_pSet->GetMaxID() + 1;
		m_pSet->AddNew();
		m_pSet->m_ID = m_lNewID;
		m_pSet->Update();

		m_pSet->Requery();
		m_pSet->MoveLast();
	
	/////////////////////////////

		NewDialog1 nDlg;
		//nDlg.OnD


	/////////////////////////////	

	UpdateData(FALSE);

	// Now we need to check if all the fields are updated by the user
	// If all fields are not updated by the user then we will show a 
	// Messagebox telling him/her that records can not be updated as 
	// all fields were not updated.
	//CString csx;

	//if (IDC_EDIT1 == NULL || IDC_EDIT2 == NULL || IDC_EDIT3 == NULL)
	//{
	//MessageBox(_T("Please enter all input fields !"));
	//}

}


void CMFCApplication1View::OnBnClickedBtnAddrecord()
{
	// TODO: Add your control notification handler code here
	//DoModal();
	NewDialog1 nDlg;
	nDlg.DoModal();

}
