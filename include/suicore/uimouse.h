// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����uimouse.h
// ��  �ܣ�ʵ�ֱ�׼�Ĵ�����ʽ��
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _UIMOUSE_H_
# define _UIMOUSE_H_

#include <suicore/uielement.h>

namespace suic
{

class SUICORE_API Mouse : public Object
{
private:

    Mouse();
    ~Mouse();
    
public:

    static ElementPtr GetMouseDown(int flag);
    static void SetMouseDown(ElementPtr, int flag);
    static Point GetPosition(ElementPtr);
    
    static MouseButtonState LeftButton();
    static MouseButtonState RightButton();
    static MouseButtonState MiddleButton();

    static ElementPtr Capture(ElementPtr);
    static ElementPtr Captured();
    static ElementPtr DirectlyOver();

    static void SetMouseOver(ElementPtr);
    static bool IsMouseOver(ElementPtr);
    static bool IsMouseCaptureWithin(ElementPtr);

    static void UpdateCursor();

    static ElementPtr HitTest(ElementPtr root, Point pt, bool bLogical);

};

};

# endif
