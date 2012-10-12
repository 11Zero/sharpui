// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����Element.h
// ��  �ܣ�������Ŀ��Element���ࡣ
// 
// ��  �ߣ�����
// ʱ  �䣺2010-05-02
// 
// ============================================================================

# ifndef _UIELEMENT_H_
# define _UIELEMENT_H_

#include <suicore/uivisual.h>
#include <suicore/uievent.h>
#include <suicore/delegate.h>

#include <suicore/style/ResourceDictionary.h>

namespace suic
{

class Element;
typedef shared<Element> ElementPtr;

typedef delegate<void(suic::Element*, const EventArg&)> EventHandler;
typedef delegate<void(suic::Element*, MouseEventArg&)> MouseEventHandler;
typedef delegate<void(suic::Element*, KeyEventArg&)> KeyEventHandler;
typedef delegate<void(suic::Element*, const EventArg&)> DragEventHandler;
typedef delegate<void(suic::Element*, RoutedEventArg&)> RoutedEventHandler;
typedef delegate<void(suic::Element*, FocusEventArg&)> FocusEventHandler;
typedef delegate<void(suic::ObjectPtr, LoadedEventArg&)> LoadedEventHandler;
typedef delegate<void(suic::ObjectPtr, DataTransferEventArg&)> TargetUpdatedEventHandler;
typedef delegate<void(suic::Element*, CursorEventArg&)> CursorEventHandler;
typedef delegate<void(suic::Element*)> InitializedEventHandler;
typedef delegate<void(suic::Element*, StylePtr)> ThemeChangedHandler;
typedef delegate<void(suic::Element*, HitResultEventArg&)> HitTestEventHandler;

class IUserData : public RefObject
{
public:

    virtual ~IUserData() {}
};

/// <summary>
/// ����Ԫ����Ļ��࣬ʵ��һ�����Ԫ�صĹ��������ͽӿ�.
/// </summary>
class SUICORE_API Element : public Visual
{
public:

    Element(const String& strClassName);
    Element();

    virtual ~Element();

    // ����¼�������

    MouseEventHandler MouseEnter;
    MouseEventHandler MouseMove;
    MouseEventHandler MouseLeave;

    MouseEventHandler MouseLButtonDown;
    MouseEventHandler MouseLButtonUp;

    MouseEventHandler MouseRButtonDown;
    MouseEventHandler MouseRButtonUp;

    CursorEventHandler CursorSet;

    MouseEventHandler MouseWheel;

    MouseEventHandler LostMouseCapture;
    MouseEventHandler GotMouseCapture;

    FocusEventHandler SetFocus;
    FocusEventHandler LostFocus;

    // Ԥ���¼�,ִ��Դ�¼�֮ǰ�����ȵ��ô��¼�
    // ���¼���Ӹ�Ԫ�ؿ�ʼִ��
    MouseEventHandler PreMouseEnter;
    MouseEventHandler PreMouseMove;
    MouseEventHandler PreMouseLeave;

    MouseEventHandler PreMouseDown;

    MouseEventHandler PreMouseLButtonDown;
    MouseEventHandler PreMouseLButtonUp;

    MouseEventHandler PreMouseRButtonDown;
    MouseEventHandler PreMouseRButtonUp;

    // �����¼�
    KeyEventHandler KeyDown;
    KeyEventHandler KeyUp;

    // ����Ԥ���¼�
    KeyEventHandler PreKeyDown;
    KeyEventHandler PreKeyUp;

    // �϶��¼�
    DragEventHandler Drag;
    DragEventHandler PreDrag;

    // ��ʼ���¼�������Ԫ������ڲ���ʼ�����һ�ε���
    // ���¼���������һ��
    InitializedEventHandler Initialized;
    ThemeChangedHandler ThemeChanged;

    LoadedEventHandler Loaded;
    LoadedEventHandler Unloaded;

