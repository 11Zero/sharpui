// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����Setter.h
// ��  �ܣ���Դ�ֵ�ķ���ʵ�֡�
// 
// ��  �ߣ�����
// ʱ  �䣺2011-08-02
// 
// ============================================================================

# ifndef _UISTYLESETTERS_H_
# define _UISTYLESETTERS_H_

#include <suic/core/uiconst.h>
#include <suic/tools/map.h>

namespace suic 
{

class SUICORE_API Setter : public RefObject
{
public:

    ObjectPtr Value;
    String Property;
    String DefValue;
    bool sealed;
    // ��� 0-����ֵ��1-�̳�ֵ
    int flag;

    Setter() : flag(0) {}
};

struct SUICORE_API PropertyDependent
{ 
    int index;
    String property;
    String name;

    PropertyDependent();

    bool operator <(const PropertyDependent& Other);
    bool operator >(const PropertyDependent& Other);
};

typedef shared<Setter> SetterPtr;
typedef Map<String, SetterPtr> SetterMap;

class SUICORE_API SetterCollection : public RefObject
{
public:

    SetterCollection();

    void SetSetter(SetterPtr setter);
    void SetValue(const String& property, ObjectPtr val);

    SetterPtr GetSetter(const String& property);
    ObjectPtr GetValue(const String& property);

    bool ContainsKey(const String& property);
    String ToString();

public:

    Set<PropertyDependent>& ResourceDriven();
    SetterMap& SetterColl();

protected:

    // ����������
    Set<PropertyDependent> _resourceDriven;
    Map<String, SetterPtr> _setterColl;
};

typedef shared<SetterCollection> SetterCollectionPtr;

inline Set<PropertyDependent>& SetterCollection::ResourceDriven()
{
    return _resourceDriven;
}

inline SetterMap& SetterCollection::SetterColl()
{
    return _setterColl;
}

}

#endif
