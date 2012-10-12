// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����UIEvent.h
// ��  �ܣ�������Ŀ���¼����ࡣ
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _UIEVENT_H_
# define _UIEVENT_H_

#include <suicore/uiobject.h>
#include <suicore/delegate.h>

namespace suic
{

/// <summary>
/// ���������Խ���ṹ���������ĳһ������Ԫ����ʱ�᷵��һ�������롣
/// </summary>
typedef struct tagHitResult
{
public:

    tagHitResult() 
    {
    }

    tagHitResult(Point pt) 
        : hitcode(-1), hitpoint(pt) 
    {
    }

    Int32 HitTestCode() { return hitcode; }
    void HitTestCode(Int32 code) { hitcode = code; }

    Point HitTestPoint() const { return hitpoint; }

    Point hitpoint;
    Int32 hitcode;

}HitResult;

/// <summary>
/// ����Ԫ�صĴ���ʽ��Tunneling�����ע���˻����¼���ϵͳ�¼�����ģ��
/// ��������¼�����ֱ���¼����������
/// </summary>
enum RoutingType
{
    Tunneling,
    Bubbling,
    Direct,
};

class SUICORE_API RoutedEventArg;

/// <summary>
/// ����Ԫ�ص��¼����������н���Ԫ�صĻ��࣬�����Ľ���Ԫ�ض���ֱ�ӻ�
/// ���ӵ�������
/// </summary>
class SUICORE_API EventArg : public Object
{
public:

    EventArg();
    Uint32 Timestamp() const;

protected:

    Uint32 _timestamp;
};

class SUICORE_API SizeModeChangedEventArg : public EventArg
{
public:

    SizeModeChangedEventArg(Size size, bool bEnd)
        : _finialSize(size), _isExit(bEnd)
    {

    }

    bool IsExitMode() const
    {
        return _isExit;
    }

    Size GetFinalSize() const
    {
        return _finialSize;
    }

protected:

    bool _isExit;
    Size _finialSize;
};

/// <summary>
/// ���ڳߴ�λ�øı�ʱ�ṹ
/// </summary>
class SUICORE_API RenderSizeChangedEventArg : public EventArg
{
public:

    RenderSizeChangedEventArg(Size prev, Size n);

    Size PrevSize();
    Size NewSize();
    bool WidthChanged();
    bool HeightChanged();

protected:

    bool bWidChanged;
    bool bHeiChanged;

    Size sizePrev;
    Size sizeNew;

};

inline Size RenderSizeChangedEventArg::PrevSize() 
{ 
    return sizePrev; 
}

inline Size RenderSizeChangedEventArg::NewSize() 
{ 
    return sizeNew; 
}

inline bool RenderSizeChangedEventArg::WidthChanged() 
{ 
    return bWidChanged; 
}

inline bool RenderSizeChangedEventArg::HeightChanged() 
{ 
    return bHeiChanged; 
}

class SUICORE_API CancelEventArg  : public suic::EventArg
{
public:

    CancelEventArg(bool cancel);

    bool IsCancel();
    void SetCancel(bool cancel);

protected:

    bool _cancel;
};

class SUICORE_API RoutedEventArg : public EventArg
{
public:

    RoutedEventArg(ObjectPtr source);

    // �¼��Ƿ��ѱ�����
    bool Handled();

    // �����¼������־
    void Handled(bool val);

    // �����¼��Ľ���Ԫ��
    ObjectPtr GetSource() const ;
    void SetSource(ObjectPtr el);

    // ӵ�����Ľ���Ԫ��
    // �����ֵΪ�գ�����뿪����
    ObjectPtr GetOriginalSource() const;

    virtual void OnSetSource(ObjectPtr source);

public:

    bool _handled;

    ObjectPtr _source;
    ObjectPtr _originalSource;
};

inline ObjectPtr RoutedEventArg::GetOriginalSource() const
{
    return _originalSource;
}

class SUICORE_API HitResultEventArg : public RoutedEventArg
{
public:

    HitResultEventArg(ObjectPtr source, Point point)
        : RoutedEventArg(source)
        , _hr(point)
    {
        ;
    }

    Point GetPoint() const
    {
        return _hr.HitTestPoint();
    }

    HitResult* GetHitResult()
    {
        return &_hr;
    }

protected:

    HitResult _hr;
};

class SUICORE_API DataTransferEventArg : public RoutedEventArg
{
public:
};

class SUICORE_API SetterChangedEventArg : public EventArg
{
public:

    enum eAction {Add, Remove, Replace};

    SetterChangedEventArg(const String& name, ObjectPtr obj, int action);

    int GetAction() const
    {
        return _action;
    }

    String GetName() const
    {
        return _name;
    }

    ObjectPtr GetSetter() const
    {
        return _value;
    }

protected:

    String _name;
    ObjectPtr _value;
    int _action;
};

class SUICORE_API StateChangedEventArg : public EventArg
{
public:

    StateChangedEventArg(int iType, bool val);

