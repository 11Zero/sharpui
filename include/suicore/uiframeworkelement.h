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

#include <suicore/uielement.h>
#include <suicore/uiinterface.h>
#include <suicore/drawing/uiBrush.h>

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

    /// <summary>
    ///     ���½�����Դ������OnStyleUpdated�¼�
    /// </summary>
    /// <returns>��</returns> 
    void UpdateStyle();
    void UpdateLoaded(ObjectPtr target);
    void UpdateUnloaded(ObjectPtr target);

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

// ���Է��ʶ���
public:

    /// <summary>
    /// ���ý���Ԫ�ص���ʽ����
    /// </summary>
    /// <remarks>
    /// ���ý�����ʽ����Ӱ��Ԫ�صĳ��֣����bStyleΪtrue��
    /// �򽫻�ʹ����ʽ��ʼ��Ԫ�صĿ�ȡ��߶ȵȹ������ԡ�
    /// ���һᴥ��OnSetterChanged()�¼����á�
    /// </remarks>
    /// <param name="thePtr">
    ///     ��ʽ����
    /// </param>
    /// <returns>��</returns> 
    DEFINE_PROPERTY(StylePtr, Style, thePtr);

    UIPROPERTY(FrameworkElementPtr, Owner);
    UIPROPERTY(String, Text);

    DEFINE_PROPERTY_R(CursorPtr, Cursor);

    /// <summary>
    /// ����Ԫ����ʾ��Ϣ
    /// </summary>
    /// <remarks>
    /// ������Ԫ��ʱ������ʾ���뿪ʱ�ر�
    /// ��ʾ��Ϣ����Ϊ�ı���Ҳ����ΪContent����
    /// </remarks>
    /// <returns>��ʾ��Ϣ</returns> 
    DEFINE_PROPERTY(ObjectPtr, ToolTip, tip);

    DEFINE_PROPERTY(int, ActrualWidth, value);
    DEFINE_PROPERTY(int, ActrualHeight, value);

    DEFINE_PROPERTY(Int32, Width, value);
    DEFINE_PROPERTY(Int32, Height, value);
    DEFINE_PROPERTY(Rect, Padding, rc);

    /// <summary>
    /// ����Ԫ�ر߾�
    /// </summary>
    /// <remarks>
    /// Ԫ�ر߾���Զ����丸����ƫ��
    /// </remarks>
    /// <returns>Ԫ�ر߾�</returns> 
    DEFINE_PROPERTY(Rect, Margin, rc);

    /// <summary>
    /// ����Ԫ����С�߶�
    /// </summary>
    /// <returns>��С�߶�</returns> 
    DEFINE_PROPERTY(Int32, MinHeight, value);
    DEFINE_PROPERTY(Int32, MinWidth, value);
    DEFINE_PROPERTY(Rect, BorderThickness, border);
    DEFINE_PROPERTY(Int32, MaxHeight, value);
    DEFINE_PROPERTY(Int32, MaxWidth, value);

public:

    virtual bool OnReadingChild(ObjectPtr& pChild, IMarkupNode* pNode);

    virtual void ArrangeVisual();

    void OnVisibilityChanged(bool visible);

    Size MeasureCore(const Size & availableSize);
    Size MeasureOverride(const Size& availableSize);

    void EndInit();
    void OnRender(DrawingContext * drawing);

    void OnSetterChanged(SetterChangedEventArg& e);
    void OnGotFocus(suic::FocusEventArg& e);
    void OnMouseEnter(MouseEventArg& e);
    void OnSetCursor(CursorEventArg& e);

    virtual void OnStyleUpdated();

    virtual void OnScrollChanged(ScrollChangedEventArg& e);
    virtual void MeasureInArranging(const Size& size);

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

    Uint16 _iCommand;
    suic::FrameworkElementPtr _owerElem;

    String _text;

    ObjectPtr _tooltip;

    // ����Ԫ�صĿ�Ⱥ͸߶�
    suic::Int32 _width;
    suic::Int32 _height;

    // ����Ԫ����С�ߴ�,���ܱ�����
    Size _sizeMin;

    // ����Ԫ�����ߴ�,���ܱ�����
    Size _sizeMax;

    Rect _thickness;
    CursorPtr _cursor;

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
    return _style;
}

#include "frameworkelement.inl"

}

#endif
