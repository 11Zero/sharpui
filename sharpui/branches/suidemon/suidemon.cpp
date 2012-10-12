// suicoredemon.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <suicore/uistring.h>
#include <sui/sharpuicore.h>
#include "Application.h"
#include "MainFrame.h"

suic::ApplicationPtr g_appPtr;

void OnApplicationLoadCompleted(suic::ApplicationPtr appPtr, const suic::EventArg&)
{
    suic::WindowPtr winPtr(appPtr->GetMainWindow());        
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/
                     , LPSTR lpCmdLine, int nCmdShow)
{
    // ��ʼ����ð�����Դ��ע��ϵͳ��
    // �˷����������
    CoreInitialize(_T("iskin/uidesign.sres"));

    // ������Դ�������࣬����Ϊ�Զ���Ԫ�ش����ص�����
    // ����ͨ���˶���������������Ҫ����
    suic::Builder build;

    // ��ȡApplication��Դ
    // ������ΪMainFrame���󣬶�ȡ�ɹ���Application::Current()
    // �ᱻ�Զ���ֵ
    build.Build(new MainFrame(), _T("res/uidemon.xml"));

    suic::ApplicationPtr pApp = suic::Application::Current();

    if (suic::Application::Current())
    {
        // ִ����Ϣѭ��
        pApp->Run();

        // ϵͳ�˳���������Դ
        pApp = suic::ApplicationPtr();
    }

	return 0;
}

