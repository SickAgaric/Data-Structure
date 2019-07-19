#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>


typedef int DATAQUType;
typedef struct QueueNode
{
	struct QueueNode* next;
	DATAQUType val;
}QueueNode;


typedef struct Queue
{
	QueueNode* front;
	QueueNode* rear;
}Queue;

void QueueCreat(Queue* queue);
void QueueDestroy(Queue* queue);

void QueuePush(Queue* queue,DATAQUType x);
void QueuePop(Queue* queue);

DATAQUType QueueFront(Queue* queue);
DATAQUType QueueBack(Queue* queue);

int QueueEmpty(Queue* queue);
int QueueSize(Queue* queue);




void QueueCreat(Queue* queue)
{
	assert(queue);

	queue->front = NULL;
	queue->rear = NULL;
}

void QueueDestroy(Queue* queue)
{
	assert(queue);
	QueueNode* cur = queue->front;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	queue->front = queue->rear = NULL;


}





void QueuePush(Queue* queue, DATAQUType x)
{
	assert(queue);

	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->next = NULL;
	node->val = x;

	if (queue->rear == NULL)
		queue->front = queue->rear = node;
	else
	{
		queue->rear->next = node;
		queue->rear = node;

	}
}


void QueuePop(Queue* queue)
{
	assert(queue && queue->front!=NULL);

	QueueNode* new = queue->front->next;

	free(queue->front);
	queue->front = new;
	

	if (queue->front == NULL)
	{
		queue->rear = NULL;
	}

}
DATAQUType QueueFront(Queue* queue)
{
	assert(queue&&queue->front!=NULL);

	return queue->front->val;
}
DATAQUType QueueBack(Queue* queue)
{
	assert(queue&&queue->rear!=NULL);

	return queue->rear->val;
}

int QueueEmpty(Queue* queue)
{
	assert(queue);

	return queue->front == NULL;
}
int QueueSize(Queue* queue)
{
	assert(queue);

	int size = 0;
	QueueNode* cur = queue->front;

	while (cur)
	{
		++size;
		cur = cur->next;
		
	}
	return size;
}