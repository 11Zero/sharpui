// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����WebBrowser.h
// ��  �ܣ�ʵ�ֱ�׼��WEB�ؼ�
// 
// ��  �ߣ�����
// ʱ  �䣺2010-08-31
// 
// ============================================================================

# ifndef _UIWEBBROWSER_H_
# define _UIWEBBROWSER_H_

#include <sui/sharpuiconfig.h>
#include <sui/ActiveXHost.h>

namespace ui
{

/// <summary>
///  WebBrowser��ʵ�ֱ�׼��WEB�ؼ���
/// </summary>
class SHARPUI_API WebBrowser : public ActiveXHost
{
public:

    WebBrowser();
    virtual ~WebBrowser();

    DeclareTypeofInfo(WebBrowser, ActiveXHost)

    bool CanGoBack() const;
    bool CanGoForward() const;

    suic::String GetSource() const;
    void SetSource(suic::String uri);

    void GoBack();
    void GoForward();

    suic::ObjectPtr InvokeScript(suic::String scriptName);

    void Navigate(const suic::String& source);
    void Refresh();

protected:

    suic::Size ArrangeOverride(const suic::Size& size);

    void OnInitialized();
    void OnLoaded(suic::LoadedEventArg& e);

    void OnVisibilityChanged(bool visible);

    void OnRender(suic::DrawingContext * drawing);

    void OnTextInput(suic::KeyboardEventArg& e);
    void OnKeyDown(suic::KeyboardEventArg& e);

    void OnGotFocus(suic::FocusEventArg& e);
    void OnLostFocus(suic::FocusEventArg& e);

    void OnSetCursor(suic::CursorEventArg& e);

    void OnMouseEnter(suic::MouseEventArg& e);
    void OnMouseMove(suic::MouseEventArg& e);
    void OnMouseLeave(suic::MouseEventArg& e);
    void OnMouseLeftButtonDown(suic::MouseEventArg& e);
    void OnMouseLeftButtonDbclk(suic::MouseEventArg& e);
    void OnMouseLeftButtonUp(suic::MouseEventArg& e);

protected:

    void* _webHost;
    suic::String _uri;
};

typedef suic::shared<WebBrowser> WebBrowserPtr;

inline suic::String WebBrowser::GetSource() const
{
    return _uri;
}

inline void WebBrowser::SetSource(suic::String uri)
{
    _uri = uri;
}

};

# endif
