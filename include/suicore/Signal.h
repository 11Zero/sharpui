//	Copyright (c) 2008-2009, Inc, ���ڿƼ���Ȩ����.
//
//	�ļ��� : Signal.h
//	��  �� : �ź���
//
//	��  �� : no
//	
//	��  �� : 1.0
//	��  �� : ����
//	��  �� : 2008-08-10

// �޸ļ�¼ ==================================================================
// ����				����			�汾		����
// 
// ===========================================================================

#ifndef __SIGNAL_H
#define __SIGNAL_H

#include <suicore/uiobject.h>

namespace suic
{

class SUICORE_API Signal
{
public:

	Signal(bool bSignal=true);
	Signal(bool bMenuReset,bool bSignal);

	~Signal();

	operator Handle() const;

	bool Wait(int iTimeout=INFINITE);

    /// <summary>
    ///     �ȴ��ڲ����ⲿ�¼���
    /// </summary>
    /// <param name="_Other">�ⲿ�¼�</param>
    /// <param name="iTimeout">��ʱʱ��</param>
    /// <returns>��������¼�����,����1;����ⲿ�¼�����,����2;��ʱ����3;����-1</returns>
    int Wait(Signal& _Other, int iTimeout=INFINITE);

	void Notify();

	void Reset();

private:

	Handle _signal;
};

}

#endif