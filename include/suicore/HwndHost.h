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

#include <suicore/uiframeworkelement.h>

namespace suic
{

/// <summary>
/// ������ʵ���ھ����������ʱ�Ŵ����С���ڡ�
/// </summary>
class SUICORE_API HwndHost : public suic::FrameworkElement
{
public:

    HwndHost();
    virtual ~HwndHost();

    DECLAREBUILD(HwndHost)

    suic::Handle GetHandle() const;
    void Sethandle(suic::Handle h);

protected:

    void OnInitialized();

    void OnLoaded(LoadedEventArg& e);
    void OnUnloaded(LoadedEventArg& e);

    void OnRender(suic::DrawingContext * drawing);

    suic::Size MeasureOverride(const suic::Size& size);
    suic::Size ArrangeOverride(const suic::Size& size);

protected:

    void BuildWindow(Handle hwndParent);
    void UpdateWindowPos();

protected:

    // ��ʵ���ھ��
    suic::Handle _handle;
    // �Ƿ�Ϊ�ڲ��������
    bool _selfHost;
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
