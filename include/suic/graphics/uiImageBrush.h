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

#include <suic/graphics/uiBrush.h>
#include <suic/graphics/uidrawing.h>

namespace suic
{

class SUICORE_API ImageBrush : public TileBrush
{
public:

    ImageBrush(suic::String path);
    virtual ~ImageBrush();

    virtual bool Parse(const suic::String& xml);
    virtual bool Parse(void* node);
    virtual void Draw(DrawingContext* drawing, const Rect* lprc);
	virtual void Draw(DrawingContext* drawing, const Rect* lprc, const Rect* border);

    ImagePtr GetImage();
    Rect GetContentBrounds();

protected:

    int CalcStretch(const String value);
    void SetValue(const String& key, const String& value);

protected:

    ImagePtr _image;
    String _value;
    bool _isInit;

    Rect _viewBox;
    Int16 _viewBoxUnits;

    Rect _viewport;
    Int16 _viewportUnits;
    Color _maskColor;
    Byte _opacity;

    Int16 _tileMode;
    Int16 _stretch;
    Int16 _alignmentX;
    Int16 _alignmentY;

    Rect _imageCorner;

    // ����ͼ���ĸ�������
    Rect _leftTopCorner;
    Rect _leftBottomCorner;
    Rect _rightTopCorner;
    Rect _rightBottomCorner;
};

typedef shared<ImageBrush> ImageBrushPtr;

};

# endif
