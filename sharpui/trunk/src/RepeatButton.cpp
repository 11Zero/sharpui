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
    : m_iTimer300(0)
    , m_iTimer301(0)
{
    int iTime = (int)::GetDoubleClickTime();

    m_iDelay = iTime + iTime / 3;
    m_iInterval = iTime / 6;
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

    suic::SystemHelper::KillTimer(m_iTimer300);
    suic::SystemHelper::KillTimer(m_iTimer301);
    m_iTimer300 = 0;
    m_iTimer301 = 0;
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
    suic::SystemHelper::KillTimer(m_iTimer301);
    m_iTimer300 = suic::SystemHelper::SetTimer(this, m_iDelay);

    __super::OnMouseLeftButtonDown(e);
}

void RepeatButton::OnMouseLeftButtonUp(suic::MouseEventArg& e)
{
    suic::SystemHelper::KillTimer(m_iTimer301);
    m_iTimer301 = 0;

    __super::OnMouseLeftButtonUp(e);
}

void RepeatButton::OnMouseEnter(suic::MouseEventArg& e)
{
    if (IsMouseDown())
    {
        suic::SystemHelper::KillTimer(m_iTimer301);
        m_iTimer301 = suic::SystemHelper::SetTimer(this, m_iInterval);
    }

    __super::OnMouseEnter(e);
}

void RepeatButton::OnMouseLeave(suic::MouseEventArg& e)
{
    suic::SystemHelper::KillTimer(m_iTimer301);
    m_iTimer301 = 0;

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
    if (id == m_iTimer300)
    {
        suic::SystemHelper::KillTimer(m_iTimer300);
        m_iTimer300 = 0;

        if (IsMouseDown())
        {
            m_iTimer301 = suic::SystemHelper::SetTimer(this, m_iInterval);
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
    m_iDelay = iDelay;
}

void RepeatButton::SetInterval(int iInterval)
{
    m_iInterval = iInterval;
}

}

