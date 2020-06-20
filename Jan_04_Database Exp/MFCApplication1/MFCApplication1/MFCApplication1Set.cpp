
// MFCApplication1Set.cpp : implementation of the CMFCApplication1Set class
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1Set implementation

// code generated on 11 January 2017, 10:01 PM

IMPLEMENT_DYNAMIC(CMFCApplication1Set, CRecordset)

CMFCApplication1Set::CMFCApplication1Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_StudentsName = L"";
	m_MarksinMaths = 0;
	m_nFields = 3;
	m_nDefaultType = dynaset;
}


long CMFCApplication1Set::GetMaxID()
{
	// Move to the last record
	MoveLast();

	// return the ID of this record
	return m_ID;
}


//#error Security Issue: The connection string may contain a password
// The connection string below may contain plain text passwords and/or
// other sensitive information. Please remove the #error after reviewing
// the connection string for any security related issues. You may want to
// store the password in some other form or use a different user authentication.
CString CMFCApplication1Set::GetDefaultConnect()
{
	return _T("DBQ=C:\\Users\\basab\\Desktop\\Database files\\Test1.mdb;DefaultDir=C:\\Users\\basab\\Desktop\\Database files;Driver={Driver do Microsoft Access (*.mdb)};DriverId=25;FIL=MSAccess;FILEDSN=C:\\Users\\basab\\Desktop\\Database files\\Test1.mdb.dsn;MaxBufferSize=2048;MaxScanRows=8;PageTimeout=5;SafeTransactions=0;Threads=3;UID=admin;UserCommitSync=Yes;");
}

CString CMFCApplication1Set::GetDefaultSQL()
{
	return _T("[StuMarks]");
}

void CMFCApplication1Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// Macros such as RFX_Text() and RFX_Int() are dependent on the
// type of the member variable, not the type of the field in the database.
// ODBC will try to automatically convert the column value to the requested type
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[Students Name]"), m_StudentsName);
	RFX_Long(pFX, _T("[Marks in Maths]"), m_MarksinMaths);

}
/////////////////////////////////////////////////////////////////////////////
// CMFCApplication1Set diagnostics

#ifdef _DEBUG
void CMFCApplication1Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFCApplication1Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

