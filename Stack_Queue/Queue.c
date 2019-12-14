#include"Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->front = pq->back = NULL;
}

void QueuePush(Queue* pq, QDataType data)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->data = data;
	newnode->next = NULL;
	if (pq->back == NULL)
	{
		pq->front = pq->back = newnode;
	}
	else
	{
		pq->back->next = newnode;
		pq->back = newnode;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq);
	QueueNode* next = pq->front->next;
	free(pq->front);
	pq->front = next;

	if (pq->front == NULL)
	{
		pq->back = NULL;
	}
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);

	return pq->front->data;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	return pq->back->data;
}

int QueueSize(Queue* pq)
{
	size_t n = 0;
	QueueNode* cur = pq->front;
	while (cur != NULL)
	{
		cur = cur->next;
		++n;
	}
	return n;
}

int QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->front == NULL ? 1 : 0;
}

void QueueDestroy(Queue* pq)
{
	QueueNode* cur = pq->front;
	while (cur != NULL)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->front = pq->back = NULL;
}
