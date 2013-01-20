// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����uikeyboard.h
// ��  �ܣ�ʵ�ֱ�׼�Ĵ�����ʽ��
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _UIKEYBOARD_H_
# define _UIKEYBOARD_H_

#include <suic/framework/uielement.h>

namespace suic
{

class SUICORE_API Keyboard : public Object
{
private:

    Keyboard();
    ~Keyboard();
    
public:

    static ElementPtr GetKeyBoardFocused();
    static void SetKeyBoardFocused(ElementPtr);

    static ElementPtr GetFocused();
    static bool SetFocus(ElementPtr);

    static bool IsFocusedWithin(ElementPtr);

};

};

# endif
