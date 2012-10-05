// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����GridViewRow.h
// ��  �ܣ�ʵ��GridViewRow
// 
// ��  �ߣ�����
// ʱ  �䣺2010-08-31
// 
// ============================================================================

# ifndef _UIGRIDVIEWROW_H_
# define _UIGRIDVIEWROW_H_

#include <sui/sharpuiconfig.h>
#include <sui/GridViewColumn.h>

namespace ui
{

// ============================================================================
// GridViewRow��
// ============================================================================

class SHARPUI_API GridViewRow : public suic::FrameworkElement
{
public:

    GridViewRow(ColumnHeaderCollectionPtr& colomns);
    virtual ~GridViewRow();

    void AddColumn(suic::ObjectPtr item);
    void SetColumn(int index, suic::ObjectPtr item);
    suic::ObjectPtr GetColumn(int index);

protected:

    suic::Element* GetLogicalChild(int index);
    suic::Int32 GetLogicalChildrenCount();

    suic::Size MeasureOverride(const suic::Size& availableSize);
    suic::Size ArrangeOverride(const suic::Size& size);

    void OnInitialized();
    void OnRender(suic::DrawingContext * drawing);

protected:

    // ����Ϣ
    ColumnHeaderCollectionPtr _colomns;
    suic::Vector<suic::ElementPtr> _cells;
};

typedef suic::shared<GridViewRow> GridViewRowPtr;

};

# endif
