#pragma once

class AFX_EXT_CLASS HashHelperInterface
{
public:
	HashHelperInterface(void);
	virtual ~HashHelperInterface(void);

	virtual CString HashCString(CString csSrc);
	virtual UINT CString2HashCode(CString csSrc);

private:

};