    TargetUpdatedEventHandler TargetUpdated;

    HitTestEventHandler HitTest;

public:

    /// <summary>
    ///     ���������һ�ݶ���
    /// </summary>
    /// <returns>���ݶ���</returns> 
    virtual ElementPtr Clone() const;

    /// <summary>
    ///     ���ý���Ԫ�ص��Զ������ݶ���
    /// </summary>
    /// <remarks>
    ///     �û������Զ����Լ������ݶ���Ȼ��ͨ���˷���
    ///     �󶨵�����Ԫ��
    /// </remarks>
    /// <param name="pData">�Զ������ݶ���</param>
    /// <returns>��</returns> 
    void SetUserData(ObjectPtr pData);

    /// <summary>
    ///     ����Զ������ݶ���,ÿ��Ԫ��������һ�������Լ���
    ///     ���ݶ������ںʹ�Ԫ�ؽ��й���
    /// </summary>
    /// <returns>�Զ������ݶ���</returns> 
    ObjectPtr GetUserData() const;

    /// <summary>
    ///     ��������Ԫ�صĳߴ�
    /// </summary>
    /// <remarks>
    ///     �˷�����ݹ���������Լ������ӽ���Ԫ�صĳߴ硣
    ///     Ĭ�Ͻ��������Ԫ�ص���Сֵ�����ֵ���ƣ����
    ///     ������Width��Height����ʹ������ֵ�������ֵ�������ԣ�
    ///     availableSize�����ο�����ʵ�����塣
    /// </remarks>
    /// <param name="availableSize">
    ///     �ο���С
    /// </param>
    /// <returns>��</returns> 
    virtual void Measure(const Size & availableSize);

    /// <summary>
    ///     �Խ���Ԫ�ؽ��в���
    /// </summary>
    /// <remarks>
    ///     �˷�����ݹ鲼�������Լ������ӽ���Ԫ�صĲ���
    ///     �ڶ��ӽ���Ԫ�ؽ��в���֮ǰ��������������е�
    ///     ���ӽ���Ԫ�ء�
    /// </remarks>
    /// <param name="finalRect">������Ԫ�ظ���������λ�ô�С</param>
    /// <returns>��</returns> 
    virtual void Arrange(const Rect & finalRect);
    virtual void ArrangeVisual();

    /// <summary>
    ///     �����Ƿ�ü��ӽ���Ԫ�ص�������Ԫ�ص�����
    /// </summary>
    /// <remarks>
    ///     ������Ҫ�ü������к��ӽ���Ԫ�ػ���ʱ����
    ///     �ü����������������
    /// </remarks>
    /// <param name="value">�ü���־</param>
    /// <returns>��</returns> 
    void SetClipToBounds(bool value);

    /// <summary>
    ///     ȡ�òü������־
    /// </summary>
    /// <returns>�ü������־</returns> 
    bool IsClipToBounds() const;

    /// <summary>
    ///     ����������������Ϣ
    /// </summary>
    /// <remarks>
    ///     ӵ����ͬ���Ľ���Ԫ�ض�����һ��Context��������
    /// </remarks>
    /// <param name="key">���ݶ���Key</param>
    /// <param name="value">���ݶ���Value</param>
    /// <returns>��</returns> 
    void SetContext(const String& key, ObjectPtr value);

    /// <summary>
    ///     ȡ��������������Ϣ
    /// </summary>
    /// <param name="key">���ݶ���Key</param>
    /// <returns>���������ݶ���ֵ</returns> 
    ObjectPtr GetContext(const String& key);

    void SetValue(const String& key, ObjectPtr value);
    ObjectPtr GetValue(const String& key);

    /// <summary>
    ///     �������Ľ���״̬
    /// </summary>
    /// <remarks>
    ///     ���������Ԫ���ܹ�ӵ�н��㣬��ô���������OnGotFocus()��
    ///     ͬʱ����֮ǰ�Ľ���Ԫ�ص�OnLostFocus()��
    /// </remarks>
    /// <returns>�������Ԫ��ӵ�н��㷵��true������false</returns> 
    bool Focus();

