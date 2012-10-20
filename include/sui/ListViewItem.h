// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����ListViewItem.h
// ��  �ܣ�ʵ�ֱ�׼��ListView�ؼ�������
// 
// ��  �ߣ�����
// ʱ  �䣺2010-08-31
// 
// ============================================================================

# ifndef _UILISTVIEWITEM_H_
# define _UILISTVIEWITEM_H_

#include <sui/sharpuiconfig.h>
#include <sui/listbox.h>

namespace ui
{

class SHARPUI_API ListViewItem : public ListBoxItem
{
public:

    ListViewItem();
    ~ListViewItem();

    DECLAREBUILD(ListViewItem)

    suic::String ToString();

    suic::ElementPtr GetColumn(int index);

    void AddColumn(suic::String text);
    void AddColumn(suic::Element* elem);

    void SetColumn(int index, suic::String text);
    void SetColumn(int index, suic::Element* elem);
};

typedef suic::shared<ListViewItem> ListViewItemPtr;

};

# endif
