// ���ڿƼ���Ȩ���� 2010-2012
// 
// �ļ�����PointAnimation.h
// ��  �ܣ�ʵ��λ�õı仯������
// 
// ��  �ߣ�����
// ʱ  �䣺2010-05-01
// 
// ===================================================

# ifndef _UIPOINTANIMATION_H_
# define _UIPOINTANIMATION_H_

#include <sui/sharpuiconfig.h>
#include <suic/animation/PropertyAnimation.h>

namespace ui
{

class SHARPUI_API PointAnimation : public suic::PropertyAnimation
{
public:

    PointAnimation(suic::DpPropertyEntity property);
    virtual ~PointAnimation();
};

}

# endif
