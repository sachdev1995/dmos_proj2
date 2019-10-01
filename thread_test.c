#include "q.h"

int main()
{
	printf("in main\n");

	Queue *head = newQueue();
	
	Queue *item = NewItem();
	
	AddQueue(&head,item);
	Queue *item1 = NewItem();
	AddQueue(&head,item1);
	Queue *item2 = NewItem();
	AddQueue(&head,item2);
	printAll(head);
	Queue *item3 = DelQueue(&head);
	if (item3!= NULL) printf("deleted item is %d\n",item3->data);
	
	Queue *item4 = DelQueue(&head);
	if (item4!= NULL) printf("deleted item is %d\n",item4->data);
	
	Queue *item5 = DelQueue(&head);
	if (item5!= NULL) printf("deleted item is %d\n",item5->data);
	
	Queue *item6 = DelQueue(&head);
	if (item6!= NULL) printf("deleted item is %d\n",item6->data);

	printAll(head);
	AddQueue(&head,item2);
	AddQueue(&head,item1);
	Queue *item7 = DelQueue(&head);
	printAll(head);

	return 0;
}