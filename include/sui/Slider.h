// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����Slider.h
// ��  �ܣ�ʵ�ֱ�׼b��tab�ؼ���
// 
// ��  �ߣ�����
// ʱ  �䣺2010-08-31
// 
// ============================================================================

# ifndef _UISLIDER_H_
# define _UISLIDER_H_

#include <sui/sharpuiconfig.h>
#include <sui/RangeBase.h>
#include <sui/Button.h>
#include <sui/DragEvent.h>

namespace ui
{

//============================================================================
// ������������Ԫ����Ļ��࣬�Ӵ��������Ŀؼ����߱���������.
//
class SHARPUI_API Slider : public RangeBase
{
public:

    Slider();
    virtual ~Slider();

    DeclareTypeofInfo(Slider, RangeBase)

// ���Է��ʶ���
public:

    double GetSelectionStart() const;
    void SetSelectionStart(double val);

    double GetSelectionEnd() const;
    void SetSelectionEnd(double val);

    double GetInterval() const;
    void SetInterval(double val);

public:

    suic::Size MeasureOverride(const suic::Size& size);
    suic::Size ArrangeOverride(const suic::Size& size);

    void OnInitialized();
    void OnRender(suic::DrawingContext * drawing);

    void OnMaximizeValue();
    void OnMaximumChanged(double oldMaximum, double newMaximum);
    void OnMinimizeValue();
    void OnMinimumChanged(double oldMinimum, double newMinimum);

    void OnValueChanged(double oldValue, double newValue);

    virtual void OnThumbDragCompleted(DragCompletedEventArg& e);
    virtual void OnThumbDragDelta(DragDeltaEventArg& e);
    virtual void OnThumbDragStarted(DragStartedEventArg& e);

    void OnMouseLeftButtonDown(suic::MouseEventArg& e);
    void OnKeyDown(suic::KeyboardEventArg& e);

protected:

    void HandleHorizontal(int pos);
    void HandleVertical(int pos);

protected:

    ButtonPtr _thumbBtn;
};

typedef SHARPUI_API suic::shared<Slider> SliderPtr;

};

# endif
