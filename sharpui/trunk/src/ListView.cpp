// ======================================================================
//
// Copyright (c) 2008-2012 ����, Inc. All rights reserved.
//
// Sharpui��Դ����ѭCPLЭ����п�Դ���κθ��˻������ڴ�Э���Ͽ�������ʹ�á�
//
// ======================================================================

//////////////////////////////////////////////////////////////////////////////
// ListView.cpp

#include <sui/listview.h>
#include <sui/textblock.h>
#include <sui/gridviewrow.h>

namespace ui
{

ListView::ListView()
{
    SetClassName(_T("ListView"));

    _header = new GridViewHeaderRow();
    suic::VisualHelper::SetLogicalParent(this, _header.get());
    _header->SetHeight(16);
    _header->Columns()->ColumnHeaderChanged += ColumnHeaderChangedHandler(this, &ListView::OnColumnHeaderChanged);

    InitializeScrollView();
}

ListView::~ListView()
{
}

void ListView::InitializeScrollView()
{
    _panel = new VisualizeHeaderPanel(_container);
    _scrollView = new ScrollViewer();

    _scrollView->SetContent(_panel);

    VisualizeHeaderPanelPtr vp(_panel);
    vp->SetHeader(_header);
}

void ListView::OnColumnHeaderResize(suic::ObjectPtr sender, DragDeltaEventArg& e)
{
    GridViewColumnPtr pColumn(sender);

    suic::Size size = _panel->GetDesiredSize();

    size.cx += e.HorizontalChange();
    
    int iNewPos = _scrollView->HorizontalScrollBar()->GetScrollPos();

    /*if (iNewPos >= _scrollView->HorizontalScrollBar()->MaxVisualPos()
        && e.HorizontalChange() < 0 && _scrollView->HorizontalScrollBar()->IsVisible())
    {
        size.cx = 10;
        pColumn->SetColumnWidth(10);
    }*/

    _panel->SetDesiredSize(size);

    /*if (e.HorizontalChange() < 0)
    {
        int iNewPos = e.HorizontalChange() + _scrollView->HorizontalScrollBar()->GetLogicPos();

        iNewPos = (int)((double)iNewPos / (double)_scrollView->HorizontalScrollBar()->GetScrollStep());

        _scrollView->HorizontalScrollBar()->SetVisualPos(iNewPos);
    }*/

    _scrollView->InvalidateArrange();

    iNewPos = _scrollView->HorizontalScrollBar()->GetScrollPos();

    _scrollView->InvalidateVisual();
}

void ListView::OnColumnHeaderChanged(GridViewColumn* pColumn, int flag)
{
    if (IsInitialized())
    {
        pColumn->ColumnHeader()->BeginInit();
        pColumn->ColumnHeader()->EndInit();

        pColumn->DragDelta += DragDeltaHandler(this, &ListView::OnColumnHeaderResize);;
    }
}

ColumnHeaderCollectionPtr& ListView::Columns()
{
    return _header->Columns();
}

int ListView::Add(suic::ObjectPtr value)
{
    ListViewItemPtr item(value);

    if (!item)
    {
        item = new ListViewItem();
        item->SetContent(value);
    }
    else
    {
        item->SetContent(new GridViewRow(Columns()));
    }

    return __super::Add(item);
}

int ListView::Insert(int index, suic::ObjectPtr value)
{
    ListViewItemPtr item(value);

    if (!item)
    {
        item = new ListViewItem();
        item->SetContent(value);
    }
    else
    {
        item->SetContent(new GridViewRow(Columns()));
    }

    return __super::Insert(index, item);
}

int ListView::AddText(const suic::String& text)
{
    ListViewItemPtr item(new ListViewItem());

    item->SetContent(new GridViewRow(Columns()));

    return __super::Add(item);
}

void ListView::SetLargeImageList()
{

}

void ListView::SetSmallImageList()
{

}

int ListView::GetHeaderStyle() const
{
    return 0;
}

void ListView::SetHeaderStyle(int iStyle)
{

}

void ListView::SetBackgroundImage(suic::ImagePtr img)
{

}

//===============================================================
//

suic::Size ListView::MeasureOverride(const suic::Size& availableSize)
{
    return __super::MeasureOverride(availableSize);
}

suic::Size ListView::ArrangeOverride(const suic::Size& availableSize)
{
    suic::Rect finalRect(0, 0, availableSize.cx, availableSize.cy);

    finalRect.Deflate(GetBorderThickness());

    _scrollView->Arrange(finalRect);

    return availableSize;
}

inline int ListView::GetMaxVisualIndex()
{
    int count = _panel->GetVisualChildrenCount();
    return (_header->IsVisible() ? (count - 1) : count);
}

void ListView::OnInitialized()
{
    __super::OnInitialized();

    // ���������
    AddVisualChild(_header.get());

    _header->SetStyle(FindResource(_T("ListViewHeader")));
    _header->BeginInit();
    _header->EndInit();

    // ��������
    Columns()->Add(_T("����"), 80);
    Columns()->Add(_T("�ݳ���"), 120);

    int index = Add(new ListViewItem());
    ListViewItemPtr item(GetItem(index));

    item->AddColumn(_T("����Ӣ��"));
    item->AddColumn(_T("�ܻ���"));

    index = Add(new ListViewItem());
    item = GetItem(index);

    Button* pBtn = new Button();

    item->AddColumn(_T("��ť����"));
    item->AddColumn(pBtn);

    pBtn->SetMinHeight(29);
}

}
