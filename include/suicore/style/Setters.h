// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����ResourceDictionary.h
// ��  �ܣ���Դ�ֵ�ķ���ʵ�֡�
// 
// ��  �ߣ�����
// ʱ  �䣺2011-08-02
// 
// ============================================================================

# ifndef _UISTYLESETTERS_H_
# define _UISTYLESETTERS_H_

#include <suicore/uiconst.h>
#include <util/dictionary.h>

namespace suic 
{

class SUICORE_API Setter : public RefObject
{
public:

    ObjectPtr Value;
    String Property;
    String RefKey;
    int From;

    Setter(int val)
        : From(val)
    {
        ;
    }
};

struct SUICORE_API PropertyDependent
{ 
    int index; 
    String property;
    String name;

    PropertyDependent()
        : index(0)
    {
        ;
    }

    bool operator <(const PropertyDependent& Other)
    {
        return name < Other.name;
    }

    bool operator >(const PropertyDependent& Other)
    {
        return name > Other.name;
    }
};

typedef shared<Setter> SetterPtr;

class SUICORE_API SetterCollection : public Dictionary<String, SetterPtr, RefObject >
{
public:

    SetterCollection();

    void SetSetter(SetterPtr setter);
    SetterPtr GetSetter(const String& property);
};

typedef shared<SetterCollection> SetterCollectionPtr;

}

#endif
