/******************************************************
opyright(C),2014-2016,Zhejiang University
** 文 件 名: bitshitf.c
** 创 建 人: lirufa
** 联系方式：137-9853-0246（tel）645926170(qq)
** 版    本：V1.0
** 完成日期: 年月日
** 描    述: findout how many 1 in bitshitf.c
******************************************************/
/******************************************************
** 函数名称：
** 函数功能：fintout how many 1
** 返 回 值：void
** 特殊说明：
*******************************************************/
#include<stdio.h>

void main(void)
{
    int num=0xef;
    printf("the num is 0x%x\n",num);
#if 0
    //way1:1 << 1,then num & (1 << 0),we need to check 32 times
    int i=0,sum=0;
    for (i=0;i<32;i++)
	{
	    if(num&(1<<i))
	    {	
		printf("i=0x%x, bit %d=1\n",1<<i,i);
		sum++;
	    }
	}
    printf("there are %d bit 1\n",sum);
#endif
#if 0
    //shift left 1 bit:*2
    num=num*2;
    printf("the num is 0x%x\n",num);
#endif
#if 0
//way2:直接找最右边的1，循环1的数量的次数，最大32次,check times bases on 1,32 at most
    //0x64=   0110 0100
    //0x64-1= 0110 0011
    //&     = 0110 0000
    //-1    = 0101 1111
    //&     = 0100 0000
    int sum=0;
    while( num )
    {	
	sum++;
	num=num&(num-1);
	printf("num =0x%x\n",num);
    }
    printf("there are %d bit 1\n",sum);
#endif
    //way3:所有1加起来的和，先是2位处理，然后4位处理，然后8位处理，最后16位处理，最多循环5次即可找出所有的1
    //0x64  =1110 1111
    //0x55  =0101 0101
    //&     =0100 0101 //保存了偶数位的1,在每四位的偶数位
    //0x64>>1=0111 0111
    //0x55   =0101 0101
    //&2     =0101 0101//保存了奇数位的1,在每四位的偶数位
    //1+2    =1001 1010
    //0x33   =0011 0011
    //&3     =0001 0010//每4位为单位，把值保存在左边2位的当中
    //>>2    =0010 0110
    //&0x33 4 =0010 0010//每4位为单位，把值保存在左边2位的当中
    //3+4    =0011 0100//
    //0x0f   =0000 1111
    //&5     =0000 0100
    //>>4    =0000 0011
    //&0x0f 6=0000 0011
    //5+6    =0000 0111//最终1的个数
    //8 bit;if 32 bits,m1=0x55 55 55 55,m2=0x33333333,m3=0x0f0f0f0f,m4=0x00ff00ff,m5=0x0000ffff
    int m1=0x55,m2=0x33,m3=0x0f;
    num=(num&m1)+( (num>>1)&m1 );//+ is higher than &
    printf("num=%d(0x%x),m1=0x%x\n",num,num,m1);
    num=(num&m2)+( (num>>2)&m2 );
    printf("num=%d(0x%x),m2=0x%x\n",num,num,m2);
    num=(num&m3)+( (num>>4)&m3 );
    printf("num=%d(0x%x),m3=0x%x\n",num,num,m3);
    
    printf("there are %d bit 1\n",num);
    return ;
}
