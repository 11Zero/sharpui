// ======================================================================
//
// Copyright (c) 2008-2012 ����, Inc. All rights reserved.
//
// Sharpui��Դ����ѭCPLЭ����п�Դ���κθ��˻������ڴ�Э���Ͽ�������ʹ�á�
//
// ======================================================================

//////////////////////////////////////////////////////////////////////////////
// HeaderItemsControl.cpp

#include <suicore/drawing/uirender.h>

#include <sui/HeaderItemsControl.h>
#include <sui/textblock.h>
#include <sui/Selector.h>

#include <util/vector.h>

namespace ui
{

HeaderedItemsControl::HeaderedItemsControl()
    : _indent(0)
{
    SetClassName(_T("HeaderItemsControl"));
}

HeaderedItemsControl::~HeaderedItemsControl()
{
}

suic::ElementPtr HeaderedItemsControl::GetHeader() const
{
    return _header;
}

void HeaderedItemsControl::SetHeader(suic::ElementPtr val)
{
    if (_header.get() != val.get() && val)
    {
        OnHeaderChanged(_header.get(), val.get());
    }
}

suic::String HeaderedItemsControl::GetText()
{
    suic::FrameworkElementPtr frame(_header);

    if (frame)
    {
        return frame->GetText();
    }
    else
    {
        return _T("");
    }
}

////////////////////////////////////////////////////////////////////////////////////////////
//
suic::Size HeaderedItemsControl::MeasureOverride(const suic::Size& availableSize)
{
    suic::Size retSize;

    if (_header)
    {
        _header->Measure(availableSize);

        retSize.cy = _header->GetDesiredSize().cy;
        retSize.cx = _header->GetDesiredSize().cx;
    }

    if (!IsCollapsed())
    {
        for (int i = 0; i < GetItems()->GetCount(); ++i)
        {
            suic::ElementPtr item(GetItems()->GetItem(i));

            if (item)
            {
                item->Measure(availableSize);
                retSize.cy += item->GetDesiredSize().cy;

                if (item->GetDesiredSize().cx > retSize.cx)
                {
                    retSize.cx = item->GetDesiredSize().cx;
                }
            }
        }
    }

    return retSize;
}

suic::Size HeaderedItemsControl::ArrangeOverride(const suic::Size& availableSize)
{
    ClearVisualChildren();

    suic::Rect itemrect;

    itemrect.left = GetPadding().left;
    itemrect.top = GetPadding().top;
    itemrect.right = availableSize.cx;

    if (_header)
    {
        itemrect.bottom = itemrect.top + _header->GetDesiredSize().cy;
        AddVisualChild(_header.get());
        _header->Arrange(itemrect);
        itemrect.top = itemrect.bottom;
    }

    if (!IsCollapsed())
    {
        itemrect.left += GetIndent();

        for (int i = 0; i < GetItems()->GetCount(); ++i)
        {
            suic::ElementPtr item(GetItems()->GetItem(i));

            itemrect.bottom = itemrect.top + item->GetDesiredSize().cy;
            AddVisualChild(item.get());
            item->Arrange(itemrect);
            itemrect.top = itemrect.bottom;

            if (itemrect.top > availableSize.cy)
            {
                break;
            }
        }
    }

    return availableSize;
}

void HeaderedItemsControl::OnSetterChanged(suic::SetterChangedEventArg& e)
{
    __super::OnSetterChanged(e);
}

void HeaderedItemsControl::OnInitialized()
{
    suic::ObjectPtr headerPtr = GetStyle()->GetValue(_T("Header"));

    if (headerPtr)
    {
        SetText(headerPtr->ToString());
    }
    else
    {
        SetText(_T(""));
    }

    __super::OnInitialized();
}

void HeaderedItemsControl::OnPreviewMouseLeftButtonDown(suic::MouseEventArg& e)
{
    if (GetHeader().get() == e.GetSource())
    {
        Selector::SelectItem(e.GetSource(), true);

        InvalidateVisual();
    }
}

void HeaderedItemsControl::
OnHeaderChanged(suic::Element* oldHeader, suic::Element* newHeader)
{
    _header = newHeader;
}

int HeaderedItemsControl::AddChild(suic::ObjectPtr child)
{
    suic::ElementPtr pElem(child);

    if (pElem->GetWrapper().Equals(_T("Header")))
    {
        SetHeader(child);

        return 0;
    }
    else
    {
        return __super::AddChild(child);
    }
}

void HeaderedItemsControl::OnRender(suic::DrawingContext * drawing)
{
    __super::OnRender(drawing);
}

};
