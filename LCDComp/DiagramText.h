#pragma once
#include "C:\Users\Tijani\Documents\Visual Studio 2013\Projects\LCDComp\LCDComp\DiagramEditor\DiagramEntity.h"

class CDiagramText :
	public CDiagramEntity
{
private:
	CString mTextData;
	COLORREF mTextColor;
	BOOL mIsUnderlined;
	int mTextScale;
public:
	inline CString GetTextData(){
		return mTextData;
	}
	inline COLORREF GetTextColor(){
		return mTextColor;
	}
	inline int GetTextScale() {
		return mTextScale;
	}
public:
	CDiagramText();
	CDiagramText(CString inTextData, COLORREF inTextColor = RGB(0, 0, 0), int inTextScale = 1, BOOL inIsUnderlined = FALSE);
	~CDiagramText();
	virtual	CDiagramEntity* Clone();
	virtual void	Draw(CDC* dc, CRect rect);
	virtual CString	GetString() const;
	static CDiagramEntity* CreateFromString(const CString & str);
	virtual BOOL	FromString(const CString& str);

};

