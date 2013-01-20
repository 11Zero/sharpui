// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����ToolBar.h
// ��  �ܣ�ʵ�ֹ������ؼ���
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _TOOLBAR_H_
# define _TOOLBAR_H_

#include <sui/sharpuiconfig.h>
#include <sui/HeaderedItemsControl.h>

namespace ui
{

class SHARPUI_API ToolBar : public HeaderedItemsControl
{
public:

    ToolBar();
    ToolBar(suic::String source);
    virtual ~ToolBar();

    DeclareTypeofInfo(ToolBar, HeaderedItemsControl)

protected:

    void OnInitialized();
    void OnRender(suic::DrawingContext * drawing);

};

typedef suic::shared<ToolBar> ToolBarPtr;

};

# endif
