//��С��������prim�㷨������ķ��
//̰�ķ���ÿ��ȡ��ѡ�߼���̱ߣ�����ȷ�������㣬���´�ѡ�߼�

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

void prim(int *G, int n)  //ͼ���ڽӾ��� ͼ������
{
	edge edgetemp, *wait;
	wait = new edge[n - 1];

	for (int i = 0; i < n-1; i++)  //��ʼ���߼�����
	{
		wait[i].vert = 0;    //��ʼ������Ϊ0
		wait[i].invert = i+1;   //��ʼ��������
		wait[i].cost = getpoint(G, n, 0, i+1);    //G[k][i] ��ʼ�߳������߲����ڱ߳�Ϊ��
	}

	int costtemp;
	int e;
	for (int i = 0; i < n-2; i++)  //�����߼����飬ÿ�θ��±߼���̱ߣ����һ���������޸�
	{
		costtemp = wait[i].cost;
		e = i;
		for (int j = i; j < n - 1; j++)  //�����߼����飬ȡ��С�߳���Ӧ����������Ϊ��������
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

		for (int j = i+1; j < n - 1; j++)  //�����߼����飬���±߼���̱߳�
		{
			if (wait[j].cost > getpoint(G, n, wait[i].invert, wait[j].invert))    //����������߳�
			{
				wait[j].cost = getpoint(G, n, wait[i].invert, wait[j].invert);
				wait[j].vert = wait[i].invert;
			}
		}
	}

	cout << "��С�������߼����£�" << endl 
		<<"��1\t"<<"��2\t"<<"�߳�"<< endl;
	for (int i = 0; i < n - 1; i++)
	{
		cout << wait[i].vert << '\t' << wait[i].invert << '\t' << wait[i].cost << endl;
	}

}
