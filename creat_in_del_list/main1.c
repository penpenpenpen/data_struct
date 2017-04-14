#include "com.h"

struct operations ops = {
	.p_show = show,
	.p_insert = insert,
	.p_insert_node = insert_node,
};

int main()
{
	struct person* head = NULL;
	struct person* head2 = NULL;
	head = ops.p_insert(head, 20);
#if 1
	head2 = head;
	
	head2 = ops.p_insert(head2, 28);
	head2 = ops.p_insert(head2, 11);
	head2 = ops.p_insert(head2, 21);
	head2 = ops.p_insert(head2, 23);
	head2 = ops.p_insert(head2, 51);
	ops.p_show(head);
#endif	
	head = del(head, 21);
	if(head == NULL){
		printf("link is empty. \n");
		exit(1);
	}
	ops.p_show(head);

	destory(head);
	return 0;
}



