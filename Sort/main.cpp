#include <iostream>

using namespace std;

void bubbSort(int num[], int n);
void selecSort(int num[], int n);
void insertSort(int num[], int n);
void heapSort(int num[], int n);
void shellSort(int num[], int n);
void mergeSort_1(int num[], int n);  //�ݹ�ʵ��
void mergeSort_2(int num[], int n);  //����ʵ��
void quickSort_1(int num[], int n);  //��������
void quickSort_2(int num[], int n);  //�Ľ�1
void quickSort_3(int num[], int n);  //�Ľ�2
void quickSort_4(int num[], int n);  //�Ľ�3
int main()
{
	int num[10] = { 3,2,6,9,5,1,7,8,4,0 };

	quickSort_4(num, 10);

	for (int i = 0; i < 10; i++)
		cout << num[i];
	cout << endl;
	return 0;
}