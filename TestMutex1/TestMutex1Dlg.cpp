
// TestMutex1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TestMutex1.h"
#include "TestMutex1Dlg.h"
#include "afxdialogex.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestMutex1Dlg 对话框

UINT LunchBackThread(LPVOID pParam)
{
	CTestMutex1Dlg *pDlg = (CTestMutex1Dlg*)pParam;
	pDlg->ThreadFunc();

	return 0;
}

UINT LunchBackThread_ID(LPVOID pParam)
{
	CTestMutex1Dlg *pDlg = (CTestMutex1Dlg*)pParam;
	pDlg->ThreadFunc_ID();

	return 0;
}

UINT LunchBackThread_Token(LPVOID pParam)
{
	CTestMutex1Dlg *pDlg = (CTestMutex1Dlg*)pParam;
	pDlg->ThreadFunc_Token();

	return 0;
}

void CTestMutex1Dlg::ThreadFunc()
{
	ST1 sst;
	bool bRet = m_MXC.AccessGranted(sst);

	int iNOP = 1;
}

void CTestMutex1Dlg::ThreadFunc_ID()
{
	bool bRet = m_MXC.AbortAccessWithID();
	if(!bRet)
		TRACE("Abort with ID failed\n");
	else
		TRACE("Abort with ID success\n");

	int iNOP = 1;
}

void CTestMutex1Dlg::ThreadFunc_Token()
{
	bool bRet = m_MXC.AbortAccessWithToken(0x1234);
	if(!bRet)
		TRACE("Abort with Token failed\n");
	else
		TRACE("Abort with Token success\n");

	int iNOP = 1;
}

CTestMutex1Dlg::CTestMutex1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTestMutex1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestMutex1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestMutex1Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CTestMutex1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CTestMutex1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CTestMutex1Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CTestMutex1Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CTestMutex1Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CTestMutex1Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CTestMutex1Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CTestMutex1Dlg::OnBnClickedButton8)
END_MESSAGE_MAP()


// CTestMutex1Dlg 消息处理程序

BOOL CTestMutex1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	m_iToken = 0;

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTestMutex1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CTestMutex1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTestMutex1Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	ST1 sst;
	bool bRet = m_MXC.AccessGranted(sst);

	int iNOP = 1;
}


void CTestMutex1Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	AfxBeginThread(LunchBackThread, this);
}


void CTestMutex1Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码

	ST1 sst;
	bool bRet = m_MXC.AccessGrantedWithID(sst);

	int iNOP = 1;
}


void CTestMutex1Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码

	bool bRet = m_MXC.AbortAccessWithID();
	if(!bRet)
		TRACE("Abort with ID failed\n");
	else
		TRACE("Abort with ID success\n");

	int iNOP = 1;
}


void CTestMutex1Dlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码

	AfxBeginThread(LunchBackThread_ID, this);
}


void CTestMutex1Dlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码

	ST1 sst;
	bool bRet = m_MXC.AccessGrantedWithToken(sst, m_iToken);

	int iNOP = 1;
}


void CTestMutex1Dlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码

	bool bRet = m_MXC.AbortAccessWithToken(m_iToken);
	if(!bRet)
		TRACE("Abort with Token failed\n");
	else
		TRACE("Abort with Token success\n");

	int iNOP = 1;
}


void CTestMutex1Dlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码

	AfxBeginThread(LunchBackThread_Token, this);
}
