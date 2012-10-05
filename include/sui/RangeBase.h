// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����RangeBase.h
// ��  �ܣ�ʵ�ֱ�׼b��tab�ؼ���
// 
// ��  �ߣ�����
// ʱ  �䣺2010-08-31
// 
// ============================================================================

# ifndef _UIRANGEBASE_H_
# define _UIRANGEBASE_H_

#include <sui/sharpuiconfig.h>
#include <suicore/uicontrol.h>

namespace ui
{

typedef delegate<void(suic::Element*,double, double)> ValueChangedEventHandler;

class SHARPUI_API RangeBase : public suic::Control
{
public:

    ValueChangedEventHandler ValueChanged;

    RangeBase();
    virtual ~RangeBase();

    double LargeChange();
    void LargeChange(double val);

    double Maximum();
    void Maximum(double val);

    double Minimum();
    void Minimum(double val);

    double SmallChange();
    void SmallChange(double val);

    double GetValue();
    void SetValue(double val);

protected:

    virtual void OnRender(suic::DrawingContext * drawing);

    virtual void OnMaximumChanged(double oldMaximum, double newMaximum);
    virtual void OnMinimumChanged(double oldMinimum, double newMinimum);
    virtual void OnValueChanged(double oldValue, double newValue);

    virtual void OnGotFocus(suic::FocusEventArg& e);

protected:

    double _iMaximum;
    double _iMinimum;
    double _iSmallChange;
    double _iValue;
};

typedef suic::shared<RangeBase> RangeBasePtr;

};

# endif
