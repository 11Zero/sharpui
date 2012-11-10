// ���ڿƼ���Ȩ���� 2010-2012
// 
// �ļ�����StoryBoard.h
// ��  �ܣ��������Ĳ��š�
// 
// ��  �ߣ�����
// ʱ  �䣺2010-05-01
// 
// ===================================================

# ifndef _UISTORYBOARD_H_
# define _UISTORYBOARD_H_

#include <animation/animation.h>
#include <suicore/uiobject.h>
#include <suicore/uielement.h>
#include <suicore/uiinterface.h>
#include <util/locker.h>

namespace suic
{

typedef struct tagAniItem
{
    AnimationPtr ani;
    TimerIdentityPtr timer;
}AniItem;

class SUICORE_API StoryBoard : public RefObject
{
public:

    StoryBoard();
    virtual ~StoryBoard();

    static bool IsRunning(FrameworkElement* pElem);
    static void StopAnimation(FrameworkElement* pElem);

    /// <summary>
    ///     ��������
    /// </summary>
    /// <remarks>
    ///     �÷���Ϊ�첽����������ڲ����ڼ䣬StoryBoard
    ///     �����ַ��Ҫ��֤��Ч���ظ����ô˷�����ֹͣ��
    ///     һ�εĶ������ţ�һ��StoryBoardһ�ν�������һ��Ԫ��
    /// </remarks>
    /// <param name="pElem">Ŀ��Ԫ��</param>
    /// <returns>��</returns>
    void Start(FrameworkElement* pElem);

    /// <summary>
    ///     ���Ŷ���
    /// </summary>
    /// <remarks>
    ///     �÷�����ָ����Ԫ���ϲ��Ŷ���õĶ���
    ///     �˷�����Ҫ�����ж����������Ż᷵��
    /// </remarks>
    /// <param name="pElem">Ŀ��Ԫ��</param>
    /// <returns>��</returns>
    void Play(FrameworkElement* pElem);

    /// <summary>
    ///     ��ͣ���Ŷ���
    /// </summary>
    /// <remarks>
    ///     �÷���������ͣ��������ж�������
    /// </remarks>
    /// <returns>��</returns>
    void Pause();
    void Stop();
    void Resume();

    /// <summary>
    ///     ���붯��
    /// </summary>
    /// <remarks>
    ///     ����ָ�����͵Ķ�������ʾ��
    /// </remarks>
    /// <param name="pAni">���ŵĶ�������</param>
    /// <returns>��</returns>
    void Add(Animation* pAni);
    void Remove(Animation* pAni);
    
    int GetCount();
    Animation* GetAnimate(int index);
    Animation* CurrentAnimate();

    /// <summary>
    ///     �����������ж���
    /// </summary>
    /// <returns>��</returns>
    void Clear();

protected:

    // ��Ų��ŵĶ�������
    Vector<AniItem> _anis;
    FrameworkElement* _owner;
    Animation* _currentAnimate;

    int _state;
    Mutex _locker;
};

typedef shared<StoryBoard> StoryBoardPtr;


class SUICORE_API StoryBoardInfo : public RefObject
{
public:

    StoryBoardPtr stb;
    AnimationPtr ani;
};

typedef shared<StoryBoardInfo> StoryBoardInfoPtr;

}

# endif
