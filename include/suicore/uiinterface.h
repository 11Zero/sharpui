// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����UIInterface.h
// ��  �ܣ�������Ŀ���û�ע��ӿڡ�
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _UIINTERFACE_H_
# define _UIINTERFACE_H_

#include <suicore/uiconst.h>
#include <suicore/uielement.h>
#include <suicore/uistructure.h>

namespace suic 
{

class IMarkupAttribute : public RefObject
{
public:

    virtual ~IMarkupAttribute() {}

    /// <summary>
    ///     ���ü�¼����һ��
    /// </summary>
    /// <returns>��</returns>
    virtual void Reset() = 0;

    /// <summary>
    ///     �ж��Ƿ񵽼�¼ĩβ
    /// </summary>
    /// <returns>��</returns>
    virtual bool HasNext() = 0;

    /// <summary>
    ///     �ƶ���¼����һ��
    /// </summary>
    /// <returns>��</returns>
    virtual void Next() = 0;

    /// <summary>
    ///     ��ȡ��ǰ��¼ֵ
    /// </summary>
    /// <returns>��ǰ��¼ֵ</returns>
    virtual String Value() = 0;
    virtual String Name() = 0;

    /// <summary>
    ///     ����ָ���ؼ��ֵ�����
    /// </summary>
    /// <param name="key">��������</param>
    /// <returns>����ֵ</returns>
    virtual String Lookup(const String&) = 0;

    /// <summary>
    ///     ȡ�ü�¼����
    /// </summary>
    /// <returns>���Լ�¼����</returns>
    virtual int GetCount() = 0;
};

typedef shared<IMarkupAttribute> MarkupAttributePtr;

class IMarkupNode;
typedef shared<IMarkupNode> MarkupNodePtr;

class IMarkupNode : public RefObject
{
public:

    virtual ~IMarkupNode() {}

    /// <summary>
    ///     ȡ�õ�ǰ�ڵ�ָ��������������ֵ
    /// </summary>
    /// <remarks>
    ///     Ҳ�����Ȼ�ȡ���Լ�����ȡֵ
    /// </remarks>
    /// <param name="key">��������</param>
    /// <returns>����ֵ</returns>
    virtual String Attribute(const String& key) const = 0;

    /// <summary>
    ///     ��ȡ���Լ���
    /// </summary>
    /// <returns>���Լ��϶���</returns>
    virtual MarkupAttributePtr Attributes() = 0;

    /// <summary>
    ///     ��ȡ��ǰ�ڵ�����
    /// </summary>
    /// <returns>�ڵ�����</returns>
    virtual String Name() = 0;

    /// <summary>
    ///     ��ȡ��ǰ�ӽڵ�����
    /// </summary>
    /// <returns>�ӽڵ�����</returns>
    virtual String ChildName() = 0;

    /// <summary>
    ///     ���ü�¼����һ��
    /// </summary>
    /// <returns>��</returns>
    virtual void Reset() = 0;

    /// <summary>
    ///     �ж��Ƿ񵽼�¼ĩβ
    /// </summary>
    /// <returns>true����¼ĩβ</returns>
    virtual bool HasNext() = 0;

    /// <summary>
    ///     �ƶ��ӽڵ㵽��һ��
    /// </summary>
    /// <returns>��</returns>
    virtual void Next() = 0;

    /// <summary>
    ///     ��ȡ��ǰ�ӽڵ����
    /// </summary>
    /// <returns>�ӽڵ����</returns>
    virtual MarkupNodePtr ChildNode() = 0;

    /// <summary>
    ///     ��ȡ��ǰ�ӽڵ����
    /// </summary>
    /// <returns>�ӽڵ����</returns>
    virtual int GetCount() = 0;
};

enum eBuildType { eNone, eElement, eResource, eProperty };

typedef delegate<ElementPtr()> BuildListener;
typedef delegate<ObjectPtr(const String&, IMarkupNode*, eBuildType)> ElementBuilder;
typedef delegate<ObjectPtr(const String&, const String&)> AttributeReader;

typedef delegate<bool(ObjectPtr,MessageParameter)> MessageListener;

typedef delegate<ObjectPtr(ObjectPtr)> ContentBuilder;

class IInitializeHook : public RefObject
{
public:

    virtual ~IInitializeHook() {}

    virtual void OnStart(ElementPtr root, ObjectPtr&) = 0;
    virtual void OnEnd(ElementPtr root, ObjectPtr&) = 0;
    virtual void OnError(const String& error) = 0;
};

typedef shared<IInitializeHook> InitializeHookPtr;

class TimerIdentity : public RefObject
{
public:

    int id;
    int elapse;
    bool started;

    TimerIdentity()
        : id(0)
        , elapse(10)
        , started(false)
    {}
};

typedef shared<TimerIdentity> TimerIdentityPtr;

typedef delegate<void(int)> TimerFunc;

class TimerEntity : public RefObject
{
public:

    TimerEntity()
    {
    }

    void SetAssigner(AssignerPtr assigner)
    {
        _assigner = assigner;
    }

    AssignerPtr GetAssigner()
    {
        return _assigner;
    }

    virtual void OnTimer(int id)
    {
        ;
    }

    virtual void OnLeftTimer(int id)
    {

    }

    virtual bool IsEndOf() const
    {
        return false;
    }

protected:

    AssignerPtr _assigner;
};

typedef shared<TimerEntity> TimerEntityPtr;

struct AnimateItem
{
    ImagePtr img;

    int elapse;
    int transparent;
    int x;
    int y;
    int w;
    int h;
    int flag;
};

struct GifDescriptor
{
    unsigned short w;
    unsigned short h;

    unsigned char packed;
    unsigned char bkIndex;
    unsigned char pixelAspect;

    Color bkcolor;
};

}

# endif
