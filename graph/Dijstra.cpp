//最短路径问题，迪杰斯特拉算法。可得到任意一点到其他所有点间的最短路径
#include <vector>
#include <iostream>
#include <string>

#define MAX INT16_MAX

typedef std::vector<std::vector<int>> arr2;
struct point {
	int dis;
	int path;
	bool flag;   //0：非生长点  1：生长点
};
void dijstra(arr2 &G, int s)
{
	point *p;
	int disminp;  //距离中间变量
	int mintemp; //距离中间变量
	int st;  //生长点

	p = new point[G.size()];  //距离与路径初始化
	for (int i = 0; i < G.size(); i++)
	{
		p[i].dis = G[s][i];
		p[i].path = s;
		p[s].flag = false;
	}

	p[s].flag = true;  //标记原点为生长点
	mintemp = MAX;
	for (int i = 0; i < G.size(); i++)
	{
		if (p[i].flag != true && p[i].dis < mintemp)
		{
			mintemp = p[i].dis;
			disminp = i;
		}
	}
	st = disminp;
	p[st].flag = true;  //标记新生长点
	for (int k = 0; k < G.size()-2; k++)
	{
		mintemp = MAX;
		for (int i = 0; i < G.size(); i++)   //松弛操作
		{
			if (p[i].flag != true)   //针对非生长点
			{
				if (G[st][i] != MAX && p[i].dis > p[st].dis + G[st][i])
				{
					p[i].dis = p[st].dis + G[st][i];
					p[i].path = st;
				}
				if (p[i].dis < mintemp)
				{
					mintemp = p[i].dis;
					disminp = i;
				}
			}
		}
		st = disminp;  //更新生长点
		p[st].flag = true;
	}

	std::string path;
	std::cout << "初始点为：" << s << "\n\n";
	std::cout << "到各点距离与路径如下：" << "\n\n";
	for (int i = 0; i < G.size(); i++)
	{
		int j;
		std::cout << i << "：距离：" << p[i].dis << "\n";
		//path.clear();
		j = i;
		path = std::to_string(i);
		while (p[j].path != s)
		{
			path = std::to_string(p[j].path) + path;
			j = p[j].path;
		}
		path = std::to_string(p[j].path) + path;
		std::cout << "路径：" << path << "\n\n";
	}

}

