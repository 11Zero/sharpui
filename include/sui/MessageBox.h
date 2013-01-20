// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����MessageBox.h
// ��  �ܣ�ʵ����Ϣ��ʾ��
// 
// ��  �ߣ�����
// ʱ  �䣺2012-08-02
// 
// ============================================================================

# ifndef _UIMESSAGEBOX_H_
# define _UIMESSAGEBOX_H_

#include <sui/sharpuiconfig.h>
#include <suic/framework/uiwindow.h>

namespace ui
{

/// <summary>
/// ��Ϣ��ʾ��
/// </summary>
class SHARPUI_API MsgBox : public suic::Window
{
public:

    enum { OK=0, YESNO=2, }; 
    enum { UIOK, UIYES, UINO, };

    static int Show(suic::Handle owner, const suic::String& title, const suic::String& msg);
    static int Show(const suic::String& title, const suic::String& msg);

    static int Show(suic::Handle owner, const suic::String& title, const suic::String& msg, int flag);
    static int Show(const suic::String& title, const suic::String& msg, int flag);

    static int Show(const suic::String& title, const suic::Object* msg);

    static int Show(suic::Handle owner, const suic::String& title, const suic::Object* msg, int flag);
    static int Show(const suic::String& title, const suic::Object* msg, int flag);

protected:

    void OnButtonDown(suic::Element* sender);

protected:

    static suic::WindowPtr GetMessageWindow();

    MsgBox();
    virtual ~MsgBox();

protected:

    suic::Size MeasureOverride(const suic::Size& size);
    suic::Size ArrangeOverride(const suic::Size& size);

    void OnInitialized();
    void OnLoaded(suic::LoadedEventArg& e);

    void OnRender(suic::DrawingContext * drawing);
};

}

# endif
