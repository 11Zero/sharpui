// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����uieventhandler.h
// ��  �ܣ�������Ŀ���¼�����ص���
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _UIEVENTHANDLER_H_
# define _UIEVENTHANDLER_H_


#include <suic/framework/uieventarg.h>
#include <suic/framework/uirouteevent.h>

namespace suic
{

class Element;
typedef delegate<void(Element*, EventArg&)> EventHandler;

typedef delegate<void(Element*, RoutedEventArg&), RefObject> RoutedEventHandler;

typedef delegate<void(Element*, MouseEventArg&), RefObject> MouseEventHandler;
typedef delegate<void(Element*, MouseWheelEventArg&), RefObject> MouseWheelEventHandler;
typedef delegate<void(Element*, KeyboardEventArg&), RefObject> KeyboardEventHandler;
typedef delegate<void(Element*, FocusEventArg&), RefObject> FocusEventHandler;
typedef delegate<void(Element*, DragEventArg&), RefObject> DragEventHandler;
typedef delegate<void(Element*, LoadedEventArg&), RefObject> LoadedEventHandler;
typedef delegate<void(Element*, CursorEventArg&), RefObject> CursorEventHandler;
typedef delegate<void(Element*, HitResultEventArg&), RefObject> HitTestEventHandler;
typedef delegate<void(Element*, RoutedEventArg&), RefObject> InitializedEventHandler;
typedef delegate<void(Element*, DataTransferEventArg&), RefObject> TargetUpdatedEventHandler;

}

# endif
