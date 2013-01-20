// ======================================================================
//
// Copyright (c) 2008-2012 ����, Inc. All rights reserved.
//
// Sharpui��Դ����ѭCPLЭ����п�Դ���κθ��˻������ڴ�Э���Ͽ�������ʹ�á�
//
// ======================================================================

//////////////////////////////////////////////////////////////////////////////
// TextBlock.cpp

#include "stdafx.h"

#include <sui/TextBlock.h>
#include <suic/render/uirender.h>

namespace ui
{

/////////////////////////////////////////////////////////
// TextBlock

ImplementTypeofInfo(TextBlock, suic::FrameworkElement)

TextBlock::TextBlock()
    : _single(true)
{
    SetClassName(_T("TextBlock"));

    SetVerticalContentAlignment(VertContentAlignment::Center);
    SetHorizontalContentAlignment(HoriContentAlignment::Left);
}

TextBlock::TextBlock(suic::String text)
{
    this->TextBlock::TextBlock();
    SetText(text);
}

TextBlock::~TextBlock()
{
}

suic::Size TextBlock::MeasureOverride(const suic::Size& availableSize)
{
    suic::Size ret = suic::Render::MeasureTextSize(GetText(), GetFont());

    ret.cx += 2;
    MeasureCheck(ret);

    return ret;
}

void TextBlock::OnInitialized()
{
    __super::OnInitialized();
}

void TextBlock::OnRender(suic::DrawingContext * drawing)
{
    // ���Ʊ���
    suic::Render::RenderBackground(drawing, this);
    suic::Render::RenderText(drawing, this, GetText(), _single);

    //
    // ���ӵ�н�������ƽ�������
    //
    if (IsFocused())
    {
        suic::Rect rect(0, 0, RenderSize().cx, RenderSize().cy);

        rect.Deflate(GetBorderThickness());
        drawing->DrawFocusedRectangle(&rect);
    }
}

void TextBlock::OnPropertyChanged(suic::PropertyChangedEventArg& e)
{
    if (e.GetName().Equals(_T("TextWrapper")))
    {
        SetSingle(e.GetSetter()->ToBool());
    }
    else
    {
        //
        // ������û����ʼ����������
        //
        __super::OnPropertyChanged(e);
    }
}

}
