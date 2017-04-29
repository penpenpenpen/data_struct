```c
#include <stdio.h>
#include <string.h>

#define	SIZE	10	

struct queue{
	int q[SIZE];
	int front;
	int rear;
};

void init_queue(struct queue* que)
{
	que->front = 0;
	que->rear = 0;	
	memset(que->q, 0x0, sizeof(que->q));
}
int in_queue(struct queue* que, int data)
{
	if((que->rear+1)%SIZE == que->front){
		printf("queue full. \n");
		return -1;
	}
	else {
		que->q[que->rear] = data;
		que->rear = (que->rear + 1)%(SIZE);
	}
}
int out_queue(struct queue* que)
{
	if(que->front == que->rear){
		printf("queue empty. \n");
		return -1;
	}
	int tmp = que->q[que->front];
	que->front = ((que->front) + 1)%SIZE;

	return tmp;
}
int set_null_queue(struct queue* que)
{
	memset(que->q, 0x0, sizeof(que->q));
}
int main()
{
	struct queue que;		
	init_queue(&que);	
	
	int i ;
	for(i=0; i<9; i++)
		in_queue(&que, 10+i);
	int ret = 0;
	printf("1st out: \n");
	for(i=0; i<10; i++)
		printf("%d\t",out_queue(&que));		
	printf("\n");
//---------------------------------------------------
	for(i=0; i<3; i++)
		in_queue(&que, 10+i);
	printf("2nd out: \n");
	for(i=0; i<5; i++)
		printf("%d\t",out_queue(&que));		
	printf("\n");

	set_null_queue(&que);

	return 0;
}
```