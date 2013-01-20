// ���ڿƼ���Ȩ���� 2010-2012
// 
// �ļ�����PropertyAnimation.h
// ��  �ܣ�����������ԵĶ��������ද��������Ҫ�ı�Ԫ��
// ������ֵ���ɴﵽ����Ч����ͬʱҲ�����Ч��һ�ֶ�����
// 
// ��  �ߣ�����
// ʱ  �䣺2012-02-01
// 
// ============================================================================

# ifndef _UIPROPERTYANIMATION_H_
# define _UIPROPERTYANIMATION_H_

#include <suic/animation/animation.h>

namespace suic
{

class SUICORE_API PropertyAnimation : public Animation
{
public:

    PropertyAnimation(DpPropertyEntity property);
    virtual ~PropertyAnimation();

    void SetProperty(const DpPropertyEntity& prop);
    DpPropertyEntity GetProperty() const;

    void SetRelayout(bool value);
    bool GetRelayout() const;

protected:

    // ��Ҫ���еĶ���������
    DpPropertyEntity _property;
    bool _relayout;
};

inline void PropertyAnimation::SetRelayout(bool value)
{
    _relayout = value;
}

inline bool PropertyAnimation::GetRelayout() const
{
    return _relayout;
}

};

# endif
