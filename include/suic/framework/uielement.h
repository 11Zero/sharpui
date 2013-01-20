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

#include <suic/framework/uivisual.h>
#include <suic/framework/uievent.h>
#include <suic/framework/eventhandlersstore.h>

#include <suic/core/delegate.h>
#include <suic/framework/uieventhandler.h>
#include <suic/styles/ResourceDictionary.h>

namespace suic
{

class Element;
typedef shared<Element> ElementPtr;

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

    DeclareTypeofInfo(Element, Visual)

    // �¼�����
    static RoutedEventEntity MouseDownEvent;
    static RoutedEventEntity MouseUpEvent;

    static RoutedEventEntity MouseLeftButtonDbclk;

    static RoutedEventEntity MouseEnterEvent;
    static RoutedEventEntity MouseMoveEvent;
    static RoutedEventEntity MouseLeaveEvent;
    static RoutedEventEntity MouseLButtonDownEvent;
    static RoutedEventEntity MouseLButtonUpEvent;
    static RoutedEventEntity MouseRButtonDownEvent;
    static RoutedEventEntity MouseRButtonUpEvent;
    static RoutedEventEntity CursorSetEvent;
    static RoutedEventEntity MouseWheelEvent;
    static RoutedEventEntity LostMouseCaptureEvent;
    static RoutedEventEntity GotMouseCaptureEvent;
    static RoutedEventEntity GotFocusEvent;
    static RoutedEventEntity LostFocusEvent;

    // �����¼�
    static RoutedEventEntity TextInputEvent;
    static RoutedEventEntity KeyDownEvent;
    static RoutedEventEntity KeyUpEvent;

    // �϶��¼�
    static RoutedEventEntity DropEvent;
    static RoutedEventEntity DragEnterEvent;
    static RoutedEventEntity DragLeaveEvent;
    static RoutedEventEntity DragOverEvent;

    // ��ʼ���¼�������Ԫ������ڲ���ʼ�����һ�ε���
    // ���¼���������һ��
    static RoutedEventEntity InitializedEvent;
    static RoutedEventEntity ThemeChangedEvent;

    static RoutedEventEntity LoadedEvent;
    static RoutedEventEntity UnloadedEvent;

    static RoutedEventEntity TargetUpdatedEvent;
    static RoutedEventEntity HitTestEvent;

    // Ԥ���¼�,ִ��Դ�¼�֮ǰ�����ȵ��ô��¼�
    // ���¼���Ӹ�Ԫ�ؿ�ʼִ��
    static RoutedEventEntity PreMouseDownEvent;
    static RoutedEventEntity PreMouseUpEvent;

    static RoutedEventEntity PreMouseLeftButtonDbclk;

    static RoutedEventEntity PreMouseWheelEvent;
    static RoutedEventEntity PreMouseMoveEvent;

    static RoutedEventEntity PreMouseLButtonDownEvent;
    static RoutedEventEntity PreMouseLButtonUpEvent;
    static RoutedEventEntity PreMouseRButtonDownEvent;
    static RoutedEventEntity PreMouseRButtonUpEvent;

    // ����Ԥ���¼�
    static RoutedEventEntity PreTextInputEvent;
    static RoutedEventEntity PreKeyDownEvent;
    static RoutedEventEntity PreKeyUpEvent;

    static RoutedEventEntity PreDropEvent;
    static RoutedEventEntity PreDragEnterEvent;
    static RoutedEventEntity PreDragLeaveEvent;
    static RoutedEventEntity PreDragOverEvent;

    static RoutedEventEntity IsSelectedEvent;

public:

    static DpPropertyEntity NameProperty;
    static DpPropertyEntity OpacityProperty;

    static DpPropertyEntity VerticalAlignmentProperty;
    static DpPropertyEntity HorizontalAlignmentProperty;

    // ��������Ԫ�������Ĵ�С,�˴�С���ܻ����Ⱦ�����С��һ��
    // ��Ϊ����ܻᱻ�丸����Ԫ�ظı䡣
    static DpPropertyEntity DesiredSizeProperty;
    static DpPropertyEntity WrapperProperty;

    // ��������������
    static DpPropertyEntity HandleChildMouseEnterProperty;

public:

