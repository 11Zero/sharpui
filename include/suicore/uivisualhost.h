// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����VisualHost.h
// ��  �ܣ����Ӹ�Ԫ�ص������࣬�ڴ�Ԫ������ʾ��Ԫ���൱�����ⴰ��
// 
// ��  �ߣ�����
// ʱ  �䣺2011-12-25
// 
// ============================================================================

# ifndef _UIVISUALHOST_H_
# define _UIVISUALHOST_H_

#include <suicore/uiframeworkelement.h>
#include <suicore/hwndadapter.h>

namespace suic
{

/// <summary>
/// VisualHost����
/// </summary>
class SUICORE_API VisualHost : public suic::RefObject
{
public:

    VisualHost();
    virtual ~VisualHost();

    virtual void SetValue(const String&, ObjectPtr);
    virtual ObjectPtr GetValue(const String&);

    virtual Handle GetHandle() const;
    void SetHandle(Handle h);

    void SetNeedRender(bool val);
    bool IsNeedRender() const;

    void SetHostElement(FrameworkElementPtr host);
    virtual FrameworkElementPtr GetHostElement() const;

    /// <summary>
    ///     ���úͻ�ȡ����������ƫ��
    /// </summary>
    /// <remarks>
    ///     �������ɸ�Ԫ�ص������Ϊ��������Ԫ���ڻ����е�
    ///     λ����SetOffset���ã���С�ο�SetSize�������塣
    /// </remarks>
    /// <param name="offset">
    ///     ��Ԫ��ƫ��
    /// </param>
    /// <returns>��</returns>
    void SetOffset(Point offset);
    Point GetOffset();

    /// <summary>
    ///     ��ȡ��Ԫ������Ļ�е�λ��
    /// </summary>
    /// <remarks>
    ///     ��Ԫ������Ļ�е�λ���ɻ�������Ļλ��ƫ��
    ///     ��SetOffset���õ�ֵ��
    /// </remarks>
    /// <returns>��Ļλ��ƫ��</returns>
    virtual Point GetScreenPoint();

    void SetSize(Size size);
    Size GetSize();

    virtual void UpdateLayout();
    virtual void Invalidate(const Rect* lpRect, bool bForce);

    virtual void SetMouseCapture();
    virtual void ReleaseMouseCapture();

    //-----------------------------------------------

    /// <summary>
    ///     ��Ⱦ����Ԫ��
    /// </summary>
    /// <remarks>
    ///     �˷���ˢ��ָ������Ľ���Ԫ�أ����lprcΪnull��
    ///     ��ˢ����������Ԫ�ء�
    /// </remarks>
    /// <param name="h">
    ///     ���ھ��
    /// </param>
    /// <param name="lprc">
    ///     ��Ч����
    /// </param>
    /// <returns>��</returns>
    virtual void OnRender(Handle h, const Rect* lprc);
    virtual void OnRender(const Rect* lprc);

    ObjectPtr GetHostInfo();

    //---------------------------------------------------

    void AddTopMost(Element* pElem);
    void InsertTopMost(int index, Element* pElem);
    bool RemoveTopMost(Element* pElem);
    int GetTopMostCount() const;
    Element* GetTopMost(int index);

    //---------------------------------------------------

public:

    virtual bool HandleEvent(MessageParameter& mp);
    virtual bool HandleEvent(Handle h, Uint32 message
        , Uint32 wp, Uint32 lp, Uint32& result);

    virtual void OnLoaded();
    virtual void OnUnloaded();

protected:

    suic::Point _offset;
    suic::Point _screenOffset;

    suic::Size _size;

    Handle _handle;
    ObjectPtr _datas;

    suic::FrameworkElementPtr _host;
};

typedef suic::shared<VisualHost> VisualHostPtr;

};

# endif
