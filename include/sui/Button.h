// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����Button.h
// ��  �ܣ�ʵ��Win32��׼�İ�ť��֧����̬�л���
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _UIBUTTON_H_
# define _UIBUTTON_H_

#include <sui/sharpuiconfig.h>
#include <suic/framework/uicontentcontrol.h>

namespace ui
{

/// <summary>
///  ѡ���¼�������CheckButton�Լ���������
/// </summary>
class SHARPUI_API CheckedEventArg : public suic::RoutedEventArg
{
public:

    CheckedEventArg(bool val) 
        : bChecked(val)
        , RoutedEventArg(suic::ObjectPtr())
    {
    }

    bool IsChecked() 
    { 
        return bChecked; 
    }

public:

    // ѡ���־
    bool bChecked;
};

class ButtonBase;

/// <summary>
/// ��ť����¼��������
/// </summary>
typedef delegate<void(suic::Element*)> ClickEventHandler;

/// <summary>
/// ��ť�Ļ��࣬���յ���¼�����ɴ�������
/// </summary>
class SHARPUI_API ButtonBase : public suic::ContentControl
{
public:

    ButtonBase();
    virtual ~ButtonBase();

    DeclareAbstractTypeofInfo(ButtonBase, suic::ContentControl)

    // ������¼�
    ClickEventHandler Click;

    /// <summary>
    ///     ��굥���¼�
    /// </summary>
    /// <remarks>
    ///     �����������ͷź�����Ԫ��֮�ڲŴ���
    ///     �˷��������Click�ⲿע���¼�
    /// </remarks>
    /// <param name="e">�¼�</param>
    /// <returns>��</returns>
    virtual void OnClick(suic::RoutedEventArg& e);

protected:

    suic::Size MeasureOverride(const suic::Size& size);

    void OnRender(suic::DrawingContext * drawing);

    void OnMouseMove(suic::MouseEventArg& e);
    void OnMouseLeftButtonDown(suic::MouseEventArg& e);
    void OnMouseLeftButtonUp(suic::MouseEventArg& e);
    void OnMouseLeftButtonDbclk(suic::MouseEventArg& e);
};

/// <summary>
/// ��ťʵ�֣�֧�������ʽ����
/// </summary>
class SHARPUI_API Button : public ButtonBase
{
public:

    Button();
    virtual ~Button();

    DeclareTypeofInfo(Button, ButtonBase)

    virtual void OnInitialized();

protected:

    void OnRender(suic::DrawingContext * drawing);
    void OnKeyDown(suic::KeyboardEventArg& e);
    void OnMouseLeftButtonDown(suic::MouseEventArg& e);

protected:

    int nOffset;
};

typedef suic::shared<Button> ButtonPtr;

/// <summary>
/// ϵͳ��С����ť��ʵ�ֵ�����С������
/// </summary>
class SHARPUI_API SystemMinButton : public Button
{
public:

    SystemMinButton();
    virtual ~SystemMinButton();

    DeclareTypeofInfo(SystemMinButton, Button)

    virtual void OnClick(suic::RoutedEventArg& e);
};

/// <summary>
/// ϵͳ��󻯺ͻ�ԭ��ť�������ǿ���󻯻�ԭ����
/// </summary>
class SHARPUI_API SystemMaxButton : public Button
{
public:

    SystemMaxButton();
    virtual ~SystemMaxButton();

    DeclareTypeofInfo(SystemMaxButton, Button)

    virtual void OnLoaded(suic::LoadedEventArg& e);
    virtual void OnClick(suic::RoutedEventArg& e);
    virtual void OnRender(suic::DrawingContext * drawing);

    virtual suic::Size MeasureOverride(const suic::Size& size);
};

/// <summary>
/// ϵͳ�رհ�ť��ʵ�ֵ����رմ���
/// </summary>
class SHARPUI_API SystemCloseButton : public Button
{
public:

    SystemCloseButton();
    virtual ~SystemCloseButton();

    DeclareTypeofInfo(SystemCloseButton, Button)

    virtual void OnClick(suic::RoutedEventArg& e);
};

}

# endif
