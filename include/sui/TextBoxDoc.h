// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����EditDoc.h
// ��  �ܣ�ʵ�ֱ�׼��win32�༭�ؼ���
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _UIEDITDOC_H_
# define _UIEDITDOC_H_

#include <sui/sharpuiconfig.h>
#include <suicore/uiobject.h>
#include <util/vector.h>

namespace ui
{

class Glyph;
typedef suic::shared<Glyph> GlyphPtr;

class Glyph : public suic::RefObject
{
public:

    virtual void Draw(suic::Handle hdc, suic::Rect * lprc) = 0;
    virtual void Bound(suic::Handle hdc, suic::Rect * lprc) = 0;
    virtual void GetText(suic::String & text) = 0;
    virtual void Insert(Glyph * gly, GlyphPtr igly) = 0;
    virtual void Add(GlyphPtr igly) = 0;
    virtual void Remove(int index) = 0;
    virtual void Remove(Glyph * gly) = 0;
    virtual GlyphPtr GetParent() = 0;
    virtual int GetChildCount() = 0;
    virtual GlyphPtr GetChild(int index) = 0;
};

class SHARPUI_API GlyphFactory : public suic::RefObject
{
public:

    static void Initialize();
    static GlyphPtr GetGlyph(suic::String & key);
    static int GetAveCharHei();
    static GlyphPtr GetGlyph(int key);

protected:

    static suic::StringMapPtr _glyphs;
};

class SHARPUI_API EditCache : public suic::RefObject
{
public:

    suic::Byte * _buff;
    suic::Uint32 _size;
    suic::Uint32 _maxsize;

    EditCache() 
        :_buff(NULL)
        , _size(0)
        , _maxsize(1024 * 1024) 
    {
    }

    void insert(suic::Byte * p, suic::Uint32 len, suic::Uint32 pos)
    {
    }

    void remove(suic::Uint32 pos, suic::Uint32 len)
    {
    }

    inline suic::Byte at(suic::Uint32 index)
    {
        return *(_buff + index);
    }
};

typedef suic::shared<EditCache> EditCachePtr;

typedef struct tagLineItem
{
    // һ���п�ʼƫ��λ��
    int _nBeg;
    // һ���н���ƫ��λ��
    int _nEnd;

    suic::Rect _rect;
    short _hf;
    short _clrText;
    short _clrSelText;
    short _clrSelTextBk;
}LineItem;

class TextBoxLine;
typedef suic::shared<TextBoxLine> EditLinePtr;

class SHARPUI_API TextBoxLine : public suic::RefObject
{
public:

    TextBoxLine();
    virtual ~TextBoxLine();

    void Draw(suic::DrawingContext * drawing, bool bActive, suic::Rect * lprc, suic::Color clrText);
    void DrawSel(suic::DrawingContext * drawing, bool bActive, suic::Rect * lprc, suic::Uint32 beg, suic::Uint32 end, suic::Color clrText);

    void GetText(suic::String & str);
    void GetSelText(suic::String & str, int beg, int len);

    void Add(suic::Char ch);
    void Add(const suic::String & str);
    void Add(const suic::Char * str, int len);

    void AddLine(const EditLinePtr & line);
    void AddLine(const EditLinePtr & line, int beg, int end);

    void Insert(suic::Char ch, int pos);
    void Insert(const suic::String & str, int pos);

    void Remove();
    void Remove(int beg, int end);

    /// <summary>
    ///     ѡ���ı�
    /// </summary>
    /// <remarks>
    ///     �˷�������beg��end�����ı�ѡȡ��
    /// </remarks>
    /// <param name="beg">
    ///     ��ʼλ��
    /// </param>
    /// <param name="end">
    ///     ����λ��
    /// </param>
    /// <returns>��</returns>
    void SelectWord(int & beg, int & end);
    suic::Uint32 GetCount();

    suic::Uint32 GetItemCount();
    void GetItem(suic::Uint32 index, LineItem & item);

    void GetRect(suic::Rect * lprc);
    int PointIn(suic::Point * lppt);

