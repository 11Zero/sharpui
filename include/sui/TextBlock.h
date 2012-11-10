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

class SHARPUI_API TextBlock : public suic::FrameworkElement
{
public:

    TextBlock();
    TextBlock(suic::String text);

    virtual ~TextBlock();

    bool IsSingle() const;
    void SetSingle(bool val);

    DECLAREBUILD(TextBlock)

protected:

    suic::Size MeasureOverride(const suic::Size& availableSize);

    void OnInitialized();
    void OnRender(suic::DrawingContext * drawing);

    void OnSetterChanged(suic::SetterChangedEventArg& e);

protected:

    bool _single;
};

typedef suic::shared<TextBlock> TextBlockPtr;

inline bool TextBlock::IsSingle() const
{
    return _single;
}

inline void TextBlock::SetSingle(bool val)
{
    _single = val;
}

};

# endif
