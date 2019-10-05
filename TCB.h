/*

Bhupinder singh Sachdev / ASU ID: 1215098443
Pavan raichur / ASU ID 1213378684: 

*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ucontext.h"

typedef struct QueueItems
{
	int thread_id;
	ucontext_t context;
	struct QueueItems *next;
	struct QueueItems *prev;
}TCB_t;



void init_TCB (TCB_t *tcb, void *function, void *stackP, int stack_size)
{
    memset(tcb,'\0', sizeof(TCB_t));   
    getcontext(&tcb->context);             
    tcb->context.uc_stack.ss_sp = stackP;
    tcb->context.uc_stack.ss_size = (size_t) stack_size;
    makecontext(&tcb->context, function, 0);
}






