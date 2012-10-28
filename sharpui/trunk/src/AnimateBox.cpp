//////////////////////////////////////////////////////////////////////////////
// AnimateBox.cpp

#include <sui/AnimateBox.h>

static int ANIM_DEFAULT_DELAY = 80;

namespace ui
{

AnimateBox::AnimateBox() 
    : _curframe(0)
    , _anim_timer(-1)
    , _wid(0)
    , _hei(0)
    , _bkcolor(-1)
{
}

AnimateBox::~AnimateBox()
{
    Clear();
}

void AnimateBox::Start()
{
    if (FrameCount() > 0)
    {
        suic::SystemHelper::suiSetTimer(_timerid, this, 10);
    }
}

void AnimateBox::Stop()
{
    if (_timerid)
    {
        suic::SystemHelper::suiKillTimer(_timerid);
    }
}

suic::ImagePtr AnimateBox::CurrentFrame() const
{
    if (FrameCount() == 0)
    {
        return NULL;
    }
    else
    {
        return _frames[_curframe].img;
    }
}

int AnimateBox::CurrentElapse() const
{
    if (FrameCount() == 0)
    {
        return 0;
    }
    else
    {
        return _frames[_curframe].elapse;
    }
}

int AnimateBox::CurrentTransparent() const
{
    if (FrameCount() == 0)
    {
        return 255;
    }
    else
    {
        return _frames[_curframe].transparent;
    }
}

void AnimateBox::NextFrame()
{
    if (FrameCount() > 0)
    {
        if (_curframe >= FrameCount() - 1)
        {
            _curframe = 0;
        }
        else
        {
            ++_curframe;
        }
    }
}

void AnimateBox::PrevFrame()
{
    if (FrameCount() > 0)
    {
        if (_curframe == 0)
        {
            _curframe = FrameCount() - 1;
        }
        --_curframe;
    }
}

void AnimateBox::Clear()
{
    _frames.clear();
}

void AnimateBox::AddFrame(suic::ImagePtr img, int iElapse, int iTransparent)
{
    if (NULL != img.get())
    {
        suic::AnimateItem item;

        item.img = img;
        item.elapse = iElapse;
        item.transparent = iTransparent;

        item.x = 0;
        item.y = 0;
        item.flag = 0;

        item.w = img->Width();
        item.h = img->Height();

        _frames.push_back(item);
    }
}

void AnimateBox::AddGif(const suic::String& strPath)
{
    suic::GifDescriptor gd;

    gd.w = 0;
    gd.h = 0;

    suic::SystemHelper::LoadGif(strPath, gd, _frames);

    _wid = gd.w;
    _hei = gd.h;
    _bkcolor = gd.bkcolor;

    SetMinWidth(_wid);
    SetMinHeight(_hei);
}

void AnimateBox::OnSetterChanged(suic::SetterChangedEventArg& e)
{
    if (e.GetName().Equals(_T("Gif")))
    {
        AddGif(e.GetSetter()->ToString());
    }
    else
    {
        //
        // ������û����ʼ����������
        //
        __super::OnSetterChanged(e);
    }
}

void AnimateBox::OnInitialized()
{
    __super::OnInitialized();

    SetMinWidth(_wid);
    SetMinHeight(_hei);
}

void AnimateBox::OnLoaded(suic::LoadedEventArg& e)
{
    __super::OnLoaded(e);

    suic::ObjectPtr obj(GetValue(_T("AutoStart")));

    if (obj && obj->ToBool())
    {
        Start();
    }
}

suic::Size AnimateBox::MeasureOverride(const suic::Size& size)
{
    suic::ImagePtr img = CurrentFrame();

    if (img)
    {
        return suic::Size(img->Width(), img->Height());
    }
    else
    {
        return suic::Size();
    }
}

void AnimateBox::OnRender(suic::DrawingContext * drawing)
{
    suic::ImagePtr img = CurrentFrame();
    int flag = 2;

    suic::FrameworkElement::OnRender(drawing);

    if (_frames.size() > 1)
    {
        suic::Rect rc(0, 0, RenderSize().cx, RenderSize().cy);
        flag = _frames[_curframe].flag;

        // �Ȼָ�����ɫ
        if (flag == 2)
        {
            //drawing->FillRectangle(rc, _bkcolor);
        }

    //    // �����Ҫ������ǰһ֡
    //    //if (_frame)
    //    //{ 
    //    //    suic::Rect rcim(0, 0, _frame->Width(), _frame->Height());

    //    //    drawing->DrawImage(_frame.get(), &rc, &rcim, CurrentTransparent());
    //    //    _frame = NULL;
    //    //}

    //    //// ��Ҫ������һ֡
    //    if (flag == 3)
    //    {
    //        _frame = img;
    //    }
    }

    if (img)
    {
        suic::Rect rect(0, 0, RenderSize().cx, RenderSize().cy);
        suic::Rect rcimg(0, 0, img->Width(), img->Height());

        drawing->DrawImage(img.get(), &rect, &rcimg, CurrentTransparent());
    }
}

void AnimateBox::OnTimer(int id)
{
    NextFrame();

    if (_timerid->elapse != CurrentElapse())
    {
        _timerid->elapse = CurrentElapse();
        suic::SystemHelper::suiRestartTimer(_timerid);
    }

    InvalidateVisual();
}

}
