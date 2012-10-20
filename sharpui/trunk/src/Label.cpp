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
#include <suicore/drawing/uirender.h>

namespace ui
{

/////////////////////////////////////////////////////////
// Label

Label::Label()
{
    SetClassName(_T("Label"));

    SetVerticalContentAlignment(suic::CENTER);
    SetHorizontalContentAlignment(suic::LEFT);
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
    suic::Render::DrawBackground(drawing, GetStyle()->GetTrigger(), &drawrect);
}

}
