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

#include <suic/graphics/uiBrush.h>

namespace suic
{

class SUICORE_API SolidColorBrush : public Brush
{
public:

    SolidColorBrush(suic::Color color);
    virtual ~SolidColorBrush();

    bool Parse(const suic::String& xml);
    bool Parse(void* node);
    void Draw(DrawingContext* drawing, const Rect* lprc);
    void Draw(DrawingContext* drawing, const Rect* lprc, const Rect* border);

    suic::Color ToColor();
    String ToString();

protected:

    suic::Color _color;
};

inline suic::Color SolidColorBrush::ToColor()
{
    return _color;
}

};

# endif
