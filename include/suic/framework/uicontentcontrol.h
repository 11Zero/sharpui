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

#include <suic/framework/uicontrol.h>

namespace suic
{

/// <summary>
/// ���ݽ���Ԫ����Ļ��࣬������һ����Ԫ�أ���������GetPadding().
/// ������б߾���ƣ�������ʱ��Ĭ������Ԫ��������������
/// </summary>
class SUICORE_API ContentControl : public Control
{
public:

    ContentControl();
    virtual ~ContentControl();

    DeclareTypeofInfo(ContentControl, Control)

public:

    static DpPropertyEntity ContentProperty;

public:

    /// <summary>
    ///     ���������ı�
    /// </summary>
    /// <remarks>
    ///     ���ı������������ݶ��󣬶��ǲ���������Ϊ����
    /// </remarks>
    /// <param name="text">�ı�</param>
    /// <returns>���ݶ���</returns> 
    void SetText(const String & text);

    void SetInternalValue(String key, ObjectPtr val);

// ���Է��ʶ���
public:

    /// <summary>
    ///     ��ȡ���ݶ���
    /// </summary>
    /// <remarks>
    ///     ���ݶ������������FrameworkElement
    /// </remarks>
    /// <returns>���ݶ���</returns> 
    ObjectPtr GetContent() const;
    void SetContent(ObjectPtr val);

public:

    virtual void OnContentChanged(suic::ObjectPtr oldContent, suic::ObjectPtr newContent);

    int AddChild(suic::ObjectPtr child);
    suic::Element* GetChild(int index);
    Int32 GetChildrenCount();
    void RemoveChild(suic::ObjectPtr child);

protected:

    suic::Size MeasureOverride(const suic::Size& size);
    suic::Size ArrangeOverride(const suic::Size& size);

    void OnInitialized();
    void OnRender(DrawingContext * drawing);

protected:

    // Ԫ�����ݶ���
    ElementPtr _content;
};

typedef shared<ContentControl> ContentControlPtr;

};

# endif
