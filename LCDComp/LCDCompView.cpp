// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// http://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// LCDCompView.cpp : implementation of the CLCDCompView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "LCDComp.h"
#endif

#include "LCDCompDoc.h"
#include "LCDCompView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

extern CMainFrame* g_pMainFrame; //Used to access MainFrame

// CLCDCompView

IMPLEMENT_DYNCREATE(CLCDCompView, CView)

BEGIN_MESSAGE_MAP(CLCDCompView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
	ON_COMMAND(ID_BUTTON10, &CLCDCompView::OnButton10)
	ON_COMMAND(ID_BTNADDTOGAL, &CLCDCompView::OnBtnaddtogal)
	ON_COMMAND(ID_BTNTEXT, &CLCDCompView::OnBtntext)
	ON_COMMAND(ID_EDITTEXT, &CLCDCompView::OnEdittext)
	ON_COMMAND(ID_BTNTEXTCOLOR, &CLCDCompView::OnBtntextcolor)
	ON_COMMAND(ID_BTNGEN, &CLCDCompView::OnBtngen)
	ON_COMMAND(ID_SCALESPIN, &CLCDCompView::OnScalespin)
	ON_COMMAND(ID_BTNSENDCMD, &CLCDCompView::OnBtnsendcmd)
	ON_COMMAND(ID_BTNSAVESTATE, &CLCDCompView::OnBtnsavestate)
	ON_COMMAND(ID_SRLPRT0, &CLCDCompView::OnSrlprt0)
	ON_UPDATE_COMMAND_UI(ID_SRLPRT0, &CLCDCompView::OnUpdateSrlprt0)
	ON_COMMAND(ID_SRLPRT1, &CLCDCompView::OnSrlprt1)
	ON_UPDATE_COMMAND_UI(ID_SRLPRT1, &CLCDCompView::OnUpdateSrlprt1)
	ON_COMMAND(ID_USBPRT, &CLCDCompView::OnUsbprt)
	ON_UPDATE_COMMAND_UI(ID_USBPRT, &CLCDCompView::OnUpdateUsbprt)
	ON_COMMAND(ID_I2CPRT, &CLCDCompView::OnI2cprt)
	ON_UPDATE_COMMAND_UI(ID_I2CPRT, &CLCDCompView::OnUpdateI2cprt)
	ON_COMMAND(ID_SPIPRT, &CLCDCompView::OnSpiprt)
	ON_UPDATE_COMMAND_UI(ID_SPIPRT, &CLCDCompView::OnUpdateSpiprt)
	ON_COMMAND(ID_ETHPRT, &CLCDCompView::OnEthprt)
	ON_UPDATE_COMMAND_UI(ID_ETHPRT, &CLCDCompView::OnUpdateEthprt)
END_MESSAGE_MAP()

// CLCDCompView construction/destruction

CLCDCompView::CLCDCompView() {
	// TODO: add construction code here
	drawRectMouse = FALSE;
	mSrlPrt0 = FALSE;
	mSrlPrt1 = FALSE;
	mUSB = FALSE;
	mI2C = FALSE;
	mSPI = FALSE;
	mEthernet = FALSE;
}

CLCDCompView::~CLCDCompView() {
}

BOOL CLCDCompView::PreCreateWindow(CREATESTRUCT& cs) {
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CLCDCompView drawing

void CLCDCompView::OnDraw(CDC* pDC) {
	CLCDCompDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

//	this->GetClientRect(&mRect);
//
//
//
//#ifdef _DEBUG
//	CString str;
//	str.Format(_T("\nX : %d, Y :%d"), mRect.right, mRect.bottom);
//	//AfxMessageBox(str);
//
//	OutputDebugString(str);
//#endif
//
//	CRect lRect(CPoint((mRect.right / 2) - 120, (mRect.bottom / 2) - 200), CSize(240, 400));
//	CBrush lBrush(BLACK_BRUSH);
//
//	pDC->SelectObject(&lBrush);
//	pDC->Rectangle(&lRect);
//
//	if (pDoc->setBrushRect == TRUE) {
//		pDC->SelectObject(pDoc->mDocBrush);
//		pDC->Rectangle(pDoc->mDocRect);
//	}
//
//	if (drawRectMouse == TRUE) {
//		CRect lRectMouse(mPtold, mPt);
//		CBrush lRectBrush(RGB(0, 127, 0));
//		pDC->SelectObject(&lRectBrush);
//		pDC->Rectangle(&lRectMouse);
//	}
}

void CLCDCompView::OnRButtonUp(UINT /* nFlags */, CPoint point) {
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CLCDCompView::OnContextMenu(CWnd* /* pWnd */, CPoint point) {
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CLCDCompView diagnostics

#ifdef _DEBUG
void CLCDCompView::AssertValid() const {
	CView::AssertValid();
}

void CLCDCompView::Dump(CDumpContext& dc) const {
	CView::Dump(dc);
}

CLCDCompDoc* CLCDCompView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLCDCompDoc)));
	return (CLCDCompDoc*)m_pDocument;
}
#endif //_DEBUG


