#include "common.h"

struct operations ops = {
	.p_create = create,
	.p_print = print,           
	.p_sort = sort, 
};                          

int main()
{
	Person *head = (Person *)malloc(sizeof(Person));
	ops.p_create(head);
	ops.p_print(head);
	ops.p_sort(head);
	ops.p_print(head);

}
