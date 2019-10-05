#include "threads.h"

int global_counter = 0;

void funct1(void)
{
	int local_counter = 0;
	while(1)
	{
		printf("in func1 global_counter = %d, local_counter = %d\n",global_counter++,local_counter++);
		yield();
	}
}

void funct2(void)
{
	int local_counter = 0;
	while(1)
	{
		printf("in func2 global_counter = %d, local_counter = %d\n",global_counter++,local_counter++);
		yield();
	}
}


int main()
{
	printf("in main\n");

	start_thread(funct1);
	start_thread(funct2);
	start_thread(funct1);

	run();

	/*

	TCB_t *head = newQueue();
	
	TCB_t *item = NewItem();
	
	AddQueue(&head,item);
	TCB_t *item1 = NewItem();
	AddQueue(&head,item1);
	TCB_t *item2 = NewItem();
	AddQueue(&head,item2);
	printAll(head);
	TCB_t *item3 = DelQueue(&head);
	if (item3!= NULL) printf("deleted item is %d\n",item3->thread_id);
	
	TCB_t *item4 = DelQueue(&head);
	if (item4!= NULL) printf("deleted item is %d\n",item4->thread_id);
	
	TCB_t *item5 = DelQueue(&head);
	if (item5!= NULL) printf("deleted item is %d\n",item5->thread_id);
	
	TCB_t *item6 = DelQueue(&head);
	if (item6!= NULL) printf("deleted item is %d\n",item6->thread_id);

	printAll(head);
	AddQueue(&head,item2);
	AddQueue(&head,item1);
	TCB_t *item7 = DelQueue(&head);
	printAll(head);
	 DelQueue(&head);
	printAll(head);
	*/





	return 0;
}