// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����ListBox.h
// ��  �ܣ�ʵ��Item�Ļ���
// 
// ��  �ߣ�����
// ʱ  �䣺2010-08-31
// 
// ============================================================================

# ifndef _UILISTBOX_H_
# define _UILISTBOX_H_

#include <sui/sharpuiconfig.h>
#include <sui/selector.h>
#include <sui/listboxitem.h>

namespace ui
{

/// <summary>
/// ʵ�ֱ�׼���б����������ListBoxItem���а�װ
/// </summary>
class SHARPUI_API ListBox : public Selector
{
public:

    enum eSelectionMode 
    {
        Single,
        Multiple,
        Extended
    };

    ListBox();
    virtual ~ListBox();

    DeclareTypeofInfo(ListBox, Selector)

    int AddText(const suic::String& text);

protected:

    void CheckAddingItem(suic::ObjectPtr& itemObj);

public:

    virtual void OnInitialized();
    virtual void OnUnloaded(suic::LoadedEventArg& e);

    virtual void OnRender(suic::DrawingContext * drawing);
    virtual void OnTimer(int iTimerId);

    virtual void OnTextInput(suic::KeyboardEventArg& e);
    virtual void OnKeyDown(suic::KeyboardEventArg& e);

    virtual void OnGotFocus(suic::FocusEventArg& e);
    virtual void OnLostFocus(suic::FocusEventArg& e);

    virtual void OnMouseMove(suic::MouseEventArg& e);
    virtual void OnMouseWheel(suic::MouseWheelEventArg& e);

    virtual void OnMouseLeftButtonDown(suic::MouseEventArg& e);
    virtual void OnMouseLeftButtonUp(suic::MouseEventArg& e);

    virtual void OnItemSelected(suic::ObjectPtr item, ItemSelectionEventArg& e);

protected:

    suic::Int32 _timerid;
};

typedef suic::shared<ListBox> ListBoxPtr;

};

# endif
