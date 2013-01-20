// ======================================================================
//
// Copyright (c) 2008-2012 ����, Inc. All rights reserved.
//
// Sharpui��Դ����ѭCPLЭ����п�Դ���κθ��˻������ڴ�Э���Ͽ�������ʹ�á�
//
// ======================================================================

//////////////////////////////////////////////////////////////////////////////
// ListViewItem.cpp

#include <sui/ListViewItem.h>
#include <sui/TextBlock.h>
#include <sui/GridViewRow.h>

namespace ui
{

//////////////////////////////////////////////////////////////
// ListViewItem
//

ImplementTypeofInfo(ListViewItem, ListBoxItem)

ListViewItem::ListViewItem()
{
    SetClassName(_T("ListViewItem"));
}

ListViewItem::~ListViewItem()
{
}

suic::String ListViewItem::ToString()
{
    GridViewRowPtr row(GetContent());

    if (!row)
    {
        return GetText();
    }
    else
    {
        return row->ToString();
    }
}

suic::ElementPtr ListViewItem::GetColumn(int index)
{
    // ���������GridViewRow
    // ֱ��ȡ����
    GridViewRowPtr row(GetContent());

    if (row)
    {
        return row->GetColumn(index);
    }
    else
    {
        return GetContent();
    }
}

void ListViewItem::AddColumn(suic::String text)
{
    GridViewRowPtr row(GetContent());

    if (row)
    {
        row->AddColumn(new ui::TextBlock(text));
    }
}

void ListViewItem::AddColumn(suic::Element* elem)
{
    GridViewRowPtr row(GetContent());

    if (row)
    {
        row->AddColumn(elem);
    }
}

void ListViewItem::SetColumn(int index, suic::String text)
{
    suic::FrameworkElementPtr col(GetColumn(index));

    if (col)
    {
        col->SetText(text);
    }
}

void ListViewItem::SetColumn(int index, suic::Element* elem)
{
    GridViewRowPtr row(GetContent());

    if (row)
    {
        row->SetColumn(index, elem);
    }
}

}
