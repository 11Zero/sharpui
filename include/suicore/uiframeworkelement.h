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
    ///     ȡ�ý���Ԫ�ص���ʽ����
    /// </summary>
    /// <returns>��ʽ����</returns> 
    StylePtr GetStyle();

    /// <summary>
    ///     ���ý���Ԫ�ص���ʽ����
    /// </summary>
    /// <remarks>
    ///     ���ý�����ʽ����Ӱ��Ԫ�صĳ��֣����bStyleΪtrue��
    ///     �򽫻�ʹ����ʽ��ʼ��Ԫ�صĿ�ȡ��߶ȵȹ������ԡ�
    ///     ���һᴥ��OnSetterChanged()�¼����á�
    /// </remarks>
    /// <param name="thePtr">
    ///     ��ʽ����
    /// </param>
    /// <returns>��</returns> 
    void SetStyle(StylePtr thePtr);

    /// <summary>
    ///     ���½�����Դ������OnStyleUpdated�¼�
    /// </summary>
    /// <returns>��</returns> 
    void UpdateStyle();
    void UpdateLoaded(ObjectPtr target);
    void UpdateUnloaded(ObjectPtr target);

    /// <summary>
    ///     ���ҽ���Ԫ�ص���Դ
    /// </summary>
    /// <remarks>
    ///     ��Դ�ǿ��Լ̳еģ�ϵͳ���ӱ�Ԫ������ָ����Դ��
    ///     Ȼ������������ֱ���ҵ�һ����Դ��
    ///     ��󽫻�����ϵͳ��Դ��Application���壩��
    /// </remarks>
    /// <param name="strName">
    ///     ��Դ����
    /// </param>
    /// <returns>��Դ����</returns> 
    ObjectPtr FindResource(const String& strName);

    /// <summary>
    ///     ���ý���Ԫ�ر������Դ����
    /// </summary>
    /// <param name="resources">��Դ����</param>
    /// <returns>��</returns> 
    void SetResources(ResourceDictionaryPtr resources);

    /// <summary>
    ///     ��ý���Ԫ�ر������Դ����
    /// </summary>
    /// <returns>��Դ����</returns> 
    ResourceDictionaryPtr& GetResources();

    /// <summary>
    ///     ���ý���Ԫ�ص�ӵ����
    /// </summary>
    /// <remarks>
    ///     ��һ����������Ķ���ӵ�к��������һЩ
    ///     ��Ϊ������ӵ���ߵ����ƺ�Ӱ��
    /// </remarks>
    /// <param name="elemPtr">
    ///     ӵ�еĽ���Ԫ��
    /// </param>
    /// <returns>��</returns> 
    void SetOwner(FrameworkElementPtr elemPtr);

    /// <summary>
    ///     ��ý���Ԫ�ص�ӵ����
    /// </summary>
    /// <returns>����Ԫ�ص�ӵ����</returns> 
    FrameworkElementPtr& GetOwner();

    void SetToolTip(ObjectPtr tip);
    ObjectPtr GetToolTip() const;

    void ShowToolTip(Point pt);

    Uint16 GetCommand() const;
    void SetCommand(Uint16 iCmd);

    /// <summary>
    ///     ���ý���Ԫ�ص��ı���
    /// </summary>
    /// <param name="text">
    ///     ����Ԫ���ı�
    /// </param>
    /// <returns>��</returns>
    virtual void SetText(const String & text);
    virtual String GetText();

    bool IsRender() const;

    CursorPtr GetCursor();

    /// <summary>
    ///     �жϽ���Ԫ���Ƿ�ѹ�¡�
    /// </summary>
    /// <returns>true: Ԫ�ر�ѹ��</returns>
    bool IsSelected() const;

    virtual String ToString();

    suic::Int32 GetWidth() const;
    void SetWidth(suic::Int32 value);
    suic::Int32 GetHeight() const;
    void SetHeight(suic::Int32 value);

    int GetActrualWidth() const;
    void SetActrualWidth(int value);
    int GetActrualHeight() const;
    void SetActrualHeight(int value);

    /// <summary>
    ///     ����Ԫ�ر߾�
    /// </summary>
    /// <remarks>
    ///     Ԫ�ر߾���Զ����丸����ƫ��
    /// </remarks>
    /// <returns>Ԫ�ر߾�</returns> 
    const Rect& GetMargin() const;
    void SetMargin(Rect rc);

    Rect GetPadding() const;
    void SetPadding(Rect rc);

    Int32 GetMaxHeight() const;
    void SetMaxHeight(Int32 value);
    Int32 GetMaxWidth() const;
    void SetMaxWidth(Int32 value);

    /// <summary>
    ///     ����Ԫ����С�߶�
    /// </summary>
    /// <remarks>
    ///     Ԫ�ر߾���Զ����丸����ƫ��
    /// </remarks>
    /// <returns>Ԫ�ر߾�</returns> 
    Int32 GetMinHeight() const;
    void SetMinHeight(Int32 value);
    Int32 GetMinWidth() const;
    void SetMinWidth(Int32 value);

    Rect GetBorderThickness() const;
    void SetBorderThickness(Rect border);

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

inline StylePtr FrameworkElement::GetStyle()
{
    return _style;
}

#include "frameworkelement.inl"

}

#endif
