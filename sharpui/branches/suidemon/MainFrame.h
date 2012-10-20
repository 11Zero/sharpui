// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����MainWindow.h
// ��  �ܣ�������湤�̡�
// 
// ��  �ߣ�����
// ʱ  �䣺2012-02-02
// 
// ============================================================================

# ifndef _UIMAINWINDOW_H_
# define _UIMAINWINDOW_H_

#include <suicore/uiobject.h>
#include <suicore/uistructure.h>

class MainFrame : public suic::Window
{
public:

    MainFrame();
    ~MainFrame();

    void OnInitialized();

    void OnTreeItemSelect(ui::TreeViewItem* pItem);

    void OnTestAni(suic::ElementPtr pElem);
    void OnTestWndAni(suic::ElementPtr pElem);
    void OnChangeSkin(suic::ElementPtr pElem);

    void OnSwitchLayered(suic::ElementPtr pElem);

    void OnStartAni(suic::ElementPtr pElem);
    void OnStopAni(suic::ElementPtr pElem);

    void SelectTabItem(suic::Element* sender);
    void OnValueChanged(suic::Element* sender, double o, double n);

    void OnLoaded(suic::LoadedEventArg& e);

protected:

    bool _bDefault;

};

#endif

