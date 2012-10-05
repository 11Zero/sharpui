// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����hwndhelper.h
// ��  �ܣ���װwindows�ľ����
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _UIHWNDHELPER_H_
# define _UIHWNDHELPER_H_

#include <suicore/uiobject.h>
#include <suicore/uivisualhost.h>
#include <suicore/uielement.h>

namespace suic
{

class SUICORE_API HwndHelper : public Object
{
public:

    HwndHelper();

    static VisualHostPtr GetVisualHost(Element* pElem); 
    static suic::Handle GetHandle(Element* pElem);
    static void LoadedElement(Element* pElem);

    static void DragMoveWindow(Element* pElem);

    static Point GetCursorPoint();
    static Point GetWindowPoint(Element*);    

    static void InvalidateAllWidows();
    static void AssignWindowMessage(suic::MessageParameter& mp);
    static Uint32 HandleDefWndMessage(suic::MessageParameter& mp);

    static void MaximizeWindow(suic::ElementPtr);
    static void RestoreWindow(suic::ElementPtr);
    static void MinimizeWindow(suic::ElementPtr);
    static void CloseWindow(suic::ElementPtr);
    static void ForceCloseWindow(suic::ElementPtr);

    static bool IsWindowMinimize(suic::ElementPtr);
    static bool IsWindowMaximize(suic::ElementPtr);
    static bool IsWindowVisible(suic::ElementPtr);
    static bool IsWindowEnable(suic::ElementPtr);
};

};

# endif
