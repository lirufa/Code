/******************************************************
**Copyright(C),2014-2016,Zhejiang University
** 文 件 名: count_words.c
** 创 建 人: lirufa
** 联系方式：137-9853-0246（tel）645926170(qq)
** 版    本：V1.0:WQ
** 完成日期: 年月日
** 描    述: count words in file
******************************************************/
/******************************************************
** 函数名称：
** 函数功能：
** 返 回 值：
** 特殊说明：
*******************************************************/
#include<stdio.h>
char c;

int input_value(char c)
{   
    int input_1=0;
    if( c==' ' )
    {
	input_1=0;
    }
    else
	input_1=1;
    
    return input_1;
}

void act_print(void)
{
    printf("%c",c);
}

void act_null(void)
{
    return ;
}

int state_table[3][2]=
{
    {2,1},
    {0,1},
    {2,1}
};

typedef void (*PF)(void);
PF act_table[3][2]=
{
    {act_null,act_print},
    {act_print,act_print},
    {act_null,act_print}
};

void main()
{
    //char s1[]=" This    is my world. And I love my    world.n  /*a//";
      //input    01111000011011011111101110101111011000011111110011111  (-1)
    //state(2)  021111022211011011111101110101111011022211111010211111
    //state input2   new state
    //0 0->2 do nothing
    //0 1->1
    //1 1->1
    //1 0->0
    //2 0->2
    //2 1->1

    //input have nothing to do with state.
    int state=0;
    int input=0;
    int counter=0;
    int counter2=0;
    //printf("s1=%s\n",s1);
    int i=0;
    int temp=0;
    while(1)
    {	
	c=getchar();
	void (*pf)(void);

	input=input_value(c);
	if(c==EOF)
	    break;
	
	pf=act_table[state][input];
	pf();
	state=state_table[state][input];
#if 0
	if(state==0 && input==0)
	{
	    state=2;
	    act_null();
    	}
	else if(state==0 && input==1)
	{
	     state=1;
	     act_print();
	     //printf("%c",c);
	}
	else if(state==1 && input==1)
	{
	    state=1;
	    act_print();
	    //printf("%c",c);
	}
	
	else if(state==1 && input==0)//pos_state must ahead or at the begin: 1 1
	{
	    state=0;
	    act_print();//make char c a global var
	    //printf("%c",c);
	}
	else if(state==2 && input==0)
	{
	    state=2;
	    act_null;
    	}
	else if(state==2 && input==1)
	{
	    state=1;   
	    act_print();
	    //printf("%c",c);
    	}
#endif
    }
    return ;
}


