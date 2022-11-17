#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>        //头文件time，用于获取当前时间; 

struct tm *localtp;

int leap(int year);
int qiuhe(int year,int month);
void shibiePrint(int sum,int year,int month);
void prtAllyear();//功能1
void prtMonth();//功能2 
void Menu();
void timenows();
void error(); 
int isFestival(int month,int day);
int whatday(int y, int m, int d);
 
int year,month,day,he;

int run[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int ping[12]={31,28,31,30,31,30,31,31,30,31,30,31};
char weekday[7][10]={"一","二","三","四","五","六","天"};
char months[13][15]={"","一月","二月","三月","四月","五月","六月","七月",
                        "八月","九月","十月","十一月","十二月"};
//判断闰年和平年
int leap(int year)
{		
	int four , hundred , fourhundred;
  	four = year % 4;
	hundred = year % 100;
	fourhundred = year % 400;
	if (four == 0 && hundred == 0 && fourhundred == 0)
		return 1;
	else if (four == 0 && hundred != 0 && fourhundred != 0)
	 	return 1;
	else 
		return 0;
}
int main(int argc, char *argv[])
{
    int num;
    system("color 0a"); 
    while(1)
    {     Menu();
        scanf("%d",&num);
        system("cls");
        /*通过switch达到选择不同功能的效果*/
        switch(num)
        {
            case 0: exit(0);
            case 1: prtAllyear();break;
            case 2: prtMonth();break;
            case 3: timenows();break;
            default :error(); break;
        }
    }
    
    system("pause");
    

    return 0;
}
/*主菜单界面*/ 
void Menu()    
{
    printf("-------------------------------------\n");
    printf("|         1)  全年月历              |\n");
    printf("|         2)  本月月历              |\n");
    printf("|         3)  查看距今多少天        |\n");
    printf("|         0)  退出程序              |\n");
    printf("-------------------------------------\n");
}
/*功能1的实现*/ 
void prtAllyear(){
	printf("\t打印月历表：\n");
    printf("请输入您要打印的年份：\n");
    scanf("%d",&year);
	int i;
	for(i=1;i<=12;i++){
		he = qiuhe(year,i);//调用函数求和
		shibiePrint(he,year,i);//进行相应的识别，并输出
	}
	system("pause");
    system("cls");
}
/*
	功能2的实现
*/
void prtMonth(){
	printf("\t打印本月日历表：\n");
    printf("请输入您要打印的年月份：\n");
    scanf("%d %d",&year,&month);
	he = qiuhe(year,month);
	shibiePrint(he,year,month);
	system("pause");
    system("cls");
} 
/*
	功能3的实现	
*/
void timenows(){
	time_t now,t1;
	int num,nums,n; 
	printf("请输入您要查询的日期：\n");
    t1=time(&now);            //这里通过头文件time.h获取当前时间值; 
    scanf("%d %d %d",&year,&month,&day);
    
    num=qiuhe(year,month);      
	num+=day;  //统计目标年份天数; 

    localtp = localtime(&now);        //通过localtime转换为本地时间; 
    printf("现在日期和时间是：          %d年%d月%d日%d:%d:%d\n",localtp->tm_year+1900,
            localtp->tm_mon+1,localtp->tm_mday,localtp->tm_hour,localtp->tm_min,
            localtp->tm_sec);
    
    /*这里的函数跟上面的是一样的，但是实参不同,
    因为计算方式一样，所以采用同一个函数，提高代码利用率*/        
    nums=qiuhe(localtp->tm_year+1900,localtp->tm_mon+1);
    nums+=localtp->tm_mday;
    
    if(num>nums){
        n=num-nums;
        printf("距离今天还有%d天\n",n);
    }    
    else{
        n=nums-num;
        printf("距离今天已过去%d天\n",n);
    }
    int week,flag=0;
    week = whatday(year,month,day);
    printf("这一天是星期%d\n",week);
   	
    flag = isFestival(month,day);
    if(flag==1){
    	printf("这一天是公历节日\n");
	}else{
		printf("这一天不是公历节日\n");
	}
	system("pause");
    system("cls");
}
/*对输入指令错误进行提示*/
void error()            
{
    printf("输入错误！！！请重新输入\n");
    
    system("pause");
    system("cls"); 
}
/*判断该日期为星期几*/ 
int whatday(int y, int m, int d)
{
    int ans;
    if(m == 1 || m == 2) m += 12, y--;
    if((y < 1752) || (y == 1752 && m < 9) || (y == 1752 && m == 9 && d < 3))
        ans = (d + 2*m + 3*(m + 1) / 5 + y + y/4 + 5) % 7 + 1;
    else 
        ans = (d + 2*m + 3*(m + 1) / 5 + y + y/4 - y/100 + y/400) % 7 + 1;
    return ans;
}

/*
	判断是否为公历节日 
*/
int isFestival(int month,int day){
	switch(month){
		case 1:
			if(day==1)
				return 1;
			break;
		case 2:
			if(day==14)
				return 1;
			break;
		case 3:
			if(day==8||day==12)
				return 1;
			break;
		case 4:
			if(day==1) 
				return 1;
			break;
		case 5:
			if(day==1||day==4)
				return 1;
			break;
		case 6:
			if(day==1)
				return 1;
			break;
		case 7:
			if(day==1)
				return 1;
			break;
		case 8:
			if(day==1)
				return 1;
			break;
		case 9:
			if(day==10)
				return 1;
			break;
		case 10:
			if(day==1)
				return 1;
			break;
		case 12:
			if(day==25)
				return 1;
			break;
		default:
			return 0;
			break; 
	}
} 
/*
	求0001 1 1到year年month月的和 
*/
int qiuhe(int year,int month)
{
	//0001 01 01 星期一
	int i,sum=0;
	for(i=1;i<year;i++)
	{
		int m;//用来标签是闰年还是平年  m==1,就是闰年
		m=leap(i);
		if(m==1)
		{
			sum=sum+366;
		}
		else
		{
			sum=sum+365;
		}
	}
	//加月份的天数
	for(i=0;i<month-1;i++){
		if(leap(year)==1)
			sum=sum+run[i];
		else
			sum=sum+ping[i];
	}
	return sum;
}
void shibiePrint(int sum,int year,int month)
{
	printf("\n");	
	printf("%s(%d)\n",months[month],year);
	printf("\n"); 
    printf("\n");   
	int yushu,temp,i;
	for(i=0;i<7;i++)
		printf("%10s",weekday[i]);
	printf("\n");
	yushu=sum%7;//得到多余的天数，然后在后一个月份用空格表示出来
	for(i=0;i<yushu;i++)
		printf("          ");//输出空格
	temp=7-yushu;
	if(leap(year)==1)
	{
		for(i=1;i<=run[month-1];i++)//打印31天
		{
			printf("%10d",i);
		if(i==temp||(i-temp)%7==0)
			printf("\n");
		}
		printf("\n");
	}
	else
	{
		for(i=1;i<=ping[month-1];i++)//打印30天
		{
			printf("%10d",i);
		if(i==temp||(i-temp)%7==0)
			printf("\n");
		}
		printf("\n");
	}
}
