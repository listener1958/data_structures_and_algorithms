//��ͨ���������������
//����������
//


#include <iostream>
#include <string>
#include "BiThrTree.h"

using namespace std;

int main()
{
	string str;

	cout << "�����������˳���������������Ҷ��Ӵ��ո������";
	getline(cin, str);
	//str.c_
	char *s1 = new char[str.length() + 1];
	char *s2 = s1;
	for(auto s:str)
	{
		*s2 = s;
		s2++;
	}
	*s2 = '\0';
	BiThrTree BTTree(s1);
	BTTree.inorderTraversal();
	cout << endl;
	system("pause");
	return 0;
}