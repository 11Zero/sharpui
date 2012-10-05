// ======================================================================
//
// Copyright (c) 2008-2012 ����, Inc. All rights reserved.
//
// Sharpui��Դ����ѭCPLЭ����п�Դ���κθ��˻������ڴ�Э���Ͽ�������ʹ�á�
//
// ======================================================================

//////////////////////////////////////////////////////////////////////////////
// MenuItem.cpp

#include <sui/Menu.h>
#include <suicore/hwndadapter.h>

namespace ui
{

class HwndSourceHookMenuPopup : public suic::IHwndAdapterHook
{
public:

    HwndSourceHookMenuPopup(suic::PopupPtr popup, MenuPtr menu);

    void HandleMouseDown(HWND hwnd);
    void HandleMouseUp();
    bool HandleMouseMove(suic::MessageParameter& mp);
    bool IsMouseOverOwer();

    bool OnFilterMessage(suic::ObjectPtr sender, suic::MessageParameter& mp);
    void ClosePopup(suic::Element* pElem);

    MenuPtr HitTestPopup();
    bool IsMouseCapture() const;
    void SetMouseCapture(bool value);

    void AddMenuPopup(MenuItemPtr item, suic::PopupPtr popup);
    void SetMainMenu(MenuPtr mainMenu);

protected:

    suic::PopupPtr _popup;
    suic::EnumeratorPtr _popups;

    MenuPtr _focusMenu;
    MenuPtr _mainMenu;

    bool _mouseCapture;
};

typedef suic::shared<HwndSourceHookMenuPopup> HwndSourceHookMenuPopupPtr;

suic::PopupPtr GetTrackMenu();
bool IsValidTrackMenu();
void UpdateMainMenu(MenuItemPtr itemPtr, MenuPtr mainMenu);
void SetTrackMenu(suic::PopupPtr menu);
void SetPopupMenu(MenuItemPtr itemPtr, int x, int y, suic::PopupPtr menu);

void AddMenuItemIntoPopup(MenuItem* pItem, suic::PopupPtr& popup);

void InternalCloseTrackMenuPopup();
int InternalTrackPopupMenu(MenuPtr mainMenu);
int TrackPopupMenuItem(MenuItemPtr itemPtr, int x, int y, MenuPtr mainMenu, suic::PopupPtr menuPop);

};
