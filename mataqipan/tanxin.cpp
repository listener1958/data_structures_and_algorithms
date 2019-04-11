//马踏棋盘算法。
//国际象棋的棋盘为8 * 8的方格棋盘，现将“马”放在任意指定的方格中，按照“马”走棋的规则将“马”进行移动。
//要求每个方格只能进入一次，最终使得“马”走遍棋盘64个方格。
//解题思路：利用图的深度搜索遍历棋盘每一个格，若不能按“马”的跳转方式获取下一格，则回溯。
//每一节点至多有8个子节点，故复杂度为8^64

//算法改进：定义子棋盘，记录每个节点当前可行的子节点，每次取下一节点从子节点较少的开始取（贪心法，每次取子节点较少，可使得最终遍历次数减少）


#include <iostream>
#define MAX 255
using namespace std;

#define X2 8   //棋盘x方向大小
#define Y2 8   //棋盘y方向大小

int chess2[X2][Y2];
int nextconut[X2][Y2];  //贪心法算法优化

int traverseChessTanxin(int x, int y, int tag);
void nextcUpdate();  //初始化数组nextconut   贪心法算法优化
void initchess();

void initchess()
{
	for (int i = 0; i < X2; i++)
	{
		for (int j = 0; j < Y2; j++)
			chess2[i][j] = 0;
	}
}
int valid2(int x, int y)  //判断节点是否有效
{
	if (x<0 || y<0 || x >= X2 || y >= Y2)
		return 0;
	if (chess2[x][y] != 0)
		return 0;

	return 1;
}
void nextcUpdate()  //初始化数组nextconut   贪心法算法优化
{
	for (int i = 0; i < X2; i++)
	{
		for (int j = 0; j < Y2; j++)
		{
			nextconut[i][j] = 0;
			if (valid2(i + 1, j - 2))
				nextconut[i][j]++;
			if (valid2(i + 2, j - 1))
				nextconut[i][j]++;
			if (valid2(i + 2, j + 1))
				nextconut[i][j]++;
			if (valid2(i + 1, j + 2))
				nextconut[i][j]++;
			if (valid2(i - 1, j + 2))
				nextconut[i][j]++;
			if (valid2(i - 2, j + 1))
				nextconut[i][j]++;
			if (valid2(i - 2, j - 1))
				nextconut[i][j]++;
			if (valid2(i - 1, j - 2))
				nextconut[i][j]++;
		}
	}
}
int getNext(int x, int y, int next[][2])   //按照count获取指定位置下一节点
{
	int c[8] = { -1,-1,-1,-1,-1,-1,-1,-1 };
	int min = INT16_MAX;
	int min_x;  //可走节点最少的节点

	if (valid2(x + 1, y - 2))  //点1
		c[0] = nextconut[x + 1][y - 2];
	if (valid2(x + 2, y - 1))  //点2
		c[1] = nextconut[x + 2][y - 1];
	if (valid2(x + 2, y + 1))  //点3
		c[2] = nextconut[x + 2][y + 1];
	if (valid2(x + 1, y + 2))  //点4
		c[3] = nextconut[x + 1][y + 2];
	if (valid2(x - 1, y + 2))  //点5
		c[4] = nextconut[x - 1][y + 2];
	if (valid2(x - 2, y + 1))  //点6
		c[5] = nextconut[x - 2][y + 1];
	if (valid2(x - 2, y - 1))  //点7
		c[6] = nextconut[x - 2][y - 1];
	if (valid2(x - 1, y - 2))  //点8
		c[7] = nextconut[x - 1][y - 2];

	for (int i = 0; i < nextconut[x][y]; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (c[j] != -1)
			{
				if (c[j] < min)
				{
					min = c[j];
					min_x = j;
					c[j] = -1;
				}
			}
		}
		switch (min_x+1)
		{
		case 1:
			next[i][0] = x + 1;
			next[i][1] = y - 2;
			break;
		case 2:
			next[i][0] = x + 2;
			next[i][1] = y - 1;
			break;
		case 3:
			next[i][0] = x + 2;
			next[i][1] = y + 1;
			break;
		case 4:
			next[i][0] = x + 1;
			next[i][1] = y + 2;
			break;
		case 5:
			next[i][0] = x - 1;
			next[i][1] = y + 2;
			break;
		case 6:
			next[i][0] = x - 2;
			next[i][1] = y + 1;
			break;
		case 7:
			next[i][0] = x - 2;
			next[i][1] = y - 1;
			break;
		case 8:
			next[i][0] = x - 1;
			next[i][1] = y - 2;
			break;
		}
	}

	return 1;
}
int traverseChessTanxin(int x, int y, int tag)
{
	chess2[x][y] = tag;
	if (tag == X2*Y2)
	{
		cout << "遍历结束。" << endl;
		for (int i = 0; i < X2; i++)
		{
			for (int j = 0; j < Y2; j++)
			{
				cout << chess2[i][j] << '\t';
			}
			cout << endl;
		}
		return 1;
	}

	nextcUpdate();
	int next[8][2];    //存储下一节点,最多有8个
	int cMax = nextconut[x][y];  //存储当前可访问下一节点数量
	getNext(x, y, next);
	
	int count = 0;
	int result = 0;
	int xx, yy;
	while (result == 0 && count < cMax)
	{
		xx = next[count][0], yy = next[count][1];
		
		result = traverseChessTanxin(xx, yy, tag + 1);

		if (!result)
			count++;
	}
	if (count == cMax)
	{
		chess2[x][y] = 0;
		return 0;
	}

	return 1;
}
