// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����AnimateBox.h
// ��  �ܣ�ʵ�ֶ����ؼ�
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-08
// 
// ============================================================================

# ifndef _UIANIMATEBOX_H_
# define _UIANIMATEBOX_H_

#include <sui/sharpuiconfig.h>
#include <suicore/uicontrol.h>

namespace ui
{

/// <summary>
///  �����ؼ����ܹ����عؼ�֡��GIF����
/// </summary>
class SHARPUI_API AnimateBox : public suic::Control
{
public:

    AnimateBox();
    virtual ~AnimateBox();

    DECLAREBUILD(AnimateBox)

    void Start();
    void Stop();

    /// <summary>
    ///     ȡ�ö������������е�֡����
    /// </summary>
    /// <param name="e">�¼�</param>
    /// <returns>����֡��</returns>
    int FrameCount() const;

    /// <summary>
    ///     ȡ�õ�ǰ��Ҫ���ŵ�֡��
    /// </summary>
    /// <param name="e">�¼�</param>
    /// <returns>��ǰ���ŵĶ���֡</returns>
    suic::ImagePtr CurrentFrame() const;
    int CurrentElapse() const;
    int CurrentTransparent() const;

    void NextFrame();
    void PrevFrame();
    void Clear();

    /// <summary>
    ///     ȡ�ö������������е�֡����
    /// </summary>
    /// <param name="bmp">֡ͼ��</param>
    /// <param name="iElapse">��һ֡�Ĳ���ʱ��</param>
    /// <returns>��</returns>
    void AddFrame(suic::ImagePtr bmp, int iElapse, int iTransparent);
    void AddGif(const suic::String& strPath);

protected:

    suic::Size MeasureOverride(const suic::Size& size);

    void OnSetterChanged(suic::SetterChangedEventArg& e);

    void OnInitialized();
    void OnLoaded(suic::LoadedEventArg& e);
    void OnRender(suic::DrawingContext * drawing);

    void OnTimer(int id);

protected:

    suic::Vector<suic::AnimateItem> _frames;

    // ��ǰ���ŵĶ���֡����
    int _curframe;
    int _anim_timer;

    int _wid;
    int _hei;

    suic::Color _bkcolor;

    suic::ImagePtr _frame;
    suic::TimerIdentityPtr _timerid;
};

typedef suic::shared<AnimateBox> AnimateBoxPtr;

inline int AnimateBox::FrameCount() const
{
    return static_cast<int>(_frames.size());
}

};

# endif