#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void bin();
void oct();
void dec();
void hex();
void Menu();
void secMenu();
void dec_bin(int n);
void dec_oct(int n);
void dec_hex(int n);
int bin_dec(char*s);
int oct_dec(char*s);
int hex_dec(char*hex);

int main(){
    int n;
    while(1){
        Menu();
        printf("Enter the choice you want to ��");
        scanf("%d",&n);
        system("cls");
        switch(n){
            case 1:
                bin();
                break;
            case 2:
                oct();
                break;
            case 3:
                dec();
                break;
            case 4:
                hex();
                break;
        }

    }
    return 0;
}
void bin(){
    char bin[10];
    int decNum,n;
    printf("�������������\n");
    scanf("%s",bin);
    system("cls");
    decNum = bin_dec(bin);
    while(1){

        secMenu();
        printf("���������ѡ��\n");
        scanf("%d",&n);
        system("cls");
        switch(n){
            case 1:
                dec_bin(decNum);
                break;
            case 2:
                dec_oct(decNum);
                break;
            case 3:
                printf("\nת��Ϊʮ������Ϊ:%d\n\n",decNum);
                break;
            case 4:
                dec_hex(decNum);
                break;
            case 5:
                return ;
            case 6:
                exit(0);
        }

    }
}
void oct(){
    char oct[10];
    int decNum,n;
    printf("������һ���˽�����:");
    scanf("%s",oct);
    system("cls");
    decNum = oct_dec(oct);
    while(1){
        secMenu();
        printf("���������ѡ��\n");
        scanf("%d",&n);
        system("cls");
        switch(n){
            case 1:
                dec_bin(decNum);
                break;
            case 2:
                dec_oct(decNum);
                break;
            case 3:
                printf("\nת��Ϊʮ������Ϊ:%d\n\n",decNum);
                break;
            case 4:
                dec_hex(decNum);
                break;
            case 5:
                return ;
            case 6:
                exit(0);
        }
    }system("pause");
    system("cls");
}
void dec(){
    int decNum,n;printf("������һ��ʮ���Ƶ���\n");
    scanf("%d",&decNum);
    system("cls");
    while(1){
        secMenu();
        printf("���������ѡ��\n");
        scanf("%d",&n);
        system("cls");
        switch(n){
            case 1:
                dec_bin(decNum);
                break;
            case 2:
                dec_oct(decNum);
                break;
            case 3:
                printf("\nת��Ϊʮ������Ϊ:%d\n\n",decNum);
                break;
            case 4:
                dec_hex(decNum);
                break;
            case 5:
                return ;
            case 6:
                exit(0);
        }
    }
    system("cls");
}
void hex(){
    char hex[10];
    int decNum,n;
    printf("������ʮ��������\n");
    scanf("%s",hex);
    system("cls");
    decNum = hex_dec(hex);
    while(1){
        secMenu();
        printf("���������ѡ��\n");
        scanf("%d",&n);
        system("cls");
        switch(n){
            case 1:
                dec_bin(decNum);
                break;
            case 2:
                dec_oct(decNum);
                break;
            case 3:
                printf("\nת��Ϊʮ������Ϊ:%d\n\n",decNum);
                break;
            case 4:
                dec_hex(decNum);
                break;
            case 5:
                return ;
            case 6:
                exit(0);
        }
    }
}
void Menu(){
    printf("��ӭ��������ת��ϵͳ\n");
    printf("        1.������        \n");
    printf("        2.�˽���        \n");
    printf("        3.ʮ����        \n");
    printf("        4.ʮ������        \n");
}
void secMenu(){
    printf("����������ת����ʲô����\n");
    printf("1.������\n");
    printf("2.�˽���\n");
    printf("3.ʮ����\n");
    printf("4.ʮ������\n");
    printf("5.������һ��\n");
    printf("6.�˳�����\n");
}
void dec_bin(int n){
    int i=0,bin[50];
    while(n>0)
    {
        bin[i]=n % 2;
        n /= 2;
        i++;
    }
    printf("\n\nת���Ķ�������Ϊ��");
    for(i--;i>=0;i--)
        printf("%d",bin[i]);
}
void dec_oct(int n){
    int i=0,oct[50];
    while(n>0)
    {
        oct[i]=n % 8;
        n /= 8;
        i++;
    }
    printf("\n\nת���İ˽�����Ϊ��");
    for(i--	;i>=0;i--)
        printf("%d",oct[i]);
}
void dec_hex(int n){
    char  hex[17] = {"0123456789ABCDEF" };
    int  c[20],i=0;
    while(n>0){
        c[i] = n % 16;
        n /= 16;
        i++;
    }
    printf("\n\nת����ʮ��������Ϊ��");
    for (--i; i >= 0; i--)
        printf("%c", hex[c[i]]);
    printf("\n");
}
int bin_dec(char*s){
    int i, n = 0;
    for (i = 0; s[i] != '\0'; ++i)
        n = n * 2 + (s[i] - '0');
    return n;
}
int oct_dec(char*s){
    int i, n = 0;
    for (i = 0; s[i] != '\0'; ++i)
        n = n * 8 + (s[i] - '0');
    return n;
}
int hex_dec(char*hec){
    int t=1,i,dec[100],l=strlen(hec),s=0;
    for(i=0;i<l;i++)
    {
        if(hec[i]>='A'&&hec[i]<='F')
            dec[i]=hec[i]-'A'+10;
        else dec[i]=hec[i]-'0';
    }
    for(int j=i-1;j>=0;j--)
    {
        s+=t*dec[j];
        t*=16;//��16��Ϊ8����Ϊ�˽���תΪʮ�����ơ�
    }
    return s;
}
