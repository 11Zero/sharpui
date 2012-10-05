// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����UIGuard.h
// ��  �ܣ�������Ŀ���߳��ڱ��ࡣ
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _UIGUARD_H_
# define _UIGUARD_H_

#include <suicore/uiobject.h>

namespace suic
{

template<typename LOCK>
class SUICORE_API Guard
{
public:

    Guard(const LOCK & lock)
        : m_lock(lock)
        , m_owner(false)
    {
        m_lock.lock();
        m_owner = true;
    }

    virtual ~Guard()
    {
        Release();
    }

    bool Acquired() const
    {
        if (!m_owner)
        {
            m_lock.lock();
            m_owner = true;
        }

        return true;
    }

    void Release() const
    {
        if (m_owner)
        {
            m_lock.unlock();
            m_owner = false;
        }
    }

protected:

    const LOCK & m_lock;
    mutable bool m_owner;

    friend class ThreadCond;
};

};

# endif
