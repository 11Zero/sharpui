// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����UIDictionary.h
// ��  �ܣ�������Ŀ�ļ�/ֵ����
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _UIDICTIONARY_H_
# define _UIDICTIONARY_H_

#include <suicore/uiobject.h>

namespace suic
{

class SUICORE_API Dictionary : public RefObject
{
public:

    Dictionary();
    virtual ~Dictionary();

    int Count() const;
    void Add(key, value);
    void Clear();
    bool ContainsKey(TKey key);
    bool ContainsValue(TValue value);
    bool Remove(TKey key);
    bool TryGetValue(TKey key, out TValue value);
};

};

# endif
