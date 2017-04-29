```c
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void in_queue(int data)
{
	struct node* tmp = malloc(sizeof(struct node));
	tmp->data = data;
	tmp->next = NULL;
	
	if(rear == NULL && front == NULL)
		front = rear = tmp;	
	else {
		rear->next = tmp;
		rear = rear->next;
	}
}
int out_queue()
{
	int tmp ;
	struct node* t;
	if(front == NULL){
		printf("\nqueue empty. \n");
		rear = NULL;
		return -1;
	}
	else {
		tmp = front->data;
		t = front;
		front = front->next;
		free(t);
	}
	return tmp;
}
void set_null_queue()
{
	struct node* t;
	while(front != NULL){
		t = front;
		front = front->next;
		free(t);
	}
}
int main()
{
	int i;
	for(i=0; i<5; i++)
		in_queue(10+i);	

	for(i=0; i<6; i++)
		printf("%d\t",out_queue());	
	printf("\n");

	for(i=0; i<5; i++)
		in_queue(21+i);	
	for(i=0; i<5; i++)
		printf("%d\t",out_queue());	
	printf("\n");

	set_null_queue();

	return 0;
}
```