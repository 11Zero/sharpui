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
#include <suicore/uicontrol.h>

namespace ui
{

// ============================================================================
// WebBrowser��ʵ�ֱ�׼��WEB�ؼ���
// ============================================================================

class SHARPUI_API WebBrowser : public suic::Control
{
public:

    WebBrowser();
    virtual ~WebBrowser();

    DECLAREBUILD(WebBrowser)

protected:

    virtual void OnInitialized();

    virtual void OnRender(suic::DrawingContext * drawing);

    virtual void OnTextInput(suic::KeyEventArg& e);
    virtual void OnKeyDown(suic::KeyEventArg& e);

    virtual void OnGotFocus(suic::FocusEventArg& e);
    virtual void OnLostFocus(suic::FocusEventArg& e);

    virtual void OnSetCursor(suic::CursorEventArg& e);

    virtual void OnMouseEnter(suic::MouseEventArg& e);
    virtual void OnMouseMove(suic::MouseEventArg& e);
    virtual void OnMouseLeave(suic::MouseEventArg& e);
    virtual void OnMouseLeftButtonDown(suic::MouseEventArg& e);
    virtual void OnMouseLeftButtonDbclk(suic::MouseEventArg& e);
    virtual void OnMouseLeftButtonUp(suic::MouseEventArg& e);

protected:
};

typedef suic::shared<WebBrowser> WebBrowserPtr;

};

# endif
