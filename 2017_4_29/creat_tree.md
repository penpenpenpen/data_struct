```c
#include <stdio.h>
#include <stdlib.h>

struct node{
	char data;
	struct node *left;
	struct node *right;
};

struct node *create(struct node *root)
{
	char ch = getchar();
	if(ch == '#'){
		return NULL;
	}else{
		root = malloc(sizeof(struct node));
		root->data = ch;
		root->left = create(root->left);
	root->right = create(root->right);
		return root;
	}
}

void pre_order(struct node *root)
{
	if(root == NULL)
		return ;
	else{
		printf("%c\t",root->data);
		pre_order(root->left);
		pre_order(root->right);
	}
}

void in_order(struct node *root)
{
	if(root == NULL)
		return ;
	else{
		in_order(root->left);
		printf("%c\t", root->data);
		in_order(root->right);
	}
}

void postorder(struct node *root)
{
	if(root == NULL)
		return ;
	else{
		postorder(root->left);
		postorder(root->right);
		printf("%c\t", root->data);
	}
}

int main()
{
	struct node *root = NULL;

	root = create(root);

	pre_order(root);
	printf("\n");
	in_order(root);
	printf("\n");
	postorder(root);
	printf("\n");

	return 0;

}
```