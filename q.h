#include "stdio.h"
#include "stdlib.h"
#include "TCB.h"



int count = 0 ;



TCB_t *newQueue()
{
	
	TCB_t *q = NULL;
	return q;
};



TCB_t *NewItem()
{
	TCB_t *q = (TCB_t *)malloc (sizeof(TCB_t ));
	//q->thread_id = ++count;
	q->next = NULL;
	q->prev = NULL;
	return q;
}



void AddQueue(TCB_t **headPtr, TCB_t *item )
{
	if(*headPtr == NULL)
	{
		item->next = item;
		item->prev = item;
		*headPtr = item;
		return;
	}

	TCB_t *temp = (*headPtr)->prev;
	temp->next = item;
	item->prev = temp;
	item->next = *headPtr;
	(*headPtr)->prev = item;
	return;
	

}

TCB_t *DelQueue(TCB_t **headPtr)
{
	if(*headPtr == NULL)
	{
		printf("queue is empty, can't delete anything\n");
		return NULL;
	}
	TCB_t *deleted;
	if(( (((*headPtr)->next) == (*headPtr))) &&  (((*headPtr)->prev) == (*headPtr)))
	{
		 deleted = *headPtr;
		(*headPtr) = NULL;

		printf("last element in queue deleted, queue is now empty\n");

	}
	else
	{
		TCB_t *temp = (*headPtr)->prev;
		temp->next = (*headPtr)->next;
		(*headPtr)->next->prev = temp;
		deleted = *headPtr;
		(*headPtr) = (*headPtr)->next;
	}
	return (deleted);
}



void printAll(TCB_t *headPtr)
{
	TCB_t *temp = headPtr;

	if(temp == NULL)
	{
		printf("queue is empty, can't print anything\n");
		return ;
	}
	
	printf("Queue thread_id is \n");
	printf("first thread_id is \n%d\n",temp->thread_id);
	temp = temp->next;
	while(headPtr != temp)
	{
		printf("%d\n",temp->thread_id);
		temp = temp->next;
	}
	printf("backwards\n");
	
	temp = temp->prev;
	printf("first thread_id is \n");
	while(headPtr != temp)
	{
		printf("%d\n",temp->thread_id);
		temp = temp->prev;
	}
	printf("%d\n",temp->thread_id);
	

}