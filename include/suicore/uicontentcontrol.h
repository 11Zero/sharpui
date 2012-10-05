// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����uicontentcontrol.h
// ��  �ܣ�ʵ�ִ��ڵĻ��������������������ԵĴ�ȡ��
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _UICONTENTCONTROL_H_
# define _UICONTENTCONTROL_H_

#include <suicore/uicontrol.h>

namespace suic
{

// ====================================================
// ���ݽ���Ԫ����Ļ��࣬������һ����Ԫ�أ���������Padding.
// ������б߾���ƣ�������ʱ��Ĭ������Ԫ��������������
// ====================================================
class SUICORE_API ContentControl : public Control
{
public:

    ContentControl();
    virtual ~ContentControl();

    /// <summary>
    ///     ��ȡ���ݶ���
    /// </summary>
    /// <remarks>
    ///     ���ݶ������������FrameworkElement
    /// </remarks>
    /// <returns>���ݶ���</returns> 
    ObjectPtr GetContent();
    void SetContent(ObjectPtr contentPtr);

    /// <summary>
    ///     ���������ı�
    /// </summary>
    /// <remarks>
    ///     ���ı������������ݶ��󣬶��ǲ���������Ϊ����
    /// </remarks>
    /// <param name="text">�ı�</param>
    /// <returns>���ݶ���</returns> 
    void SetText(const String & text);

public:

    virtual suic::Size MeasureOverride(const suic::Size& size);
    virtual suic::Size ArrangeOverride(const suic::Size& size);
    
    virtual void OnInitialized();
    virtual void OnSetterChanged(SetterChangedEventArg& e);
    virtual void OnRender(DrawingContext * drawing);

    virtual void OnMouseLeftButtonDown(MouseEventArg& e);
    virtual void OnMouseLeftButtonDbclk(MouseEventArg& e);

    virtual void OnContentChanged(suic::ObjectPtr oldContent, suic::ObjectPtr newContent);

    virtual void AddLogicalChild(suic::Element* child);
    virtual suic::Element* GetLogicalChild(int index);
    virtual Int32 GetLogicalChildrenCount();

protected:

    // Ԫ�����ݶ���
    ElementPtr _content;
};

typedef shared<ContentControl> ContentControlPtr;

};

# endif
