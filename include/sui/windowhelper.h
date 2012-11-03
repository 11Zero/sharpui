// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����WndHelper.h
// ��  �ܣ�ʵ�ִ��ڵĻ��������������������ԵĴ�ȡ��
// 
// ��  �ߣ�����
// ʱ  �䣺2010-09-23
// 
// ============================================================================

# ifndef _UIWNDHELPER_H_
# define _UIWNDHELPER_H_

#include <sui/sharpuiconfig.h>
#include <suicore/uicontrol.h>

namespace ui
{

/*****************************************************************
* ���н���Ԫ����Ļ��࣬ʵ��һ�����Ԫ�صĹ��������ͽӿ�.
*/
class SHARPUI_API WndHelper : public suic::Object
{
public:

    WndHelper(suic::ElementPtr p);
    virtual ~WndHelper();

    bool OpenClipboard();
    void CloseClipboard();

    int PasteText(suic::String & text);
    int CutText(suic::String & text);
    int CopyText(const suic::String & text);

protected:

    suic::ElementPtr ePtr;
};

};

# endif