// CLCDCompView message handlers


BOOL CLCDCompView::OnEraseBkgnd(CDC* pDC) {

	//return CView::OnEraseBkgnd(pDC);
	//return FALSE;
	// Set brush to desired background color
	CBrush backBrush(RGB(192, 192, 192));

	// Save old brush
	CBrush* pOldBrush = pDC->SelectObject(&backBrush);

	CRect rect;
	pDC->GetClipBox(&rect);     // Erase the area needed

	pDC->PatBlt(rect.left, rect.top, rect.Width(), rect.Height(),
		PATCOPY);
	pDC->SelectObject(pOldBrush);
	return TRUE;
}


void CLCDCompView::OnSize(UINT nType, int cx, int cy) {
	CView::OnSize(nType, cx, cy);
	GetClientRect(&mRect);

	if (mDiagEdit.m_hWnd)
		mDiagEdit.MoveWindow((mRect.right / 2) - 120, (mRect.bottom / 2) - 200, 240, 400);

}


void CLCDCompView::OnInitialUpdate() {
	CView::OnInitialUpdate();

	//Color Button init

	CMFCRibbonColorButton * TextColorBox = DYNAMIC_DOWNCAST(CMFCRibbonColorButton, g_pMainFrame->m_wndRibbonBar.FindByID(ID_BTNTEXTCOLOR));

	TextColorBox->EnableOtherButton(_T("More Colors..."));


	//Ribbon Gallery Init
	CArray<CString> imgsPaths;

	//Find buttons images
	CFileFind finder;
	BOOL bWorking = finder.FindFile(_T("res\\buttons\\*.png"));
	while (bWorking) {
		CString str;
		bWorking = finder.FindNextFile();
		
		str.Format(_T("%s"), (LPCTSTR)finder.GetFilePath());
#ifdef _DEBUG
		AfxMessageBox(str);
#endif // _DEBUG


		imgsPaths.Add(str);
	}

	CMFCRibbonGallery * btn7 = DYNAMIC_DOWNCAST(CMFCRibbonGallery, g_pMainFrame->m_wndRibbonBar.FindByID(ID_BUTTON10));

	imagesPalette.SetImageSize(CSize(64, 64));


	//Populate palette from buttons folder
	for (int i = 0; i < imgsPaths.GetSize(); i++) {
		CImage tmpImage;
		tmpImage.Load(imgsPaths[i]);
		HBITMAP BitmapHandle = tmpImage.Detach();

		if (BitmapHandle)imagesPalette.AddImage(BitmapHandle, TRUE);
		else AfxMessageBox(_T("Hbitmap Null"));

		MapBtnID[imagesPalette.GetCount() - 1] = imgsPaths[i];
	}

#ifdef _DEBUG
	CString str;
	str.Format(_T("Image Count : %d"), imagesPalette.GetCount());
	AfxMessageBox(str);
#endif // _DEBUG

	//Attach palette to image gallery
	btn7->SetPalette(imagesPalette);
	btn7->SetPaletteID(5);
	btn7->RedrawIcons();
	g_pMainFrame->m_wndRibbonBar.ForceRecalcLayout();

	//END OF IMG GALLERY INIT

	//Diagram editor init
	if (!mDiagEdit.m_hWnd) {

		CLCDCompDoc* pDoc = GetDocument();

		CRect rect;
		GetClientRect(rect);
		mDiagEdit.Create(WS_CHILD | WS_VISIBLE, rect, this, &(pDoc->mDocEntityCont));

		int count = 0;

		CDiagramEntity* objTemp;

		while ((objTemp = pDoc->mDocEntityCont.GetAt(count++))) {

			if (objTemp->GetType() == _T("port")) {
				
				//TODO: Set Checkbox State from file
				CString boolStr;
				CDiagramPort* objPort = reinterpret_cast<CDiagramPort*>(objTemp);
				
				objPort->GetBools(mSrlPrt0, mSrlPrt1, mUSB, mI2C, mSPI, mEthernet);
				
				boolStr.Format(_T("%i,%i,%i,%i,%i,%i"), mSrlPrt0, mSrlPrt1, mUSB, mI2C, mSPI, mEthernet);
				
				AfxMessageBox(boolStr);
				g_pMainFrame->m_wndRibbonBar.ForceRecalcLayout();
				

			}
		}
	}
	else
		mDiagEdit.Clear();
	
}


