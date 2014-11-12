#include<stdio.h>
#include<math.h>
typedef struct point POINT;


/**/POINT
{
        float x;
        float y;
};
//typedef struct point POINT;
float calculate(POINT p1,POINT p2)
{	
        float dx=p1.x-p2.x;
        float dy=p1.y-p2.y;
	float distance=0;
        distance=sqrt(dx*dx+dy*dy);

	return distance;
}

void main(void)
{
	printf("define a struct data named point\n");
	
/*	struct point
	{
		float x;
		float y;
	};
*/
	POINT point_1;
	POINT point_2;
	printf("please enter a value of point1.x and point_1.y\n");
	scanf("%f %f", &point_1.x, &point_1.y);
        printf("please enter a value of point_2.x and point_2.y\n");
	scanf("%f %f", &point_2.x, &point_2.y);
/*	point_1.x=1;
	point_1.y=2;
	point_2.x=2.5;
	point_2.y=3.5;
*/
//      struct point point_1={1,2};
//      struct point point_2={4,5};
	printf("point_1.x=%f,point_1.y=%f\n",point_1.x,point_1.y);	
        printf("point_2.x=%f,point_2.y=%f\n",point_2.x,point_2.y);            

//	printf("%p,%p,%p,%p\n",&point_1.x,&point_1.y,&point_2.x,&point_2.y);
//	printf("the sizeof int,char,float =%d,%d,%d,%d,%d\n",sizeof(int),sizeof(char),sizeof(float),sizeof(double),sizeof(struct point));
	
	float distance=0;
	distance = calculate(point_1,point_2);	
	printf("the distance between P1&P2=%f\n",distance);
	
	return;
}
