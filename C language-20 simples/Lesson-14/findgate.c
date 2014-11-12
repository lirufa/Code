/*find.c--find a way out in the chessboard*/
#include<stdio.h>
/*define the chessboard size*/
#define ROW 10
#define COL 10
/*define the chessboard*/
int chessboard [ROW][COL];

 /*print the chessbord*/
void print_chessboard(void)
{
          int i=0,j=0;
          for(i=0;i<10;i++)
          {
                 for(j=0;j<10;j++)
                 printf("%2d",chessboard[i][j]);
		 printf("\n");
          }
          
         return;
}  

 /*inti the chessbord*/
void inti_chessboard()
{
	 int i=0,j=0;
	 for(i=0;i<10;i++)
         {
                for(j=0;j<10;j++)
                chessboard[i][j]=rand()%2;
         }
	
	return;
}

struct direction
{
     int dr;
     int dc;
     char name[16];
 };

/*define a struct array with4 element*/
typedef struct direction dir_t;
//dir_t one={1,0}--inti a var
dir_t dir[4]=
{
    {-1,0,"up"},
    {1,0,"down"},
    {0,-1,"left"},
    {0,1,"right"},
};

/*check the input*/
int check(int i,int j)
{
    int ways=0,dx=0,dy=0,m=0;
    for(m=0;m<4;m++)
    {	
	 dx=i+dir[m].dr;
	 dy=j+dir[m].dc;
	 printf("debug1:dx=%d,dy=%d\n",dx,dy);
	if(chessboard[dx][dy]==0)//one dir, like up
	{
	ways++;
	printf("%s is OK\n",dir[m].name);
	}
    }
#if 0    //2
    if( (j==0) && (i==0) )
    {
         //if(chessboard[i-1][j]==0)//check up (-1,0)
           //   ways++;
         if(chessboard[i+1][j]==0)//check down (1,0)
              ways++;
        // if(chessboard[i][j-1]==0)//check left (0,-1)
            //  ways++;
       if(chessboard[i][j+1]==0)//check right (0,1)
           ways++;
    }

    if( (j==9) && (i==0) )
    {	
         // if(chessboard[i-1][j]==0)//check up (-1,0)
             // ways++;
         if(chessboard[i+1][j]==0)//check down (1,0)
              ways++;
         if(chessboard[i][j-1]==0)//check left (0,-1)
              ways++;
      // if(chessboard[i][j+1]==0)//check right (0,1)
         //    ways++;

    }

    if( (j==0) && (i==9) )
     {
	printf("11 %d\n",ways);
	if(chessboard[i-1][j]==0)//check up (-1,0)
           ways++;
       // if(chessboard[i+1][j]==0)//check down (1,0)
          // ways++;
       // if(chessboard[i][j-1]==0)//check left (0,-1)
          // ways++;
        if(chessboard[i][j+1]==0)//check right (0,1)
            ways++;
	printf("22 %d\n",ways);
     }

    if( (j==9) && (i==9) )
    {
        if(chessboard[i-1][j]==0)//check up (-1,0)
              ways++;
        //if(chessboard[i+1][j]==0)//check down (1,0)
              //ways++;
        if(chessboard[i][j-1]==0)//check left (0,-1)
              ways++;
     // if(chessboard[i][j+1]==0)//check right (0,1)
        //    ways++;
    }

    //3
    if( (i==0) && (0<j&&j<9) )//
    {
	//if(chessboard[i-1][j]==0)//check up (-1,0)
          // ways++;
        if(chessboard[i+1][j]==0)//check down (1,0)
           ways++;
        if(chessboard[i][j-1]==0)//check left (0,-1)
           ways++;
        if(chessboard[i][j+1]==0)//check right (0,1)
           ways++;
    }
    if( (i==9) && (0<j&&j<9) )
    {
	if(chessboard[i-1][j]==0)//check up (-1,0)
	    ways++;
	//if(chessboard[i+1][j]==0)//check down (1,0)
	  //  ways++;
	if(chessboard[i][j-1]==0)//check left (0,-1)
            ways++;
	if(chessboard[i][j+1]==0)//check right (0,1)
	    ways++;
    }
    if( (j==0) && (0<i&&i<9) )
    {
        if(chessboard[i-1][j]==0)//check up (-1,0)
            ways++;
        if(chessboard[i+1][j]==0)//check down (1,0)
            ways++;
        //if(chessboard[i][j-1]==0)//check left (0,-1)
           // ways++;
        if(chessboard[i][j+1]==0)//check right (0,1)
            ways++;
    }
    if( (j==9) && (0<i&&i<9) )
    {
	 if(chessboard[i-1][j]==0)//check up (-1,0)
	      ways++;
         if(chessboard[i+1][j]==0)//check down (1,0)
              ways++;
         if(chessboard[i][j-1]==0)//check left (0,-1)
              ways++;
        // if(chessboard[i][j+1]==0)//check right (0,1)
          //    ways++;
    }
    
    //4
    if( (i>0&&i<9) && (j>0&&j<9))
    {
	if(chessboard[i-1][j]==0)//check up (-1,0)
	    ways++;
        if(chessboard[i+1][j]==0)//check down (1,0)
	    ways++;
        if(chessboard[i][j-1]==0)//check left (0,-1)
	    ways++;
        if(chessboard[i][j+1]==0)//check right (0,1)
            ways++;
    }
    //printf("33%d\n",ways);
#endif
    return ways;

}

#if 0
struct directions dirs[4]
{
    struct direction up=(-1,0,"up");
    struct direction down=(-1,0,"down");
    struct direction left=(-1,0,"left");
    struct direction right=(-1,0,"right");
};
#endif

void main(void)
{	
	int i=0,j=0;	
	printf("first print a int array\n");
	
	/*print the chessbord*/
	print_chessboard();
#if 0
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
			printf("%2d",chessboard[i][j]);
		printf("\n");
	}
#endif	
	/*inti and print the chessboard*/
	inti_chessboard();

	printf("\n\n");
	print_chessboard();
	
	char flag;
	printf("Please enter any key except 'p'\n");
	while( (flag=getchar())!='q' )
	{
	    int ret=0;
	    printf("Please input the ROW and COL value,enter 'q'to quit\n");
	    scanf("%d %d",&i,&j);//no comma
	    printf("ROW=%d,COL=%d\n",i,j);
	    /*check the ROW and COL in the chessboard:i=(0,9),j=(0,9)*/
	    // check_value(i,j);
	    if( !(i>=0&&i<=9&&j>=0&&j<=9)  )
	     {
                 printf("please enter effective value\n");
	         continue;
	     }
#if 0	    
	    if( (i<0) || (i>9) || (j<0) || (j>9) )
	    {
		printf("please enter effective value\n");
		continue;
	    }
#endif	    
	    /*check whether there is a way for [i][j],and return a value*/
	    ret=check(i,j);//ret:0-4
	    if(ret==0)
		printf("There is no way.\n");
	    else
		printf("Yes,there are %d ways!\n",ret);

	}

	return;
}
