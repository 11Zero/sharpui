// ���ڿƼ���Ȩ���� 2010-2012
// 
// �ļ�����Visual.h
// ��  �ܣ�������Ŀ�Ŀ��Ӷ������дӴ˶���̳е�Ԫ�ض����Գ����ڽ����ϡ�
// 
// ��  �ߣ�����
// ʱ  �䣺2010-05-01
// 
// ============================================================================

# ifndef _UIVISUAL_H_
# define _UIVISUAL_H_

#include <suic/core/uiobject.h>
#include <suic/core/uiassigner.h>
#include <suic/graphics/uidrawing.h>
#include <suic/graphics/uigeometry.h>
#include <suic/framework/uidpproperty.h>
#include <suic/framework/uidpobject.h>

namespace suic
{

class SUICORE_API Visual : public DpObject
{
public:

    Visual();
    virtual ~Visual();

    DeclareAbstractTypeofInfo(Visual, DpObject)

    /// <summary>
    ///     ��ȡ����Ԫ�ص����д�С��
    /// </summary>
    /// <remarks>
    ///     ��������ܻ����Ԫ�ر������Ⱦ����
    /// </remarks>
    /// <returns>����Ԫ�ص����д�С</returns>
    const suic::Rect& VisualDescendantBounds() const;

    /// <summary>
    ///     ��ȡ����Ԫ����Ը�Ԫ�ص�ƫ�ơ�
    /// </summary>
    /// <returns>��Ը�Ԫ�ص�ƫ��</returns>
    const suic::Point& GetVisualOffset() const;

    /// <summary>
    ///     �õ����Ӹ�Ԫ�ء�
    /// </summary>
    /// <returns>���Ӹ�Ԫ��</returns>
    suic::Visual* GetParent() const;

    /// <summary>
    ///     ȡ�ÿ�����Ԫ�ظ�����
    /// </summary>
    /// <returns>������Ԫ�ظ���</returns>
    virtual int GetVisualChildrenCount();

    /// <summary>
    ///     ȡ�ÿ�����Ԫ�ء�
    /// </summary>
    /// <remarks>
    ///     ��Ԫ����ÿ�ε���Arrangeʱ���ᱻ�����Ȼ�����¼��㡣
    /// </remarks>
    /// <param name="index">Ԫ������</param>
    /// <returns>������Ԫ��</returns>
    virtual suic::Visual* GetVisualChild(int index);
    virtual void AddVisualChild(suic::Visual* child);
    virtual void ClearVisualChildren();
    virtual void RemoveVisualChild(suic::Visual* pChild);

    /// <summary>
    ///     ȡ�ÿ�����Ԫ���ڼ����е�������
    /// </summary>
    /// <param name="pChild">��Դ����</param>
    /// <returns>����������</returns>
    virtual int GetVisualChildIndex(suic::Visual* pChild);
    bool HitTestPoint(Point pt) const;

    /// <summary>
    ///     ��õ�ǰ�̵߳ķ���������
    /// </summary>
    /// <returns>����������</returns>
    AssignerPtr GetAssigner() const;

    virtual void OnVisualRenderChanged();

    void Precompute();

    bool ReadVisualFlag(int key) const;
    void WriteVisualFlag(int key, bool add);

    static void PropagateResumeLayout(Visual* parent, Visual* v);

public:

    int GetTreeLevel() const;
    void SetTreeLevel(int val);

    /// <summary>
    ///     ȡ����Ⱦ���ݶ���
    /// </summary>
    /// <returns>��Ⱦ���ݶ���</returns>
    ObjectPtr GetRenderData() const;
    GeometryPtr GetVisualClip() const;
    
protected:

    void PrecomputeRecursive(Rect& bboxSubgraph);

    virtual HitResult HitTestCore(Point pt);
    virtual void OnRender(suic::DrawingContext * drawing) = 0;

protected:

    Uint32 _vflag;
    int _treeLevel;
    // left��top��ʾ��Ԫ�غͱ�Ԫ�ص����ƫ�ƣ�����С�ڵ���0
    // right��bottom����ʾԪ�ؼ�����Ԫ�ص�����Ⱥ͸߶�
    Rect _descendantBounds;

    // �͸�����ƫ�ƣ���Ԫ�ػ��Ƶ���Ԫ��ʱ�õ�
    Point _offset;
    Point _canvasOffset;
    bool _clipToBounds;

    // ����Ԫ�ر߽�����,UpdateLayout���õ�
    Rect _rectMargin;
    // ����Ԫ�صĲü�����;
    Rect _rectClip;

    // ����Ԫ��ʵ����Ⱦ����,����UpdateLayout������
    //Rect _finalRect;
    Size _size;

    // ����Ԫ�ص��ڱ߾�
    Rect _rectPadding;

    // �ڸ�Ԫ���е�����
    Uint32 _parentIndex;

    ObjectPtr _packaged;
    AssignerPtr _assigner;
};

typedef shared<Visual> VisualPtr;

inline ObjectPtr Visual::GetRenderData() const
{
    return _packaged;
}

inline const suic::Point& Visual::GetVisualOffset() const
{
    return _offset;
}

inline AssignerPtr Visual::GetAssigner() const
{
    return _assigner;
}

};

# endif
