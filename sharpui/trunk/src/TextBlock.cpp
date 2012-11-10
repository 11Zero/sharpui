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
    : _single(true)
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
    suic::TriggerPtr setter(suic::Render::GetTriggerByStatus(this, GetStyle()));

    if (setter.get())
    {
        suic::Size ret = suic::Render::MeasureTextSize(GetText(), setter);

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
    // ���Ʊ���
    suic::Render::DrawBackground(drawing, this);
    suic::Render::DrawText(drawing, this, GetText(), _single);

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

void TextBlock::OnSetterChanged(suic::SetterChangedEventArg& e)
{
    if (e.GetName().Equals(_T("IsSingle")))
    {
        SetSingle(e.GetSetter()->ToBool());
    }
    else
    {
        //
        // ������û����ʼ����������
        //
        __super::OnSetterChanged(e);
    }
}

}
