// ======================================================================
//
// Copyright (c) 2008-2012 ����, Inc. All rights reserved.
//
// Sharpui��Դ����ѭCPLЭ����п�Դ���κθ��˻������ڴ�Э���Ͽ�������ʹ�á�
//
// ======================================================================

//////////////////////////////////////////////////////////////////////////////
// MenuItem.cpp

#include <sui/menuitem.h>
#include <sui/Menu.h>
#include <suicore/hwndadapter.h>
#include <suicore/drawing/uirender.h>

#include "menuitemhelper.h"

namespace ui
{

MenuItem::MenuItem()
{
    SetClassName(_T("MenuItem"));
    SetMinHeight(MENUITEM_MINHEIGHT);
    SetHorizontalContentAlignment(suic::LEFT);
    SetFocusable(false);
    SetOrientation(CoreFlags::Vertical);
}

MenuItem::~MenuItem()
{
}

bool MenuItem::IsSubmenuOpen() const
{
    if (!IsSubmenu())
    {
        return false;
    }

    return !_submenuPopup->IsClosed();
}

bool MenuItem::IsSubmenu() const
{
    if (!_submenuPopup)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void MenuItem::SetIcon(suic::ImagePtr icon)
{
    _icon = icon;
}

suic::ImagePtr MenuItem::GetIcon() const
{
    return _icon;
}

////////////////////////////////////////////////////////////////////////////////////////////
// �˵����¼�
//
void MenuItem::OnClick(suic::ObjectPtr menu, bool bIsMain)
{
}

void MenuItem::OnPopupClosed(suic::ObjectPtr source, suic::EventArg& e)
{

}

void MenuItem::OnSubmenuOpened(suic::RoutedEventArg& e)
{

}

void MenuItem::OnChecked(suic::RoutedEventArg& e)
{

}

void MenuItem::OnUnchecked(suic::RoutedEventArg& e)
{

}

////////////////////////////////////////////////////////////////////////////////////////////
// MenuItem
//
suic::ElementPtr MenuItem::FindName(const suic::String& strName)
{
    if (GetName().Equals(strName))
    {
        return this;
    }
    else if (!_submenuPopup)
    {
        return suic::ElementPtr();
    }
    else
    {
        return _submenuPopup->FindName(strName);
    }
}

int MenuItem::AddChild(suic::ObjectPtr child)
{
    MenuItem* pItem = dynamic_cast<MenuItem*>(child.get());

    if (pItem)
    {
        if (!_submenuPopup)
        {
            MenuPtr subMenu(new Menu());

            subMenu->SetStyle(FindResource(_T("Menu")));
            subMenu->SetOrientation(GetOrientation());

            _submenuPopup = new suic::UIPopup();
            _submenuPopup->SetPopupRoot(subMenu.get());
        }

        return _submenuPopup->GetPopupRoot()->AddChild(child);
    }
    else
    {
        return 0;
    }
}

suic::Size MenuItem::MeasureOverride(const suic::Size& size)
{
    suic::Size availableSize(size);

    availableSize = __super::MeasureOverride(availableSize);
    availableSize.cx += MENUITEM_ICONSIZE;

    return availableSize;
}

void MenuItem::OnInitialized()
{
    __super::OnInitialized();

    SetStyle(FindResource(GetClassName()));

    suic::ObjectPtr headerPtr = GetStyle()->GetValue(_T("Header"));

    if (headerPtr)
    {
        SetText(headerPtr->ToString());
    }
}

void MenuItem::OnStyleUpdated()
{
    if (_submenuPopup)
    {
        _submenuPopup->UpdateStyle();
    }
}

void MenuItem::OnRender(suic::DrawingContext * drawing)
{
    suic::Rect rect(0, 0, RenderSize.cx, RenderSize.cy);
    suic::StylePtr sty(GetStyle());
    suic::TriggerPtr trg;

    if (IsEnabled() && (IsSelected() || IsMouseOver() || IsSubmenuOpen()))
    {
        trg = sty->GetTrigger(suic::FOCUSED);
    }
    else
    {
        trg = sty->GetTrigger(!IsEnabled() ? suic::DISABLED : _T(""));
    }

    if (!trg)
    {
        trg = sty->GetTrigger(_T(""));
    }

    if (trg)
    {
        suic::Render::DrawBackground(drawing, trg, &rect);
        rect.left += MENUITEM_ICONSIZE;
        suic::Render::DrawText(drawing, this, GetText(), trg, &rect, true);
    }
}

void MenuItem::OnTextInput(suic::KeyEventArg& e)
{
}

void MenuItem::OnKeyDown(suic::KeyEventArg& e)
{
}

void MenuItem::OnGotFocus(suic::FocusEventArg& e)
{
}

void MenuItem::OnLostFocus(suic::FocusEventArg& e)
{
}

void MenuItem::OnSetCursor(suic::CursorEventArg& e)
{
}

void MenuItem::OnMouseEnter(suic::MouseEventArg& e)
{
    __super::OnMouseEnter(e);

    if (!IsEnabled())
    {
        return;
    }

    Selector::SelectItem(this, true);

    bool bOpenSubmenu = false;
    Menu* pMenu = dynamic_cast<Menu*>(GetParent());

    for (int i = 0; i < pMenu->GetVisualChildrenCount(); ++i)
    {
        MenuItem* pMenuItem = dynamic_cast<MenuItem*>(pMenu->GetVisualChild(i));

        if (pMenuItem->IsSubmenuOpen())
        {
            if (pMenuItem == this)
            {
                return;
            }

            suic::MouseEventArg e(this, e.MousePoint());

            pMenuItem->OnMouseLeave(e);
            pMenuItem->_submenuPopup->Close();
            bOpenSubmenu = true;

            break;
        }
    }

    //
    // ������Ӳ˵����򵯳�
    //
    if (!IsSubmenu())
    {
        ;
    }
    else if (GetTrackMenu())
    {
        MenuPtr menu = MenuPtr::cast(_submenuPopup->GetPopupRoot());
        suic::Size availableSize;

        menu->Measure(availableSize);

        int cx = menu->GetDesiredSize().cx;
        int cy = menu->GetDesiredSize().cy;

        _submenuPopup->SetWidth(cx);
        _submenuPopup->SetHeight(cy);

        if (!GetTrackMenu()->IsClosed())
        {
            suic::Point pt = suic::SystemHelper::CalcScreenElementPoint(this, CoreFlags::eRightTop);

            pt.x -= menu->GetBorderThickness().right;

            _submenuPopup->WriteFlag(CoreFlags::IsLayeredWindow, true);
            AddMenuItemIntoPopup(this, _submenuPopup);
            _submenuPopup->SetPopupPos(true, pt.x, pt.y, true, cx, cy);
        }
        else
        {
            suic::Point pt = suic::SystemHelper::CalcScreenElementPoint(this, CoreFlags::eLeftBottom);
            SetPopupMenu(this, pt.x, pt.y, _submenuPopup);
        }
    }
}

void MenuItem::OnMouseMove(suic::MouseEventArg& e)
{
    __super::OnMouseMove(e);
}

void MenuItem::OnMouseLeave(suic::MouseEventArg& e)
{
    suic::Rect rect = suic::VisualHelper::GetRenderRect(this);

    if (!rect.PointIn(e.MousePoint()))
    {
        Selector::SelectItem(this, false);

        MenuItemPtr overItem = MenuItemPtr::cast(e.GetOriginalSource());

        //
        // ������Ӳ˵�����������ͬһ���˵�Ԫ���ڣ���ر�
        //
        if (IsSubmenuOpen() && overItem
            && overItem->GetParent() == GetParent())
        {
            _submenuPopup->Close();
        }

        InvalidateVisual();
    }

    __super::OnMouseLeave(e);
    e.Handled(true);
}

void MenuItem::OnMouseLeftButtonDown(suic::MouseEventArg& e)
{
    suic::Element::OnMouseLeftButtonDown(e);

    if (!e.Handled())
    {
        Selector::SelectItem(this, true);

        InvalidateVisual();

        MenuPtr pMenu(GetParent());

        if (pMenu)
        {
            pMenu->OnItemLeftButtonDown(this, e);
        }
    }
}

void MenuItem::OnMouseLeftButtonDbclk(suic::MouseEventArg& e)
{
    __super::OnMouseLeftButtonDown(e);
}

void MenuItem::OnMouseLeftButtonUp(suic::MouseEventArg& e)
{
    __super::OnMouseLeftButtonUp(e);

    if (GetTrackMenu())
    {
        GetTrackMenu()->ReleaseCaptureMouse();
    }
}

};
