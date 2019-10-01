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
	//Queue *q = (Queue *)malloc (sizeof(Queue ));
	Queue *q = NULL;
	return q;
};



Queue *NewItem()
{
	Queue *q = (Queue *)malloc (sizeof(Queue ));
	q->data = ++count;
	return q;
}



void AddQueue(Queue *headPtr, Queue *item )
{
	if(headPtr == NULL)
	{
		printf("inside\n");	
		item->next = item;
		item->prev = item;
		headPtr = item;
		return;
	}
}



void printAll(Queue *headPtr)
{
	Queue *temp = headPtr;

	if(temp == NULL)
	{
		printf("queue is empty\n");
		return ;
	}

	printf("Queue data is \n");
	temp = temp->next;
	while(headPtr != temp)
	{
		printf("%d\n",temp->data);
		temp = temp->next;
	}
	printf("last data is %d\n",temp->data);

}