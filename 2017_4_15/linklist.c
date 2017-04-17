#include <stdio.h> 
#include <stdlib.h>

struct person{
	int age;
	struct person* next;
};


struct person* create_loop_head(struct person* phead, int pa)
{
	struct person* tmp = malloc(sizeof(struct person));
	tmp->age = pa;
	tmp->next = NULL;

	tmp->next = tmp;
	return tmp;	
}
void add_node(struct person* phead, int a)
{
	struct person* tmp = malloc(sizeof(struct person));
	tmp->age = a;
	tmp->next = NULL;
	struct person* find = phead;

	while(find->next != phead)	
		find = find->next;	
	find->next = tmp;
	tmp->next = phead;	
}
void show(struct person* phead)
{
	struct person* tmp = phead;
	do{
		printf("%d\t", phead->age);
		phead = phead->next;
	} while(phead != tmp);
	printf("\n");
}

void destory2(struct person* phead)
{
	struct person* tmp = phead->next;
	phead->next = NULL;

	while(tmp != NULL){
		phead = tmp;
		tmp = tmp->next;
		free(phead);
	}
}

void destory(struct person* phead)
{
	struct person* tmp = phead;
	struct person* find = phead;

	do{
		phead = tmp;
		tmp = tmp->next;
		free(phead);
	} while(tmp != find);
}
int del_repeat_node(struct person* phead, int data)
{
	struct person* tmp = phead;
	struct person* find = NULL;
	int flag = 0;

	if(phead->age == data){
		flag = 1;
	}
	while(tmp->next != phead){
		if(tmp->next->age == data){
			if(flag == 0){
				flag = 1;
				tmp = tmp->next;
			}else {
				find = tmp->next;
				tmp->next = find->next;
				free(find);
			}
		}
		else 
			tmp = tmp->next;
	}
}
int main()
{
	struct person* head = NULL;
	head = create_loop_head(head, 20);	
	add_node(head, 20);
	add_node(head, 31);
	add_node(head, 20);
	add_node(head, 20);
	add_node(head, 20);
	add_node(head, 39);
	add_node(head, 40);
	add_node(head, 20);

	show(head);
	del_repeat_node(head, 20);
	show(head);

	destory(head);
	return 0;
}



