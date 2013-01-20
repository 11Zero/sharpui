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

    DeclareTypeofInfo(HeaderedItemsControl, ItemsControl)

    void SetText(const suic::String & text);
    suic::String GetText();

// ���Է��ʶ���
public:

    suic::ElementPtr GetHeader() const;
    void SetHeader(suic::ElementPtr val);

public:

    int AddChild(suic::ObjectPtr child);

    suic::Size MeasureOverride(const suic::Size& size);
    suic::Size ArrangeOverride(const suic::Size& size);

    void OnInitialized();
    void OnRender(suic::DrawingContext * drawing);

    void OnPropertyChanged(suic::PropertyChangedEventArg& e);
    void OnHeaderChanged(suic::Element* oldHeader, suic::Element* newHeader);

    void OnPreviewMouseLeftButtonDown(suic::MouseEventArg& e);

protected:

    void InitializeScrollView();

protected:

    // Header�Ĳ�����
    suic::PanelPtr _headerHost;
    suic::FrameworkElementPtr _header;
};

typedef suic::shared<HeaderedItemsControl> HeaderedItemsControlPtr;

}

# endif
