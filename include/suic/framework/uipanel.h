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

#include <suic/framework/uiframeworkelement.h>
#include <suic/tools/uielementcollection.h>

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

    DeclareTypeofInfo(Panel, FrameworkElement)

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

    void SetInternalValue(String key, ObjectPtr val);

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
    Rect ArrangeCheck(Element* pElem, const Rect & Rect);

public:

    Int32 GetChildrenCount();
    suic::Element* GetChild(int index);

    int AddChild(suic::ObjectPtr child);
    int InsertChild(int index, suic::ObjectPtr child);
    void ClearChildren();
    void RemoveChild(suic::ObjectPtr child);

    suic::Visual* GetVisualChild(int index);

protected:


    Size MeasureOverride(const Size& availableSize);
    suic::Size ArrangeOverride(const suic::Size& size);

    void OnScrollChanged(ScrollChangedEventArg& e);
    void OnRenderSizeChanged(RenderSizeChangedEventArg& e);

    void OnRender(DrawingContext * drawing);

protected:

    ElementCollectionPtr _elementConnection;
    Vector<int> _zIndex;
    Vector<int> _tabIndex;

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
