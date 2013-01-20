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
#include <suic/render/uirender.h>

namespace ui
{

ImplementTypeofInfo(CheckButton, ButtonBase)

CheckButton::CheckButton() 
    : _bChecked(false)
    , _bAutoSize(true)
    , _bAdjusted(false)
{
    SetClassName(_T("CheckButton"));
    SetHorizontalContentAlignment(HoriAlignment::Left);
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

void CheckButton::OnPropertyChanged(suic::PropertyChangedEventArg& e)
{
    //
    // ��ʼ���ؼ�������Դ
    //
    if (e.GetName().Equals(_T("AutoSize")))
    {
        if (e.GetSetter()->ToString().Equals(_T("False")))
        {
            SetAutoSize(false);
        }
    }
    else
    {
        //
        // ������û����ʼ����������
        //
        __super::OnPropertyChanged(e);
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
            //TriggerEvent(Checked, evt);
        }
    }
}

void CheckButton::AutoCalcSize()
{
}

suic::Size CheckButton::MeasureOverride(const suic::Size& size)
{
    suic::Size ret;

    if (GetStyle())
    {
        suic::SetterCollectionPtr& setPtr = GetStyle()->Setters();
        suic::ImageBrushPtr bkgnd(setPtr->GetValue(InternalBackgrount()));

        if (bkgnd)
        {
            suic::Size sizeImg;
            suic::Rect rectBk;

            rectBk = bkgnd->GetContentBrounds();       
            ret = suic::Render::MeasureTextSize(GetText(), GetFont());

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
    if (GetStyle())
    {
        // 
        // �Ȼ��Ʊ���
        //
        suic::Rect drawrect(0, 0, RenderSize().cx, RenderSize().cy);
        suic::ImageBrushPtr bkgnd(suic::Render::GetProperty(this, GetStyle().get(), InternalBackgrount()));

        if (bkgnd)
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

        suic::Render::RenderText(drawing, this, GetText(), &drawrect, true);
    }
}

void CheckButton::OnKeyDown(suic::KeyboardEventArg& e)
{
    if (e.IsSpacePress())
    {
        if (IsFocused())
        {
            SetCheck(!_bChecked);
            e.SetHandled(true);
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
    e.SetHandled(true);
}

void CheckButton::OnLostFocus(suic::FocusEventArg& e)
{
}

}
