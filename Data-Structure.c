//SList.h
#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>


typedef int SLTDateType;

typedef struct SListNode
{
	SLTDateType date;
	struct SListNode* _next;
}SListNode;

typedef struct SList
{
	 SListNode* _head;
}SList;

void SListInit(SList* plt);
void SListPushBack(SList* plt, SLTDateType x);//后插
void SListPushFront(SList* plt, SLTDateType x);//前插
void SListPopBack(SList* plt);//后删
void SListPopFront(SList* plt);//前删
SListNode* SListFind(SList* plt, SLTDateType x);//找元素
void SListInsertAfter(SListNode* pos, SLTDateType x);//任意后插
void SListEraseAfter(SListNode* pos);//任意后删
void SListRemove(SList* plt, SLTDateType x);//根据元素  任意删
void SListPrint(SList* plt);

//Slist.c
#include"Slist.h"

void SListInit(SList* plt)
{
	assert(plt);
	plt->_head = NULL;
}

void SListPushBack(SList* plt, SLTDateType x)//后插
{
	assert(plt);
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));

	newnode->date = x;
	newnode->_next = NULL;

	if (plt->_head == NULL)
	{
		plt->_head = newnode;
	}
	else
	{
		SListNode* cur = plt->_head;
		while (cur->_next != NULL)
		{
			cur = cur->_next;
		}
		cur->_next = newnode;
	}

}
void SListPushFront(SList* plt, SLTDateType x)//前插
{
	assert(plt);
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->date = x;
	newnode->_next = NULL;
	
	newnode->_next = plt->_head;
	plt->_head = newnode;

}

void SListPopBack(SList* plt)//后删
{
	assert(plt);
	SListNode* cur = plt->_head;


	if (cur == NULL)
	{
		return;
	}
	else if(cur->_next == NULL)
	{
		free(cur);
		plt->_head = NULL;

	}

	else
	{

		while (cur->_next->_next != NULL)
		{
			cur = cur->_next;
		}
		free(cur->_next);
		cur->_next = NULL;
	}
}
void SListPopFront(SList* plt)//前删
{
	assert(plt);
	SListNode* cur = plt->_head;
	
	if (cur == NULL)
	{
		return;
	}
	else
	{

		plt->_head = cur->_next;
		free(cur);
		cur = NULL;

	}
}
SListNode* SListFind(SList* plt, SLTDateType x)//找元素
{
	assert(plt);
	SListNode* cur = plt->_head;
	while (cur->_next != NULL)
	{
		if (cur->date == x)
			return cur;
		cur = cur->_next;
	}
	return NULL;

}
void SListInsertAfter(SListNode* pos, SLTDateType x)//任意后插
{
	assert(pos);

	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->date = x;
	newnode->_next = NULL;

	newnode->_next = pos->_next;
	pos->_next = newnode;

}
void SListEraseAfter(SListNode* pos)//任意后删
{
	assert(pos);
	if (pos->_next == NULL)
	{
		return;
	}
	else
	{
		SListNode* next = pos->_next;
		pos->_next = next->_next;
		free(next);
		next = NULL;
	}
}
void SListRemove(SList* plt, SLTDateType x)//根据元素  任意删
{
	assert(plt);
	SListNode* prev = NULL;
	SListNode* cur = plt->_head;
	

	while (cur != NULL)
	{
		if (cur->date == x)
		{
			if (prev == NULL)
				plt->_head = cur->_next;
			else
				prev->_next = cur->_next;

			free(cur);
			cur = NULL;
			return;
		}
		else
		{
			prev = cur;
			cur = cur->_next;
		}
	}
}
void SListPrint(SList* plt)
{
	assert(plt);
	SListNode* cur = plt->_head;

	while (cur != NULL)
	{
		printf("%d->", cur->date);
		cur = cur->_next;
	}
	printf("NULL\n");
}


void TestList()
{
	SList lt;
	SListInit(&lt);
	SListPushBack(&lt, 1);
	SListPushBack(&lt, 2);
	SListPushBack(&lt, 3);
	SListPushBack(&lt, 4);
	SListPushFront(&lt, 0);

	SListPrint(&lt);

	SListPopBack(&lt);
	SListPopBack(&lt);
	SListPopBack(&lt);
	SListPrint(&lt);

	SListPopFront(&lt);
	SListPopFront(&lt);
	SListPrint(&lt);



}
void TestList2()
{
	SList lt;
	SListInit(&lt);
	SListPushBack(&lt, 1);
	SListPushBack(&lt, 2);
	SListPushBack(&lt, 3);
	SListPushBack(&lt, 4);
	SListPushFront(&lt, 0);
	SListPrint(&lt);

	SListNode* pos = SListFind(&lt, 3);
	SListInsertAfter(pos, 30);
	SListPrint(&lt);

	SListEraseAfter(pos);
	SListPrint(&lt);

	SListRemove(&lt, 4);
	SListPrint(&lt);



}



//Test.c

#include"Slist.h"


int main()
{
	TestList();
	printf("TestList2\n");
	TestList2();
	system("pause");
	return 0;
}