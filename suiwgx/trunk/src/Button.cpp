// ======================================================================
//
// Copyright (c) 2008-2012 ����, Inc. All rights reserved.
//
// Sharpui��Դ����ѭCPLЭ����п�Դ���κθ��˻������ڴ�Э���Ͽ�������ʹ�á�
//
// ======================================================================

//////////////////////////////////////////////////////////////////////////////
// Button.cpp

#include <sui/Button.h>
#include <suic/render/uirender.h>
#include <suic/tools/hwndhelper.h>

namespace ui
{

//////////////////////////////////////////////////////////////////////////////
// ButtonBase

ImplementTypeofInfo(ButtonBase, suic::ContentControl)

ButtonBase::ButtonBase()
{
    SetMinHeight(4);
    SetMinWidth(4);

    // ֧����괫�ݻ���
    WriteFlag(CoreFlags::IsSupportMouseOver, true);
    SetFocusable(true);
}

ButtonBase::~ButtonBase()
{
}

suic::Size ButtonBase::MeasureOverride(const suic::Size& size)
{
    suic::Size ret = __super::MeasureOverride(size);

    if (ret.cx <= 0 || ret.cy <= 0)
    {
        //
        // ���㱳��ͼ������������С
        //
        return suic::Render::MeasureImageSize(GetBackground());
    }

    return ret;
}

void ButtonBase::OnRender(suic::DrawingContext * drawing)
{
    suic::Control::OnRender(drawing);
}

void ButtonBase::OnMouseMove(suic::MouseEventArg& e)
{
    e.SetHandled(true);
    __super::OnMouseMove(e);
}

void ButtonBase::OnMouseLeftButtonDown(suic::MouseEventArg& e)
{
    e.SetHandled(true);
    SetCaptureMouse();
    __super::OnMouseLeftButtonDown(e);
}

void ButtonBase::OnMouseLeftButtonUp(suic::MouseEventArg& e)
{
    e.SetHandled(true);
    ReleaseCaptureMouse();

    //
    // ֻ�����λ��Ԫ���ϲų���Click�¼�
    //
    if (IsMouseOver())
    {
        suic::RoutedEventArg re(e.GetOriginalSource());

        OnClick(re);
    }

    __super::OnMouseLeftButtonUp(e);
}

void ButtonBase::OnMouseLeftButtonDbclk(suic::MouseEventArg& e)
{
    OnMouseLeftButtonDown(e);
}

void ButtonBase::OnClick(suic::RoutedEventArg& e)
{
    if (NULL != Click)
    {
        Click(this);
    }
}

//////////////////////////////////////////////////////////////////////////////
// Button

ImplementTypeofInfo(Button, ButtonBase)

Button::Button()
    : nOffset(0)
{
    SetClassName(_T("Button"));
}

Button::~Button()
{
}

void Button::OnInitialized()
{
    // ���û���
    ButtonBase::OnInitialized();
}

void Button::OnRender(suic::DrawingContext * drawing)
{
    ButtonBase::OnRender(drawing);
}

void Button::OnMouseLeftButtonDown(suic::MouseEventArg& e)
{
    __super::OnMouseLeftButtonDown(e);
    SetFocus();
}

void Button::OnKeyDown(suic::KeyboardEventArg& e)
{
    //
    // ѹ�¼��̿ո��򴥷�OnClick
    //
    if (e.IsSpacePress())
    {
        if (IsFocused())
        {
            suic::RoutedEventArg re(this);

            OnClick(re);
        }
    }

    e.SetHandled(true);
}

ImplementTypeofInfo(SystemMinButton, Button)
ImplementTypeofInfo(SystemMaxButton, Button)
ImplementTypeofInfo(SystemCloseButton, Button)

//-------------------------------------------
SystemMinButton::SystemMinButton()
{
    SetClassName(_T("SystemMinButton"));
    SetToolTip(new suic::OString(_T("��С��")));
    SetFocusable(false);
}

SystemMinButton::~SystemMinButton()
{
    ;
}

void SystemMinButton::OnClick(suic::RoutedEventArg& e)
{
    suic::HwndHelper::MinimizeWindow(this);
}

//-------------------------------------------
SystemMaxButton::SystemMaxButton()
{
    SetClassName(_T("SystemMaxButton"));
    SetFocusable(false);
}

SystemMaxButton::~SystemMaxButton()
{
    ;
}

void SystemMaxButton::OnLoaded(suic::LoadedEventArg& e)
{
    __super::OnLoaded(e);
}

void SystemMaxButton::OnClick(suic::RoutedEventArg& e)
{
    if (suic::HwndHelper::IsWindowMaximize(this))
    {
        SetToolTip(new suic::OString(_T("���")));
        suic::HwndHelper::RestoreWindow(this);
    }
    else
    {
        SetToolTip(new suic::OString(_T("���»�ԭ")));
        suic::HwndHelper::MaximizeWindow(this);
    }
}

suic::Size SystemMaxButton::MeasureOverride(const suic::Size& size)
{
    suic::Size ret;
    suic::ImageBrushPtr bkgnd;

    if (GetStyle()->Setters())
    {
        bkgnd = GetStyle()->Setters()->GetValue(_T("Restore"));
    }
    
    if (!bkgnd)
    {
        bkgnd = GetSetters()->GetValue(_T("Restore"));
    }

    if (bkgnd)
    {
        suic::Rect rectBk;

        rectBk = bkgnd->GetContentBrounds();       
        ret.cx += rectBk.Width() + 4;
        ret.cy += rectBk.Height();
    }

    return ret;
}

void SystemMaxButton::OnRender(suic::DrawingContext * drawing)
{
    suic::String strName;

    if (suic::HwndHelper::IsWindowMaximize(this))
    {
        strName = _T("Restore");
        SetToolTip(new suic::OString(_T("���»�ԭ")));
    }
    else
    {
        strName = _T("Max");
        SetToolTip(new suic::OString(_T("���")));
    }

    suic::Rect drawrect(0, 0, RenderSize().cx, RenderSize().cy);
    suic::BrushPtr bkgnd(suic::Render::GetProperty(this, GetStyle().get(), strName));

    if (bkgnd)
    {
        bkgnd->Draw(drawing, &drawrect);
    }
}

//-------------------------------------------
SystemCloseButton::SystemCloseButton()
{
    SetClassName(_T("SystemCloseButton"));
    SetToolTip(new suic::OString(_T("�ر�")));
    SetFocusable(false);
}

SystemCloseButton::~SystemCloseButton()
{
    ;
}

void SystemCloseButton::OnClick(suic::RoutedEventArg& e)
{
    suic::HwndHelper::CloseWindow(this);
}

};
