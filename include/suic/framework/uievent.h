// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����UIEvent.h
// ��  �ܣ�������Ŀ���¼����ࡣ
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _UIEVENT_H_
# define _UIEVENT_H_

#include <suic/core/uiobject.h>
#include <suic/core/delegate.h>
#include <suic/framework/uiroutedeventarg.h>

namespace suic
{

class DragDropEffects
{
public:

    enum
    {
        Scroll = -2,
        All = -1,
        None = 0,
        Copy = 1,
        Move = 2,
        Link = 4,
    };
};

class SUICORE_API CancelEventArg  : public suic::EventArg
{
public:

    CancelEventArg(bool cancel);

    bool IsCancel();
    void SetCancel(bool cancel);

protected:

    bool _cancel;
};

};

# endif
