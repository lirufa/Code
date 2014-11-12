/*************************
*name:joseph-1.c
*date:Sep 25,2014
*author:Lirufa
*function:find the last num with Joseph algorithm
************************/
#include<stdio.h>
/*define a global var for the people*/
int people[1000];
/*define a list array used to the local element's of people next elementindex*/
int next[1000];
/*define a count num*/
#define COUNTER 3

void main(void)
{	
		
	int num=0,i=0,left=0,prev=0,indexval=0;
	printf("please enter a num of people of Joseph:\n");
	scanf("%d",&num);
	left=num;

	/*inti the people array*/
	for(i=1;i<=num;i++)
	{	people[i-1]=i;//set value from 1
	//	printf("%4d",people[i-1]);
	}
	//printf("   (people)\n");
	
	for(i=1;i<=num;i++)
        {      indexval=i%num;
	       next[i-1]=indexval;
        //       printf("%4d",next[i-1]);
        }       
        //printf("  (next)\n");

	int counter=0,n=0;
	while(1)
	{	//if(people[n]>0)
			counter++;

		if(counter==COUNTER)
		{
		printf("get rid of %d\n",people[n]);//used for debug
                        people[n]=0;
 			next[prev]=next[n];

		/*	for(i=1;i<=num;i++)
               		{     	printf("%4d",people[i-1]);
                	}
			printf("\n");

                        for(i=1;i<=num;i++)
                        {      printf("%4d",next[i-1]);
                        }
                        printf("\n");
		*/
			left--;//the num of people of non 0
			counter=0;
		}
		//getchar();
		//printf("n=%d,counter=%d,left=%d\n",n,counter,left);
		prev=n;
		n=next[n];
			
		if(n==num)//ID of array
			n=0;
		if(left<1)//left a identifier countting array element
		break;
	}
	printf("%d is left and the joseph.c is finished!\n",people[n]);	
	return;
}