    /// <summary>
    ///     �������Ԫ��
    /// </summary>
    /// <remarks>
    ///     ����丸����Ԫ�ش��ڽ���״̬���˽���Ԫ��Ҳ
    ///     �ᱻ���á�
    /// </remarks>
    /// <returns>�����ϴν���Ԫ�ؼ���״̬</returns> 
    virtual bool Enable(bool val);

    /// <summary>
    ///     ���ý���Ԫ�صĿɼ�״̬
    /// </summary>
    /// <param name="val">�ɼ���־</param>
    /// <returns>�����ϴν���Ԫ�ؿɼ�״̬</returns> 
    virtual bool SetVisible(bool val);

    /// <summary>
    ///     ����Ԫ���¼�
    /// </summary>
    /// <param name="e">Ԫ���¼�</param>
    /// <returns>��</returns> 
    void RaiseEvent(RoutedEventArg& e);

    virtual bool CheckName(String& name);

    /// <summary>
    ///     ȡ��Ԫ�ص�ˮƽ���뷽ʽ
    /// </summary>
    /// <remarks>
    ///     ���뷽ʽ��Left��Center��Right��Stretch��
    /// </remarks>
    /// <returns>ˮƽ���뷽ʽ</returns> 
    int GetHorizontalAlignment();

    /// <summary>
    ///     ȡ��Ԫ�صĴ�ֱ���뷽ʽ
    /// </summary>
    /// <remarks>
    ///     ���뷽ʽ��Top��Center��Bottom��Stretch��
    /// </remarks>
    /// <returns>��ֱ���뷽ʽ</returns> 
    int GetVerticalAlignment();

    /// <summary>
    ///     ȡ��Ԫ�����ݵ�ˮƽ���뷽ʽ
    /// </summary>
    /// <remarks>
    ///     ���뷽ʽ��Left��Center��Right��
    /// </remarks>
    /// <returns>����ˮƽ���뷽ʽ</returns> 
    int GetHorizontalContentAlignment();

    /// <summary>
    ///     ȡ��Ԫ�����ݵĴ�ֱ���뷽ʽ
    /// </summary>
    /// <remarks>
    ///     ���뷽ʽ��Top��Center��Bottom��
    /// </remarks>
    /// <returns>��ֱ���ݶ��뷽ʽ</returns> 
    int GetVerticalContentAlignment();

    /// <summary>
    ///     ����Ԫ�ص�ˮƽ���뷽ʽ
    /// </summary>
    /// <remarks>
    ///     ���뷽ʽ��Left��Center��Right��Stretch��
    /// </remarks>
    /// <returns>��</returns> 
    void SetHorizontalAlignment(const String & align);

    /// <summary>
    ///     ����Ԫ�صĴ�ֱ���뷽ʽ
    /// </summary>
    /// <remarks>
    ///     ���뷽ʽ��Top��Center��Bottom��Stretch��
    /// </remarks>
    /// <returns>��</returns> 
    void SetVerticalAlignment(const String & align);

    void SetHorizontalContentAlignment(const String & align);
    void SetVerticalContentAlignment(const String & align);

    /// <summary>
    ///     ��ȡ����Ԫ�صķ���
    /// </summary>
    /// <remarks>
    ///     ����Ԫ�صķ����Ϊˮƽ�ʹ�ֱ��Horizontal��Vertical����
    /// </remarks>
    /// <returns>Horizontal: ˮƽ; Vertical: ��ֱ</returns> 
    CoreFlags::Orientation GetOrientation() const;

    /// <summary>
    ///     ���ý���Ԫ�صķ���
    /// </summary>
    /// <param name="bHorz"> Horizontal: ˮƽ; Vertical: ��ֱ</param>
    /// <returns>��</returns> 
    void SetOrientation(CoreFlags::Orientation iHorz);

