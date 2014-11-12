#include<stdio.h>

int sum(int num_1,int digital_1)
{
	 	int counter=0;
                do
                {
                        if(num_1%10==digital_1)
                                counter++;
                        num_1=num_1/10;
                }while(num_1!=0);

	return counter;
}

int main(void)
{
	int num=0;
	printf("please enter a num:\n");
	int i=0,tmp=0;
	int sum9=0;
	int digital=0;
	scanf("%d",&num);
	printf("please enter a digital:\n");
	scanf("%d",&digital);

	for(i=1;i<=num;i++)
	{	
		sum9+=sum(i,digital);
	/*
		do
		{
			if(tmp%10==digital)
				counter++;
			tmp=tmp/10;
		}while(tmp!=0);
	*/
	}
	
#if DEBUG
	printf("the digital is %d\n",digital);
#endif
	printf("the num of digital is %d\n",sum9);

	return 0;
}
