//��⺺ŵ�����⣬��n��Բ�̴�x�ᣬ����y�ᣬ�ƶ���z��

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

	cout << "�����뺺ŵ�����ȣ�";
	cin >> n;

	move(n, 'x', 'y', 'z');


	system("pause");
	return 0;
}