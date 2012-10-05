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

#include <suicore/uiobject.h>

namespace suic
{

class Image;

/*-
* ���ƽӿ��࣬���һ��Ļ��ƣ��ߵ���ɫ���ñ�׼����ɫ��ʾ
* ���ʽΪ��
*/
class DrawingContext : public RefObject
{
public:

    virtual ~DrawingContext() {};

    virtual void SetOffset(int x, int y) = 0;

    // ȡ��ԭʼ�Ĳü�����
    virtual Rect* RenderClip() = 0;
    virtual Size CalculateText(const Char * text, int size, int fmt) = 0;

    // ���òü�����
    virtual void PushClip(const Rect* rcClip) = 0;
    virtual void PushTextColor(Color clr) = 0;
    // �ָ���һ�βü�����
    virtual void Pop() = 0;

    virtual void SetPixel(int x, int y, Color clr) = 0;
    /*-
    * ���ܣ� ����һ��ֱ��
    * ������ pt1-��ʼ�㣻pt2-�յ㣻n-�ߵĺ�ȣ�clr-�ߵ���ɫ
    */
    virtual void DrawLine(Point pt1, Point pt2, Uint16 n, Color clr) = 0;
    virtual void DrawRectangle(Rect rc, Uint16 n, Color clr) = 0;
    virtual void DrawRoundRectangle(Rect rc, Uint16 n, Uint16 w, Uint16 h, Color clr) = 0;
    virtual void DrawFocused(const Rect * lprc) = 0;

    virtual void DrawImage(Image* img, const Rect* rcdc, const Rect* rcimg, Byte alpha) = 0;
    virtual void DrawTransparent(Image* img, const Rect* rcdc, const Rect* rcimg, Color trans) = 0;

    virtual void FillRectangle(Rect rc, Color clr) = 0;
    virtual void DrawGradient(const Rect* rc, Color dwFirst, Color dwSecond, bool bVertical) = 0;

    virtual void DrawText(const Char * text, int size, const Rect * rc, Color color, Uint32 horz, Uint32 vert) = 0;
    virtual void DrawText(const Char * text, int size, const Rect * rc
        , Color bkcolor, Color color, Uint32 horz, Uint32 vert) = 0;
};

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
    virtual bool Load(const Byte* data, Int32 size) = 0;

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

