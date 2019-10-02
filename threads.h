#include "q.h"

TCB_t *ReadyQ;
TCB_t *Curr_Thread;
unsigned int stack_size = 8192;
int thread_count = 0;


void start_thread(void (*function)(void))
{ 

	stack_t *stack = (stack_t *)malloc( stack_size );
	TCB_t *tcb = NewItem();
	init_TCB(tcb,function,stack,stack_size);
	tcb->thread_id = thread_count++; //TO DO
	AddQueue(&ReadyQ,tcb);

}


void run()

{   
	Curr_Thread = DelQueue(&ReadyQ);
	ucontext_t parent;     
    getcontext(&parent);   
    swapcontext(&parent, &(Curr_Thread->context));

}

void yield() // similar to run
{  TCB_t *Prev_Thread;
   AddQueue(&ReadyQ, Curr_Thread);
   Prev_Thread = Curr_Thread;
   Curr_Thread = DelQueue(&ReadyQ);
   //swap the context, from Prev_Thread to the thread pointed to Curr_Thread
   swapcontext(&(Prev_Thread->context),&(Curr_Thread->context));
}
 