    /// <summary>
    ///  ���������һ�ݶ���
    /// </summary>
    /// <returns>���ݶ���</returns> 
    virtual ElementPtr Clone() const;

    void AddHandler(RoutedEventEntity routedEvent, ObjectPtr handler, bool handledEventsToo);
    void AddHandler(RoutedEventEntity routedEvent, ObjectPtr handler);
    void RemoveHandler(RoutedEventEntity routedEvent, ObjectPtr handler);

    /// <summary>
    ///  ��������Ԫ�صĳߴ�
    /// </summary>
    /// <remarks>
    ///  �˷�����ݹ���������Լ������ӽ���Ԫ�صĳߴ硣
    ///  Ĭ�Ͻ��������Ԫ�ص���Сֵ�����ֵ���ƣ����
    ///  ������Width��Height����ʹ������ֵ�������ֵ�������ԣ�
    ///  availableSize�����ο�����ʵ�����塣
    /// </remarks>
    /// <param name="availableSize">
    ///  �ο���С
    /// </param>
    /// <returns>��</returns> 
    virtual void Measure(const Size & availableSize);

    /// <summary>
    ///  �Խ���Ԫ�ؽ��в���
    /// </summary>
    /// <remarks>
    ///  �˷�����ݹ鲼�������Լ������ӽ���Ԫ�صĲ���
    ///  �ڶ��ӽ���Ԫ�ؽ��в���֮ǰ��������������е�
    ///  ���ӽ���Ԫ�ء�
    /// </remarks>
    /// <param name="finalRect">������Ԫ�ظ���������λ�ô�С</param>
    /// <returns>��</returns> 
    virtual void Arrange(const Rect & finalRect);

    /// <summary>
    ///  ����������������Ϣ
    /// </summary>
    /// <remarks>
    ///  ӵ����ͬ���Ľ���Ԫ�ض�����һ��Context��������
    /// </remarks>
    /// <param name="key">���ݶ���Key</param>
    /// <param name="value">���ݶ���Value</param>
    /// <returns>��</returns> 
    void SetContext(const String& key, ObjectPtr value);

    /// <summary>
    ///  ȡ��������������Ϣ
    /// </summary>
    /// <param name="key">���ݶ���Key</param>
    /// <returns>���������ݶ���ֵ</returns> 
    ObjectPtr GetContext(const String& key);

    /// <summary>
    ///  �������Ľ���״̬
    /// </summary>
    /// <remarks>
    ///  ���������Ԫ���ܹ�ӵ�н��㣬��ô���������OnGotFocus()��
    ///  ͬʱ����֮ǰ�Ľ���Ԫ�ص�OnLostFocus()��
    /// </remarks>
    /// <returns>�������Ԫ��ӵ�н��㷵��true������false</returns> 
    bool SetFocus();

    /// <summary>
    ///  �������Ԫ��
    /// </summary>
    /// <remarks>
    ///  ����丸����Ԫ�ش��ڽ���״̬���˽���Ԫ��Ҳ
    ///  �ᱻ���á�
    /// </remarks>
    /// <returns>�����ϴν���Ԫ�ؼ���״̬</returns> 
    virtual bool Enable(bool val);

    /// <summary>
    ///  ���ý���Ԫ�صĿɼ�״̬
    /// </summary>
    /// <param name="val">�ɼ���־</param>
    /// <returns>�����ϴν���Ԫ�ؿɼ�״̬</returns> 
    virtual bool SetVisible(bool val);

    bool IsLogicalElement() const;

    /// <summary>
    ///  ����Ԫ���¼�
    /// </summary>
    /// <param name="e">Ԫ���¼�</param>
    /// <returns>��</returns> 
    void RaisedEvent(RoutedEventArg* e);

    virtual bool CheckName(String& name);

    /// <summary>
    ///  �жϵ�ǰ����Ԫ���Ƿ񱻳�ʼ����
    /// </summary>
    /// <remarks>
    ///  ֻ�б���ʼ���Ľ���Ԫ������ص���ʽ����Դ�Ż��ʼ����
    ///  ��ʱ����Ҳ���ᴥ��������׼��������Ҫ�����ݡ�
    /// </remarks>
    /// <returns>true: �������Ԫ���Ѿ���ʼ��</returns> 
    bool IsInitialized() const;

