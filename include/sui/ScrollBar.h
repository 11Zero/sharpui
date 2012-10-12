// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����ScrollBar.h
// ��  �ܣ�ʵ�ֹ�����
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _UISCROLLBAR_H_
# define _UISCROLLBAR_H_

#include <sui/RangeBase.h>
#include <sui/UIDefine.h>
#include <sui/RepeatButton.h>

namespace ui
{

enum ScrollEventType
{
    EndScroll = 0,
    First = 1,
    LargeDecrement = 2,
    LargeIncrement = 3,
    Last = 4,
    SmallDecrement = 5,
    SmallIncrement = 6,
    ThumbPosition = 7,
    ThumbTrack = 8,
};

class SHARPUI_API ScrollEventArg : public suic::RoutedEventArg
{
public:

    ScrollEventArg(double curVal) 
        : currentVal(curVal) 
        , RoutedEventArg(suic::ObjectPtr())
    {
    }

    double CurrentValue() 
    { 
        return currentVal; 
    }

    ui::ScrollEventType EventType() 
    { 
        return scrollType;
    }

    void EventType(ui::ScrollEventType t) 
    { 
        scrollType = t; 
    }

protected:

    ui::ScrollEventType scrollType;

    double currentVal;
};

// ���������������
typedef delegate<void(suic::ElementPtr, ui::ScrollEventArg&)> ScrollEventHandler;

class ThumbButton : public ui::Button
{
public:

    void OnRender(suic::DrawingContext * drawing);
};

class SHARPUI_API ScrollBar : public ui::RangeBase
{
public:

    ScrollBar();
    virtual ~ScrollBar();

    DECLAREBUILD(ScrollBar)

    ui::ScrollEventHandler Scroll;
    ui::ScrollEventHandler TrackScroll;

    int GetScrollPos();
    void SetScrollPos(int iPos);

    int GetScrollSize();

    int MaxScrollPos();

    /// <summary>
    ///     ���ù�������Ϣ
    /// </summary>
    /// <param name="iStep">���㲽��(ÿ�ι���һ�еľ���)</param>
    /// <returns>��</returns>
    void SetScrollStep(int iStep);
    int GetScrollStep();
    int GetLogicSize() const;

    void ScrollToBegin(bool bRepaint=true);
    void ScrollTo(int nNewPos, bool bRepaint=true);
    void ScrollToEnd(bool bRepaint=true);

    /// <summary>
    ///     ���ù�������Ϣ
    /// </summary>
    /// <param name="iVisual">���������С(ˮƽΪ���;��ֱΪ�߶�)</param>
    /// <param name="iLogic">�߼������С</param>
    /// <returns>��</returns>
    void SetScrollInfo(int iVisual, int iLogic, bool bRepaint);
    void UpdateScrollInfo(int iVisual, int iLogic, bool bCalc);

    void UpdateScrollVisual(int iVisual, bool bRepaint);
    void UpdateScrollLogic(int iLogic, bool bRepaint);
    void AddScrollLogic(int iLogic, bool bRepaint=false);

    void UpdateScrollBar();

    void ShowFirstScrollButton(bool bShow);
    void ShowSecondScrollButton(bool bShow);

    void LineUp();
    void LineDown();

    void LineLeft();
    void LineRight();

    void PageUp();
    void PageDown();

    void DoScroll(bool bUpdate=true);

public:

    virtual void OnInitialized();
    virtual void OnLoaded(suic::LoadedEventArg& e);
    virtual void OnUnloaded(suic::LoadedEventArg& e);
    virtual void OnStyleUpdated();

    virtual void OnRender(suic::DrawingContext * drawing);
	virtual void OnPreviewMouseLeftButtonDown(suic::MouseEventArg& e);

    virtual void OnSetterChanged(suic::SetterChangedEventArg& e);

protected:

    int PosFromThumb(int thumb, const suic::Size & szClamp);
    suic::Rect GetScrollThumbRect(const suic::Size & size, bool bThumb=false);
    suic::Rect CalcScrollThumbSize();
    void CalcScrollPos();

    void InternalInit();

protected:

    virtual suic::Size MeasureOverride(const suic::Size& size);
    suic::Size ArrangeOverride(const suic::Size& size);

    void OnBeginTrack(suic::Element* pSender, suic::MouseEventArg& e);
    void OnEndTrack(suic::Element* pSender, suic::MouseEventArg& e);

    void OnHorzTrack(suic::Element* pSender, suic::MouseEventArg& e);
    void OnVertTrack(suic::Element* pSender, suic::MouseEventArg& e);

    void OnPageUp(suic::Element* pSender, suic::MouseEventArg& e);
    void OnPageDown(suic::Element* pSender, suic::MouseEventArg& e);

    void OnPageLeft(suic::Element* pSender, suic::MouseEventArg& e);
    void OnPageRight(suic::Element* pSender, suic::MouseEventArg& e);

    void OnLineLeft(suic::Element* pSender, suic::MouseEventArg& e);
    void OnLineRight(suic::Element* pSender, suic::MouseEventArg& e);

    void OnLineUp(suic::Element* pSender, suic::MouseEventArg& e);
    void OnLineDown(suic::Element* pSender, suic::MouseEventArg& e);

protected:

    // ���������Ϣ
    suic::Rect _rcTrack;
    suic::Rect _rcTrackStart;
    suic::Point _ptTrackStart;

    // �������
    ThumbButton _thumb;

    // �ϼ�ͷ�����ͷ
    RepeatButton _decreaseBtn;
    RepeatButton _increaseBtn;

    // ҳ����
    RepeatButton _decreasePage;
    RepeatButton _increasePage;

    UIScrollInfo _scroInfo;

    // ʵ�ʿ��Ӵ�С
    int _iVisualSize;
    // �߼���С
    int _iLogicSize;
    // ��������
    int _iStep;
};

typedef suic::shared<ScrollBar> ScrollBarPtr;

inline int ScrollBar::GetLogicSize() const
{
    return _iLogicSize;
}


};

# endif