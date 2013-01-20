// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����Selector.h
// ��  �ܣ�ʵ��Item�Ļ���
// 
// ��  �ߣ�����
// ʱ  �䣺2010-08-31
// 
// ============================================================================

# ifndef _UISELECTOR_H_
# define _UISELECTOR_H_

#include <sui/sharpuiconfig.h>
#include <sui/ItemsControl.h>

namespace ui
{

class SHARPUI_API SelectionChangedEventArg : public suic::RoutedEventArg
{
public:

    SelectionChangedEventArg();

    void AddItem(suic::ObjectPtr item, bool bAdd);

    suic::ItemContentList* AddedItems();
    suic::ItemContentList* RemovedItems();

protected:

    void CallEventHandler(suic::ObjectPtr& handler, suic::ObjectPtr& target);

protected:

    suic::ItemContentList _addItems;
    suic::ItemContentList _removeItems;
};

class SHARPUI_API ItemFocusChangedEventArg : public suic::RoutedEventArg
{
public:

    ItemFocusChangedEventArg(suic::Element* oldFocus,suic::Element* newFocus);

    suic::Element* GetOldFocus() const { return _oldFocus; }
    suic::Element* GetNewFocus() const { return _newFocus; }

protected:

    suic::Element* _oldFocus;
    suic::Element* _newFocus;
};

typedef delegate<void(suic::Element*,SelectionChangedEventArg&),suic::RefObject> SelectionChangedHandler;
typedef delegate<void(suic::Element*,ItemFocusChangedEventArg&)> ItemFocusChangedHandler;

class SelectionMode
{
public:

    enum eSelectionMode
    {
        Single = 0,
        Multiple = 1,
        Extended = 2,
    };
};

/// <summary>
///  ������ѡ�����Ԫ���߼���
/// </summary>
class SHARPUI_API Selector : public ItemsControl
{
public:

    static suic::RoutedEventEntity SelectionChangedEvent;
    ItemFocusChangedHandler ItemFocusChanged;

    Selector();
    virtual ~Selector();

    DeclareAbstractTypeofInfo(Selector, ItemsControl)

    /// <summary>
    ///     ��һ�������ȡSelector����
    /// </summary>
    /// <remarks>
    ///     �˷�����ȡָ������ĵ�һ��Selector����
    /// </remarks>
    /// <param name="pElem">�������</param>
    /// <returns>ֱ��Selector����</returns> 
    static Selector* SelectorFromItem(suic::Element* pElem);

    /// <summary>
    ///  ѡ���ȡ��һ������
    /// </summary>
    /// <remarks>
    ///  �˷�����ʹ��SelectorFromItem��ȡSelector����
    ///  Ȼ������Ԫ�ص�IsSelected��־��ͬʱ����Selector
    ///  �����OnItemSelected�¼�
    /// </remarks>
    /// <param name="item">�������</param>
    /// <param name="selected">ѡ���־</param>
    /// <returns>��</returns> 
    static void SelectItem(suic::ObjectPtr item, bool selected);
    static void SetItemFocus(suic::ElementPtr focusItem);
    
    SelectionMode::eSelectionMode GetSelectionMode() const;

    int SelectedIndex();
    void SelectedIndex(int iIndex);

    suic::ObjectPtr SelectedItem();
    void SelectedItem(suic::ObjectPtr obj);

    void SetItemFocus(int index);

    /// <summary>
    ///     ȡ�����е�ѡ����
    /// </summary>
    /// <returns>��</returns> 
    void UnselectAllItems();

public:

    static void SelectionChangedThunk(suic::Element* sender, SelectionChangedEventArg& e);

    virtual void OnItemSelected(suic::ObjectPtr item, ItemSelectionEventArg& e);
    virtual void OnSelectionChanged(SelectionChangedEventArg& e);
    virtual void OnItemFocusChanged(ItemFocusChangedEventArg& e);

protected:

    void ScrollByUpDown(suic::Element* pElem, bool bUp);

    virtual int GetVisualStartIndex();
    virtual int GetVisualEndIndex();

    void OnInitialized();

    void OnTextInput(suic::KeyboardEventArg& e);
    void OnKeyDown(suic::KeyboardEventArg& e);

protected:

    int _iSelected;

    suic::ItemContentList _selectedItems;
    // ѡ��ģʽ
    SelectionMode::eSelectionMode _selectMode;
};

typedef suic::shared<Selector> SelectorPtr;

inline SelectionMode::eSelectionMode Selector::GetSelectionMode() const
{
    return _selectMode;
}

inline int Selector::GetVisualStartIndex()
{
    return 0;
}

inline int Selector::GetVisualEndIndex()
{
    return _itemsHost->GetVisualChildrenCount();
}

};

# endif