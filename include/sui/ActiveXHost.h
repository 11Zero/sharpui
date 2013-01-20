// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����ActiveXControl.h
// ��  �ܣ�ʵ��ActiveXHost�ؼ��ķ�װ
// 
// ��  �ߣ�����
// ʱ  �䣺2010-08-31
// 
// ============================================================================

# ifndef _UIACTIVEX_H_
# define _UIACTIVEX_H_

#include <sui/sharpuiconfig.h>
#include <suic/framework/hwndhost.h>

namespace ui
{

/// <summary>
///  ActiveXHost����װActiveXHost�ؼ���
/// </summary>
class SHARPUI_API ActiveXHost : public suic::HwndHost
{
public:

    ActiveXHost();
    virtual ~ActiveXHost();

    DeclareTypeofInfo(ActiveXHost, suic::HwndHost)

    suic::Handle GetControlHandle() const;

protected:

    bool DoVerb(int verb);

protected:

    virtual void OnInitialized();

    virtual void OnRender(suic::DrawingContext * drawing);

    virtual void OnTextInput(suic::KeyboardEventArg& e);
    virtual void OnKeyDown(suic::KeyboardEventArg& e);

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

    // ���class id
    //CLSID _clsid;

    suic::Handle _hwndParent;
    suic::Handle _axWindow;
    suic::Rect _boundRect;

    // �ؼ�����
    /*IOleObject* _axOleObject;
    IOleInPlaceObject* _axOleInPlaceObject;
    IOleInPlaceActiveObject* _axOleInPlaceActiveObject;*/
};

typedef suic::shared<ActiveXHost> ActiveXPtr;

};

# endif
