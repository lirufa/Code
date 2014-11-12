#include<stdio.h>

/*prove the difference between struct and union*/
struct end
{
	int n;
	char test[4];
};

union begin
{
	int n;
	char test[4];
};

typedef struct end end_t;
typedef union begin begin_t;

void main(void)
{
	char n[10];
	//int a=480122;//way1:use char type to read int type
	long int b=0x01234567;
 	begin_t t;
	t.n=b;	
	
	printf("the add of begin_t=0x%x\n and the add of t.test[0]=0x%x\n",&t,&t.test[0]);
	printf("t.test[0]=%x\n",t.test[0]);
	if(t.test[0]==0x67)
		printf("is little end\n");

	//printf("the sizeof end_t=%d, the sizeof begin_t=%d\n",sizeof(struct end),sizeof(union begin));
	//printf("%c\n",a);
	printf("please enter a array:\n");
	//printf("&a=%p,&b=%p\n",&a,&b);
	//printf("the sizeof long int=%d\n",sizeof(long int));

 	return ;

}
