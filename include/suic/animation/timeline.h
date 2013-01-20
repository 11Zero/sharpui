// ���ڿƼ���Ȩ���� 2010-2012
// 
// �ļ�����Timeline.h
// ��  �ܣ����嶯����ʱ�����࣬�κζ������������̳С�
// 
// ��  �ߣ�����
// ʱ  �䣺2012-02-01
// 
// ============================================================================

# ifndef _UITIMELINE_H_
# define _UITIMELINE_H_

#include <suic/core/uiobject.h>

namespace suic
{

class SUICORE_API Timeline : public RefObject
{
public:

    Timeline();
    virtual ~Timeline();

    /// <summary>
    ///     �����������������ԡ�
    /// </summary>
    /// <remarks>
    ///     ���������ΪTrue��ָ���������������к󣬷�������һ�Ρ�
    /// </remarks>
    /// <returns>true: �������к󣬷�������һ��</returns>
    bool GetAutoReverse() const;
    void SetAutoReverse(bool val);

    double GetAccelerationRatio() const;
    void SetAccelerationRatio(double val);

    /// <summary>
    ///     �������п�ʼʱ�䡣
    /// </summary>
    /// <remarks>
    ///     �����Duration�Ķ�����ʼʱ�䡣
    /// </remarks>
    /// <returns>������ʼʱ��</returns>
    double GetBeginTime() const;
    void SetBeginTime(double val);

    double GetDuration() const;
    void SetDuration(double val);

    /// <summary>
    ///     ���úͻ�ȡ���Ŷ����ķ�ʽ��
    /// </summary>
    /// <returns>���Ŷ����ķ�ʽ</returns>
    int GetPlayMode() const;
    void SetPlayMode(int val);

    /// <summary>
    ///     ���úͻ�ȡ�������ظ����͡�
    /// </summary>
    /// <returns>�������ظ�����</returns>
    int GetRepeatMode() const;
    void SetRepeatMode(int val);
    
    /// <summary>
    ///     ���úͻ�ȡ�����Ĳ������ʡ�
    /// </summary>
    /// <returns>�����Ĳ�������</returns>
    double GetSpeedRatio() const;
    void SetSpeedRatio(double val);
    
protected:

    bool _autoReverse;
    double _beginTime;
    double _accRatio;
    int _fillMode;
    int _repeatMode;
    double _speedRatio;
    double _duration;
};

typedef shared<Timeline> TimelinePtr;

};

# endif
