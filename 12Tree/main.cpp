//普通二叉树建立与遍历
//线索二叉树
//


#include <iostream>
#include <string>
#include "BiThrTree.h"

using namespace std;

int main()
{
	string str;

	cout << "请以中序遍历顺序输入树，无左右儿子处空格替代：";
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