#include "stdio.h"
#include "stdlib.h"

typedef struct QueueItems
{
	int data;
	struct QueueItems *next;
	struct QueueItems *prev;
}Queue;

int count = 0 ;



Queue *newQueue()
{
	
	Queue *q = NULL;
	return q;
};



Queue *NewItem()
{
	Queue *q = (Queue *)malloc (sizeof(Queue ));
	q->data = ++count;
	q->next = NULL;
	q->prev = NULL;
	return q;
}



void AddQueue(Queue **headPtr, Queue *item )
{
	if(*headPtr == NULL)
	{
		item->next = item;
		item->prev = item;
		*headPtr = item;
		return;
	}

	Queue *temp = (*headPtr)->prev;
	temp->next = item;
	item->prev = temp;
	item->next = *headPtr;
	(*headPtr)->prev = item;
	return;
	

}

Queue *DelQueue(Queue **headPtr)
{
	if(*headPtr == NULL)
	{
		printf("queue is empty, can't delete anything\n");
		return NULL;
	}
	Queue *deleted;
	if(( (((*headPtr)->next) == (*headPtr))) &&  (((*headPtr)->prev) == (*headPtr)))
	{
		 deleted = *headPtr;
		(*headPtr) = NULL;

		printf("last element in queue deleted, queue is now empty\n");

	}
	else
	{
		Queue *temp = (*headPtr)->prev;
		temp->next = (*headPtr)->next;
		(*headPtr)->next->prev = temp;
		deleted = *headPtr;
		(*headPtr) = (*headPtr)->next;
	}
	return (deleted);
}



void printAll(Queue *headPtr)
{
	Queue *temp = headPtr;

	if(temp == NULL)
	{
		printf("queue is empty, can't print anything\n");
		return ;
	}
	
	printf("Queue data is \n");
	printf("first data is \n%d\n",temp->data);
	temp = temp->next;
	while(headPtr != temp)
	{
		printf("%d\n",temp->data);
		temp = temp->next;
	}
	printf("backwards\n");
	
	temp = temp->prev;
	printf("first data is \n");
	while(headPtr != temp)
	{
		printf("%d\n",temp->data);
		temp = temp->prev;
	}
	printf("%d\n",temp->data);
	

}