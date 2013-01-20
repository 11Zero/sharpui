// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����SelectorPanel.h
// ��  �ܣ���ѡ��塣
// 
// ��  �ߣ�����
// ʱ  �䣺2012-06-02
// 
// ============================================================================

# ifndef _SELECTORPANEL_H_
# define _SELECTORPANEL_H_

#include <sui/sharpuiconfig.h>
#include <suic/framework/uipanel.h>

namespace ui
{

class SHARPUI_API SelectorPanel : public suic::Panel
{
public:

    SelectorPanel();
    virtual ~SelectorPanel();

    DeclareTypeofInfo(SelectorPanel, suic::Panel)

protected:

    void OnInitialized();
    void OnRender(suic::DrawingContext * drawing);

};

typedef suic::shared<SelectorPanel> SelectorPanelPtr;

};

# endif
