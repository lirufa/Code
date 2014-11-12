#include <stdio.h>

void print(int *a)
{
	printf("%d\n",sizeof(a));
}
int main(void)
{
	int a[10];
	printf("%d\n",sizeof(a));
	print(a);
	getchar();
	return 0;
}
