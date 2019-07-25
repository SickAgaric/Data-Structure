#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>


typedef int DATAtype;


typedef struct Heap
{
	DATAtype* arr;
	int size;
	int capacity;
}Heap;

void HeapCreat(Heap* he, DATAtype* arr, int size);
void HeapDestroy(Heap* he);
void Print(Heap* he);

DATAtype HeapTop(Heap* he);

void HeapPush(Heap* he, DATAtype x);
void HeapPop(Heap* he);
void HeapDestroy(Heap* he);

void HeapSort(DATAtype* arr, int size);


int HeapSize(Heap* he);

#include"Heap.h"


void Swap(DATAtype* a,DATAtype* b)
{
	DATAtype* temp = *a;
	*a = *b;
	*b = temp;
}

void AdjustDown(DATAtype* arr, size_t size, size_t parents)
{
	int child = parents * 2 + 1;

	while (child<size)
	{
		if (child+1<size&&arr[child] > arr[child + 1])
			child++;


		if (arr[child] < arr[parents])
		{
			Swap(&arr[child],&arr[parents]);
			parents = child;
			child = parents * 2 + 1;
		}
		else
			break;
	}


}

void AdjustUP(DATAtype* arr, size_t size, size_t parents)
{
	int child = parents*2+1;



	while (child<size)
	{
		if (child + 1<size && arr[child] < arr[child + 1])
			child++;


		if (arr[child] > arr[parents])
		{
			Swap(&arr[child], &arr[parents]);
			parents = child;
			child = parents * 2 + 1;
		}
		else
			break;
	}


}





void HeapCreat(Heap* he, DATAtype* arr, int size)
{
	he->arr = (DATAtype*)malloc(sizeof(DATAtype)*size);
	memcpy(he->arr, arr, sizeof(DATAtype)*size);

	he->capacity = size;
	he->size = size;
	

	for (int i = (size - 1 - 1) / 2; i >= 0; --i)
		AdjustUP(he->arr,he->size,i);
}


void Print(Heap* he)
{
	
	for (int i = 0; i<he->size; i++)
	{
		printf("%d ", he->arr[i]);
	}
	printf("\n");
}


int HeapSize(Heap* he)
{
	return he->size;
}

DATAtype HeapTop(Heap* he)
{
	return he->arr[0];
}

void HeapPush(Heap* he, DATAtype x)
{
	int newcapacity = he->capacity * 2;
	if (he->size == he->capacity)
		he->arr = (DATAtype*)realloc(he->arr,sizeof(DATAtype)*newcapacity);
	he->capacity = newcapacity;

	he->arr[he->size] = x;
	he->size++;
		
	for (int i = (he->size - 1 - 1) / 2; i >= 0; --i)
		AdjustDown(he->arr, he->size, i);
}

void HeapPop(Heap* he)
{

	he->size--;
	if (he->size == 0)
		free(he->arr);
}

void HeapDestroy(Heap* he)
{
	he->capacity = he->size = 0;
	free(he->arr);
}

void HeapSort(DATAtype* arr, int size)
{

	assert(arr);
	
	for (int i = (size - 2) / 2; i >= 0; --i)
	{
		AdjustUP(arr, size, i);
	}
	int end = size - 1;
	while (end>0)
	{
		Swap(&arr[0], &arr[end]);
		AdjustUP(arr, end, 0);
		--end;
	}
	
}
#include"Heap.h"


//void Test()
//{
//	Heap myheap;
//	DATAtype arr[] = { 7, 5, 2, 0, 6, 8, 3, 9, 1 };
//	HeapCreat(&myheap, arr, sizeof(arr)/sizeof(DATAtype));
//	/*HeapPush(&myheap, 0);*/
//	/*HeapSort(&myheap.arr, sizeof(arr) / sizeof(DATAtype));*/
//
//	Print(&myheap);
//	
//
//	/*printf("%d\n", HeapSize(&myheap));
//	printf("%d\n",HeapTop(&myheap));
//	HeapPop(&myheap);
//	Print(&myheap);
//
//	HeapDestroy(&myheap);*/
//	
//
//
//}
void Test1()
{
	/*Heap myheap;*/
	DATAtype arr[] = { 7, 5, 2, 0, 6, 8, 3, 9, 1 };
	/*HeapCreat(&myheap, arr, sizeof(arr) / sizeof(DATAtype));
	Print(&myheap);*/

	HeapSort(arr, sizeof(arr) / sizeof(int));
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	




}

