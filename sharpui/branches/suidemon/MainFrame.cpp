/////////////////////////////////////////////////////
// MainFrame.cpp

#include "stdafx.h"

#include "MainFrame.h"
#include <animation/DoubleAnimation.h>
#include <animation/StoryBoard.h>

MainFrame::MainFrame()
{ 
    _bDefault = true;
}

MainFrame::~MainFrame()
{
}

void MainFrame::OnInitialized()
{
    __super::OnInitialized();

    ui::ButtonPtr pBtn = ui::ButtonPtr::cast(FindName(_T("TestAni")));

    if (pBtn)
    {
        // ע�ᰴť�ĵ���¼�
        pBtn->Click += ui::ClickEventHandler(this, &MainFrame::OnTestAni);
    }

    pBtn = ui::ButtonPtr::cast(FindName(_T("TestWndAni")));

    if (pBtn)
    {
        pBtn->Click += ui::ClickEventHandler(this, &MainFrame::OnTestWndAni);
    }

    pBtn = ui::ButtonPtr::cast(FindName(_T("SkinBtn")));

    if (pBtn)
    {
        pBtn->Click += ui::ClickEventHandler(this, &MainFrame::OnChangeSkin);
    }
    
    ui::SliderPtr pSld = FindName(_T("sld"));

    if (pSld)
    {
        pSld->ValueChanged += ui::ValueChangedEventHandler(this, &MainFrame::OnValueChanged);
    }

    ui::TreeViewPtr treePtr(FindName(_T("Tree01")));

    if (treePtr)
    {
        treePtr->ItemSelected += ui::SelectTreeItemHandler(this, &MainFrame::OnTreeItemSelect);
    }

    // TabItemѡ���¼�
    ui::TabControlPtr tab(FindName(_T("TestTab")));

    if (tab)
    {
        tab->ItemSelected += ui::ItemSelectedHandler(this, &MainFrame::SelectTabItem);
    }

    pBtn = ui::ButtonPtr::cast(FindName(_T("SwitchLayered")));

    if (pBtn)
    {
        pBtn->Click += ui::ClickEventHandler(this, &MainFrame::OnSwitchLayered);
    }

    // ������ֹͣ����
    pBtn = ui::ButtonPtr::cast(FindName(_T("StartAni")));

    if (pBtn)
    {
        pBtn->Click += ui::ClickEventHandler(this, &MainFrame::OnStartAni);
    }

    pBtn = ui::ButtonPtr::cast(FindName(_T("StopAni")));

    if (pBtn)
    {
        pBtn->Click += ui::ClickEventHandler(this, &MainFrame::OnStopAni);
    }
    
    ui::ListViewPtr listPtr(FindName(_T("ListView01")));

    if (listPtr)
    {
        listPtr->Columns()->Add(_T("����"), 100);
        listPtr->Columns()->Add(_T("�ݳ���"), 80);

        int index = listPtr->Add(new ui::ListViewItem());
        ui::ListViewItemPtr item(listPtr->GetItem(index));

        item->AddColumn(_T("����Ӣ��"));
        item->AddColumn(_T("�ܻ���"));
    }
}

void MainFrame::SelectTabItem(suic::Element* sender)
{
    ui::TabItemPtr tab(sender);
    suic::FrameworkElementPtr cont(tab->GetTabContent());

    if (cont)
    {
        suic::StoryBoardPtr pSb = new suic::StoryBoard();
        suic::Animation* pAni = new ui::DoubleAnimation(suic::OPACITY, 0, 1);

        // ����ΪTrue����������ͷ����ִ��һ��
        //pAni->SetAutoReverse(true);
        pAni->SetSpeedRatio(60);
        pAni->SetDuration(0.5);
        pSb->Add(pAni);
        pSb->Start(cont.get());
    }
}

void MainFrame::OnValueChanged(suic::Element* sender, double o, double n)
{
    ui::ProgressBarPtr pb = FindName(_T("pb"));

    if (pb)
    {
        pb->SetValue(n);
    }
}

void MainFrame::OnTreeItemSelect(ui::TreeViewItem* pItem)
{
    suic::String text = pItem->GetText();

    ui::MsgBox::Show(_T("Info"), text);
}

