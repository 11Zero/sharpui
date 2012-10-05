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

class IElementCollection : public RefObject
{
public:

    virtual ~IElementCollection() {};

    virtual int GetCapacity() = 0;
    virtual void SetCapacity(int iCapacity) = 0;

    virtual int GetCount() = 0;

    virtual ElementPtr GetElement(int iIndex) = 0;

    virtual int Add(ElementPtr element) = 0;
    virtual void Clear() = 0;
    virtual void ClearLogicalParent(ElementPtr element) = 0;
    virtual bool Contains(ElementPtr element) = 0;

    virtual void CopyTo(ElementPtr array[], int index) = 0;

    virtual int IndexOf(ElementPtr element) = 0;
    virtual void Insert(int index, ElementPtr element) = 0;

    virtual void Remove(ElementPtr element) = 0;
    virtual void RemoveAt(int index) = 0;
    virtual void RemoveRange(int index, int count) = 0; 
};

typedef shared<IElementCollection> ElementCollectionPtr;

SUICORE_API ElementCollectionPtr CreateElementCollection(ElementPtr parent);

};

# endif
