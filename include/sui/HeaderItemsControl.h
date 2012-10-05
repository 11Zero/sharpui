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

// ============================================================
// HeaderItemsControl����ѡ����Ļ��ࡣ
// ============================================================
class SHARPUI_API HeaderedItemsControl : public ItemsControl
{
public:

    HeaderedItemsControl();
    virtual ~HeaderedItemsControl();

    suic::ElementPtr GetHeader() const;
    void SetHeader(suic::ElementPtr val);

    int GetIndent() const;
    void SetIndent(int val);

    suic::String GetText();

public:

    virtual void OnHeaderChanged(suic::Element* oldHeader, suic::Element* newHeader);

    virtual void AddLogicalChild(suic::Element* child);

    virtual suic::Size MeasureOverride(const suic::Size& size);
    virtual suic::Size ArrangeOverride(const suic::Size& size);

    virtual void OnInitialized();
    virtual void OnRender(suic::DrawingContext * drawing);

    virtual void OnPreviewMouseLeftButtonDown(suic::MouseEventArg& e);

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
