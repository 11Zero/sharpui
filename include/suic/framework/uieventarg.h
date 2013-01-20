// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����uieventarg.h
// ��  �ܣ�������Ŀ���¼����ࡣ
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _UIEVENTARG_H_
# define _UIEVENTARG_H_

#include <suic/core/uiobject.h>
#include <suic/core/delegate.h>

namespace suic
{

/// <summary>
/// ����Ԫ�ص��¼����������н���Ԫ�صĻ��࣬�����Ľ���Ԫ�ض���ֱ�ӻ�
/// ���ӵ�������
/// </summary>
class SUICORE_API EventArg : public Object
{
public:

    EventArg();
    Uint32 Timestamp() const;

    virtual void CallEventHandler(ObjectPtr& handler, ObjectPtr& target);

    template<typename T, typename H, typename A>
    void InternalCall(ObjectPtr& handler, ObjectPtr& target)
    {
        T* pElem(dynamic_cast<T*>(target.get()));
        H* pHandler(dynamic_cast<H*>(handler.get()));

        if (pHandler && pElem)
        {
            (*pHandler)(pElem, *((A*)this));
        }
    }

protected:

    Uint32 _timestamp;
};

};

# endif
