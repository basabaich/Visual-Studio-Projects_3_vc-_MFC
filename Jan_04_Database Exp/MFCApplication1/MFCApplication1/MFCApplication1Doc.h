
// MFCApplication1Doc.h : interface of the CMFCApplication1Doc class
//


#pragma once
#include "MFCApplication1Set.h"


class CMFCApplication1Doc : public CDocument
{
protected: // create from serialization only
	CMFCApplication1Doc();
	DECLARE_DYNCREATE(CMFCApplication1Doc)

// Attributes
public:
	CMFCApplication1Set m_MFCApplication1Set;

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CMFCApplication1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
