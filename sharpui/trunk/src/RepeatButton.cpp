// ======================================================================
//
// Copyright (c) 2008-2012 ����, Inc. All rights reserved.
//
// Sharpui��Դ����ѭCPLЭ����п�Դ���κθ��˻������ڴ�Э���Ͽ�������ʹ�á�
//
// ======================================================================

//////////////////////////////////////////////////////////////////////////////
// RepeatButton.cpp

#include <sui/RepeatButton.h>

namespace ui
{

RepeatButton::RepeatButton()
{
    int iTime = (int)::GetDoubleClickTime();

    _iDelay = iTime + iTime / 3;
    _iInterval = iTime / 6;
}

RepeatButton::~RepeatButton()
{
}

void RepeatButton::OnInitialized()
{
    // 
    // ���û�������¼��ַ�����
    //
    Element::OnInitialized();
}

void RepeatButton::OnUnloaded(suic::LoadedEventArg& e)
{
    __super::OnUnloaded(e);

    suic::SystemHelper::KillTimer(_iTimer300);
    suic::SystemHelper::KillTimer(_iTimer301);
}

void RepeatButton::OnRender(suic::DrawingContext * drawing)
{
    // 
    // ֱ�ӵ��û�����л���
    //
    Button::OnRender(drawing);
}

void RepeatButton::OnMouseLeftButtonDown(suic::MouseEventArg& e)
{
    suic::SystemHelper::KillTimer(_iTimer301);
    suic::SystemHelper::SetTimer(_iTimer300, this, _iDelay);

    __super::OnMouseLeftButtonDown(e);
}

void RepeatButton::OnMouseLeftButtonUp(suic::MouseEventArg& e)
{
    suic::SystemHelper::KillTimer(_iTimer301);

    __super::OnMouseLeftButtonUp(e);
}

void RepeatButton::OnMouseEnter(suic::MouseEventArg& e)
{
    if (IsMouseDown())
    {
        suic::SystemHelper::KillTimer(_iTimer301);
        suic::SystemHelper::SetTimer(_iTimer301, this, _iInterval);
    }

    __super::OnMouseEnter(e);
}

void RepeatButton::OnMouseLeave(suic::MouseEventArg& e)
{
    suic::SystemHelper::KillTimer(_iTimer301);

    __super::OnMouseLeave(e);
}

void RepeatButton::OnClick(suic::RoutedEventArg& e)
{
    // 
    // ������ʱ��������OnClick�¼�
    //
    __super::OnClick(e);
}

void RepeatButton::OnTimer(int id)
{
    if (_iTimer300 && id == _iTimer300->id)
    {
        suic::SystemHelper::KillTimer(_iTimer300);

        if (IsMouseDown())
        {
            suic::SystemHelper::SetTimer(_iTimer301, this, _iInterval);
        }
    }

    if (IsMouseDown())
    {
        suic::Point pt = suic::SystemHelper::CalcuCusorPoint(this);

        pt = PointFromScreen(pt);

        OnRepeated(VisualDescendantBounds().PointIn(pt));
    }
}

void RepeatButton::OnRepeated(bool bMouseIn)
{
    if (bMouseIn && MouseLButtonDown)
    {
        suic::Point pt;
        suic::MouseEventArg e(this, pt);

        MouseLButtonDown(this, e);
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////
//

void RepeatButton::SetDelay(int iDelay)
{
    _iDelay = iDelay;
}

void RepeatButton::SetInterval(int iInterval)
{
    _iInterval = iInterval;
}

}

