// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����UIObjecth
// ��  �ܣ�������Ŀ�Ļ��������еĶ��󶼱���Ӵ˼̳С�
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _UIOBJECT_H_
# define _UIOBJECT_H_

#include <suicore/uitypes.h>
#include <suicore/uimicro.h>
#include <suicore/uiconst.h>
#include <suicore/uishared.h>
#include <suicore/stringcore.h>
#include <suicore/suicoreids.h>

namespace suic
{

/// <summary>
/// ��ܽ���������Ļ��࣬����new��delete��ʵ���ڴ����
/// </summary>
class SUICORE_API Object
{
public:

    virtual ~Object();

    virtual String ToString();
    virtual bool ToBool();
    virtual Double ToDouble();
    virtual Int32 ToInt32();
    virtual Rect ToRect();
    virtual Size ToSize();
    virtual Point ToPoint();
    virtual Color ToColor();
    virtual int HashCode() const;

#ifdef _DEBUG
    static void * operator new(size_t size, const char* name=__FILE__, int line=__LINE__);
    static void operator delete(void* ptr, const char* name, int line);
#else
    static void * operator new(size_t size);
#endif

    static void operator delete(void* ptr);

    static void * operator new[](size_t size);
    static void operator delete[](void* ptr);
};

/// <summary>
/// �����ü�����Ļ���
/// </summary>
class SUICORE_API RefObject : public Object
{
public:

    RefObject();
    virtual ~RefObject() {}

    RefObject(const RefObject&);
    RefObject& operator=(const RefObject&);

    int ReferenceCount () const;

    bool IsAutoDelete () const;
    bool SetAutoDelete (bool bDel);

    void __addRef ();
    void __release ();

private:

    bool _autoDelete;
    long _count;
};

typedef shared<RefObject> ObjectPtr;

};

# endif
