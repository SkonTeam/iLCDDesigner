#include "stdafx.h"
#include "DiagramPort.h"


CDiagramPort::CDiagramPort() {
	mSerialPort0 = FALSE;
	mSerialPort1 = FALSE;
	mUSB = FALSE;
	mI2C = FALSE;
	mSPI = FALSE;
	mEthernet = FALSE;

	SetType(_T("port"));
}
CDiagramPort::CDiagramPort(bool inSerialPort0, bool inSerialPort1, bool inUSB, bool inI2C, bool inSPI, bool inEthernet) {
	mSerialPort0 = inSerialPort0;
	mSerialPort1 = inSerialPort1;
	mUSB = inUSB;
	mI2C = inI2C;
	mSPI = inSPI;
	mEthernet = inEthernet;

	SetType(_T("port"));
}
void CDiagramPort::SetBools(bool inSerialPort0, bool inSerialPort1, bool inUSB, bool inI2C, bool inSPI, bool inEthernet) {
	
	mSerialPort0 = inSerialPort0;
	mSerialPort1 = inSerialPort1;
	mUSB = inUSB;
	mI2C = inI2C;
	mSPI = inSPI;
	mEthernet = inEthernet;

}
void CDiagramPort::GetBools(bool &inSerialPort0, bool &inSerialPort1, bool &inUSB, bool &inI2C, bool &inSPI, bool &inEthernet) {

	inSerialPort0 = mSerialPort0;
	inSerialPort1 = mSerialPort1;
	inUSB = mUSB;
	inI2C = mI2C;
	inSPI = mSPI;
	inEthernet = mEthernet;

}
CDiagramPort::~CDiagramPort() {
}
CDiagramEntity* CDiagramPort::Clone() {
	CDiagramPort* obj = new CDiagramPort;
	obj->Copy(this);

	obj->mSerialPort0 = mSerialPort0;
	obj->mSerialPort1 = mSerialPort1;
	obj->mUSB = mUSB;
	obj->mI2C = mI2C;
	obj->mSPI = mSPI;
	obj->mEthernet = mEthernet;

	return obj;
}

CString	CDiagramPort::GetString() const {
	CString str;

	bool lSerialPort0 = mSerialPort0;
	bool lSerialPort1 = mSerialPort1;
	bool lUSB = mUSB;
	bool lI2C = mI2C;
	bool lSPI = mSPI;
	bool lEthernet = mEthernet;

	str.Format(_T(",%i,%i,%i,%i,%i,%i;"), lSerialPort0,lSerialPort1,lUSB,lI2C,lSPI,lEthernet);

	str = GetDefaultGetString() + str;

	return str;
}
CDiagramEntity* CDiagramPort::CreateFromString(const CString & str) {
	CDiagramPort* obj = new CDiagramPort;
	if (!obj->FromString(str)) {

		delete obj;
		obj = NULL;

	}

	return obj;

}
BOOL CDiagramPort::FromString(const CString& str) {
	BOOL result = FALSE;
	CString data(str);
	if (LoadFromString(data)) {

		CTokenizer	tok(data);

		int lSerialPort0;
		int lSerialPort1;
		int lUSB;
		int lI2C;
		int lSPI;
		int lEthernet;


		int count = 0;

		tok.GetAt(count++, lSerialPort0);
		tok.GetAt(count++, lSerialPort1);
		tok.GetAt(count++, lUSB);
		tok.GetAt(count++, lI2C);
		tok.GetAt(count++, lSPI);
		tok.GetAt(count++, lEthernet);

		
		this->mSerialPort0 = lSerialPort0;
		this->mSerialPort1 = lSerialPort1;
		this->mUSB = lUSB;
		this->mI2C = lI2C;
		this->mSPI = lSPI;
		this->mEthernet = lEthernet;

		result = TRUE;

	}

	return result;
}