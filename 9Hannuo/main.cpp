//求解汉诺塔问题，将n个圆盘从x轴，借助y轴，移动到z轴

#include<iostream>

using namespace std;

void move(int n, char x, char y, char z)
{
	if (n == 1)
	{
		cout << x << "-->" << z << endl;
	}
	else
	{
		move(n - 1, x, z, y);
		cout << x << "-->" << z << endl;
		move(n - 1, y, x, z);
	}
}

int main()
{
	int n;

	cout << "请输入汉诺塔长度：";
	cin >> n;

	move(n, 'x', 'y', 'z');


	system("pause");
	return 0;
}