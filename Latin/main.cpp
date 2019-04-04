#include<iostream>

using namespace std;

int main()
{
	int n;
	int i, j;

	cout << "请输入拉丁方阵的维度：";
	cin >> n;

	cout << endl
		<< "对应拉丁方阵为：" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << (i + j) % n + 1 << '\t';
		cout << endl;
	}
		

	system("pause");
	return 0;
}