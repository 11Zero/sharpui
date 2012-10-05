// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����StackPanel.h
// ��  �ܣ�ջʽ�ؼ����ֹ���֧�ֶ��Ӵ�����Զ����֡�
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _UISTACKPANEL_H_
# define _UISTACKPANEL_H_

#include <sui/sharpuiconfig.h>
#include <suicore/uipanel.h>

namespace ui
{

class SHARPUI_API StackPanel : public suic::Panel
{
public:

    StackPanel();
    StackPanel(bool bHorz);

    DECLAREBUILD(StackPanel)

    virtual ~StackPanel();

protected:

    void OnRender(suic::DrawingContext * drawing);

    virtual suic::Size MeasureOverride(const suic::Size& size);
    virtual suic::Size ArrangeOverride(const suic::Size& size);

protected:

    void CalcHorzElement(suic::FrameworkElement* ePtr, suic::Rect& rcLay
        , suic::Rect& rc, suic::Rect& rcClip);
    void CalcVertElement(suic::FrameworkElement* ePtr, suic::Rect& rcLay
        , suic::Rect& rc, suic::Rect& rcClip);

private:

    void RelayoutHorizontal(const suic::Size& size);
    void RelayoutVertical(const suic::Size& size);
};

typedef suic::shared<StackPanel> StackPanelPtr;

}

# endif
