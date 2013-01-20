// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����FileWindow.h
// ��  �ܣ�ʵ�ִ洢���򿪶Ի���
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _UIFILEGROWSER_H_
# define _UIFILEGROWSER_H_

#include <sui/sharpuiconfig.h>
#include <suic/framework/uicontrol.h>

namespace ui
{

class SHARPUI_API FileBrowser : public suic::Control
{
public:

    FileBrowser(bool bDel=false);

    virtual ~FileBrowser();

    bool Open(const suic::String& filter=_T("All\0*.*\0"));
    bool Save(const suic::String& filter=_T("All\0*.*\0"));

    suic::String GetFilePath() const;

protected:

    virtual void OnRender(suic::DrawingContext * drawing);

    bool InternalOpen(bool bOpen, const suic::String& filter=_T("All\0*.*\0"));

protected:

    suic::String _path;

};

};

# endif
