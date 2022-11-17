#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


//全局变量区
char _pwd[10]="123456";

//结构体区
struct _Magzine{
    char magname[30];	//杂志名称
    float price;		//单价
    char magtype[30];		//杂志类型
    struct _Magzine *next;
}Magzine;

struct _Customer{
    char account[20];//客户编号
    char name[20];	//姓名
    char sex[3];	//性别
    char tel[12];	//电话
    struct _Customer *next;
};

struct _CMR  //客户订阅杂志关系结构
{
    char account[20];	//客户编号
    char Mag_name[20];	//杂志名
    int subsnum;		//订阅数量
    float allmoney;		//订阅总金额
    struct _CMR *next;
};
struct Max_Min{
    char magname[30];	//杂志名称
    float price;		//单价
    char magtype[30];		//杂志类型
    int subnum;			//订阅数量
};

struct _Magzine *Mcreat() //尾插法创建链表
{
    struct _Magzine *head,*tail; //head头指针，tail尾指针
    struct _Magzine *p; //p：当前指针，指向当前处理的结点
    FILE *fp;
    int i;
    if((fp=fopen("E:\\design\\Magzine.txt","r"))==NULL) //打开文件fp 文件指针
    {
        printf("杂志信息文件Magzinet.txt不存在\n");
        exit(0); //关闭所有文件，退出程序，返回操作系统
    }
    head=tail=(struct _Magzine *)malloc(sizeof(struct _Magzine));  //刚开始只有一个结点就是头结点及尾结点
    head->next=0;  //头指针为空，为了怕文件中一个数据都没有
    while(!feof(fp))
    {
        p = (struct _Magzine *)malloc(sizeof(struct _Magzine)); //新申请下一个插入结点
        fscanf(fp,"%s",p->magname);//从文件中读入结点数据域串
        fscanf(fp,"%f",&p->price);
        fscanf(fp,"%s",p->magtype);
        tail->next=p;     //链表的上一个尾结点指针域指向新结点，即新结点插入到链表尾
        tail=p;           //设置新插入的结点是尾结点
        tail->next=0;     //新结点指针域为空表示新结点是链表尾
    }
    fclose(fp);
    return head;
}

struct _Customer *Ccreat() //尾插法创建链表
{
    struct _Customer *head,*tail; //head头指针，tail尾指针
    struct _Customer *p; //p：当前指针，指向当前处理的结点
    FILE *fp;
    int i;
    if((fp=fopen("E:\\design\\Customer.txt","r"))==NULL) //打开文件fp 文件指针
    {
        printf("客户信息文件Customer.txt不存在\n");
        exit(0); //关闭所有文件，退出程序，返回操作系统
    }
    head=tail=(struct _Customer *)malloc(sizeof(struct _Customer));  //刚开始只有一个结点就是头结点及尾结点
    head->next=0;  //头指针为空，为了怕文件中一个数据都没有
    while(!feof(fp))
    {
        p = (struct _Customer *)malloc(sizeof(struct _Customer)); //新申请下一个插入结点
        fscanf(fp,"%s",p->account);//从文件中读入结点数据域串
        fscanf(fp,"%s",p->name);
        fscanf(fp,"%s",p->sex);
        fscanf(fp,"%s",p->tel);

        tail->next=p;     //链表的上一个尾结点指针域指向新结点，即新结点插入到链表尾
        tail=p;           //设置新插入的结点是尾结点
        tail->next=0;     //新结点指针域为空表示新结点是链表尾
    }
    fclose(fp);
    return head;
}

