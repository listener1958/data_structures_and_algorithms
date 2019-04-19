//快速排序：冒泡排序的改进，首先确定一基准元素，通过交换元素使得较小的位于基准左边，较大的位于基准右边，依次递归

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
	int left = 0, right = n - 1;  //定义左右哨兵
	while (left < right)
	{
		while (num[right] >= base && left<right)
			right--;
		swap(num, left, right);    //每次和base记录交换，base为开始排序时第一个点
		while (num[left] <= base && left<right)
			left++;
		swap(num, left, right);    //每次和base记录交换，base为开始排序时第一个点
	}
	qSort_1(num, left);
	if (left + 1 < n)
		qSort_1(&num[left + 1], n - left - 1);
}

void quickSort_1(int num[], int n)
{
	qSort_1(num, n);
}

//改进1：每次排序都需要多次交换数据，每次都是与基准交换，而基准最终一定会移动至left==right处
//       故将基准暂存，每次只需单向移动数据，最后将基准移动至left==right处即可
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
			num[left] = num[right];    //每次和base记录交换，base为开始排序时第一个点
			while (num[left] <= base && left < right)
				left++;
			num[right] = num[left];   //每次和base记录交换，base为开始排序时第一个点
		}
		num[left] = base;  //将基准值移动至中间
		qSort_2(num, low, left - 1);
		qSort_2(num, left + 1, high);
	}
}

void quickSort_2(int num[], int n)
{
	qSort_2(num, 0, n-1);
}

//改进2：每次取首位元素为基准点，若首位元素为最小或最大，则不能达到二分的效果。可将基准点取为首尾元素与中间元素三者的中位数
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
			num[left] = num[right];    //每次和base记录交换，base为开始排序时第一个点
			while (num[left] <= base && left < right)
				left++;
			num[right] = num[left];   //每次和base记录交换，base为开始排序时第一个点
		}
		num[left] = base;  //将基准值移动至中间
		qSort_3(num, low, left - 1);
		qSort_3(num, left + 1, high);
	}
}

void quickSort_3(int num[], int n)
{
	qSort_3(num, 0, n - 1);
}

//改进3：在基准点互换过程中增加对子序列是否有序的判断，若已有序则不需再排序。方法，每次left++或right--时增加起泡操作，若一次循环移动中没有进行起泡操作，说明已是有序
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
					swap(num, right+1, right+2), r = true;  //增加起泡操作,由于第right个可能被替换，故仅对已比较替换的元素进行操作
			}
			num[left] = num[right];    //每次和base记录交换，base为开始排序时第一个点
			while (num[left] <= base && left < right)
			{
				left++;
				if (left-2>=low && num[left-1] < num[left-2])
					swap(num, left-1, left-2), l = true;  //增加起泡操作,由于第left个可能被替换，故仅对已比较替换的元素进行操作
			}
			num[right] = num[left];   //每次和base记录交换，base为开始排序时第一个点
		}
		num[left] = base;  //将基准值移动至中间
		if (l)   //有起泡操作，不能保证有序，需排序
			qSort_4(num, low, left - 1);
		if (r)   //有起泡操作，不能保证有序，需排序
			qSort_4(num, left + 1, high);
	}
}

void quickSort_4(int num[], int n)
{
	qSort_4(num, 0, n - 1);
}