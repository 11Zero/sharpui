// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����RadioButton.h
// ��  �ܣ�ʵ�ֱ�׼ѡ��ؼ���
// 
// ��  �ߣ�����
// ʱ  �䣺2010-10-31
// 
// ============================================================================

# ifndef _UIRADIOBUTTON_H_
# define _UIRADIOBUTTON_H_

#include <sui/sharpuiconfig.h>
#include <sui/CheckButton.h>

namespace ui
{

class SHARPUI_API RadioButton : public CheckButton
{
public:

    RadioButton();
    virtual ~RadioButton();

    DECLAREBUILD(RadioButton)

    void SetGroup(const suic::String & name);
    suic::String GetGroup();

    virtual void SetCheck();
    virtual void SetUncheck();

protected:

    virtual void OnSetterChanged(suic::SetterChangedEventArg& e);

    virtual void OnRender(suic::DrawingContext * drawing);
    virtual void OnLoaded(suic::LoadedEventArg& e);

    virtual void OnKeyDown(suic::KeyEventArg& e);
    virtual void OnMouseLeftButtonUp(suic::MouseEventArg& e);
    virtual void OnMouseLeftButtonDbclk(suic::MouseEventArg& e);

    virtual void OnGotFocus(suic::FocusEventArg& e);
    virtual void OnLostFocus(suic::FocusEventArg& e);

protected:

    suic::String _sGrpName;
};

typedef suic::shared<RadioButton> RadioButtonPtr;

};

# endif