// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����GridViewHeaderRow.h
// ��  �ܣ�ʵ��GridViewHeaderRow
// 
// ��  �ߣ�����
// ʱ  �䣺2010-08-31
// 
// ============================================================================

# ifndef _UIGRIDVIEWHEADERROW_H_
# define _UIGRIDVIEWHEADERROW_H_

#include <sui/sharpuiconfig.h>
#include <sui/GridViewColumn.h>

namespace ui
{

/// <summary>
/// GridViewHeaderRow
/// </summary>
class SHARPUI_API GridViewHeaderRow : public suic::FrameworkElement
{
public:

    GridViewHeaderRow();
    virtual ~GridViewHeaderRow();

    ColumnHeaderCollectionPtr& Columns();

    int GetColumnCount() const;
    GridViewColumn* GetColumn(int index);

protected:

    suic::Size MeasureOverride(const suic::Size& availableSize);
    suic::Size ArrangeOverride(const suic::Size& size);

    void OnInitialized();
    void OnRender(suic::DrawingContext * drawing);

protected:

    // ����Ϣ
    ColumnHeaderCollectionPtr _colomns;
};

typedef suic::shared<GridViewHeaderRow> GridViewHeaderRowPtr;

};

# endif
