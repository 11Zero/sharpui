// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����visualtreehelper.h
// ��  �ܣ���װwindows�ľ����
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _UIVISUALTREEHELPER_H_
# define _UIVISUALTREEHELPER_H_

#include <suicore/uiobject.h>
#include <suicore/uiinterface.h>
#include <suicore/uiframeworkelement.h>

namespace suic
{

class SUICORE_API VisualTreeHelper : public Object
{
public:

    VisualTreeHelper();

    static ElementPtr FindElement(Element*, const String&);

};

};

namespace suic
{

class SUICORE_API VisualHelper : public Object
{
public:

    VisualHelper();

    static Rect GetRenderRect(Element* pElem);
    static Point GetCursorPoint(Element* pElem);

    static bool CursorPointIsInWindow(Element*);
    static bool CursorPointIsInElement(Element*);

    static void SetLogicalParent(Element* pParent, Element* pChild);
    static void SetVisualParent(Element* pParent, Element* pChild);
    static void AddVisualChild(Visual* pParent, Visual* pChild);
    static void InsertVisualChild(Visual* pParent, Visual* pPos, Visual* pChild, bool bAfter);
    static void InsertVisualChild(Visual* pParent, int iPos, Visual* pChild, bool bAfter);
    static void ClearVisualChildren(Visual* pParent);
    static void RemoveVisualChild(suic::Visual* pChild);
    static void RemoveVisualChild(int iPos);

    static void InvalidateWindow(Element*);    

    static ElementPtr FindElement(Element*, const String&);
    static FrameworkElementPtr GetRootElement(Element*);
};

};

# endif
