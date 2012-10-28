// ======================================================================
//
// Copyright (c) 2008-2012 ����, Inc. All rights reserved.
//
// Sharpui��Դ����ѭCPLЭ����п�Դ���κθ��˻������ڴ�Э���Ͽ�������ʹ�á�
//
// ======================================================================

//////////////////////////////////////////////////////////////////////////////
// TreeView.cpp

#include <sui/treeviewitem.h>
#include <sui/treeview.h>
#include <sui/TextBlock.h>
#include <suicore/drawing/uiImageBrush.h>
#include <suicore/drawing/uirender.h>

namespace ui
{

typedef delegate<void()> TreeButtonClickEventHandler;

class TreeButton : public ui::Button
{
public:

    TreeButtonClickEventHandler Expanded;
    TreeButtonClickEventHandler Collapsed;

    TreeButton(suic::ImageBrushPtr exp, suic::ImageBrushPtr cop)
        : _expanded(exp)
        , _collapsed(cop)
        , _bCollapsed(false)
    {
        SetClassName(_T("TreeButton"));
    }

    void OnClick(suic::RoutedEventArg& e)
    {
        _bCollapsed = !_bCollapsed;

        if (_bCollapsed)
        {
            if (Collapsed)
            {
                Collapsed();
            }
        }
        else
        {
            if (Expanded)
            {
                Expanded();
            }
        }
    }

    void OnRender(suic::DrawingContext * drawing)
    {
        suic::Rect rect(0, 0, RenderSize().cx, RenderSize().cy);

        if (_expanded)
        {
            if (_bCollapsed)
            {
                _expanded->Draw(drawing, &rect);
            }
            else
            {
                _collapsed->Draw(drawing, &rect);
            }
        }
    }

    suic::Size MeasureOverride(const suic::Size& size)
    {
        suic::Rect rect;

        if (_expanded)
        {
            rect = _expanded->GetContentBrounds();
        }

        return suic::Size(rect.Width(), rect.Height());
    }

    void SetCollapsed(bool bCollapsed)
    {
        _bCollapsed = bCollapsed;
    }

    void OnGotFocus(suic::FocusEventArg& e)
    {
        ;
    }

protected:

    suic::ImageBrushPtr _expanded;
    suic::ImageBrushPtr _collapsed;

