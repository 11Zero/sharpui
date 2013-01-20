// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����GradientBrush.h
// ��  �ܣ����彥��ˢ�ӻ��ࡣ
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _UIGRADIENTBRUSH_H_
# define _UIGRADIENTBRUSH_H_

#include <suic/graphics/uiBrush.h>

namespace suic
{

class SUICORE_API GradientBrush : public Brush
{
public:

    GradientBrush();
    virtual ~GradientBrush();

    virtual bool Parse(const suic::String& xml);
    virtual void Draw(DrawingContext* drawing, const Rect* lprc);

protected:

    ObjectPtr _data;
};

};

# endif
