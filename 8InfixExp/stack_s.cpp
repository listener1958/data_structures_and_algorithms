#include "stack_s.h"

//c++��дģ�溯��ʱ��template<class T>֮��ģ���ͷ�ļ�������cpp�ļ����롣
//�����ζ�ߣ���ͷ�ļ�����ĺ�ģ��ĵط�������ͷ�ļ���ʵ�֣�û��ģ�涨��ĵط����Է���cpp��ʵ��


//template<class stacktype>
//stack_s<stacktype>::stack_s()
//{
//	base = top = new stacktype[STACKINITSIZE];
//	size = STACKINITSIZE;
//}
//
//template<class stacktype>
//void stack_s<stacktype>::push(stacktype s)
//{
//	if (top - base + 1 >= size)
//	{
//		stacktype *sbase, *stop, *ss;
//		stop = sbase = new stacktype[size + STACKINCREMENT];
//		ss = base;
//		while (ss <= top)
//		{
//			*stop = *ss;
//			stop++;
//			ss++;
//		}
//		delete base;
//		base = sbase;
//		top = --stop;
//		size += STACKINCREMENT;
//	}
//
//	top++;
//	*top = s;
//}
//
//template<class stacktype>
//int stack_s<stacktype>::pop(stacktype & s)
//{
//	if (base == top)
//		return 0;
//
//	s = *top--;
//	return 1;
//}
//
//template<class stacktype>
//stack_s<stacktype>::~stack_s()
//{
//	delete this->base;
//}
