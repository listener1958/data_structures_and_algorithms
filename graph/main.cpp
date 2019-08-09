#include <iostream>
#include <vector>

#define MAX INT16_MAX

using namespace std;

typedef vector<vector<int>> arr2;

void floyd(arr2 &G);
void dijstra(arr2 &G, int s);
int main()
{
	arr2 graph = {
		{ 0,    1,  2,MAX,MAX },
		{ 1,    0,MAX,  2,  5 },
		{ 2,  MAX,  0,  3,MAX },
		{ MAX,  2,  3,  0,  1 },
		{ MAX,  5,MAX,  1,  0 }
	};

	//floyd(graph);
	dijstra(graph, 0);

	return 0;
}