void MainFrame::OnTestAni(suic::ElementPtr pElem)
{
    suic::FrameworkElementPtr frame(pElem.get());

    suic::ResourceDictionaryPtr resPtr(suic::Application::LoadComponent(NULL, _T("������/resource1.xml")));

    if (resPtr)
    {
        suic::ApplicationPtr pApp(suic::Application::Current());

        pApp->SetResources(resPtr);
    }

    suic::StoryBoard::StopAnimation(frame.get());

    suic::StoryBoardPtr pSb = new suic::StoryBoard();
    suic::AnimationPtr widPtr(new ui::DoubleAnimation(suic::WIDTH, 20, frame->GetWidth(), true));
    
    widPtr->SetDuration(0.4);

    pSb->Add(widPtr.get());
    pSb->Add(new ui::DoubleAnimation(suic::OPACITY, 0, 1));
    pSb->Start(frame.get());
}

void MainFrame::OnChangeSkin(suic::ElementPtr pElem)
{
    // �����л�ϵͳ��Դ�����ж�̬����
    if (_bDefault)
    {
        CoreApp::Current()->SetResources(_T("res/black_res.xml"));
    }
    else
    {
        CoreApp::Current()->SetResources(_T("res/default.xml"));
    }

    _bDefault = !_bDefault;
}

void MainFrame::OnSwitchLayered(suic::ElementPtr pElem)
{
    bool bLayered = ReadFlag(CoreFlags::IsLayeredWindow);

    if (bLayered)
    {
        SetValue(suic::ISLAYEREDWINDOW, new suic::UString(_T("False")));
        SetText(_T("Sharpui����������ʾ(��ͨ)"));

        suic::ImageBrushPtr bk(GetValue(_T("Background")));

        if (bk)
        {
            bk->SetOpacity(1.0);
        }
    }
    else
    {
        SetValue(suic::ISLAYEREDWINDOW, new suic::UString(_T("True")));

        suic::ImageBrushPtr bk(GetValue(_T("Background")));

        if (bk)
        {
            bk->SetOpacity(0.8);
        }
        //SetOpacity(0.8);
        SetText(_T("Sharpui����������ʾ(�ֲ�)"));
    }

    InvalidateVisual();
}

void MainFrame::OnStartAni(suic::ElementPtr pElem)
{
    ui::AnimateBoxPtr aniPtr(FindName(_T("ani")));

    if (aniPtr)
    {
        aniPtr->Start();
    }
}

void MainFrame::OnStopAni(suic::ElementPtr pElem)
{
    ui::AnimateBoxPtr aniPtr(FindName(_T("ani")));

    if (aniPtr)
    {
        aniPtr->Stop();
    }
}

void MainFrame::OnTestWndAni(suic::ElementPtr pElem)
{
    suic::StoryBoardPtr pSb = new suic::StoryBoard();
    suic::Animation* pAni = new ui::DoubleAnimation(suic::OPACITY, 1, 0);
    
    // �������ڿ�ʼ����NameΪMainContainer��Ԫ��
    // �������г����ڽ����ϵ�Ԫ�ض�����������FrameworkElement
    suic::FrameworkElementPtr pSln = FindName(_T("MainContainer"));

    // ����ΪTrue����������ͷ����ִ��һ��
    pAni->SetAutoReverse(true);
    pAni->SetSpeedRatio(60);
    pAni->SetDuration(0.5);
    pSb->Add(pAni);
    pSb->Start(pSln.get());

    // �����л�ϵͳ��Դ�����ж�̬����
    suic::ResourceDictionaryPtr resPtr(CoreApp::LoadComponent(NULL, _T("������/resource.xml")));

    if (resPtr)
    {
        suic::ApplicationPtr pApp(CoreApp::Current());

        pApp->SetResources(resPtr);
    }
}

void MainFrame::OnLoaded(suic::LoadedEventArg& e)
{
    __super::OnLoaded(e);

    // ���ھ�����ʾ
    CenterWindow();

    // ���ô���֧�ֲ���ʽ���������ſ��Զ������͸���ȶ���
    SetValue(suic::ISLAYEREDWINDOW, new suic::UString(_T("True")));

    // ����������ʾ��
    suic::StoryBoardPtr pSb = new suic::StoryBoard();
    // ����һ��Double���䶯��
    suic::Animation* pAni = new ui::DoubleAnimation(suic::OPACITY, 0, 1);

    // ��������Ϊ60����
    pAni->SetSpeedRatio(60);
    // ����ִ��ʱ���Ϊ2��
    pAni->SetDuration(2);
    // �Ѷ����ӵ�������ʾ��
    pSb->Add(pAni);

    // �������������뵽��ʾ���ÿ��������������
    // һ�������Ķ�ʱ��
    pSb->Start(this);
}