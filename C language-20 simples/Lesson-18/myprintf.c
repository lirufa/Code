#include<stdio.h>
char buf[32];
#if 0 
#define SWAP(a,b)    \
   do { char temp;   \
	temp=a;      \
	a=b;	     \
	b=temp;      \
    }while(0)
#endif
#if 1
#define SWAP(a,b)\
    do\
    {\
      a=(a)+(b);\
      b=(a)-(b);\
      a=(a)-(b);\
      }while(0)
#endif
char reverse(char buf[],int i)
{   
    int j=0;
    for(j=0;j<i/2;j++)
    {
	SWAP(buf[j],buf[i-1-j]);
    }

    return ;
}
char itoa(int base,int val,char buf[])//char *buf
{   
    //1:fulfill decimal and hex first, char string later
    //2:change into char and save in buf[] array
    //3:swap the array element and save in buf[] array
    char tmp[24]="0123456789ABCDE";
    int temp=0;
    int i=0;
    while(val!=0)//if you don't know,fill a '1'first, then change
    {
	    
	temp=val%base;
	buf[i]=tmp[temp];
	val=val/base;
	i++;
    }
    buf[i]='\0';
    reverse(buf,i);
    return ;
}

char myputs(char *buf)
{
    while(*buf)
    {
	putchar(*buf++);
    }
    return ;
}

int myprintf(const char *format,...)
{
    int *p;
    char c;
    p=(int*)&format;
    while( (c=*format++)!='\0' )
    {
	if(c!='%')
	{
	   putchar(c);
	   continue;
	   //printf("%c",c);
	}
	else
	{   
	    int value=0;
	    //char buf[32]="123456789";//will affect the *p
	    c=*format++;
	    if(c=='d')
	    {
		p++;
		value=*p;

		//printf("debug2:*p=%d,value=%d\n",*p,value);
		itoa(10,value,buf);
		//puts(buf);//add a enter automatically
		myputs(buf);
	    }
    	    if(c=='x')
	    {
		p++;
		value=*p;

		//printf("%x",*p);
		itoa(16,value,buf);
		//puts(buf);
		myputs(buf);
	    }
	    if(c=='c')
	    {
		p++;
		value=*p;

		//printf("%c",*p);
		//itoa(10,value,buf);
		//puts(buf);
		putchar(*p);
	    }
	    if(c=='s')
	    {
		p++;
		value=*p;
		
		//printf("%s",(char *)*p);
		//printf("%c\n",*p);//fail,not as s1[1]
		//printf("%s",*p);//fail,not as 's1'
		myputs( (char*) value);
	/*	while(1)
		{
		   //putchar( value );
		    putchar( (char*)value );
		    value++;
		    putchar( (char*)value );
		    //putchar( *p );
		    value++;
		    putchar( value );
		    //putchar( *p );
		    break;
		    //puts(p);
		}
	*/
	    }

	}    
    }
    printf("\n");
/*
    printf("&p=%x\n",&p);
    //printf("p=%x\n",p);
    printf("*p=%d\n",*p);
    p++;
    printf("&p=%x\n",&p);
    //printf("p=%x\n",p);
    printf("*p=%d\n",*p);
    p++;
    printf("&p=%x\n",&p);
    //printf("p=%x\n",p);
    printf("*p=%d\n",*p);
*/
    return 0;

}

void main(void)
{
    char a='a';
    int b=100;
    char s1[]="hello world";

myprintf("<Testing myprintf: 100:(10)=%d,(16)=%x,(c)=%c,(s)=%s>\n",12345,200,a,"hello");
    myprintf("<Testing myprintf: 100:(10)=%d,(16)=%x,(c)=%c,(s)=%s>\n",100,b,a,s1);

    return ;
}
