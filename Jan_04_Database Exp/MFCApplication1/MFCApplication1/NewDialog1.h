#pragma once


// NewDialog1 dialog

class NewDialog1 : public CDialogEx
{
	DECLARE_DYNAMIC(NewDialog1)

public:
	NewDialog1(CWnd* pParent = NULL);   // standard constructor
	virtual ~NewDialog1();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NEWDIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	
};
