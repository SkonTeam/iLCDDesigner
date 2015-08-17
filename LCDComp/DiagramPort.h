#pragma once
#include "DiagramEditor/DiagramEntity.h"
class CDiagramPort :
	public CDiagramEntity
{
private:
	bool mSerialPort0;
	bool mSerialPort1;
	bool mUSB;
	bool mI2C;
	bool mSPI;
	bool mEthernet;
public:
	CDiagramPort();
	CDiagramPort(bool inSerialPort0, bool inSerialPort1, bool inUSB, bool inI2C, bool inSPI, bool inEthernet);
	~CDiagramPort();
	virtual	CDiagramEntity* Clone();

	//Saving and loading functions
	virtual CString	GetString() const;
	static CDiagramEntity* CreateFromString(const CString & str);
	virtual BOOL	FromString(const CString& str);

	void SetBools(bool inSerialPort0, bool inSerialPort1, bool inUSB, bool inI2C, bool inSPI, bool inEthernet);
	void GetBools(bool &inSerialPort0, bool &inSerialPort1, bool &inUSB, bool &inI2C, bool &inSPI, bool &inEthernet);
};

