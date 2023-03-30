
// TestMutex1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TestMutex1.h"
#include "TestMutex1Dlg.h"
#include "afxdialogex.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestMutex1Dlg �Ի���

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


// CTestMutex1Dlg ��Ϣ�������

BOOL CTestMutex1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	m_iToken = 0;

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTestMutex1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CTestMutex1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTestMutex1Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	ST1 sst;
	bool bRet = m_MXC.AccessGranted(sst);

	int iNOP = 1;
}


void CTestMutex1Dlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	AfxBeginThread(LunchBackThread, this);
}


void CTestMutex1Dlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	ST1 sst;
	bool bRet = m_MXC.AccessGrantedWithID(sst);

	int iNOP = 1;
}


void CTestMutex1Dlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	bool bRet = m_MXC.AbortAccessWithID();
	if(!bRet)
		TRACE("Abort with ID failed\n");
	else
		TRACE("Abort with ID success\n");

	int iNOP = 1;
}


void CTestMutex1Dlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	AfxBeginThread(LunchBackThread_ID, this);
}


void CTestMutex1Dlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	ST1 sst;
	bool bRet = m_MXC.AccessGrantedWithToken(sst, m_iToken);

	int iNOP = 1;
}


void CTestMutex1Dlg::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	bool bRet = m_MXC.AbortAccessWithToken(m_iToken);
	if(!bRet)
		TRACE("Abort with Token failed\n");
	else
		TRACE("Abort with Token success\n");

	int iNOP = 1;
}


void CTestMutex1Dlg::OnBnClickedButton8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	AfxBeginThread(LunchBackThread_Token, this);
}
