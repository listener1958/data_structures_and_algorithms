#pragma once

#define STACKINITSIZE 20
#define STACKINCREMENT 10

//typedef double stacktype;


template<class stacktype>
class stack_s
{
	stacktype *base, *top;
	int size;
public:
	stack_s(){
		base = top = new stacktype[STACKINITSIZE];
		size = STACKINITSIZE;
	}
	//void init();
	void push(stacktype s){
		if (top - base + 1 >= size)
		{
			stacktype *sbase, *stop, *ss;
			stop = sbase = new stacktype[size + STACKINCREMENT];
			ss = base;
			while (ss <= top)
			{
				*stop = *ss;
				stop++;
				ss++;
			}
			delete base;
			base = sbase;
			top = --stop;
			size += STACKINCREMENT;
		}

		top++;
		*top = s;
	}
	int pop(stacktype& s){
		if (base == top)
			return 0;

		s = *top--;
		return 1;
	}

	~stack_s(){ delete this->base; }
};

typedef stack_s<double> stack_d;
typedef stack_s<char> stack_c;

