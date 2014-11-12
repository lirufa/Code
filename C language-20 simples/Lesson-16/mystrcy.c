#include<stdio.h>
#include<assert.h>
#define CONSTAIN_A_ZERO(N)  1

char *mystrcy3(char *dest,char *src)
{
    char *p=dest;
    int *d= (int *)dest;
    int *s= (int *)src;

    while(1)
    {
	if(!CONSTAIN_A_ZERO(*s))
	{
	    *d=*s;
	    d++;
	    s++;
	    continue;
	}
	dest=(char *)d;//addr? value?
	while(*dest++=*src++);
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
    char s2[16]="hello world";
    //char s3[16]=NULL;--invalid inti
    char *p = NULL;
    //s1=[16]?--need [16],if not ,segment fault
    //s2={"hel..."},s2={'h','e',...}?
    //end of char array\0?-if more than 16 chars,it will just print 16 chars
    
    printf("s2 = %s\n",s2);
    // mystrcy(s1,s2);
    mystrcy3(s1,s2);
    printf("s1 = %s\n",s1);

    return ;
}