    /// <summary>
    ///     ��ȡ����Ԫ�������ƣ�ÿ������Ԫ�ص������Ψһ��
    /// </summary>
    /// <returns>����Ԫ��������</returns> 
    String GetClassName() const;

    /// <summary>
    ///     �жϵ�ǰ����Ԫ���Ƿ񱻳�ʼ����
    /// </summary>
    /// <remarks>
    ///     ֻ�б���ʼ���Ľ���Ԫ������ص���ʽ����Դ�Ż��ʼ����
    ///     ��ʱ����Ҳ���ᴥ��������׼��������Ҫ�����ݡ�
    /// </remarks>
    /// <returns>true: �������Ԫ���Ѿ���ʼ��</returns> 
    bool IsInitialized() const;

    /// <summary>
    ///     �жϵ�ǰ����Ԫ�صĿɼ��ԡ�
    /// </summary>
    /// <remarks>
    ///     �����Ԫ�ز��ɼ�����Ҳ���ɼ���
    /// </remarks>
    /// <returns>true: ����Ԫ�ؿɼ�</returns> 
    bool IsVisible() const;

    /// <summary>
    ///     �жϵ�ǰ����Ԫ�ص������ԡ�
    /// </summary>
    /// <returns>true: ����Ԫ������</returns> 
    bool IsCollapsed() const;

    /// <summary>
    ///     �жϵ�ǰ����Ԫ�صĽ����ԡ�
    /// </summary>
    /// <remarks>
    ///     �����Ԫ�ؽ��ã���Ҳ���á�
    /// </remarks>
    /// <returns>true: ����Ԫ�ؿ���</returns> 
    bool IsEnabled() const;

    /// <summary>
    ///     �жϽ���Ԫ���Ƿ����ϡ�
    /// </summary>
    /// <returns>true: ��������</returns> 
    bool IsTopMost() const;

    /// <summary>
    ///     �жϽ���Ԫ���Ƿ�ӵ�н��㡣
    /// </summary>
    /// <returns>true: ӵ�н���</returns> 
    bool IsFocused() const;

    /// <summary>
    ///     �жϽ���Ԫ���Ƿ����㡣
    /// </summary>
    /// <returns>true: ����</returns> 
    bool IsFocusable() const;
    void SetFocusable(bool value);

    /// <summary>
    ///     �ж�����ڽ���Ԫ���ϻ����ӽ���Ԫ���ϡ�
    /// </summary>
    /// <remarks>
    ///     �����Ԫ��ӵ����꣬��Ҳ����true��
    /// </remarks>
    /// <returns>true: ӵ�����</returns> 
    bool IsMouseOver() const;

    /// <summary>
    ///     �ж�����ڽ���Ԫ���ϡ�
    /// </summary>
    /// <remarks>
    ///     ֻ�����ֱ����Ԫ���ϲŷ���true��
    /// </remarks>
    /// <returns>true: ӵ�����</returns> 
    bool IsMouseDirectlyOver() const;

    /// <summary>
    ///     �жϽ���Ԫ���Ƿ�ѹ�¡�
    /// </summary>
    /// <returns>true: Ԫ�ر�ѹ��</returns>
    bool IsMouseDown() const;

    /// <summary>
    ///     �жϽ������Ԫ�ص�����Ƿ�ĳ������Ԫ�ؿ��ơ�
    /// </summary>
    /// <remarks>
    ///     ĳЩ����Ԫ�ػ���hot״̬ʱ������Ҫ�жϴ˱�־��
    /// </remarks>
    /// <returns>true: ӵ�����</returns> 
    bool IsMouseCaptured() const;

