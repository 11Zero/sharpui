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
#include <suic/framework/uipopup.h>
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

    DeclareTypeofInfo(ComboBoxItem, ListBoxItem)

protected:

    void OnPropertyChanged(suic::PropertyChangedEventArg& e);
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

    DeclareTypeofInfo(ComboBox, Selector)

    ComboBox();
    virtual ~ComboBox();

    void ClearChildren();

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
    suic::String GetText() const;

    int AddText(const suic::String& text);

    /// <summary>
    ///    ����������Ƿ��Ѿ���
    /// </summary>
    /// <returns>true���򿪣�false���ر�</returns>
    bool StaysOpenOnEdit() const;

public:

    int AddChild(suic::ObjectPtr child);

    void OnTextBoxCursor(suic::Element*, suic::CursorEventArg& e);

    virtual void OnDropDownClosed(DropDownEventArg& e);
    virtual void OnDropDownOpened(DropDownEventArg& e);

public:

    void OnRender(suic::DrawingContext * drawing);

    void OnKeyDown(suic::KeyboardEventArg& e);
    void OnTextInput(suic::KeyboardEventArg& e);

    void OnPreviewSetCursor(suic::CursorEventArg& e);
    void OnPreviewMouseLeftButtonDown(suic::MouseEventArg& e);
    void OnPreviewMouseLeftButtonDbclk(suic::MouseEventArg& e);

    void OnMouseLeftButtonDown(suic::MouseEventArg& e);
    void OnMouseLeftButtonUp(suic::MouseEventArg& e);
    void OnMouseLeftButtonDbclk(suic::MouseEventArg& e);
    void OnPreviewMouseEnter(suic::MouseEventArg& e);
    void OnPreviewMouseMove(suic::MouseEventArg& e);

    void OnSetCursor(suic::CursorEventArg& e);

    void OnGotFocus(suic::FocusEventArg& e);
    void OnLostFocus(suic::FocusEventArg& e);

    void OnSelectionChanged(suic::Element* sender, SelectionChangedEventArg& e);

protected:

    void CheckAddingItem(suic::ObjectPtr& itemObj);

    suic::Size MeasureOverride(const suic::Size& size);
    suic::Size ArrangeOverride(const suic::Size& size);

    void OnInitialized();
    void OnStyleUpdated();
    void OnPropertyChanged(suic::PropertyChangedEventArg& e);

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
