#include "q.h"

int main()
{
	printf("in main\n");

	void *head = newQueue();
	printAll(head);
	Queue *item = NewItem();
	//if(item == NULL) printf ("empty\n");
	//printf("%d\n",item->data);
	AddQueue(head,item);
	printAll(head);

	return 0;
}