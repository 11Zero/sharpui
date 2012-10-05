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

///==================================================
/// Tab�ؼ�����ͷ�������ⶨ��Ԫ�ؽ������.
///
class SHARPUI_API TabControl : public Selector
{
public:

    TabControl();
    virtual ~TabControl();

    DECLAREBUILD(TabControl);

    suic::ObjectPtr SelectedContent() const;

protected:
    
    virtual suic::Size MeasureOverride(const suic::Size& size);
    virtual suic::Size ArrangeOverride(const suic::Size& size);

    virtual void OnInitialized();
    virtual void OnLoaded(suic::LoadedEventArg& e);

    virtual void OnRender(suic::DrawingContext * drawing);

    virtual void OnItemsChanged(NotifyContainerChangedArg& e);    
    virtual void OnItemSelected(suic::ObjectPtr item, ItemSelectionEventArg& e);

    virtual void OnPreviewMouseLeftButtonDown(suic::MouseEventArg& e);
    virtual void OnPreviewMouseLeftButtonUp(suic::MouseEventArg& e);
    virtual void OnMouseEnter(suic::MouseEventArg& e);
    virtual void OnMouseLeave(suic::MouseEventArg& e);

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