    /// <summary>
    ///     �жϽ������Ԫ�ص�����Ƿ�ĳ������Ԫ�ؿ��ơ�
    /// </summary>
    /// <remarks>
    ///     ���ӽ���Ԫ�ؿ���Ҳ����true��
    /// </remarks>
    /// <returns>true: ӵ�����</returns> 
    bool IsMouseCaptureWithin() const;
    bool IsFocusedWithin() const;
    //bool IsKeyboardFocusWithin();

    /// <summary>
    ///     ˢ�½���Ԫ�ػ��ơ�
    /// </summary>
    /// <remarks>
    ///     ���ڷֲ㴰�ڽ���ֱ�ӻ��ƣ�������ڻ����߳���
    ///     ���첽ִ�С�
    /// </remarks>
    /// <param name="bForce">�Ƿ�ǿ��ˢ��</param>
    /// <returns>��</returns>
    void InvalidateVisual(bool bForce=false);

    /// <summary>
    ///     ˢ�½���Ԫ�ػ��ơ�
    /// </summary>
    /// <remarks>
    ///     �˷���ָ���ü�����
    /// </remarks>
    /// <param name="lprc">�ü�����</param>
    /// <param name="bForce">�Ƿ�ǿ��ˢ��</param>
    /// <returns>��</returns>
    void InvalidateRect(suic::Rect* lprc, bool bForce=false);

    /// <summary>
    ///     ���Բ������Ŀ���Ȩ��
    /// </summary>
    /// <returns>��</returns>
    void SetCaptureMouse();

    /// <summary>
    ///     �����ͷ����Ŀ���Ȩ��
    /// </summary>
    /// <remarks>
    ///     �����ǰ����Ĳ��Ǳ�Ԫ�أ����ԡ�
    /// </remarks>
    /// <returns>��</returns>
    void ReleaseCaptureMouse();

    virtual String ToString();

    /// <summary>
    ///     ���������ת��Ϊ����Ԫ�ص����ꡣ
    /// </summary>
    /// <param name="point">��������</param>
    /// <returns>����Ԫ������</returns>
    Point PointFromScreen(Point point);

    /// <summary>
    ///     ����Ԫ�������ת��Ϊ�������ꡣ
    /// </summary>
    /// <param name="point">��������</param>
    /// <returns>��������</returns>
    Point PointToScreen(Point point);

    virtual void OnPreviewSetCursor(CursorEventArg& e);
    virtual void OnSetCursor(CursorEventArg& e);

    // ����¼�����
    virtual void OnMouseEnter(MouseEventArg& e);
    virtual void OnMouseMove(MouseEventArg& e);
    virtual void OnMouseCaptureMove(MouseEventArg& e);
    virtual void OnMouseLeave(MouseEventArg& e);
    virtual void OnMouseWheel(MouseWheelEventArg& e);

    virtual void OnMouseLeftButtonDown(MouseEventArg& e);
    virtual void OnMouseLeftButtonUp(MouseEventArg& e);
    virtual void OnMouseRightButtonDown(MouseEventArg& e);
    virtual void OnMouseRightButtonUp(MouseEventArg& e);

    virtual void OnMouseLeftButtonDbclk(MouseEventArg& e);

    // ���Ԥ���¼�����
    virtual void OnPreviewMouseEnter(MouseEventArg& e);
    virtual void OnPreviewMouseMove(MouseEventArg& e);
    virtual void OnPreviewMouseLeave(MouseEventArg& e);

    virtual void OnPreviewMouseLeftButtonDown(MouseEventArg& e);
    virtual void OnPreviewMouseLeftButtonUp(MouseEventArg& e);
    virtual void OnPreviewMouseRightButtonDown(MouseEventArg& e);
    virtual void OnPreviewMouseRightButtonUp(MouseEventArg& e);

    virtual void OnPreviewMouseLeftButtonDbclk(MouseEventArg& e);

    // �϶��¼�����
    virtual void OnDragEnter(DragEventArg& e);
    virtual void OnDragLeave(DragEventArg& e);
    virtual void OnDragOver(DragEventArg& e);
    virtual void OnDrop(DragEventArg& e);

