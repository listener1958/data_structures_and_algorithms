#include<iostream>

using namespace std;

int main()
{
	int n;
	int i, j;

	cout << "���������������ά�ȣ�";
	cin >> n;

	cout << endl
		<< "��Ӧ��������Ϊ��" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << (i + j) % n + 1 << '\t';
		cout << endl;
	}
		

	system("pause");
	return 0;
}