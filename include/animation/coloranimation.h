// ���ڿƼ���Ȩ���� 2010-2012
// 
// �ļ�����ColorAnimation.h
// ��  �ܣ�ʵ��Ԫ�ص���ɫ�仯������
// 
// ��  �ߣ�����
// ʱ  �䣺2010-05-01
// 
// ===================================================

# ifndef _UICOLORANIMATION_H_
# define _UICOLORANIMATION_H_

#include <sui/sharpuiconfig.h>
#include <animation/PropertyAnimation.h>

namespace ui
{

class SHARPUI_API ColorAnimation : public suic::PropertyAnimation
{
public:

    ColorAnimation(suic::String property);
    virtual ~ColorAnimation();
};

}

# endif
