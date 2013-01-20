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

#include <suic/core/stringcore.h>
#include <suic/core/uiobject.h>

namespace suic
{

class SUICORE_API OString : public RefObject
{
public:

    OString();
    OString(const String& value);
    OString(const OString& Other);
    OString(Int32 value);

    String ToString();
    Double ToDouble();
    Int32 ToInt32();
    bool ToBool();
    Rect ToRect();
    Size ToSize();
    Point ToPoint();
    Color ToColor();

    String& operator*() { return _value; }

protected:

    String _value;
};

}

# endif
