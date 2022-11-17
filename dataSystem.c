#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>        //ͷ�ļ�time�����ڻ�ȡ��ǰʱ��; 

struct tm *localtp;

int leap(int year);
int qiuhe(int year,int month);
void shibiePrint(int sum,int year,int month);
void prtAllyear();//����1
void prtMonth();//����2 
void Menu();
void timenows();
void error(); 
int isFestival(int month,int day);
int whatday(int y, int m, int d);
 
int year,month,day,he;

int run[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int ping[12]={31,28,31,30,31,30,31,31,30,31,30,31};
char weekday[7][10]={"һ","��","��","��","��","��","��"};
char months[13][15]={"","һ��","����","����","����","����","����","����",
                        "����","����","ʮ��","ʮһ��","ʮ����"};
//�ж������ƽ��
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
        /*ͨ��switch�ﵽѡ��ͬ���ܵ�Ч��*/
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
/*���˵�����*/ 
void Menu()    
{
    printf("-------------------------------------\n");
    printf("|         1)  ȫ������              |\n");
    printf("|         2)  ��������              |\n");
    printf("|         3)  �鿴��������        |\n");
    printf("|         0)  �˳�����              |\n");
    printf("-------------------------------------\n");
}
/*����1��ʵ��*/ 
void prtAllyear(){
	printf("\t��ӡ������\n");
    printf("��������Ҫ��ӡ����ݣ�\n");
    scanf("%d",&year);
	int i;
	for(i=1;i<=12;i++){
		he = qiuhe(year,i);//���ú������
		shibiePrint(he,year,i);//������Ӧ��ʶ�𣬲����
	}
	system("pause");
    system("cls");
}
/*
	����2��ʵ��
*/
void prtMonth(){
	printf("\t��ӡ����������\n");
    printf("��������Ҫ��ӡ�����·ݣ�\n");
    scanf("%d %d",&year,&month);
	he = qiuhe(year,month);
	shibiePrint(he,year,month);
	system("pause");
    system("cls");
} 
/*
	����3��ʵ��	
*/
void timenows(){
	time_t now,t1;
	int num,nums,n; 
	printf("��������Ҫ��ѯ�����ڣ�\n");
    t1=time(&now);            //����ͨ��ͷ�ļ�time.h��ȡ��ǰʱ��ֵ; 
    scanf("%d %d %d",&year,&month,&day);
    
    num=qiuhe(year,month);      
	num+=day;  //ͳ��Ŀ���������; 

    localtp = localtime(&now);        //ͨ��localtimeת��Ϊ����ʱ��; 
    printf("�������ں�ʱ���ǣ�          %d��%d��%d��%d:%d:%d\n",localtp->tm_year+1900,
            localtp->tm_mon+1,localtp->tm_mday,localtp->tm_hour,localtp->tm_min,
            localtp->tm_sec);
    
    /*����ĺ������������һ���ģ�����ʵ�β�ͬ,
    ��Ϊ���㷽ʽһ�������Բ���ͬһ����������ߴ���������*/        
    nums=qiuhe(localtp->tm_year+1900,localtp->tm_mon+1);
    nums+=localtp->tm_mday;
    
    if(num>nums){
        n=num-nums;
        printf("������컹��%d��\n",n);
    }    
    else{
        n=nums-num;
        printf("��������ѹ�ȥ%d��\n",n);
    }
    int week,flag=0;
    week = whatday(year,month,day);
    printf("��һ��������%d\n",week);
   	
    flag = isFestival(month,day);
    if(flag==1){
    	printf("��һ���ǹ�������\n");
	}else{
		printf("��һ�첻�ǹ�������\n");
	}
	system("pause");
    system("cls");
}
/*������ָ����������ʾ*/
void error()            
{
    printf("������󣡣�������������\n");
    
    system("pause");
    system("cls"); 
}
/*�жϸ�����Ϊ���ڼ�*/ 
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
	�ж��Ƿ�Ϊ�������� 
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
	��0001 1 1��year��month�µĺ� 
*/
int qiuhe(int year,int month)
{
	//0001 01 01 ����һ
	int i,sum=0;
	for(i=1;i<year;i++)
	{
		int m;//������ǩ�����껹��ƽ��  m==1,��������
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
	//���·ݵ�����
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
	yushu=sum%7;//�õ������������Ȼ���ں�һ���·��ÿո��ʾ����
	for(i=0;i<yushu;i++)
		printf("          ");//����ո�
	temp=7-yushu;
	if(leap(year)==1)
	{
		for(i=1;i<=run[month-1];i++)//��ӡ31��
		{
			printf("%10d",i);
		if(i==temp||(i-temp)%7==0)
			printf("\n");
		}
		printf("\n");
	}
	else
	{
		for(i=1;i<=ping[month-1];i++)//��ӡ30��
		{
			printf("%10d",i);
		if(i==temp||(i-temp)%7==0)
			printf("\n");
		}
		printf("\n");
	}
}
