// ======================================================================
//
// Copyright (c) 2008-2012 ����, Inc. All rights reserved.
//
// Sharpui��Դ����ѭCPLЭ����п�Դ���κθ��˻������ڴ�Э���Ͽ�������ʹ�á�
//
// ======================================================================

//////////////////////////////////////////////////////////////////////////////
// GridViewHeaderRow.cpp

#include <sui/GridViewHeaderRow.h>

namespace ui
{

//////////////////////////////////////////////////////////////
// GridViewHeaderRow
//
GridViewHeaderRow::GridViewHeaderRow()
{
    SetClassName(_T("GridViewHeaderRow"));

    _colomns = new ColumnHeaderCollection();
}

GridViewHeaderRow::~GridViewHeaderRow()
{
}

ColumnHeaderCollectionPtr& GridViewHeaderRow::Columns()
{
    return _colomns;
}

int GridViewHeaderRow::GetColumnCount() const
{
    return _colomns->GetCount();
}

GridViewColumn* GridViewHeaderRow::GetColumn(int index)
{
    return _colomns->GetColumn(index);
}

suic::Size GridViewHeaderRow::MeasureOverride(const suic::Size& availableSize)
{
    int iColumnHei = 0;
    int iColumnWid = 0;

    for (int i = 0; i < GetColumnCount(); ++i)
    {
        GridViewColumn* pColumn = GetColumn(i);

        pColumn->ColumnHeader()->Measure(availableSize);

        if (pColumn->ColumnHeader()->GetDesiredSize().cy > iColumnHei)
        {
            iColumnHei = pColumn->ColumnHeader()->GetDesiredSize().cy;
        }

        iColumnWid += pColumn->GetColumnWidth();
    }

    return suic::Size(iColumnWid, iColumnHei);
}

suic::Size GridViewHeaderRow::ArrangeOverride(const suic::Size& size)
{
    ClearVisualChildren();

    suic::Rect finalRect(0, 0, size.cx, size.cy);

    for (int i = 0; i < GetColumnCount(); ++i)
    {
        GridViewColumn* pColumn = GetColumn(i);
        GridSplitter* pHeader = pColumn->ColumnHeader()->HeaderGripper();

        finalRect.right = finalRect.left + pColumn->GetColumnWidth();

        AddVisualChild(pColumn->ColumnHeader());
        pColumn->ColumnHeader()->Arrange(finalRect);

        finalRect.left = finalRect.right;
        finalRect.right += pHeader->GetDesiredSize().cx;

        AddVisualChild(pHeader);
        pHeader->Arrange(finalRect);

        finalRect.left = finalRect.right;
    }

    return size;
}

void GridViewHeaderRow::OnInitialized()
{
    __super::OnInitialized();
}

void GridViewHeaderRow::OnRender(suic::DrawingContext * drawing)
{
    suic::Rect drawrect(0, 0, RenderSize().cx, RenderSize().cy);

    // 
    // �Ȼ��Ʊ���
    //
    suic::Render::DrawBackground(drawing, GetStyle()->GetTrigger(), &drawrect);
}

};
