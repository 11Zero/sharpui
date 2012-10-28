// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����UIString.h
// ��  �ܣ�������Ŀ��String���͡�
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _UISTRING_H_
# define _UISTRING_H_

#include <suicore/stringcore.h>
#include <suicore/uiobject.h>

namespace suic
{

class SUICORE_API UString : public RefObject
{
public:

    UString(const String& value);
    UString(Int32 value);

    virtual String ToString();
    virtual Double ToDouble();
    virtual Int32 ToInt32();
    virtual bool ToBool();
    virtual Rect ToRect();
    virtual Size ToSize();
    virtual Point ToPoint();
    virtual Color ToColor();

    String& operator*() { return _value; }

protected:

    String _value;
};

}

# endif
