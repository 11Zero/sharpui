// ���ڿƼ���Ȩ���� 2010-2012
// 
// �ļ�����DoubleAnimation.h
// ��  �ܣ�ʵ��Ԫ�ص�double���Ա仯�仯������
// 
// ��  �ߣ�����
// ʱ  �䣺2010-05-01
// 
// ===================================================

# ifndef _UIDOUBLEANIMATION_H_
# define _UIDOUBLEANIMATION_H_

#include <sui/sharpuiconfig.h>
#include <suic/animation/PropertyAnimation.h>

namespace ui
{

class SHARPUI_API DoubleAnimation : public suic::PropertyAnimation
{
public:

    DoubleAnimation(suic::DpPropertyEntity property, bool bRelayout=false);
    DoubleAnimation(suic::DpPropertyEntity property, double dFrom, double dTo, bool bRelayout=false);

    virtual ~DoubleAnimation();

    virtual void OnMeasure(suic::FrameworkElement* pElem);

    /// <summary>
    ///     ������ʼʱ�ص�
    /// </summary>
    /// <param name="pElem">Ŀ��Ԫ��</param>
    /// <returns>��</returns>
    virtual void OnStart(suic::FrameworkElement* pElem);
    virtual void OnFinish(suic::FrameworkElement* pElem);

    double GetFrom() const;
    void SetFrom(double val);

    double GetTo() const;
    void SetTo(double val);

    double GetCurrentValue();

protected:

    double _dFrom;
    double _dTo;
    double _dCurrent;

    bool _bReverse;
};

}

# endif
