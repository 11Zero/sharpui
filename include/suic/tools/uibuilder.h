// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����uibuilder.h
// ��  �ܣ����湹���ࡣ
// 
// ��  �ߣ�����
// ʱ  �䣺2012-08-02
// 
// ============================================================================

# ifndef _UIBUILDER_H_
# define _UIBUILDER_H_

#include <suic/core/uiobject.h>
#include <suic/core/uiinterface.h>
#include <suic/framework/uiwindow.h>

namespace suic
{

class SUICORE_API Builder : public Object
{
public:

    Builder();
    Builder(ElementBuilder bl);

    virtual ~Builder();

    /// <summary>
    ///     ������ʽ�����ļ������ظ�Ԫ��
    /// </summary>
    /// <remarks>
    ///     �˺���������Դ�ļ����ɽ���Ԫ�أ��ⲿ���Դ���
    ///     ��Ԫ�ص�ʵ���࣬ϵͳ��ʹ�ô��������Ԫ�أ�Ҳ��
    ///     �Դ���һ����������Դ����������ϵͳ��ʹ�ô����
    ///     ��Դ�����ʼ��Ԫ����ʽ������ʹ��ϵͳĬ�ϣ����鴫�룩
    /// </remarks>
    /// <param name="parent">
    ///     ��Ԫ��ʵ����
    /// </param>
    /// <param name="res">
    ///     ��Դ�����ļ�
    /// </param>
    /// <returns>��Ԫ�ض������main��Ϊ�գ���Ϊmain</returns>
    ObjectPtr Build(ObjectPtr parent, const AsciiStr& res);

    /// <summary>
    ///     Ԫ�ش���������ӿ�
    /// </summary>
    /// <remarks>
    ///     Ԫ�ش���ʱϵͳ�Զ�����ע��ӿڽ��д���
    ///     �˽ӿ�ע�������һ���Ե��ã���ʹ�������Զ�����
    /// </remarks>
    /// <param name="bl">
    ///     Ԫ�ش���������
    /// </param>
    /// <returns>��</returns>
    void AddListener(const suic::String& name, suic::BuildListener bl);

    /// <summary>
    ///     Ԫ�ش���������ӿ�
    /// </summary>
    /// <remarks>
    ///     Ԫ�ش���ʱϵͳ�Զ�����ע��ӿڽ��д���
    ///     �˽ӿ�ע������������Ե�Ԫ�ش����ӿ�
    /// </remarks>
    /// <param name="bl">
    ///     Ԫ�ش���������
    /// </param>
    /// <returns>��</returns>
    static void RegisterElement(const suic::String& name, suic::BuildListener bl);

protected:

    // ��ʱ��Դ��ȡ�ص��ӿ�
    ElementBuilder _builder;
    // ��ʱԪ�ش�������ע��ӿ�
    Map<suic::String, BuildListener> _builders;
};

}

# endif
