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
    suic::String strRes = _T("iskin/resource.sres");
    suic::String strApp = _T("res/application.xml");

    // ����������
    suic::String strCmd(lpCmdLine);
    suic::VectorString vecStr;

    suic::Split(vecStr, strCmd, _T(" "));

    for (int i = 0; i < (int)vecStr.size(); ++i)
    {
        suic::VectorString vecTmp;

        suic::Split(vecTmp, vecStr[i], _T("="));

        if (vecTmp.size() == 2)
        {
            if (vecTmp[0].Equals(_T("Res")))
            {
                strRes = vecTmp[1];
            }
            else if (vecTmp[0].Equals(_T("App")))
            {
                strApp = vecTmp[1];
            }
        }
    }

    // ��ʼ����ð�����Դ��ע��ϵͳ��
    // �˷����������
    CoreInitialize(strRes);

    // ������Դ�������࣬����Ϊ�Զ���Ԫ�ش����ص�����
    // ����ͨ���˶���������������Ҫ����
    suic::Builder build;

    AsciiStr resStr(strApp.c_str());

    // ��ȡApplication��Դ
    // ������ΪMainFrame���󣬶�ȡ�ɹ���Application::Current()
    // �ᱻ�Զ���ֵ
    build.Build(new MainFrame(), resStr);

    suic::ApplicationPtr pApp = suic::Application::Current();

    pApp->LoadCompleted += OnApplicationLoadCompleted;

    if (suic::Application::Current())
    {
        // ִ����Ϣѭ��
        pApp->Run();

        // ϵͳ�˳���������Դ
        pApp = suic::ApplicationPtr();
    }

	return 0;
}

