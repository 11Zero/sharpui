// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����uiinvokerpriorityqueue.h
// ��  �ܣ�ʵ�ִ������ȼ��Ķ��С�
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _UIINVOKERPRIORITYQUEUE_H_
# define _UIINVOKERPRIORITYQUEUE_H_

#include <suic/core/uiassignerinvoker.h>
#include <suic/types/uistructure.h>
#include <suic/tools/locker.h>

namespace suic
{

class SUICORE_API InvokerPriorityQueue  : public RefObject
{
public:

    InvokerPriorityQueue();

    // ȡ�������ݵ�������ȼ�
    int GetMaxPriority();

    // �������ȼ���ߵĲ�����
    AssignerInvokerPtr Dequeue();
    AssignerInvokerPtr GetSenderItem();

    void Enqueue(AssignerInvokerPtr, int Priority);
    void RemoveItem(AssignerInvokerPtr item);

protected:

    void CalculateMaxPriority();

protected:

    Vector<AssignerInvokerPtr> _sendQueue;

    typedef Vector<AssignerInvokerPtr, RefObject> VectorRef;
    typedef shared<VectorRef> VectorPtr;

    Vector<VectorPtr> _queue;
    int _maxPriority;
    Mutex _queueLock;
};

typedef shared<InvokerPriorityQueue> InvokerPriorityQueuePtr;

}

# endif