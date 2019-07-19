#pragma once
#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#include<assert.h>
#include<stdlib.h>



typedef int DATAType;

typedef struct Stack
{
	DATAType* array;
	size_t top;
	size_t capacity;
}Stack;

void StackCreat(Stack* ps);
void StackDestroy(Stack* ps);

void StackPush(Stack* ps, DATAType x);
void StackPop(Stack* ps);

DATAType StackTop(Stack* ps);

bool StackEmpty(Stack* ps);
size_t StackSize(Stack* ps);




void StackCreat(Stack* ps)
{
	assert(ps);

	ps->array = NULL;
	ps->top = 0;
	ps->capacity = 0;
}
void StackDestroy(Stack* ps)
{
	assert(ps);

	if (ps->array != NULL)
	{
		free(ps->array);
		ps->array = NULL;
		ps->capacity = ps->top = 0;
	}
}

void StackPush(Stack* ps, DATAType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		size_t newcapacity = ps->capacity == 0 ? 2 : ps->capacity * 2;
		//ps->capacity == 0为 A 表达式  如果满足A计算B 不满足计算C
		ps->capacity = newcapacity;
		ps->array = (DATAType*)realloc(ps->array,newcapacity*sizeof(DATAType));
		//realloc可能存在空间申请失败的问题
		if (ps->array == NULL)
			return NULL;
	}
	ps->array[ps->top] = x;
	ps->top++;

}
void StackPop(Stack* ps)
{
	assert(ps&&ps->top>0);

	--ps->top;
}

DATAType StackTop(Stack* ps)
{
	assert(ps&&ps->top>0);

	/*DATAType top = ps->array[ps->top];
	--ps->top;

	return top;*/
	return ps->array[ps->top-1];
}
size_t StackSize(Stack* ps)
{
	assert(ps);

	return ps->top;
}

bool StackEmpty(Stack* ps)
{
	assert(ps);

	/*if (ps->top == 0)
		return true;
		else
		return false;*/
	return ps->top == 0;
}

