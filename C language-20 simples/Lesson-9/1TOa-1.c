#include<stdio.h>

int num=0;
char buf[10];
int i=0;
int tmp=0;
/*char reverse(int i);
{

int n;
        char temp;
        for(n=0;n<i/2;n++)
        {
                //char temp;
                temp=buf[n];
                buf[n]=buf[i-n-1];
                buf[i-n-1]=temp;
        }
}*/


void getval(int num)
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

char reverse(int i);
{

int n;
        char temp;
        for(n=0;n<i/2;n++)
        {
                //char temp;
                temp=buf[n];
                buf[n]=buf[i-n-1];
                buf[i-n-1]=temp;
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
	getval(num);
	reverse(i);
	printf("string=%s\n",buf);	

	return 0;
}
