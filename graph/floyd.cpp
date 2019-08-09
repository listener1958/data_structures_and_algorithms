//���·�����⣬���������㷨���ɵõ��������������·��
#include <vector>
#include <iostream>

#define MAX INT16_MAX

typedef std::vector<std::vector<int>> arr2;

void floyd(arr2 &G)
{
	arr2 P, D;  //DΪ����� PΪ�ڵ��

	D = G;  //������ʼ��
	P.resize(G.size());  //�ڵ���ʼ��
	for (int i = 0; i < D.size(); i++)
	{
		P[i].resize(G.size());
		for (int j = 0; j < D.size(); j++)
			P[i][j] = i;
	}
	
	for (int k = 0; k < D.size(); k++)
	{
		for (int i = 0; i < D.size(); i++)
		{
			for (int j = 0; j < D.size(); j++)
			{
				//�Ƚ�Ŀǰ�ľ��뵽�;���k����ת�ĸ�����С
				if (D[i][k] != MAX && D[k][j] != MAX &&
					D[i][j] > D[i][k] + D[k][j])
				{
					D[i][j] = D[i][k] + D[k][j];
					P[i][j] = k;
				}
			}
		}
	}
	
	for (int i = 0; i < D.size(); i++)
	{
		for (int j = 0; j < D.size(); j++)
		{
			std::cout << P[i][j]+1 << '\t';
		}
		std::cout << '\n';
	}
	std::cout << "\n\n";
	for (int i = 0; i < D.size(); i++)
	{
		for (int j = 0; j < D.size(); j++)
		{
			std::cout << D[i][j] << '\t';
		}
		std::cout << '\n';
	}


}
