// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����ListBoxItem.h
// ��  �ܣ�ʵ��Item�Ļ���
// 
// ��  �ߣ�����
// ʱ  �䣺2010-08-31
// 
// ============================================================================

# ifndef _UILISTBOXITEM_H_
# define _UILISTBOXITEM_H_

#include <sui/sharpuiconfig.h>
#include <suicore/uicontentcontrol.h>

namespace ui
{

class SHARPUI_API ListBoxItem : public suic::ContentControl
{
public:

    ListBoxItem();
    virtual ~ListBoxItem();

    DECLAREBUILD(ListBoxItem)

protected:

    void OnSetterChanged(suic::SetterChangedEventArg& e);

    void OnRender(suic::DrawingContext * drawing);

    void OnMouseLeftButtonDown(suic::MouseEventArg& e);
    void OnMouseLeftButtonUp(suic::MouseEventArg& e);
};

typedef suic::shared<ListBoxItem> ListBoxItemPtr;

};

# endif
