// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����UIRouteEvent.h
// ��  �ܣ�������Ŀ��·���¼����ࡣ
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _UIROUTEEVENT_H_
# define _UIROUTEEVENT_H_

#include <suic/core/uiobject.h>
#include <suic/core/delegate.h>

namespace suic
{

/// <summary>
/// ����Ԫ�صĴ���ʽ��Tunneling�����ע���˻����¼���ϵͳ�¼�����ģ��
/// ��������¼�����ֱ���¼����������
/// </summary>
enum RoutingStrategy
{
    Direct,
    Bubble,
    Tunnel,
};

class RoutedEvent : public RefObject
{
public:

    RoutedEvent(String name, RoutingStrategy routingStrategy, String handlerType, TypeofInfo* ownerType);
    RoutingStrategy GetRoutingStrategy() const;
    TypeofInfo* GetOwnerType() const;
    String GetName() const;
    int GetGlobalIndex() const;

protected:

    String _name;
    TypeofInfo* _ownerType;
    int _globalIndex;
    RoutingStrategy _routingStrategy;    
};

typedef suic::shared<RoutedEvent> RoutedEventEntity;

};

# endif
