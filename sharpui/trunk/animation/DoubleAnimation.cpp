// ======================================================================
//
// Copyright (c) 2008-2012 ����, Inc. All rights reserved.
//
// Sharpui��Դ����ѭCPLЭ����п�Դ���κθ��˻������ڴ�Э���Ͽ�������ʹ�á�
//
// ======================================================================

#include <animation/DoubleAnimation.h>

namespace ui
{

DoubleAnimation::DoubleAnimation(suic::String property, bool bRelayout)
    : _dFrom(0)
    , _dTo(1)
    , _bReverse(false)
    , suic::PropertyAnimation(property)
{
    SetRelayout(bRelayout);
}

DoubleAnimation::DoubleAnimation(suic::String property, double dFrom, double dTo, bool bRelayout)
    : _dFrom(dFrom)
    , _dTo(dTo)
    , _bReverse(false)
    , suic::PropertyAnimation(property)
{
    SetRelayout(bRelayout);
}

DoubleAnimation::~DoubleAnimation()
{

}

void DoubleAnimation::OnMeasure(suic::FrameworkElement* pElem)
{
    if (_isEndOf)
    {
        return;
    }

    suic::String strVal;
    double dValue = GetCurrentValue();

    strVal.Format(_T("%lf"), dValue);

    pElem->SetValue(_property, new suic::UString(strVal));

    if (GetRelayout())
    {
        if (pElem->GetParent())
        {
            pElem->GetParent()->UpdateLayout();
        }
        else
        {
            pElem->UpdateLayout();
        }
    }
    else
    {
        pElem->InvalidateVisual();
    }
}

double DoubleAnimation::GetCurrentValue()
{
    if (_isEndOf)
    {
        return 0;
    }

    double dDiff = (_dTo - _dFrom) * GetSpeedRatio() / GetDuration();

    if (_bReverse)
    {
        _dCurrent -= dDiff;

        if ((dDiff > 0 && _dCurrent <= _dFrom) 
            || (dDiff < 0 && _dCurrent >= _dFrom))
        {
            _dCurrent = _dFrom;
            _isEndOf = true;
        }
    }
    else
    {
        _dCurrent += dDiff;

        if ((dDiff > 0 && _dCurrent >= _dTo) 
            || (dDiff < 0 && _dCurrent <= _dTo))
        {
            _dCurrent = _dTo;

            if (GetAutoReverse())
            {
                _bReverse = true;
            }
            else
            {
                _isEndOf = true;
            }
        }
    }

    return _dCurrent;
}

void DoubleAnimation::OnStart(suic::FrameworkElement* pElem)
{
    __super::OnStart(pElem);

    _bReverse = false;
    _dCurrent = _dFrom + (_dTo - _dFrom) * GetSpeedRatio() / GetDuration();

    suic::String strVal;

    strVal.Format(_T("%lf"), _dFrom);
    pElem->SetValue(_property, new suic::UString(strVal));

    if (pElem->GetParent() && GetRelayout())
    {
        pElem->GetParent()->UpdateLayout();
    }
    else
    {
        pElem->InvalidateVisual();
    }
}

void DoubleAnimation::OnEnd(suic::FrameworkElement* pElem)
{
    __super::OnEnd(pElem);

    suic::String strVal;

    if (!_bReverse)
    {
        strVal.Format(_T("%lf"), _dTo);
    }
    else
    {
        strVal.Format(_T("%lf"), _dFrom);
    }

    pElem->SetValue(_property, new suic::UString(strVal));

    if (pElem->GetParent() && GetRelayout())
    {
        pElem->GetParent()->UpdateLayout();
    }
    else
    {
        pElem->InvalidateVisual();
    }
}

double DoubleAnimation::GetFrom() const
{
    return _dFrom;
}

void DoubleAnimation::SetFrom(double val)
{
    _dFrom = val;
}

double DoubleAnimation::GetTo() const
{
    return _dTo;
}

void DoubleAnimation::SetTo(double val)
{
    _dTo = val;
}

}