    void SetStateName(const String& name);
    String GetStateName() const;

    int GetType() const;
    bool GetValue() const;

protected:

    String _name;
    int _type;
    bool _value;
};

class SUICORE_API ScrollPosChangedEventArg : public EventArg
{
public:

    ScrollPosChangedEventArg(double horz, double vert);

    double GetHorzScrollPos() const { return _horz; }
    double GetVertScrollPos() const { return _vert; }

protected:

    double _horz;
    double _vert;
};

class SUICORE_API ValueChangedEventArg : public EventArg
{
public:

    ValueChangedEventArg(const String& key, ObjectPtr oldVal, ObjectPtr newVal);

    String GetKey() const { return _key; }
    ObjectPtr GetOldValue() const { return _oldVal; }
    ObjectPtr GetNewValue() const { return _newVal; }

protected:

    String _key;
    ObjectPtr _oldVal;
    ObjectPtr _newVal;
};

class SUICORE_API LoadedEventArg : public RoutedEventArg
{
public:

    LoadedEventArg(ObjectPtr obj);

    ObjectPtr GetTarget();

protected:

    ObjectPtr _targetObj;
};

class SUICORE_API FocusEventArg : public RoutedEventArg
{
public:

    FocusEventArg(ObjectPtr source, ObjectPtr o, ObjectPtr n);

    ObjectPtr GetOldFocus() const;
    ObjectPtr GetNewFocus() const;

protected:

    ObjectPtr _oldFocus;
    ObjectPtr _newFocus;
};

inline ObjectPtr FocusEventArg::GetOldFocus() const
{
    return _oldFocus;
}

inline ObjectPtr FocusEventArg::GetNewFocus() const
{
    return _newFocus;
}

/// <summary>
/// ��������¼�
/// </summary>
class SUICORE_API KeyEventArg : public RoutedEventArg
{
public:

    KeyEventArg(ObjectPtr source, int c);

    int GetKey() const { return ch; }
    void SetKey(int c) { ch = c; }

    int State() const { return state; }

    bool IsBackPress() const;
    bool IsDeletePress() const;

    bool IsControlPress() const;
    bool IsShiftPress() const;
    bool IsMenuKeyPress() const;
    bool IsAltPress() const;
    bool IsEnterPress() const;
    bool IsEscPress() const;

    bool IsSpacePress() const;

    bool IsLeftArrow() const;
    bool IsUpArrow() const;
    bool IsRightArrow() const;
    bool IsDownArrow() const;

    bool IsPageup() const;
    bool IsPagedown() const;

    bool IsHomeKey() const;
    bool IsEndKey() const;

    bool IsCapsLock() const;
    bool IsTabKey() const;

    bool IsDigitalKey() const;
    bool IsAlphaKey() const;

protected:

    int ch;
    int state;
};

enum MouseButtonState
{
    eMouseRelease,
    eMousePress,
};

/// <summary>
/// ��������¼�
/// </summary>
class SUICORE_API MouseEventArg : public RoutedEventArg
{
public:

    MouseEventArg(ObjectPtr source, Point pt);

    int MouseState();
    int State();
    Point MousePoint();
    void SetMousePoint(Point pt);

    MouseButtonState LeftButton();
    MouseButtonState MiddleButton();
    MouseButtonState RightButton();
    MouseButtonState XButton1();
    MouseButtonState XButton2();

protected:

    int state;
    int mousestate;
    Point mousept;
};

inline int MouseEventArg::MouseState() 
{ 
    return mousestate; 
}

inline int MouseEventArg::State() 
{ 
    return state; 
}

inline Point MouseEventArg::MousePoint() 
{ 
    return mousept; 
}

/// <summary>
/// �������Ĺ����¼�
/// </summary>
class SUICORE_API MouseWheelEventArg : public MouseEventArg
{
public:

    MouseWheelEventArg(Point pt, int timestamp, int delta);
    int Delta() { return _delta; }

protected:

    int _delta;
};

/// <summary>
/// �������¼�
/// </summary>
class SUICORE_API CursorEventArg : public MouseEventArg
{
public:

    CursorEventArg(Point pt) 
        : MouseEventArg(ObjectPtr(), pt) 
    {
    }
};

/// <summary>
/// ������ҷ�¼�����ĳһ�������ϵ�ĳ������Ԫ���ϱ�����
/// </summary>
class SUICORE_API DragEventArg : public RoutedEventArg
{
public:
};

/// <summary>
/// �����¼��������Ҫ�ֶ�����ĳ������Ԫ�صĻ��ƣ����Է��ʹ��¼���
/// </summary>
class SUICORE_API DrawEventArg : public RoutedEventArg
{
public:

    DrawEventArg(const Rect & rc) 
        : rcClip(rc)
        , RoutedEventArg(ObjectPtr())
    {
    }

    Rect & RenderClip() { return rcClip; }
    void RenderClip(Rect & rc) { rcClip = rc; }

protected:

    Rect rcClip;
};

};

# endif
