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

#include <suic/core/uiobject.h>
#include <suic/framework/uivisualhost.h>
#include <suic/framework/uielement.h>

namespace suic
{

class SUICORE_API HwndHelper : public Object
{
public:

    static VisualHostPtr GetVisualHost(Element* pElem); 
    static suic::Handle GetHandle(Element* pElem);
    static void LoadedElement(Element* pElem);

    static bool IsMouseInElement(suic::Element* element);

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

protected:

    HwndHelper();
};

};

# endif
