// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����MenuItem.h
// ��  �ܣ�ʵ�ֱ�׼��MenuItem�ؼ�
// 
// ��  �ߣ�����
// ʱ  �䣺2010-08-31
// 
// ============================================================================

# ifndef _UIMENUITEM_H_
# define _UIMENUITEM_H_

#include <sui/sharpuiconfig.h>
#include <sui/ItemContainer.h>
#include <suicore/uipopup.h>
#include <suicore/drawing/uidrawing.h>

namespace ui
{

// ============================================================================
// MenuItem��ʵ�ֱ�׼�Ĳ˵��
// ============================================================================

class MenuItem;
typedef suic::shared<MenuItem> MenuItemPtr;

typedef delegate<void(suic::ObjectPtr, MenuItemPtr)> MenuItemClickEventHandler;

enum MenuItemRole
{ 
    TopLevelItem,
    TopLevelHeader, 
    SubmenuItem, 
    SubmenuHeader,
};

class SHARPUI_API MenuItem : public suic::ContentControl
{
public:

    suic::RoutedEventHandler SubmenuOpenedEvent;
    suic::RoutedEventHandler SubmenuClosedEvent;

    MenuItemClickEventHandler MenuItemClick;

    MenuItem();
    virtual ~MenuItem();

    DECLAREBUILD(MenuItem)

    bool IsSubmenuOpen() const;
    bool IsSubmenu() const;

    void SetIcon(suic::ImagePtr icon);
    suic::ImagePtr GetIcon() const;

public:

    virtual void OnClick(suic::ObjectPtr menu, bool bIsMain);

    virtual void OnPopupClosed(suic::ObjectPtr source, suic::EventArg& e);
    virtual void OnSubmenuOpened(suic::RoutedEventArg& e);

    virtual void OnChecked(suic::RoutedEventArg& e);
    virtual void OnUnchecked(suic::RoutedEventArg& e);

protected:

    suic::ElementPtr FindName(const suic::String& strName);
    virtual void AddLogicalChild(suic::Element* child);

    virtual suic::Size MeasureOverride(const suic::Size& size);

    virtual void OnInitialized();
    virtual void OnStyleUpdated();

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

    suic::PopupPtr _submenuPopup;
    MenuItemPtr _currentSelection;
    suic::ImagePtr _icon;

    friend class Menu;
};

};

# endif
