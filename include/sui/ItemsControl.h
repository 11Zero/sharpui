// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����ItemsControl.h
// ��  �ܣ�ʵ��Item�Ļ���
// 
// ��  �ߣ�����
// ʱ  �䣺2010-08-31
// 
// =============================================================

# ifndef _UIITEMSCONTROL_H_
# define _UIITEMSCONTROL_H_

#include <sui/sharpuiconfig.h>
#include <sui/scrollbar.h>
#include <suicore/uicontentcontrol.h>
#include <suicore/uielementcollection.h>
#include <sui/itemcontainer.h>

#include <sui/VisualizePanel.h>
#include <sui/ScrollViewer.h>

namespace ui
{

class ItemContainer;

/// <summary>
/// ItemsControl,����ѡ����Ļ��ࡣ
/// </summary>
class SHARPUI_API ItemsControl : public suic::Control
{
public:

    ItemsControl();
    virtual ~ItemsControl();

public:

    bool HasItems() const;
    bool IsGrouping() const;

    ItemContainerPtr GetItems() const;

    int GetItemsCount() const;

    /// <summary>
    ///     �����������
    /// </summary>
    /// <remarks>
    ///     ������Ǵ�Element���������ʹ��TextBloch���а�װ
    /// </remarks>
    /// <param name="value">
    ///     �������
    /// </param>
    /// <returns>�����������</returns>
    virtual int Add(suic::ObjectPtr value);
    virtual int Insert(int index, suic::ObjectPtr value);
    virtual int AddText(const suic::String& text);

    virtual void RemoveAt(int iIndex);
    virtual void Remove(suic::ObjectPtr ePtr);
    virtual void RemoveAll();

    virtual suic::ObjectPtr GetItem(int iIndex) const;
    virtual suic::String GetItemText(int iIndex) const;

    void OnNotifyContainerChanged(suic::ObjectPtr sender, NotifyContainerChangedArg& e);

public:

    virtual void AddLogicalChild(suic::Element* child);
    virtual void RemoveLogicalChild(suic::Element* child);
    virtual suic::Element* GetLogicalChild(int index);
    virtual suic::Int32 GetLogicalChildrenCount();

    virtual void OnItemsChanged(NotifyContainerChangedArg& e);

    virtual suic::Size MeasureOverride(const suic::Size& size);
    virtual suic::Size ArrangeOverride(const suic::Size& size);

    virtual void OnInitialized();
    virtual void OnUnloaded(suic::LoadedEventArg& e);

    virtual void OnRender(suic::DrawingContext * drawing);

    virtual void OnTextInput(suic::KeyEventArg& e);
    virtual void OnKeyDown(suic::KeyEventArg& e);

    virtual void OnMouseEnter(suic::MouseEventArg& e);
    virtual void OnMouseMove(suic::MouseEventArg& e);
    virtual void OnMouseLeave(suic::MouseEventArg& e);

    virtual void OnPreviewMouseLeftButtonDown(suic::MouseEventArg& e);
    virtual void OnMouseLeftButtonDown(suic::MouseEventArg& e);
    virtual void OnMouseLeftButtonDbclk(suic::MouseEventArg& e);
    virtual void OnMouseLeftButtonUp(suic::MouseEventArg& e);

    virtual void OnMouseWheel(suic::MouseWheelEventArg& e);

protected:

    virtual void InitializeScrollView();

protected:

    // Ԫ�ش洢����
    ItemContainerPtr _container;
    // ���ֶ���
    suic::PanelPtr _panel;
    // ��ͼ����
    ScrollViewPtr _scrollView;
    //ScrollData _scrollData;
};

typedef suic::shared<ItemsControl> ItemsControlPtr;

};

# endif
