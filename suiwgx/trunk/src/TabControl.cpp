// ======================================================================
//
// Copyright (c) 2008-2012 ����, Inc. All rights reserved.
//
// Sharpui��Դ����ѭCPLЭ����п�Դ���κθ��˻������ڴ�Э���Ͽ�������ʹ�á�
//
// ======================================================================

//////////////////////////////////////////////////////////////////////////////
// TabControl.cpp

#include <sui/TabControl.h>
#include <sui/StackPanel.h>
#include <suic/render/uirender.h>

namespace ui
{

ImplementTypeofInfo(TabControl, Selector)

TabControl::TabControl()
    : _isAverage(false)
    , _headerHeight(25)
{
    SetClassName(_T("TabControl"));
    _headerPanel.SetAutoDelete(false);
    _headerPanel.SetHorizontalAlignment(HoriAlignment::Stretch);

    _headerPanel.Children()->SetLogicalParent(this);
}

TabControl::~TabControl()
{
}

suic::ObjectPtr TabControl::SelectedContent() const
{
    return suic::ObjectPtr();
}

void TabControl::OnPropertyChanged(suic::PropertyChangedEventArg& e)
{
    if (e.GetName().Equals(_T("Average")))
    {
        _isAverage = e.GetSetter()->ToBool();
    }
    else
    {
        //
        // ������û����ʼ����������
        //
        __super::OnPropertyChanged(e);
    }
}

void TabControl::ClearChildren()
{
    _headerPanel.ClearChildren();
    __super::ClearChildren();
}

void TabControl::RemoveChild(suic::ObjectPtr child)
{
    _headerPanel.RemoveChild(child);
    __super::RemoveChild(child);
}

suic::Size TabControl::MeasureOverride(const suic::Size& size)
{
    suic::Size availableSize;

    //if (ReadFlag(CoreFlags::IsMeasureDirty))
    {
        _headerHeight = 0;

        int iItems = GetItems()->GetCount();

        for (int i = 0; i < iItems; ++i)
        {
            TabItemPtr tabItem(GetItems()->GetItem(i));

            tabItem->Measure(size);

            if (tabItem->GetDesiredSize().cy > _headerHeight)
            {
                _headerHeight = tabItem->GetDesiredSize().cy;
            }
        }

        _headerPanel.SetMinHeight(_headerHeight);

        TabItemPtr focusTab(_focusedItem);

        if (focusTab && focusTab->GetTabContent())
        {
            focusTab->GetTabContent()->Measure(size);
        }

        WriteFlag(CoreFlags::IsMeasureDirty, false);
    }

    return size;
}

suic::Size TabControl::ArrangeOverride(const suic::Size& size)
{
    ClearVisualChildren();

    _headerPanel.ClearChildren();

    int iItems = GetItems()->GetCount();
    suic::Rect finalRect(0, 0, size.cx, size.cy);

    if (iItems > 0)
    {
        if (_isAverage)
        {
            TabItemPtr tabItem;
            int iWid = size.cx / iItems;
            suic::Size itemSize(iWid, _headerHeight);

            for (int i = 0; i < iItems - 1; ++i)
            {
                tabItem = GetItems()->GetItem(i).get();
                tabItem->SetDesiredSize(itemSize);
            }

            tabItem = GetItems()->GetItem(iItems - 1).get();

            itemSize.cx = size.cx - iWid * (iItems - 1);
            tabItem->SetDesiredSize(itemSize);

            for (int i = 0; i < iItems; ++i)
            {
                tabItem = GetItems()->GetItem(i).get();
                _headerPanel.AddChild(tabItem.get());
            }

            finalRect.bottom = finalRect.top + _headerHeight;

            AddVisualChild(&_headerPanel);
            _headerPanel.Arrange(finalRect);
        }
        else
        {
            for (int i = 0; i < iItems; ++i)
            {
                TabItemPtr tabItem = GetItems()->GetItem(i);

                if (tabItem)
                {
                    _headerPanel.AddChild(tabItem.get());
                }
            }

            finalRect.bottom = finalRect.top + _headerHeight;

            AddVisualChild(&_headerPanel);
            _headerPanel.Arrange(finalRect);
        }

        finalRect.top = finalRect.bottom;
        finalRect.bottom = size.cy;
    }

    TabItemPtr focusTab(_focusedItem);

    if (focusTab)
    {  
        if (focusTab->GetTabContent())
        {
            AddVisualChild(focusTab->GetTabContent());
            focusTab->GetTabContent()->Arrange(finalRect);
        }
    }

    return size;
}

void TabControl::OnInitialized()
{
    __super::OnInitialized();

    //AddLogicalChild(&_headerPanel);

    _headerPanel.SetClassName(_T("TabHeader"));
    //_headerPanel.Children()->NotifyCollectionChanged += suic::NotifyCollectionChangedHandler(this, &TabControl::OnNotifyCollectionChanged);

    _headerPanel.BeginInit();
    _headerPanel.EndInit();

    if (GetItems()->GetCount() > 0 && !_focusedItem)
    {
        Selector::SelectItem(GetItems()->GetItem(0), true);
    }

    TabItemPtr focusTab(_focusedItem);

    if (focusTab && focusTab->GetTabContent())
    {
        focusTab->GetTabContent()->Measure(suic::Size());
    }
}

void TabControl::OnLoaded(suic::LoadedEventArg& e)
{
    __super::OnLoaded(e);

    if (_focusedItem)
    {
        Selector::SelectItem(_focusedItem, true);
    }
}

void TabControl::OnStyleUpdated()
{
    _headerPanel.UpdateStyle();
}

void TabControl::OnRender(suic::DrawingContext * drawing)
{
    suic::Rect rect(0, _headerHeight, RenderSize().cx, RenderSize().cy - _headerHeight);
    suic::Render::RenderBackground(drawing, this, &rect);
}

void TabControl::OnNotifyCollectionChanged(suic::ObjectPtr sender, suic::NotifyCollectionChangedArg& e)
{
    if (sender.get() == &_headerPanel)
    {
        if (e.GetAction() == suic::NotifyCollectionChangedAction::Remove)
        {
            RemoveChild(e.OldItems()->GetAt(0));
        }
    }
    else
    {
        __super::OnNotifyCollectionChanged(sender, e);
    }
}

void TabControl::OnItemsChanged(suic::NotifyCollectionChangedArg& e)
{
    WriteFlag(CoreFlags::IsMeasureDirty, true);

    if (e.NewItems()->GetCount() > 0)
    {        
        TabItemPtr itemPtr(e.NewItems()->GetAt(0));
        suic::ElementPtr focused;

        //
        // ʹ��ǰӵ�н����Ԫ������������(����zIndex)
        //
        if (focused)
        {
            //suic::Panel::SetZIndex(focused, _itemLayout->GetLogicalChildrenCount());
        }
    }
}

void TabControl::OnItemSelected(suic::ObjectPtr item, ItemSelectionEventArg& e)
{
    __super::OnItemSelected(item, e);

    //
    // ���ò�����С�������־��ʹ���ֹ���������Ԫ�ز�����С
    //
    RaisedMeasureDirty();

    //
    // ˢ�²��ֺ���ʾ
    //
    InvalidateMeasure();
    InvalidateArrange();
    InvalidateVisual();
}

void TabControl::OnItemFocusChanged(ItemFocusChangedEventArg& e)
{
    if (e.GetOldFocus())
    {
        TabItemPtr itemPtr(e.GetOldFocus());
        
        if (itemPtr && itemPtr->GetTabContent())
        {
            itemPtr->GetTabContent()->SetVisible(false);
        }
    }

    if (e.GetNewFocus())
    {
        TabItemPtr itemPtr(e.GetNewFocus());
        
        if (itemPtr && itemPtr->GetTabContent())
        {
            itemPtr->GetTabContent()->SetVisible(true);
        }
    }

    __super::OnItemFocusChanged(e);
}

void TabControl::OnPreviewMouseLeftButtonDown(suic::MouseEventArg& e)
{
    __super::OnPreviewMouseLeftButtonDown(e);
}

void TabControl::OnPreviewMouseLeftButtonUp(suic::MouseEventArg& e)
{
}

void TabControl::OnMouseEnter(suic::MouseEventArg& e)
{
    e.SetHandled(true);   
}

void TabControl::OnMouseLeave(suic::MouseEventArg& e)
{
    e.SetHandled(true); 
}

};
