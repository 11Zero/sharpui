// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����TextBlock.h
// ��  �ܣ�ʵ���ı�����ơ�
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _UITEXTBLOCK_H_
# define _UITEXTBLOCK_H_

#include <sui/sharpuiconfig.h>
#include <suicore/uicontrol.h>

namespace ui
{

class SHARPUI_API TextBlock : public suic::Control
{
public:

    TextBlock();
    TextBlock(suic::String text);

    virtual ~TextBlock();

    DECLAREBUILD(TextBlock)

    bool HandleFocus() const;

    virtual void OnInitialized();
    virtual suic::Size MeasureOverride(const suic::Size& availableSize);

protected:

    virtual void OnRender(suic::DrawingContext * drawing);

    virtual void OnMouseLeftButtonDown(suic::MouseEventArg& e);
    virtual void OnMouseLeftButtonUp(suic::MouseEventArg& e);

    virtual void OnMouseEnter(suic::MouseEventArg& e);
    virtual void OnMouseMove(suic::MouseEventArg& e);
    virtual void OnMouseLeave(suic::MouseEventArg& e);
};

typedef suic::shared<TextBlock> TextBlockPtr;

};

# endif