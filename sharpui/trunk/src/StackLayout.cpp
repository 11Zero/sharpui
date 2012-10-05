// ======================================================================
//
// Copyright (c) 2008-2012 ����, Inc. All rights reserved.
//
// Sharpui��Դ����ѭCPLЭ����п�Դ���κθ��˻������ڴ�Э���Ͽ�������ʹ�á�
//
// ======================================================================

//////////////////////////////////////////////////////////////////////////////
// StackLayout.cpp

#include <sui/StackLayout.h>
#include <util/vector.h>

namespace ui
{

StackLayout::StackLayout()
{
    SetClassName(_T("StackLayout"));
}

StackLayout::StackLayout(bool bHorz)
{
    SetOrientation(CoreFlags::Horizontal);;

    SetClassName(_T("StackLayout"));
}

StackLayout::~StackLayout()
{
}

void StackLayout::OnRender(suic::DrawingContext * drawing)
{
    __super::OnRender(drawing);
}

suic::Size StackLayout::MeasureOverride(const suic::Size& availableSize)
{
    return __super::MeasureOverride(availableSize);    
}

suic::Size StackLayout::ArrangeOverride(const suic::Size& size)
{
    ClearVisualChildren();

    // 
    // ˮƽ����
    //
    if (GetOrientation() == CoreFlags::Horizontal)
    {
        RelayoutHorizontal(size);
    }
    else
    {
        RelayoutVertical(size);
    }

    return size;
}

typedef struct tagCalcuItem
{
public:

    suic::Rect rect;
    int index;

    tagCalcuItem() {}
    ~tagCalcuItem() {}
}CalcuItem;

void StackLayout::RelayoutHorizontal(const suic::Size& size)
{
    suic::Rect rcLay(0, 0, size.cx, size.cy);

    rcLay.Deflate(GetPadding());

    int nLeft = rcLay.left;
    int nRight = nLeft;
    
    int iCount = GetLogicalChildrenCount();

    for (int i = 0; i < iCount; ++i)
    {
        suic::FrameworkElementPtr ePtr(GetLogicalChild(i));

        if (ePtr->IsVisible())
        {
            suic::Rect & rcpad = ePtr->GetPadding();

            if (ePtr->GetHorizontalAlignment() == CoreFlags::Stretch)
            {
                suic::FrameworkElementPtr eStretch = ePtr;

                int iBeg = rcLay.left;
                int iEnd = iBeg;
                int in = i + 1;

                suic::Vector<CalcuItem> vecrc;

                for (; in < iCount; ++in)
                {
                    CalcuItem item;
                    suic::Rect rcClip;

                    ePtr = suic::ElementPtr::cast(GetLogicalChild(in));

                    if (ePtr->IsVisible())
                    {
                        CalcHorzElement(ePtr, rcLay, item.rect, rcClip);

                        item.index = in;
                        vecrc.push_back(item);

                        iEnd = rcLay.left;

                        if (rcLay.left >= rcLay.right)
                        {
                            ++in;
                            break;
                        }
                    }
                }

                int iGlue = rcLay.right - iEnd;

                if (iGlue < 0)
                {
                    iGlue = 0;
                }

                for (int j = 0; j < (int)vecrc.size(); ++j)
                {
                    ePtr = suic::ElementPtr::cast(GetLogicalChild(vecrc[j].index));

                    vecrc[j].rect.left += iGlue;
                    vecrc[j].rect.right += iGlue;

                    // 
                    // ���뵽������
                    //
                    AddVisualChild(suic::VisualPtr::cast(ePtr));
                    ePtr->Arrange(vecrc[j].rect);
                }

                if (iGlue > 0)
                {
                    rcLay.left = iBeg;
                    rcLay.right = rcLay.left + iGlue;
                    suic::Rect rc = rcLay;
                    suic::Rect rcClip = rc;

                    suic::Rect rcmgr = eStretch->GetMargin();

                    int iVert = eStretch->GetVerticalAlignment();
                    suic::Size szelem = ePtr->GetDesiredSize();
                    ARRANGEVERTICALCHILDREN(iVert, rcLay, rcmgr, rc, rcClip);

                    rc.right -= rcmgr.right;
                    rc.left += rcmgr.left;

                    // 
                    // ���뵽������
                    //
                    AddVisualChild(suic::VisualPtr::cast(eStretch));
                    eStretch->Arrange(rc);
                }

                break;
            }

            suic::Rect rc;
            suic::Rect rcClip;

            CalcHorzElement(ePtr, rcLay, rc, rcClip);

            // 
            // ���뵽������
            //
            AddVisualChild(suic::VisualPtr::cast(ePtr));
            ePtr->Arrange(rc);

            if (rcLay.left >= rcLay.right)
            {
                break;
            }
        }
    }
}

void StackLayout::RelayoutVertical(const suic::Size& size)
{
    suic::Rect rcLay(0, 0, size.cx, size.cy);

    rcLay.Deflate(GetBorderThickness());

    int iTop = rcLay.top;
    int iBottom = iTop;

    int iCount = GetLogicalChildrenCount();

    for (int i = 0; i < iCount; ++i)
    {
        suic::FrameworkElementPtr ePtr(GetLogicalChild(i));

        if (ePtr->IsVisible())
        {
            suic::Rect & rcpad = ePtr->GetPadding();

            if (ePtr->GetVerticalAlignment() == CoreFlags::Stretch)
            {
                suic::FrameworkElementPtr eStretch = ePtr;

                int iBeg = rcLay.top;
                int iEnd = iBeg;
                int in = i + 1;

                suic::Vector<CalcuItem> vecrc;

                for (; in < iCount; ++in)
                {
                    suic::Rect rcClip;
                    CalcuItem item;

                    ePtr = suic::ElementPtr::cast(GetLogicalChild(in));

                    if (ePtr->IsVisible())
                    {
                        CalcVertElement(ePtr, rcLay, item.rect, rcClip);

                        item.index = in;
                        vecrc.push_back(item);

                        iEnd = rcLay.top;

                        if (rcLay.top >= rcLay.bottom)
                        {
                            ++in;
                            break;
                        }
                    }
                }

                int iGlue = rcLay.bottom - iEnd;

                if (iGlue < 0)
                {
                    iGlue = 0;
                }

                for (int j = 0; j < (int)vecrc.size(); ++j)
                {
                    ePtr = GetLogicalChild(vecrc[j].index);

                    vecrc[j].rect.top += iGlue;
                    vecrc[j].rect.bottom += iGlue;

                    // 
                    // ���뵽������
                    //
                    AddVisualChild(suic::VisualPtr::cast(ePtr));
                    ePtr->Arrange(vecrc[j].rect);
                }

                if (iGlue > 0)
                {
                    rcLay.top = iBeg;
                    rcLay.bottom = rcLay.top + iGlue;
                    suic::Rect rc = rcLay;
                    suic::Rect rcClip = rc;

                    suic::Rect rcmgr = eStretch->GetMargin();

                    int iHorz = ePtr->GetHorizontalAlignment();
                    suic::Size szelem = ePtr->GetDesiredSize();
                    ARRANGEHORIZONTALCHILDREN(iHorz, rcLay, rcmgr, rc, rcClip);

                    rc.bottom -= rcmgr.bottom;
                    rc.top += rcmgr.top;

                    // 
                    // ���뵽������
                    //
                    AddVisualChild(suic::VisualPtr::cast(eStretch));
                    eStretch->Arrange(rc);
                }

                break;
            }

            suic::Rect rc;
            suic::Rect rcClip;

            CalcVertElement(ePtr, rcLay, rc, rcClip);

            // 
            // ���뵽������
            //
            AddVisualChild(suic::VisualPtr::cast(ePtr));
            ePtr->Arrange(rc);

            if (rcLay.top >= rcLay.bottom)
            {
                break;
            }
        }
    }
}

};
