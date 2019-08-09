//���·�����⣬�Ͻ�˹�����㷨���ɵõ�����һ�㵽�������е������·��
#include <vector>
#include <iostream>
#include <string>

#define MAX INT16_MAX

typedef std::vector<std::vector<int>> arr2;
struct point {
	int dis;
	int path;
	bool flag;   //0����������  1��������
};
void dijstra(arr2 &G, int s)
{
	point *p;
	int disminp;  //�����м����
	int mintemp; //�����м����
	int st;  //������

	p = new point[G.size()];  //������·����ʼ��
	for (int i = 0; i < G.size(); i++)
	{
		p[i].dis = G[s][i];
		p[i].path = s;
		p[s].flag = false;
	}

	p[s].flag = true;  //���ԭ��Ϊ������
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
	p[st].flag = true;  //�����������
	for (int k = 0; k < G.size()-2; k++)
	{
		mintemp = MAX;
		for (int i = 0; i < G.size(); i++)   //�ɳڲ���
		{
			if (p[i].flag != true)   //��Է�������
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
		st = disminp;  //����������
		p[st].flag = true;
	}

	std::string path;
	std::cout << "��ʼ��Ϊ��" << s << "\n\n";
	std::cout << "�����������·�����£�" << "\n\n";
	for (int i = 0; i < G.size(); i++)
	{
		int j;
		std::cout << i << "�����룺" << p[i].dis << "\n";
		//path.clear();
		j = i;
		path = std::to_string(i);
		while (p[j].path != s)
		{
			path = std::to_string(p[j].path) + path;
			j = p[j].path;
		}
		path = std::to_string(p[j].path) + path;
		std::cout << "·����" << path << "\n\n";
	}

}

