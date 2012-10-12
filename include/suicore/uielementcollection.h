// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����uielementcollection.h
// ��  �ܣ�ʵ�ֽ���Ԫ�صļ��ϡ�
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _UIELEMENTCOLLECTION_H_
# define _UIELEMENTCOLLECTION_H_

#include <suicore/uielement.h>

namespace suic
{

class SUICORE_API ElementCollection : public RefObject
{
public:

    ElementCollection(ElementPtr virtualParent, ElementPtr logicParent);
    virtual ~ElementCollection();

    int GetCapacity();
    void SetCapacity(int iCapacity);

    int GetCount();

    Element* GetElement(int iIndex);

    int Add(ElementPtr element);
    void Clear();
    void ClearLogicalParent(ElementPtr element);
    bool Contains(ElementPtr element);

    void CopyTo(ElementPtr array[], int index);

    int IndexOf(ElementPtr element);
    void Insert(int index, ElementPtr element);

    void Remove(ElementPtr element) ;
    void RemoveAt(int index);
    void RemoveRange(int index, int count); 

protected:

    ElementPtr _logicParent;
    ElementPtr _virtualParent;

    Vector<ElementPtr> _items;
};

typedef shared<ElementCollection> ElementCollectionPtr;

inline int ElementCollection::GetCount()
{
    return _items.size();
}

inline Element* ElementCollection::GetElement(int iIndex)
{
    return _items[iIndex].get();
}

};

# endif
