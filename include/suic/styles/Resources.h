// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����Resources.h
// ��  �ܣ���Դ�ķ���ʵ�֡�
// 
// ��  �ߣ�����
// ʱ  �䣺2011-08-02
// 
// ============================================================================

# ifndef _UIRESOURCS_H_
# define _UIRESOURCS_H_

#include <suicore/uiconst.h>
#include <suicore/uiobject.h>

namespace suic 
{

class Resources;
typedef Shared<Resources> ResourcesPtr;

class Resources : public RefObject
{
public:

    String TargetName;
    ResourceDictionaryPtr Resources;
    StyleCollection Styles;

    Resources();
    virtual ~Resources();

    int GetCount() const;
    ResourcesPtr GetResources(int index);
    ResourcesPtr Lookup(const String& targetName) const;
    void SetResources(const String& targetName, ResourcesPtr resources);

    void Clear();

    String ToString();

protected:

    ObjectPtr _items;
};

typedef Shared<ResourceDictionary> ResourceDictionaryPtr;

}

#endif
