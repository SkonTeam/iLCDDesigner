#include "stdafx.h"
#include "DiagramText.h"


CDiagramText::CDiagramText(){
	SetType(_T("text"));
}
CDiagramText::CDiagramText(CString inTextData, COLORREF inTextColor , int inTextScale ,BOOL inIsUnderlined) {
	mTextData = inTextData;
	mTextColor = inTextColor;
	mIsUnderlined = inIsUnderlined;
	mTextScale = inTextScale;
	SetType(_T("text"));
}

CDiagramText::~CDiagramText()
{
}
CDiagramEntity* CDiagramText::Clone(){
	CDiagramText* obj = new CDiagramText;
	obj->Copy(this);
	obj->mTextData = this->mTextData;
	obj->mTextColor = this->mTextColor;
	obj->mIsUnderlined = this->mIsUnderlined;
	obj->mTextScale = this->mTextScale;
	return obj;
}
void CDiagramText::Draw(CDC* dc, CRect rect){

	int points = 14;

	double point = static_cast< double >(dc->GetDeviceCaps(LOGPIXELSX) / 72.0);
	int fontsize = static_cast< int >((points / 10.0) * point + .5);

	int fontheight = 10 * mTextScale;

	LOGFONT	lf;
	ZeroMemory(&lf, sizeof(lf));

	lstrcpy(lf.lfFaceName, _T("FontAAA"));
	lf.lfHeight = Round(static_cast< double >(fontheight)* GetZoom());
	lf.lfItalic = (BYTE)(FALSE);
	lf.lfUnderline = (BYTE)(mIsUnderlined);
	lf.lfStrikeOut = (BYTE)(FALSE);
	lf.lfCharSet = (BYTE) DEFAULT_CHARSET;
	lf.lfWeight = FW_NORMAL;

	CFont	font;
	font.CreateFontIndirect(&lf);

	dc->SelectObject(&font);
	int color = dc->SetTextColor(mTextColor);
	int mode = dc->SetBkMode(TRANSPARENT);


	dc->DrawText(mTextData, rect, DT_NOPREFIX | DT_WORDBREAK);

	dc->SetBkMode(mode);
	dc->SelectStockObject(ANSI_VAR_FONT);
}

CString	CDiagramText::GetString() const{
	CString str;

	str.Format(_T(",%s,%i,%i,%i;"),
		mTextData,
		mTextColor,
		mIsUnderlined,
		mTextScale );

	str = GetDefaultGetString() + str;

	return str;
}

CDiagramEntity* CDiagramText::CreateFromString(const CString & str){
	CDiagramText* obj = new CDiagramText;
	if (!obj->FromString(str))
	{

		delete obj;
		obj = NULL;

	}

	return obj;
}
BOOL CDiagramText::FromString(const CString& str){
	
	BOOL result = FALSE;
	CString data(str);
	if (LoadFromString(data))
	{

		CTokenizer	tok(data);

		CString		lTextData;
		COLORREF	lTextColor;
		BOOL		lIsUnderlined;
		int			lTextScale;

		int count = 0;

		tok.GetAt(count++, lTextData);
		tok.GetAt(count++, lTextColor);
		tok.GetAt(count++, lIsUnderlined);
		tok.GetAt(count++, lTextScale);

		this->mTextData = lTextData;
		this->mTextColor = lTextColor;
		this->mIsUnderlined = lIsUnderlined;
		this->mTextScale = lTextScale;

		result = TRUE;

	}

	return result;

}