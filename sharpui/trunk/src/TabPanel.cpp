// ======================================================================
//
// Copyright (c) 2008-2012 ����, Inc. All rights reserved.
//
// Sharpui��Դ����ѭCPLЭ����п�Դ���κθ��˻������ڴ�Э���Ͽ�������ʹ�á�
//
// ======================================================================

//////////////////////////////////////////////////////////////////////////////
// TabPanel.cpp

#include <sui/TabPanel.h>

namespace ui
{

//////////////////////////////////////////////////////////////
// TabLayout
//
TabPanel::TabPanel()
{
    SetClassName(_T("TabLayout"));
}

TabPanel::~TabPanel()
{
}

void TabPanel::OnInitialized()
{
    __super::OnInitialized();
}

void TabPanel::OnRender(suic::DrawingContext * drawing)
{
    __super::OnRender(drawing);
}

void TabPanel::OnGotFocus(suic::FocusEventArg& e)
{

}

};
