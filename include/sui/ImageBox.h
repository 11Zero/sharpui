// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����ImageBox.h
// ��  �ܣ�ʵ��ͼ��ؼ���
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _IMAGEBOX_H_
# define _IMAGEBOX_H_

#include <sui/sharpuiconfig.h>
#include <suicore/uiframeworkelement.h>

namespace ui
{

class SHARPUI_API ImageBox : public suic::FrameworkElement
{
public:

    ImageBox();
    ImageBox(suic::String source);

    virtual ~ImageBox();

    DECLAREBUILD(ImageBox)

    //Uri GetBaseUri();
    //void GetBaseUri(Uri);
    /// <summary>
    ///     ����ͼ��ؼ���ʾ��ͼ��·��
    /// </summary>
    /// <param name="source">ͼ��·��</param>
    /// <returns>true:���óɹ���false:����ʧ��</returns>
    bool SetSource(suic::String source);

    bool SetSourceFromMemory(const suic::Byte* pData, suic::Uint64 len);

    /// <summary>
    ///     ȡ��ͼ��ؼ�Դ������һ��ͼ�����
    /// </summary>
    /// <returns>ͼ�����</returns>
    suic::ImagePtr GetSource() const;

    bool IsValid() const;

protected:

    suic::Size MeasureOverride(const suic::Size& availableSize);

    void OnInitialized();
 
    void OnRender(suic::DrawingContext * drawing);
    void OnLoaded(suic::LoadedEventArg& e);

protected:

    // ͼ��Դ����
    suic::ImagePtr _source;

};

typedef suic::shared<ImageBox> ImageBoxPtr;

};

# endif
