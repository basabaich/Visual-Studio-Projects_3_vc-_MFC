
// MFCApplication1View.h : interface of the CMFCApplication1View class
//

#pragma once
#include "afxwin.h"
#include"NewDialog1.h"

class CMFCApplication1Set;

class CMFCApplication1View : public CRecordView
{
protected: // create from serialization only
	CMFCApplication1View();
	DECLARE_DYNCREATE(CMFCApplication1View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCAPPLICATION1_FORM };
#endif
	CMFCApplication1Set* m_pSet;

// Attributes
public:
	CMFCApplication1Doc* GetDocument() const;

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
	virtual ~CMFCApplication1View();
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
	afx_msg void OnRecordNext();
	afx_msg void OnRecordPrev();
	
	CEdit m_cID;
	CEdit m_cNameOfStudent;
	CEdit m_cMarksInMaths;
//	afx_msg void OnOleInsertNew();
//	afx_msg void OnBnClickedBtnnewrecord();
	afx_msg void OnRecordAddNew();
//	int m_iID;
//	CString m_csName;

	//////////////////////////////////
	// Define manually
	long m_lNewID;
	
	//////////////////////////////

	afx_msg void OnBnClickedBtnAddrecord();
	
};

#ifndef _DEBUG  // debug version in MFCApplication1View.cpp
inline CMFCApplication1Doc* CMFCApplication1View::GetDocument() const
   { return reinterpret_cast<CMFCApplication1Doc*>(m_pDocument); }
#endif

