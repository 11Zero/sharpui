// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����ComboBox.h
// ��  �ܣ�ʵ�ֱ�׼����Ͽ�ؼ���
// 
// ��  �ߣ�����
// ʱ  �䣺2010-10-31
// 
// ============================================================================

# ifndef _UICOMBOBOX_H_
# define _UICOMBOBOX_H_

#include <sui/sharpuiconfig.h>
#include <sui/Selector.h>
#include <suicore/uipopup.h>
#include <sui/textbox.h>
#include <sui/ListBox.h>

namespace ui
{

/// <summary>
/// ��Ͽ������ΪListBox�������
/// </summary>
class SHARPUI_API ComboBoxItem : public ListBoxItem
{
public:

    ComboBoxItem();
    virtual ~ComboBoxItem();

    DECLAREBUILD(ComboBoxItem);

    int AddText(const suic::String& text);

protected:

    void OnSetterChanged(suic::SetterChangedEventArg& e);
    void OnMouseMove(suic::MouseEventArg& e);

    void OnMouseLeftButtonDown(suic::MouseEventArg& e);
    void OnMouseLeftButtonUp(suic::MouseEventArg& e);

    void OnRender(suic::DrawingContext * drawing);
};

/// <summary>
/// ��Ͽ��������ʱ�¼�
/// </summary>
class SHARPUI_API DropDownEventArg : public suic::EventArg
{
public:

    DropDownEventArg(suic::PopupPtr popup, suic::ElementPtr list);

    suic::PopupPtr GetPopup() const;
    suic::ElementPtr GetList() const;

protected:

    suic::PopupPtr _popup;
    suic::ElementPtr _list;
};

inline suic::PopupPtr DropDownEventArg::GetPopup() const
{
    return _popup;
}

inline suic::ElementPtr DropDownEventArg::GetList() const
{
    return _list;
}

typedef delegate<void(suic::Element*, DropDownEventArg&)> DropDownEventHandler;

/// <summary>
/// ��Ͽ��������ӿؼ���ɣ�TextBox��ListBox��
/// </summary>
class SHARPUI_API ComboBox : public Selector
{
public:

    DropDownEventHandler DropDownClosed;
    DropDownEventHandler DropDownOpened;

    DECLAREBUILD(ComboBox)

    ComboBox();
    virtual ~ComboBox();

    void SetReadOnly(bool bOnly);
    bool IsReadOnly() const;
    bool IsDropDown() const;

    /// <summary>
    ///     ����������ĸ߶�
    /// </summary>
    /// <param name="height">������߶�</param>
    /// <returns>��</returns>
    void SetDropDownHeight(int height);

    /// <summary>
    ///     ����Ԫ���ı���Ĭ�ϻ��_textBox��������
    /// </summary>
    /// <param name="text">�ı���Ϣ</param>
    /// <returns>��</returns>
    void SetText(const suic::String & text);
    suic::String GetText();

    int AddText(const suic::String& text);

    /// <summary>
    ///    ����������Ƿ��Ѿ���
    /// </summary>
    /// <returns>true���򿪣�false���ر�</returns>
    bool StaysOpenOnEdit() const;

public:

    void AddLogicalChild(suic::Element* child);

    void OnTextBoxCursor(suic::Element*, suic::CursorEventArg& e);

    virtual void OnDropDownClosed(DropDownEventArg& e);
    virtual void OnDropDownOpened(DropDownEventArg& e);

public:

    virtual void OnRender(suic::DrawingContext * drawing);

    virtual void OnKeyDown(suic::KeyEventArg& e);
    virtual void OnTextInput(suic::KeyEventArg& e);

    virtual void OnPreviewSetCursor(suic::CursorEventArg& e);
    virtual void OnPreviewMouseLeftButtonDown(suic::MouseEventArg& e);
    virtual void OnPreviewMouseLeftButtonDbclk(suic::MouseEventArg& e);

    virtual void OnMouseLeftButtonDown(suic::MouseEventArg& e);
    virtual void OnMouseLeftButtonUp(suic::MouseEventArg& e);
    virtual void OnMouseLeftButtonDbclk(suic::MouseEventArg& e);
    virtual void OnPreviewMouseEnter(suic::MouseEventArg& e);
    virtual void OnPreviewMouseMove(suic::MouseEventArg& e);

    virtual void OnSetCursor(suic::CursorEventArg& e);

    virtual void OnGotFocus(suic::FocusEventArg& e);
    virtual void OnLostFocus(suic::FocusEventArg& e);

protected:

    virtual suic::Size MeasureOverride(const suic::Size& size);
    virtual suic::Size ArrangeOverride(const suic::Size& size);

    virtual void OnInitialized();
    virtual void OnStyleUpdated();
    virtual void OnSetterChanged(suic::SetterChangedEventArg& e);

protected:

    // ����������,����list������
    suic::PopupPtr _popup;
    // �����б��
    ListBoxPtr _list;
    // �༭��
    TextBoxPtr _textBox;
    // �Ƿ�ֻ��
    bool _bReadOnly;
    // ������ĸ߶�
    int _downHeight;
};

typedef suic::shared<ComboBox> ComboBoxPtr;

};

# endif