void CLCDCompView::OnButton10() {

	CString str;

	int palID;

	CMFCRibbonGallery * btn7 = DYNAMIC_DOWNCAST(CMFCRibbonGallery, g_pMainFrame->m_wndRibbonBar.FindByID(ID_BUTTON10));
	palID = btn7->GetPaletteID();
	int LastSelected = btn7->GetLastSelectedItem(palID);

	/*str.Format(_T("Palette ID : %d last item : %d ImgLoc : %s"), palID, LastSelected,MapBtnID[LastSelected]);
	AfxMessageBox(str);*/

	CString FilePath = MapBtnID[LastSelected]; //Get path to clicked image

	//TODO: Add Event handling

	mDiagEdit.SetSnapToGrid(TRUE);
	if (mDiagEdit.GetMultidraw() == FALSE) {
		//mDiagEdit.SetMultidraw(TRUE);
		CDiagramEntity* obj = new CDiagramImage(FilePath);
		mDiagEdit.StartDrawingObject(obj);

	}
	else {
		mDiagEdit.SetMultidraw(FALSE);
	}


}


void CLCDCompView::OnButton5() {

	// TODO: Add your command handler code here
}

HBITMAP ResizeBmp(HWND hWnd, HBITMAP hBmp, int cx, int cy) {
	HDC dc = GetDC(hWnd);
	HDC copyDC = CreateCompatibleDC(dc);
	HDC srcDC = CreateCompatibleDC(dc);
	int oriCx, oriCy;

	//Get Original Size
	BITMAP bm;
	GetObject(hBmp, sizeof(bm), &bm);
	oriCx = bm.bmWidth;
	oriCy = bm.bmHeight;

	RECT bmpRect;
	bmpRect.top = 0;
	bmpRect.left = 0;
	bmpRect.right = cx;
	bmpRect.bottom = cy;

	RECT oriRect = bmpRect;
	oriRect.right = oriCx;
	oriRect.bottom = oriCy;

	HRGN rgn1 = CreateRectRgnIndirect(&bmpRect);
	HRGN rgn2 = CreateRectRgnIndirect(&oriRect);
	SelectClipRgn(copyDC, rgn1);
	SelectClipRgn(srcDC, rgn2);
	DeleteObject(rgn1);
	DeleteObject(rgn2);

	HBITMAP copyBMP = CreateCompatibleBitmap(dc, cx, cy);
	HBITMAP copyBMPold = (HBITMAP)SelectObject(copyDC, copyBMP);
	HBITMAP srcBMPold = (HBITMAP)SelectObject(srcDC, hBmp);

	if (oriCx != cx || oriCy != cy) {
		StretchBlt(copyDC, 0, 0, cx, cy, srcDC, 0, 0, oriCx, oriCy, SRCCOPY);
	}
	else {
		BitBlt(copyDC, 0, 0, cx, cy, srcDC, 0, 0, SRCCOPY);
	}

	copyBMP = (HBITMAP)SelectObject(copyDC, copyBMPold);

	DeleteDC(copyDC);
	DeleteDC(srcDC);

	return copyBMP;
}
CImage* Resize64pxV2(CImage& image) {
	if (!image.IsNull()) {
		int iNewWidth = 64;
		int iNewHeight = 64;

		CDC *screenDC = CDC::FromHandle(GetDC(NULL));
		CDC *pMDC = new CDC;
		pMDC->CreateCompatibleDC(screenDC);

		CBitmap *pb = new CBitmap;
		pb->CreateCompatibleBitmap(screenDC, iNewWidth, iNewHeight);

		CBitmap *pob = pMDC->SelectObject(pb);
		image.StretchBlt(pMDC->m_hDC, 0, 0, iNewWidth, iNewHeight, 0, 0, image.GetWidth(), image.GetHeight(), SRCCOPY);
		pMDC->SelectObject(pob);
		
		CImage * new_image = new CImage;
		new_image->Attach((HBITMAP)(*pb));
		
		//new_image->Save(_T("c:\\NewImage2.png"));
		
		//*outImage = new_image;

		//delete pb;
		//delete pMDC;

		return new_image;
	}
	return NULL;
}
void CLCDCompView::OnBtnaddtogal() {
	CString filename;

	CFileDialog fOpenDlg(TRUE, L"bmp", NULL, OFN_FILEMUSTEXIST,
		_T("PNG Images (*.png)|*.png|Bitmap Images (*.bmp)|*.bmp-||"), this);

	fOpenDlg.m_pOFN->lpstrTitle = _T("Button image file");

	fOpenDlg.m_pOFN->lpstrInitialDir = _T("c:");

	if (fOpenDlg.DoModal() == IDOK) {
		filename = fOpenDlg.GetPathName(); // return full path and filename

		CMFCRibbonGallery * btn7 = DYNAMIC_DOWNCAST(CMFCRibbonGallery, g_pMainFrame->m_wndRibbonBar.FindByID(ID_BUTTON10));

		CImage image;
		image.Load(filename);

		HBITMAP BitmapHandle = image.Detach();

		BitmapHandle = ResizeBmp((GetActiveWindow())->GetSafeHwnd(), BitmapHandle, 64, 64);

		//TODO: Resize images width > 64 pix

		if (BitmapHandle)imagesPalette.AddImage(BitmapHandle, TRUE);
		else AfxMessageBox(_T("Hbitmap Null"));

		btn7->SetPalette(imagesPalette);
		btn7->SetPaletteID(5);
		btn7->RedrawIcons();
		g_pMainFrame->m_wndRibbonBar.ForceRecalcLayout();

		MapBtnID[imagesPalette.GetCount() - 1] = filename;

#ifdef _DEBUG
		AfxMessageBox(filename);
#endif // _DEBUG

	}

}


