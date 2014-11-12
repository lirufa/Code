#include<stdio.h>

int main(void)
{
	int sum=0;
	int i=0;

	printf("add 1 to 100:\n");
	for (i;i<=100;i++)
	{	
     		if(i%2==1)
			continue;
		sum+=i;
		
	}	
	printf("sum=%d\n",sum);

	return 0;

}
