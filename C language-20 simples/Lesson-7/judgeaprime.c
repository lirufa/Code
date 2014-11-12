#include<stdio.h>
#include<math.h>

int main(void)
{
	int num=0;
 	int i=0; 
	int maxprime=0;
	printf("judge a num prime or not:\n");
	
	for(num=2;num<=100000;num++)
	{
//		int tmp=sqrt(num);
		for(i=2;i<=num/2;i++)
		{
			if(num%i==0)
			{
#if DEBUGG
				printf("%d is not a prime\n",num);
#endif
				break;
			}
		}

		if(i==num/2+1)
		{
			maxprime=num;
#if DEBUGG	
		printf("%d is a prime\n",num);
#endif
		}
	//printf("the max prime is %d\n",maxprime);
	}
        printf("the max prime is %d\n",maxprime);

	return 0;
}
