	/*
	���ݹ�����
		Ҫ��
	��1���ܶ�ȡָ���Ĵ����ļ����ļ������Ǵ�Ӣ�ġ������Ļ���Ӣ�Ļ�ϵȲ�ͬ��ʽ������������ ����
�ַ������������������֮�䡣
	��2���û�����Ҫ������ַ������Լ�����Ĵ��� n�������ַ������뵽�ļ��� n �����λ���ϣ�
�����ļ����̡�
	��3���û�����ĳ�ַ�����ͳ�Ƹ��ַ������ļ��г��ֵĴ�����
	��4��������Ҫ���������ļ�����Ӣ�ģ������ģ���Ӣ�Ļ�ϡ� 
	*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#define N 100000
void Ch_File();
void Eng_File();
void Ch_En_File();
void menu();
char*readCharact(char*filename);
int substring(char *str,char *str1);
void save(char*filename,char*str1);
char*insert(char*des,char*source,int index);
int main(){
	int n;
	while(1){
		menu();
		printf("���������ѡ��\n");
        setbuf(stdout, NULL);
		scanf("%d",&n);
		switch(n){
			case 1:Eng_File();break;
			case 2:Ch_File();break;
			case 3:Ch_En_File();break;
			case 4:exit(0);
			default: printf("�����������������\n");
                break;
		}
	}
	
    return 0;
	
}
void menu()
{
    printf("             ***********��ӭʹ�����ݹ�����***************\n");
	printf("             *       		1����Ӣ���ļ�      	    *\n");
	printf("             *       		2���������ļ�      	    *\n");
	printf("             *       		3����Ӣ����ļ�            *\n");
	printf("             *       		4���˳�����          		*\n");	
	printf("             ********************************************\n");
}
void Eng_File(){
	char*EngFile = "E:\\design\\Eng.txt";
	char str[N],*str1,*str2,str3[N];//strҪ������ַ���,str1ԭ�����ַ������ļ��ж�ȡ����str2�������ַ���
	str1 = readCharact(EngFile);
	int i=0,n,len,m,count=0;
	srand(time(NULL));
	printf("��������Ҫ������ַ���\n");
	scanf("%s",str);
	printf("��������Ҫ����Ĵ���\n");
	scanf("%d",&n);
	len = strlen(str1);
	int len1 = strlen(str);
	m = rand()%len+1;
	printf("debug:insert\n"); 
	str1 = insert(str1,str,m);
	len = strlen(str1);
	int a[100];//�ҳ��Ƿ������������ĺ��� 
    for (i = 0;  *(str1+i);i++) {
        if(*(str+i)>127) {
            a[count++] = i;
        }
    }
	i=1;
    int j=0;
	while(i<n){
		if(i<count){
			str1 = insert(str1,str,a[j]);
		}else{
            m = rand()%len+1;
			str1 = insert(str1,str,m);
		}
		i++;
        j++;
	}
    str2 = str1;
	printf("this is a test:");
	printf("%s\n", str2);
	printf("str2 end...\n");
	printf("��������Ҫ�������ַ���\n");
	scanf("%s",str3);
	int c;
	c = substring(str2,str3);
	printf("��������ַ���������%d��\n",c);
	save(EngFile,str2);
}
void Ch_File(){
	srand(time(NULL));
	char*ChFile = "E:\\design\\Ch.txt";
	char str[N],*str1,*str2;
	str1 = readCharact(ChFile); 
	int i=0,n,len,m,count=0;
	printf("��������Ҫ������ַ���\n");
	scanf("%s",str);
	printf("��������Ҫ����Ĵ���\n");
	scanf("%d",&n);
	len = strlen(str1);
	int a[100];//�ҳ��������������ĺ��ֵ��±� 
    for (i = 0;  *(str1+i);i++) {
        if(*(str1+i)>127) {
            a[count++] = i;
        }
    }
	i=0;
    int j = 0;
	m = rand()%len+1;
    while(i<n){
        if(i<count){
            str1 = insert(str1,str,a[j]);
        }else{
            m = rand()%len+1;
            str1 = insert(str1,str,m);
        }
        i++;
        j++;
    }
    printf("this is a test:");
    printf("%s\n", str1);
    printf("str1 end...\n");
	printf("��������Ҫ�������ַ���\n");
	scanf("%s",str2);
	int c;
	c = substring(str1,str2);
	printf("��������ַ���������%d��\n",c);
	save(ChFile,str1);
	
}
void Ch_En_File(){
	char*ChEnFile = "E:\\design\\Ch_En.txt";
    char str[N],*str1,*str2;
    str1 = readCharact(ChEnFile);
    int i=0,n,len,m,count=0;
    printf("��������Ҫ������ַ���\n");
    scanf("%s",str);
    printf("��������Ҫ����Ĵ���\n");
    scanf("%d",&n);
    len = strlen(str1);
    int a[100];//�ҳ��������������ĺ��ֵ��±�
    for (i = 0;  *(str1+i);i++) {
        if(*(str1+i)>127) {
            a[count++] = i;
        }
    }
    i=0;
    int j = 0;
    m = rand()%len+1;
    while(i<n){
        if(i<count){
            str1 = insert(str1,str,a[j]);
        }else{
            m = rand()%len+1;
            str1 = insert(str1,str,m);
        }
        i++;
        j++;
    }
    printf("this is a test:");
    printf("%s\n", str1);
    printf("str1 end...\n");
    printf("��������Ҫ�������ַ���\n");
    scanf("%s",str2);
    int c;
    c = substring(str1,str2);
    printf("��������ַ���������%d��\n",c);
    save(ChEnFile,str1);

}
char *readCharact(char*filename)//��ĳ�ļ��ж����ַ��������ļ��ַ��洢��string��
{
	int i=0;
	char *string;
	string=(char*)malloc(sizeof(char)*N);
	FILE*fp=fopen(filename,"r");
	if(!fp)
	{
		printf("open failed!\n");
		exit(0);
	}
	while(!feof(fp)){
		
		fscanf(fp,"%c",string+i);
		i++;
	}
	*(string+i-1)='\0';//!!!!�ַ�����β��'\0'
	fclose(fp);
	return string;
}
void save(char*filename,char*str1){
	FILE*fp = fopen(filename,"w");
 	if(fp==NULL){ 
		printf("open failed!\n"); 
    	exit(0); //�ر������ļ����˳����򣬷��ز���ϵͳ
 	}
     fprintf(fp,"%s",str1);
     fclose(fp);
}
int substring(char *str,char *str1){
    int x=0;
    char *p;//���⸽����ʼֵ
    do{
        p=strstr(str,str1);//1.pָ��ָ��strstr�ķ���ֵ��3.��һ��ѭ���� ���ﺯ���Ĳ��������仯��p����ָ��strstr����ֵ�����ѭ����
        if(p != NULL) {
            str=p+1;//2.strͬ��ָ��strstr����ֵp����һ����ַ��
            x=x+1;
        }
    }
    while(p!=NULL);
    return x;

}
char*insert(char*des,char*source,int index){
	char*str;
    str=(char*)malloc(sizeof(char)*N);
	int len = strlen(des);
	int i;
	int j = index;
	for(i= 0;i<len;i++,j++){
		*(str+i) = *(des + j);
	}
	*(str + i) = '\0';
	for(i=0,j=index;i<strlen(source);i++,j++){
		*(des + j) = *(source + i);
	}
	for(i=0;i<strlen(str);i++,j++){
		*(des + j) = *(str + i);
	}
    *(des + j) = '\0';
	return des;
}

