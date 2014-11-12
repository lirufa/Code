#include<stdio.h>
int global=200;

int main(void)
{
	int local=100;

	printf("hello world.\n");
	printf("global=0X%x\n",global);
	printf("local=0x%x\n",local);

	printf("&global=%p\n",&global);
	printf("&global=0x%x\n",&global);


	printf("&main=%p\n",&main);
	printf("local=%p\n",&local);
	return 0;
}
