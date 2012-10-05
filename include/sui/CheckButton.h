// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����CheckButton.h
// ��  �ܣ�ʵ�ֱ�׼��ѡ��ؼ���
// 
// ��  �ߣ�����
// ʱ  �䣺2010-10-31
// 
// ============================================================================

# ifndef _UICHECKBOX_H_
# define _UICHECKBOX_H_

#include <sui/sharpuiconfig.h>
#include <sui/Button.h>

namespace ui
{

/// <summary>
/// ��ѡ��ť
/// </summary>
class SHARPUI_API CheckButton : public ButtonBase
{
public:

    // ѡ���¼�
    CheckedEventHandler Checked;

    CheckButton();
    virtual ~CheckButton();

    DECLAREBUILD(CheckButton)

    /// <summary>
    ///     �����Ƿ��Զ������С
    /// </summary>
    /// <param name="val">true:�Զ���false:��ʽ</param>
    /// <returns>��</returns>
    void SetAutoSize(bool val);
    bool GetAutoSize() const;

    /// <summary>
    ///     ���ذ�ť�Ƿ�ѡ
    /// </summary>
    /// <returns>��ѡ��true��ȡ����false</returns>
    bool IsChecked() const;

    /// <summary>
    ///     ѡ��ť
    /// </summary>
    /// <param name="val">true:ѡ��false��ȡ��</param>
    /// <returns>��</returns>
    void SetCheck(bool val);

protected:

    virtual void OnRender(suic::DrawingContext * drawing);

    virtual void OnKeyDown(suic::KeyEventArg& e);

    virtual void OnMouseLeftButtonUp(suic::MouseEventArg& e);
    virtual void OnMouseLeftButtonDbclk(suic::MouseEventArg& e);

    virtual void OnGotFocus(suic::FocusEventArg& e);
    virtual void OnLostFocus(suic::FocusEventArg& e);

protected:

    suic::String InternalBackgrount();

    virtual void OnInitialized();
    virtual void OnSetterChanged(suic::SetterChangedEventArg& e);

    void AutoCalcSize();
    suic::Size MeasureOverride(const suic::Size& size);

protected:

    // �Զ�������С
    bool _bAutoSize;

    // �Ƿ�ѡ���־
    bool _bChecked;
    bool _bAdjusted;
};

typedef suic::shared<CheckButton> CheckButtonPtr;

};

# endif