// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����CaretElement.h
// ��  �ܣ��������߼���
// 
// ��  �ߣ�����
// ʱ  �䣺2012-07-02
// 
// ============================================================================

# ifndef _UICARETELEMENT_H_
# define _UIAPPLICATION_H_

#include <suicore/uiframeworkelement.h>

namespace suic {

class SUICORE_API CaretElement : public FrameworkElement
{
public:

    CaretElement();
    virtual ~CaretElement();

    void Show();
    void Hide();

protected:

    void OnRender(DrawingContext * drawing);

};

}

# endif
