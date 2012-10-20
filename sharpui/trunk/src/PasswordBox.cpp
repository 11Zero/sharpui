// ======================================================================
//
// Copyright (c) 2008-2012 ����, Inc. All rights reserved.
//
// Sharpui��Դ����ѭCPLЭ����п�Դ���κθ��˻������ڴ�Э���Ͽ�������ʹ�á�
//
// ======================================================================

//////////////////////////////////////////////////////////////////////////////
// PasswordBox.cpp

#include <sui/PasswordBox.h>
#include <sui/WindowHelper.h>
#include <suicore/drawing/uirender.h>

namespace ui
{

///////////////////////////////////////////////////////////////////////////////////
// PasswordBox
PasswordBox::PasswordBox()
    : _passwordChar('*')
    , _startSel(0)
    , _selCount(0)
    , _caretPos(0)
    , _horizontalOffset(0)
{
    SetClassName(_T("PasswordBox"));
}

PasswordBox::~PasswordBox()
{
}

void PasswordBox::Cut()
{
    if (InSelectMode())
    {
        // �ȿ������ڴ�
        Copy();

        _password.Remove(_startSel, _selCount);

        InvalidateVisual();
        ResetCaretPos();
    }
}

void PasswordBox::Copy()
{
    if (InSelectMode())
    {
        ui::WndHelper helper(this);
        helper.HideCaret();

        if (!helper.OpenClipboard())
        {
            return;
        }

        suic::String strSel = _password.Substring(_startSel, _selCount);

        helper.CopyText(strSel);
        helper.CloseClipboard();
    }
}

void PasswordBox::Paste()
{
    ui::WndHelper helper(this);

    if (!helper.OpenClipboard()) 
    {
        return;
    }

    suic::String text;
    helper.PasteText(text);

    _password.Insert(_caretPos, text);

    helper.CloseClipboard();

    InvalidateVisual();
    ResetCaretPos();
}

void PasswordBox::SelectAll()
{
    WndHelper(this).HideCaret();

    _startSel = 0;
    _selCount = _password.Length() - _startSel;
    _caretPos = _selCount;
    InternalSetCaret(0);

    InvalidateVisual();
    ResetCaretPos();
}

suic::String PasswordBox::GetText()
{
    suic::String text;

    return text;
}

void PasswordBox::SetText(const suic::String & text)
{
    _password = text;
    _caretPos = _password.Length();
    InternalSetCaret(0);
}

void PasswordBox::OnRender(suic::DrawingContext * drawing)
{
    suic::TriggerPtr setter(suic::Render::GetTriggerByStatus(this, GetStyle()));        
    suic::Rect rcdraw(0, 0, RenderSize().cx, RenderSize().cy);

    // ����䱳��
    suic::Render::DrawBackground(drawing, setter, &rcdraw);

    // �����ı�

    suic::Color clrText(ARGB(255,0,0,0));
    suic::ObjectPtr oValue = setter->GetValue(suic::FOREGROUND);

    if (oValue)
    {
        clrText = oValue->ToColor();
    }

    if (_password.Length() > 0)
    {
        suic::FormattedText att;
        suic::Size sizeChar(suic::Render::MeasureTextSize(suic::String(_passwordChar, 1), GetStyle()->GetTrigger()));

        suic::String text(_passwordChar, _password.Length());
        suic::Rect rcCtrl = rcdraw;
        rcCtrl.Deflate(GetBorderThickness());
        rcCtrl.Deflate(GetPadding());

        drawing->PushClip(&rcCtrl);

        rcCtrl.left -= _horizontalOffset * sizeChar.cx;

        if (InSelectMode())
        {
            suic::String strDraw;
            int iRight = rcCtrl.right;
            int iStart = 0;
            int iCount = 0;

            GetSelectRange(iStart, iCount);

            if (iStart > 0)
            {
                strDraw = suic::String(_passwordChar, iStart);
                rcCtrl.right = rcCtrl.left + sizeChar.cx * iStart;

                suic::Render::DrawText(drawing, this, strDraw, setter, &rcCtrl);

                rcCtrl.left = rcCtrl.right;
            }

            strDraw = suic::String(_passwordChar, iCount);
            rcCtrl.right = rcCtrl.left + sizeChar.cx * iCount;

            att.bkcolor = ARGB(255,100,120,120);

            drawing->DrawText(strDraw.c_str(), strDraw.Length(), &rcCtrl, &att);

            if (iStart + iCount < _password.Length() && rcCtrl.right < iRight)
            {
                iCount = _password.Length() - iStart - iCount;

                strDraw = suic::String(_passwordChar, iCount);
                rcCtrl.left = rcCtrl.right;
                rcCtrl.right += sizeChar.cx * iCount;

                suic::Render::DrawText(drawing, this, strDraw, setter, &rcCtrl);
            }
        }
        else
        {
            suic::String strDraw(_passwordChar, _password.Length());

            suic::Render::DrawText(drawing, this, strDraw, setter, &rcCtrl);
        }

        drawing->Pop();
    }

    suic::Render::DrawBorderBrush(drawing, setter, &rcdraw);
}

bool PasswordBox::InSelectMode() const
{
    return (_selCount != 0);
}

void PasswordBox::CancelSelectMode()
{
    _startSel = 0;
    _selCount = 0;
}

void PasswordBox::DeleteSelection()
{
    if (InSelectMode())
    {
        int iStart = 0;
        int iCount = 0;

        GetSelectRange(iStart, iCount);

        _password.Remove(iStart, iCount);

        if (_selCount > 0)
        {
            _caretPos -= _selCount;
        }

        CancelSelectMode();

        if (_caretPos <= 0)
        {
            _caretPos = 0;
        }

        InternalSetCaret(0);
    }
}

void PasswordBox::GetSelectRange(int& iStart, int& iCount)
{
    iStart = _startSel;
    iCount = _selCount;

    if (_selCount < 0)
    {
        iStart = _startSel + _selCount;
        iCount = -_selCount;
    }
}

void PasswordBox::ResetCaretPos()
{
    ui::WndHelper helper(this);

    helper.HideCaret();

    suic::Size size(suic::Render::MeasureTextSize(suic::String(_passwordChar, 1), GetStyle()->GetTrigger()));
    suic::Point pt = PointToScreen(suic::Point());
    suic::Rect rc(GetVisualOffset().x, GetVisualOffset().y
        , RenderSize().cx, RenderSize().cy);

    int iCaretPos = (_caretPos - _horizontalOffset) * size.cx 
        + GetBorderThickness().left + GetPadding().left;
    suic::Rect rcCaret(iCaretPos, 0, 1, RenderSize().cy);

    rcCaret.top = (RenderSize().cy - size.cy) / 2;
    rcCaret.bottom = rcCaret.top + size.cy;

    rcCaret.Offset(pt.x, pt.y);

    //
    // ȥ�������ڲü�����
    //
    suic::Element* pParent = GetParent();

    while (pParent)
    {
        suic::Rect tmp = suic::VisualHelper::GetRenderRect(pParent);

        rcCaret.Intersect(&tmp);
        pParent = pParent->GetParent();
    }

    rcCaret.Offset(-pt.x, -pt.y);

    helper.CreateSolidCaret(1, rcCaret.Height());
    helper.SetCaretPos(rcCaret.left, rcCaret.top);
    helper.ShowCaret();
}

int PasswordBox::CalcCaretPos(int xOffset)
{
    xOffset -= PointToScreen(suic::Point()).x;
    xOffset -= GetBorderThickness().left;
    xOffset -= GetPadding().left;

    if (xOffset <= 0)
    {
        return 0;
    }

    if (_password.Length() == 0) 
    {
        return 0;
    }

    suic::String strChar(_passwordChar, 1);
    int iPos = 0;
    suic::Size size(suic::Render::MeasureTextSize(strChar, GetStyle()->GetTrigger()));

    iPos = (int)((double)xOffset / (double)size.cx) + _horizontalOffset;

    if (iPos >= (int)_password.Length())
    {
        iPos = (int)_password.Length();
    }

    return iPos;
}

void PasswordBox::InternalSetCaret(int iOff)
{
    _caretPos += iOff;

    suic::String strChar(_passwordChar, 1);
    suic::Size size(suic::Render::MeasureTextSize(strChar, GetStyle()->GetTrigger()));
    int iSize = RenderSize().cx - GetPadding().left - GetPadding().right
        - GetBorderThickness().left - GetBorderThickness().right;
    // �������λ��
    int iCaretPos = (_caretPos - _horizontalOffset) * size.cx;

    if (iCaretPos > iSize)
    {
        _horizontalOffset = _caretPos - ((double)iSize / (double)size.cx);
    }
    else if (_caretPos < _horizontalOffset)
    {
        _horizontalOffset = _caretPos;
    }
}

void PasswordBox::OnTextInput(suic::KeyEventArg& e)
{
    int ch = e.GetKey();
    int code = e.State();

    union wcharfmt
    {
        suic::Char w;
        suic::Byte asc[2];
    };

    static bool bUnicode = false;
    static wcharfmt wf;

    suic::Byte nChar = (suic::Byte)ch;

    // ����һ��˫�ֽڵı���
    if (ch >= 0x80)
    {
    }
    // ����ascii�룬ע����������Ƕ��ֽڵ�һ����
    else if (nChar >= 0x80)
    {
        bUnicode = true;
        wf.asc[0] = nChar;
    }
    else
    {
        if (bUnicode)
        {
            wf.asc[1] = nChar;
        }
        else
        {
            // ɾ����
            if (VK_BACK == nChar)
            {
                if (InSelectMode())
                {
                    DeleteSelection();
                }
                // ɾ��һ���ַ�
                else if (_caretPos > 0)
                {
                    _password.Remove(_caretPos - 1, 1);
                    InternalSetCaret(-1);
                }
            }
            else if (nChar >= 32 && nChar <= 126)
            {
                bool bCtrl = (code & MK_CONTROL) == MK_CONTROL;
                
                if (!bCtrl)
                {
                    DeleteSelection();
                    _password.Insert(_caretPos, suic::String(ch, 1));
                    InternalSetCaret(1);
                }
                else if (nChar == 'v' || 
                    nChar == 'V')
                {
                    // paste(ճ��)
                    Paste();
                }
            }
        }

        bUnicode = false;
    }

    InvalidateVisual();
    // �������ù��λ��
    ResetCaretPos();
}

void PasswordBox::OnKeyDown(suic::KeyEventArg& e)
{
    WndHelper(this).HideCaret();

    e.Handled(true);

    int state = e.State();
    int ch = e.GetKey();

    bool bShift = (state & MK_SHIFT) == MK_SHIFT;
    bool bCtrl = (state & MK_CONTROL) == MK_CONTROL;

    bool bValid = true;
    bool bUpDown = false;
    bool bSel = InSelectMode();

    if (VK_LEFT == ch)
    {
        CancelSelectMode();

        // �����ƶ�һ�����
        if (_caretPos > 0)
        {
            InternalSetCaret(-1);
        }
    }
    else if (VK_RIGHT == ch)
    {
        CancelSelectMode();

        // �����ƶ�һ�����
        if (_caretPos < _password.Length())
        {
            InternalSetCaret(1);
        }
    }
    else if (VK_DELETE == ch)
    {
        if (InSelectMode())
        {
            DeleteSelection();
        }
        else
        {
            // ����ɾ��һ���ַ�
            _password.Remove(_caretPos, 1);
        }
    }
    else if (VK_ESCAPE == ch)
    {
        // ȡ��ѡ��ģʽ
        CancelSelectMode();
    }
    else if (VK_HOME == ch)
    {
        // ��������
        _caretPos = 0;
        InternalSetCaret(0);
        CancelSelectMode();
    }
    else if (VK_END == ch)
    {
        // ������ĩ
        _caretPos = _password.Length();
        InternalSetCaret(0);
        CancelSelectMode();
    }
    else if (bCtrl && (ch == 'v' || ch == 'V'))
    {
        //Paste();
        return;
    }
    else if (bCtrl && (ch == 'c' || ch == 'C'))
    {
        //Copy();
        return;
    }
    else if (bCtrl && (ch == 'x' || ch == 'X'))
    {
        //Cut();
        return;
    }
    else if (bCtrl && (ch == 'a' || ch == 'A'))
    {
        SelectAll();
        return;
    }
    else
    {
        ResetCaretPos();
        return;
    }

    // ˢ�½�����ʾ

    InvalidateVisual();
    ResetCaretPos();
}

void PasswordBox::OnGotFocus(suic::FocusEventArg& e)
{
    e.Handled(true);

    WndHelper(this).HideCaret();

    InvalidateVisual();
    ResetCaretPos();
}

void PasswordBox::OnLostFocus(suic::FocusEventArg& e)
{
    WndHelper(this).HideCaret();

    DestroyCaret();
    InvalidateVisual();

    __super::OnLostFocus(e);
}

void PasswordBox::OnMouseLeftButtonDown(suic::MouseEventArg& e)
{
    SetCaptureMouse();

    e.Handled(true);

    WndHelper(this).HideCaret();

    int code = e.State();

    bool bShift = (code & MK_SHIFT) == MK_SHIFT;
    bool bCtrl = (code & MK_CONTROL) == MK_CONTROL;

    suic::Point tmPt(e.MousePoint());
    bool bValid = false;

    if (bShift)
    {
        // ѡ��
        bValid = true;
    }
    
    _caretPos = CalcCaretPos(tmPt.x);
    InternalSetCaret(0);

    CancelSelectMode();
    _startSel = _caretPos;

    InvalidateVisual();
    ResetCaretPos();
}

void PasswordBox::OnMouseLeftButtonUp(suic::MouseEventArg& e)
{
    ReleaseCaptureMouse();
}

void PasswordBox::OnMouseLeftButtonDbclk(suic::MouseEventArg& e)
{
    __super::OnMouseLeftButtonDbclk(e);

    _startSel = 0;
    _selCount = _password.Length() - _startSel;
    _caretPos = _selCount;
    InternalSetCaret(0);

    InvalidateVisual();
    ResetCaretPos();

    e.Handled(true);
}

void PasswordBox::OnMouseMove(suic::MouseEventArg& e)
{
    e.Handled(true);

    if (IsMouseCaptured())
    {
        suic::Point tmPt(e.MousePoint());
        int iPos = CalcCaretPos(tmPt.x);
        int iDif = abs(iPos - _startSel);

        if (iDif > 0)
        {
            _selCount = iPos - _startSel;
            _caretPos = iPos;//_startSel + _selCount;
            InternalSetCaret(0);

            InvalidateVisual();
            ResetCaretPos();
        }
    }
}

void PasswordBox::OnSetCursor(suic::CursorEventArg& e)
{
    suic::Rect rc(0, 0, RenderSize().cx, RenderSize().cy);

    rc.Deflate(GetBorderThickness());
    rc.Deflate(GetPadding());
    rc.Offset(PointToScreen(suic::Point()));

    if (rc.PointIn(e.MousePoint()))
    {
        ::SetCursor(LoadCursor(NULL, IDC_IBEAM));
        e.Handled(true);
    }
}

void PasswordBox::OnSetterChanged(suic::SetterChangedEventArg& e)
{
    __super::OnSetterChanged(e);
}

void PasswordBox::OnInitialized()
{
    __super::OnInitialized();

    suic::ObjectPtr obj(GetValue(_T("PasswordChar")));
    
    if (obj && !obj->ToString().Empty())
    {
        _passwordChar = obj->ToString()[0];
    }
}

}
