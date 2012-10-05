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
#include <suicore/uimousedriver.h>
#include <suicore/drawing/uirender.h>
#include <sui/listbox.h>

namespace ui
{

ListBoxItem::ListBoxItem()
{
    SetClassName(_T("ListBoxItem"));
    SetMinHeight(16);
    SetHorizontalContentAlignment(suic::LEFT);
}

ListBoxItem::~ListBoxItem()
{
}

void ListBoxItem::OnSetterChanged(suic::SetterChangedEventArg& e)
{
    __super::OnSetterChanged(e);
}

void ListBoxItem::OnMouseLeftButtonDown(suic::MouseEventArg& e)
{
    suic::Element::OnMouseLeftButtonDown(e);

    if (!e.Handled())
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
    if (IsEnabled() && IsSelected())
    {
        suic::TriggerPtr setter = GetStyle()->GetTrigger(suic::FOCUSED);

        if (!setter)
        {
            setter = GetStyle()->GetTrigger();
        }

        if (setter)
        {
            suic::UIRender::Draw(drawing, this, setter);
        }
    }
    else
    {
        suic::Control::OnRender(drawing);
    }
}

}
