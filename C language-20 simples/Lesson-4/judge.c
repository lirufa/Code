#include<stdio.h>

int main(void)
{
	int num;
	
	printf("demo judge number prity\n");
	scanf("%d\n", &num);

	if(num%2==0)
		printf("%d is a even\n",num);
	if(num%2==1)
		printf("%d is a odd\n",num);
	return 0;
}