    // �����¼�����
    virtual void OnTextInput(KeyEventArg& e);
    virtual void OnKeyDown(KeyEventArg& e);
    virtual void OnKeyUp(KeyEventArg& e); 

    // Ԥ��������¼�����
    virtual void OnPreChar(KeyEventArg& e);
    virtual void OnPreKeyDown(KeyEventArg& e);
    virtual void OnPreKeyUp(KeyEventArg& e); 

    // ������׽�¼�����
    virtual void OnLostKeyboardFocus(KeyEventArg& e);

    virtual void OnLostMouseCapture(MouseEventArg& e);
    virtual void OnGotMouseCapture(MouseEventArg& e);

    virtual void OnGotFocus(FocusEventArg& e);
    virtual void OnLostFocus(FocusEventArg& e);

    // Ԫ����ӱ仯�¼�����
    virtual void OnChildrenChanged(ElementPtr kidAdded, ElementPtr kidRemoved);
    virtual void OnParentChanged(ElementPtr oldParent, ElementPtr newParent);

    virtual void OnStyleChanged(StylePtr oldStyle, StylePtr newStyle);
    
    virtual void OnRenderSizeChanged(RenderSizeChangedEventArg& e);
    virtual void OnRenderSizeModeChanged(SizeModeChangedEventArg& e);

    virtual void OnTimer(int iTimerId);
    virtual void OnLeaveTimer(int iTimerId);

    virtual void BeginInit();
    virtual void EndInit();

    virtual bool OnEvent(Element* sender, Object* event);

    /// <summary>
    ///     ���ڼ����¼���
    /// </summary>
    /// <remarks>
    ///     �ڴ��ڴ���׼����ʾʱÿ��Ԫ�ض��ᱻ���á�
    /// </remarks>
    /// <param name="e">�����¼�</param>
    /// <returns>��</returns>
    virtual void OnLoaded(LoadedEventArg& e);
    virtual void OnUnloaded(LoadedEventArg& e);
    virtual void OnTargetUpdated(DataTransferEventArg& e);

    /// <summary>
    ///     Ԫ������ֵ�仯ʱ���лص���������Ԫ�ر���ڵ�����ԣ�
    /// </summary>
    /// <remarks>
    ///     ��һ�μ��غ͸�����Դʱ������á�
    /// </remarks>
    /// <param name="e">������Ϣ�¼�</param>
    /// <returns>��</returns>
    virtual void OnSetterChanged(SetterChangedEventArg& e);

    /// <summary>
    ///     IsSelected��״̬�仯ʱ�ص���
    /// </summary>
    /// <remarks>
    ///     ״̬�仯ʱ��Ԫ���д�����ᡣ
    /// </remarks>
    /// <param name="e">״̬�¼��������¾�״̬</param>
    /// <returns>��</returns>
    virtual void OnStateChanged(StateChangedEventArg& e);
    virtual void OnValueChanged(ValueChangedEventArg& e);

    virtual void OnScrollPosChanged(ScrollPosChangedEventArg& e);

    virtual void OnHitTest(HitResultEventArg& e);

    /// <summary>
    ///     ���½���Ԫ�صĲ��֡���ʾ��
    /// </summary>
    /// <remarks>
    ///     �˷����ڲ�����InvalidateArrange()��InvalidateVisual()��
    /// </remarks>
    /// <returns>��</returns>
    void UpdateLayout();

    /// <summary>
    ///     ˢ��Ԫ�ز��֡�
    /// </summary>
    /// <returns>��</returns>
    void InvalidateArrange();

    /// <summary>
    ///     ˢ��Ԫ�ش�С��
    /// </summary>
    /// <returns>��</returns>    
    void InvalidateMeasure();

    bool ReadFlag(int key) const;
    void WriteFlag(int key, bool add);

