#include<stdio.h>

void qsort(int a[], int low, int high)
{
	int i = low;
	int j = high;
	int temp = a[low];
	if(i >= j)
		return ;
	while(i < j){
		while(i < j && a[j] >= temp)
			--j;
		if(i < j){
			a[i] = a[j];
		}
		while(i < j && a[i] <= temp)
			++i;
		if(i < j){
			a[j] = a[i];
		}
	}
	a[i] = temp;

	qsort(a, low, i - 1);//递归调用排序 由low到i - 1
	qsort(a, i + 1, high);//递归调用排序 由i + 1到high
}

int main()
{
	int a[8] = {5, 2, 32, 43, 23, 45, 24, 50};
	int i;

	qsort(a, 0, 7);

	for(i = 0; i < 8; i++)
		printf("%3d", a[i]);
	printf("\n");
}
