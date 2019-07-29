#include<stdio.h>
#include<stdlib.h>
#include"Stack.h"//此处调用了之前写的栈


void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void Print(int* a, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", a[i]);
	printf("\n");
}

//void InsertSort(int* a,int size)
//{
//	for (int i = 1; i < size; i++)
//	{
//		/*int j = i - 1;
//		int temp = a[j + 1];
//
//
//		for (; j >= 0;j--)
//		{
//			if (a[j] > temp)
//				a[j + 1] = a[j];
//			else
//				break;
//
//		}
//		a[j+1] = temp;*/
//		int end = i;
//		int temp = a[end];
//		while (end--)//此处end--，end = 1，然后加入循环，这句话结束，end = 1-1等于0，然后0进入end--，不满足，end在执行一次end--，end最后等于-1
//		{
//			if (a[end] > temp)
//				a[end+1] = a[end];
//			else
//				break;
//		}
//		a[end+1] = temp;
//	}
//	
//}
//
////void ShellSort(int* a,int size)
////{
////	for (int gap = size / 2; gap > 0; gap /= 2)
////	{
////		for (int i = 0; i < size - gap; ++i)
////		{
////			int end = i;
////			int temp = a[end + gap];
////			while (end >= 0)
////			{
////				if (temp < a[end])
////				{
////					a[end + temp] = a[end];
////					end -= gap;
////				}
////				else
////					break;
////			}
////			a[end + gap] = temp;
////		}
////	}
////
////
////}
//
//void ShellSort(int* a, int size)
//{
//	for (int gap = size / 2; gap > 0; gap = gap/2)//在用6的时候，gap为2，运行一次gap为2的情况，就可以完成排序
//
//	{
//		for (int i = 0; i < size - gap; ++i)
//		{
//			int end = i;
//			int temp = a[end + gap];
//			while (end >= 0)
//			{
//				if (temp < a[end])
//				{
//					a[end + gap] = a[end];
//					end = end - gap;
//				}
//				else
//				{
//					break;
//				}
//
//			}
//			a[end+gap] = temp;
//		}
//	}
//
//
//
//}
//void SlectSort(int* a, int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = i; j < size; j++)
//		{
//			if (a[i]>a[j])
//			Swap(&a[i], &a[j]);
//		}
//	}
//}
//
//void  BubbleSort(int* a, int size)//每次找到一个最大的数放在最后边，然后继续比较
//{
//	for (int i = 0; i < size-1; i++)
//	{
//		for (int j = 0; j < size-i-1; j++)
//		{
//			if (a[j] > a[j+1])
//				Swap(&a[j], &a[j+1]);
//
//		}
//	}
//}
//

void InsertSort(int* a, int size)
{

	for (int i = 1; i < size; i++)
	{
		int end = i;
		int temp = a[end];

		while (end--)
		{
			if (a[end] > temp)
				a[end + 1] = a[end];
			else
				break;
		}
		a[end + 1] = temp;
	}
}

void ShellSort(int* a, int size)
{
	int gap = size;

	while (gap > 1)
	{
		gap = gap / 3+1;//此处应该加1，防止这种特例10/4 = 2,下次直接跳出循环，gap没有循环到1，导致结果出错，但是也可以将gap = gap/2，但是/3感觉效率更高一点
		for (int i = 0; i < size - gap; ++i)
		{
			int end = i;
			int temp = a[end + gap];
			while (end >= 0)
			{
				if (temp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
					break;
			}
			a[end + gap] = temp;
		}
	}
}

void SlectSort(int* a, int size)
{
	/*int begin = 0;
	int end = size - 1;

	while (begin <= end)
	{
		int MinIndex = begin;
		int MaxIndex = begin;

		for (int i = begin+1; i <= end;++i)
		{
			if (a[i] > a[MaxIndex])
				MaxIndex = i;
			if (a[i] < a[MinIndex])
				MinIndex = i;

		}
		Swap(&a[begin], &a[MaxIndex]);
		Swap(&a[end], &a[MinIndex]);


		++begin;
		--end;

	}*/
	int begin = 0;
	int end = size;
	while (begin < end)
	{
		int MinIndex = begin;

		for (int i = begin+1; i < size; ++i)//注意对i的控制，当选择一个数的时候，必须让i走到最后一个，所以要<size
		{
			if (a[i] < a[MinIndex])
				MinIndex = i;

		}
		Swap(&a[begin], &a[MinIndex]);
		++begin;
	}
}
void BubbleSort(int* a, int size)
{

	/*for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j <size - 1 - i; j++)
		{
			if (a[j]>a[j + 1])
				Swap(&a[j], &a[j + 1]);
		}
	}*/



	/*for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size-i-1; j++)
		    {
					if (a[j] > a[j+1])
						Swap(&a[j], &a[j+1]);
		     }
		}*/
	int end = size;
	while (end > 0)
	{
		//尤其注意对边界条件的控制
		for(int i = 1;i<end;i++)
		//for (int i = 0; i < end - 1; i++)
		{
			if (a[i-1]>a[i])
				Swap(&a[i-1], &a[i]);
			/*if (a[i]>a[i + 1])
				Swap(&a[i], &a[i + 1]);*/

		}
		--end;
	}
}

int GetMidIndex(int* a, int left, int right)
{
	int mid = left + (right - left) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
			return mid;
		else if (a[mid]>a[right])
			return right;
		else
			right;
	}
	else//left>mid
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[left] < a[right])
			return left;
		else
			return right;
	}
}
int partion1(int* a, int left, int right)//左右指针
{
	int mid = GetMidIndex(a, left, right);
	Swap(&a[right], &a[mid]);
	int key = a[right];
	int keyindex = right;

	while (left < right)
	{
		while (left<right && a[left] <= key)
			++left;

		while (left<right && a[right]>=key)//这块如果不加等于号，right就不会移动，这样循环就会出现严重的错误
			--right;

		Swap(&a[left], &a[right]);

		++left;
		--right;
	}
	--left;//这块如果不对left，得到的值就会不对，因为上述循环，对left最后进行了++，所以出来之后得--这样值才不会出错
	Swap(&a[left], &a[keyindex]);

	return left;
}

