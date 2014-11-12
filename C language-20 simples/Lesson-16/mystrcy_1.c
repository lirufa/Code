#include<stdio.h>
#include<assert.h>
#define CONSTAIN_A_ZERO(n) ( (n-0x01010101)&(~n)&(0x80808080) )

#define TEST(n) (n-1)&(~n)&0x80

char *mystrcy3(char *dest,char *src)
{
    char *p=dest;
    int *d= (int *)dest;
    int *s= (int *)src;

    while(1)
    {
	//if(1)
	if( ! ( CONSTAIN_A_ZERO(*s) ) )//just a char is \0,it will false.this fun is just for deal with the end is \0, not between the array with a \0
	{
	    *d=*s;
	    //printf("3)d=%s\n",(char *)d);
	    printf("*d=%x\n",*d);
	    d++;
	    s++;
	    continue;
	}
	src=(char *)s;
	dest=(char *)d;//addr? value?
	//printf("1) s1=%s,d=%s\n",dest,(char *)d);
	while(*dest++=*src++);
	//printf("2) s1=%s,src=%s\n",dest,src);
	break;
    }
    return p;
}

char *mystrcy(char *dest,char *src)
{
    char *p=dest;
#if 0
    if(dest==NULL || src==NULL)
    {
	printf("enter not NULL array\n");
	//continue;--not invalid, must in a loop
	return dest;
    }
#endif
    assert(dest!=NULL && src!=NULL);
    //way1
    //while(*dest++ = *src++);//when the last char of '\0',= fisr, then deal with while, then ++
  //if dest is NULL, serious problem,segment fault,write src random addr
    //way2:
    int delta=dest-src;
    while( *( (char*)(src+delta) ) = *src++ );
    return dest;//the last dest after many ++?
}

void main(void)
{
    char s1[16];
    char s2[16]="hello12world";
    //char s3[16]=NULL;--invalid inti
    char *p = NULL;
    //s1=[16]?--need [16],if not ,segment fault
    //s2={"hel..."},s2={'h','e',...}?
    //end of char array\0?-if more than 16 chars,it will just print 16 chars
#if 0
    int n;
    for(n=0x00;n<=0xff;n++)
    {
	printf("char n is 0x%x, and TEST(n)=0x%x\n",n,TEST(n));
    }
#endif
    printf("s2 = %s,s1=%s\n",s2,s1);
    // mystrcy(s1,s2);
    mystrcy3(s1,s2);
    printf("s2=%s,s1 = %s\n",s2,s1);

    return ;
}