    /// <summary>
    ///  ˢ�½���Ԫ�ػ��ơ�
    /// </summary>
    /// <remarks>
    ///  ���ڷֲ㴰�ڽ���ֱ�ӻ��ƣ�������ڻ����߳���
    ///  ���첽ִ�С�
    /// </remarks>
    /// <param name="bForce">�Ƿ�ǿ��ˢ��</param>
    /// <returns>��</returns>
    void InvalidateVisual(bool bForce=false);

    /// <summary>
    ///  ˢ�½���Ԫ�ػ��ơ�
    /// </summary>
    /// <remarks>
    ///  �˷���ָ���ü�����
    /// </remarks>
    /// <param name="lprc">�ü�����</param>
    /// <param name="bForce">�Ƿ�ǿ��ˢ��</param>
    /// <returns>��</returns>
    void InvalidateRect(suic::Rect* lprc, bool bForce=false);

    /// <summary>
    ///  ���Բ������Ŀ���Ȩ��
    /// </summary>
    /// <returns>��</returns>
    void SetCaptureMouse();

    /// <summary>
    ///  �����ͷ����Ŀ���Ȩ��
    /// </summary>
    /// <remarks>
    ///  �����ǰ����Ĳ��Ǳ�Ԫ�أ����ԡ�
    /// </remarks>
    /// <returns>��</returns>
    void ReleaseCaptureMouse();

    virtual String ToString();

    /// <summary>
    ///  ���������ת��Ϊ����Ԫ�ص����ꡣ
    /// </summary>
    /// <param name="point">��������</param>
    /// <returns>����Ԫ������</returns>
    Point PointFromScreen(Point point);

    /// <summary>
    ///  ����Ԫ�������ת��Ϊ�������ꡣ
    /// </summary>
    /// <param name="point">��������</param>
    /// <returns>��������</returns>
    Point PointToScreen(Point point);

    DrawingContextPtr RenderOpen();
    void RenderClose();

public:

    virtual void OnPreviewSetCursor(CursorEventArg& e);
    virtual void OnSetCursor(CursorEventArg& e);

    // ����¼�����
    virtual void OnMouseDown(MouseEventArg& e);
    virtual void OnMouseUp(MouseEventArg& e);

    virtual void OnMouseEnter(MouseEventArg& e);
    virtual void OnMouseMove(MouseEventArg& e);
    virtual void OnMouseLeave(MouseEventArg& e);

    virtual void OnMouseWheel(MouseWheelEventArg& e);

    virtual void OnMouseLeftButtonDown(MouseEventArg& e);
    virtual void OnMouseLeftButtonUp(MouseEventArg& e);
    virtual void OnMouseRightButtonDown(MouseEventArg& e);
    virtual void OnMouseRightButtonUp(MouseEventArg& e);

    virtual void OnMouseLeftButtonDbclk(MouseEventArg& e);

    // ���Ԥ���¼�����
    virtual void OnPreviewMouseDown(MouseEventArg& e);
    virtual void OnPreviewMouseUp(MouseEventArg& e);

    virtual void OnPreviewMouseMove(MouseEventArg& e);
    virtual void OnPreviewMouseWheel(MouseEventArg& e);

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

    // �϶�Ԥ���¼�����
    virtual void OnPreviewDragEnter(DragEventArg& e);
    virtual void OnPreviewDragLeave(DragEventArg& e);
    virtual void OnPreviewDragOver(DragEventArg& e);
    virtual void OnPreviewDrop(DragEventArg& e);


    // �����¼�����
    virtual void OnTextInput(KeyboardEventArg& e);
    virtual void OnKeyDown(KeyboardEventArg& e);
    virtual void OnKeyUp(KeyboardEventArg& e); 

    // Ԥ��������¼�����
    virtual void OnPreviewTextInput(KeyboardEventArg& e);
    virtual void OnPreviewKeyDown(KeyboardEventArg& e);
    virtual void OnPreviewKeyUp(KeyboardEventArg& e); 

    // ������׽�¼�����
    virtual void OnLostKeyboardFocus(KeyboardEventArg& e);

    virtual void OnLostMouseCapture(MouseEventArg& e);
    virtual void OnGotMouseCapture(MouseEventArg& e);

    virtual void OnGotFocus(FocusEventArg& e);
    virtual void OnLostFocus(FocusEventArg& e);

