
// TestMutex1.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTestMutex1App:
// �йش����ʵ�֣������ TestMutex1.cpp
//

class CTestMutex1App : public CWinApp
{
public:
	CTestMutex1App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTestMutex1App theApp;