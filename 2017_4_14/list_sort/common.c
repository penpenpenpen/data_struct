#include "common.h"

Person *create(Person *head)                          
{
	Person *p,*q;
	p = head;
	int age;
	printf("please input age :\n");
	scanf("%d",&age);
	while(age > 0){
		q = (Person *)malloc(sizeof(Person));
		q->age = age;
		p->next = q;
		p = p->next;
		printf("please input age :\n");
		scanf("%d",&age);
	}
	return head;
}
void print(Person *head)
{
	Person *p = head->next;
	while(p != NULL){
		printf(" %d ",p->age);
		p = p->next;
	}
	printf("\n");
}

void sort(Person *head)
{
	Person *p = head->next, *pre;
	Person *r = p->next;
	p->next = NULL;
	p=r;
	while(p != NULL){
		r = p->next;
		pre = head;
		while(pre->next != NULL && pre->next->age < p->age)
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = r;
	}
}
