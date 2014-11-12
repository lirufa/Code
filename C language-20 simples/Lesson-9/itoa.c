#include<stdio.h>

int num=0;
char buf[10];
int i=0;
int tmp=0;
void getval(int num,char buf[])
{	

	tmp=num;
        do
        {
                //int tmp=0;
                buf[i]=tmp%10+'0';
                tmp=tmp/10;

        #if DEBUG
                printf("%d\n",buf[i]);
        #endif
                i++;
        }while(tmp!=0);
        buf[i]='\0';

}
#if 0
void SWAP(char a,char b)
{

	char temp;
        temp=a;
        a=b;
        b=temp;

}
#endif

#define SWAP(a,b)   \
do{		    \
	char temp;  \
        temp=a;     \
        a=b;        \
        b=temp;     \
}while(0)

void reverse(char buf[])
{

	int n;
        //char temp;
        for(n=0;n<i/2;n++)
        {

		if(i>=0)	
		SWAP(buf[n],buf[i-n-1]);
		else
		printf("error!\n");
	}
}


int main(void)
{
	/*int num=0;
	char buf[10];
	int i=0;
	int tmp=0;*/

	printf("please enter a num:\n");
	scanf("%d",&num);
	getval(num,buf);
	reverse(buf);
	printf("string=%s\n",buf);	

	return 0;
}
