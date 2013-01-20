// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����Style.h
// ��  �ܣ�Ԫ����ʽ�ķ���ʵ�֡�
// 
// ��  �ߣ�����
// ʱ  �䣺2011-08-02
// 
// ============================================================================

# ifndef _UISTYLE_H_
# define _UISTYLE_H_

#include <suic/styles/Triggers.h>
#include <suic/styles/Setters.h>

namespace suic
{

class Style;
typedef shared<Style> StylePtr;
typedef Map<String, StylePtr> StyleMap;

class SUICORE_API Style : public RefObject
{

public:

    TriggerCollection& Triggers();
    SetterCollectionPtr& Setters();
    StyleMap& StylePart();

    String GetKey() const;
    String GetTargetType() const;
    String GetBasedOnKey() const;
    StylePtr GetBasedOn() const;

    void SetKey(String);
    void SetTargetType(String);
    void SetBasedOnKey(String);
    void SetBasedOn(StylePtr val);

protected:

    String _key;
    String _targetType;
    String _basedOnKey;
    StylePtr _basedOn;

    TriggerCollection _triggers;
    SetterCollectionPtr _setters;
    Map<String, StylePtr> _stylePart;

public:

    Style();
    virtual ~Style();

    StylePtr Clone();

    void SetSetter(SetterPtr val);

    SetterPtr GetSetter(const String& property);
    ObjectPtr GetValue(const String& property);
    SetterPtr GetSetter(const String& state, const String& property);

    TriggerPtr GetTrigger();
    TriggerPtr GetTrigger(const String& state);

    StylePtr GetStylePart(const String& part);

    String ToString();
};

class SUICORE_API StyleCollection : public Object
{
public:

    Map<String, StylePtr> StyleColl;

    StyleCollection();

    StylePtr GetStyle(const String& property);
    void SetStyle(StylePtr value); 
};

}

#endif
