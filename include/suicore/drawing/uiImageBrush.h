// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����ImageBrush.h
// ��  �ܣ�ʵ��ͼ��ˢ��
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _UIIMAGEBRUSH_H_
# define _UIIMAGEBRUSH_H_

#include <suicore/drawing/uiBrush.h>
#include <suicore/drawing/uidrawing.h>

namespace suic
{

class SUICORE_API ImageBrush : public Brush
{
public:

    ImageBrush();
    virtual ~ImageBrush();

    virtual bool Parse(const suic::String& xml);
    virtual bool Parse(void* node);
    virtual void Draw(DrawingContext* drawing, const Rect* lprc);
	virtual void Draw(DrawingContext* drawing, const Rect* lprc, const Rect* border);

    ImagePtr GetImage();
    Rect GetContentBrounds();

protected:

    ObjectPtr _data;
    ImagePtr _image;
};

typedef shared<ImageBrush> ImageBrushPtr;

};

# endif