void CLCDCompView::OnBtntext() {
	CMFCRibbonEdit * TextEditBox = DYNAMIC_DOWNCAST(CMFCRibbonEdit, g_pMainFrame->m_wndRibbonBar.FindByID(ID_EDITTEXT));
	CMFCRibbonColorButton * TextColorBox = DYNAMIC_DOWNCAST(CMFCRibbonColorButton, g_pMainFrame->m_wndRibbonBar.FindByID(ID_BTNTEXTCOLOR));
	CMFCRibbonEdit * TextScaleSpin = DYNAMIC_DOWNCAST(CMFCRibbonEdit, g_pMainFrame->m_wndRibbonBar.FindByID(ID_SCALESPIN));

	CString lText = TextEditBox->GetEditText();
	COLORREF lTextColor = TextColorBox->GetColor();
	int lTextScale = _ttoi(TextScaleSpin->GetEditText());

	mDiagEdit.SetSnapToGrid(TRUE);
	if (mDiagEdit.GetMultidraw() == FALSE) {
		//mDiagEdit.SetMultidraw(TRUE);
		CDiagramEntity* obj = new CDiagramText(lText, lTextColor, lTextScale);
		mDiagEdit.StartDrawingObject(obj);

	}
	else {
		mDiagEdit.SetMultidraw(FALSE);
	}
}


void CLCDCompView::OnEdittext() {
	// TODO: Add your command handler code here
}

void CLCDCompView::OnBtntextcolor() {
	// TODO: Add your command handler code here
}

