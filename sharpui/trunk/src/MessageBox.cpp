// ======================================================================
//
// Copyright (c) 2008-2012 ����, Inc. All rights reserved.
//
// Sharpui��Դ����ѭCPLЭ����п�Դ���κθ��˻������ڴ�Э���Ͽ�������ʹ�á�
//
// ======================================================================

//////////////////////////////////////////////////////////////////////////////
// MsgBox.cpp

#include <sui/MessageBox.h>
#include <suicore/drawing/uirender.h>
#include <suicore/hwndhelper.h>
#include <suicore/uiapplication.h>

#include <sui/StackLayout.h>
#include <sui/CaptionBar.h>

namespace ui
{

//////////////////////////////////////////////////////////////////////////////
// MsgBox

MsgBox::MsgBox()
{
    SetAutoDelete(false);
}

MsgBox::~MsgBox()
{
}

int MsgBox::Show(const suic::String& title, const suic::String& msg)
{
    suic::String TEMP(_T("<Window Author=\"����(QQ:386666951)\" ></Window>"));

    suic::WindowPtr box(CoreApp::LoadComponent(NULL, suic::String(TEMP.utf8_str().c_str())));

    box->SetMinWidth(200);
    box->SetMinHeight(200);

    box->SetText(title);
    box->SetOwner(CoreCurrentApp()->GetMainWindow());
    box->ShowDialog();

    return OK;
}

int MsgBox::Show(const suic::String& title, const suic::String& msg, int flag)
{
    return OK;
}

int MsgBox::Show(const suic::String& title, const suic::Object* msg)
{
    return OK;
}

int MsgBox::Show(const suic::String& title, const suic::Object* msg, int flag)
{
    return OK;
}

suic::Size MsgBox::MeasureOverride(const suic::Size& size)
{
    suic::Size ret = __super::MeasureOverride(size);

    return ret;
}

suic::Size MsgBox::ArrangeOverride(const suic::Size& size)
{
    return size;
}

void MsgBox::OnRender(suic::DrawingContext * drawing)
{
    suic::Window::OnRender(drawing);
}

}
