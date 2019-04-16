//最小生成树，Kruskal算法（克鲁斯卡尔）
//贪心法，每次取最短边,判断不会组成回路则此边有效,否则不取此边

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX INT16_MAX

using namespace std;

void kruskal(int *G, int n);
int main()
{
	int graph[5][5] = {
		{ MAX,  1,  2,MAX,MAX },
		{ 1,MAX,MAX,  2,  5 },
		{ 2,MAX,MAX,  3,MAX },
		{ MAX,  2,  3,MAX,  1 },
		{ MAX,  5,MAX,  1,MAX }
	};

	kruskal((int*)graph, 5);

	return 0;
}

struct edge {
	int vert, invert;
	int cost;
};

int getpoint(int *G, int n, int i, int j)
{
	return *(G + i*n + j);
}

void kruskal(int *G, int n)  //图的邻接矩阵 图定点数
{
	vector<edge> edges;
	int* point = new int[n];

	for (int i = 0; i < n; i++)    //初始化各点对应分组
		point[i] = i;

	for (int i = 0; i < n-1; i++)  //初始化边集数组
	{
		for (int j = i+1; j < n; j++)
		{
			if (getpoint(G, n, i, j) < MAX)
			{
				edges.push_back({ i,j,getpoint(G, n, i, j) });
			}
		}
	}

	sort(edges.begin(), edges.end(), [](edge e1, edge e2) {return e1.cost < e2.cost; });

	for (auto it = edges.begin(); it != edges.end(); it++)
	{
		if (point[it->vert] == point[it->invert])
			it->cost = -1;
		else
		{
			int temp = point[it->invert];   //记录需修改点集的序号
			for (int i = 0; i < n; i++)
				if (point[i] == temp)
					point[i] = point[it->vert];
		}
	}
	

	cout << "最小生成树边集如下：" << endl
		<< "点1\t" << "点2\t" << "边长" << endl;
	for (int i = 0; i < edges.size(); i++)
	{
		cout << edges[i].vert << '\t' << edges[i].invert << '\t' << edges[i].cost << endl;
	}

}
