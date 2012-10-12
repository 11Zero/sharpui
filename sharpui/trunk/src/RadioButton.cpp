// ======================================================================
//
// Copyright (c) 2008-2012 ����, Inc. All rights reserved.
//
// Sharpui��Դ����ѭCPLЭ����п�Դ���κθ��˻������ڴ�Э���Ͽ�������ʹ�á�
//
// ======================================================================

//////////////////////////////////////////////////////////////////////////////
// RadioButton.cpp

#include <sui/RadioButton.h>
#include <suicore/drawing/uirender.h>
#include <internal/RadioGroupManager.h>

namespace ui
{

RadioButton::RadioButton()
{
    SetClassName(_T("RadioButton"));
}

RadioButton::~RadioButton()
{
}

static suic::String g_sr_key = _T("sharpui.radiogrp");

static RadioGroupManager* GetRadioGroupManager(suic::Element* pElem)
{
    suic::VisualHostPtr hostObj = suic::HwndHelper::GetVisualHost(pElem);

    if (!hostObj)
    {
        return NULL;
    }
    else
    {
        suic::ObjectPtr objGrp = hostObj->GetValue(g_sr_key);

        if (!objGrp)
        {
            return NULL;
        }
        else
        {
            return dynamic_cast<RadioGroupManager*>(objGrp.get());
        }
    }
}

void RadioButton::SetGroup(const suic::String & name)
{
    if (!_sGrpName.Equals(name))
    {
        RadioButtonPtr thisPtr(this);
        RadioGroupManager * radioGrp = GetRadioGroupManager(this);

        if (radioGrp)
        {
            radioGrp->RemoveRadioFromGroup(thisPtr);
            _sGrpName = name;
            radioGrp->CheckGroupElement(thisPtr);
        }
        else
        {
            _sGrpName = name;
        }
    }
}

suic::String RadioButton::GetGroup()
{
    return _sGrpName;
}

void RadioButton::SetCheck()
{
    // û�г�ʼ����ֱ�ӷ���
    if (!IsInitialized())
    {
        return;
    }

    if (!_bChecked)
    {
        bool bAuto = SetAutoDelete(false);

        RadioGroupManager * radioGrp = GetRadioGroupManager(this);
        RadioButtonPtr rdPtr;

        if (radioGrp)
        {
            rdPtr = radioGrp->LookupCheckedRadioFromGroup(_sGrpName);

            suic::SystemHelper::Trace(_T("radioGrp->LookupCheckedRadioFromGroup(_sGrpName)\n"));
        }

        // ȡ�������Ѿ���ѡ�еĿؼ�
        if (NULL != rdPtr)
        {
            rdPtr->SetUncheck();
        }

        _bChecked = true;

        // ����һ�λ���
        InvalidateVisual();

        CheckedEventArg evt(_bChecked);

        if (NULL != Checked)
        {
            TriggerEvent(Checked,evt);
        }

        SetAutoDelete(bAuto);
    }
    else
    {
        InvalidateVisual();
    }
}

void RadioButton::SetUncheck()
{
    // û�г�ʼ����ֱ�ӷ���
    if (!IsInitialized())
    {
        return;
    }

    if (_bChecked)
    {
        bool bAuto = SetAutoDelete(false);

        _bChecked = false;

        // ����һ�λ���
        InvalidateVisual();

        CheckedEventArg evt(_bChecked);

        if (NULL != Checked)
        {
            TriggerEvent(Checked,evt);
        }

        SetAutoDelete(bAuto);
    }
}

//////////////////////////////////////////////////////////////////////////////
// RadioButton
//
void RadioButton::OnSetterChanged(suic::SetterChangedEventArg& e)
{
    //
    // ��ʼ���ؼ�������Դ
    //
    if (e.GetName().Equals(_T("Group")))
    {
        SetGroup(e.GetSetter()->ToString());
    }
    else
    {
        //
        // �����ȵ��û����ʼ����������
        //
        __super::OnSetterChanged(e);
    }
}

void RadioButton::OnRender(suic::DrawingContext * drawing)
{
    __super::OnRender(drawing);
}

void RadioButton::OnLoaded(suic::LoadedEventArg& e)
{
    suic::VisualHostPtr hostObj = suic::VisualHostPtr::cast(e.GetTarget());
    suic::ObjectPtr objGrp = hostObj->GetValue(g_sr_key);

    if (!objGrp)
    {
        objGrp = new RadioGroupManager();
        hostObj->SetValue(g_sr_key, objGrp);
    }

    RadioGroupManager * radioGrp = dynamic_cast<RadioGroupManager*>(objGrp.get());

    if (radioGrp)
    {
        ui::RadioButtonPtr thisPtr(this);

        radioGrp->CheckGroupElement(thisPtr);
    }

    __super::OnLoaded(e);
}

void RadioButton::OnKeyDown(suic::KeyEventArg& e)
{
    if (e.IsSpacePress())
    {
        if (IsFocused())
        {
            SetCheck();

            e.Handled(true);
        }
    }
}


void RadioButton::OnMouseLeftButtonUp(suic::MouseEventArg& e)
{
    ButtonBase::OnMouseLeftButtonUp(e);

    if (IsMouseOver())
    {
        SetCheck();
    }
    else
    {
        InvalidateVisual();
    }
}

void RadioButton::OnMouseLeftButtonDbclk(suic::MouseEventArg& e)
{
    OnMouseLeftButtonDown(e);
}

void RadioButton::OnGotFocus(suic::FocusEventArg& e)
{
    __super::OnGotFocus(e);
}

void RadioButton::OnLostFocus(suic::FocusEventArg& e)
{
}

};