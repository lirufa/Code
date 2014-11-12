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
int input_value(char *p)
{   
    int input_1=0;
    if( (*p>='a' && *p<='z') || (*p>='A'&&*p<='Z') )
    {
	input_1=1;
	//printf("debug1:s1[i]=%c, input=%d\n",*p,input_1);
    }
    else
    {
	input_1=0;
//	printf("debug2:s1[i]=%c, input=%d\n",*p,input_1);
    }
    return input_1;
}

void main()
{
    char s1[]=  " This    is my world. And I love my    world.  ";
    //char s1[]=gets();
    //input      01111000011011011111001110101111011000011111000(-1)
    //state     001111   0110110111110011101011110110   111110
    //                   ^  ^  ^     ^    ^ ^    ^  ^        ^
    //state(2)  021111022211011011111021110101111011022211111022
    //state input2   new state
    //0 0->2 do nothing
    //0 1->1
    //1 1->1
    //1 0->0
    //0 0->2
    //2 0->2
    //2 1->1

    //state  input1  newstate
    //0 0->0;
    //0 1->1;
    //1 0->0;
    //1 1->1
    //input have nothing to do with state.
    int state=0;
    int input=0;
    int counter=0;
    int counter2=0;
    printf("s1=%s\n",s1);

    int i=0;
    int temp=0;
    while(1)
    {	
	input=input_value(&s1[i]);
	if(s1[i]=='\0')
	    break;
	//0 0->2
	//0 1->1
	//1 1->1
	//1 0->0
	//2 0->2
	//2 1->1
	if(state==0 && input==0)
	{
	    state=2;
    	}
/*	if(state==0 && input==1)
	{
	    state=1;
	   // temp=s1[i];
	    temp=i;
	    counter2++;
	    printf("debug4:counter2=%d\n",counter2);

	}*/
	else if(state==0 && input==1)
	{
	    state=1;
	     printf("%c",s1[i]);

        /*  int j=0;
	   // printf("debug3:counter2=%d\n",counter2);
	    counter++;
	    for(j=0;j<counter2;j++)
	    {
		printf("%c",s1[temp+j]);
	    }
	    printf("\n");
	    counter2=0;
	*/
	}
	else if(state==1 && input==1)
	{
	    state=1;
	    printf("%c",s1[i]);

	    //counter2++;
	    //printf("debug5:counter2=%d\n",counter2);
	}
	
	else if(state==1 && input==0)//pos_state must ahead or at the begin: 1 1
	{
	    state=0;
	    printf("%c",s1[i]);

	   // temp=s1[i];
	   // temp=i;
	   // counter2++;
	   // printf("debug4:counter2=%d\n",counter2);
	}
	else if(state==2 && input==0)
	{
	    state=2;
    	}
	else if(state==2 && input==1)
	{
	    state=1;
	    printf("%c",s1[i]);
    	}
	i++;
    }
    printf("\n");
   // printf("there are %d words in total.\n",counter);

    return ;
}