struct _CMR *CMRcreat() //尾插法创建链表
{
    struct _CMR *head,*tail; //head头指针，tail尾指针
    struct _CMR *p; //p：当前指针，指向当前处理的结点
    FILE *fp;
    int i;
    if((fp=fopen("E:\\design\\CMR.txt","r"))==NULL) //打开文件fp 文件指针
    {
        printf("客户订阅信息CMR.txt不存在\n");
        exit(0); //关闭所有文件，退出程序，返回操作系统
    }
    head=tail=(struct _CMR *)malloc(sizeof(struct _CMR));  //刚开始只有一个结点就是头结点及尾结点
    head->next=0;  //头指针为空，为了怕文件中一个数据都没有
    while(!feof(fp))
    {
        p = (struct _CMR *)malloc(sizeof(struct _CMR)); //新申请下一个插入结点

        fscanf(fp,"%s",p->account);//从文件中读入结点数据域串
        fscanf(fp,"%s",p->Mag_name);
        fscanf(fp,"%d",&p->subsnum);
        fscanf(fp,"%f",&p->allmoney);
        tail->next=p;     //链表的上一个尾结点指针域指向新结点，即新结点插入到链表尾
        tail=p;           //设置新插入的结点是尾结点
        tail->next=0;     //新结点指针域为空表示新结点是链表尾
    }
    fclose(fp);
    return head;
}
void modCusMenu();
void norMenu();
void showCusAll(struct _Customer*head);
void delCusMenu();
void mainMenu();
void manaLogic();
void manaMenu();
void MagLogic();
void addMagzine(struct _Magzine*head);
void serchMag(struct _Magzine*head);
void serMagMenu();
void serMagByName(struct _Magzine*head);
void serMagByPrice(struct _Magzine*head);
void serMagByType(struct _Magzine*head);
void modMag(struct _Magzine*head);
void modMagMenu();
void delMag(struct _Magzine*head);
void delMagMenu();
void delMagByName(struct _Magzine*head);
void ShowMagAll(struct _Magzine*head);
void prnMag(struct _Magzine*p);
void saveMag(struct _Magzine*head);
void serCusMenu();
void serCusByAc(struct _Customer*head);
void serCusByName(struct _Customer*head);
void serCusBySex(struct _Customer*head);
void serCusByTel(struct _Customer*head);
void CusMenu();
void addCus(struct _Customer*head);
void prnCus(struct _Customer*p);
void NormalLogic();
void MagMenu();
void CusLogic();
void serCus(struct _Customer*head);
void orderMag();
void Count();
void modCus(struct _Customer*head);
void delCus(struct _Customer*head);
void Countnum(struct _CMR *CMRhead,struct _Magzine *Mhead);
void delCusByName(struct _Customer*head);

int main(){
    int n;
    char pwd[20];
    while(1){
        mainMenu();
        printf("请输入选项\n");
        setbuf(stdout, NULL);
        scanf("%d",&n);
        system("cls");
        switch(n){
            case 1:
                printf("请输入管理员密码\n");
                scanf("%s",pwd);
                if(strcmp(pwd,_pwd)==0){
                    manaLogic();
                    break;
                }else{
                    printf("请重新输入选项\n");
                    continue;
                }
            case 2: NormalLogic(); break;
            case 3: exit(0);
        }
    }
    return 0;
}


void mainMenu(){//主菜单
    printf("***********欢迎来到杂志订阅管理系统**********\n");
    printf("        1、管理员登录\n");
    printf("        2、用户登录\n");
    printf("        3、退出程序\n");
}

