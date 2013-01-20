// ======================================================================
//
// Copyright (c) 2008-2012 ����, Inc. All rights reserved.
//
// Sharpui��Դ����ѭCPLЭ����п�Դ���κθ��˻������ڴ�Э���Ͽ�������ʹ�á�
//
// ======================================================================

//////////////////////////////////////////////////////////////////////////////
// DirBrowser.cpp

#include "stdafx.h"
#include "commdlg.h"
#include <ShlObj.h>
#include <sui/DirBrowser.h>

namespace ui
{

//////////////////////////////////////////////////////////////////////////////
// DirBrowser

DirBrowser::DirBrowser(bool bDel)
{
    SetClassName(_T("DirBrowser"));
    SetAutoDelete(bDel);
}

DirBrowser::~DirBrowser()
{
}

void DirBrowser::OnRender(suic::DrawingContext * drawing)
{
}

int CALLBACK BrowseCallbackProc(HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData)     
{     
    /*if  (uMsg == BFFM_INITIALIZED)  
    {     
        ::SendMessage(hwnd, BFFM_SETSELECTION, TRUE, lpData);     
    }*/

    return 0;    
}

bool DirBrowser::Open(suic::String dir, suic::Handle owner/*=0*/, bool bMulti/*=false*/)
{
    LPITEMIDLIST pidlRoot = NULL;  
    suic::String curPath(dir);  
    BROWSEINFO bi;  
    suic::Char buffer[MAX_PATH] = {0};

    bi.hwndOwner = HandleToHwnd(owner);  
    bi.pidlRoot = NULL;//curPath.c_str();  
    bi.pszDisplayName = NULL;  
    bi.lpszTitle = _T("ѡ��Ŀ¼");
    bi.ulFlags = BIF_EDITBOX;  
    bi.lpfn = BrowseCallbackProc;  
    bi.lParam = (LPARAM)dir.c_str();  
    bi.iImage = 0;  
    LPITEMIDLIST pList = NULL; 

    if ((pList = SHBrowseForFolder(&bi)) != NULL)  
    {  
        suic::Char path[MAX_PATH] = {0};  

        SHGetPathFromIDList(pList,path);
        _dir = path;

        return true;
    }
    else
    {
        return false;
    }
}

suic::String DirBrowser::GetDir() const
{
    return _dir;
}

};
