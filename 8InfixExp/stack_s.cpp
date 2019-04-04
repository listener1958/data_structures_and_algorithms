#include "stack_s.h"

//c++在写模版函数时（template<class T>之类的），头文件不能与cpp文件分离。
//这就意味者，你头文件定义的含模版的地方必须在头文件中实现，没用模版定义的地方可以放在cpp中实现


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
