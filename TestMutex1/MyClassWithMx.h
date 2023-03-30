#pragma once

#include "HashHelper/HashHelperInterface.h"

typedef struct st1
{
	int iA;
	float fB;

	st1()
	{
		iA = 1;
		fB = 2.0f;
	}
}ST1;

typedef class CMyClassWithMx
{
public:
	CMyClassWithMx()
	{
		_hMutex = CreateMutex(NULL, FALSE, "Mutex1");
		_iAccessToken = 0;
		_iCurrentID = 0;

		InitDLL();
	}

	~CMyClassWithMx()
	{
		if(_hMutex != INVALID_HANDLE_VALUE)
			CloseHandle(_hMutex);

		if(_hDllInstance != nullptr)
		{
			FreeLibrary(_hDllInstance);
			_hDllInstance = nullptr;
			_handle = nullptr;
		}
	}

	bool AccessGranted(ST1 &sst)
	{
		if(WaitForSingleObject(_hMutex, 2000) != WAIT_OBJECT_0)
			return false;

		sst = _st1;
		_iCurrentID = GetCurrentThreadId();
		TraceInfo();
		ReleaseMutex(_hMutex);
		return true;
	}

	bool EndAccess(ST1 sst)
	{
		if(WaitForSingleObject(_hMutex, 2000) != WAIT_OBJECT_0)
			return false;

		_st1 = sst;
		ReleaseMutex(_hMutex);
		return true;
	}

	bool AccessGrantedWithID(ST1 &sst)
	{
		if(WaitForSingleObject(_hMutex, 2000) != WAIT_OBJECT_0)
			return false;

		sst = _st1;
		_iCurrentID = GetCurrentThreadId();
		
		TraceInfo();
		//ReleaseMutex(_hMutex);
		return true;
	}

	bool EndAccessWithID(ST1 sst)
	{
// 		if(WaitForSingleObject(_hMutex, 2000) != WAIT_OBJECT_0)
// 			return false;
		DWORD dwCurID = GetCurrentThreadId();
		if(dwCurID != _iCurrentID)
			return false;

		_st1 = sst;
		_iCurrentID = 0;
		ReleaseMutex(_hMutex);
		return true;
	}

	bool AccessGrantedWithToken(ST1 &sst, DWORD &dwToken)
	{
		if(WaitForSingleObject(_hMutex, 2000) != WAIT_OBJECT_0)
			return false;

		sst = _st1;
		_iCurrentID = GetCurrentThreadId();
		TraceInfo();
		_iAccessToken = _pInstance->CString2HashCode(_csID);
		dwToken = _iAccessToken;
		TraceToken();
		return true;
	}

	bool EndAccessWithToken(ST1 sst, DWORD dwToken)
	{
		if(dwToken != _iAccessToken)
			return false;

		_st1 = sst;
		_iCurrentID = 0;
		_iAccessToken = 0;
		ReleaseMutex(_hMutex);
		return true;
	}

	bool AbortAccess()
	{
		return true;
	}

	bool AbortAccessWithID()
	{
		DWORD dwCurID = GetCurrentThreadId();
		if(dwCurID != _iCurrentID)
			return false;

		_iCurrentID = 0;
		ReleaseMutex(_hMutex);
		return true;
	}

	bool AbortAccessWithToken(DWORD dwToken)
	{
		if(dwToken != _iAccessToken)
			return false;

		_iCurrentID = 0;
		_iAccessToken = 0;
		ReleaseMutex(_hMutex);
		return true;
	}

	void TraceInfo()
	{
		CString csInfo;
		//csInfo.Format("Current thread ID:0x%08x\n", _iCurrentID);
		csInfo.Format("0x%08x", _iCurrentID);
		_csID = csInfo;
		csInfo = "Current thread ID:" + csInfo + "\n";
		TRACE(csInfo);
	}

	void TraceToken()
	{
		CString csInfo;
		csInfo.Format("Current Access Token:0x%08x\n", _iAccessToken);
		TRACE(csInfo);
	}

	void InitDLL()
	{
		_hDllInstance = ::AfxLoadLibrary("HashHelperDll.dll");
		if (_hDllInstance == nullptr)
		{
			DWORD dwError = GetLastError();
			return;
		}
		// 获取动态库中函数地址
		_handle = GetProcAddress(_hDllInstance, _T("GetInstance"));
		if (nullptr == _handle)
		{
			assert(false);
			FreeLibrary(_hDllInstance);
			return;
		}

		_pInstance = (HashHelperInterface *)_handle();
	}

protected:
	ST1 _st1;
	HANDLE _hMutex;
	DWORD _iCurrentID;
	DWORD _iAccessToken;
	CString _csID;

private:
	FARPROC _handle;
	HINSTANCE _hDllInstance;
	HashHelperInterface *_pInstance;

}MX_CLASS;