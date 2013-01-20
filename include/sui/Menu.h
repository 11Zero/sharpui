// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����Menu.h
// ��  �ܣ�ʵ�ֱ�׼��Menu�ؼ�
// 
// ��  �ߣ�����
// ʱ  �䣺2010-08-31
// 
// ============================================================================

# ifndef _UIMENU_H_
# define _UIMENU_H_

#include <sui/sharpuiconfig.h>
#include <sui/selector.h>
#include <sui/MenuItem.h>

namespace ui
{

// ============================================================================
// Menu��ʵ�ֱ�׼���б��
// ============================================================================

class Menu;
typedef suic::shared<Menu> MenuPtr;

class SHARPUI_API Menu : public Selector
{
public:

    MenuItemClickEventHandler MenuItemClick;

    Menu();
    virtual ~Menu();

    DeclareTypeofInfo(Menu, Selector)

    static int TrackPopupMenu(int x, int y, MenuPtr menu);
    static void AddSubMenu(MenuItemPtr item, MenuPtr subMenu);

    MenuItemPtr GetMenuItem(int index);
    int AddText(const suic::String& text);

public:

    suic::Size MeasureOverride(const suic::Size& size);
    suic::Size ArrangeOverride(const suic::Size& size);

    void OnInitialized();

    void OnRender(suic::DrawingContext * drawing);

    void OnTextInput(suic::KeyboardEventArg& e);
    void OnKeyDown(suic::KeyboardEventArg& e);
    void OnSetCursor(suic::CursorEventArg& e);

    void OnMouseEnter(suic::MouseEventArg& e);
    void OnMouseMove(suic::MouseEventArg& e);
    void OnMouseLeave(suic::MouseEventArg& e);
    void OnMouseLeftButtonDown(suic::MouseEventArg& e);
    void OnMouseLeftButtonDbclk(suic::MouseEventArg& e);
    void OnMouseLeftButtonUp(suic::MouseEventArg& e);

    virtual void OnSelectionChanged(SelectionChangedEventArg& e);
    virtual void OnItemLeftButtonDown(MenuItem* item, suic::MouseEventArg& e);

protected:

    MenuItemPtr _currentSelection;
};

};

# endif