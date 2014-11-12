/*delete the comment of program's*/
#include<stdio.h>

int get_word_type(char c)
{
    if(c=='/')
	return 1;
    if(c=='*')
	return 2;
    if(c=='\n')
	return 3;
    if(c=='\'')
	return 4;
    if(c=='\\')
	return 5;
    return 0;
}
//get new state
int preprocess(char c,int state,int input)
{
    if( state==0 && input==1)
    {
	 state=1;
    }

    else
    if( state==0 && input==4)
    {
	 state=5;
	 putchar(c);
    }
    else
    if( state==5 && input==4)
    {
	 state=0;
	 putchar(c);
    }

    else
    if( state==5 && input==5)
    {
	 state=6;
	 putchar(c);
    }
    else
    if( state==6 && input==4)
    {
	 state=5;
	 putchar(c);
    }
    else
    if( state==6 && input==0)
    {
	 state=5;
	 putchar(c);
    }
    else
    if( state==6 && input==5)
    {
	 state=5;
	 putchar(c);
    }

    else
    if( state==1 && input==1)
    {
	 state=4;
    }
    else
    if( state==4 && input==0) 
    {
	 state=4;
    }
    else
    if( state==4 && input==3)
    {
	 state=0;
    }

    else
    if( state==1 && input==2)
    {
	 state=2;
    }
    else
    if( state==2 && input==0)
    {
	 state=2;
    }
    else
    if( state==2 && input==2)
    {
	 state=3;
    }
    else
    if( state==3 && input==1)
    {
	 state=0;
    }
    else
    if( state==3 && input==0)
    {
	 state=2;
    }
    else
    if( state==0 || state==5)//why?do you know?
    {
	 putchar(c);
    }

    return state;
}

#define debug(fmt, args...)  fprintf(stderr, fmt, ##args)
int main(void)
{   
    //input a file
    char c;
    //char a='\'';
    //printf("c=%c,a=%c\n",c,a);
    int input=0;
    int state=0;
    while(1)
    {
	c=getchar();//just read a char onetime
	if(c==EOF)
	    break;
	
	debug("%c",c);
	input=get_word_type(c);
	state=preprocess(c,state,input);
	debug("  ,input=%d,state=%d\n",input,state);
	//preprocess(state,input);
    }
    
    return 0;
}
