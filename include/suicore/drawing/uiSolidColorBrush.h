// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����SolidColorBrush.h
// ��  �ܣ�ʵ����ɫˢ�ӡ�
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _UISOLIDCOLORBRUSH_H_
# define _UISOLIDCOLORBRUSH_H_

#include <suicore/drawing/uiBrush.h>

namespace suic
{

class SUICORE_API SolidColorBrush : public Brush
{
public:

    SolidColorBrush(suic::Color color);
    virtual ~SolidColorBrush();

    virtual bool Parse(const suic::String& xml);
    virtual bool Parse(void* node);
    virtual void Draw(DrawingContext* drawing, const Rect* lprc);
    virtual void Draw(DrawingContext* drawing, const Rect* lprc, const Rect* border);

    suic::Color ToColor();

protected:

    suic::Color _color;
};

inline suic::Color SolidColorBrush::ToColor()
{
    return _color;
}

};

# endif