void manaLogic() {//管理员
    int n;
    while (1){
        manaMenu();
        printf("请输入您的选择\n");
        scanf("%d",&n);
        switch (n) {
            case 1: MagLogic();
                break;
            case 2: CusLogic();
                break;
            case 3:
                orderMag();
                break;
            case 4:
                Count();
                break;
        }
    }
}
void manaMenu(){//杂志信息管理菜单
    printf("**********亲爱的管理员，欢迎您**********\n");
    printf("        1、杂志信息管理\n");
    printf("        2、客户信息管理\n");
    printf("        3、杂志订阅功能\n");
    printf("        4、统计功能\n");
}
void MagLogic(){//杂志信息管理系统
    int n;
    struct _Magzine*head;
    head = Mcreat();
    while (1){
        MagMenu();
        printf("请输入你的选择\n");
        scanf("%d",&n);
        switch (n) {
            case 1: addMagzine(head);
                break;
            case 2: serchMag(head);
                break;
            case 3: modMag(head);
                break;
            case 4: delMag(head);
                break;
            case 5: ShowMagAll(head);
                break;
            case 6:
                return;
            case 7:
                exit(0);
        }

    }
}
void MagMenu(){
    printf("***********亲爱的管理员，欢迎您来到杂志信息管理系统***********\n");
    printf("        1、添加杂志信息\n");
    printf("        2、查询杂志信息\n");
    printf("        3、修改杂志信息\n");
    printf("        4、删除杂志信息\n");
    printf("        5、查询所有杂志信息\n");
    printf("        6、返回上一级\n");
    printf("        7、退出程序\n");
}
void addMagzine(struct _Magzine*head){//添加杂志信息
    struct _Magzine  *p_new; //指向新节点结点的指针p_new
    p_new=(struct _Magzine *)malloc(sizeof(struct _Magzine));  //新节点申请内存
    p_new->next=head->next;//p是插入前的节点， p->next是插入节点的后面节点，插入节点的指针域存放后面的
    head->next=p_new;//插入前的节点p的指针域存放插入的新节点
    printf("请输入添加的杂志信息(格式为 杂志名 价格 杂志种类)\n");
    scanf("%s",p_new->magname);//从键盘中读入结点数据域串
    scanf("%f",&p_new->price);
    scanf("%s",p_new->magtype);
    printf("添加成功!\n");
}
void serchMag(struct _Magzine*head){//查询杂志信息
    int n;
    while (1){
        serMagMenu();
        printf("请输入你要查询的选项\n");
        scanf("%d",&n);
        switch (n) {
            case 1: serMagByName(head);
                break;
            case 2: serMagByPrice(head);
                break;
            case 3: serMagByType(head);
                break;
            case 4:
                return;
            case 5:
                exit(0);
            default:
                printf("输入有误。请重新输入\n");
                break;
        }
        saveMag(head);
    }
}
void serMagMenu(){
    printf("        1、按杂志名字查询\n");
    printf("        2、按杂志价格查询\n");
    printf("        3、按杂志类型查询\n");
    printf("        4、返回上一级\n");
    printf("        5、退出程序\n");
}
void  serMagByName(struct _Magzine*head){
    char name[30];
    printf("请输入你要查找的名字\n");
    scanf("%s",name);
    struct _Magzine*p_new;
    p_new = head->next;
    while (p_new != 0){
        if(strcmp(p_new->magname,name)==0){
            prnMag(p_new);
        }
        p_new = p_new->next;
    }
}
void serMagByPrice(struct _Magzine*head){
    float price;
    printf("请输入你要查找的价格");
    scanf("%f",&price);
    struct _Magzine*p;
    p = head->next;
    while (p != 0){
        if(p->price == price){
            prnMag(p);
        }
        p = p->next;
    }
}
void serMagByType(struct _Magzine*head){
    char type[30];
    printf("请输入你要查找的杂志类型\n");
    scanf("%s",type);
    struct _Magzine*p;
    p = head->next;
    while (p != 0){
        if(strcmp(p->magtype,type)==0){
            prnMag(p);
        }
        p = p->next;
    }
}
void modMag(struct _Magzine*head){//修改杂志信息
    char name[30];
    int n;
    printf("请输入你要查找的名字\n");
    scanf("%s",name);
    struct _Magzine*p;
    p = head->next;
    while (p != 0){
        if(strcmp(p->magname,name)==0){
            modMagMenu();
            printf("请输入你要修改的选项\n");
            scanf("%d",&n);
            switch (n) {
                case 1:
                    printf("原杂志名为%s：修改为：",p->magname);
                    scanf("%s",p->magname);//从键盘中输入新名字
                    printf("修改成功\n");
                    prnMag(p);
                    break;
                case 2:
                    printf("原杂志价格为%f：修改为：",p->price);
                    scanf("%f",&p->price);//从键盘中输入新价格
                    printf("修改成功\n");
                    prnMag(p);
                    break;
                case 3:
                    printf("原杂志类型为%s：修改为：",p->magtype);
                    scanf("%s",p->magtype);//从键盘中输入新种类
                    printf("修改成功\n");
                    prnMag(p);
                    break;
                case 4:
                    return;
                case 5:
                    exit(0);
                default:
                    printf("输入有误。请重新输入\n");
                    break;
            }
        }
        p = p->next;
    }
}
void modMagMenu(){
    printf("        1、修改姓名\n");
    printf("        2、修改价格\n");
    printf("        3、修改类型\n");
    printf("        4、返回上一级\n");
    printf("        5、退出程序\n");
}

