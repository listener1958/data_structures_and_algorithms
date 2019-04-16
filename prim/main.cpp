//最小生成树，prim算法（普利姆）
//贪心法，每次取待选边集最短边，重新确定生长点，更新待选边集

#include <iostream>

#define MAX INT16_MAX

using namespace std;

void prim(int *G, int n);
int main()
{
	int graph[5][5] = {
		{ MAX,  1,  2,MAX,MAX},
		{   1,MAX,MAX,  2,  5 },
		{   2,MAX,MAX,  3,MAX },
		{ MAX,  2,  3,MAX,  1 },
		{ MAX,  5,MAX,  1,MAX }
	};
	
	prim((int*)graph, 5);

	return 0;
}

struct edge {
	int vert, invert;
	int cost;
};

int getpoint(int *G,int n, int i, int j)
{
	return *(G + i*n + j);
}

void prim(int *G, int n)  //图的邻接矩阵 图定点数
{
	edge edgetemp, *wait;
	wait = new edge[n - 1];

	for (int i = 0; i < n-1; i++)  //初始化边集数组
	{
		wait[i].vert = 0;    //初始生长点为0
		wait[i].invert = i+1;   //初始待生长点
		wait[i].cost = getpoint(G, n, 0, i+1);    //G[k][i] 初始边长，若边不存在边长为∞
	}

	int costtemp;
	int e;
	for (int i = 0; i < n-2; i++)  //遍历边集数组，每次更新边集最短边，最后一条边无需修改
	{
		costtemp = wait[i].cost;
		e = i;
		for (int j = i; j < n - 1; j++)  //遍历边集数组，取最小边长对应非生长点作为新生长点
		{
			if (costtemp > wait[j].cost)
			{
				costtemp = wait[j].cost;
				e = j;
			}
		}
		edgetemp = wait[i];
		wait[i] = wait[e];
		wait[e] = edgetemp;

		for (int j = i+1; j < n - 1; j++)  //遍历边集数组，更新边集最短边长
		{
			if (wait[j].cost > getpoint(G, n, wait[i].invert, wait[j].invert))    //更新生长点边长
			{
				wait[j].cost = getpoint(G, n, wait[i].invert, wait[j].invert);
				wait[j].vert = wait[i].invert;
			}
		}
	}

	cout << "最小生成树边集如下：" << endl 
		<<"点1\t"<<"点2\t"<<"边长"<< endl;
	for (int i = 0; i < n - 1; i++)
	{
		cout << wait[i].vert << '\t' << wait[i].invert << '\t' << wait[i].cost << endl;
	}

}
