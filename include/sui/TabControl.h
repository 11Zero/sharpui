// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����TabControl.h
// ��  �ܣ�ʵ�ֱ�׼b��tab�ؼ���
// 
// ��  �ߣ�����
// ʱ  �䣺2010-08-31
// 
// ============================================================================

# ifndef _UITABCONTROL_H_
# define _UITABCONTROL_H_

#include <sui/sharpuiconfig.h>
#include <sui/TabItem.h>
#include <sui/Selector.h>
#include <sui/StackPanel.h>

namespace ui
{

/// <summary>
///  Tab�ؼ�����ͷ�������ⶨ��Ԫ�ؽ������.
/// </summary>
class SHARPUI_API TabControl : public Selector
{
public:

    TabControl();
    virtual ~TabControl();

    DECLAREBUILD(TabControl);

    suic::ObjectPtr SelectedContent() const;

protected:

    void ClearChildren();
    void RemoveChild(suic::ObjectPtr child);

    suic::Size MeasureOverride(const suic::Size& size);
    suic::Size ArrangeOverride(const suic::Size& size);

    void OnInitialized();
    void OnLoaded(suic::LoadedEventArg& e);

    void OnStyleUpdated();

    void OnRender(suic::DrawingContext * drawing);

    void OnNotifyCollectionChanged(suic::ObjectPtr sender, suic::NotifyCollectionChangedArg& e);

    void OnSetterChanged(suic::SetterChangedEventArg& e);
    void OnItemsChanged(suic::NotifyCollectionChangedArg& e);    
    void OnItemSelected(suic::ObjectPtr item, ItemSelectionEventArg& e);

    void OnItemFocusChanged(suic::Element* newFocus, suic::Element* oldFocus);

    void OnPreviewMouseLeftButtonDown(suic::MouseEventArg& e);
    void OnPreviewMouseLeftButtonUp(suic::MouseEventArg& e);
    void OnMouseEnter(suic::MouseEventArg& e);
    void OnMouseLeave(suic::MouseEventArg& e);

protected:

    // �б�ͷ�Ƿ����ƽ��ֵ����
    bool _isAverage;
    // Tab������߶�
    int _headerHeight;
    // Tab�����
    StackPanel _headerPanel;
};

typedef suic::shared<TabControl> TabControlPtr;

};

# endif
