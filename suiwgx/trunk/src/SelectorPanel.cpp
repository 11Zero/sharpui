// ======================================================================
//
// Copyright (c) 2008-2012 ����, Inc. All rights reserved.
//
// Sharpui��Դ����ѭCPLЭ����п�Դ���κθ��˻������ڴ�Э���Ͽ�������ʹ�á�
//
// ======================================================================

//////////////////////////////////////////////////////////////////////////////
// SelectorPanel.cpp

#include "stdafx.h"

#include <sui/SelectorPanel.h>
#include <suic/render/uirender.h>

namespace ui
{

//////////////////////////////////////////////////////////////////////////////
// SelectorPanel

ImplementTypeofInfo(SelectorPanel, suic::Panel)

SelectorPanel::SelectorPanel()
{
    SetClassName(_T("SelectorPanel"));
}

SelectorPanel::~SelectorPanel()
{
}

void SelectorPanel::OnInitialized()
{
    __super::OnInitialized();
}

void SelectorPanel::OnRender(suic::DrawingContext * drawing)
{
}

}
