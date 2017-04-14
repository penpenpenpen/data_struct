#ifndef	_COMMON_H
#define	_COMMON_H

#include <stdio.h>
#include <stdlib.h>

typedef struct person{
	int age;
	struct person* next;
}PER, *PPER;

struct operations {
	struct person* (*p_create)(struct person*, int );
	void (*p_show)(struct person* );
	struct person* (*p_insert)(struct person* , int );
	struct person* (*p_insert_head)(struct person* , int );
	struct person* (*p_insert_node)(struct person* , int, int, int );
};

PPER create(struct person* , int );
void show(struct person* );
struct person* insert(struct person* , int );
struct person* insert_head(struct person* , int );
struct person* insert_node(struct person* , int, int, int );
struct person* del(struct person* , int );

#endif





