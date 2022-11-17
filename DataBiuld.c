	/*
	数据构建器
		要求：
	（1）能读取指定的磁盘文件：文件可以是纯英文、纯中文或中英文混合等不同样式。对于中文文 件，
字符串必须插入在两汉字之间。
	（2）用户输入要插入的字符串，以及插入的次数 n。程序将字符串插入到文件的 n 个随机位置上，
并将文件存盘。
	（3）用户输入某字符串，统计该字符串在文件中出现的次数。
	（4）至少需要测试三个文件：纯英文，纯中文，中英文混合。 
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
		printf("请输入你的选项\n");
        setbuf(stdout, NULL);
		scanf("%d",&n);
		switch(n){
			case 1:Eng_File();break;
			case 2:Ch_File();break;
			case 3:Ch_En_File();break;
			case 4:exit(0);
			default: printf("输入错误，请重新输入\n");
                break;
		}
	}
	
    return 0;
	
}
void menu()
{
    printf("             ***********欢迎使用数据构建器***************\n");
	printf("             *       		1、纯英文文件      	    *\n");
	printf("             *       		2、纯中文文件      	    *\n");
	printf("             *       		3、中英混合文件            *\n");
	printf("             *       		4、退出程序          		*\n");	
	printf("             ********************************************\n");
}
void Eng_File(){
	char*EngFile = "E:\\design\\Eng.txt";
	char str[N],*str1,*str2,str3[N];//str要插入的字符串,str1原来的字符串（文件中读取），str2插入后的字符串
	str1 = readCharact(EngFile);
	int i=0,n,len,m,count=0;
	srand(time(NULL));
	printf("请输入你要插入的字符串\n");
	scanf("%s",str);
	printf("请输入你要插入的次数\n");
	scanf("%d",&n);
	len = strlen(str1);
	int len1 = strlen(str);
	m = rand()%len+1;
	printf("debug:insert\n"); 
	str1 = insert(str1,str,m);
	len = strlen(str1);
	int a[100];//找出是否含有两个连续的汉字 
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
	printf("请输入你要搜索的字符串\n");
	scanf("%s",str3);
	int c;
	c = substring(str2,str3);
	printf("你输入的字符串出现了%d次\n",c);
	save(EngFile,str2);
}
void Ch_File(){
	srand(time(NULL));
	char*ChFile = "E:\\design\\Ch.txt";
	char str[N],*str1,*str2;
	str1 = readCharact(ChFile); 
	int i=0,n,len,m,count=0;
	printf("请输入你要插入的字符串\n");
	scanf("%s",str);
	printf("请输入你要插入的次数\n");
	scanf("%d",&n);
	len = strlen(str1);
	int a[100];//找出含有两个连续的汉字的下标 
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
	printf("请输入你要搜索的字符串\n");
	scanf("%s",str2);
	int c;
	c = substring(str1,str2);
	printf("你输入的字符串出现了%d次\n",c);
	save(ChFile,str1);
	
}
void Ch_En_File(){
	char*ChEnFile = "E:\\design\\Ch_En.txt";
    char str[N],*str1,*str2;
    str1 = readCharact(ChEnFile);
    int i=0,n,len,m,count=0;
    printf("请输入你要插入的字符串\n");
    scanf("%s",str);
    printf("请输入你要插入的次数\n");
    scanf("%d",&n);
    len = strlen(str1);
    int a[100];//找出含有两个连续的汉字的下标
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
    printf("请输入你要搜索的字符串\n");
    scanf("%s",str2);
    int c;
    c = substring(str1,str2);
    printf("你输入的字符串出现了%d次\n",c);
    save(ChEnFile,str1);

}
char *readCharact(char*filename)//从某文件中读出字符，读出文件字符存储在string中
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
	*(string+i-1)='\0';//!!!!字符串结尾加'\0'
	fclose(fp);
	return string;
}
void save(char*filename,char*str1){
	FILE*fp = fopen(filename,"w");
 	if(fp==NULL){ 
		printf("open failed!\n"); 
    	exit(0); //关闭所有文件，退出程序，返回操作系统
 	}
     fprintf(fp,"%s",str1);
     fclose(fp);
}
int substring(char *str,char *str1){
    int x=0;
    char *p;//任意附个初始值
    do{
        p=strstr(str,str1);//1.p指针指向strstr的返回值。3.再一次循环到 这里函数的参数发生变化，p重新指向strstr返回值，如此循环。
        if(p != NULL) {
            str=p+1;//2.str同样指向strstr返回值p的下一个地址。
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

