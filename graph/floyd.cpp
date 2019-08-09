//最短路径问题，弗洛伊德算法。可得到任意两点间的最短路径
#include <vector>
#include <iostream>

#define MAX INT16_MAX

typedef std::vector<std::vector<int>> arr2;

void floyd(arr2 &G)
{
	arr2 P, D;  //D为距离表 P为节点表

	D = G;  //距离表初始化
	P.resize(G.size());  //节点表初始化
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
				//比较目前的距离到和经过k点中转哪个距离小
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
