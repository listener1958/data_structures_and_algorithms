//��С��������Kruskal�㷨����³˹������
//̰�ķ���ÿ��ȡ��̱�,�жϲ�����ɻ�·��˱���Ч,����ȡ�˱�

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

void kruskal(int *G, int n)  //ͼ���ڽӾ��� ͼ������
{
	vector<edge> edges;
	int* point = new int[n];

	for (int i = 0; i < n; i++)    //��ʼ�������Ӧ����
		point[i] = i;

	for (int i = 0; i < n-1; i++)  //��ʼ���߼�����
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
			int temp = point[it->invert];   //��¼���޸ĵ㼯�����
			for (int i = 0; i < n; i++)
				if (point[i] == temp)
					point[i] = point[it->vert];
		}
	}
	

	cout << "��С�������߼����£�" << endl
		<< "��1\t" << "��2\t" << "�߳�" << endl;
	for (int i = 0; i < edges.size(); i++)
	{
		cout << edges[i].vert << '\t' << edges[i].invert << '\t' << edges[i].cost << endl;
	}

}
