#include <iostream>

using namespace std;

void bubbSort(int num[], int n);
void selecSort(int num[], int n);
void insertSort(int num[], int n);
void heapSort(int num[], int n);
void shellSort(int num[], int n);
void mergeSort_1(int num[], int n);  //递归实现
void mergeSort_2(int num[], int n);  //迭代实现
void quickSort_1(int num[], int n);  //快速排序
void quickSort_2(int num[], int n);  //改进1
void quickSort_3(int num[], int n);  //改进2
void quickSort_4(int num[], int n);  //改进3
int main()
{
	int num[10] = { 3,2,6,9,5,1,7,8,4,0 };

	quickSort_4(num, 10);

	for (int i = 0; i < 10; i++)
		cout << num[i];
	cout << endl;
	return 0;
}