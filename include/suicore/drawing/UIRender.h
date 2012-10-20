// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����UIRender.h
// ��  �ܣ������ⲿ�Ļص��ӿ�
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-12
// 
// ============================================================================

# ifndef _UIDRAWING_H_
# define _UIDRAWING_H_

#include <suicore/drawing/uidrawing.h>
#include <suicore/uiframeworkelement.h>
#include <suicore/uifont.h>

namespace suic
{

class SUICORE_API Render : public RefObject
{
public:

    static void Draw(DrawingContext* drawing, FrameworkElement* obj, TriggerPtr& trigger);
    static void Draw(DrawingContext* drawing, FrameworkElement* obj, suic::StylePtr& style, const String& state);
    static void Draw(DrawingContext* drawing, FrameworkElement* obj, suic::StylePtr& style);

    static void DrawBackground(DrawingContext* drawing, FrameworkElement* obj);
    static void DrawBackground(DrawingContext* drawing, TriggerPtr& trigger, const Rect* rc);
    static void DrawBorderBrush(DrawingContext* drawing, TriggerPtr& trigger, const Rect* rc);

    static void DrawText(DrawingContext* drawing, FrameworkElement* obj, String& text, TriggerPtr& trigger, const Rect* rc);
    static void DrawText(DrawingContext* drawing, FrameworkElement* obj, String& text);

    static TriggerPtr GetTriggerByStatus(FrameworkElement* obj, suic::StylePtr& style);
    static Size MeasureImageSize(const TriggerPtr& trigger);
    static Size MeasureTextSize(String& text, const TriggerPtr& trigger);
    static Size MeasureTextSizeEx(String& text, Font* font);

protected:

    Render() {}
    virtual ~Render();
};

#define RENDER suic::Render

};

# endif

