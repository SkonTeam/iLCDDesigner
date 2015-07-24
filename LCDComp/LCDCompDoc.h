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

// LCDCompDoc.h : interface of the CLCDCompDoc class
//


#pragma once


class CLCDCompDoc : public CDocument
{
protected: // create from serialization only
	CLCDCompDoc();
	DECLARE_DYNCREATE(CLCDCompDoc)

// Attributes
public:
	
// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL SaveModified();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CLCDCompDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	inline void SetDocRect(CRect* inRect){
		mDocRect.CopyRect(inRect);
	}
	inline void SetDocBrush(COLORREF inBrush){
		mDocBrush.CreateSolidBrush(inBrush);
		setBrushRect = TRUE;
	}
public:
	CRect mDocRect;
	CBrush mDocBrush;
	bool setBrushRect;
	CDiagramEntityContainer mDocEntityCont;
protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS

};
