/*

Bhupinder singh Sachdev / ASU ID: 1215098443
Pavan raichur / ASU ID 1213378684: 

*/

#include "threads.h"

int global_counter = 0;

void funct1(void)
{
	int local_counter = 0;
	while(1)
	{
		get_threadId(Curr_Thread);
		printf("in func1 global_counter = %d, local_counter = %d\n",global_counter++,local_counter++);
		yield();
	}
}

void funct2(void)
{
	int local_counter = 0;
	while(1)
	{
		get_threadId(Curr_Thread);
		printf("in func2 global_counter func = %d, local_counter = %d\n",global_counter++,local_counter++);
		yield();
	}
}


int main()
{
	printf("in main\n");
	ReadyQ = newQueue();

	start_thread(funct1);
	start_thread(funct2);
	start_thread(funct1);
	start_thread(funct2);

	run();
	
	return 0;
}
