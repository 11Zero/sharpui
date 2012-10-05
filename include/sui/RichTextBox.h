// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����RichTextBox.h
// ��  �ܣ�ʵ�ֱ�׼��RichEdit�ؼ�
// 
// ��  �ߣ�����
// ʱ  �䣺2010-08-31
// 
// ============================================================================

# ifndef _UIRICHEDITBOX_H_
# define _UIRICHEDITBOX_H_

#include <sui/sharpuiconfig.h>
#include <suicore/uicontrol.h>

namespace ui
{

// ============================================================================
// RichTextBox��ʵ�ֱ�׼��RichEdit��
// ============================================================================

class SHARPUI_API RichTextBox : public suic::Control
{
public:

    RichTextBox();
    virtual ~RichTextBox();

    DECLAREBUILD(RichTextBox)

protected:

    virtual void OnInitialized();

    virtual void OnRender(suic::DrawingContext * drawing);

    virtual void OnTextInput(suic::KeyEventArg& e);
    virtual void OnKeyDown(suic::KeyEventArg& e);

    virtual void OnGotFocus(suic::FocusEventArg& e);
    virtual void OnLostFocus(suic::FocusEventArg& e);
    virtual void OnSetCursor(suic::CursorEventArg& e);

    virtual void OnMouseEnter(suic::MouseEventArg& e);
    virtual void OnMouseMove(suic::MouseEventArg& e);
    virtual void OnMouseLeave(suic::MouseEventArg& e);
    virtual void OnMouseLeftButtonDown(suic::MouseEventArg& e);
    virtual void OnMouseLeftButtonDbclk(suic::MouseEventArg& e);
    virtual void OnMouseLeftButtonUp(suic::MouseEventArg& e);

protected:
};

typedef suic::shared<RichTextBox> RichTextBoxPtr;

};

# endif
