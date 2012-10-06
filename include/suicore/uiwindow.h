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

#include <suicore/uipanel.h>
#include <suicore/uiassigner.h>

namespace suic
{

typedef delegate<void(suic::Element*, CancelEventArg&)> CancelEventHandler;

class SUICORE_API Window : public Panel
{
public:

    EventHandler Closed;
    CancelEventHandler Closing;
    EventHandler LocationChanged;
    EventHandler StateChanged;

    Window();
    virtual ~Window();

    virtual ElementPtr CreateElement() const;

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

    void SetLocation(suic::Point pt);
    suic::Point GetLocation() const;

public:

    virtual void OnClosed(EventArg& e);
    virtual void OnClosing(CancelEventArg& e);
    virtual void OnActivated(EventArg& e);
    virtual void OnDeactivated(EventArg& e);

protected:
    
    suic::Size MeasureOverride(const suic::Size& size);
    suic::Size ArrangeOverride(const suic::Size& size);

    void OnLoaded(suic::LoadedEventArg& e);

    void OnSetterChanged(SetterChangedEventArg& e);

    void OnRenderSizeChanged(RenderSizeChangedEventArg& e);
    void OnRenderSizeModeChanged(SizeModeChangedEventArg& e);

    void OnHitTest(HitResultEventArg& e);
    void OnRender(suic::DrawingContext * drawing);

    void OnKeyDown(suic::KeyEventArg& e);
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

    Int32 _dialogResult;
    bool _showingAsDialog;

    Handle _dialogPreviousActiveHandle;
    AssignerFramePtr _frame;

    suic::Point _prevLocation;
    ElementPtr _disWindows;

    Uint32 _style;
    Uint32 _state;
    bool _canResize;
};

typedef shared<Window> WindowPtr;

};

# endif
