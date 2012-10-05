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
#include <suicore/drawing/uirender.h>

namespace ui
{

/////////////////////////////////////////////////////////
// TextBlock

TextBlock::TextBlock()
{
    SetClassName(_T("TextBlock"));

    SetVerticalContentAlignment(suic::CENTER);
    SetHorizontalContentAlignment(suic::LEFT);
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
    suic::TriggerPtr setter(suic::UIRender::GetTriggerByStatus(this, GetStyle()));

    if (setter.get())
    {
        suic::Size ret = suic::UIRender::MeasureTextSize(GetText(), setter);

        ret.cx += 2;
        MeasureCheck(ret);

        return ret;
    }
    else
    {
        return __super::MeasureOverride(availableSize);
    }
}

void TextBlock::OnInitialized()
{
    __super::OnInitialized();
}

void TextBlock::OnRender(suic::DrawingContext * drawing)
{
    suic::Rect elemrect(0, 0, RenderSize().cx, RenderSize().cy);

    // ���Ʊ���
    //suic::UIRender::DrawBackground(drawing, GetStyle()->GetTrigger(), &elemrect);

    elemrect.Deflate(GetPadding());

    suic::UIRender::DrawText(drawing, GetText()
        , GetStyle()->GetTrigger(), &elemrect
        , GetHorizontalContentAlignment(), GetVerticalContentAlignment());

    //
    // ���ӵ�н�������ƽ�������
    //
    if (IsFocused())
    {
        suic::Rect rect(0, 0, RenderSize().cx, RenderSize().cy);

        rect.Deflate(GetBorderThickness());
        drawing->DrawFocused(&rect);
    }
}

void TextBlock::OnMouseLeftButtonDown(suic::MouseEventArg& e)
{
    Element::OnMouseLeftButtonDown(e);
}

void TextBlock::OnMouseLeftButtonUp(suic::MouseEventArg& e)
{
    Element::OnMouseLeftButtonUp(e);
}

void TextBlock::OnMouseEnter(suic::MouseEventArg& e)
{
}

void TextBlock::OnMouseMove(suic::MouseEventArg& e)
{
}

void TextBlock::OnMouseLeave(suic::MouseEventArg& e)
{
}

bool TextBlock::HandleFocus() const
{
    return false;
}

};
