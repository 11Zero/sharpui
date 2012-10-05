// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����uipopup.h
// ��  �ܣ�ʵ�ֱ�׼�ĵ������ڣ��޽��㣩��
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _UIPOPUP_H_
# define _UIPOPUP_H_

#include <suicore/uicontentcontrol.h>
#include <suicore/hwndadapter.h>
#include <suicore/uiassigner.h>

namespace suic
{

class SUICORE_API UIPopup : public ContentControl
{
public:

    UIPopup();
    virtual ~UIPopup();

    void SetPopupRoot(ElementPtr root);
    ElementPtr GetPopupRoot() const;

    virtual void Show();
    virtual void SetPopupPos(bool position, int x, int y, bool size, int width, int height);
    virtual void TrackingPopup(int x, int y, bool size, int width, int height, HwndAdapterHookPtr hook);

    bool IsActive();

    virtual void Hide();
    virtual void Close();

    void Activate();

    bool IsChildPopup() const;
    void SetChildPopup(bool value);

    bool IsClosing() const;
    bool IsClosed() const;
    bool IsValid() const;

    void SetPopupCapture();
    void ReleasePopupCapture();

    AssignerFramePtr GetAssignerFrame() const;

    virtual void OnClosing(CancelEventArg& e);
    virtual void OnClosed(EventArg& e);

protected:
    
    virtual suic::Size MeasureOverride(const suic::Size& size);
    virtual suic::Size ArrangeOverride(const suic::Size& size);

    virtual void OnInitialized();
    virtual void OnRender(suic::DrawingContext * drawing);

    virtual void OnHitTest(HitResultEventArg& e);
    virtual void OnMouseWheel(suic::MouseWheelEventArg& e);

protected:

    int InternalCreate();

protected:

    bool _bClosing;
    bool _bClosed;
    ElementPtr _popupRoot;
    AssignerFramePtr _frame;

    Point _location;
};

typedef shared<UIPopup> PopupPtr;

class SUICORE_API HwndSourceHookSystemPopup : public suic::IHwndAdapterHook
{
public:

    HwndSourceHookSystemPopup(UIPopup* pPopup);

    bool OnFilterMessage(ObjectPtr sender, MessageParameter& mp);

    void SetAssignerFrame(AssignerFramePtr assignerStage);

protected:

    bool IsMouseInOwner();

protected:

    PopupPtr _popup;
    AssignerFramePtr _frame;
};

};

# endif