int main()
{


	Test1();


	system("pause");
	return 0;
}


//创建二叉树，进行遍历
#include<stdio.h>
#include<malloc.h>

typedef struct TreeNOde
{
	char s;
	struct TreeNode* left;
	struct TreeNode* right;
}Node;

Node* CreatPreoder(char* arr, int* size)
{
	if (arr[*size] == '#')
	{
		++(*size);
		return NULL;
	}

	Node* root = (Node*)malloc(sizeof(Node));
	root->s = arr[*size];
	++(*size);

	root->left = CreatPreoder(arr, size);

	root->right = CreatPreoder(arr, size);

	return root;
}
void inoder(Node* root)
{
	if (root == NULL)
		return;

	inoder(root->left);
	printf("%c ", root->s);
	inoder(root->right);
}

int main()
{
	char arr[101];
	
	scanf("%s",arr);
	
            int i = 0;//传参应该放在while，不然会延续上一次的传参
            Node* root = CreatPreoder(arr, &i);
		    inoder(root);
            printf("\n");
	

	return 0;
}
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct TreeNOde
{
	char s;
	struct TreeNode* left;
	struct TreeNode* right;
}Node;

void Print(Node* root)
{
	if (root == NULL)
		return;
	printf("%c", root->s);

	Print(root->left);
	
	Print(root->right);

}

Node* CreatPreoder(char* arr, int* size)
{
	if (arr[*size] == '#')
	{
		++(*size);
		return NULL;
	}

	Node* root = (Node*)malloc(sizeof(Node));
	root->s = arr[*size];
	++(*size);

	root->left = CreatPreoder(arr, size);

	root->right = CreatPreoder(arr, size);

	return root;
}
void inoder(Node* root)
{
	if (root == NULL)
		return;

	inoder(root->left);
	printf("%c ", root->s);
	inoder(root->right);
}
void BinaryTreeDestory(Node** root)
{
	if (*root == NULL)
		return;
	BinaryTreeDestory(&((*root)->left));

	BinaryTreeDestory(&((*root)->right));

	free(*root);
	*root = NULL;


}
int BinaryTreeSize(Node* root)
{
	if (root == NULL)
		return 0;

	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}
int BinaryTreeLeafSize(Node* root)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL&&root->right == NULL)
		return 1;

	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);

}
int BinaryTreeLevelKSize(Node* root, int k)
{
	if (root == NULL)
		return 0;

	if (k > 1)
		return 1;

	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}

void BinaryTreePostOrder(Node* root)
{

	if (root == NULL)
		return;
	
	BinaryTreePostOrder(root->left);

	BinaryTreePostOrder(root->right);
	printf("%c", root->s);
	
}
Node* BinaryTreeFind(Node* root, Node** c ,char x)
{
	
	
	if (root == NULL)
		return NULL;
	if (root->s == x)
	{
		
		*c = root;
		
	}
	

	BinaryTreeFind(root->left,c,x);
	BinaryTreeFind(root->right,c, x);

	

}

void BinaryTreeLevelOrder(Node* root)
{

}

void Test()
{
	char arr[101] = "abc##de#g##f###";

	/*scanf("%s", arr);*/

	int i = 0;//传参应该放在while，不然会延续上一次的传参
	Node* root = CreatPreoder(arr, &i);
	Print(root);
	printf("\n");


	/*printf("%d\n", BinaryTreeSize(root));*/

	
	printf("%d\n", BinaryTreeLeafSize(root));
	int k = 2;
	printf("%d\n",BinaryTreeLevelKSize(root, k));
	/*BinaryTreeDestory(&root);*/
	Node* c = (Node*)malloc(sizeof(Node));
	BinaryTreeFind(root,&c, 'b');
	printf("%c\n", c->s);
	

}


int main()
{
	
	
	
	Test();
	system("pause");
	return 0;
}










