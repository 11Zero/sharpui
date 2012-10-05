// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����delegate.h
// ��  �ܣ�ʵ��ί�е���
// 
// ��  �ߣ�����
// ʱ  �䣺2010-08-02
// 
// ============================================================================

# ifndef _UIDELEGATE_H_
# define _UIDELEGATE_H_

#include <suicore/uiobject.h>

inline void throwBadInvoke()
{
}

////////////////////////////////////////////////////////////////////////////////////////
// Ŀǰ���֧��9������ί�а�

#define FUNC_RET R

#define UNION_S(a, b) UNION_S_OO((a, b))
#define UNION_S_OO(par) UNION_S_I ## par
#define UNION_S_I(a, b) UNION_S_II(a ## b)
#define UNION_S_II(res) res
#define UNION_ARG(r,u) r##(##u##)

////////////////////////////////////////////////////////////////////////////////////////
// ֧�ֶ���������ظ���

#define ARGS_REPEAT_2_1(T,A) T##1 A##1
#define ARGS_REPEAT_2_2(T,A) ARGS_REPEAT_2_1(T,A),T##2 A##2
#define ARGS_REPEAT_2_3(T,A) ARGS_REPEAT_2_2(T,A),T##3 A##3
#define ARGS_REPEAT_2_4(T,A) ARGS_REPEAT_2_3(T,A),T##4 A##4
#define ARGS_REPEAT_2_5(T,A) ARGS_REPEAT_2_4(T,A),T##5 A##5
#define ARGS_REPEAT_2_6(T,A) ARGS_REPEAT_2_5(T,A),T##6 A##6
#define ARGS_REPEAT_2_7(T,A) ARGS_REPEAT_2_6(T,A),T##7 A##7
#define ARGS_REPEAT_2_8(T,A) ARGS_REPEAT_2_7(T,A),T##8 A##8
#define ARGS_REPEAT_2_9(T,A) ARGS_REPEAT_2_8(T,A),T##9 A##9


#define ARGS_REPEAT_1_1(A) A##1
#define ARGS_REPEAT_1_2(A) ARGS_REPEAT_1_1(A),A##2
#define ARGS_REPEAT_1_3(A) ARGS_REPEAT_1_2(A),A##3
#define ARGS_REPEAT_1_4(A) ARGS_REPEAT_1_3(A),A##4
#define ARGS_REPEAT_1_5(A) ARGS_REPEAT_1_4(A),A##5
#define ARGS_REPEAT_1_6(A) ARGS_REPEAT_1_5(A),A##6
#define ARGS_REPEAT_1_7(A) ARGS_REPEAT_1_6(A),A##7
#define ARGS_REPEAT_1_8(A) ARGS_REPEAT_1_7(A),A##8
#define ARGS_REPEAT_1_9(A) ARGS_REPEAT_1_8(A),A##9


// error Cannot handle Delegate objects that accept more than 9 arguments!


////////////////////////////////////////////////////////////////////////////////////////

#define REPEAT_2_N(n,T,A) UNION_S(ARGS_REPEAT_2_,n(T,A))
#define REPEAT_1_N(n,A) UNION_S(ARGS_REPEAT_1_,n(A))

class X;
union IFunctor
{
   // ���ڷº���ָ��
   mutable void * obj_ptr;

   // ���������͵ĺ���ָ��
   mutable void (*func_ptr)();

   // ���ڳ�Ա���� ָ��
   struct memfunc_ptr_t 
   {
      void (X::*memfunc_ptr)(int);
      void * obj_ptr;
   }bound_memfunc_ptr;
};
//functor.func_ptr = (void (*)())(f);
//functor.obj_ptr = new FunctionObj(f);

template<typename sinature>
class delegate {};

template<typename sinature>
struct function_call {};


// 0������ί��
#define ARGS_COUNT 0
#include "delegate.inl"


// ֧��һ������ί��
#define ARGS_COUNT 1
#include "delegate.inl"

#define ARGS_COUNT 2
#include "delegate.inl"

#define ARGS_COUNT 3
#include "delegate.inl"

#define ARGS_COUNT 4
#include "delegate.inl"


#define ARGS_COUNT 5
#include "delegate.inl"

#define ARGS_COUNT 6
#include "delegate.inl"

#define ARGS_COUNT 7
#include "delegate.inl"

#define ARGS_COUNT 8
#include "delegate.inl"

#define ARGS_COUNT 9
#include "delegate.inl"

#endif