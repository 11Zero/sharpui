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

// =========================================================
// ����������Ԫ����Ļ��࣬ʵ��һ�����Ԫ�صĹ��������ͽӿ�.
//
class SUICORE_API Panel : public FrameworkElement
{
public:

    Panel();
    virtual ~Panel();

    ElementCollectionPtr & Children();

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

protected:

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

    virtual suic::Size ArrangeOverride(const suic::Size& size);

    virtual void OnRender(DrawingContext * drawing);

    virtual void AddLogicalChild(suic::Element* child);
    virtual void InsertLogicalChild(int index, suic::Element* child);
    virtual void ClearLogicalChildren();
    virtual void RemoveLogicalChild(suic::Element* child);

    virtual suic::Visual* GetVisualChild(int index);
    virtual suic::Element* GetLogicalChild(int index);
    virtual Int32 GetLogicalChildrenCount();

    virtual void OnGotFocus(FocusEventArg& e);
    virtual void OnLostFocus(FocusEventArg& e);

protected:

    ElementCollectionPtr _elementConnection;
    IntVector _zIndex;
    IntVector _tabIndex;

    int _horizontalOffset;
    int _verticalOffset;
};

typedef shared<Panel> PanelPtr;

inline void Panel::SetHorizontalOffset(int val)
{
    _horizontalOffset = val;
}

inline void Panel::SetVerticalOffset(int val)
{
    _verticalOffset = val;
}

};

# endif
