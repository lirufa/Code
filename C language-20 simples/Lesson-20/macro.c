/******************************************************
**Copyright(C),2014-2016,Zhejiang University
** 文 件 名: macro.c
** 创 建 人: lirufa
** 联系方式：137-9853-0246（tel）645926170(qq)
** 版    本：V1.0:WQ
** 完成日期: 年月日
** 描    述: parse the macro difinition
******************************************************/
/******************************************************
** 函数名称：
** 函数功能：
** 返 回 值：
** 特殊说明：
*******************************************************/
#include<stdio.h>
#include<string.h>
//char c; 
//#define debug (ftm,args...)  fprintf(stderr,fmt,##args)
#define debug(fmt, args...)  fprintf(stderr, fmt, ##args)
enum i{i0=0,i1,i2,i3,i4};
int input_value(char *word)
{   
    if( strcmp(word," ")==0 )//word==" "
	return i0;
    else//mutual exclusion
    if( strcmp(word,"\t")==0 )
	return i0;
    else
    if( strcmp(word,"#")==0)
	return i1;
    else
    if( strcmp(word,"define")==0)
	return i2;
    else
    if( strcmp(word,"\n")==0)
	return i4;
    else
	return i3;
}

char buf[64];
char word[64];
char bufword[64];
struct define
{
    char name[64];
    char value[64];
}macro[16];
int counter=0;

//a0-print by a "word", not a char
void act_print_word(void)
{
    int i=0;
   for(i=0;i<counter;i++)
   {
   	if( strcmp(word,macro[i].name)==0 )
	{
	    printf("%s",macro[i].value);
	    return ;
	}
   }
  printf("%s",word);
/*
   if( strcmp(word,name)==0 )
	printf("%s",value);
    else
	printf("%s",word);
*/
   return ;
}
//a1-save to buf for word
void act_save_to_buf(void)
{   
    strcat(buf,word);
   return ;
}
//a2-
void act_print_buf_and_word(void)
{   
    strcat(buf,word);
   // word[]="";
    printf("%s",buf);
   return ;
}
//a3-save anyword(MAX) to buf_word from word
void act_save_word(void)
{
    strcat(bufword, word);
    //word[]="";
    //printf("%c",c);
   return ;
}
//a4-copy anywod of MAX to name[]
void get_macro_name(void)
{
    strcpy(macro[counter].name,bufword);
    debug("%s\n",macro[counter].name);
    //word[]="
    strcpy(bufword,"");
    //printf("%c",c);
   return ;
}
//a5-copy anyword of value to value[];
void get_macro_value(void)
{
    strcpy(macro[counter].value,bufword);
    counter++;
    debug("%s\n",macro[counter].value);
    //word[]="";
    strcpy(bufword,"");
    //printf("%c",c);
   return ;
}
//a6
void act_null(void)
{
    return ;
}

#define a0  act_print_word	//print directly
#define a1  act_save_to_buf
#define a2  act_print_buf_and_word
#define a3  act_save_word      //from buf
#define a4  get_macro_name
#define a5  get_macro_value
#define a6  act_null

typedef void (*PF)(void);
PF act_table[7][5]=
{
    a0,	a1, a0,	a0, a0,
    a2,	a2, a1,	a2, a2,
    a1, a2, a2, a2, a2,
    a1,	a3, a3,	a3, a2,
    a4, a4, a3, a1, a5,
    a6,	a3, a3,	a3, a5,
    a3, a3, a3, a3, a5
};

enum s{s0=0,s1,s2,s3,s4,s5,s6};
int state_table[7][5]=
{
    s0,	s1, s0,	s0, s0,
    s1, s0, s2, s0, s0, //allow "# define",not "##"
    s3, s0, s0, s0, s0,
    s3, s4, s4, s4, s0,
    s5, s5, s5, s5, s0,
    s5,	s6, s6,	s6, s0,
    s6, s6, s6, s6, s0
};

void getword(char *word)
{
    char c;
    c=getchar();
    if(c==EOF)
    {
	*word='\0';
	//*word='';
	return ;
    }
    //if c=#,1,%
    if( !isalpha(c) )
    {
	*word++=c;
	*word='\0';
	return ;
    }
    do//first input c, then judge c
    {
	*word++=c;
	c=getchar();
	//printf("debug1:%s",word);
    }while( isalnum(c) || c=='_');
    // current c is not (isalnum) or '_',give c to stdin
    ungetc(c,stdin);
    *word = '\0';

    return  ;
}

void main()
{
    int state=0;
    int input=0;
    void (*pf)(void);
    //printf("s1=%s\n",s1);
    //int i=0;
    while(1)
    {	
	getword(word);
	input=input_value(word);
	if(strcmp(word,"")==0)
	    break;
	
	pf=act_table[state][input];
	pf();
	state=state_table[state][input];
	debug("word=<%s>,input=%d,state=%d\n",word,input,state);
	//strcpy(word,"");
	//printf("debug2:%s",word);

    }
    return ;
}


