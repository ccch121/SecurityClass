
// TestMutex1Dlg.h : ͷ�ļ�
//

#pragma once

#include "MyClassWithMx.h"


// CTestMutex1Dlg �Ի���
class CTestMutex1Dlg : public CDialogEx
{
// ����
public:
	CTestMutex1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

	void ThreadFunc();
	void ThreadFunc_ID();
	void ThreadFunc_Token();

// �Ի�������
	enum { IDD = IDD_TESTMUTEX1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	MX_CLASS m_MXC;
	DWORD m_iToken;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
};