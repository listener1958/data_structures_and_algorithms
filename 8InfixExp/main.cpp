#include<iostream>
#include "stack_s.h"
//#include "stack_s.cpp"

#define NUMSIZE 10

using namespace std;

//const char operatorT[]={}

int priorityCal(char c)
{
	switch (c)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '^':
		return 3;
	default:
		return 0;
	}
}

int trypush(stack_c &st, char opera)
{
	char c;
	if (st.pop(c))
	{
		if (opera == ')')
		{
			if (c == '(')
				return 1;
			else
			{
				st.push(c);
				return 0;
			}	
		}
		if (opera == '(')
		{
			st.push(c);
			st.push(opera);
			return 1;
		}
		if (priorityCal(opera) <= priorityCal(c))
		{
			st.push(c);
			return 0;
		}
		else
		{
			st.push(c);
			st.push(opera);
			return 1;
		}
	}

	st.push(opera);
	return 1;
}

int expcal(double& d1, double& d2, char c)
{
	switch (c)
	{
	case '+':
		d1 = d1 + d2;
		break;
	case '-':
		d1 = d1 - d2;
		break;
	case '*':
		d1 = d1 * d2;
		break;
	case '/':
		d1 = d1 / d2;
		break;
	case '^':
		d1 = pow(d1, d2);
		break;
	default:
		return 0;
	}

	return 1;
}

int main()
{
	stack_d sNum;
	stack_c sOperator;
	

	cout << "请输入中缀表达式，支持加减乘除乘方括号浮点数计算，数字与运算符以空格隔开，表达式以#结束！" << endl;

	char c, c1;  //c输入字符接收，c1计算用运算符
	char str[NUMSIZE];
	int i = 0;
	double d1, d2; //计算用中间变量
	d1 = d2 = 0;

	cin >> c;
	while (c != '#')
	{
		if (isdigit(c))
		{
			if (i >= NUMSIZE - 1)
			{
				cout << "数字位数过多！" << endl;
				system("pause");
				return 0;
			}
			str[i++] = c;
			str[i] = '\0';

		}
		else if (c == '.')
		{
			if (i >= NUMSIZE - 1)
			{
				cout << "数字位数过多！" << endl;
				system("pause");
				return 0;
			}
			if (i == 0)
			{
				cout << "数字输入有误！" << endl;
				system("pause");
				return 0;
			}
			str[i++] = c;
			str[i] = '\0';
		}
		else if (c == ' ')
		{
			if (i != 0)
			{
				d1 = atof(str);
				sNum.push(d1);
				i = 0;
			}
		}
		else
		{
			while (!trypush(sOperator, c))
			{
				if (sOperator.pop(c1) && sNum.pop(d2) && sNum.pop(d1))
				{
					if (expcal(d1, d2, c1))
					{
						sNum.push(d1);
					}
				}
				else
				{
					cout << "运算出错！" << endl;
					system("pause");
					return 0;
				}
			}
			/*switch (c)
			{
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
			case ')':

			default:
				cout << "输入错误！" << endl;
				system("pause");
				return 0;
				break;

			}*/
		}
		cin.get(c);
	}

	while (sOperator.pop(c1) && sNum.pop(d2) && sNum.pop(d1))
	{
		if (expcal(d1, d2, c1))
		{
			sNum.push(d1);
		}
	}
	if (!sOperator.pop(c1) && sNum.pop(d1) && !sNum.pop(d2))
	{
		cout << "运算结果：" << d1 << endl;
	}
	else
	{
		cout << "运算出错！" << endl;
		system("pause");
		return 0;
	}

	/*if (sc_pop(st, d) && !sc_pop(st, d1))
	{
		cout << "运算结果：" << d << endl;
	}
	else
	{
		cout << "运算出错！" << endl;
	}*/

	system("pause");
	return 0;
}