    // Ԫ����ӱ仯�¼�����
    //virtual void OnChildrenChanged(ElementPtr kidAdded, ElementPtr kidRemoved);
    //virtual void OnParentChanged(ElementPtr oldParent, ElementPtr newParent);
    //virtual void OnStyleChanged(StylePtr oldStyle, StylePtr newStyle);
    
    virtual void OnRenderSizeChanged(RenderSizeChangedEventArg& e);
    virtual void OnRenderSizeModeChanged(SizeModeChangedEventArg& e);

    virtual void OnTimer(int iTimerId);
    virtual void OnLeaveTimer(int iTimerId);

    virtual void BeginInit();
    virtual void EndInit();

    virtual bool OnEvent(Element* sender, Object* event);

    /// <summary>
    ///  ���ڼ����¼���
    /// </summary>
    /// <remarks>
    ///  �ڴ��ڴ���׼����ʾʱÿ��Ԫ�ض��ᱻ���á�
    /// </remarks>
    /// <param name="e">�����¼�</param>
    /// <returns>��</returns>
    virtual void OnLoaded(LoadedEventArg& e);
    virtual void OnUnloaded(LoadedEventArg& e);
    virtual void OnTargetUpdated(DataTransferEventArg& e);

    /// <summary>
    ///  Ԫ������ֵ�仯ʱ���лص���������Ԫ�ر���ڵ�����ԣ�
    /// </summary>
    /// <remarks>
    ///  ��һ�μ��غ͸�����Դʱ������á�
    /// </remarks>
    /// <param name="e">������Ϣ�¼�</param>
    /// <returns>��</returns>
    virtual void OnPropertyChanged(PropertyChangedEventArg& e);

    /// <summary>
    ///  IsSelected��״̬�仯ʱ�ص���
    /// </summary>
    /// <remarks>
    ///  ״̬�仯ʱ��Ԫ���д�����ᡣ
    /// </remarks>
    /// <param name="e">״̬�¼��������¾�״̬</param>
    /// <returns>��</returns>
    virtual void OnStateChanged(StateChangedEventArg& e);
    virtual void OnVisibilityChanged(bool visible);
    virtual void OnHitTest(HitResultEventArg& e);

    /// <summary>
    ///  ���½���Ԫ�صĲ��֡���ʾ��
    /// </summary>
    /// <remarks>
    ///  �˷����ڲ�����InvalidateArrange()��InvalidateVisual()��
    /// </remarks>
    /// <returns>��</returns>
    void UpdateLayout();

    /// <summary>
    ///  ˢ��Ԫ�ز��֡�
    /// </summary>
    /// <returns>��</returns>
    void InvalidateArrange();

    /// <summary>
    ///  ˢ��Ԫ�ش�С��
    /// </summary>
    /// <returns>��</returns>    
    void InvalidateMeasure();

    bool ReadFlag(int key) const;
    void WriteFlag(int key, bool add);

    void InputHitTest(Point pt, ElementPtr& enabledHit, ElementPtr& rawHit);

    virtual void RaisedMeasureDirty();

public:

    /// <summary>
    ///  �õ�����Ԫ�ص��߼���Ԫ�ء�
    /// </summary>
    /// <remarks>
    ///  �߼���Ԫ�غͿ��Ӹ�Ԫ�ؿ��ܲ�һ����
    /// </remarks>
    /// <returns>��Ԫ��</returns>
    virtual suic::Element* LogicalParent() const;

    /// <summary>
    ///  �õ�����Ԫ�صĿ��Ӹ�Ԫ�ء�
    /// </summary>
    /// <returns>���Ӹ�Ԫ��</returns>
    suic::Element* GetParent() const;

    virtual void OnRender(DrawingContext * drawing);

    /// <summary>
    /// �����߼�Ԫ�أ��˷�������Ԫ�ص��߼���Ԫ�ء�
    /// ���߼�������ϵ����˴˷���Ԫ�ؽ��ᱻ�����߼���
    /// ������Ԫ�أ��������ʽ���߼�����һ�����塣
    /// </summary>
    /// <param name="child">��Ԫ��</param>
    /// <returns>��</returns>
    void AddLogicalChild(suic::Element* child);

