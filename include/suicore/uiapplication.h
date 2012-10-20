// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����Application.h
// ��  �ܣ�Ӧ�ó������
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _UIAPPLICATION_H_
# define _UIAPPLICATION_H_

#include <suicore/uiwindow.h>
#include <suicore/style/ResourceDictionary.h>

namespace suic {

class Application;
typedef shared<Application> ApplicationPtr;

typedef delegate<void(ApplicationPtr, const EventArg&)> LoadCompletedEventHandler;
typedef delegate<void(ApplicationPtr, const EventArg&)> StartupEventHandler;
typedef delegate<void(ApplicationPtr, const EventArg&)> ExitEventHandler;

class SUICORE_API Application : public RefObject
{
public:

    LoadCompletedEventHandler LoadCompleted;
    StartupEventHandler Startup;
    ExitEventHandler Exit;
    EventHandler Activated;
    EventHandler Deactivated;

    Application();
    virtual ~Application();

    void Run(WindowPtr element);
    void Run();

    static ApplicationPtr Current();
    
    String GetStartupUri() const;
    void SetStartupUri(const String& uri);

    // Windows();
    WindowPtr GetMainWindow() const;
    void SetMainWindow(WindowPtr mainWnd);

    ResourceDictionaryPtr GetResources() const;
    void SetResources(ResourceDictionary* resources);
    void SetResources(String strRes);

    ObjectPtr FindResource(const String& name);

    static ObjectPtr LoadComponent(ObjectPtr parent, const String& resLocater);

protected:

    String _startupUri;
    WindowPtr _mainWindow;
   
    ResourceDictionaryPtr _resources;
};

inline ResourceDictionaryPtr Application::GetResources() const
{
    return _resources;
}

#define CoreApp suic::Application

}

# endif
