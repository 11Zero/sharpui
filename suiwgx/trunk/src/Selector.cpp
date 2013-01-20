// ======================================================================
//
// Copyright (c) 2008-2012 ����, Inc. All rights reserved.
//
// Sharpui��Դ����ѭCPLЭ����п�Դ���κθ��˻������ڴ�Э���Ͽ�������ʹ�á�
//
// ======================================================================

//////////////////////////////////////////////////////////////////////////////
// Selector.cpp

#include <sui/Selector.h>

namespace ui
{

SelectionChangedEventArg::SelectionChangedEventArg()
    : suic::RoutedEventArg(suic::ObjectPtr())
{
}

ItemFocusChangedEventArg::ItemFocusChangedEventArg(suic::Element* oldFocus, suic::Element* newFocus)
    : suic::RoutedEventArg(newFocus)
    , _oldFocus(oldFocus), _newFocus(newFocus)
{
}

void SelectionChangedEventArg::AddItem(suic::ObjectPtr item, bool bAdd)
{
    if (bAdd)
    {
        _addItems.Add(item);
    }
    else
    {
        _removeItems.Add(item);
    }
}

suic::ItemContentList* SelectionChangedEventArg::AddedItems()
{
    return &_addItems;
}

suic::ItemContentList* SelectionChangedEventArg::RemovedItems()
{
    return &_removeItems;
}
// ============================================================================
// Selector��Item�Ļ��ࡣ
// ============================================================================

ImplementTypeofInfo(Selector, ItemsControl)

Selector::Selector()
    : _selectMode(SelectionMode::Single)
{
}

Selector::~Selector()
{
}

Selector* Selector::SelectorFromItem(suic::Element* pElem)
{
    suic::Element* pParent = pElem->LogicalParent();

    while (pParent)
    {
        Selector* pRet = dynamic_cast<Selector*>(pParent);

        if (pRet)
        {
            return pRet;
        }

        pParent = pParent->LogicalParent();
    }

    return NULL;
}

void Selector::SelectItem(suic::ObjectPtr item, bool selected)
{
    suic::ElementPtr pElem(item);
    Selector* pSelector = Selector::SelectorFromItem(pElem.get());

    if (!pElem || !pSelector)
    {
        ;
    }
    else
    {
        ItemSelectionEventArg es(selected, 0);

        pElem->SetSelected(selected);
        pSelector->OnItemSelected(item, es);
    }
}

void Selector::SetItemFocus(suic::ElementPtr focusItem)
{
    Selector* pSelector = Selector::SelectorFromItem(focusItem);

    if (focusItem && pSelector)
    {
        suic::ElementPtr oldFocus(pSelector->_focusedItem);

        pSelector->_focusedItem = focusItem.get();
        focusItem->SetFocus();

        ItemFocusChangedEventArg eifc(oldFocus.get(), focusItem.get());

        pSelector->OnItemFocusChanged(eifc);
    }
}

void Selector::SetItemFocus(int index)
{
    suic::ElementPtr viewPtr(GetItems()->GetItem(index));

    SetItemFocus(viewPtr);
}

int Selector::SelectedIndex()
{
    return -1;
}

void Selector::SelectedIndex(int iIndex)
{
    suic::ElementPtr viewPtr(GetItems()->GetItem(iIndex));

    SelectItem(viewPtr.get(), true);
}

suic::ObjectPtr Selector::SelectedItem()
{
    suic::ObjectPtr ret;

    if (_selectedItems.GetCount() > 0)
    {
        ret = _selectedItems.GetAt(0);
    }
    
    return ret;
}

void Selector::SelectedItem(suic::ObjectPtr obj)
{
    int index = GetItems()->IndexOf(obj);

    if (index >= 0)
    {
        SelectedIndex(index);
    }
}

void Selector::UnselectAllItems()
{
    for (int i = 0; i < _selectedItems.GetCount(); ++i)
    {
        suic::ElementPtr item(_selectedItems.GetAt(i));
        item->SetSelected(false);
    }

    _selectedItems.Reset();

    suic::FrameworkElementPtr frame(_focusedItem);

    if (frame)
    {
        frame->SetSelected(false);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////
//
void Selector::OnItemSelected(suic::ObjectPtr item, ItemSelectionEventArg& e)
{
    suic::ElementPtr oldFocus(_focusedItem);
    SelectionChangedEventArg ec;
    suic::Element* pItem = dynamic_cast<suic::Element*>(item.get());

    if (e.IsSelected())
    {
        suic::ElementPtr tmpPtr(_focusedItem.get());

        if (_focusedItem != pItem)
        {
            ItemFocusChangedEventArg eifc(tmpPtr.get(), pItem);

            OnItemFocusChanged(eifc);

            _focusedItem = pItem;
        }

        if (ItemSelected)
        {
            ItemSelected(pItem);
        }
    }
    else
    {
        if (_focusedItem == pItem)
        {
            _focusedItem = NULL;
        }

        if (ItemUnselected)
        {
            ItemUnselected(pItem);
        }
    }

    ec.AddItem(item, e.IsSelected());
    OnSelectionChanged(ec);

    suic::FrameworkElementPtr frame(_focusedItem);

    if (frame && _focusedItem != oldFocus)
    {
        if (frame->IsFocusable())
        {
            frame->SetFocus();
        }
    }
}

void Selector::OnSelectionChanged(SelectionChangedEventArg& e)
{
    if (e.RemovedItems()->GetCount() > 0)
    {
        for (int i = 0; i < e.RemovedItems()->GetCount(); ++i)
        {
            _selectedItems.Remove(e.RemovedItems()->GetAt(i));
        }
    }

    if (e.AddedItems()->GetCount() > 0)
    {
        if (_selectMode == SelectionMode::Single)
        {
            if (_selectedItems.GetCount() > 0
                && _selectedItems.GetAt(0) != e.AddedItems()->GetAt(0))
            {
                suic::FrameworkElementPtr pElem(_selectedItems.GetAt(0));

                Selector::SelectItem(_selectedItems.GetAt(0), false);
                pElem->UpdateSetters("");

                pElem->InvalidateVisual();
            }

            _selectedItems.Reset();
        }

        for (int i = 0; i < e.AddedItems()->GetCount(); ++i)
        {
            suic::ObjectPtr itemPtr = e.AddedItems()->GetAt(i);

            _selectedItems.Add(itemPtr);
        }
    }

    if (SelectionChanged)
    {
        SelectionChanged(e);
    }
}

void Selector::OnItemFocusChanged(ItemFocusChangedEventArg& e)
{
    if (ItemFocusChanged)
    {
        ItemFocusChanged(this, e);
    }
}

void Selector::ScrollByUpDown(suic::Element* pElem, bool bUp)
{
    double val = _scrollHost->VerticalScrollBar()->GetScrollPos();
    double step = _scrollHost->VerticalScrollBar()->GetScrollStep();
    double pos = (double)pElem->GetDesiredSize().cy / step + 0.5;

    if (bUp)
    {
        pos = -pos;
    }

    SetItemFocus(pElem);

    _scrollHost->ScrollToVerticalPos(val + pos);
    _scrollHost->InvalidateArrange();
}

void Selector::OnInitialized()
{
    __super::OnInitialized();

    for (int i = 0; i < GetItems()->GetCount(); ++i)
    {
        suic::ElementPtr itemPtr(GetItems()->GetItem(i));
        suic::ObjectPtr obj = itemPtr->GetInternalValue(_T("IsSelected"));

        if (obj && obj->ToBool())
        {
            SelectedIndex(i);
        }
    }
}

void Selector::OnTextInput(suic::KeyboardEventArg& e)
{
    __super::OnTextInput(e);
}

void Selector::OnKeyDown(suic::KeyboardEventArg& e)
{
    if (e.IsLeftArrow() || e.IsRightArrow())
    {
        double val = _scrollHost->HorizontalScrollBar()->GetScrollSize();
        double step = _scrollHost->HorizontalScrollBar()->GetScrollStep();

        if (e.IsLeftArrow())
        {
            _scrollHost->ScrollToHorizontalPos(val - 1);
        }
        else if (e.IsRightArrow())
        {
            _scrollHost->ScrollToHorizontalPos(val + 1);
        }
    }
    else if (e.IsUpArrow())
    {
        if (!_focusedItem)
        {
            if (GetVisualEndIndex() > 0)
            {
                SetItemFocus(_itemsHost->GetVisualChild(GetVisualEndIndex() - 1));
            }
        }
        else
        {
            suic::ElementPtr frame(_focusedItem);
            //BringIntoView
            int index = _itemsHost->GetVisualChildIndex(frame.get());

            if (index > GetVisualStartIndex())
            {
                suic::ElementPtr pElem(_itemsHost->GetVisualChild(index - 1));

                if (index == GetVisualStartIndex() + 1)
                {
                    ScrollByUpDown(pElem.get(), true);
                }
                else
                {
                    SetItemFocus(pElem.get());
                }
            }
            else
            {
                index = _itemsHost->GetVisibleStart();

                if (index > 0)
                {
                    ScrollByUpDown(GetChild(index - 1), true);
                }
                else
                {
                    ScrollByUpDown(GetChild(0), true);
                }
            }
        }

        _scrollHost->InvalidateVisual();
    }
    else if (e.IsDownArrow())
    {
        if (!_focusedItem)
        {
            if (_itemsHost->GetVisualChildrenCount() > 0)
            {
                SetItemFocus(GetVisualChild(0));
            }
        }
        else
        {
            suic::ElementPtr frame(_focusedItem);
            int index = _itemsHost->GetVisualChildIndex(frame.get());

            if (index < GetVisualEndIndex() - 1)
            {
                suic::ElementPtr pElem(_itemsHost->GetVisualChild(index + 1));

                if (index == GetVisualEndIndex() - 2)
                {
                    ScrollByUpDown(pElem.get(), false);
                }
                else
                {
                    SetItemFocus(pElem.get());
                }
            }
            else
            {
                index = _itemsHost->GetVisibleStart() + _itemsHost->GetVisibleCount();

                if (index < GetItemsCount() - 1)
                {
                    ScrollByUpDown(GetChild(index + 1), false);
                }
                else
                {
                    ScrollByUpDown(GetChild(GetItemsCount() - 1), false);
                }
            }

            _scrollHost->InvalidateVisual();
        }
    }
    else if (e.IsPageup())
    {
        ;
    }
    else if (e.IsPagedown())
    {
        ;
    }
    else if (e.IsHomeKey())
    {
        ;
    }
    else if (e.IsEndKey())
    {
        ;
    }
    else
    {
        __super::OnKeyDown(e);
        return;
    }

    e.SetHandled(true);
}

};
