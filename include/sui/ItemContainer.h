// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����uiitemcontainer.h
// ��  �ܣ�ʵ�ֽ���Ԫ����ļ��ϡ�
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _UIITEMCONTAINER_H_
# define _UIITEMCONTAINER_H_

#include <sui/sharpuiconfig.h>
#include <suicore/uicontentcontrol.h>

namespace ui
{

class SHARPUI_API ItemSelectionEventArg : public suic::RoutedEventArg
{
public:

    ItemSelectionEventArg(bool bSelected, int iType)
        : suic::RoutedEventArg(suic::ObjectPtr())
    {
        _selected = bSelected;
        _type = iType;
    }

    bool IsSelected() const
    {
        return _selected;
    }

    int GetSelectionType() const
    {
        return _type;
    }

protected:

    bool _selected;
    int _type;
};

static const int MENUITEM_MINHEIGHT = 18;
static const int MENUITEM_ICONSIZE = 18;

class SHARPUI_API ItemContentList
{
public:

    ItemContentList();
    virtual ~ItemContentList();

    suic::Int32 GetCount();
    suic::ObjectPtr GetAt(suic::Int32 index);
    void Add(suic::ObjectPtr item);
    bool Remove(suic::ObjectPtr item);
    suic::ObjectPtr RemoveAt(suic::Int32 index);
    void Reset();

protected:

    suic::EnumeratorPtr _items;
};

class SHARPUI_API NotifyContainerChangedAction
{
public:

    enum eAction 
    {
        Add = 0,
        Remove = 1,
        Replace = 2,
        Move = 3,
        Reset = 4,
    };
};

class SHARPUI_API NotifyContainerChangedArg : public suic::RoutedEventArg
{
public:

    NotifyContainerChangedArg(int ac);

    int GetAction() const;

    void AddNewItem(suic::ObjectPtr item);
    void AddOldItem(suic::ObjectPtr item);

    ItemContentList* NewItems();
    ItemContentList* OldItems();

protected:

    int _action;
    ItemContentList _newItems;
    ItemContentList _oldItems;
};

inline int NotifyContainerChangedArg::GetAction() const
{
    return _action;
}

typedef delegate<void(suic::ObjectPtr, NotifyContainerChangedArg&)> NotifyContainerChangedHandler;

class SHARPUI_API ItemContainer : public suic::RefObject
{
public:

    NotifyContainerChangedHandler ContainerChanged;

    ItemContainer(suic::Element* itemControl);
    virtual ~ItemContainer();

    int GetCount();

    suic::ObjectPtr GetItem(int iIndex) const;
    suic::String GetItemText(int iIndex) const;

    int InsertItem(int index, suic::ObjectPtr item);
    int AddItem(suic::ObjectPtr item);

    void Clear();
    bool Contains(suic::ObjectPtr element);

    int IndexOf(suic::ObjectPtr item) const;

    void Remove(suic::ObjectPtr item);
    void RemoveAt(int index);
    void RemoveRange(int index, int count); 

protected:

    void HandleItem(suic::ObjectPtr& obj);

protected:

    suic::Element* _itemControl;
    suic::Vector<suic::ObjectPtr> _items;
};

typedef suic::shared<ItemContainer> ItemContainerPtr;

};

# endif
