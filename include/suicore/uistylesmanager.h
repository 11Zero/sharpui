// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����UIStylesManager
// ��  �ܣ�������Ŀ����Դ��Դ�����ࡣ
// 
// ��  �ߣ�����
// ʱ  �䣺2012-08-02
// 
// ============================================================================

# ifndef _UISTYLESMANAGER_H_
# define _UISTYLESMANAGER_H_

#include <suicore/uiresource.h>

namespace suic
{

class StylesManager : public Object
{
public:

    virtual ~StylesManager() {};

    StyleSelectorPtr GetStyleSelector(const suic::String& name);
};

}

# endif
