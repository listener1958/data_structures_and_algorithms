#include<iostream>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10

using namespace std;

struct stack
{
	char *top, *base;
	int size;
};

void sc_init(stack *p)
{
	p->base = p->top = new char[STACK_INIT_SIZE];
	p->size = STACK_INIT_SIZE;
}

void sc_push(stack *p, char c)
{
	if (p->top - p->base == p->size - 1)
	{
		char *p1,*p2,*p3;
		p2 = p1 = new char[p->size + STACKINCREMENT];
		p3 = p->base;
		while (p3 <= p->top)
		{
			*p2 = *p3;
			p3++;
			p2++;
		}
		delete p->base;
		p->top = --p2;
		p->base = p1;
		p->size += STACKINCREMENT;
	}

	*(++p->top) = c;
}

int sc_pop(stack *p, char &c)
{
	if (p->top == p->base)
		return 0;

	c = *p->top;
	p->top--;
	return 1;
}

void bin2dec(stack *p,stack *result)
{
	int dec,i;
	char c = 0;
	dec = 0;
	i = 0;

	while (sc_pop(p, c))
	{
		dec += (c - '0')*pow(2, i++);
	}

	while (dec)
	{
		sc_push(result, dec % 10);
		dec /= 10;
	}
	return ;
}

void bin2oct(stack *p,stack *result)
{
	int dec, i;
	char c = 0;
	dec = 0;
	i = 0;

	while (sc_pop(p, c))
	{
		dec += (c - '0')*pow(2, i++%3);
		if (i == 3)
		{
			sc_push(result, dec);
			dec = 0;
		}
	}
	if (dec)
	{
		sc_push(result, dec);
	}

	return ;
}

void bin2hex(stack *p,stack *result)
{
	int dec, i;
	char c = 0;
	dec = 0;
	i = 0;

	while (sc_pop(p, c))
	{
		dec += (c - '0')*pow(2, i++ % 4);
		if (i == 4)
		{
			sc_push(result, dec);
			dec = 0;
		}
	}
	if (dec)
	{
		sc_push(result, dec);
	}

	return;
}

int main()
{
	stack *st = new stack;
	stack *stresult = new stack;
	char c,d;
	sc_init(st);
	cout << "请输入二进制数以#结束：" << endl;
	cin >> c;
	while (c != '#')
	{
		sc_push(st, c);
		cin >> c;
	}

	sc_init(stresult);

	//bin2dec(st, stresult);  //转换为10进制
	//bin2oct(st, stresult);  //转换为8进制
	bin2hex(st, stresult);  //转换为16进制

	cout << "转换结果：" << endl;
	while (sc_pop(stresult, c))
	{
		if (c < 10)
			d = c + '0';
		else
			d = (c - 10) + 'A';
		cout << d;
	}
		

	system("pause");
	return 0;
}