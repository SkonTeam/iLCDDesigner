#pragma once
class CDiagramControlFactory
{
public:
	CDiagramControlFactory();
	~CDiagramControlFactory();
	static CDiagramEntity* CreateFromString(const CString& str);
};