void CLCDCompView::OnCombofont() {

	// TODO: Add your command handler code here
}
//Helper functions
std::string CstrToStr(CString inCStr) {
	CT2CA pszConvertedAnsiString(inCStr);
	std::string StdStr(pszConvertedAnsiString);
	return StdStr;
}
CString ExtractFilename(CString inFilePath) {

	int nameIndex = inFilePath.ReverseFind(_T('\\'));
	if (nameIndex == -1)return _T("");
	CString inNameExt(inFilePath.Mid(nameIndex + 1));
	int pngIndex = inNameExt.ReverseFind(_T('.'));
	if (pngIndex == -1)return inNameExt;
	CString FileName(inNameExt.Mid(0, pngIndex));

	return FileName;
}

//Generate LCD commands based on added objects
void CLCDCompView::OnBtngen() {

	CLCDCompDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CString filepath;

	CFileDialog fBuildDlg(FALSE, L"txt", NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		_T("Text files (*.txt)|*.txt||"), this);

	fBuildDlg.m_pOFN->lpstrTitle = _T("Button image file");

	fBuildDlg.m_pOFN->lpstrInitialDir = _T("c:");

	if (fBuildDlg.DoModal() == IDOK) {


		filepath = fBuildDlg.GetPathName();
		Screen LCDCodeGen(CstrToStr(filepath));

		int count = 0;

		pDoc->DoFileSave();
		AfxMessageBox(ExtractFilename(pDoc->GetPathName()));

		LCDCodeGen.StartMacro("ResetMacro", 0);
		LCDCodeGen.ResetAll();
		LCDCodeGen.EndMacro();

		LCDCodeGen.StartMacro(CstrToStr(ExtractFilename(pDoc->GetPathName())), 1);
		CDiagramEntity* obj;
		while ((obj = pDoc->mDocEntityCont.GetAt(count++))) {
			CString TypeStr = obj->GetType();

			if (TypeStr == _T("image")) {
				CDiagramImage* objImage = reinterpret_cast<CDiagramImage*>(obj);

				//Extract filename from path
				CString ImagePath(objImage->GetImageLocation());
				int nameIndex = ImagePath.ReverseFind(_T('\\'));
				CString ImageNameExt(ImagePath.Mid(nameIndex + 1));
				int pngIndex = ImageNameExt.ReverseFind(_T('.'));
				CString ImageName(ImageNameExt.Mid(0, pngIndex));

				//Convert from CString to String
				std::string NameStr(CstrToStr(ImageName));
				NameStr.append(SSTR(count));

				LCDCodeGen.WriteComment(std::string("Display image : " + NameStr));
				//LCDCodeGen.StartMacro(NameStr, count - 1);
				//Code Generator
				
				//TODO: Fix Macro names and ids
				//Erase Display
				//LCDCodeGen.EraseDisplay();

				//Initialize LCD graphics to scale
				LCDCodeGen.SetGraphicsScaling((byte_int)(objImage->GetRight() - objImage->GetLeft()) / 64);

				//Set position and draw
				LCDCodeGen.SetCursorPosition((word)objImage->GetLeft(), (word)objImage->GetTop());
				LCDCodeGen.DisplayLocalGraphicbyname((char*)NameStr.c_str());

				//Set Touch Rectangle
				LCDCodeGen.SetTouchFieldHeight((word)(objImage->GetBottom() - objImage->GetTop()));
				LCDCodeGen.SetTouchFieldWidth((word)(objImage->GetRight() - objImage->GetLeft()));

				//Set Touch event screens

				//TODO: Implement touch actions

				LCDCodeGen.SetTouchFieldMakeMacrobyname("<SET THE NAME OF MACRO TO LAUNCH WHEN PRESSED HERE>");
				//LCDCodeGen.SetTouchFieldBreakMacrobyname("TheBreak");

				//Create Touch field
				LCDCodeGen.CreateDefineTouchField(2, 33);
			}

			if (TypeStr == _T("text")) {
				CDiagramText* objText = reinterpret_cast<CDiagramText*>(obj);

				std::string textStr(CstrToStr(objText->GetTextData()));
				int TextScale = objText->GetTextScale();

				//LCDCodeGen.StartMacro(textStr, count - 1);
				
				//Code Generator

				LCDCodeGen.WriteComment(std::string("Display text : " + textStr));

				LCDCodeGen.SetFontsScaling(TextScale);

				LCDCodeGen.SetForegroundColor(objText->GetTextColor());
				LCDCodeGen.SetCursorPosition((word)objText->GetLeft(), (word)objText->GetTop());
				LCDCodeGen.WriteText(textStr);

			}
			if (TypeStr == _T("port")) {
				CDiagramPort* objPort = reinterpret_cast<CDiagramPort*>(obj);

				PortNumbers PrtState = NULLPRT;
				std::string PortsEnabledStr("Enabling Ports : ");

				if (mSrlPrt0) { PrtState = PrtState | SERIALPRT0; PortsEnabledStr.append(" Serial Port 0||"); }
				if (mSrlPrt1) { PrtState = PrtState | SERIALPRT1; PortsEnabledStr.append(" Serial Port 1||"); }
				if (mUSB) { PrtState = PrtState | USB; PortsEnabledStr.append(" USB||"); }
				if (mI2C) { PrtState = PrtState | I2C; PortsEnabledStr.append(" I2C||"); }
				if (mSPI) { PrtState = PrtState | SPI; PortsEnabledStr.append(" SPI||"); }
				if (mEthernet) { PrtState = PrtState | ETHERNET; PortsEnabledStr.append(" Ethernet||"); }

				//Code Generator
				LCDCodeGen.WriteComment(PortsEnabledStr);

				LCDCodeGen.EnableDisableCommunicationPorts(PrtState,500);

			}

		}
		LCDCodeGen.EndMacro();
	}
	
}


