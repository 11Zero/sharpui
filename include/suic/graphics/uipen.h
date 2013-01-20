// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����uiPen.h
// ��  �ܣ����廭�ʻ��ࡣ
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _UIPEN_H_
# define _UIPEN_H_

#include <suic/graphics/uiresource.h>

namespace suic
{

class SUICORE_API Pen : public Resource
{
public:

    virtual ~Pen() {}

    double GetThickness() const;
    void GetThickness(double val);

    Color GetColor() const;

protected:

    double _thickness;
    Color _color;
};

typedef shared<Pen> PenPtr;

inline double Pen::GetThickness() const
{
    return _thickness;
}

inline void Pen::GetThickness(double val)
{
    _thickness = val;
}

inline Color Pen::GetColor() const
{
    return _color;
}

}

# endif
