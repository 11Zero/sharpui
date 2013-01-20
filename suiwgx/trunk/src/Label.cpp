// ======================================================================
//
// Copyright (c) 2008-2012 ����, Inc. All rights reserved.
//
// Sharpui��Դ����ѭCPLЭ����п�Դ���κθ��˻������ڴ�Э���Ͽ�������ʹ�á�
//
// ======================================================================

//////////////////////////////////////////////////////////////////////////////
// Label.cpp

#include "stdafx.h"

#include <sui/Label.h>
#include <suic/render/uirender.h>

namespace ui
{

/////////////////////////////////////////////////////////
// Label

ImplementTypeofInfo(Label, suic::ContentControl)

Label::Label()
{
    SetClassName(_T("Label"));

    SetVerticalContentAlignment(VertContentAlignment::Center);
    SetHorizontalContentAlignment(HoriContentAlignment::Left);
}

Label::Label(suic::String text)
{
    this->Label::Label();
    SetText(text);
}

Label::~Label()
{
}

suic::Size Label::MeasureOverride(const suic::Size& availableSize)
{
    return __super::MeasureOverride(availableSize);
}

void Label::OnInitialized()
{
    __super::OnInitialized();
}

void Label::OnRender(suic::DrawingContext * drawing)
{
    suic::Rect drawrect(0, 0, RenderSize().cx, RenderSize().cy);

    // 
    // �Ȼ��Ʊ���
    //
    suic::Render::RenderBackground(drawing, this, &drawrect);
    suic::Render::RenderText(drawing, this, GetText(), true);
}

}
