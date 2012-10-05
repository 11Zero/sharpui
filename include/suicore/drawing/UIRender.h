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

class SUICORE_API UIRender : public RefObject
{
public:

    static void Draw(DrawingContext* drawing, FrameworkElement* obj, TriggerPtr& trigger);
    static void Draw(DrawingContext* drawing, FrameworkElement* obj, suic::StylePtr& style, const String& state);
    static void Draw(DrawingContext* drawing, FrameworkElement* obj, suic::StylePtr& style);

    static void DrawBackground(DrawingContext* drawing, TriggerPtr& trigger, const Rect* rc);
    static void DrawBorderBrush(DrawingContext* drawing, TriggerPtr& trigger, const Rect* rc);
    static void DrawText(DrawingContext* drawing, String& text, TriggerPtr& trigger
        , const Rect* rc, int iHorz, int iVert);

    static TriggerPtr GetTriggerByStatus(FrameworkElement* obj, suic::StylePtr& style);
    static Size MeasureImageSize(const TriggerPtr& trigger);
    static Size MeasureTextSize(String& text, const TriggerPtr& trigger);
    static Size MeasureTextSizeEx(String& text, Font* font);

protected:

    UIRender() {}
    virtual ~UIRender();
};

#define RENDER suic::UIRender

};

# endif

