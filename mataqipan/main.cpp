//马踏棋盘算法。
//国际象棋的棋盘为8 * 8的方格棋盘，现将“马”放在任意指定的方格中，按照“马”走棋的规则将“马”进行移动。
//要求每个方格只能进入一次，最终使得“马”走遍棋盘64个方格。
//解题思路：利用图的深度搜索遍历棋盘每一个格，若不能按“马”的跳转方式获取下一格，则回溯。
//每一节点至多有8个子节点，故复杂度为8^64

//算法改进：定义子棋盘，记录每个节点当前可行的子节点，每次取下一节点从子节点较少的开始取（贪心法，每次取子节点较少，可使得最终遍历次数减少）
//本文件为原算法，改进算法见 tanxin.cpp


#include <iostream>

using namespace std;

#define X 5   //棋盘x方向大小
#define Y 5   //棋盘y方向大小

int chess[X][Y];

int traverseChess(int x, int y, int tag);
int traverseChessTanxin(int x, int y, int tag);   //贪心法算法优化
void nextcUpdate();  //初始化数组nextconut   贪心法算法优化
void initchess();  //初始化数组chess2   贪心法算法优化
int main()
{
	//暴力方法
	//for (int i = 0; i < X; i++)
	//{
	//	for (int j = 0; j < Y; j++)
	//		chess[i][j] = 0;
	//}
	//if (!traverseChess(0, 0, 1))
	//{
	//	cout << "Traverse Failed!" << endl;
	//}

	//贪心算法
	initchess();
	nextcUpdate();
	if (!traverseChessTanxin(1, 0, 1))
	{
		cout << "Traverse Failed!" << endl;
	}

	return 0;
}
int valid(int x, int y)  //判断节点是否有效
{
	if ( x<0 || y<0 || x>=X || y>=Y )
		return 0;
	if ( chess[x][y] != 0 )
		return 0;

	return 1;
}
int getNext(int& x, int& y,int count)   //按照count获取指定位置下一节点
{
	int xx = x;
	int yy = y;
	switch (count)
	{
	case 1:
		if (valid(xx + 1, yy - 2))
			x = xx + 1, y = yy - 2;
		break;
	case 2:
		if (valid(xx + 2, yy - 1))
			x = xx + 2, y = yy - 1;
		break;
	case 3:
		if (valid(xx + 2, yy + 1))
			x = xx + 2, y = yy + 1;
		break;
	case 4:
		if (valid(xx + 1, yy + 2))
			x = xx + 1, y = yy + 2;
		break;
	case 5:
		if (valid(xx - 1, yy + 2))
			x = xx - 1, y = yy + 2;
		break;
	case 6:
		if (valid(xx - 2, yy + 1))
			x = xx - 2, y = yy + 1;
		break;
	case 7:
		if (valid(xx - 2, yy - 1))
			x = xx - 2, y = yy - 1;
		break;
	case 8:
		if (valid(xx - 1, yy - 2))
			x = xx - 1, y = yy - 2;
		break;
	}

	if (x == xx || y == yy)
		return 0;

	return 1;
}
int traverseChess(int x, int y, int tag)
{
	chess[x][y] = tag;

	if (tag == X*Y)
	{
		cout << "遍历结束。" << endl;
		for (int i = 0; i < X; i++)
		{
			for (int j = 0; j < Y; j++)
			{
				cout << chess[i][j] << '\t';
			}
			cout << endl;
		}	
		return 1;
	}
	int count = 1;
	int result = 0;
	int xx = x, yy = y;
	while (result == 0 && count <= 8)
	{
		xx = x, yy = y;
		if (getNext(xx, yy, count))
		{
			result = traverseChess(xx, yy, tag + 1);
		}
		if (!result)
			count++;
	}
	if (count == 9)
	{
		chess[x][y] = 0;
		return 0;
	}
		
	return 1;
}
