#ifndef	_COMMON_H
#define	_COMMON_H

#include <stdio.h>
#include <stdlib.h>

typedef struct person{
	int age;
	struct person* next;
}Person;

struct operations {
	Person* (*p_create)(struct person* );
	void (*p_print)(Person* );
	void (*p_sort)(Person* );
};

Person* create(Person* );
void print(Person* );
void sort(Person* );
#endif