    /// <summary>
    ///  ����һ����Ԫ��
    /// </summary>
    /// <param name="index">��������λ��</param>
    /// <param name="child">��Ԫ��</param>
    /// <returns>��</returns>
    virtual int AddChild(ObjectPtr obj);
    virtual int AddText(const String& val);

    /// <summary>
    ///  ��ָ��λ�ò�����Ԫ�ء�
    /// </summary>
    /// <param name="index">��������λ��</param>
    /// <param name="child">��Ԫ��</param>
    /// <returns>�����Ԫ������</returns>
    virtual int InsertChild(int index, suic::ObjectPtr child);

    /// <summary>
    ///  ��������߼�Ԫ�ء�
    /// </summary>
    /// <returns>��</returns>
    virtual void ClearChildren();

    /// <summary>
    ///  �Ƴ�ָ����Ԫ�ء�
    /// </summary>
    /// <param name="child">��Ԫ��</param>
    /// <returns>��</returns>
    virtual void RemoveChild(suic::ObjectPtr child);

    /// <summary>
    ///  ��ȡ�߼�Ԫ��,�������뷵���ʺ��Լ����߼���Ԫ��
    /// </summary>
    /// <param name="index">����λ��</param>
    /// <returns>��Ԫ��</returns>
    virtual Element* GetChild(int index);

    /// <summary>
    ///  ��ȡ�߼�Ԫ�ظ�����
    /// </summary>
    /// <returns>�߼�Ԫ�ظ���</returns>
    virtual Int32 GetChildrenCount();

    virtual ObjectPtr GetInternalValue(String key);
    virtual void SetInternalValue(String key, ObjectPtr val);

public:

    /// <summary>
    ///  ����ָ���Ľ���Ԫ��
    /// </summary>
    /// <remarks>
    ///  ʹ��Name=""��������Բ��ұ����Լ����ӽڵ�Ľ���Ԫ�ء�
    /// </remarks>
    /// <param name="strName">Ԫ�����ƣ���Name���塣</param>
    /// <returns>����Ԫ�ض���</returns> 
    virtual ElementPtr FindName(const String& strName);
    bool IsRenderable() const;

// ���Է��ʶ���
public:

    int GetPersistId() const;
    SetterCollectionPtr& GetSetters();

    /// <summary>
    ///  �жϵ�ǰ����Ԫ�صĿɼ��ԡ�
    /// </summary>
    /// <remarks>
    ///  �����Ԫ�ز��ɼ�����Ҳ���ɼ���
    /// </remarks>
    /// <returns>true: ����Ԫ�ؿɼ�</returns>
    bool IsVisible() const;

    /// <summary>
    ///  �жϵ�ǰ����Ԫ�صĽ����ԡ�
    /// </summary>
    /// <remarks>
    ///  �����Ԫ�ؽ��ã���Ҳ���á�
    /// </remarks>
    /// <returns>true: ����Ԫ�ؿ���</returns> 
    bool IsEnabled() const;

    /// <summary>
    ///  �жϽ���Ԫ���Ƿ�ӵ�н��㡣
    /// </summary>
    /// <returns>true: ӵ�н���</returns> 
    bool IsFocused() const;

    /// <summary>
    ///  �ж�����ڽ���Ԫ���ϻ����ӽ���Ԫ���ϡ�
    /// </summary>
    /// <remarks>
    ///  �����Ԫ��ӵ����꣬��Ҳ����true��
    /// </remarks>
    /// <returns>true: ӵ�����</returns> 
    virtual bool IsMouseOver() const;

    /// <summary>
    ///  �ж�����ڽ���Ԫ���ϡ�
    /// </summary>
    /// <remarks>
    ///  ֻ�����ֱ����Ԫ���ϲŷ���true��
    /// </remarks>
    /// <returns>true: ӵ�����</returns> 
    bool IsMouseDirectlyOver() const;

    /// <summary>
    ///  �жϽ������Ԫ�ص�����Ƿ�ĳ������Ԫ�ؿ��ơ�
    /// </summary>
    /// <remarks>
    ///  ĳЩ����Ԫ�ػ���hot״̬ʱ������Ҫ�жϴ˱�־��
    /// </remarks>
    /// <returns>true: ӵ�����</returns> 
    bool IsMouseCaptured() const;

