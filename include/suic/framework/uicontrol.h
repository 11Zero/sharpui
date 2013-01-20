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

#include <suic/framework/uiframeworkelement.h>

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

    DeclareTypeofInfo(Control, FrameworkElement)

// ���Է��ʶ���
public:

    bool IsTabStop() const;
    void SetTabStop(bool val);

    int GetTabIndex() const;
    void SetTabIndex(int val);

public:

    void OnRender(DrawingContext * drawing);
    void OnPropertyChanged(PropertyChangedEventArg& e);

protected:

    int _iTabIndex;
};

typedef shared<Control> ControlPtr;

}

#endif
