// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����TabPanel.h
// ��  �ܣ�ʵ��TabPanel��ǩ���֡�
// 
// ��  �ߣ�����
// ʱ  �䣺2010-08-31
// 
// ============================================================================

# ifndef _UITABPANEL_H_
# define _UITABPANEL_H_

#include <sui/sharpuiconfig.h>
#include <suicore/uipanel.h>

namespace ui
{

/// <summary>
///  TabLayout��ʵ�ֱ�ǩ���֡�
/// </summary>
class SHARPUI_API TabPanel : public suic::Panel
{
public:

    TabPanel();
    virtual ~TabPanel();

protected:

    virtual void OnInitialized();

    virtual void OnRender(suic::DrawingContext * drawing);
    virtual void OnGotFocus(suic::FocusEventArg& e);

protected:
};

typedef suic::shared<TabPanel> TabLayoutPtr;

};

# endif