    /// <summary>
    ///  �жϽ������Ԫ�ص�����Ƿ�ĳ������Ԫ�ؿ��ơ�
    /// </summary>
    /// <remarks>
    ///  ���ӽ���Ԫ�ؿ���Ҳ����true��
    /// </remarks>
    /// <returns>true: ӵ�����</returns> 
    bool IsMouseCaptureWithin() const;

    /// <summary>
    /// �жϽ���Ԫ���Ƿ�ѹ�¡�
    /// </summary>
    /// <returns>true: Ԫ�ر�ѹ��</returns>
    virtual bool IsSelected() const;
    virtual void SetSelected(bool val);

    /// <summary>
    ///  �жϵ�ǰ����Ԫ�ص������ԡ�
    /// </summary>
    /// <returns>true: ����Ԫ������</returns> 
    bool IsCollapsed() const;

    /// <summary>
    ///  �жϽ���Ԫ���Ƿ����ϡ�
    /// </summary>
    /// <returns>true: ��������</returns> 
    bool IsTopMost() const;

    /// <summary>
    ///     �жϽ���Ԫ���Ƿ�ѹ�¡�
    /// </summary>
    /// <returns>true: Ԫ�ر�ѹ��</returns>
    bool IsMouseDown() const;

    bool IsFocusedWithin() const;
    bool IsKeyboardFocusWithin() const;

    /// <summary>
    ///  ���ý���Ԫ�ص��Զ������ݶ���
    /// </summary>
    /// <remarks>
    ///  �û������Զ����Լ������ݶ���Ȼ��ͨ���˷���
    ///  �󶨵�����Ԫ��
    /// </remarks>
    /// <param name="pData">�Զ������ݶ���</param>
    /// <returns>��</returns> 
    ObjectPtr GetUserData() const;
    void SetUserData(ObjectPtr val);

    /// <summary>
    ///  �����Ƿ�ü��ӽ���Ԫ�ص�������Ԫ�ص�����
    /// </summary>
    /// <remarks>
    ///  ������Ҫ�ü������к��ӽ���Ԫ�ػ���ʱ����
    ///  �ü����������������
    /// </remarks>
    /// <param name="value">�ü���־</param>
    /// <returns>��</returns> 
    bool IsClipToBounds() const;
    void SetClipToBounds(bool val);

    /// <summary>
    ///  ��ȡ����Ԫ�صķ���
    /// </summary>
    /// <remarks>
    ///  ����Ԫ�صķ����Ϊˮƽ�ʹ�ֱ��Horizontal��Vertical����
    /// </remarks>
    /// <returns>Horizontal: ˮƽ; Vertical: ��ֱ</returns> 
    CoreFlags::Orientation GetOrientation() const;
    void SetOrientation(CoreFlags::Orientation val);

    /// <summary>
    ///  �жϽ���Ԫ���Ƿ����㡣
    /// </summary>
    /// <returns>true: ����</returns> 
    bool IsFocusable() const;
    void SetFocusable(bool val);

    bool GetAllowDrop() const;
    void SetAllowDrop(bool val);

    /// <summary>
    ///  ���ý���Ԫ�ر�ʶ
    /// </summary>
    /// <remarks>
    ///  ��ͬһ�������д˽���Ԫ�ر�ʶ����Ψһ��
    /// </remarks>
    /// <param name="name">����Ԫ�����Ʊ�ʶ</param>
    /// <returns>��</returns> 
    String GetName() const;
    void SetName(const String& val);

    /// <summary>
    ///  ȡ��Ԫ�ص�ˮƽ���뷽ʽ
    /// </summary>
    /// <remarks>
    ///  ���뷽ʽ��Left��Center��Right��Stretch��
    /// </remarks>
    /// <returns>ˮƽ���뷽ʽ</returns> 
    int GetHorizontalAlignment() const;
    void SetHorizontalAlignment(int val);

    /// <summary>
    ///  ȡ��Ԫ�صĴ�ֱ���뷽ʽ
    /// </summary>
    /// <remarks>
    ///  ���뷽ʽ��Top��Center��Bottom��Stretch��
    /// </remarks>
    /// <returns>��ֱ���뷽ʽ</returns> 
    int GetVerticalAlignment() const;
    void SetVerticalAlignment(int val);

