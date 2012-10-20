// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����Label.h
// ��  �ܣ���ǩ�ؼ���֧����Ϸ�ʽʵ�֡�
// 
// ��  �ߣ�����
// ʱ  �䣺2011-07-02
// 
// ============================================================================

# ifndef _UILABEL_H_
# define _UILABEL_H_

#include <sui/sharpuiconfig.h>
#include <suicore/uicontentcontrol.h>

namespace ui
{

class SHARPUI_API Label : public suic::ContentControl
{
public:

    Label();
    Label(suic::String text);

    virtual ~Label();

    DECLAREBUILD(Label)

    void OnInitialized();
    suic::Size MeasureOverride(const suic::Size& availableSize);

protected:

    virtual void OnRender(suic::DrawingContext * drawing);
};

typedef suic::shared<Label> LabelPtr;

};

# endif