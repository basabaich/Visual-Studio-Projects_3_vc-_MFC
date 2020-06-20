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

// DataExpView.h : interface of the CDataExpView class
//

#pragma once
#include "afxwin.h"

class CDataExpSet;

class CDataExpView : public CRecordView
{
protected: // create from serialization only
	CDataExpView();
	DECLARE_DYNCREATE(CDataExpView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_DATAEXP_FORM };
#endif
	CDataExpSet* m_pSet;

// Attributes
public:
	CDataExpDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CDataExpView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_cedit1;
	CEdit m_cEdit2;
	CEdit m_cEdit3;
	afx_msg void OnRecordNext();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordLast();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	CButton m_cButton3;
	CButton m_cButton4;
};

#ifndef _DEBUG  // debug version in DataExpView.cpp
inline CDataExpDoc* CDataExpView::GetDocument() const
   { return reinterpret_cast<CDataExpDoc*>(m_pDocument); }
#endif

