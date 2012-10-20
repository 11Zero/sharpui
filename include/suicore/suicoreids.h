// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����uilibids.h
// ��  �ܣ�������Դ�õ��ı�ʶ
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-08
// 
// ============================================================================

# ifndef _UILIBIDS_H_
# define _UILIBIDS_H_

namespace suic
{

static String ISLAYEREDWINDOW = _T("IsLayeredWindow");

// ȫ��Ψһ��ԴID
static String USID = _T("usid");
static String RESOURCES = _T("Resources");

static String WINDOW = _T("Window");

static String PANEL = _T("Panel");
static String LAYOUT = _T("Layout");
static String STACKPANEL = _T("StackPanel");
static String FLOWPANEL = _T("FlowPanel");

static String GRID = _T("Grid");
static String GRIDROW = _T("Grid.Row");
static String GRIDCOLUMN = _T("Grid.Column");

static String BUTTON = _T("Button");
static String CHECKBUTTON = _T("CheckButton");
static String RADIOBUTTON = _T("RadioButton");

static String SCROLLBAR = _T("ScrollBar");
static String TOOLBAR = _T("ToolBar");
static String MENUBAR = _T("MenuBar");

static String TEXTBOX = _T("TextBox");
static String RICHTEXTBOX = _T("RichTextBox");

static String LISTCTRL = _T("ListCtrl");
static String LISTBOX = _T("ListBox");
static String COMBOBOXLISTBOX = _T("ComboBox.ListBox");
static String TREECTRL = _T("TreeCtrl");

static String COMBOBOX = _T("ComboBox");

///////////////////////////////////////////////////////////////////////////////
// ���Զ���

// ���������Ľ��洰��
static String STARTUPRRI = _T("StartupUri");

static String CLIPTOBOUNDS = _T("ClipToBounds");
static String TOPMOST = _T("TopMost");

static String WIDTH = _T("Width");
static String HEIGHT = _T("Height");

static String STRETCH = _T("Stretch");
static String CONTENT = _T("Content");

static String BACKGROUND = _T("Background");
static String FOREGROUND = _T("Foreground");

static String FONTFAMILY = _T("Family");
static String FONTSIZE = _T("Size");
static String FONTSTYLE = _T("FontStyle");
static String FONTWEIGHT = _T("Weight");
static String FONTSTRETCH = _T("Stretch");

// Բ��ˮƽ����ĳ���
static String RADIUSX = _T("RadiusX");
// Բ�Ǵ�ֱ����ĳ���
static String RADIUSY = _T("RadiusY");

static String OPACITY = _T("Opacity");
static String OPACITYMASK = _T("OpacityMask");

static String TEXT = _T("Text");
static String NAME = _T("Name");
static String ENABLE = _T("Enable");
static String TOOLTIP = _T("ToolTip");
static String VISIBILITY = _T("Visibility");
static String ORIENTATION = _T("Orientation");

static String VERTICALALIGNMENT = _T("VerticalAlignment");
static String HORIZONTALALIGNMENT = _T("HorizontalAlignment");

static String VERTICALCONTENTALIGNMENT = _T("VerticalContentAlignment");
static String HORIZONTALCONTENTALIGNMENT = _T("HorizontalContentAlignment");

// Ԫ�����ݵ���ʾ����
static String FLOWDIRECTION = _T("FlowDirection");
static String ZINDEX = _T("ZIndex");
static String LOCATION = _T("Location");

// ������Ԫ�غ���������Ԫ��֮�����߾�
static String MARGIN = _T("Margin");
// ������Ԫ�ص����ݺ����Ե�ľ���
static String PADDING = _T("Padding");

static String MINWIDTH = _T("MinWidth");
static String MAXWIDTH = _T("MaxWidth");

static String MINHEIGHT = _T("MinHeight");
static String MAXHEIGHT = _T("MaxHeight");

// �߿�ˢ����������ɫ�����仭ˢ��ͼ��Ϳջ�ˢ
static String BORDERBRUSH = _T("BorderBrush");

// �߿��С,Rect����,left��top��right��bottom�ֱ����
// �ĸ��߿�ĸߺͿ�
static String BORDERTHICKNESS = _T("BorderThickness");

static String IMAGEBRUSH = _T("ImageBrush");
static String IMAGESOURCE = _T("Source");
static String VIEWBOX = _T("ViewBox");
static String VIEWBOXUNITS = _T("ViewboxUnits");
static String VIEWPORT = _T("Viewport");
static String VIEWPORTUNITS = _T("ViewportUnits");
static String ALIGNMENTX = _T("AlignmentX");
static String ALIGNMENTY = _T("AlignmentY");
static String TILEMODE = _T("TileMode");
static String IMAGECORNER = _T("ViewCorner");
static String DRAWEDGE = _T("DrawEdge");

// ���仭ˢ
static String LINEARGRADIENTBRUSH = _T("LinearGradientBrush");
static String STARTPOINT = _T("StartPoint");
static String ENDPOINT = _T("EndPoint");
static String GRADIENTSTOP = _T("GradientStop");
static String COLOR = _T("Color");
static String OFFSET = _T("Offset");

///////////////////////////////////////////////////////////////////////////////
// ����ֵ����
//
static String VERTICAL = _T("Vertical");
static String HORIZONTAL = _T("Horizontal");

static String True = _T("True");
static String False = _T("False");
static String LEFT = _T("Left");
static String RIGHT = _T("Right");
static String TOP = _T("Top");
static String BOTTOM = _T("Bottom");
static String CENTER = _T("Center");
static String JUSTIFY = _T("Justify");

static String NONE = _T("None");
static String Null = _T("Null");
static String XNULL = _T("x:Null");

static String VISIBLE = _T("Visible");
static String HIDDEN = _T("Hidden");
static String COLLAPSED = _T("Collapsed");

static String RELATIVETOBOUNDINGBOX = _T("RelativeToBoundingBox");
static String Absolute = _T("Absolute");
static String FLIPX = _T("FlipX");
static String FLIPY = _T("FlipY");
static String FLIPXY = _T("FlipXY");
static String TILE = _T("Tile");

static String FILL = _T("Fill");
static String UNIFORM = _T("Uniform");
static String UNIFORMTOFILL = _T("UniformToFill");

static String RIGHTTOLEFT = _T("RightToLeft");
static String LEFTTORIGHT = _T("LeftToRight");

///////////////////////////////////////////////////////////////////////////////
// ״̬����

static String STATICRESOURCE = _T("StaticResource");
static String DYNAMICRESOURCE = _T("DynamicResource"); 

static String WRAPPERTYPE = _T("Wrapper");
static String BASEDON = _T("BasedOn");
static String XKEY = _T("x:Key");
static String XTYPE = _T("x:Type");
static String PROPERTY = _T("Property");
static String VALUE = _T("Value");
static String XPREFIX = _T("x:");
static String VPREFIX = _T("v:");
static String SETTER_VALUE = _T("Setter.Value");
static String SETTER = _T("Setter");
static String TRIGGERS = _T("Triggers");
static String TRIGGER = _T("Trigger");
static String STYLE = _T("Style");
static String TARGETTYPE = _T("TargetType");

static String STATE = _T("");
static String NORMAL = _T("Normal");
static Uint32 U_NORMAL = 0;

static String DEFAULT = _T("Default");
static Uint32 U_DEFAULT = 0;

static String MOUSEOVER = _T("IsMouseOver");
static Uint32 U_MOUSEOVER = 1;

static String PRESSED = _T("IsPressed");
static Uint32 U_PRESSED = 2;

static String DISABLED = _T("IsDisabled");
static Uint32 U_DISABLED = 3;

static String FOCUSED = _T("IsFocused");
static Uint32 U_FOCUSED = 4;

static String SELECTED = _T("IsSelected");
static Uint32 U_SELECTED = 5;

static String CURSOR = _T("Cursor");

};

# endif