void delMag(struct _Magzine*head){
    int n;
    while (1){
        delMagMenu();
        printf("请输入你的选项\n");
        scanf("%d",&n);
        switch (n) {
            case 1: delMagByName(head);
                break;
            case 2:
                return;
            case 3:
                exit(0);
            default:
                printf("你输入的有误，请重新输入\n");
                break;
        }
    }
}
void delMagMenu(){
    printf("        1、按杂志姓名查找并删除\n");
    printf("        2、返回上一级\n");
    printf("        3、退出程序\n");
}
void delMagByName(struct _Magzine*head){
    char name[30];
    int n;
    printf("请输入你要查找的名字\n");
    scanf("%s",name);
    struct _Magzine *p,*p_del;
    p = head->next;
    p_del = (struct _Magzine *)malloc(sizeof(struct _Magzine));
    while ( p != 0){
        if(strcmp(p->magname,name)==0){
            p_del=p;
            break;
        }
        p = p->next;
    }
    if(p_del==0)
        return ;//空节点
    p = head->next;//开始指向第一个结点
    if(p_del==head){
        head=p_del->next;
    }//删除的是头结点，直接将头结点指针指向删除节点的下一个节点
    else
        while(p!=0) //链表不为空，有结点，循环目的是找删除结点的前一个结点
        {
            if(p->next==p_del) //要删除节点的前面一个节点=要删除节点
            {
                p->next=p_del->next;
                break;
            }
            p = p->next;   //p等于当前结点的指针域，就是指向链表的下一个结点
        }
    free(p_del);//释放删除节点内存
    printf("删除成功\n");
}

