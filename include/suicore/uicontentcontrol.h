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

/// <summary>
/// ���ݽ���Ԫ����Ļ��࣬������һ����Ԫ�أ���������Padding.
/// ������б߾���ƣ�������ʱ��Ĭ������Ԫ��������������
/// </summary>
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

    suic::Size MeasureOverride(const suic::Size& size);
    suic::Size ArrangeOverride(const suic::Size& size);
    
    void OnInitialized();
    void OnSetterChanged(SetterChangedEventArg& e);
    void OnRender(DrawingContext * drawing);

    void OnMouseLeftButtonDown(MouseEventArg& e);
    void OnMouseLeftButtonDbclk(MouseEventArg& e);

    void OnContentChanged(suic::ObjectPtr oldContent, suic::ObjectPtr newContent);

    int AddChild(suic::ObjectPtr child);
    suic::Element* GetChild(int index);
    Int32 GetChildrenCount();

protected:

    // Ԫ�����ݶ���
    ElementPtr _content;
};

typedef shared<ContentControl> ContentControlPtr;

};

# endif
