// ���ڿƼ���Ȩ���� 2010-2012
// 
// �ļ�����dpobject.h
// ��  �ܣ�Sharpui�Ļ��࣬������Ե�����ʵ�ֵ��߼���
// 
// ��  �ߣ�����
// ʱ  �䣺2011-05-01
// 
// ============================================================================

# ifndef _UIDPOBJECT_H_
# define _UIDPOBJECT_H_

#include <suic/core/uiobject.h>
#include <suic/tools/map.h>

namespace suic
{

class SUICORE_API DpObject : public RefObject 
{    
public:
  
    DpObject() {}

    DeclareTypeofInfo(DpObject, RefObject)

    ObjectPtr GetValue(const DpPropertyEntity& dp) const;
    void SetValue(DpPropertyEntity& dp, ObjectPtr value);

    ObjectPtr ReadLocalValue(const DpPropertyEntity& dp) const;
    void ClearValue(DpPropertyEntity& dp);

    ObjectPtr ReadBaseValue(const DpPropertyEntity& dp) const;
    void WriteBaseValue(const DpPropertyEntity& dp, ObjectPtr val);

    void RestoreLocalValue(const DpPropertyEntity& dp);

protected:

    mutable Map<int, EffectiveEntryPtr> _effectiveValues;
};

}

# endif
