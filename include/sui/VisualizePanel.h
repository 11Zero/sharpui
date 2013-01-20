// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����VisualizePanel.h
// ��  �ܣ�ʵ����������Ԫ�ز�������֧�ֹ�Ͳ��
// 
// ��  �ߣ�����
// ʱ  �䣺2011-08-31
// 
// ============================================================================

# ifndef _UIVISUALIZEPANEL_H_
# define _UIVISUALIZEPANEL_H_

#include <sui/sharpuiconfig.h>
#include <sui/itemcontainer.h>
#include <sui/ScrollViewer.h>

#include <suic/framework/uipanel.h>

namespace ui
{

class ScrollData
{
public:

    suic::Size _viewport;
    ScrollViewerPtr _scrollOwner;
    suic::Size _maxDesiredSize;

    bool _allowHorizontal;
    bool _allowVertical;
};

/// <summary>
/// VisualizePanel
/// </summary>
class SHARPUI_API VisualizePanel : public suic::Panel
{
public:

    VisualizePanel(ItemCollectionPtr container);
    virtual ~VisualizePanel();

    DeclareAbstractTypeofInfo(VisualizePanel, suic::Panel)

protected:

    virtual void OnInitialized();
    virtual void OnRender(suic::DrawingContext * drawing);

    virtual suic::Size MeasureOverride(const suic::Size& size);
    virtual suic::Size ArrangeOverride(const suic::Size& size);

protected:

    suic::Size ArrangeHorizontal(const suic::Size& size);
    suic::Size ArrangeVertical(const suic::Size& size, int iOffset);

protected:

    ItemCollectionPtr _container;

    ScrollData _scrollData;
};

typedef suic::shared<VisualizePanel> VisualizePanelPtr;

class SHARPUI_API VisualizeHeaderPanel : public VisualizePanel
{
public:

    VisualizeHeaderPanel(ItemCollectionPtr container);

    suic::FrameworkElementPtr GetHeader();
    void SetHeader(suic::FrameworkElementPtr val);

protected:

    suic::Size MeasureOverride(const suic::Size& size);
    suic::Size ArrangeOverride(const suic::Size& size);

protected:

    suic::FrameworkElementPtr _header;
};

typedef suic::shared<VisualizeHeaderPanel> VisualizeHeaderPanelPtr;

}

# endif