    int Offset(int index);
    int GetLineHei() { return _rcLine.bottom - _rcLine.top; };

    void RefleshRect();
    void RefleshRect(suic::Handle hdc);

protected:

    suic::Rect _rcLine;
    suic::String _buff;
    suic::Vector<LineItem> _items;
};

class SHARPUI_API TextBoxDoc : public suic::RefObject
{
public:

    TextBoxDoc();
    virtual ~TextBoxDoc();

    void Cut();
    void Copy();
    void Paste();
    void SelectAll();

    void DrawPassword(suic::DrawingContext * drawing, suic::Char ch, bool bActive
        , suic::Rect * lprc, suic::Color clrText);
    void DrawSingleLine(suic::DrawingContext * drawing, bool bActive, suic::Rect * lprc, suic::Color clrText);
    void Draw(suic::DrawingContext * drawing, bool bActive, suic::Rect * lprc, suic::Color clrText);

    void SetVisualRect(suic::Rect * lprc);
    suic::Rect GetVisualRect() const;

    void SetSingleLine(bool bSingle)
    {
        _bSingleLine = bSingle;
    }

    bool IsSingleLine() const
    {
        return _bSingleLine;
    }

    // ������Ϣ����
    int GetHorzScrollPos() const;
    int GetVertScrollPos() const;
    void SetHorzScrollPos(int nNewPos);
    void SetVertScrollPos(int nNewPos);

    void GetHorzScrollInfo(int & iVisual, int & iLogic);
    void GetVertScrollInfo(int & iVisual, int & iLogic);

    void Add(GlyphPtr gly);
    void Add(const suic::String & text);
    void Add(const suic::Char * text, suic::Uint32 len);
    void Add(suic::Char ch);

    void GetSelectText(suic::String & text);
    void GetText(suic::String & text);

    bool SetCaret(suic::Point * lppt);
    void TrackCaret(suic::Point * lppt);
    bool SelectWord(suic::Point * lppt);

    suic::Rect GetCaret(bool bUpDown);

    bool OnLineHome(bool bSel);
    bool OnLineEnd(bool bSel);

    bool OnPageNext(bool bSel);
    bool OnPagePrior(bool bSel);

    // �ƶ���굽���ӷ�Χ��ʼ
    bool OnVisualHome(bool bSel);
    bool OnVisualEnd(bool bSel);

    bool OnDocHome(bool bSel);
    bool OnDocEnd(bool bSel);

    bool OnLeftCaret(bool bSel);
    bool OnUpCaret(bool bSel);
    bool OnRightCaret(bool bSel);
    bool OnDownCaret(bool bSel);

    void CancelSelect();

    // �����ѡ�еķ���true������false
    bool DeleteSelect();
    void ReplaceSelect(const suic::String & text);
    void ReplaceSelect(const GlyphPtr gly);

    // �ڹ�괦����һ��
    void InsertLine();

    void DelLeftOne();
    void DelRightOne();

    // �Ƿ���ѡ��
    bool IsSelectMode();
    
    int GetCharHei() const
    {
        return _aveCharHei;
    }

    int GetCharWid() const
    {
        return _aveCharWid;
    }

    bool HasContent() const;

protected:

    void SetSelInfo(bool bSel, int * & nOffset, int * & nLine);
    bool RecalcCaret(bool bUpDown);
    bool NormalizeScroll();
    void CalcTextRect(suic::Rect * lprc, int nLine);
    bool CalcSelectPos(int & bline, int & bl, int & br, int & eline, int & el, int & er);

protected:

    EditCachePtr _textCache;
    suic::Vector<EditLinePtr> _lines;

    bool _bSingleLine;

    int _aveCharWid;
    int _aveCharHei;

    suic::Rect _rcVisual;
    suic::Rect _caretPos;
    suic::Rect _caretPrePos;

    int _horzScroll;
    int _vertScroll;

    int _caretLine;
    int _caretOffset;

    int _trackLine;
    int _trackOffset;

    suic::Color _textcolor;
};

inline suic::Rect TextBoxDoc::GetVisualRect() const
{
    return _rcVisual;
}

}

# endif
