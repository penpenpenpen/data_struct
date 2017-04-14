#include "com.h"

PPER create(struct person* phead, int pa)
{
	struct person* tmp = malloc(sizeof(struct person));
	tmp->age = pa;
	tmp->next = NULL;
	struct person* find = phead;
	
	if(phead == NULL)	
		return tmp;
	else {
		while(find->next != NULL)	
			find = find->next;
		find->next = tmp;
		return phead;	
	}
}
void show(struct person* phead)
{
	while(phead){
		printf("%d\t", phead->age);
		phead = phead->next;
	}
	printf("\n");
}
struct person* insert_head(struct person* phead, int pa)
{
	struct person* tmp = malloc(sizeof(struct person));
	tmp->age = pa;
	tmp->next = NULL;
	
	tmp->next = phead;
	return tmp;
}
struct person* insert(struct person* phead, int pa)
{
	struct person* tmp = malloc(sizeof(struct person));
	tmp->age = pa;
	tmp->next = NULL;

	if(phead == NULL)	
		return tmp;
	else {
		phead->next = tmp;	
		return tmp;
	}
}




struct person* insert_node(struct person* phead, int pa, int key, int flag)
{
	struct person* tmp = malloc(sizeof(struct person));
	tmp->age = pa;
	tmp->next = NULL;
	struct person* find = phead;

	if(phead == NULL)
		return tmp;
	if(flag == 0){
		tmp->next = phead;
		return tmp;
	} else if(flag == 1){
		while(find != NULL && find->age != key)
			find = find->next;
		if(find == NULL){
			printf("not found. \n");
		} else {
			tmp->next = find->next;
			find->next = tmp;
		}
		return phead;
	}
}

struct person* del(struct person* phead, int a)
{
	struct person* tmp = phead;
	struct person* bak = NULL;

	if(phead == NULL)	
		;
	else if(a == phead->age){
		phead = phead->next;
		free(tmp);
	} else  {
		while(tmp->next != NULL){
			if(tmp->next->age == a){
				bak = tmp->next;
				tmp->next = bak->next;
				free(bak);
				bak = NULL;	// 防止野指针的出现
				return phead;
			}
			tmp = tmp->next;	
		}
		printf("not found. \n");
	}
	return phead;
}

void destory(struct person* phead)
{
	struct person* tmp = phead;
	while(phead){
		tmp = phead;
		phead = phead->next;
		free(tmp);	
	}
}








