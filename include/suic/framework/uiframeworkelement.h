// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����UIFrameworkElement.h
// ��  �ܣ�������Ŀ��FrameElement���ࡣ
// 
// ��  �ߣ�����
// ʱ  �䣺2010-05-02
// 
// ============================================================================

# ifndef _UIFRAMEELEMENT_H_
# define _UIFRAMEELEMENT_H_

#include <suic/framework/uielement.h>
#include <suic/core/uiinterface.h>
#include <suic/graphics/uiBrush.h>
#include <suic/graphics/uifont.h>

namespace suic
{

class FrameworkElement;
typedef shared<FrameworkElement> FrameworkElementPtr;

typedef delegate<void(suic::Element*, ContextMenuEventArg&)> ContextMenuEventHandler;

/// <summary>
/// ��ܽ���Ԫ����Ļ��࣬ʵ�ֿ�ܽ���Ԫ�صĹ��������ͽӿ�.
/// </summary>
class SUICORE_API FrameworkElement : public Element
{
public:

    FrameworkElement();
    virtual ~FrameworkElement();

    DeclareTypeofInfo(FrameworkElement, Element)

    void ResetStyle();

    /// <summary>
    ///     ���½�����Դ������OnStyleUpdated�¼�
    /// </summary>
    /// <returns>��</returns> 
    void UpdateStyle();

    void DoInit();

    void UpdateLoaded(ObjectPtr target);
    void UpdateUnloaded(ObjectPtr target);

    /// <summary>
    ///     ��Trigger�¼����»�����Դ
    /// </summary>
    /// <returns>��</returns>
    void UpdateSetters(const String& trigger);

    /// <summary>
    /// ���ҽ���Ԫ�ص���Դ
    /// </summary>
    /// <remarks>
    /// ��Դ�ǿ��Լ̳еģ�ϵͳ���ӱ�Ԫ������ָ����Դ��
    /// Ȼ������������ֱ���ҵ�һ����Դ��
    /// ��󽫻�����ϵͳ��Դ��Application���壩��
    /// </remarks>
    /// <param name="strName">
    ///     ��Դ����
    /// </param>
    /// <returns>��Դ����</returns> 
    ObjectPtr FindResource(const String& strName);

    /// <summary>
    /// ���ý���Ԫ�ر������Դ����
    /// </summary>
    /// <param name="resources">��Դ����</param>
    /// <returns>��</returns> 
    void SetResources(ResourceDictionaryPtr resources);

    /// <summary>
    /// ��ý���Ԫ�ر������Դ����
    /// </summary>
    /// <returns>��Դ����</returns> 
    ResourceDictionaryPtr& GetResources();

    /// <summary>
    ///     ���ý���Ԫ�ص�ӵ����
    /// </summary>
    /// <remarks>
    /// ��һ����������Ķ���ӵ�к��������һЩ
    /// ��Ϊ������ӵ���ߵ����ƺ�Ӱ��
    /// </remarks>
    /// <param name="elemPtr">
    /// ӵ�еĽ���Ԫ��
    /// </param>
    /// <returns>��</returns> 
    void SetOwner(FrameworkElementPtr elemPtr);

    /// <summary>
    /// ��ý���Ԫ�ص�ӵ����
    /// </summary>
    /// <returns>����Ԫ�ص�ӵ����</returns> 
    FrameworkElementPtr& GetOwner();

    void ShowToolTip(Point pt);

    Uint16 GetCommand() const;
    void SetCommand(Uint16 iCmd);

    void SetSelected(bool val);
    bool Enable(bool val);

    virtual String ToString();
    void SetInternalValue(String key, ObjectPtr val);
    ObjectPtr GetInternalValue(const String& key);

public:

    static DpPropertyEntity WidthProperty;
    static DpPropertyEntity HeightProperty;
    static DpPropertyEntity MinWidthProperty;
    static DpPropertyEntity MinHeightProperty;
    static DpPropertyEntity MaxWidthProperty;
    static DpPropertyEntity MaxHeightProperty;

    static DpPropertyEntity BackgroundProperty;
    static DpPropertyEntity ForegroundProperty;
    static DpPropertyEntity BorderBrushProperty;
    static DpPropertyEntity FontProperty;

    static DpPropertyEntity CursorProperty;
    static DpPropertyEntity ToolTipProperty;

    static DpPropertyEntity BorderThicknessProperty;
    static DpPropertyEntity VerticalContentAlignmentProperty;
    static DpPropertyEntity HorizontalContentAlignmentProperty;

// ���Է��ʶ���
public:

    /// <summary>
    /// ���ý���Ԫ�ص���ʽ����
    /// </summary>
    /// <remarks>
    /// ���ý�����ʽ����Ӱ��Ԫ�صĳ��֣����bStyleΪtrue��
    /// �򽫻�ʹ����ʽ��ʼ��Ԫ�صĿ�ȡ��߶ȵȹ������ԡ�
    /// ���һᴥ��OnPropertyChanged()�¼����á�
    /// </remarks>
    /// <param name="thePtr">
    ///     ��ʽ����
    /// </param>
    /// <returns>��</returns> 
    StylePtr GetStyle() const;
    void SetStyle(StylePtr val);

