// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����FileWindow.h
// ��  �ܣ�ʵ�ִ洢���򿪶Ի���
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _UIDIRGROWSER_H_
# define _UIDIRGROWSER_H_

#include <sui/sharpuiconfig.h>
#include <suic/framework/uicontrol.h>

namespace ui
{

class SHARPUI_API DirBrowser : public suic::Control
{
public:

    DirBrowser(bool bDel=false);

    virtual ~DirBrowser();

    bool Open(suic::String dir, suic::Handle owner=0, bool bMulti=false);

    suic::String GetDir() const;

protected:

    virtual void OnRender(suic::DrawingContext * drawing);

protected:

    suic::String _dir;

};

};

# endif
