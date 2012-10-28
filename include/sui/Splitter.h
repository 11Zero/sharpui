// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����Splitter.h
// ��  �ܣ�ʵ��Splitter�ָ�֡�
// 
// ��  �ߣ�����
// ʱ  �䣺2012-08-31
// 
// ============================================================================

# ifndef _UISPLITTER_H_
# define _UISPLITTER_H_

#include <sui/sharpuiconfig.h>
#include <suicore/uipanel.h>

namespace ui
{

/// <summary>
///  TabLayout��ʵ�ַָ�֡�
/// </summary>
class SHARPUI_API Splitter : public suic::Panel
{
public:

    Splitter();
    virtual ~Splitter();

    DECLAREBUILD(Splitter)

protected:

    suic::Size MeasureOverride(const suic::Size& size);
    suic::Size ArrangeOverride(const suic::Size& size);

    void ArrangeHorizontal(const suic::Size& size);
    void ArrangeVertical(const suic::Size& size);

    void OnInitialized();

    void OnRender(suic::DrawingContext * drawing);
    void OnGotFocus(suic::FocusEventArg& e);

    void OnMouseMove(suic::MouseEventArg& e);

    void OnMouseLeftButtonDown(suic::MouseEventArg& e);
    void OnMouseLeftButtonUp(suic::MouseEventArg& e);

protected:

    suic::Vector<suic::Rect> _splits;
    int _trackingIndex;
    suic::Point _trackingPt;
};

typedef suic::shared<Splitter> SplitterPtr;

};

# endif
