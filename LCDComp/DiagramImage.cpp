#include "stdafx.h"
#include "DiagramImage.h"


CDiagramImage::CDiagramImage(CString inImgLoc)
{
	mBitmapHandle = NULL;
	mImageLocation = inImgLoc;
	SetType(_T("image"));
}
CDiagramImage::CDiagramImage()
{
	mBitmapHandle = NULL;
	mImageLocation = _T("NULL");
	SetType(_T("image"));
}

CDiagramImage::~CDiagramImage()
{
}

//Used to copy image object
CDiagramEntity* CDiagramImage::Clone(){
	CDiagramImage* obj = new CDiagramImage;
	obj->Copy(this);
	obj->SetImageLocation(this->mImageLocation);
	return obj;
}

//Called when image is resized
void CDiagramImage::Draw(CDC* dc, CRect rect){
	CImage tmpImage;
	tmpImage.Load(mImageLocation);
	if (!tmpImage.IsNull()){
		mBitmapHandle = tmpImage.Detach();
	}
	if (mBitmapHandle)
	{
		CBitmap bmp;
		bmp.Attach(mBitmapHandle);
		CDC bmpDC;
		bmpDC.CreateCompatibleDC(dc);

		static bool pmdone = false;
		if (!pmdone) {
			PremultiplyBitmapAlpha(HDC(dc), mBitmapHandle);
			pmdone = true;
		}

		CBitmap* oldbmp = bmpDC.SelectObject(&bmp);
		BITMAP bitmap;
		bmp.GetBitmap(&bitmap);
		int width = bitmap.bmWidth;
		int height = bitmap.bmHeight;


		BLENDFUNCTION bf;
		bf.BlendOp = AC_SRC_OVER;
		bf.BlendFlags = 0;
		bf.SourceConstantAlpha = 255;
		bf.AlphaFormat = AC_SRC_ALPHA;

		//dc->StretchBlt(rect.left, rect.top, rect.Width(), rect.Height(), &bmpDC, 0, 0, width, height, SRCCOPY);
		dc->AlphaBlend(rect.left, rect.top, rect.Width(), rect.Height(), &bmpDC, 0, 0, width, height, bf); //Renders with transparency
		bmpDC.SelectObject(oldbmp);
		bmp.Detach();
	}
}
void CDiagramImage::SetHBitmap(HBITMAP inHBitmap){
	mBitmapHandle = inHBitmap;
}

//Functions below needed to implement document saving and loading
CString	CDiagramImage::GetString() const{
	CString str;

	CString filename = mImageLocation;
	MakeSaveString(filename);

	str.Format(_T(",%s;"),filename);

	str = GetDefaultGetString() + str;

	return str;
}

CDiagramEntity* CDiagramImage::CreateFromString(const CString & str){
	
	CDiagramImage* obj = new CDiagramImage;
	if (!obj->FromString(str))
	{

		delete obj;
		obj = NULL;

	}

	return obj;
}
BOOL CDiagramImage::FromString(const CString& str){

	BOOL result = FALSE;
	CString data(str);
	if (LoadFromString(data))
	{

		CTokenizer	tok(data);

		CString		lImageLocation;
		

		int count = 0;

		tok.GetAt(count++, lImageLocation);
		
		UnmakeSaveString(lImageLocation);
		this->mImageLocation = lImageLocation;
		

		result = TRUE;

	}

	return result;

}