int Partion2(int* a, int left, int right)//挖坑法
{
	int key = a[right];
	while (left < right)
	{
		while (left < right && a[left] < key)
			++left;
		a[right] = a[left];

		while (left < right && a[right] > key)
			--right;
		a[left] = a[right];

		//与前后指针不同的是，此处少了left++和right--，因为此处是覆盖，而前者是交换。

		
	}
	a[left] = key;
	return left;

}

int partion3(int* a, int left, int right)
{
	int cur, prev;
	int key = a[right];
	prev = left - 1;
	cur = left;

	while (cur < right)
	{
		if (a[cur] < key && ++prev!=cur)//prev==cur不做交换，然后cur继续往前走
			Swap(&a[cur], &a[prev]);

		++cur;
	}
	++prev;
	Swap(&a[right], &a[prev]);

	return prev;
}


void Non_Recursion(int* a, int left, int right)
{
	Stack s;
	StackCreat(&s);
	StackPush(&s, left);
	StackPush(&s, right);

	while (!StackEmpty(&s))
	{
		int end = StackTop(&s);
		StackPop(&s);
		int begin = StackTop(&s);
		StackPop(&s);

		int keyindex = partion3(a, begin, end);

		if (end > keyindex + 1)
		{
			StackPush(&s, keyindex + 1);
			StackPush(&s, end);
		}
		if (begin < keyindex - 1)
		{
			StackPush(&s, begin);
			StackPush(&s, keyindex - 1);
		}
	}

}





void  Quicksort(int* a,int left,int right)
{
	if (left >= right)//这块的>符号，非常的必要。
		//因为当只有左右两个数值的时候，key=right，left+1 = 1,然后循环条件会right--,left++,虽然最PointerSort中最后会对left--,但是right = 0，left = 1，所以if语句中需要对这个情况进行判断
		return;


	int keyindex = partion3(a, left, right);

	Quicksort(a, left, keyindex - 1);
	Quicksort(a, keyindex + 1, right);

}


void _MergeSort(int* a, int left, int right,int* temp)
{
	if (left == right)
		return;

	int mid = left + (right - left) / 2;

	_MergeSort(a, left, mid, temp);
	_MergeSort(a, mid+1, right, temp);

	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = left;

	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			temp[i++] = a[begin1];
			++begin1;
		}
		else
		{
			temp[i++] = a[begin2];
			++begin2;
		}
	}

	while (begin1 <= end1)
	{
		temp[i++] = a[begin1];
		++begin1;
	}
	while (begin2 <= end2)
	{
		temp[i++] = a[begin2];
		++begin2;
	}

	memcpy(a + left, temp + left, sizeof(int)*(i - left));

}

void MergeSort()
{
	int a[] = { 2, 3, 1, 5, 6, 8, 9, 7, 4 };
	int n = sizeof(a) / sizeof(int);
	int* temp = (int*)malloc(sizeof(int)*n);

	_MergeSort(a, 0, n - 1, temp);
	
	Print(a, n);


	free(temp);
}

void CountingSort(int* a, int size)
{
	int min = a[0];
	int max = a[0];

	for (int i = 0; i < size; ++i)
	{
		if (a[i] < min)
			min = a[i];
		if (a[i]>max)
			max = a[i];
	}

	int len = max - min + 1;
	int* count = (int*)malloc(sizeof(int)*len);

	memset(count, 0, sizeof(int)*len);

	for (int i = 0; i < size; ++i)
	{
		count[a[i] - min]++;
	}

	int j = 0;

	for (int i = 0; i < len; ++i)
	{
		while (count[i]--)
		{
			a[j++] = i + min;
		}
	}

	
	
}






void _InsertSort()
{
	int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	InsertSort(a, sizeof(a) / sizeof(int));
	Print(a, sizeof(a) / sizeof(int));
}
void _ShellSort()
{
	int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	ShellSort(a, sizeof(a) / sizeof(int));
	Print(a, sizeof(a) / sizeof(int));
}

void _SlectSort()
{
	int a[] = { 2,3,1,5,6,8,9,7,4 };
	SlectSort(a, sizeof(a) / sizeof(int));
	Print(a, sizeof(a) / sizeof(int));
}

void _BubbleSort()
{
	int a[] = { 2, 3, 1, 5, 6, 8, 9, 7, 4 };
	BubbleSort(a, sizeof(a) / sizeof(int));
	Print(a, sizeof(a) / sizeof(int));
}
void _Quicksort()
{
	int a[] = { 2, 3, 1, 5, 6, 8, 9, 7, 4 };
	Non_Recursion(a, 0, sizeof(a) / sizeof(int)-1);
	Print(a, sizeof(a) / sizeof(int));
}

void Test()
{
	
	/*_InsertSort();
	_ShellSort();*/
	/*_SlectSort();*/
	//_BubbleSort();
	MergeSort();

	

	/*BubbleSort(a, sizeof(a) / sizeof(int));
	Print(a, sizeof(a) / sizeof(int));*/

}