#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* pre;
	struct node* next;
};

struct node* create(struct node* phead, int data)
{
	struct node* tmp = malloc(sizeof(struct node));
	tmp->data = data;
	tmp->pre = NULL;
	tmp->next = NULL;

	return tmp;
}
struct node* add_head(struct node* phead, int data)
{
	struct node* tmp = malloc(sizeof(struct node));
	tmp->data = data;
	tmp->pre = NULL;
	tmp->next = NULL;

	tmp->next = phead;	
	phead->pre = tmp;

	return tmp;
}
void show(struct node* phead)
{
	while(phead){
		printf("%d\t", phead->data);
		phead = phead->next;
	}
	printf("\n");
}
int insert(struct node* phead, int key, int data)
{
	struct node* tmp = malloc(sizeof(struct node));
	tmp->data = data;
	tmp->pre = NULL;
	tmp->next = NULL;
	struct node* find = phead;	

	while(find != NULL){
		if(find->data == key) {
			tmp->next = find->next;
			tmp->pre = find;
			find->next = tmp;
			if(tmp->next != NULL)
				tmp->next->pre = tmp;
		}
		find = find->next;
	}
}
struct node* del2(struct node* phead, int key)
{
	struct node* tmp = phead;
	struct node* find = NULL;

	if(tmp->data == key){
		phead = phead->next;
		phead->pre = NULL;
		free(tmp);
		return phead;
	}
	while(tmp != NULL){
		if(tmp->data == key ){
			if(tmp->next == NULL){
				tmp->pre->next = tmp->next;
			}  else { 
				tmp->pre->next = tmp->next;
				tmp->next->pre = tmp->pre;
			}
			free(tmp);			
			return phead;
		}
		tmp = tmp->next;
	}
}
struct node* del(struct node* phead, int key)
{
	struct node* tmp = phead;
	struct node* find = NULL;

	if(tmp->data == key){
		phead = phead->next;
		phead->pre = NULL;
		free(tmp);
		return phead;
	}
	while(tmp != NULL){
		if(tmp->data == key ){
			tmp->pre->next = tmp->next;
			if(tmp->next != NULL)
				tmp->next->pre = tmp->pre;
			free(tmp);			
			return phead;
		}
		tmp = tmp->next;
	}
}
void destory(struct node* phead)
{
	while(phead->next != NULL){
		phead = phead->next;
		free(phead->pre);
	}
	free(phead);
}
int main()
{
	struct node* head = NULL;

	head = create(head, 20);	
	head = add_head(head, 23);
	head = add_head(head, 21);
	head = add_head(head, 53);
	head = add_head(head, 93);
	show(head);

	insert(head, 20, 100);
	show(head);
	head = del(head, 93);
	show(head);

	destory(head);
	return 0;
}