    virtual void RaisedMeasureDirty();

public:

    /// <summary>
    ///     �õ�����Ԫ�ص��߼���Ԫ�ء�
    /// </summary>
    /// <remarks>
    ///     �߼���Ԫ�غͿ��Ӹ�Ԫ�ؿ��ܲ�һ����
    /// </remarks>
    /// <returns>��Ԫ��</returns>
    virtual suic::Element* LogicalParent() const;

    /// <summary>
    ///     �õ�����Ԫ�صĿ��Ӹ�Ԫ�ء�
    /// </summary>
    /// <returns>���Ӹ�Ԫ��</returns>
    suic::Element* GetParent() const;

    virtual void OnRender(DrawingContext * drawing);

    /// <summary>
    ///     �����߼�Ԫ�ء�
    /// </summary>
    /// <param name="child">��Ԫ��</param>
    /// <returns>��</returns>
    virtual void AddLogicalChild(suic::Element* child);

    /// <summary>
    ///     ��ָ��λ�ò����߼�Ԫ�ء�
    /// </summary>
    /// <param name="index">��������λ��</param>
    /// <param name="child">��Ԫ��</param>
    /// <returns>��</returns>
    virtual void InsertLogicalChild(int index, suic::Element* child);

    /// <summary>
    ///     ��������߼�Ԫ�ء�
    /// </summary>
    /// <returns>��</returns>
    virtual void ClearLogicalChildren();

    /// <summary>
    ///     �Ƴ�ָ���߼�Ԫ�ء�
    /// </summary>
    /// <param name="child">��Ԫ��</param>
    /// <returns>��</returns>
    virtual void RemoveLogicalChild(suic::Element* child);

    /// <summary>
    ///     ��ȡ�߼�Ԫ�ء�
    /// </summary>
    /// <param name="index">����λ��</param>
    /// <returns>��Ԫ��</returns>
    virtual suic::Element* GetLogicalChild(int index);

    /// <summary>
    ///     ��ȡ�߼�Ԫ�ظ�����
    /// </summary>
    /// <returns>�߼�Ԫ�ظ���</returns>
    virtual Int32 GetLogicalChildrenCount();

public:

    /// <summary>
    ///     ��ȡ����Ԫ�ص���Ⱦ���򣬴˴�С������������ͻ��ơ�
    /// </summary>
    /// <remarks>
    ///     Arrange�Ժ󣬴�ֵ��ı䡣
    /// </remarks>
    /// <returns>��Ⱦ�����С</returns>
    virtual Size RenderSize();

    const Size & GetDesiredSize() const;
    void SetDesiredSize(Size value);

    double GetOpacity() const;
    void SetOpacity(double iOpacity);

    bool CheckState(Uint32 state) const;
    void SetClassName(const String& clsName);

    /// <summary>
    ///     ���ý���Ԫ�ر�ʶ
    /// </summary>
    /// <remarks>
    ///     ��ͬһ�������д˽���Ԫ�ر�ʶ����Ψһ��
    /// </remarks>
    /// <param name="name">����Ԫ�����Ʊ�ʶ</param>
    /// <returns>��</returns> 
    void SetName(const String & name);

    /// <summary>
    ///     ��ý���Ԫ�ر�ʶ
    /// </summary>
    /// <returns>����Ԫ�ر�ʶ</returns> 
    String GetName();

    void SetWrapper(const String & name);
    String GetWrapper();

    /// <summary>
    ///     ����ָ���Ľ���Ԫ��
    /// </summary>
    /// <remarks>
    ///     ʹ��Name=""��������Բ��ұ����Լ����ӽڵ�Ľ���Ԫ�ء�
    /// </remarks>
    /// <param name="strName">Ԫ�����ƣ���Name���塣</param>
    /// <returns>����Ԫ�ض���</returns> 
    virtual ElementPtr FindName(const String& strName);

protected:

