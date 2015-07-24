#include "stdafx.h"
#include "DiagramControlFactory.h"


CDiagramControlFactory::CDiagramControlFactory()
{
}


CDiagramControlFactory::~CDiagramControlFactory()
{
}
//Add new classes to this function for loading purposes
CDiagramEntity* CDiagramControlFactory::CreateFromString(const CString& str){

	CDiagramEntity* obj;

	obj = CDiagramLine::CreateFromString(str);
	if (!obj)
		obj = CDiagramImage::CreateFromString(str); 
	if (!obj)
		obj = CDiagramText::CreateFromString(str); 
	if (!obj)
		obj = CDiagramPort::CreateFromString(str);
	if (!obj)
		obj = CDiagramEntity::CreateFromString(str);


	return obj;
}
