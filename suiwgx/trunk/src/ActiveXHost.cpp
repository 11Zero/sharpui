// ======================================================================
//
// Copyright (c) 2008-2012 ����, Inc. All rights reserved.
//
// Sharpui��Դ����ѭCPLЭ����п�Դ���κθ��˻������ڴ�Э���Ͽ�������ʹ�á�
//
// ======================================================================

//////////////////////////////////////////////////////////////////////////////
// ActiveXHost.cpp

#include <sui/ActiveXHost.h>

namespace ui
{

ImplementTypeofInfo(ActiveXHost, suic::HwndHost)

ActiveXHost::ActiveXHost()
{
    SetClassName(_T("ActiveXHost"));
}

ActiveXHost::~ActiveXHost()
{
}

bool ActiveXHost::DoVerb(int verb)
{ 
    /*int hr = _axOleObject.DoVerb(verb,
        IntPtr.Zero,
        this.ActiveXSite,
        0, 
        this.ParentHandle.Handle,
        _bounds); 

    return hr == S_OK;*/ 

    return false;
}

/////////////////////////////////////////////////////////////////
//
void ActiveXHost::OnInitialized()
{
    __super::OnInitialized();
}

void ActiveXHost::OnRender(suic::DrawingContext * drawing)
{
    __super::OnRender(drawing);
}

void ActiveXHost::OnTextInput(suic::KeyboardEventArg& e)
{
}

void ActiveXHost::OnKeyDown(suic::KeyboardEventArg& e)
{
}

void ActiveXHost::OnGotFocus(suic::FocusEventArg& e)
{
}

void ActiveXHost::OnLostFocus(suic::FocusEventArg& e)
{
}

void ActiveXHost::OnSetCursor(suic::CursorEventArg& e)
{
}

void ActiveXHost::OnMouseEnter(suic::MouseEventArg& e)
{
    __super::OnMouseEnter(e);
}

void ActiveXHost::OnMouseMove(suic::MouseEventArg& e)
{
    __super::OnMouseMove(e);
}

void ActiveXHost::OnMouseLeave(suic::MouseEventArg& e)
{
    __super::OnMouseLeave(e);
}

void ActiveXHost::OnMouseLeftButtonDown(suic::MouseEventArg& e)
{
    __super::OnMouseLeftButtonDown(e);
}

void ActiveXHost::OnMouseLeftButtonDbclk(suic::MouseEventArg& e)
{
    __super::OnMouseLeftButtonDbclk(e);
}

void ActiveXHost::OnMouseLeftButtonUp(suic::MouseEventArg& e)
{
    __super::OnMouseLeftButtonUp(e);
}

}
