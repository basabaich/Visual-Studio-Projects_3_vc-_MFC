// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// http://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// DataExpView.cpp : implementation of the CDataExpView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "DataExp.h"
#endif

#include "DataExpSet.h"
#include "DataExpDoc.h"
#include "DataExpView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDataExpView

IMPLEMENT_DYNCREATE(CDataExpView, CRecordView)

BEGIN_MESSAGE_MAP(CDataExpView, CRecordView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDataExpView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_RECORD_NEXT, &CDataExpView::OnRecordNext)
	ON_COMMAND(ID_RECORD_PREV, &CDataExpView::OnRecordPrev)
	ON_COMMAND(ID_RECORD_FIRST, &CDataExpView::OnRecordFirst)
	ON_COMMAND(ID_RECORD_LAST, &CDataExpView::OnRecordLast)
	ON_BN_CLICKED(IDC_BUTTON3, &CDataExpView::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CDataExpView::OnBnClickedButton4)
END_MESSAGE_MAP()

// CDataExpView construction/destruction

CDataExpView::CDataExpView()
	: CRecordView(IDD_DATAEXP_FORM)
{
	m_pSet = NULL;
	// TODO: add construction code here

}

CDataExpView::~CDataExpView()
{
}

void CDataExpView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// you can insert DDX_Field* functions here to 'connect' your controls to the database fields, ex.
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT1, m_pSet->m_ID, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT2, m_pSet->m_animals, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT3, m_pSet->m_sound, m_pSet);
	// See MSDN and ODBC samples for more information
	DDX_Control(pDX, IDC_EDIT1, m_cedit1);
	DDX_Control(pDX, IDC_EDIT2, m_cEdit2);
	DDX_Control(pDX, IDC_EDIT3, m_cEdit3);
	DDX_Control(pDX, IDC_BUTTON3, m_cButton3);
	DDX_Control(pDX, IDC_BUTTON4, m_cButton4);
}

BOOL CDataExpView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void CDataExpView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_DataExpSet;
	CRecordView::OnInitialUpdate();

}


// CDataExpView printing


void CDataExpView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDataExpView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDataExpView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDataExpView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CDataExpView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDataExpView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDataExpView diagnostics

#ifdef _DEBUG
void CDataExpView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CDataExpView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CDataExpDoc* CDataExpView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDataExpDoc)));
	return (CDataExpDoc*)m_pDocument;
}
#endif //_DEBUG


// CDataExpView database support
CRecordset* CDataExpView::OnGetRecordset()
{
	return m_pSet;
}



// CDataExpView message handlers


void CDataExpView::OnRecordNext()
{
	// TODO: Add your command handler code here
	if(!m_pSet->IsEOF())
	{
		m_pSet->MoveNext();
		UpdateData(FALSE);
	}
}


void CDataExpView::OnRecordPrev()
{
	// TODO: Add your command handler code here
	if (!m_pSet->IsBOF())
	{
		m_pSet->MoveNext();
		UpdateData(FALSE);
	}
}



void CDataExpView::OnRecordFirst()
{
	// TODO: Add your command handler code here
}


void CDataExpView::OnRecordLast()
{
	// TODO: Add your command handler code here
}


void CDataExpView::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	//////////////////////////////////
	// This is previous data button
	if (!m_pSet->IsBOF())
	{
		m_pSet->MovePrev();
		UpdateData(FALSE);
	}
}


void CDataExpView::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	///////////////////////////////////
	// This is next data button
	if (!m_pSet->IsEOF())
	{
		m_pSet->MoveNext();
		UpdateData(FALSE);
	}
}
