#include <stdio.h>

int insert(int* a, int len)
{
	int i = 0, j = 0, tmp = 0;

	for(i=0; i<len-1; i++)	{
			j = i;	
			tmp = a[i+1];
		while(tmp < a[j] && j>=0 ){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = tmp;
	}
}



int main()
{
	int a[9] = {12, 9, 0, 3, -12, 11, 7, 11, 1};
	insert(a, 9);
	int i = 0;
	for(i=0; i<9; i++)
		printf("%d  ", a[i]);
	printf("\n");

	return 0;
}