    virtual String GetText() const;
    virtual void SetText(const String& val);

    CursorPtr GetCursor() const;
    bool IsInVisual() const;

    /// <summary>
    /// ����Ԫ����ʾ��Ϣ
    /// </summary>
    /// <remarks>
    /// ������Ԫ��ʱ������ʾ���뿪ʱ�ر�
    /// ��ʾ��Ϣ����Ϊ�ı���Ҳ����ΪContent����
    /// </remarks>
    /// <returns>��ʾ��Ϣ</returns> 
    ObjectPtr GetToolTip() const;
    void SetToolTip(ObjectPtr val);

    int GetActrualWidth() const;
    void SetActrualWidth(int val);

    int GetActrualHeight() const;
    void SetActrualHeight(int val);

    Int32 GetWidth() const;
    void SetWidth(Int32 val);

    Int32 GetHeight() const;
    void SetHeight(Int32 val);

    Rect GetPadding() const;
    void SetPadding(Rect val);

    /// <summary>
    /// ����Ԫ�ر߾�
    /// </summary>
    /// <remarks>
    /// Ԫ�ر߾���Զ����丸����ƫ��
    /// </remarks>
    /// <returns>Ԫ�ر߾�</returns> 
    Rect GetMargin() const;
    void SetMargin(Rect val);

    /// <summary>
    /// ����Ԫ����С�߶�
    /// </summary>
    /// <returns>��С�߶�</returns> 
    Int32 GetMinHeight() const;
    void SetMinHeight(Int32 val);

    Int32 GetMinWidth() const;
    void SetMinWidth(Int32 val);

    Rect GetBorderThickness() const;
    void SetBorderThickness(Rect val);

    Int32 GetMaxHeight() const;
    void SetMaxHeight(Int32 val);

    Int32 GetMaxWidth() const;
    void SetMaxWidth(Int32 val);

    /// <summary>
    ///  ȡ��Ԫ�����ݵ�ˮƽ���뷽ʽ
    /// </summary>
    /// <remarks>
    ///  ���뷽ʽ��Left��Center��Right��
    /// </remarks>
    /// <returns>����ˮƽ���뷽ʽ</returns> 
    int GetHorizontalContentAlignment() const;
    void SetHorizontalContentAlignment(int val);

    /// <summary>
    ///  ȡ��Ԫ�����ݵĴ�ֱ���뷽ʽ
    /// </summary>
    /// <remarks>
    ///  ���뷽ʽ��Top��Center��Bottom��
    /// </remarks>
    /// <returns>��ֱ���ݶ��뷽ʽ</returns> 
    int GetVerticalContentAlignment() const;
    void SetVerticalContentAlignment(int val);

    BrushPtr GetBackground() const;
    void SetBackground(BrushPtr val);

    BrushPtr GetBorderBrush() const;
    void SetBorderBrush(BrushPtr val);

    BrushPtr GetForeground() const;
    void SetForeground(BrushPtr val);

    FontPtr GetFont() const;
    void SetFont(FontPtr val);

public:

    virtual void ArrangeVisual();

    Size MeasureCore(const Size & availableSize);
    Size MeasureOverride(const Size& availableSize);

    void OnRender(DrawingContext * drawing);

    void OnVisibilityChanged(bool visible);
    void OnStateChanged(StateChangedEventArg& e);
    void OnMouseEnter(MouseEventArg& e);
    void OnSetCursor(CursorEventArg& e);

    virtual void OnStyleUpdated();
    virtual void OnScrollChanged(ScrollChangedEventArg& e);
    virtual void MeasureInArranging(const Size& size);
    virtual bool OnReadingChild(ObjectPtr& pChild, IMarkupNode* pNode);

    void BeginInit();
    void EndInit();

protected:

    /// <summary>
    ///     ����������Ĵ�С�������С���������ơ�
    /// </summary>
    /// <remarks>
    ///     ����߶ȺͿ���Ѿ����ã���ʹ������ֵ��
    /// </remarks>
    /// <param name="desiredSize">
    ///     �������������������С
    /// </param>
    /// <returns>��</returns>
    void MeasureCheck(Size & desiredSize);

protected:

    // ���汾����Դ
    ResourceDictionaryPtr _resources;
    // �������Ԫ����Ⱦ����
    StylePtr _styleCache;

    String _text;
    Uint16 _iCommand;
    bool _inVisual;

    BrushPtr _backgrnd;
    BrushPtr _foregrnd;
    BrushPtr _brbrush;
    FontPtr _font;

    suic::FrameworkElementPtr _owerElem;
};

inline String FrameworkElement::ToString()
{
    return GetText();
}

inline StylePtr FrameworkElement::GetStyle() const
{
    return _styleCache;
}

#include "frameworkelement.inl"

}

#endif
