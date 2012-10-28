// ���ڿƼ���Ȩ���� 2010-2012
// 
// �ļ�����uivisualcollection.h
// ��  �ܣ�������Ӷ��󼯺ϡ�
// 
// ��  �ߣ�����
// ʱ  �䣺2011-05-01
// 
// ============================================================================

# ifndef _UIVISUALCOLLECTION_H_
# define _UIVISUALCOLLECTION_H_

#include <suicore/uivisual.h>

namespace suic
{

class Visual;
class SUICORE_API VisualCollection : public RefObject
{
public:

    Vector<VisualPtr> _items; 
    VisualPtr _owner; 

    VisualCollection(VisualPtr parent);
    virtual ~VisualCollection();

protected:

};

};

# endif
