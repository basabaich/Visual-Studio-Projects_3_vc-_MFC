// NewDialog1.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "NewDialog1.h"
#include "afxdialogex.h"


// NewDialog1 dialog

IMPLEMENT_DYNAMIC(NewDialog1, CDialogEx)

NewDialog1::NewDialog1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_NEWDIALOG1, pParent)
{

}

NewDialog1::~NewDialog1()
{
}

void NewDialog1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(NewDialog1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &NewDialog1::OnBnClickedButton1)
END_MESSAGE_MAP()


// NewDialog1 message handlers


void NewDialog1::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	

}
