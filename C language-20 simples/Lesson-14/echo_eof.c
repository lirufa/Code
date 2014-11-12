#include<stdio.h>
int main(void)
{
    int ch;
    
    while( ( ch=getchar() )!='\n' )//!=EOF
	putchar(ch);

    return 0;
}
