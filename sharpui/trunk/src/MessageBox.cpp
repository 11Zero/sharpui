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
#include <sui/ImageBox.h>

namespace ui
{

//////////////////////////////////////////////////////////////////////////////
// MsgBox

MsgBox::MsgBox()
{
    SetClassName(_T("MessageBox"));

    _dialogResult = -1;
}

MsgBox::~MsgBox()
{
}

suic::WindowPtr MsgBox::GetMessageWindow()
{
    static suic::String TEMP;
    
    if (TEMP.Empty())
    {
        TEMP = _T("<MessageBox Opacity=\"1\" ResizeBox=\"False\" Author=\"����(QQ:386666951)\" Height=\"100\" Width=\"180\" MinHeight=\"100\" MinWidth=\"180\" ");

        TEMP += ">";

        TEMP += "<StackLayout Name=\"cnt\" VerticalAlignment=\"Stretch\" HorizontalAlignment=\"Stretch\" Orientation=\"Vertical\" >";

        //title------------------------------
        TEMP += "<StackLayout Background=\"{x:Null}\" HorizontalAlignment=\"Stretch\" Height=\"26\" >";
        TEMP += "<TextBlock Name=\"title\" Padding=\"4,2,2,2\" HorizontalAlignment=\"Stretch\" />";
        TEMP += "<SystemCloseButton Name=\"close\" IsEnabled=\"False\" />";
        TEMP += "</StackLayout>";
        //title------------------------------

        TEMP += "<StackLayout Name=\"msglay\" VerticalAlignment=\"Stretch\" HorizontalAlignment=\"Stretch\" MinHeight=\"42\" >";
        
        TEMP += "<ImageBox Name=\"icon\" Source=\"images/question.png\" VerticalAlignment=\"Top\" HorizontalAlignment=\"Left\" Margin=\"8\" >";
        TEMP += "</ImageBox>";

        TEMP += "</StackLayout>";

        //�ײ�------------------------------
        TEMP += "<Panel Background=\"{x:Null}\" HorizontalAlignment=\"Stretch\" Height=\"32\" >";
        TEMP += "<StackPanel Name=\"btns\" VerticalAlignment=\"Stretch\" HorizontalAlignment=\"Right\" Margin=\"2,4,15,4\" >";        
        TEMP += "<Button Name=\"yes\" Padding=\"16,5,16,5\" VerticalAlignment=\"Center\" Content=\"��(Y)\" />";
        TEMP += "<Button Name=\"no\" Margin=\"16,0,0,0\" Padding=\"16,5,16,5\" VerticalAlignment=\"Center\" Content=\"��(N)\" />";
        TEMP += "</StackPanel>";
        TEMP += "</Panel>";
        //�ײ�------------------------------

        TEMP += "</StackLayout>";

        TEMP += "</MessageBox>";
    }

    suic::WindowPtr box(CoreApp::LoadComponent(new MsgBox(), TEMP.utf8_str()));

    return box;
}

int MsgBox::Show(suic::WindowPtr owner, const suic::String& title, const suic::String& msg)
{
    return MsgBox::Show(owner, title, msg, OK);
}

int MsgBox::Show(const suic::String& title, const suic::String& msg)
{
    return MsgBox::Show(CoreApp::Current()->GetMainWindow(), title, msg, OK);
}

int MsgBox::Show(suic::WindowPtr owner, const suic::String& title, const suic::String& msg, int flag)
{
    suic::WindowPtr box(GetMessageWindow());
    suic::Size size;
    ui::StackLayoutPtr cnt(box->FindName(_T("cnt")));
    ui::TextBlockPtr tiPtr(box->FindName(_T("title")));
    ui::StackLayoutPtr msgLayPtr(box->FindName(_T("msglay")));
    ui::TextBlockPtr msgPtr(new ui::TextBlock(msg));

    msgPtr->SetPadding(suic::Rect(6,6,0,0));
    msgPtr->SetHorizontalAlignment(suic::STRETCH);
    msgPtr->SetVerticalAlignment(suic::STRETCH);

    if (YESNO == flag)
    {
    }
    else
    {
        ui::ButtonPtr yesPtr(box->FindName(_T("yes")));
        ui::ButtonPtr noPtr(box->FindName(_T("no")));

        ui::ImageBoxPtr imPtr(box->FindName(_T("icon")));

        imPtr->SetSource(_T("images/icon.png"));

        yesPtr->SetName(_T("ok"));
        noPtr->SetVisible(false);
    }

    msgLayPtr->AddChild(msgPtr);
    tiPtr->SetText(title);

    box->UpdateLayout();

    box->SetWidth(cnt->GetDesiredSize().cx);
    box->SetHeight(cnt->GetDesiredSize().cy);

    if (owner)
    {
        box->SetOwner(CoreApp::Current()->GetMainWindow());
    }
    else
    {
        box->SetOwner(owner);
    }

    box->ShowDialog();

    return box->GetDialogResult();
}

int MsgBox::Show(const suic::String& title, const suic::String& msg, int flag)
{
    return MsgBox::Show(CoreApp::Current()->GetMainWindow(), title, msg, flag);
}

int MsgBox::Show(const suic::String& title, const suic::Object* msg)
{
    return OK;
}

int MsgBox::Show(suic::WindowPtr owner, const suic::String& title, const suic::Object* msg, int flag)
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
    suic::Size ret = __super::ArrangeOverride(size);

    return size;
}

void MsgBox::OnInitialized()
{
    __super::OnInitialized();

    if (!FindResource(_T("MessageBox")))
    {
        SetStyle(FindResource(suic::WINDOW));
        SetValue(_T("Author"), new suic::UString("����(QQ:386666951)"));
    }
}

void MsgBox::OnLoaded(suic::LoadedEventArg& e)
{
    __super::OnLoaded(e);

    ui::ButtonPtr pBtn(FindName(_T("ok")));

    if (pBtn)
    {
        pBtn->Click += ui::ClickEventHandler(this, &MsgBox::OnButtonDown);
    }

    pBtn = FindName(_T("yes"));

    if (pBtn)
    {
        pBtn->Click += ui::ClickEventHandler(this, &MsgBox::OnButtonDown);
    }

    pBtn = FindName(_T("no"));

    if (pBtn)
    {
        pBtn->Click += ui::ClickEventHandler(this, &MsgBox::OnButtonDown);
    }
}

void MsgBox::OnRender(suic::DrawingContext * drawing)
{
    suic::Window::OnRender(drawing);
}

void MsgBox::OnButtonDown(suic::ElementPtr sender)
{
    if (sender->GetName().Equals(_T("ok")))
    {
        _dialogResult = UIOK;
    }
    else if (sender->GetName().Equals(_T("yes")))
    {
        _dialogResult = UIYES;
    }
    else if (sender->GetName().Equals(_T("no")))
    {
        _dialogResult = UINO;
    }

    Close();
}

}
