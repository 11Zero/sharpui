// ======================================================================
//
// Copyright (c) 2008-2012 ����, Inc. All rights reserved.
//
// Sharpui��Դ����ѭCPLЭ����п�Դ���κθ��˻������ڴ�Э���Ͽ�������ʹ�á�
//
// ======================================================================

//////////////////////////////////////////////////////////////////////////////
// GridView.cpp

#include <sui/GridView.h>

namespace ui
{

//////////////////////////////////////////////////////////////
// GridView
//
GridView::GridView()
{
    SetClassName(_T("GridView"));
}

GridView::~GridView()
{
}

void GridView::OnInitialized()
{
    __super::OnInitialized();
}

void GridView::OnRender(suic::DrawingContext * drawing)
{
    __super::OnRender(drawing);
}

};
