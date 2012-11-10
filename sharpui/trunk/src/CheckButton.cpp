// ======================================================================
//
// Copyright (c) 2008-2012 ����, Inc. All rights reserved.
//
// Sharpui��Դ����ѭCPLЭ����п�Դ���κθ��˻������ڴ�Э���Ͽ�������ʹ�á�
//
// ======================================================================

//////////////////////////////////////////////////////////////////////////////
// CheckButton.cpp

#include <sui/CheckButton.h>
#include <suicore/drawing/uirender.h>

namespace ui
{

CheckButton::CheckButton() 
    : _bChecked(false)
    , _bAutoSize(true)
    , _bAdjusted(false)
{
    SetClassName(_T("CheckButton"));
    SetHorizontalContentAlignment(suic::LEFT);
    SetPadding(suic::Rect(2,0,0,0));
}

CheckButton::~CheckButton()
{
}

void CheckButton::OnInitialized()
{
    // 
    // ���û�������¼��ַ�����
    //
    ButtonBase::OnInitialized();

    _bAdjusted = false;
}

void CheckButton::OnSetterChanged(suic::SetterChangedEventArg& e)
{
    //
    // ��ʼ���ؼ�������Դ
    //
    if (e.GetName().Equals(_T("AutoSize")))
    {
        if (e.GetSetter()->ToString().Equals(suic::False))
        {
            SetAutoSize(false);
        }
    }
    else
    {
        //
        // ������û����ʼ����������
        //
        __super::OnSetterChanged(e);
    }
}

void CheckButton::SetAutoSize(bool val)
{
    _bAutoSize = val;
}

bool CheckButton::GetAutoSize() const
{
    return _bAutoSize;
}

bool CheckButton::IsChecked() const
{
    return _bChecked;
}

void CheckButton::SetCheck(bool val)
{
    if (val != _bChecked)
    {
        _bChecked = val;
        CheckedEventArg evt(_bChecked);

        if (val && NULL != Checked)
        {
            TriggerEvent(Checked, evt);
        }
    }
}

void CheckButton::AutoCalcSize()
{
}

suic::Size CheckButton::MeasureOverride(const suic::Size& size)
{
    suic::Size ret;
    suic::TriggerPtr& trg = GetStyle()->GetTrigger();

    if (trg.get())
    {
        suic::ImageBrushPtr bkgnd(trg->GetValue(InternalBackgrount()));

        if (bkgnd)
        {
            suic::Size sizeImg;
            suic::Rect rectBk;

            rectBk = bkgnd->GetContentBrounds();       
            ret = suic::Render::MeasureTextSize(GetText(), trg);

            ret.cx += rectBk.Width() + 4;
            ret.cy += rectBk.Height();
        }
    }

    return ret;
}

//////////////////////////////////////////////////////////////////////////////
// CheckButton

suic::String CheckButton::InternalBackgrount()
{
    if (_bChecked)
    {
        return _T("Checked");
    }
    else
    {
        return _T("Unchecked");
    }
}

void CheckButton::OnRender(suic::DrawingContext * drawing)
{
    // 
    // �Ȼ��Ʊ���
    //
    suic::TriggerPtr trg(suic::Render::GetTriggerByStatus(this, GetStyle()));
    suic::Rect drawrect(0, 0, RenderSize().cx, RenderSize().cy);
    suic::ImageBrushPtr bkgnd(trg->GetValue(InternalBackgrount()));

    if (NULL != bkgnd)
    {
        suic::Rect rectBk = bkgnd->GetContentBrounds();

        drawrect.right = drawrect.left + rectBk.Width();
        drawrect.top += (drawrect.Height() - rectBk.Height()) / 2;
        drawrect.bottom = drawrect.top + rectBk.Height();

        bkgnd->Draw(drawing, &drawrect);
    }

    //
    // ��������
    //
    drawrect.top = 0;
    drawrect.bottom = RenderSize().cy;
    drawrect.left = drawrect.right + GetPadding().left;
    drawrect.right = RenderSize().cx;

    suic::Render::DrawText(drawing, this, GetText(), trg, &drawrect, true);
}

void CheckButton::OnKeyDown(suic::KeyEventArg& e)
{
    if (e.IsSpacePress())
    {
        if (IsFocused())
        {
            SetCheck(!_bChecked);
            e.Handled(true);
        }
    }
}

void CheckButton::OnMouseLeftButtonUp(suic::MouseEventArg& e)
{
    if (IsMouseOver())
    {
        // ����ѡ���¼�
        SetCheck(!_bChecked);
    }

    __super::OnMouseLeftButtonUp(e);
}

void CheckButton::OnMouseLeftButtonDbclk(suic::MouseEventArg& e)
{
    OnMouseLeftButtonDown(e);
}

void CheckButton::OnGotFocus(suic::FocusEventArg& e)
{
    __super::OnGotFocus(e);
    e.Handled(true);
}

void CheckButton::OnLostFocus(suic::FocusEventArg& e)
{
}

}
