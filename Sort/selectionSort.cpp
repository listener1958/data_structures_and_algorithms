//ѡ���������δ�����������ѡ����С��������2С������������������λ����һλ������

void selecSort(int num[], int n)
{
	int temp, k;
	for (int i = 0; i < n; i++)
	{
		k = i;
		for (int j = i; j < n; j++)
			if (num[k] > num[j])
				k = j;
		temp = num[k];
		num[k] = num[i];
		num[i] = temp;
	}
		
}