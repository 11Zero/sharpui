// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����StyleTriggers.h
// ��  �ܣ�Ԫ�ش����ķ���ʵ�֡�
// 
// ��  �ߣ�����
// ʱ  �䣺2011-08-02
// 
// ============================================================================

# ifndef _UISTYLETRIGGERS_H_
# define _UISTYLETRIGGERS_H_

#include <suicore/uiconst.h>
#include <suicore/style/Setters.h>
#include <util/vector.h>

namespace suic 
{

class SUICORE_API Trigger : public RefObject
{
public:

    String Key;
    String Property;
    String Value;
    String SourceName;

    SetterCollectionPtr Setters;
    Set<PropertyDependent> ResourceDriven;

public:

    Trigger();

    SetterPtr GetSetter(const String& property);
    ObjectPtr GetValue(const String& property);
};

typedef shared<Trigger> TriggerPtr;

class SUICORE_API TriggerCollection : public Dictionary<String, TriggerPtr>
{
public:

    TriggerCollection();

    void SetTrigger(TriggerPtr trg);
};

}

#endif
