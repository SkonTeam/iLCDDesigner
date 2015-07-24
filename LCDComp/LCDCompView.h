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

// LCDCompView.h : interface of the CLCDCompView class
//

#pragma once


#define WM_BTN_ADD (WM_USER + 100)

class CLCDCompView : public CView
{
protected: // create from serialization only
	CLCDCompView();
	DECLARE_DYNCREATE(CLCDCompView)

// Attributes
public:
	CLCDCompDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CLCDCompView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
private:
	CRect mRect;
	CBrush mBrush;
	CRect mvRect;
	BOOL mLMBDown;
	CPoint mPtold; 
	CPoint mPt;
	BOOL drawRectMouse;

	CRect  m_rcTrack;
	CPoint m_ptStartTrack;
	
	HRGN winHrgn;

	CDiagramEditor mDiagEdit;
	bool mSrlPrt0;
	bool mSrlPrt1;
	bool mUSB;
	bool mI2C;
	bool mSPI;
	bool mEthernet;
public:
	CMFCToolBarImages imagesPalette;
	CMap<int,int, CString,CString> MapBtnID;
protected:
	void DrawSelection();
// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
	afx_msg LRESULT OnBtnAdd(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void OnInitialUpdate();
	afx_msg void OnSet1btn2();
	afx_msg void OnSet1btn1();
	afx_msg void OnButton7();
	afx_msg void OnButton10();
//	afx_msg void OnUpdateButton5(CCmdUI *pCmdUI);
	afx_msg void OnButton5();
	afx_msg void OnBtnaddtogal();
	afx_msg void OnBtntext();
	afx_msg void OnEdittext();
	afx_msg void OnBtntxtcolor();
	afx_msg void OnBtntextcolor();
	afx_msg void OnCombofont();
	afx_msg void OnBtngen();
	afx_msg void OnScalespin();
	afx_msg void OnBtnsendcmd();
	afx_msg void OnBtnsavestate();
	afx_msg void OnSrlprt0();
	afx_msg void OnUpdateSrlprt0(CCmdUI *pCmdUI);
	afx_msg void OnSrlprt1();
	afx_msg void OnUpdateSrlprt1(CCmdUI *pCmdUI);
	afx_msg void OnUsbprt();
	afx_msg void OnUpdateUsbprt(CCmdUI *pCmdUI);
	afx_msg void OnI2cprt();
	afx_msg void OnUpdateI2cprt(CCmdUI *pCmdUI);
	afx_msg void OnSpiprt();
	afx_msg void OnUpdateSpiprt(CCmdUI *pCmdUI);
	afx_msg void OnEthprt();
	afx_msg void OnUpdateEthprt(CCmdUI *pCmdUI);
};

#ifndef _DEBUG  // debug version in LCDCompView.cpp
inline CLCDCompDoc* CLCDCompView::GetDocument() const
   { return reinterpret_cast<CLCDCompDoc*>(m_pDocument); }
#endif

