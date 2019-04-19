//��������ð������ĸĽ�������ȷ��һ��׼Ԫ�أ�ͨ������Ԫ��ʹ�ý�С��λ�ڻ�׼��ߣ��ϴ��λ�ڻ�׼�ұߣ����εݹ�

void swap(int num[], int i, int j)
{
	int temp = num[i];
	num[i] = num[j];
	num[j] = temp;
}

void qSort_1(int num[], int n)
{
	if (n <= 1)
		return;

	int base = num[0];
	int left = 0, right = n - 1;  //���������ڱ�
	while (left < right)
	{
		while (num[right] >= base && left<right)
			right--;
		swap(num, left, right);    //ÿ�κ�base��¼������baseΪ��ʼ����ʱ��һ����
		while (num[left] <= base && left<right)
			left++;
		swap(num, left, right);    //ÿ�κ�base��¼������baseΪ��ʼ����ʱ��һ����
	}
	qSort_1(num, left);
	if (left + 1 < n)
		qSort_1(&num[left + 1], n - left - 1);
}

void quickSort_1(int num[], int n)
{
	qSort_1(num, n);
}

//�Ľ�1��ÿ��������Ҫ��ν������ݣ�ÿ�ζ������׼����������׼����һ�����ƶ���left==right��
//       �ʽ���׼�ݴ棬ÿ��ֻ�赥���ƶ����ݣ���󽫻�׼�ƶ���left==right������
void qSort_2(int num[], int low, int high)
{
	if (low < high)
	{
		int base = num[low];
		int left = low, right = high;
		while (left < right)
		{
			while (num[right] >= base && left < right)
				right--;
			num[left] = num[right];    //ÿ�κ�base��¼������baseΪ��ʼ����ʱ��һ����
			while (num[left] <= base && left < right)
				left++;
			num[right] = num[left];   //ÿ�κ�base��¼������baseΪ��ʼ����ʱ��һ����
		}
		num[left] = base;  //����׼ֵ�ƶ����м�
		qSort_2(num, low, left - 1);
		qSort_2(num, left + 1, high);
	}
}

void quickSort_2(int num[], int n)
{
	qSort_2(num, 0, n-1);
}

//�Ľ�2��ÿ��ȡ��λԪ��Ϊ��׼�㣬����λԪ��Ϊ��С��������ܴﵽ���ֵ�Ч�����ɽ���׼��ȡΪ��βԪ�����м�Ԫ�����ߵ���λ��
void qSort_3(int num[], int low, int high)
{
	if (low < high)
	{
		if (num[low] > num[high])
			swap(num, low, high);
		if (num[(low + high) / 2] > num[high])
			swap(num, (low + high) / 2, high);
		if (num[(low + high) / 2] > num[low])
			swap(num, low, (low + high) / 2);
		int base = num[low];
		int left = low, right = high;
		while (left < right)
		{
			while (num[right] >= base && left < right)
				right--;
			num[left] = num[right];    //ÿ�κ�base��¼������baseΪ��ʼ����ʱ��һ����
			while (num[left] <= base && left < right)
				left++;
			num[right] = num[left];   //ÿ�κ�base��¼������baseΪ��ʼ����ʱ��һ����
		}
		num[left] = base;  //����׼ֵ�ƶ����м�
		qSort_3(num, low, left - 1);
		qSort_3(num, left + 1, high);
	}
}

void quickSort_3(int num[], int n)
{
	qSort_3(num, 0, n - 1);
}

//�Ľ�3���ڻ�׼�㻥�����������Ӷ��������Ƿ�������жϣ������������������򡣷�����ÿ��left++��right--ʱ�������ݲ�������һ��ѭ���ƶ���û�н������ݲ�����˵����������
void qSort_4(int num[], int low, int high)
{
	if (low < high)
	{
		if (num[low] > num[high])
			swap(num, low, high);
		if (num[(low+high) / 2] > num[high])
			swap(num, (low + high) / 2, high);
		if (num[(low + high) / 2] > num[low])
			swap(num, low, (low + high) / 2);
		int base = num[low];
		int left = low, right = high;
		bool l = false, r = false;
		while (left < right)
		{
			while (num[right] >= base && left < right)
			{
				right--;
				if (right+2<=high && num[right+1] > num[right+2])
					swap(num, right+1, right+2), r = true;  //�������ݲ���,���ڵ�right�����ܱ��滻���ʽ����ѱȽ��滻��Ԫ�ؽ��в���
			}
			num[left] = num[right];    //ÿ�κ�base��¼������baseΪ��ʼ����ʱ��һ����
			while (num[left] <= base && left < right)
			{
				left++;
				if (left-2>=low && num[left-1] < num[left-2])
					swap(num, left-1, left-2), l = true;  //�������ݲ���,���ڵ�left�����ܱ��滻���ʽ����ѱȽ��滻��Ԫ�ؽ��в���
			}
			num[right] = num[left];   //ÿ�κ�base��¼������baseΪ��ʼ����ʱ��һ����
		}
		num[left] = base;  //����׼ֵ�ƶ����м�
		if (l)   //�����ݲ��������ܱ�֤����������
			qSort_4(num, low, left - 1);
		if (r)   //�����ݲ��������ܱ�֤����������
			qSort_4(num, left + 1, high);
	}
}

void quickSort_4(int num[], int n)
{
	qSort_4(num, 0, n - 1);
}