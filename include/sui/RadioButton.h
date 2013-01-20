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

    DeclareTypeofInfo(RadioButton, CheckButton)

    virtual void SetCheck();
    virtual void SetUncheck();

// ���Է��ʶ���
public:

    /// <summary>
    ///     �����Ƿ��Զ������С
    /// </summary>
    /// <param name="val">true:�Զ���false:��ʽ</param>
    /// <returns>��</returns>
    suic::String GetGroup() const;
    void SetGroup(suic::String val);

protected:

    virtual void OnPropertyChanged(suic::PropertyChangedEventArg& e);

    virtual void OnRender(suic::DrawingContext * drawing);
    virtual void OnLoaded(suic::LoadedEventArg& e);

    virtual void OnKeyDown(suic::KeyboardEventArg& e);
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