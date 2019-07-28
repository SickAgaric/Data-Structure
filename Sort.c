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