    bool _bCollapsed;
};

//=====================================================
// TreeItemHeader

TreeItemHeader::TreeItemHeader()
{
    SetClassName(_T("TreeViewItem"));
    WriteFlag(CoreFlags::IsSupportMouseOver, true);
}

void TreeItemHeader::OnRender(suic::DrawingContext * drawing)
{
    if (IsEnabled())
    {
        suic::TriggerPtr setter;

        if (IsFocused())
        {
            setter = GetStyle()->GetTrigger(suic::SELECTED);
        }
        else if (IsSelected())
        {
            setter = GetStyle()->GetTrigger(suic::FOCUSED);
        }
        else if (IsMouseOver())
        {
            setter = GetStyle()->GetTrigger(suic::MOUSEOVER);
        }

        if (!setter)
        {
            setter = GetStyle()->GetTrigger();
        }

        if (setter)
        {
            suic::Render::Draw(drawing, this, setter);
        }
    }
    else
    {
        suic::Control::OnRender(drawing);
    }
}

//======================================================
// TreeViewItem

static TreeView* GetParentTreeView(suic::Element* pElem)
{
    TreeView* pTree = NULL;
    suic::Element* pParent = pElem->GetParent();

    while (pParent)
    {
        pTree = dynamic_cast<TreeView*>(pParent);

        if (pTree)
        {
            break;
        }

        pParent = pParent->GetParent();
    }

    return pTree;
}

TreeViewItem::TreeViewItem()
    : _showDotLine(false)
{
    SetIndent(20);

    SetHorizontalContentAlignment(suic::LEFT);
    SetVerticalContentAlignment(suic::CENTER);

    SetPadding(suic::Rect(2,0,0,0));

    TreeItemHeader* pHeader = new TreeItemHeader();

    _header = pHeader;
    _check.SetAutoDelete(false);
    _icon.SetAutoDelete(false);

    pHeader->SetMinHeight(18);
}

void TreeViewItem::Select()
{
    TreeView* pTree = GetParentTreeView(this);

    if (pTree)
    {
        suic::RoutedEventArg e(this);

        OnSelected(e);

        pTree->OnSelectTreeItem(this);
    }
}

void TreeViewItem::Unselect()
{
    TreeView* pTree = GetParentTreeView(this);

    if (pTree)
    {
        suic::RoutedEventArg e(this);

        OnUnselected(e);

        pTree->OnUnselectTreeItem(this);
    }
}

void TreeViewItem::Expand()
{
    WriteFlag(CoreFlags::IsCollapsed, false);

    int count = GetItems()->GetCount();

    for (int i = 0; i < count; ++i)
    {
        TreeViewItemPtr item = TreeViewItemPtr::cast(GetItems()->GetItem(i));

        if (item)
        {
            item->Expand();
        }
    }
}

void TreeViewItem::Collapse()
{
    WriteFlag(CoreFlags::IsCollapsed, true);

    int count = GetItems()->GetCount();

    for (int i = 0; i < count; ++i)
    {
        TreeViewItemPtr item = TreeViewItemPtr::cast(GetItems()->GetItem(i));

        if (item)
        {
            item->Collapse();
        }
    }
}

/////////////////////////////////////////////////////////////////////
//
static void DrawVertTreeDot(suic::DrawingContext * drawing, int by, int ey, int x)
{
    for (int i = by; i <= ey; ++i)
    {
        drawing->SetPixel(x, i++, ARGB(255,180,180,180));
    }
}

static void DrawHorzTreeDot(suic::DrawingContext * drawing, int bx, int ex, int y)
{
    for (int i = bx; i <= ex; ++i)
    {
        drawing->SetPixel(i++, y, ARGB(255,180,180,180));
    }
}

ImageBox* TreeViewItem::GetIcon()
{
    return &_icon;
}

void TreeViewItem::
OnHeaderChanged(suic::Element* oldHeader, suic::Element* newHeader)
{
    TreeItemHeaderPtr itemHead(_header);

    itemHead->SetContent(newHeader);
}

void TreeViewItem::OnSetterChanged(suic::SetterChangedEventArg& e)
{
    //
    // ��ʼ���ؼ�������Դ
    //
    if (e.GetName().Equals(_T("Header")))
    {
        TreeItemHeaderPtr itemHead(_header);

        itemHead->SetText(e.GetSetter()->ToString());
    }
    else if (e.GetName().Equals(_T("Icon")))
    {
        _icon.SetSource(e.GetSetter()->ToString());
    }
    else if (e.GetName().Equals(_T("CheckButton")))
    {
        _check.SetVisible(e.GetSetter()->ToBool());
    }
    else if (e.GetName().Equals(_T("Indent")))
    {
        SetIndent(e.GetSetter()->ToInt32());
    }
    else
    {
        //
        // ������û����ʼ����������
        //
        __super::OnSetterChanged(e);
    }
}

void TreeViewItem::OnMouseLeftButtonDbclk(suic::MouseEventArg& e)
{
    __super::OnMouseLeftButtonDbclk(e);

    if (GetItems()->GetCount() > 0)
    {
        suic::RoutedEventArg er(this);
        _expand->OnClick(er);
    }

    e.Handled(true);
}

void TreeViewItem::OnInitialized()
{
    __super::OnInitialized();

    suic::ObjectPtr Expanded = FindResource(_T("Expanded"));
    suic::ObjectPtr Collapsed = FindResource(_T("Collapsed"));

    TreeButton* pBtn = new TreeButton(Expanded, Collapsed);
    _expand = pBtn;

    _expand->SetVisible(false);

    pBtn->Expanded.Add(this, &TreeViewItem::OnExpanded);
    pBtn->Collapsed.Add(this, &TreeViewItem::OnCollapsed);

    SetWidth(suic::NonInt);
    SetHeight(suic::NonInt);

    SetMinHeight(16);

    TreeItemHeaderPtr itemHead(_header);

    itemHead->SetStyle(FindResource(itemHead->GetClassName()));

    SetText(_T(""));

    _check.SetStyle(FindResource(_check.GetClassName()));
    _check.BeginInit();
    _check.EndInit();
}

void TreeViewItem::OnStyleUpdated()
{
    if (_expand)
    {
        _expand->UpdateStyle();
    }

    _check.UpdateStyle();
}

void TreeViewItem::OnRender(suic::DrawingContext * drawing)
{
    TreeItemHeaderPtr itemHead(_header);
    int count = GetVisualChildrenCount();

    // ��������������
    if (_showDotLine)
    {
        ;
    }
}

suic::Size TreeViewItem::MeasureOverride(const suic::Size& availableSize)
{
    _expand->Measure(availableSize);
    _check.Measure(availableSize);

    suic::Size retSize;
    
    if (!IsCollapsed())
    {
        retSize = __super::MeasureOverride(availableSize);
    }

    retSize.cy += GetPadding().top;
    retSize.cy += GetPadding().bottom;
    retSize.cx += GetIndent();

    return retSize;
}

suic::Size TreeViewItem::ArrangeOverride(const suic::Size& finalSize)
{
    // ��������ӽڵ�
    ClearVisualChildren();

    const int ITEMSPACE = 2;

    suic::Rect finalRect(0, 0, finalSize.cx, 0);

    // ������չ��ť
    if (_expand->IsVisible())
    {
        finalRect.right = finalRect.left + _expand->GetDesiredSize().cx;
        finalRect.top = (_header->GetDesiredSize().cy - _expand->GetDesiredSize().cy) / 2;
        finalRect.bottom = finalRect.top + _expand->GetDesiredSize().cy;

        AddVisualChild(_expand.get());
        _expand->Arrange(finalRect);

        finalRect.left = finalRect.right + 12;
    }

    // ����ѡ��ť
    if (_check.IsVisible())
    {
        finalRect.right = finalRect.left + _check.GetDesiredSize().cx;
        finalRect.top = (_header->GetDesiredSize().cy - _check.GetDesiredSize().cy) / 2;
        finalRect.bottom = finalRect.top + _check.GetDesiredSize().cy;

        AddVisualChild(&_check);
        _check.Arrange(finalRect);

        finalRect.left = finalRect.right;
    }

    if (_icon.IsValid())
    {
        // ����ͼ��

        finalRect.right = finalRect.left + _icon.GetSource()->Width();
        finalRect.bottom = _icon.GetSource()->Height();

        AddVisualChild(&_icon);
        _icon.Arrange(finalRect);

        finalRect.left = finalRect.right + 8;
    }

    finalRect.right = finalRect.left + _header->GetDesiredSize().cx;
    finalRect.top = 0;
    finalRect.bottom = _header->GetDesiredSize().cy;

    AddVisualChild(_header.get());
    _header->Arrange(finalRect);

    finalRect.top = finalRect.bottom;
    finalRect.left = GetIndent();

    if (!IsCollapsed())
    {
        for (int i = 0; i < GetItems()->GetCount(); ++i)
        {
            TreeViewItemPtr item(GetItems()->GetItem(i));

            finalRect.right = finalRect.left + item->GetDesiredSize().cx;
            finalRect.bottom = finalRect.top + item->GetDesiredSize().cy;

            AddVisualChild(item.get());
            item->Arrange(finalRect);

            finalRect.top = finalRect.bottom;
        }
    }

    return finalSize;
}

void TreeViewItem::OnMouseLeftButtonDown(suic::MouseEventArg& e)
{
    suic::Element::OnMouseLeftButtonDown(e);
    suic::ElementPtr pHeader = suic::ElementPtr::cast(GetHeader());

    if (!e.Handled())
    {
        suic::Rect rect = suic::VisualHelper::GetRenderRect(pHeader);
        e.Handled(true);

        if (rect.PointIn(e.MousePoint()))
        {
            Select();
        }
    }
}

void TreeViewItem::OnGotFocus(suic::FocusEventArg& e)
{
    return __super::OnGotFocus(e);

    e.Handled(true);
}

void TreeViewItem::OnLostFocus(suic::FocusEventArg& e)
{
}

void TreeViewItem::OnItemsChanged(suic::NotifyCollectionChangedArg& e)
{
    __super::OnItemsChanged(e);

    if (e.GetAction() == suic::NotifyCollectionChangedAction::Add)
    {
        for (int i = 0; i < e.NewItems()->GetCount(); ++i)
        {
            TreeViewItemPtr itemPtr(e.NewItems()->GetAt(i));

            if (itemPtr)
            {
                itemPtr->ItemSelected = ItemSelected;
                itemPtr->ItemUnselected = ItemUnselected;
            }
        }
    }
}

void TreeViewItem::OnStateChanged(suic::StateChangedEventArg& e)
{
    if (e.GetType() == CoreFlags::IsSelected)
    {
        suic::ElementPtr pHeader = suic::ElementPtr::cast(GetHeader());

        if (pHeader)
        {
            pHeader->WriteFlag(e.GetType(), e.GetValue());
        }
    }
}

void TreeViewItem::OnExpanded()
{
    WriteFlag(CoreFlags::IsCollapsed, false);

    TreeView* pTree = GetParentTreeView(this);

    pTree->UpdateLayout();
}

void TreeViewItem::OnCollapsed()
{
    //
    // ȡ��������ָ��
    //
    TreeView* pTree = GetParentTreeView(this);


    WriteFlag(CoreFlags::IsCollapsed, true);

    TreeViewItemPtr selPtr(pTree->SelectedItem());

    //
    // ����Լ�������ѡ���ˣ�ȡ����ѡ�б��ڵ�
    //
    if (selPtr && selPtr.get() != this)
    {
        selPtr->Unselect();
        Select();
    }

    if (pTree)
    {
        pTree->UpdateLayout();
    }
}

void TreeViewItem::OnSelected(suic::RoutedEventArg& e)
{
    if (ItemSelected)
    {
        ItemSelected(this);
    }
}

void TreeViewItem::OnUnselected(suic::RoutedEventArg& e)
{
    if (ItemUnselected)
    {
        ItemUnselected(this);
    }
}

};
