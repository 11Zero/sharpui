// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����stringcore.h
// ��  �ܣ�������Ŀ���ַ�������
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _STRINGCORE_H_
# define _STRINGCORE_H_

#include <suic/types/uitypes.h>
#include <suic/tools/asciistr.h>

namespace suic
{

extern SUICORE_API const Int32 npos;
extern SUICORE_API const int LOCAL_CODE;
extern SUICORE_API const int UTF8_CODE;

/// <summary>
/// �ַ�����ķ�װ.
/// </summary>
class SUICORE_API String
{
public:

    String();

    String(Int32 value);
    String(Double value);
    String(const char* value, int code=LOCAL_CODE);
    String(const Char* value);
    String(const Char* value, Int32 count);
    String(Char c, Int32 count);
    String(const Char* value, Int32 startIndex, Int32 length);
    String(const String& other);

    virtual ~String();

    static bool Equals(const String a, const String b);
    static Int32 GetCharSize(const Char* value);
    static Uint32 HexToInt32(const String& str);
    static Uint32 HexToAlphaColor(const String& str);
    static String Int32ToHex(Uint32 hex);

    int GetHashCode() const;
    Int32 Length() const;

    bool EndsWith(const String value) const;
    bool Contains(const String value) const;
    bool Equals(const String& value) const;

    int Compare(const String& Other) const;

    bool Empty() const;
    int ToInt();
    double ToDouble();

    Char* c_str() const;
    AsciiStr utf8_str() const;

    bool operator <(const String& Other);
    bool operator >(const String& Other);
    bool operator ==(const String& Other);

    String operator=(const String& Other);
    String operator+=(const String& Other);

    SUICORE_API friend bool operator==(const String& first, const String& second);
    SUICORE_API friend String operator+(const String& first, const String& second);

    Int32 IndexOf(Char value, int startIndex) const;
    Int32 IndexOf(String value) const;
    Int32 IndexOf(String value, int startIndex) const;
    Int32 IndexOf(Char value, int startIndex, int count) const;
    Int32 IndexOf(String value, int startIndex, int count) const;

    String Remove(int startIndex);
    String Remove(int startIndex, int count);
    String Replace(Char oldChar, Char newChar);
    String Replace(String oldValue, String newValue);

    String Insert(int startIndex, String insertValue);

    String Substring(int startIndex) const;
    String Substring(int startIndex, int length) const;

    String ToLower();
    String ToString();
    String ToUpper();
    String Trim();

    void Resize(int size);

    String Format(const Char * szFormat, ...);

    Char operator[](Int32 index);
	const Char operator[](Int32 index) const;

protected:

    Char * _Ptr;
};

};

# endif
