
// ALEnqStatSet.cpp : implementation of the CALEnqStatSet class
//

#include "stdafx.h"
#include "ALEnqStat.h"
#include "ALEnqStatSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CALEnqStatSet implementation

// code generated on 08 January 2017, 02:47 PM

IMPLEMENT_DYNAMIC(CALEnqStatSet, CRecordset)

CALEnqStatSet::CALEnqStatSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_CustName = _T("");
	m_CustEnqref = _T("");
	//m_EnqDt;
	m_emailrefofenq = _T("");
	m_Quoteref = _T("");
	//m_Quotedt=_T("");
	m_emailrefofquote = _T("");
	m_Equipment = _T("");
	m_Valueofquote = 0;
	m_Status = _T("");
	m_nFields = 11;
	m_nDefaultType = dynaset;
}
//#error Security Issue: The connection string may contain a password
// The connection string below may contain plain text passwords and/or
// other sensitive information. Please remove the #error after reviewing
// the connection string for any security related issues. You may want to
// store the password in some other form or use a different user authentication.
CString CALEnqStatSet::GetDefaultConnect()
{
	return _T("DBQ=E:\\Visual Studio Projects_3_vc++_MFC\\AL_Status_database.mdb;DefaultDir=E:\\Visual Studio Projects_3_vc++_MFC;Driver={Microsoft Access Driver (*.mdb)};DriverId=25;FIL=MS Access;FILEDSN=E:\\Visual Studio Projects_3_vc++_MFC\\AL_Status_database.mdb.dsn;MaxBufferSize=2048;MaxScanRows=8;PageTimeout=5;SafeTransactions=0;Threads=3;UID=admin;UserCommitSync=Yes;");
}

CString CALEnqStatSet::GetDefaultSQL()
{
	return _T("[EnqData]");
}

void CALEnqStatSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// Macros such as RFX_Text() and RFX_Int() are dependent on the
// type of the member variable, not the type of the field in the database.
// ODBC will try to automatically convert the column value to the requested type
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[Cust Name]"), m_CustName);
	RFX_Text(pFX, _T("[Cust Enq ref]"), m_CustEnqref);
	RFX_Date(pFX, _T("[Enq Dt]"), m_EnqDt);
	RFX_Text(pFX, _T("[email ref of enq]"), m_emailrefofenq);
	RFX_Text(pFX, _T("[Quote ref]"), m_Quoteref);
	RFX_Date(pFX, _T("[Quote dt]"), m_Quotedt);
	RFX_Text(pFX, _T("[email ref of quote]"), m_emailrefofquote);
	RFX_Text(pFX, _T("[Equipment]"), m_Equipment);
	RFX_Long(pFX, _T("[Value of quote]"), m_Valueofquote);
	RFX_Text(pFX, _T("[Status]"), m_Status);

}
/////////////////////////////////////////////////////////////////////////////
// CALEnqStatSet diagnostics

#ifdef _DEBUG
void CALEnqStatSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CALEnqStatSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

