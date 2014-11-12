#include<stdio.h>

int main(void)
{
	int num=0;
	int counter=0;
	printf("sum 9 from 1 to num,please enter a num:\n");
	
	scanf("%d",&num);
				
	int i=0,tmp=0;
	for(i=1;i<=num;i++)
	{
		tmp=i;		
		while(tmp!=0)
		{		
			if(tmp%10==9)
				{
					counter++;	
					printf("%d has a 9\n",i);
				}
			tmp=tmp/10;
		}
	}
	
	printf("counter=%d\n",counter);

	return 0;
}
