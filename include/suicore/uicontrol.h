// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����Control.h
// ��  �ܣ�������Ŀ�һ���û��ؼ��ࡣ
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _UICONTROL_H_
# define _UICONTROL_H_

#include <suicore/uiframeworkelement.h>

namespace suic
{

/// <summary>
/// �ؼ�����࣬����̳�֧��tab���л�
/// </summary>
class SUICORE_API Control : public FrameworkElement
{
public:

    Control();
    virtual ~Control();

    bool IsTabStop() const;
    void SetTabStop(bool val);

    int GetTabIndex() const;
    void SetTabIndex(int index);

public:

    virtual void OnRender(DrawingContext * drawing);

    virtual void OnGotFocus(suic::FocusEventArg& e);
    virtual void OnMouseEnter(MouseEventArg& e);

    virtual void OnMouseLeftButtonDown(MouseEventArg& e);
    virtual void OnMouseLeftButtonUp(MouseEventArg& e);

    void OnSetterChanged(SetterChangedEventArg& e);

protected:

    int _iTabIndex;
};

typedef shared<Control> ControlPtr;

}

#endif