void ShowMagAll(struct _Magzine*head){//打印出所有的杂志信息
    struct _Magzine *p; //指向当前结点的指针p
    p = head->next;//开始指向第一个结点
    printf("杂志名 价格  类型\n");
    while(p!=0) //链表不为空，有结点
    {
        printf("%s\t%f\t%s\n",p->magname,p->price,p->magtype);//输出p指向的当前结点数据域的串
        p = p->next;   //p等于当前结点的指针域，就是指向链表的下一个结点
    }
}
void prnMag(struct _Magzine *p){//打印出当前节点的信息
    if (p!=0){ //结点不为空，有结点
        printf("%s %f %s\n",p->magname,p->price,p->magtype);//输出p指向的当前结点数据域的串
    }
}
void saveMag(struct _Magzine*head){//保存进文件
    struct _Magzine*p;
    FILE*fp;
    int i;
    if((fp = fopen("E:\\design\\Magzine.txt","w")==NULL)){
        printf("杂志信息文件Magzine.txt不存在\n");
        exit(0);
    }
    p = head->next;
    while (p != 0){
        fprintf(fp,"%s ",p->magname);
        fprintf(fp,"%f ",p->price);
        fprintf(fp,"%s ",p->magtype);
        p = p->next;
    }
}
void CusLogic(){//客户信息管理
    int n;
    struct _Customer*head;
    head = Ccreat();
    while(1){
        CusMenu();
        printf("请输入您的选择\n");
        scanf("%d",&n);
        switch (n) {
            case 1: addCus(head);
                break;
            case 2: serCus(head);
                break;
            case 3:
                modCus(head);
                break;
            case 4:
                delCus(head);
                break;
            case 5:
                showCusAll(head);
                break;
            case 6:
                return;
            case 7:
                exit(0);
        }
    }
}
void CusMenu(){
    printf("***********亲爱的管理员，欢迎您来到客户信息管理系统***********\n");
    printf("        1、添加客户信息\n");
    printf("        2、查询客户信息\n");
    printf("        3、修改客户信息\n");
    printf("        4、删除客户信息\n");
    printf("        5、查询所有客户信息\n");
    printf("        6、返回上一级\n");
    printf("        7、退出程序\n");
}
void addCus(struct _Customer*head){//添加客户信息
    struct _Customer  *p_new; //指向新节点结点的指针p_new
    p_new=(struct _Customer *)malloc(sizeof(struct _Customer));  //新节点申请内存
    p_new->next=head->next;//p是插入前的节点， p->next是插入节点的后面节点，插入节点的指针域存放后面的
    head->next=p_new;//插入前的节点p的指针域存放插入的新节点
    printf("请输入添加的客户信息(格式为 编号 姓名 性别 电话)\n");
    scanf("%s",p_new->account);
    scanf("%s",p_new->name);
    scanf("%s",p_new->sex);
    scanf("%s",p_new->tel);
    printf("添加成功!\n");
}

