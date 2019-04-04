#include<iostream>
#include"linkedTable.h"

using namespace std;

int search(int a[], int x, int left, int right);


int main()
{
	//int a[] = { 5,8,12,21,29,43,52,64,70,81,87,199 };
	//int b = search(a,199,0,11);
	//cout << "search result£º" << b << endl;
	
	//linkedTable* A = new linkedTable();
	linkedTable A;
	A.AddNode(1);
	A.AddNode(2);
	A.AddNode(3);
	A.AddNode(1);
	A.AddNode(2);
	cout << A << endl;



	system("pause");
}

int search(int a[],int x,int left,int right)
{
	int mid;
	int r;

	if (left > right)
		return -1;
	
	mid = (left + right) / 2;
	if (a[mid] > x)
		r = search(a, x, left, mid - 1);
	else if (a[mid] < x)
		r = search(a, x, mid + 1, right);
	else
		r = mid;

	return r;
}
