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

class MainFrame : public suic::Window
{
public:

    MainFrame();
    ~MainFrame();

    void OnInitialized();

    void OnTreeItemSelect(ui::TreeViewItem* pItem);

    void OnTestAni(suic::Element* pElem);
    void OnTestWndAni(suic::Element* pElem);
    void OnChangeSkin(suic::Element* pElem);

    void OnSwitchLayered(suic::Element* pElem);

    void OnStartAni(suic::Element* pElem);
    void OnStopAni(suic::Element* pElem);

    void OnOpenUri(suic::Element* pElem);

    void SelectTabItem(suic::Element* sender);
    void OnValueChanged(suic::Element* sender, double o, double n);

    void OnLoaded(suic::LoadedEventArg& e);

    void OnFinishAni(suic::FrameworkElement* pElem);

protected:

    bool _bDefault;

};

#endif

