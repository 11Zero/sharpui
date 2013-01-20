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

    /// <summary>
    /// ���ý���Ԫ�ص��ı���
    /// </summary>
    /// <param name="text">
    /// ����Ԫ���ı�
    /// </param>
    /// <returns>��</returns>
    virtual void SetText(const String & text);
    virtual String GetText();

    bool IsRender() const;

    /// <summary>
    /// �жϽ���Ԫ���Ƿ�ѹ�¡�
    /// </summary>
    /// <returns>true: Ԫ�ر�ѹ��</returns>
    bool IsSelected() const;

    virtual String ToString();
    ObjectPtr GetValue(const String& key);

public:

    static ElementPropertyPtr WidthProperty;
    static ElementPropertyPtr HeightProperty;
    static ElementPropertyPtr MinWidthProperty;
    static ElementPropertyPtr MinHeightProperty;
    static ElementPropertyPtr MaxWidthProperty;
    static ElementPropertyPtr MaxHeightProperty;

    static ElementPropertyPtr VerticalContentAlignmentProperty;
    static ElementPropertyPtr HorizontalContentAlignmentProperty;

    static ElementPropertyPtr BackgroundProperty;
    static ElementPropertyPtr ForegroundProperty;
    static ElementPropertyPtr BorderBrushProperty;
    static ElementPropertyPtr FontProperty;

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
    PROPERTYENTRY(StylePtr, Style, thePtr);

    PROPERTYRW(FrameworkElementPtr, Owner);
    PROPERTYRW(String, Text);

    PROPERTYENTRY_R(CursorPtr, Cursor);
    PROPERTYENTRY(bool, IsInVisual, val);

    /// <summary>
    /// ����Ԫ����ʾ��Ϣ
    /// </summary>
    /// <remarks>
    /// ������Ԫ��ʱ������ʾ���뿪ʱ�ر�
    /// ��ʾ��Ϣ����Ϊ�ı���Ҳ����ΪContent����
    /// </remarks>
    /// <returns>��ʾ��Ϣ</returns> 
    PROPERTYENTRY(ObjectPtr, ToolTip, tip);

    PROPERTYENTRY(int, ActrualWidth, value);
    PROPERTYENTRY(int, ActrualHeight, value);

    PROPERTYENTRY(Int32, Width, value);
    PROPERTYENTRY(Int32, Height, value);
    PROPERTYENTRY_RR(Rect, Padding, rc);

    /// <summary>
    /// ����Ԫ�ر߾�
    /// </summary>
    /// <remarks>
    /// Ԫ�ر߾���Զ����丸����ƫ��
    /// </remarks>
    /// <returns>Ԫ�ر߾�</returns> 
    PROPERTYENTRY_RR(Rect, Margin, rc);

    /// <summary>
    /// ����Ԫ����С�߶�
    /// </summary>
    /// <returns>��С�߶�</returns> 
    PROPERTYENTRY(Int32, MinHeight, value);
    PROPERTYENTRY(Int32, MinWidth, value);
    PROPERTYENTRY(Rect, BorderThickness, border);
    PROPERTYENTRY(Int32, MaxHeight, value);
    PROPERTYENTRY(Int32, MaxWidth, value);

    /// <summary>
    ///  ȡ��Ԫ�����ݵ�ˮƽ���뷽ʽ
    /// </summary>
    /// <remarks>
    ///  ���뷽ʽ��Left��Center��Right��
    /// </remarks>
    /// <returns>����ˮƽ���뷽ʽ</returns> 
    PROPERTYENTRY(int, HorizontalContentAlignment, val);

    /// <summary>
    ///  ȡ��Ԫ�����ݵĴ�ֱ���뷽ʽ
    /// </summary>
    /// <remarks>
    ///  ���뷽ʽ��Top��Center��Bottom��
    /// </remarks>
    /// <returns>��ֱ���ݶ��뷽ʽ</returns> 
    PROPERTYENTRY(int, VerticalContentAlignment, val);

    PROPERTYENTRY(BrushPtr, Background, val);
    PROPERTYENTRY(BrushPtr, BorderBrush, val);
    PROPERTYENTRY(BrushPtr, Foreground, val);
    PROPERTYENTRY(FontPtr, Font, val);

public:

    virtual bool OnReadingChild(ObjectPtr& pChild, IMarkupNode* pNode);
    virtual void ArrangeVisual();

    void OnVisibilityChanged(bool visible);

    Size MeasureCore(const Size & availableSize);
    Size MeasureOverride(const Size& availableSize);

    void OnRender(DrawingContext * drawing);

    void OnPropertyChanged(PropertyChangedEventArg& e);
    void OnStateChanged(StateChangedEventArg& e);

    void OnGotFocus(suic::FocusEventArg& e);
    void OnMouseEnter(MouseEventArg& e);
    void OnSetCursor(CursorEventArg& e);

    virtual void OnStyleUpdated();

    virtual void OnScrollChanged(ScrollChangedEventArg& e);
    virtual void MeasureInArranging(const Size& size);

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
    StylePtr _basedOn;

    Uint16 _iCommand;
    suic::FrameworkElementPtr _owerElem;

    String _text;

    ObjectPtr _tooltip;
    bool _inVisual;

    Rect _thickness;
    CursorPtr _cursor;

    BrushPtr _backgrnd;
    BrushPtr _foregrnd;
    BrushPtr _brbrush;
    FontPtr _font;
};

inline bool FrameworkElement::IsRender() const
{
    return !ReadFlag(CoreFlags::IsNotRender);
}

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
