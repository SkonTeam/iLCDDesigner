#pragma once
#include "DiagramEditor/DiagramEntity.h"
class CDiagramImage :
	public CDiagramEntity
{
private:
	HBITMAP mBitmapHandle;
	CString mImageLocation;
public:
	inline void SetImageLocation(CString inImageLocation){
		mImageLocation = inImageLocation;
	}
	inline CString GetImageLocation(){
		return mImageLocation;
	}
public:
	CDiagramImage();
	CDiagramImage(CString inImgLoc);
	~CDiagramImage();
	virtual	CDiagramEntity* Clone();
	virtual void	Draw(CDC* dc, CRect rect);
	virtual void SetHBitmap(HBITMAP inHBitmap);
	
	//Saving and loading functions
	virtual CString	GetString() const;
	static CDiagramEntity* CreateFromString(const CString & str);
	virtual BOOL	FromString(const CString& str);

};

//Utility Function for transparent background
inline void PremultiplyBitmapAlpha(HDC hDC, HBITMAP hBmp)
{
	BITMAP bm = { 0 };
	GetObject(hBmp, sizeof(bm), &bm);
	BITMAPINFO* bmi = (BITMAPINFO*)_alloca(sizeof(BITMAPINFOHEADER)+(256 * sizeof(RGBQUAD)));
	::ZeroMemory(bmi, sizeof(BITMAPINFOHEADER)+(256 * sizeof(RGBQUAD)));
	bmi->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	BOOL bRes = ::GetDIBits(hDC, hBmp, 0, bm.bmHeight, NULL, bmi, DIB_RGB_COLORS);
	if (!bRes || bmi->bmiHeader.biBitCount != 32) return;
	LPBYTE pBitData = (LPBYTE) ::LocalAlloc(LPTR, bm.bmWidth * bm.bmHeight * sizeof(DWORD));
	if (pBitData == NULL) return;
	LPBYTE pData = pBitData;
	::GetDIBits(hDC, hBmp, 0, bm.bmHeight, pData, bmi, DIB_RGB_COLORS);
	for (int y = 0; y < bm.bmHeight; y++) {
		for (int x = 0; x < bm.bmWidth; x++) {
			pData[0] = (BYTE)((DWORD)pData[0] * pData[3] / 255);
			pData[1] = (BYTE)((DWORD)pData[1] * pData[3] / 255);
			pData[2] = (BYTE)((DWORD)pData[2] * pData[3] / 255);
			pData += 4;
		}
	}
	::SetDIBits(hDC, hBmp, 0, bm.bmHeight, pBitData, bmi, DIB_RGB_COLORS);
	::LocalFree(pBitData);
}