void serCus(struct _Customer*head){//查询客户信息
    int n;
    while (1){
        serCusMenu();
        printf("请输入你要搜索的选项\n");
        scanf("%d",&n);
        switch (n) {
            case 1: serCusByAc(head);
                break;
            case 2: serCusByName(head);
                break;
            case 3: serCusBySex(head);
                break;
            case 4: serCusByTel(head);
                break;
            case 5:
                return;
            case 6:
                exit(0);
        }
    }
}
void serCusMenu(){//查询客户信息的菜单
    printf("        1、按客户编号查询\n");
    printf("        2、按客户姓名查找\n");
    printf("        3、按客户性别查找\n");
    printf("        4、按客户电话查找\n");
    printf("        5、返回上一级\n");
    printf("        6、退出程序\n");
}
void serCusByAc(struct _Customer*head){
    char account[30];
    printf("请输入你要查找的用户编号");
    scanf("%s",account);
    struct _Customer*p;
    p = head->next;
    while (p != 0){
        if(strcmp(p->account,account)==0){
            prnMag(p);
        }
        p = p->next;
    }
}
void serCusByName(struct _Customer*head){
    char name[30];
    printf("请输入你要查找的名字\n");
    scanf("%s",name);
    struct _Customer*p;
    p = head->next;
    while (p != 0){
        if(strcmp(p->name,name)==0){
            prnCus(p);
        }
        p = p->next;
    }
}
void serCusBySex(struct _Customer*head){
    char sex[3];
    printf("请输入你要查找的性别\n");
    scanf("%s",sex);
    struct _Customer*p;
    p = head->next;
    while (p != 0){
        if(strcmp(p->sex,sex)==0){
            prnCus(p);
        }
        p = p->next;
    }
}
void serCusByTel(struct _Customer*head){
    char tel[12];
    printf("请输入你要查找的电话号码\n");
    scanf("%s",tel);
    struct _Customer*p;
    p = head->next;
    while (p != 0){
        if(strcmp(p->tel,tel)){
            prnCus(p);
        }
        p = p->next;
    }
}
void modCus(struct _Customer*head){//修改客户信息
    char name[30];
    int n;
    printf("请输入你要查找的名字\n");
    scanf("%s",name);
    struct _Customer*p;
    p = head->next;
    while (p != 0){
        if(strcmp(p->name,name)==0){
            modCusMenu();
            printf("请输入你要修改的选项\n");
            scanf("%d",&n);
            switch (n) {
                case 1:
                    printf("原编号为%s,修改为:",p->account);
                    scanf("%s",p->account);
                    printf("修改成功\n");
                    prnCus(p);
                    break;
                case 2:
                    printf("原杂志名为%s：修改为：",p->name);
                    scanf("%s",p->name);//从键盘中输入新名字
                    printf("修改成功\n");
                    prnMag(p);
                    break;
                case 3:
                    printf("原性别为%s：修改为：",p->sex);
                    scanf("%s",p->sex);//从键盘中输入新价格
                    printf("修改成功\n");
                    prnCus(p);
                    break;
                case 4:
                    printf("原电话号码为%s：修改为：",p->tel);
                    scanf("%s",p->tel);//从键盘中输入新种类
                    printf("修改成功\n");
                    prnCus(p);
                    break;
                case 5:
                    return;
                case 6:
                    exit(0);
                default:
                    printf("输入有误。请重新输入\n");
                    break;
            }
        }
        p = p->next;
    }
}
void modCusMenu(){
    printf("        1、修改编号\n");
    printf("        2、修改姓名\n");
    printf("        3、修改性别\n");
    printf("        4、修改手机号\n");
    printf("        5、返回上一级\n");
    printf("        6、退出程序\n");
}
void delCus(struct _Customer*head){//删除客户信息
    int n;
    while (1){
        delCusMenu();
        printf("请输入你的选项\n");
        scanf("%d",&n);
        switch (n) {
            case 1: delCusByName(head);
                break;
            case 2:
                return;
            case 3:
                exit(0);
            default:
                printf("你输入的有误，请重新输入\n");
                break;
        }
    }
}
void delCusMenu(){
    printf("        1、按客户姓名查找并删除\n");
    printf("        2、返回上一级\n");
    printf("        3、退出程序\n");
}
void delCusByName(struct _Customer*head){
    char name[30];
    int n;
    printf("请输入你要查找的名字\n");
    scanf("%s",name);
    struct _Customer *p,*p_del;
    p = head->next;
    p_del = (struct _Customer *)malloc(sizeof(struct _Customer));
    while ( p != 0){
        if(strcmp(p->name,name)==0){
            p_del=p;
            break;
        }
        p = p->next;
    }
    if(p_del==0)
        return ;//空节点
    p = head->next;//开始指向第一个结点
    if(p_del==head){
        head=p_del->next;
    }//删除的是头结点，直接将头结点指针指向删除节点的下一个节点
    else
        while(p!=0) //链表不为空，有结点，循环目的是找删除结点的前一个结点
        {
            if(p->next==p_del) //要删除节点的前面一个节点=要删除节点
            {
                p->next=p_del->next;
                break;
            }
            p = p->next;   //p等于当前结点的指针域，就是指向链表的下一个结点
        }
    free(p_del);//释放删除节点内存
    printf("删除成功\n");
}
void showCusAll(struct _Customer*head){//输出链表里面所有的信息
    struct _Customer *p; //指向当前结点的指针p
    p = head->next;//开始指向第一个结点
    printf("编号  姓名  性别  电话号码\n");
    while(p!=0) //链表不为空，有结点
    {
        printf("%s\t%s\t%s\t%s\n",p->account,p->name,p->sex,p->tel);//输出p指向的当前结点数据域的串
        p = p->next;   //p等于当前结点的指针域，就是指向链表的下一个结点
    }
}
void prnCus(struct _Customer*p){//输出当前节点的信息
    if (p!=0){ //结点不为空，有结点
        printf("%s %s %s %s\n",p->account,p->name,p->sex,p->tel);//输出p指向的当前结点数据域的串
    }
}
void saveCus(struct _Customer*head){//把链表信息存进文件
    struct _Customer*p;
    FILE*fp;
    int i;
    if((fp = fopen("E:\\design\\Magzine.txt","w")==NULL)){
        printf("杂志信息文件Magzine.txt不存在\n");
        exit(0);
    }
    p = head->next;
    while (p != 0){
        fprintf(fp,"%s ",p->account);
        fprintf(fp,"%s ",p->name);
        fprintf(fp,"%s ",p->sex);
        fprintf(fp,"%s ",p->tel);
        p = p->next;
    }
}
void orderMag(){//录入客户订阅杂志信息
    struct _CMR *head,*p;
    float sum;
    head = CMRcreat();
    printf("-------------\n");
    printf("输出所有客户订购杂志信息\n");
    p = head->next;//开始指向第一个结点

    while(p!=0) //链表不为空，有结点
    {
        printf("客户的编号为:%s \n 杂志名为:%s \n 杂志数量为:%d \n 杂志总金额为:%f\n",p->account,p->Mag_name,p->subsnum,p->allmoney);//输出p指向的当前结点数据域的串
        p = p->next;   //p等于当前结点的指针域，就是指向链表的下一个结点
    }
}
void Count(){//统计每种杂志的数量并且显示订阅前三名和后三名
    printf("------------------\n");
    struct _Magzine *Mhead;
    struct _CMR *CMRhead;
    Mhead = Mcreat();
    CMRhead = CMRcreat();
    Countnum(CMRhead,Mhead);
}
void Countnum(struct _CMR *CMRhead,struct _Magzine *Mhead){
    struct _CMR	*CMRp;
    CMRp = CMRhead->next;
    struct _Magzine *Mp;
    Mp = Mhead->next;
    int i=0,j,k,n[50]={0};
    struct Max_Min out[50];
    char temp_name[20];
    char temp_type[20];
    float temp;
    while(Mp!=0){
        while(CMRp!=0){
            if(strcmp(CMRp->Mag_name,Mp->magname)==0){
                strcpy(out[i].magname,Mp->magname);
                strcpy(out[i].magtype,Mp->magtype);
                out[i].price = Mp->price;
                out[i].subnum += CMRp->subsnum;
            }
            CMRp = CMRp->next;
        }
        Mp = Mp->next;
        i++;
    }
    for(j=0;j<i;j++){
        for(k=0;k<i-j-1;k++){
            if(out[k].subnum<out[k+1].subnum){
                strcpy(temp_name,out[k].magname);
                strcpy(out[k].magname,out[k+1].magname);
                strcpy(out[k+1].magname,temp_name);

                strcpy(temp_type,out[k].magtype);
                strcpy(out[k].magtype,out[k+1].magtype);
                strcpy(out[k+1].magtype,temp_type);

                temp = out[k].price;
                out[k].price = out[k+1].price;
                out[k+1].price = temp;
            }
        }
    }
    printf("订阅数前三的是:\n");
    for(j=0;j<3;j++){
        printf("%s %s %f\n",out[j].magname,out[j].magtype,out[j].price);
    }
    printf("订阅数最后三位是:\n");
    for(i;i>i-3;i--){
        printf("%s %s %f\n",out[i].magname,out[i].magtype,out[i].price);
    }
}
void NormalLogic() {
    struct _Magzine*head;
    head = Mcreat();
    int n;
    while (1){
        norMenu();
        printf("请输入您的选项\n");
        scanf("%d",&n);
        switch (n) {
            case 1:
                serMagByName(head);
                break;
            case 2:
                serMagByPrice(head);
                break;
            case 3:
                serMagByType(head);
                break;
            case 4:
                exit(0);
        }
    }
}
void norMenu(){
    printf("**********亲爱的客户，您好***********\n");
    printf("        您好，您只有查询权限喔\n");
    printf("        1、按杂志名字查询\n");
    printf("        2、按杂志价格查询\n");
    printf("        3、按杂志类型查询\n");
    printf("        4、退出系统\n");
}

