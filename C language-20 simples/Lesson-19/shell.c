/******************************************************
**Copyright(C),2014-2016,GDUT University
** 文 件 名: shell.c
** 创 建 人: lirufa
** 联系方式：137-9853-0246（tel）645926170(qq)
** 版    本：V1.0
** 完成日期: 年月日
** 描    述: This program is for parsr the command
******************************************************/
/******************************************************
** 函数名称：
** 函数功能：
** 返 回 值：
** 特殊说明：
*******************************************************/
#include<stdio.h>
int (*pf)(int ,int );

int powr(int a,int b)
{
    int i=0;
    int sum=1;
    for(i=1;i<=b;i++)
    {	
	sum*=a;
	//sum=sum*a;
    }
    return sum;
}
int add(int a,int b)
{
    return a+b;
}
int sub(int a,int b)
{
    return a-b;
}
int mul(int a,int b)
{
    return a*b;
}
int div(int a,int b)
{
    if(b==0)
	return 0;
    return a/b;
}
int math_main(int argc, char *argv[],char c)
{
    int a=0,b=0;
    int result=0;
    a=atoi(argv[1]);
    b=atoi(argv[2]);
    
    //result=add(a,b);
    //result=sub(a,b);
    result=pf(a,b);
    printf("%d %c %d=%d\n",a,c,b,result);

    return ;
}
#if 0
int add_main(int argc, char *argv[])
{
    int a=0,b=0;
    a=atoi(argv[1]);
    b=atoi(argv[2]);

    printf("%d+%d=%d\n",a,b,a+b);

    return ;
}

int sub_main(int argc, char *argv[])
{
    int a=0,b=0;
    a=atoi(argv[1]);
    b=atoi(argv[2]);

    printf("%d-%d=%d\n",a,b,a-b);

    return 0;
}
#endif
struct opt
{
    char name[8];
    int (*pf)(int,int);
    char c;

}op[]={
	{"powr",powr,'^'},
	{"add",add,'+'},
	{"sub",sub,'-'},
	{"mul",mul,'*'},
	{"div",div,'/'},//add more you can
    };

int command_do(int argc, char *argv[])
{
    if(argc<3)
    {
	printf("the argc=%d is few, please input again\n",argc);
	//continue;//must in a loop
	return 0;
    }
#if 0
    if(strcmp(argv[0],"add")==0)
	pf=add;
	//add_main(argc,argv);
    if(strcmp(argv[0],"sub")==0)
	pf=sub;
	//sub_main(argc,argv);
#endif
    int m=0;
    char symbol;
    for(m=0;m<sizeof(op)/sizeof(op[0]);m++)
    {	printf("m=%d\n",m);
	if( strcmp(argv[0],op[m].name)==0 )
	{    
	    pf=op[m].pf;
	    symbol=op[m].c;
	    break;
	}
    }
    math_main(argc,argv,symbol);
    return 0;
}

void shell_parse(char *buf)
{
    int argc=0;
    int state=0;
    char *argv[8];
    //state machine
    //state input newstate
    //0 ' ' 0  //"  a
    //0 a   1  //"a
    //1 b   1  //"ab
    //1 ' ' 0  //"ab "

    while(*buf)//c!='\0'
    {
	char c=*buf;
	if(state==0 && c==' ')
	{
	    state=0;
	}
	else 
	if(state==0 && c!=' ')//if just char and space and '\n' and '\0',no others symbols
	{
	    state=1;
	    argv[argc++]=buf;
	}
	else 
	if(state==1 && c!=' ')
	{
	    state=1;
	}
	else 
	if(state==1 && c==' ')
	{
	    state=0;
	    *buf='\0';//find a element's end
	}
	if(*buf=='\n')
	    *buf='\0';
	buf++;
    }
    
    int i=0;
    printf("argc=%d\n",argc);
    for(i=0;i<argc;i++)
    {
	printf("argv[%d] = %s\n",i,argv[i]);    
    }
    command_do(argc,argv); 

    return ;
}

void main(int argc, char * argv[])
{
    printf("output the demo argc and argv\n");
    printf("argc=%d\n",argc);

    int i=0;
    char buf[32];
#if 0
    for(i=0;i<argc;i++)
    {
	printf("argv[%d] = %s\n",i,argv[i]);    
    }
#endif
    while(1)//ctrl-c quit
    {
	printf("NCCL#");
	//scanf("%s\n",buf);//will stop at first ' ','\n','\tab'
	//gets(buf);//don't compare the array length
	fgets(buf,16,stdin);
	puts(buf);
	//parse the buf[]
	shell_parse(buf);
    }
    return ;
}
