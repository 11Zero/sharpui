// ======================================================================
//
// Copyright (c) 2008-2012 ����, Inc. All rights reserved.
//
// Sharpui��Դ����ѭCPLЭ����п�Դ���κθ��˻������ڴ�Э���Ͽ�������ʹ�á�
//
// ======================================================================

//////////////////////////////////////////////////////////////////////////////
// ListBox.cpp

#include <sui/listboxitem.h>
#include <suic/input/uimousedriver.h>
#include <suic/render/uirender.h>
#include <sui/listbox.h>

namespace ui
{

ImplementTypeofInfo(ListBoxItem, suic::ContentControl)

ListBoxItem::ListBoxItem()
{
    SetClassName(_T("ListBoxItem"));
    SetMinHeight(16);
    SetHorizontalContentAlignment(HoriAlignment::Left);
}

ListBoxItem::~ListBoxItem()
{
}

void ListBoxItem::OnPropertyChanged(suic::PropertyChangedEventArg& e)
{
    __super::OnPropertyChanged(e);
}

void ListBoxItem::OnMouseLeftButtonDown(suic::MouseEventArg& e)
{
    suic::Element::OnMouseLeftButtonDown(e);

    if (!e.IsHandled())
    {
        Selector::SelectItem(this, true);

        InvalidateVisual();
    }
}

void ListBoxItem::OnMouseLeftButtonUp(suic::MouseEventArg& e)
{
    suic::Control::OnMouseLeftButtonUp(e);

    ListBox* pParent = dynamic_cast<ListBox*>(LogicalParent());

    if (pParent)
    {
        pParent->OnMouseLeftButtonUp(e);
    }
}

void ListBoxItem::OnRender(suic::DrawingContext * drawing)
{
    suic::Render::RenderControl(drawing, this, false);
}

}
