#include<stdio.h>
//#define PRINT(x) printf("<Debug>"  #x "=%d\n",x);
#define PRINT(x) 

int main(void)
{
	int i=0;
	int j=0;
	printf("print 9*9 multiplication table:\n");

	for(i=1;i<=9;i++)
	{	
		for(j=1;j<=i;j++)
			{
				
				//PRINT(j);
				//printf("j=%d",j);
				printf("%d*%d=%d\t",i,j,i*j);
				PRINT(j);

			}	
		printf("\n");
	}
	return 0;
}
