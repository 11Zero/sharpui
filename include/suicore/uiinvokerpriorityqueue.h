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

#include <suicore/uiassignerinvoker.h>
#include <suicore/uistructure.h>
#include <util/locker.h>

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
    void Enqueue(AssignerInvokerPtr, int Priority);

    void RemoveItem(AssignerInvokerPtr item);

protected:

    void CalculateMaxPriority();

protected:

    EnumeratorPtr _sendQueue;
    EnumeratorPtr _queue;
    int _maxPriority;
    Mutex _queueLock;
};

typedef shared<InvokerPriorityQueue> InvokerPriorityQueuePtr;

}

# endif