// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����uiResource.h
// ��  �ܣ�������Դ���ࡣ
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _UIRESOURCE_H_
# define _UIRESOURCE_H_

#include <suicore/uiobject.h>
#include <suicore/uiconst.h>

namespace suic
{

class SUICORE_API Resource : public RefObject
{
public:

    virtual ~Resource() {}

    inline String GetKey() const;
    inline void SetKey(const String& key);

    inline String GetName() const;

protected:

    String _key;
    String _name;
};

inline String Resource::GetKey() const 
{ 
    return _key; 
}

inline void Resource::SetKey(const String& key) 
{ 
    _key = key; 
}

inline String Resource::GetName() const 
{ 
    return _name; 
}

}

# endif