    /// <summary>
    ///     Ԫ�صĳ�ʼ���¼���
    /// </summary>
    /// <remarks>
    ///     �˺�����EndInit���ã���ʱ���е���Դ������Ԫ�ض���ʼ����ϡ�
    /// </remarks>
    /// <returns>��</returns>
    virtual void OnInitialized();

    /// <summary>
    ///     ʵ�ֽ���Ԫ�������Ĵ�С�����߼���
    /// </summary>
    /// <remarks>
    ///     ������Ӧ�ü̳д˷�����������С�ļ��㣬
    ///     �˺���Ĭ�ϻ����Measure����DesiredSizeֵ��
    /// </remarks>
    /// <param name="availableSize">�ο���С</param>
    /// <returns>����Ԫ�������Ĵ�С</returns>
    virtual Size MeasureOverride(const Size& size);

    /// <summary>
    ///     ʵ�ֽ���Ԫ�ش�С��λ�õļ��㡣
    /// </summary>
    /// <remarks>
    ///     ������Ӧ�ü̳д˷����������λ�úʹ�С����ļ��㣬
    ///     ����ԪӦ��ʹ�ô���������Լ�������Ԫ�ء�
    /// </remarks>
    /// <param name="finalRect"> ��Ԫ���ṩ�Ŀ�������λ�ô�С</param>
    /// <returns>���ֺ�Ĵ�С</returns>
    virtual Size ArrangeOverride(const Size& size);

    /// <summary>
    ///     ʵ�ֽ���Ԫ�ش�С�����߼���
    /// </summary>
    /// <param name="availableSize">�ο���С</param>
    /// <returns>����Ԫ�������Ĵ�С</returns>
    virtual Size MeasureCore(const Size & availableSize);    

    /// <summary>
    ///     ʵ�ֽ���Ԫ������С��λ�õļ��㡣
    /// </summary>
    /// <param name="finalRect">��Ԫ���ṩ�Ŀ�������λ�ô�С</param>
    /// <returns>��</returns>
    virtual void ArrangeCore(const Rect & finalRect);

    /// <summary>
    ///     ����������Ĵ�С�������С���������ơ�
    /// </summary>
    /// <remarks>
    ///     ����߶ȺͿ���Ѿ����ã���ʹ������ֵ��
    /// </remarks>
    /// <param name="desiredSize">�������������������С</param>
    /// <returns>��</returns>
    void MeasureCheck(Size & desiredSize);

protected:

    String _className;
    // Ԫ�ص�����
    String _name;
    String _wrapper;

    // ����Ԫ����Ⱦ����
    StylePtr _style;

    // ��¼Ԫ�ص�״̬,����ʾ32��
    Uint32 _state;
    // ��¼Ԫ�صı�־,����ʾ32��
    Uint32 _flag;

    // ��������Ԫ�������Ĵ�С,�˴�С���ܻ����Ⱦ�����С��һ��
    // ��Ϊ����ܻᱻ�丸����Ԫ�ظı䡣
    Size _desiredSize;
};

inline String Element::GetClassName() const
{
    return _className;
}

inline void Element::SetName(const String & name)
{
    _name = name;
}

inline String Element::GetName()
{
    return _name;
}

inline void Element::SetWrapper(const String & name)
{
    _wrapper = name;
}

inline String Element::GetWrapper()
{
    return _wrapper;
}

inline bool Element::IsClipToBounds() const
{
    return _clipToBounds;
}

inline Size Element::RenderSize()
{
    return _size;
}

inline const Size& Element::GetDesiredSize() const
{
    return _desiredSize;
}

inline void Element::SetDesiredSize(Size value)
{
    _desiredSize = value;
}

inline double Element::GetOpacity() const
{
    return _opacity;
}

inline void Element::SetOpacity(double iOpacity)
{
    _opacity = iOpacity;
}

}

#endif
