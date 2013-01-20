// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����UIDrawing.h
// ��  �ܣ�������ƽӿ�
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-12
// 
// ============================================================================

# ifndef _UIDRAWIN_H_
# define _UIDRAWIN_H_

#include <suic/core/uiobject.h>
#include <suic/graphics/uigeometry.h>
#include <suic/graphics/uibrush.h>
#include <suic/graphics/uipen.h>

namespace suic
{

class Image;

/// <summary>
///  �ı���������
/// </summary>
typedef struct tagFormattedText
{
    bool single;
    bool ellipsis;

    // CoreFlags::Left,CoreFlags::Right,CoreFlags::Center
    int horzAlign;
    // CoreFlags::Top,CoreFlags::Bottom,CoreFlags::Center
    int vertAlign;

    // -1�������ı�����
    Color bkcolor;
    // Ĭ��Ϊ0����ɫ��
    Color color;
    // ����
    Handle font;

    tagFormattedText()
        : color(ARGB(255,0,0,1))
        , bkcolor(-1)
        , single(true)
        , ellipsis(false)
        , horzAlign(CoreFlags::Left)
        , vertAlign(CoreFlags::Center)
        , font(0)
    {
        ;
    }

}FormattedText;

/// <summary>
///  ���ƽӿ��࣬���һ��Ļ��ƣ��ߵ���ɫ���ñ�׼����ɫ��ʾ
/// </summary>
class __declspec(novtable) DrawingContext : public RefObject
{
public:

    virtual ~DrawingContext() {};

    void SetOffset(int x, int y);
    Point GetOffset() const;

    //---------------------------------------------------------------

    virtual Handle GetHandle() const = 0;
    virtual Rect GetClip() = 0;

    virtual Size CalculateText(const Char * text, int size, const FormattedText* att) = 0;

    virtual void PushClip(const Rect* rcClip) = 0;
    virtual void PushTextColor(Color clr) = 0;

    virtual void Pop() = 0;

    virtual void SetPixel(int x, int y, Color clr) = 0;

    virtual void DrawLine(Pen* pen, Point pt0, Point pt1) = 0;
    virtual void DrawRectangle(Rect rc, Uint16 n, Color clr) = 0;
    virtual void DrawRoundRectangle(Rect rc, Uint16 n, Uint16 w, Uint16 h, Color clr) = 0;
    virtual void DrawFocusedRectangle(const Rect * lprc) = 0;
    virtual void DrawGradient(const Rect* rc, Color dwFirst, Color dwSecond, bool bVertical) = 0;

    virtual void DrawEllipse(Color clr, Point center, Double radiusX, Double radiusY) = 0;

    virtual void DrawImage(Image* img, const Rect* rcdc, const Rect* rcimg, Byte alpha) = 0;
    virtual void DrawImage(Image* img, const Rect* rcdc, const Rect* rcimg, Byte alpha, Color trans) = 0;

    virtual void DrawText(const Char * text, int size, const Rect * rc, const FormattedText* att) = 0;

    virtual void FillRectangle(Rect rc, Color clr) = 0;

    //void DrawVideo(MediaPlayer player, Rect rectangle);

    //void PushClip(Geometry clipGeometry);
    //void PushOpacityMask(Brush brush);
    //void PushOpacity(Double opacity);

    //------------------------------------------------------------

protected:

    // ����ƫ��
    Point _offset;
};

inline void DrawingContext::SetOffset(int x, int y)
{
    _offset.x = x;
    _offset.y = y;
}

inline Point DrawingContext::GetOffset() const
{
    return _offset;
}

typedef shared<DrawingContext> DrawingContextPtr;

class Image : public RefObject
{
public:

    virtual ~Image() {};

    virtual bool IsValid() const = 0;
    virtual void SetMaskColor(Color clr) = 0;

    virtual bool Load(const String& strFile) = 0;
    virtual bool Load(Handle hRes, const String& strName, const String& strType) = 0;
    virtual bool LoadIcon(const Handle icon) = 0;
    virtual bool LoadHandle(const Handle bmp) = 0;
    virtual bool Load(const Byte* data, suic::Uint64 size) = 0;
    virtual bool Load(const Byte* data, int w, int h) = 0;

    virtual bool Save(const String& filename, int iType) = 0;

    virtual Handle GetHandle() = 0;
    virtual void Detach() = 0;

    virtual int Width() = 0;
    virtual int Height() = 0;
    virtual bool IsAlpha() = 0;
    virtual void Clear() = 0;
};

typedef shared<Image> ImagePtr;

};

# endif
