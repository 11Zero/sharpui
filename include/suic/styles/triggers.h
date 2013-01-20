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

#include <suic/core/uiconst.h>
#include <suic/styles/Setters.h>
#include <suic/tools/vector.h>

namespace suic 
{

class SUICORE_API Trigger : public RefObject
{
protected:

    // ��Դ���������
    int _index;
    // �ؼ���
    String _key;
    // Trigger����
    String _property;
    // Triggerֵ
    String _value;
    String _sourceName;

    // Trigger������ֵ
    SetterCollectionPtr _setters;

public:

    Trigger(int val);

    void SetSetter(SetterPtr val);
    SetterPtr GetSetter(const String& property);
    ObjectPtr GetValue(const String& property);

    String ToString();

public:

    SetterCollectionPtr& Setters();

    int GetIndex() const;

    String GetKey() const;
    void SetKey(String val);

    String GetProperty() const;
    void SetProperty(String val);

    String GetValue() const;
    void SetValue(String val);

    String GetSourceName() const;
    void SetSourceName(String val);
};

typedef shared<Trigger> TriggerPtr;

class SUICORE_API TriggerCollection : public Object
{
public:

    Map<String, TriggerPtr> TriggerColl;

    TriggerCollection();

    void SetTrigger(TriggerPtr trg);
    TriggerPtr GetTrigger(const String& property);

    bool ContainsKey(const String& property);
    String ToString();

};

}

#endif
