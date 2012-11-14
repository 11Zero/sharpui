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

#include <suicore/style/Triggers.h>
#include <suicore/style/Setters.h>

namespace suic
{

class UIStyle;
typedef shared<UIStyle> StylePtr;

class SUICORE_API UIStyle : public RefObject
{
public:

    String Key;
    String TargetType;
    String BasedOn;
    String RefStyle;
    StylePtr RefBasedOn;

    TriggerCollection Triggers;
    SetterCollectionPtr Setters;
    Map<String, StylePtr> StylePart;

    //Vector<String> ContainerDriven;
    Set<PropertyDependent> ResourceDriven;

public:

    UIStyle();
    virtual ~UIStyle();

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

class SUICORE_API StyleCollection : public Dictionary<String, StylePtr,suic::Object>
{
public:

    StyleCollection();

    StylePtr GetStyle(const String& property);
    void SetStyle(StylePtr value);
};

}

#endif
