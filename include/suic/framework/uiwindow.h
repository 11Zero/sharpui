// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����Window.h
// ��  �ܣ�ʵ�ֱ�׼�Ĵ�����ʽ��
// 
// ��  �ߣ�����
// ʱ  �䣺2010-12-12
// 
// ============================================================================

# ifndef _UIWINDOW_H_
# define _UIWINDOW_H_

#include <suic/framework/uipanel.h>
#include <suic/core/uiassigner.h>

namespace suic
{

class Window;
typedef delegate<void(Window*, CancelEventArg&)> CancelEventHandler;

class SUICORE_API Window : public Panel
{
public:

    EventHandler Closed;
    CancelEventHandler Closing;
    EventHandler LocationChanged;
    EventHandler StateChanged;

    Window();
    virtual ~Window();

    DeclareTypeofInfo(Window, Panel)

    virtual Int32 Show();
    virtual Int32 ShowNoActivate();
    virtual int ShowDialog();

    void CenterWindow();

    Int32 GetDialogResult();

    virtual void Hide();
    virtual void Close();

    void Activate();
    bool Enable(bool val);

    void StartDragMove();
    void DragMove();
    void EndDragMove();

    void SetInternalValue(String key, ObjectPtr val);

// ���Է��ʶ���
public:

    bool IsMainWindow() const;

    Handle GetOwnerHandle() const;
    void SetOwnerHandle(Handle val);

    Uint32 GetWindowStyle() const;
    void SetWindowStyle(Uint32 val);

    Uint32 GetWindowState() const;
    void SetWindowState(Uint32 val);

    Point GetLocation() const;
    void SetLocation(Point val);

public:

    virtual void OnClosed(EventArg& e);
    virtual void OnClosing(CancelEventArg& e);
    virtual void OnActivated(EventArg& e);
    virtual void OnDeactivated(EventArg& e);

protected:
    
    void UpdateBackground(const Size& size);

    suic::Size MeasureOverride(const suic::Size& size);
    suic::Size ArrangeOverride(const suic::Size& size);

    void OnLoaded(suic::LoadedEventArg& e);

    void OnStyleUpdated();  

    void OnRenderSizeChanged(RenderSizeChangedEventArg& e);
    void OnRenderSizeModeChanged(SizeModeChangedEventArg& e);

    void OnHitTest(HitResultEventArg& e);
    void OnRender(suic::DrawingContext * drawing);

    void OnKeyDown(suic::KeyboardEventArg& e);
    void OnMouseLeftButtonDown(suic::MouseEventArg& e);

protected:

    bool CreateWindowDuringShow();
    bool InitializeComponent(const String& resLocator, String resid);

protected:

    suic::ObjectPtr _data;

    suic::Point _location;
    bool _isClosing;
    bool _appShuttingDown;
    bool _isActivate;
    bool _isMainWindow;

    Int32 _dialogResult;
    bool _showingAsDialog;

    Handle _dialogPreviousActiveHandle;
    AssignerFramePtr _frame;

    suic::Point _prevLocation;
    ElementPtr _disWindows;

    Handle _ownerHandle;

    Uint32 _wndStyle;
    Uint32 _wndState;
    bool _canResize;
};

typedef shared<Window> WindowPtr;

inline Handle Window::GetOwnerHandle() const
{
    return _ownerHandle;
}

inline void Window::SetWindowStyle(Uint32 val)
{
    _wndStyle = val;
}

inline void Window::SetWindowState(Uint32 val)
{
    _wndState = val;
}

inline Uint32 Window::GetWindowStyle() const
{
    return _wndStyle;
}

inline Uint32 Window::GetWindowState() const
{
    return _wndState;
}

};

# endif
