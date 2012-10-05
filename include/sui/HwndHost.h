// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����HwndHost.h
// ��  �ܣ�ʵ����ʵ����Ƕ��
// 
// ��  �ߣ�����
// ʱ  �䣺2012-08-31
// 
// ============================================================================

# ifndef _UIHWNDHOST_H_
# define _UIHWNDHOST_H_

#include <sui/sharpuiconfig.h>
#include <suicore/uicontrol.h>

namespace ui
{

// ============================================================================
// GridView��
// ============================================================================

class SHARPUI_API HwndHost : public suic::Control
{
public:

    HwndHost();
    virtual ~HwndHost();

    DECLAREBUILD(HwndHost)

    suic::Handle GetHandle() const;
    void Sethandle(suic::Handle h);

protected:

    virtual void OnInitialized();

    virtual void OnRender(suic::DrawingContext * drawing);

    virtual suic::Size MeasureOverride(const suic::Size& size);
    virtual suic::Size ArrangeOverride(const suic::Size& size);

protected:

    suic::Handle _handle;
};

typedef suic::shared<HwndHost> HwndHostPtr;

inline suic::Handle HwndHost::GetHandle() const
{
    return _handle;
}

inline void HwndHost::Sethandle(suic::Handle h)
{
    _handle = h;
}

};

# endif
