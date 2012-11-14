// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����HeaderItemsControl.h
// ��  �ܣ�����ͷ�����ݵĿؼ�
// 
// ��  �ߣ�����
// ʱ  �䣺2011-12-25
// 
// ============================================================================

# ifndef _UIHEADERITEMSCONTROL_H_
# define _UIHEADERITEMSCONTROL_H_

#include <sui/sharpuiconfig.h>
#include <sui/itemscontrol.h>

namespace ui
{

/// <summary>
/// HeaderItemsControl����ѡ����Ļ��ࡣ
/// </summary>
class SHARPUI_API HeaderedItemsControl : public ItemsControl
{
public:

    HeaderedItemsControl();
    virtual ~HeaderedItemsControl();

    void SetText(const suic::String & text);
    suic::String GetText();

// ���Է��ʶ���
public:

    DEFINE_PROPERTY(suic::ElementPtr, Header, val);
    DEFINE_PROPERTY(int, Indent, val);

public:

    int AddChild(suic::ObjectPtr child);

    suic::Size MeasureOverride(const suic::Size& size);
    suic::Size ArrangeOverride(const suic::Size& size);

    void OnInitialized();
    void OnRender(suic::DrawingContext * drawing);

    void OnSetterChanged(suic::SetterChangedEventArg& e);
    void OnHeaderChanged(suic::Element* oldHeader, suic::Element* newHeader);

    void OnPreviewMouseLeftButtonDown(suic::MouseEventArg& e);

protected:

    suic::ElementPtr _header;
    int _indent;
};

typedef suic::shared<HeaderedItemsControl> HeaderItemsControlPtr;

inline int HeaderedItemsControl::GetIndent() const
{
    return _indent;
}

inline void HeaderedItemsControl::SetIndent(int val)
{
    _indent = val;
}

}

# endif
