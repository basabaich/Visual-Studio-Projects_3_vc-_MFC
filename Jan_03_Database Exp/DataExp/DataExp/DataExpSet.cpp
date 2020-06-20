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

// DataExpSet.cpp : implementation of the CDataExpSet class
//

#include "stdafx.h"
#include "DataExp.h"
#include "DataExpSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDataExpSet implementation

// code generated on 10 January 2017, 09:36 PM

IMPLEMENT_DYNAMIC(CDataExpSet, CRecordset)

CDataExpSet::CDataExpSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_sound = L"";
	m_animals = L"";
	m_nFields = 3;
	m_nDefaultType = snapshot;
}
//#error Security Issue: The connection string may contain a password
// The connection string below may contain plain text passwords and/or
// other sensitive information. Please remove the #error after reviewing
// the connection string for any security related issues. You may want to
// store the password in some other form or use a different user authentication.
CString CDataExpSet::GetDefaultConnect()
{
	return _T("DBQ=C:\\Users\\basab\\Desktop\\Database files\\db10.mdb;DefaultDir=C:\\Users\\basab\\Desktop\\Database files;Driver={Microsoft Access Driver (*.mdb, *.accdb)};DriverId=25;FIL=MS Access;FILEDSN=C:\\Users\\basab\\Desktop\\Database files\\db10.mdb.dsn;MaxBufferSize=2048;MaxScanRows=8;PageTimeout=5;SafeTransactions=0;Threads=3;UID=admin;UserCommitSync=Yes;");
}

CString CDataExpSet::GetDefaultSQL()
{
	return _T("[Animals]");
}

void CDataExpSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// Macros such as RFX_Text() and RFX_Int() are dependent on the
// type of the member variable, not the type of the field in the database.
// ODBC will try to automatically convert the column value to the requested type
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[sound]"), m_sound);
	RFX_Text(pFX, _T("[animals]"), m_animals);

}
/////////////////////////////////////////////////////////////////////////////
// CDataExpSet diagnostics

#ifdef _DEBUG
void CDataExpSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CDataExpSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

