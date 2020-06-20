
// ALEnqStatSet.h: interface of the CALEnqStatSet class
//


#pragma once

// code generated on 08 January 2017, 02:47 PM

class CALEnqStatSet : public CRecordset
{
public:
	CALEnqStatSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CALEnqStatSet)

// Field/Param Data

// The string types below (if present) reflect the actual data type of the
// database field - CStringA for ANSI datatypes and CStringW for Unicode
// datatypes. This is to prevent the ODBC driver from performing potentially
// unnecessary conversions.  If you wish, you may change these members to
// CString types and the ODBC driver will perform all necessary conversions.
// (Note: You must use an ODBC driver version that is version 3.5 or greater
// to support both Unicode and these conversions).

	long	m_ID;
	CStringW	m_CustName;
	CStringW	m_CustEnqref;
	CTime	m_EnqDt;
	CStringW	m_emailrefofenq;
	CStringW	m_Quoteref;
	CTime	m_Quotedt;
	CStringW	m_emailrefofquote;
	CStringW	m_Equipment;
	long	m_Valueofquote;
	CStringW	m_Status;
	
// Overrides
	// Wizard generated virtual function overrides
	public:
	virtual CString GetDefaultConnect();	// Default connection string

	virtual CString GetDefaultSQL(); 	// default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX support

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

