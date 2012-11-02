// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����uipanel.h
// ��  �ܣ��������Ļ��ࡣ
// 
// ��  �ߣ�����
// ʱ  �䣺2010-11-02
// 
// ============================================================================

# ifndef _UIPANEL_H_
# define _UIPANEL_H_

#include <suicore/uiframeworkelement.h>
#include <suicore/uielementcollection.h>

namespace suic
{

/// <summary>
/// ����������Ԫ����Ļ��࣬ʵ��һ�����Ԫ�صĹ��������ͽӿ�.
/// </summary>
class SUICORE_API Panel : public FrameworkElement
{
public:

    Panel();
    virtual ~Panel();

    // �����಻�Ƽ�ʹ������������в��֡�������
    ElementCollectionPtr & Children();

    //LogicalChildren

    bool SetItemsHost(bool value);
    bool IsItemsHost();

    /// <summary>
    ///     ȡ��Ԫ�ص�zIndex
    /// </summary>
    /// <param name="element">
    ///     ���õ�Ԫ��
    /// </param>
    /// <returns>Z��������</returns> 
    static int GetZIndex(suic::Element* element);
    static void SetZIndex(suic::Element* element, int value);

    void SetHorizontalOffset(int val);
    void SetVerticalOffset(int val);

    int GetVisibleStart() const;
    int GetVisibleCount() const;

protected:

    ElementCollectionPtr & InternalChildren();
    int InternalChildCount() const;
    Element* InternalChild(int index);

    /// <summary>
    ///     ����������Ԫ�ص�zIndex
    /// </summary>
    /// <returns>��</returns> 
    void RecomputeZState();

    /// <summary>
    ///     ����������Ĳ��֡�
    /// </summary>
    /// <remarks>
    ///     ��������û��ȥ����Ԫ�صı߿��С��
    /// </remarks>
    /// <param name="pElem">�����Ԫ��</param>
    /// <param name="size">
    ///     ��Ԫ���ṩ�Ŀ��������С
    /// </param>
    /// <returns>����Ԫ��������λ������</returns>
    static Rect ArrangeCheck(Element* pElem, const Size & size);

public:

    Size MeasureOverride(const Size& availableSize);
    suic::Size ArrangeOverride(const suic::Size& size);

    void OnSetterChanged(suic::SetterChangedEventArg& e);
    void OnScrollChanged(ScrollChangedEventArg& e);
    void OnRenderSizeChanged(RenderSizeChangedEventArg& e);

    void OnRender(DrawingContext * drawing);

    Int32 GetChildrenCount();
    suic::Element* GetChild(int index);

    int AddChild(suic::ObjectPtr child);
    int InsertChild(int index, suic::ObjectPtr child);
    void ClearChildren();
    void RemoveChild(suic::ObjectPtr child);

    suic::Visual* GetVisualChild(int index);

    void OnGotFocus(FocusEventArg& e);
    void OnLostFocus(FocusEventArg& e);

protected:

    ElementCollectionPtr _elementConnection;
    IntVector _zIndex;
    IntVector _tabIndex;

    // ��������һ��Ԫ�����߼����е�����
    int _visibleStart;
    int _visibleCount;

    // ˮƽƫ��λ��
    int _horizontalOffset;
    // ��ֱƫ��λ��
    int _verticalOffset;

    // ��屳��ɫ
    ImagePtr _cavas;
};

typedef shared<Panel> PanelPtr;

inline int Panel::GetVisibleStart() const
{
    return _visibleStart;
}

inline int Panel::GetVisibleCount() const
{
    return _visibleCount;
}

inline void Panel::SetHorizontalOffset(int val)
{
    _horizontalOffset = val;
}

inline void Panel::SetVerticalOffset(int val)
{
    _verticalOffset = val;
}

inline suic::Element* Panel::GetChild(int index)
{
    return _elementConnection->GetElement(index);
}

inline Int32 Panel::GetChildrenCount()
{
    return _elementConnection->GetCount();
}

};

# endif
