#include <iostream>
#include "kmpstr.h"

using namespace std;

int main()
{
	char* str1 = "abaaabaaaaegedf";
	char* str2 = "abaaaa";
	kmpstr s2(str2, 6);

	int i = s2.kmp(str1, 15);

	cout << "�ַ���\"" << str1 << "\"���ַ���\"" << str2 << "\"ƥ����Ϊ��" << endl
		<< i << endl;

	system("pause");
	return 0;
}