void CLCDCompView::OnScalespin() {
	// TODO: Add your command handler code here
}


void CLCDCompView::OnBtnsendcmd() {
	AfxMessageBox(_T("NOT YET IMPLEMENTED!"));
	
}


void CLCDCompView::OnBtnsavestate() {
	CLCDCompDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	int count = 0;
	
	CDiagramEntity* objTemp;
	
	while ((objTemp = pDoc->mDocEntityCont.GetAt(count++))) {
		
		if (objTemp->GetType() == _T("port")) {

			CDiagramPort* objPort = reinterpret_cast<CDiagramPort*>(objTemp);
			objPort->SetBools(mSrlPrt0, mSrlPrt1, mUSB, mI2C, mSPI, mEthernet);
			return;
		}
	}

	CDiagramEntity* obj = new CDiagramPort(mSrlPrt0, mSrlPrt1, mUSB, mI2C, mSPI, mEthernet);
	mDiagEdit.AddObject(obj);
}

//CheckBox Mechanics
void CLCDCompView::OnSrlprt0() {
	mSrlPrt0 = !mSrlPrt0;
}


void CLCDCompView::OnUpdateSrlprt0(CCmdUI *pCmdUI) {
	pCmdUI->SetCheck(mSrlPrt0);
}


void CLCDCompView::OnSrlprt1() {
	mSrlPrt1 = !mSrlPrt1;
}


void CLCDCompView::OnUpdateSrlprt1(CCmdUI *pCmdUI) {
	pCmdUI->SetCheck(mSrlPrt1);
}


void CLCDCompView::OnUsbprt() {
	mUSB = !mUSB;
}


void CLCDCompView::OnUpdateUsbprt(CCmdUI *pCmdUI) {
	pCmdUI->SetCheck(mUSB);
}


void CLCDCompView::OnI2cprt() {
	mI2C = !mI2C;
}


void CLCDCompView::OnUpdateI2cprt(CCmdUI *pCmdUI) {
	pCmdUI->SetCheck(mI2C);
}


void CLCDCompView::OnSpiprt() {
	mSPI = !mSPI;
}


void CLCDCompView::OnUpdateSpiprt(CCmdUI *pCmdUI) {
	pCmdUI->SetCheck(mSPI);
}


void CLCDCompView::OnEthprt() {
	mEthernet = !mEthernet;
}


void CLCDCompView::OnUpdateEthprt(CCmdUI *pCmdUI) {
	pCmdUI->SetCheck(mEthernet);
}
//End of Checkbox Mechanics