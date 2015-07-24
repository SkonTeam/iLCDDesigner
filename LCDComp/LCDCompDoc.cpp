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

// LCDCompDoc.cpp : implementation of the CLCDCompDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "LCDComp.h"
#endif

#include "LCDCompDoc.h"
#include "DiagramControlFactory.h"
#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CLCDCompDoc

IMPLEMENT_DYNCREATE(CLCDCompDoc, CDocument)

BEGIN_MESSAGE_MAP(CLCDCompDoc, CDocument)
END_MESSAGE_MAP()


// CLCDCompDoc construction/destruction

CLCDCompDoc::CLCDCompDoc()
{
	// TODO: add one-time construction code here
	setBrushRect = FALSE;
}

CLCDCompDoc::~CLCDCompDoc()
{
}

BOOL CLCDCompDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CLCDCompDoc serialization

void CLCDCompDoc::Serialize(CArchive& ar)
{
	//TODO: Implement Save and Load
	if (ar.IsStoring())
	{
		ar.WriteString(mDocEntityCont.GetString() + _T("\r\n"));
		int count = 0;
		CDiagramEntity* obj;
		while ((obj = mDocEntityCont.GetAt(count++)))
			ar.WriteString(obj->GetString() + _T("\r\n"));

		mDocEntityCont.SetModified(FALSE);

	}
	else
	{
		mDocEntityCont.Clear();
		CString str;
		while (ar.ReadString(str))
		{

			if( !mDocEntityCont.FromString( str ) )
			{
				CDiagramEntity* obj = CDiagramControlFactory::CreateFromString( str ); 
				if( obj )
					mDocEntityCont.Add( obj );
			}
		}
		mDocEntityCont.SetModified( FALSE );
		// TODO: add loading code here
	}
}
BOOL CLCDCompDoc::SaveModified(){
	SetModifiedFlag(mDocEntityCont.IsModified());
	return CDocument::SaveModified();
}
#ifdef SHARED_HANDLERS

// Support for thumbnails
void CLCDCompDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CLCDCompDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CLCDCompDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CLCDCompDoc diagnostics

#ifdef _DEBUG
void CLCDCompDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLCDCompDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CLCDCompDoc commands
