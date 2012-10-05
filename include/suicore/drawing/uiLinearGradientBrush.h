// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����GradientBrush.h
// ��  �ܣ����彥��ˢ�ӻ��ࡣ
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _UILINEARGRADIENTBRUSH_H_
# define _UILINEARGRADIENTBRUSH_H_

#include <suicore/drawing/uiGradientBrush.h>

namespace suic
{

class SUICORE_API LinearGradientBrush : public GradientBrush
{
public:

    LinearGradientBrush();
    virtual ~LinearGradientBrush();

    virtual bool Parse(const suic::String& xml);
    virtual bool Parse(void* node);
    virtual void Draw(DrawingContext* drawing, const Rect* lprc);

protected:

    ObjectPtr _data;
};

};

# endif
