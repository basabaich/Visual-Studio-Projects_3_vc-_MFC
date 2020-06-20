
// ALEnqStatView.h : interface of the CALEnqStatView class
//

#pragma once
#include "ATLComTime.h"

class CALEnqStatSet;

class CALEnqStatView : public CRecordView
{
protected: // create from serialization only
	CALEnqStatView();
	DECLARE_DYNCREATE(CALEnqStatView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_ALENQSTAT_FORM };
#endif
	CALEnqStatSet* m_pSet;

// Attributes
public:
	CALEnqStatDoc* GetDocument() const;

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
	virtual ~CALEnqStatView();
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
	afx_msg void OnBnClickedButton1();
	CString m_csName;
	int m_iID;
	CString m_csEnqRef;
	int m_coldateEnqDate;
	CString m_csEmailRefOfEnq;
	CString m_csQuoteRef;
	int m_coledateQuoteDate;
	CString m_csEmailRefOfQuote;
	CString m_csEquipments;
	int m_intQuoteValue;
	CString m_csStatus;
	float m_floatEnqDate;
	float m_floatQuoteDate;
};

#ifndef _DEBUG  // debug version in ALEnqStatView.cpp
inline CALEnqStatDoc* CALEnqStatView::GetDocument() const
   { return reinterpret_cast<CALEnqStatDoc*>(m_pDocument); }
#endif

