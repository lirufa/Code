/*judge a car number is restricted or not*/
#include<stdio.h>
enum day
{
	MON=1,
	TUE,//equal"TUE=2"
	WED,
	THU,
	FRI,
	SAT,
	SUN
};
int get_last_num(char car_num_str[10])
{
	int i=0,tail_num=0;
	while(car_num_str[i])
	{
		tail_num=car_num_str[i]-'0';
		i++;
		//printf("tail_num is %d\n",tail_num);
	}
	
	return tail_num;
}

int is_restricted(int tail_num,enum day today)
{
	//tail_num:0,1...9
	//0 5,1 6,2 7,3 8,4 9
	int ret=0;
	switch(tail_num)
	{
		case 0:
		case 5:
			ret=(today==MON)?1:0;
			break;
#if 0
			if(today==MON)
			{	ret=1;
				break;
			}
			else
			{	ret=0;
				break;
			}
#endif
		
		case 1:
    	        case 6:
                        if(today==TUE)
                        {       ret=1;
                                break;
			}
			else
			{
			 	ret=0;
				break;
			}
		case 2:
                case 7:
                        if(today==WED)
                       {        ret=1;
                                break;
			}
			else
			{ 	ret=0;
				break;
			}
		case 3:
                case 8:
                      if(today==THU)
                      {     ret=1;
                            break;
		      }
		      else
		      {	    ret=0;
			    break;	
		      }
		case 4:
                case 9:
                     if(today==FRI)
		     {      ret=1;
                            break;
		     }
		     else
		     {	    ret=0;
			    break;
		     }
		default:ret=0;
	}
	return ret;
}

void main(void)
{
	char car_num_str[10]="B12344";
	int tail_num=0,ret=0;
	enum day today=4;//today only get value from 1 to 7	
	
	//scanf("%d",&today);
	printf("please enter the car num char:\n");
	scanf("%s",car_num_str);//input a string for a char string
	printf("car num is %s\n",car_num_str);	

	/*get the last num of car*/
	tail_num=get_last_num(car_num_str);
#if 1
	printf("tail_num=%d\n",tail_num);
#endif
	/*retrun the flat to judge*/
	ret=is_restricted(tail_num,today);
#if 1
	printf("ret=%d\n",ret);
#endif
	if(ret==1)
		printf("this car is restricted today.\n");
	else
		printf("this car is NOT restricted today.\n");

	return;
}