    /// <summary>
    ///  ��ȡ����Ԫ�ص���Ⱦ���򣬴˴�С������������ͻ��ơ�
    /// </summary>
    /// <remarks>
    ///  Arrange�Ժ󣬴�ֵ��ı䡣
    /// </remarks>
    /// <returns>��Ⱦ�����С</returns>
    Size RenderSize() const;
    void RenderSize(Size val);

    double GetOpacity() const;
    void SetOpacity(double val);

    Size GetDesiredSize() const;
    void SetDesiredSize(Size val);

    String GetWrapper() const;
    void SetWrapper(const String& val);

    /// <summary>
    ///  ��ȡ����Ԫ�������ƣ�ÿ������Ԫ�ص������Ψһ��
    /// </summary>
    /// <returns>����Ԫ��������</returns> 
    String GetClassName() const;
    void SetClassName(const String& val);

    EventHandlersStorePtr GetEventHandlersStore() const;

public:

    /// <summary>
    ///  Ԫ�صĳ�ʼ���¼���
    /// </summary>
    /// <remarks>
    ///  �˺�����EndInit���ã���ʱ���е���Դ������Ԫ�ض���ʼ����ϡ�
    /// </remarks>
    /// <returns>��</returns>
    virtual void OnInitialized();

    /// <summary>
    ///  ʵ�ֽ���Ԫ�������Ĵ�С�����߼���
    /// </summary>
    /// <remarks>
    ///  ������Ӧ�ü̳д˷�����������С�ļ��㣬
    ///  �˺���Ĭ�ϻ����Measure����DesiredSizeֵ��
    /// </remarks>
    /// <param name="availableSize">�ο���С</param>
    /// <returns>����Ԫ�������Ĵ�С</returns>
    virtual Size MeasureOverride(const Size& size);

    /// <summary>
    ///  ʵ�ֽ���Ԫ�ش�С��λ�õļ��㡣
    /// </summary>
    /// <remarks>
    ///  ������Ӧ�ü̳д˷����������λ�úʹ�С�ļ��㣬
    ///  ����ԪӦ��ʹ�ô���������Լ�������Ԫ�ء�
    /// </remarks>
    /// <param name="finalRect">��Ԫ���ṩ�Ŀ�������λ�ô�С</param>
    /// <returns>���ֺ�Ĵ�С</returns>
    virtual Size ArrangeOverride(const Size& size);

    /// <summary>
    ///  ʵ�ֽ���Ԫ�ش�С�����߼���
    /// </summary>
    /// <param name="availableSize">�ο���С</param>
    /// <returns>����Ԫ�������Ĵ�С</returns>
    virtual Size MeasureCore(const Size & availableSize);    

    /// <summary>
    ///  ʵ�ֽ���Ԫ������С��λ�õļ��㡣
    /// </summary>
    /// <param name="finalRect">��Ԫ���ṩ�Ŀ�������λ�ô�С</param>
    /// <returns>��</returns>
    virtual void ArrangeCore(const Rect & finalRect);

    /// <summary>
    ///  ����������Ĵ�С�������С���������ơ�
    /// </summary>
    /// <remarks>
    ///  ����߶ȺͿ���Ѿ����ã���ʹ������ֵ��
    /// </remarks>
    /// <param name="desiredSize">�������������������С</param>
    /// <returns>��</returns>
    void MeasureCheck(Size & desiredSize);

protected:

    String _className;
    SetterCollectionPtr _setters;
    EventHandlersStorePtr _eventHandlersStore;
    
    // ��¼Ԫ�ص�״̬,����ʾ32��
    Uint32 _state;

    Size _desiredSize;
    Rect _borderThickness;
    short _horiAlignment;
    short _vertAlignment;
    CoreFlags::Orientation _orientation;

    // ��һ�β�������
    Size _previousAvailableSize;
};

inline EventHandlersStorePtr Element::GetEventHandlersStore() const
{
    return _eventHandlersStore;
}

inline String Element::GetClassName() const
{
    return _className;
}

inline bool Element::IsClipToBounds() const
{
    return _clipToBounds;
}

inline Size Element::RenderSize() const
{
    return _size;
}

inline void Element::RenderSize(Size val)
{
    _size = val;
}

inline SetterCollectionPtr& Element::GetSetters()
{
    return _setters;
}

}

#endif
