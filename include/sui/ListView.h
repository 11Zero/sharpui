// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����ListView.h
// ��  �ܣ�ʵ�ֱ�׼��ListView�ؼ�
// 
// ��  �ߣ�����
// ʱ  �䣺2010-08-31
// 
// ============================================================================

# ifndef _UILISTVIEW_H_
# define _UILISTVIEW_H_

#include <sui/sharpuiconfig.h>
#include <sui/listbox.h>
#include <sui/GridViewHeaderRow.h>
#include <sui/listviewitem.h>

namespace ui
{

// =========================================================
// ListView��ʵ�ֱ�׼���б��
// =========================================================

class SHARPUI_API ListView : public ListBox
{
public:

    ListView();
    virtual ~ListView();

    DECLAREBUILD(ListView);

    ColumnHeaderCollectionPtr& Columns();

    int Add(suic::ObjectPtr value);
    int Insert(int index, suic::ObjectPtr value);
    int AddText(const suic::String& text);

    void SetLargeImageList();
    void SetSmallImageList();

    int GetHeaderStyle() const;
    void SetHeaderStyle(int iStyle);

    void SetBackgroundImage(suic::ImagePtr img);

    void OnColumnHeaderResize(suic::ObjectPtr sender, DragDeltaEventArg& e);
    void OnColumnHeaderChanged(GridViewColumn* pColumn, int flag);

protected:

    void InitializeScrollView();

    suic::Size MeasureOverride(const suic::Size& size);
    suic::Size ArrangeOverride(const suic::Size& size);

    void OnInitialized();

    void OnRender(suic::DrawingContext * drawing);

    void OnTextInput(suic::KeyEventArg& e);
    void OnKeyDown(suic::KeyEventArg& e);

    void OnGotFocus(suic::FocusEventArg& e);

    void OnMouseLeftButtonDown(suic::MouseEventArg& e);
    void OnMouseLeftButtonDbclk(suic::MouseEventArg& e);
    void OnMouseLeftButtonUp(suic::MouseEventArg& e);

    void OnSelectionChanged(SelectionChangedEventArg& e);

protected:

    GridViewHeaderRowPtr _header;
};

typedef suic::shared<ListView> ListViewPtr;

};

# endif
