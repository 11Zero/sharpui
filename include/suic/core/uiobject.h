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

#include <suic/core/uimicro.h>
#include <suic/core/uiconst.h>
#include <suic/core/uishared.h>
#include <suic/core/stringcore.h>

namespace suic
{

class Object;
struct TypeofInfo
{
    // ����
    const char* typeName;
    // ��������Ϣ
    TypeofInfo* (__stdcall* baseType)();
    Object* (__stdcall* typeCreate)();

    // �ж��Ƿ��ָ����̳�
    bool IsDerivedFrom(TypeofInfo* baseType);
};

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
    virtual int GetHashCode() const;

#ifdef _DEBUG
    static void* operator new(size_t size, const char* name=__FILE__, int line=__LINE__);
    static void operator delete(void* ptr, const char* name, int line);
#else
    static void* operator new(size_t size);
#endif

    static void operator delete(void* ptr);

    static void* operator new[](size_t size);
    static void operator delete[](void* ptr);

public:

    static TypeofInfo typeObject;
    static TypeofInfo* __stdcall BaseType();
    static TypeofInfo* __stdcall ThisType();
    static Object* __stdcall Create();

    virtual suic::TypeofInfo* GetThisType() const;
    virtual suic::String GetTypeid() const;
};

/// <summary>
/// �����ü�����Ļ���
/// </summary>
class SUICORE_API RefObject : public Object
{
public:

    RefObject();
    virtual ~RefObject() {}

    DeclareTypeofInfo(RefObject, Object)

    RefObject(const RefObject&);
    RefObject& operator=(const RefObject&);

    bool SetAutoDelete(bool val);
    bool IsAutoDelete() const;

    int GetCount() const;
 
public:

    void __addRef();
    void __release();

private:

    bool _autoDelete;
    long _count;
};

typedef shared<RefObject> ObjectPtr;

};

# endif
