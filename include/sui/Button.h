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
#include <suicore/uicontentcontrol.h>

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

/// <summary>
/// ѡ���¼��������
/// </summary>
typedef delegate<void(suic::ElementPtr, CheckedEventArg&)> CheckedEventHandler;

/// <summary>
/// ��ť����¼��������
/// </summary>
typedef delegate<void(suic::ElementPtr)> ClickEventHandler;

/// <summary>
/// ��ť�Ļ��࣬���յ���¼�����ɴ�������
/// </summary>
class SHARPUI_API ButtonBase : public suic::ContentControl
{
public:

    ButtonBase();
    virtual ~ButtonBase();

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

    virtual void OnMouseEnter(suic::MouseEventArg& e);
    virtual void OnMouseMove(suic::MouseEventArg& e);
    virtual void OnMouseLeave(suic::MouseEventArg& e);

    virtual void OnMouseLeftButtonDown(suic::MouseEventArg& e);
    virtual void OnMouseLeftButtonUp(suic::MouseEventArg& e);

    virtual void OnMouseLeftButtonDbclk(suic::MouseEventArg& e);

    virtual void OnGotFocus(suic::FocusEventArg& e);
    virtual void OnLostFocus(suic::FocusEventArg& e);
};

/// <summary>
/// ��ťʵ�֣�֧�������ʽ����
/// </summary>
class SHARPUI_API Button : public ButtonBase
{
public:

    Button();
    virtual ~Button();

    DECLAREBUILD(Button)

    virtual void OnInitialized();

protected:

    void OnRender(suic::DrawingContext * drawing);
    void OnKeyDown(suic::KeyEventArg& e);

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

    DECLAREBUILD(SystemMinButton)

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

    DECLAREBUILD(SystemMaxButton)

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

    DECLAREBUILD(SystemCloseButton)

    virtual void OnClick(suic::RoutedEventArg& e);
};

}

# endif
