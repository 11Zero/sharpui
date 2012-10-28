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
#include <suicore/drawing/uirender.h>
#include <suicore/hwndhelper.h>

namespace ui
{

//////////////////////////////////////////////////////////////////////////////
// ButtonBase

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
        if (GetStyle())
        {
            suic::TriggerPtr setter(suic::Render::GetTriggerByStatus(this, GetStyle()));

            //
            // ���㱳��ͼ������������С
            //
            if (setter.get())
            {
                return suic::Render::MeasureImageSize(setter);
            }
        }
    }

    return ret;
}

void ButtonBase::OnRender(suic::DrawingContext * drawing)
{
    suic::Control::OnRender(drawing);
}

void ButtonBase::OnMouseEnter(suic::MouseEventArg& e)
{
    __super::OnMouseEnter(e);
}

void ButtonBase::OnMouseMove(suic::MouseEventArg& e)
{
    e.Handled(true);
    __super::OnMouseMove(e);
}

void ButtonBase::OnMouseLeave(suic::MouseEventArg& e)
{
    __super::OnMouseLeave(e);

    e.Handled(true);
}

void ButtonBase::OnMouseLeftButtonDown(suic::MouseEventArg& e)
{
    suic::Control::OnMouseLeftButtonDown(e);
}

void ButtonBase::OnMouseLeftButtonUp(suic::MouseEventArg& e)
{
    suic::Control::OnMouseLeftButtonUp(e);

    //
    // ֻ�����λ��Ԫ���ϲų���Click�¼�
    //
    if (IsMouseOver())
    {
        suic::RoutedEventArg re(e.GetOriginalSource());

        OnClick(re);
    }
}

void ButtonBase::OnMouseLeftButtonDbclk(suic::MouseEventArg& e)
{
    OnMouseLeftButtonDown(e);
}

void ButtonBase::OnGotFocus(suic::FocusEventArg& e)
{
    InvalidateVisual();

    __super::OnGotFocus(e);
    e.Handled(true);
}

void ButtonBase::OnLostFocus(suic::FocusEventArg& e)
{
    InvalidateVisual();
    __super::OnGotFocus(e);
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
    Control::OnRender(drawing);
}

void Button::OnKeyDown(suic::KeyEventArg& e)
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

    e.Handled(true);
}

//-------------------------------------------
SystemMinButton::SystemMinButton()
{
    SetClassName(_T("SystemMinButton"));
    SetToolTip(new suic::UString(_T("��С��")));
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
        SetToolTip(new suic::UString(_T("���")));
        suic::HwndHelper::RestoreWindow(this);
    }
    else
    {
        SetToolTip(new suic::UString(_T("���»�ԭ")));
        suic::HwndHelper::MaximizeWindow(this);
    }
}

suic::Size SystemMaxButton::MeasureOverride(const suic::Size& size)
{
    suic::Size ret;
    suic::TriggerPtr& trg = GetStyle()->GetTrigger();

    if (trg.get())
    {
        suic::ImageBrushPtr bkgnd(trg->GetValue(_T("Restore")));

        if (bkgnd)
        {
            suic::Rect rectBk;

            rectBk = bkgnd->GetContentBrounds();       
            ret.cx += rectBk.Width() + 4;
            ret.cy += rectBk.Height();
        }
    }

    return ret;
}

void SystemMaxButton::OnRender(suic::DrawingContext * drawing)
{
    suic::String strName;

    if (suic::HwndHelper::IsWindowMaximize(this))
    {
        strName = _T("Restore");
        SetToolTip(new suic::UString(_T("���»�ԭ")));
    }
    else
    {
        strName = _T("Max");
        SetToolTip(new suic::UString(_T("���")));
    }

    suic::Rect drawrect(0, 0, RenderSize().cx, RenderSize().cy);
    suic::TriggerPtr trigger(suic::Render::GetTriggerByStatus(this, GetStyle()));
    suic::BrushPtr bkgnd(trigger->GetValue(strName));

    if (bkgnd)
    {
        bkgnd->Draw(drawing, &drawrect);
    }
}

//-------------------------------------------
SystemCloseButton::SystemCloseButton()
{
    SetClassName(_T("SystemCloseButton"));
    SetToolTip(new suic::UString(_T("�ر�")));
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
