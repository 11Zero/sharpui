// ======================================================================
//
// Copyright (c) 2008-2012 ����, Inc. All rights reserved.
//
// Sharpui��Դ����ѭCPLЭ����п�Դ���κθ��˻������ڴ�Э���Ͽ�������ʹ�á�
//
// ======================================================================

//////////////////////////////////////////////////////////////////////////////
// ToolBar.cpp

#include "stdafx.h"

#include <sui/ToolBar.h>
#include <suic/render/uirender.h>

namespace ui
{

//////////////////////////////////////////////////////////////////////////////
// ToolBar

ImplementTypeofInfo(ToolBar, HeaderedItemsControl)

ToolBar::ToolBar()
{
    SetClassName(_T("ToolBar"));
}

ToolBar::~ToolBar()
{
}

void ToolBar::OnInitialized()
{
    __super::OnInitialized();
}

void ToolBar::OnRender(suic::DrawingContext * drawing)
{
}

}
