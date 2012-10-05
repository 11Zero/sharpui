// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����TabItem.h
// ��  �ܣ�ʵ��Tab�ؼ��
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _UITABITEM_H_
# define _UITABITEM_H_

#include <sui/sharpuiconfig.h>
#include <sui/itemcontainer.h>
#include <sui/HeaderContentControl.h>

namespace ui
{

// ========================================================
// ������������Ԫ����Ļ��࣬�Ӵ��������Ŀؼ����߱���������.
//
class SHARPUI_API TabItem : public suic::ContentControl
{
public:

    TabItem();
    virtual ~TabItem();

    suic::ElementPtr FindName(const suic::String& strName);

    suic::ElementPtr GetTabContent();
    void SetTabContent(suic::ElementPtr elem);

    DECLAREBUILD(TabItem)

public:

    virtual void AddLogicalChild(suic::Element* child);
   
    virtual void OnInitialized();
    virtual void OnLoaded(suic::LoadedEventArg& e);

    virtual void OnStyleUpdated();

    virtual void OnSetterChanged(suic::SetterChangedEventArg& e);
    virtual void OnTabContentChanged(suic::Element* oldVal, suic::Element* newVal);

    virtual void OnRender(suic::DrawingContext * drawing);

    void OnMouseEnter(suic::MouseEventArg& e);
    void OnMouseMove(suic::MouseEventArg& e);
    void OnMouseLeave(suic::MouseEventArg& e);

    void OnPreviewMouseLeftButtonDown(suic::MouseEventArg& e);
    void OnMouseLeftButtonDown(suic::MouseEventArg& e);
    void OnMouseLeftButtonUp(suic::MouseEventArg& e);

    void OnGotFocus(suic::FocusEventArg& e);

protected:

    suic::ElementPtr _tabContent;
};

typedef SHARPUI_API suic::shared<TabItem> TabItemPtr;

inline suic::ElementPtr TabItem::GetTabContent()
{
    return _tabContent;
}

};

# endif
