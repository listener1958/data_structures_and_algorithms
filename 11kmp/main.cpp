#include <iostream>
#include "kmpstr.h"

using namespace std;

int main()
{
	char* str1 = "abaaabaaaaegedf";
	char* str2 = "abaaaa";
	kmpstr s2(str2, 6);

	int i = s2.kmp(str1, 15);

	cout << "×Ö·û´®\"" << str1 << "\"Óë×Ö·û´®\"" << str2 << "\"Æ¥Åä½á¹ûÎª£º" << endl
		<< i << endl;

	system("pause");
	return 0;
}