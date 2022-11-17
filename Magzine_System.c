#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


//ȫ�ֱ�����
char _pwd[10]="123456";

//�ṹ����
struct _Magzine{
    char magname[30];	//��־����
    float price;		//����
    char magtype[30];		//��־����
    struct _Magzine *next;
}Magzine;

struct _Customer{
    char account[20];//�ͻ����
    char name[20];	//����
    char sex[3];	//�Ա�
    char tel[12];	//�绰
    struct _Customer *next;
};

struct _CMR  //�ͻ�������־��ϵ�ṹ
{
    char account[20];	//�ͻ����
    char Mag_name[20];	//��־��
    int subsnum;		//��������
    float allmoney;		//�����ܽ��
    struct _CMR *next;
};
struct Max_Min{
    char magname[30];	//��־����
    float price;		//����
    char magtype[30];		//��־����
    int subnum;			//��������
};

struct _Magzine *Mcreat() //β�巨��������
{
    struct _Magzine *head,*tail; //headͷָ�룬tailβָ��
    struct _Magzine *p; //p����ǰָ�룬ָ��ǰ����Ľ��
    FILE *fp;
    int i;
    if((fp=fopen("E:\\design\\Magzine.txt","r"))==NULL) //���ļ�fp �ļ�ָ��
    {
        printf("��־��Ϣ�ļ�Magzinet.txt������\n");
        exit(0); //�ر������ļ����˳����򣬷��ز���ϵͳ
    }
    head=tail=(struct _Magzine *)malloc(sizeof(struct _Magzine));  //�տ�ʼֻ��һ��������ͷ��㼰β���
    head->next=0;  //ͷָ��Ϊ�գ�Ϊ�����ļ���һ�����ݶ�û��
    while(!feof(fp))
    {
        p = (struct _Magzine *)malloc(sizeof(struct _Magzine)); //��������һ��������
        fscanf(fp,"%s",p->magname);//���ļ��ж�����������
        fscanf(fp,"%f",&p->price);
        fscanf(fp,"%s",p->magtype);
        tail->next=p;     //�������һ��β���ָ����ָ���½�㣬���½����뵽����β
        tail=p;           //�����²���Ľ����β���
        tail->next=0;     //�½��ָ����Ϊ�ձ�ʾ�½��������β
    }
    fclose(fp);
    return head;
}

struct _Customer *Ccreat() //β�巨��������
{
    struct _Customer *head,*tail; //headͷָ�룬tailβָ��
    struct _Customer *p; //p����ǰָ�룬ָ��ǰ����Ľ��
    FILE *fp;
    int i;
    if((fp=fopen("E:\\design\\Customer.txt","r"))==NULL) //���ļ�fp �ļ�ָ��
    {
        printf("�ͻ���Ϣ�ļ�Customer.txt������\n");
        exit(0); //�ر������ļ����˳����򣬷��ز���ϵͳ
    }
    head=tail=(struct _Customer *)malloc(sizeof(struct _Customer));  //�տ�ʼֻ��һ��������ͷ��㼰β���
    head->next=0;  //ͷָ��Ϊ�գ�Ϊ�����ļ���һ�����ݶ�û��
    while(!feof(fp))
    {
        p = (struct _Customer *)malloc(sizeof(struct _Customer)); //��������һ��������
        fscanf(fp,"%s",p->account);//���ļ��ж�����������
        fscanf(fp,"%s",p->name);
        fscanf(fp,"%s",p->sex);
        fscanf(fp,"%s",p->tel);

        tail->next=p;     //�������һ��β���ָ����ָ���½�㣬���½����뵽����β
        tail=p;           //�����²���Ľ����β���
        tail->next=0;     //�½��ָ����Ϊ�ձ�ʾ�½��������β
    }
    fclose(fp);
    return head;
}

struct _CMR *CMRcreat() //β�巨��������
{
    struct _CMR *head,*tail; //headͷָ�룬tailβָ��
    struct _CMR *p; //p����ǰָ�룬ָ��ǰ����Ľ��
    FILE *fp;
    int i;
    if((fp=fopen("E:\\design\\CMR.txt","r"))==NULL) //���ļ�fp �ļ�ָ��
    {
        printf("�ͻ�������ϢCMR.txt������\n");
        exit(0); //�ر������ļ����˳����򣬷��ز���ϵͳ
    }
    head=tail=(struct _CMR *)malloc(sizeof(struct _CMR));  //�տ�ʼֻ��һ��������ͷ��㼰β���
    head->next=0;  //ͷָ��Ϊ�գ�Ϊ�����ļ���һ�����ݶ�û��
    while(!feof(fp))
    {
        p = (struct _CMR *)malloc(sizeof(struct _CMR)); //��������һ��������

        fscanf(fp,"%s",p->account);//���ļ��ж�����������
        fscanf(fp,"%s",p->Mag_name);
        fscanf(fp,"%d",&p->subsnum);
        fscanf(fp,"%f",&p->allmoney);
        tail->next=p;     //�������һ��β���ָ����ָ���½�㣬���½����뵽����β
        tail=p;           //�����²���Ľ����β���
        tail->next=0;     //�½��ָ����Ϊ�ձ�ʾ�½��������β
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
        printf("������ѡ��\n");
        setbuf(stdout, NULL);
        scanf("%d",&n);
        system("cls");
        switch(n){
            case 1:
                printf("���������Ա����\n");
                scanf("%s",pwd);
                if(strcmp(pwd,_pwd)==0){
                    manaLogic();
                    break;
                }else{
                    printf("����������ѡ��\n");
                    continue;
                }
            case 2: NormalLogic(); break;
            case 3: exit(0);
        }
    }
    return 0;
}


void mainMenu(){//���˵�
    printf("***********��ӭ������־���Ĺ���ϵͳ**********\n");
    printf("        1������Ա��¼\n");
    printf("        2���û���¼\n");
    printf("        3���˳�����\n");
}

void manaLogic() {//����Ա
    int n;
    while (1){
        manaMenu();
        printf("����������ѡ��\n");
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
void manaMenu(){//��־��Ϣ����˵�
    printf("**********�װ��Ĺ���Ա����ӭ��**********\n");
    printf("        1����־��Ϣ����\n");
    printf("        2���ͻ���Ϣ����\n");
    printf("        3����־���Ĺ���\n");
    printf("        4��ͳ�ƹ���\n");
}
void MagLogic(){//��־��Ϣ����ϵͳ
    int n;
    struct _Magzine*head;
    head = Mcreat();
    while (1){
        MagMenu();
        printf("���������ѡ��\n");
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
    printf("***********�װ��Ĺ���Ա����ӭ��������־��Ϣ����ϵͳ***********\n");
    printf("        1�������־��Ϣ\n");
    printf("        2����ѯ��־��Ϣ\n");
    printf("        3���޸���־��Ϣ\n");
    printf("        4��ɾ����־��Ϣ\n");
    printf("        5����ѯ������־��Ϣ\n");
    printf("        6��������һ��\n");
    printf("        7���˳�����\n");
}
void addMagzine(struct _Magzine*head){//�����־��Ϣ
    struct _Magzine  *p_new; //ָ���½ڵ����ָ��p_new
    p_new=(struct _Magzine *)malloc(sizeof(struct _Magzine));  //�½ڵ������ڴ�
    p_new->next=head->next;//p�ǲ���ǰ�Ľڵ㣬 p->next�ǲ���ڵ�ĺ���ڵ㣬����ڵ��ָ�����ź����
    head->next=p_new;//����ǰ�Ľڵ�p��ָ�����Ų�����½ڵ�
    printf("��������ӵ���־��Ϣ(��ʽΪ ��־�� �۸� ��־����)\n");
    scanf("%s",p_new->magname);//�Ӽ����ж�����������
    scanf("%f",&p_new->price);
    scanf("%s",p_new->magtype);
    printf("��ӳɹ�!\n");
}
void serchMag(struct _Magzine*head){//��ѯ��־��Ϣ
    int n;
    while (1){
        serMagMenu();
        printf("��������Ҫ��ѯ��ѡ��\n");
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
                printf("������������������\n");
                break;
        }
        saveMag(head);
    }
}
void serMagMenu(){
    printf("        1������־���ֲ�ѯ\n");
    printf("        2������־�۸��ѯ\n");
    printf("        3������־���Ͳ�ѯ\n");
    printf("        4��������һ��\n");
    printf("        5���˳�����\n");
}
void  serMagByName(struct _Magzine*head){
    char name[30];
    printf("��������Ҫ���ҵ�����\n");
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
    printf("��������Ҫ���ҵļ۸�");
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
    printf("��������Ҫ���ҵ���־����\n");
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
void modMag(struct _Magzine*head){//�޸���־��Ϣ
    char name[30];
    int n;
    printf("��������Ҫ���ҵ�����\n");
    scanf("%s",name);
    struct _Magzine*p;
    p = head->next;
    while (p != 0){
        if(strcmp(p->magname,name)==0){
            modMagMenu();
            printf("��������Ҫ�޸ĵ�ѡ��\n");
            scanf("%d",&n);
            switch (n) {
                case 1:
                    printf("ԭ��־��Ϊ%s���޸�Ϊ��",p->magname);
                    scanf("%s",p->magname);//�Ӽ���������������
                    printf("�޸ĳɹ�\n");
                    prnMag(p);
                    break;
                case 2:
                    printf("ԭ��־�۸�Ϊ%f���޸�Ϊ��",p->price);
                    scanf("%f",&p->price);//�Ӽ����������¼۸�
                    printf("�޸ĳɹ�\n");
                    prnMag(p);
                    break;
                case 3:
                    printf("ԭ��־����Ϊ%s���޸�Ϊ��",p->magtype);
                    scanf("%s",p->magtype);//�Ӽ���������������
                    printf("�޸ĳɹ�\n");
                    prnMag(p);
                    break;
                case 4:
                    return;
                case 5:
                    exit(0);
                default:
                    printf("������������������\n");
                    break;
            }
        }
        p = p->next;
    }
}
void modMagMenu(){
    printf("        1���޸�����\n");
    printf("        2���޸ļ۸�\n");
    printf("        3���޸�����\n");
    printf("        4��������һ��\n");
    printf("        5���˳�����\n");
}

void delMag(struct _Magzine*head){
    int n;
    while (1){
        delMagMenu();
        printf("���������ѡ��\n");
        scanf("%d",&n);
        switch (n) {
            case 1: delMagByName(head);
                break;
            case 2:
                return;
            case 3:
                exit(0);
            default:
                printf("���������������������\n");
                break;
        }
    }
}
void delMagMenu(){
    printf("        1������־�������Ҳ�ɾ��\n");
    printf("        2��������һ��\n");
    printf("        3���˳�����\n");
}
void delMagByName(struct _Magzine*head){
    char name[30];
    int n;
    printf("��������Ҫ���ҵ�����\n");
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
        return ;//�սڵ�
    p = head->next;//��ʼָ���һ�����
    if(p_del==head){
        head=p_del->next;
    }//ɾ������ͷ��㣬ֱ�ӽ�ͷ���ָ��ָ��ɾ���ڵ����һ���ڵ�
    else
        while(p!=0) //����Ϊ�գ��н�㣬ѭ��Ŀ������ɾ������ǰһ�����
        {
            if(p->next==p_del) //Ҫɾ���ڵ��ǰ��һ���ڵ�=Ҫɾ���ڵ�
            {
                p->next=p_del->next;
                break;
            }
            p = p->next;   //p���ڵ�ǰ����ָ���򣬾���ָ���������һ�����
        }
    free(p_del);//�ͷ�ɾ���ڵ��ڴ�
    printf("ɾ���ɹ�\n");
}

void ShowMagAll(struct _Magzine*head){//��ӡ�����е���־��Ϣ
    struct _Magzine *p; //ָ��ǰ����ָ��p
    p = head->next;//��ʼָ���һ�����
    printf("��־�� �۸�  ����\n");
    while(p!=0) //����Ϊ�գ��н��
    {
        printf("%s\t%f\t%s\n",p->magname,p->price,p->magtype);//���pָ��ĵ�ǰ���������Ĵ�
        p = p->next;   //p���ڵ�ǰ����ָ���򣬾���ָ���������һ�����
    }
}
void prnMag(struct _Magzine *p){//��ӡ����ǰ�ڵ����Ϣ
    if (p!=0){ //��㲻Ϊ�գ��н��
        printf("%s %f %s\n",p->magname,p->price,p->magtype);//���pָ��ĵ�ǰ���������Ĵ�
    }
}
void saveMag(struct _Magzine*head){//������ļ�
    struct _Magzine*p;
    FILE*fp;
    int i;
    if((fp = fopen("E:\\design\\Magzine.txt","w")==NULL)){
        printf("��־��Ϣ�ļ�Magzine.txt������\n");
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
void CusLogic(){//�ͻ���Ϣ����
    int n;
    struct _Customer*head;
    head = Ccreat();
    while(1){
        CusMenu();
        printf("����������ѡ��\n");
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
    printf("***********�װ��Ĺ���Ա����ӭ�������ͻ���Ϣ����ϵͳ***********\n");
    printf("        1����ӿͻ���Ϣ\n");
    printf("        2����ѯ�ͻ���Ϣ\n");
    printf("        3���޸Ŀͻ���Ϣ\n");
    printf("        4��ɾ���ͻ���Ϣ\n");
    printf("        5����ѯ���пͻ���Ϣ\n");
    printf("        6��������һ��\n");
    printf("        7���˳�����\n");
}
void addCus(struct _Customer*head){//��ӿͻ���Ϣ
    struct _Customer  *p_new; //ָ���½ڵ����ָ��p_new
    p_new=(struct _Customer *)malloc(sizeof(struct _Customer));  //�½ڵ������ڴ�
    p_new->next=head->next;//p�ǲ���ǰ�Ľڵ㣬 p->next�ǲ���ڵ�ĺ���ڵ㣬����ڵ��ָ�����ź����
    head->next=p_new;//����ǰ�Ľڵ�p��ָ�����Ų�����½ڵ�
    printf("��������ӵĿͻ���Ϣ(��ʽΪ ��� ���� �Ա� �绰)\n");
    scanf("%s",p_new->account);
    scanf("%s",p_new->name);
    scanf("%s",p_new->sex);
    scanf("%s",p_new->tel);
    printf("��ӳɹ�!\n");
}

void serCus(struct _Customer*head){//��ѯ�ͻ���Ϣ
    int n;
    while (1){
        serCusMenu();
        printf("��������Ҫ������ѡ��\n");
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
void serCusMenu(){//��ѯ�ͻ���Ϣ�Ĳ˵�
    printf("        1�����ͻ���Ų�ѯ\n");
    printf("        2�����ͻ���������\n");
    printf("        3�����ͻ��Ա����\n");
    printf("        4�����ͻ��绰����\n");
    printf("        5��������һ��\n");
    printf("        6���˳�����\n");
}
void serCusByAc(struct _Customer*head){
    char account[30];
    printf("��������Ҫ���ҵ��û����");
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
    printf("��������Ҫ���ҵ�����\n");
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
    printf("��������Ҫ���ҵ��Ա�\n");
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
    printf("��������Ҫ���ҵĵ绰����\n");
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
void modCus(struct _Customer*head){//�޸Ŀͻ���Ϣ
    char name[30];
    int n;
    printf("��������Ҫ���ҵ�����\n");
    scanf("%s",name);
    struct _Customer*p;
    p = head->next;
    while (p != 0){
        if(strcmp(p->name,name)==0){
            modCusMenu();
            printf("��������Ҫ�޸ĵ�ѡ��\n");
            scanf("%d",&n);
            switch (n) {
                case 1:
                    printf("ԭ���Ϊ%s,�޸�Ϊ:",p->account);
                    scanf("%s",p->account);
                    printf("�޸ĳɹ�\n");
                    prnCus(p);
                    break;
                case 2:
                    printf("ԭ��־��Ϊ%s���޸�Ϊ��",p->name);
                    scanf("%s",p->name);//�Ӽ���������������
                    printf("�޸ĳɹ�\n");
                    prnMag(p);
                    break;
                case 3:
                    printf("ԭ�Ա�Ϊ%s���޸�Ϊ��",p->sex);
                    scanf("%s",p->sex);//�Ӽ����������¼۸�
                    printf("�޸ĳɹ�\n");
                    prnCus(p);
                    break;
                case 4:
                    printf("ԭ�绰����Ϊ%s���޸�Ϊ��",p->tel);
                    scanf("%s",p->tel);//�Ӽ���������������
                    printf("�޸ĳɹ�\n");
                    prnCus(p);
                    break;
                case 5:
                    return;
                case 6:
                    exit(0);
                default:
                    printf("������������������\n");
                    break;
            }
        }
        p = p->next;
    }
}
void modCusMenu(){
    printf("        1���޸ı��\n");
    printf("        2���޸�����\n");
    printf("        3���޸��Ա�\n");
    printf("        4���޸��ֻ���\n");
    printf("        5��������һ��\n");
    printf("        6���˳�����\n");
}
void delCus(struct _Customer*head){//ɾ���ͻ���Ϣ
    int n;
    while (1){
        delCusMenu();
        printf("���������ѡ��\n");
        scanf("%d",&n);
        switch (n) {
            case 1: delCusByName(head);
                break;
            case 2:
                return;
            case 3:
                exit(0);
            default:
                printf("���������������������\n");
                break;
        }
    }
}
void delCusMenu(){
    printf("        1�����ͻ��������Ҳ�ɾ��\n");
    printf("        2��������һ��\n");
    printf("        3���˳�����\n");
}
void delCusByName(struct _Customer*head){
    char name[30];
    int n;
    printf("��������Ҫ���ҵ�����\n");
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
        return ;//�սڵ�
    p = head->next;//��ʼָ���һ�����
    if(p_del==head){
        head=p_del->next;
    }//ɾ������ͷ��㣬ֱ�ӽ�ͷ���ָ��ָ��ɾ���ڵ����һ���ڵ�
    else
        while(p!=0) //����Ϊ�գ��н�㣬ѭ��Ŀ������ɾ������ǰһ�����
        {
            if(p->next==p_del) //Ҫɾ���ڵ��ǰ��һ���ڵ�=Ҫɾ���ڵ�
            {
                p->next=p_del->next;
                break;
            }
            p = p->next;   //p���ڵ�ǰ����ָ���򣬾���ָ���������һ�����
        }
    free(p_del);//�ͷ�ɾ���ڵ��ڴ�
    printf("ɾ���ɹ�\n");
}
void showCusAll(struct _Customer*head){//��������������е���Ϣ
    struct _Customer *p; //ָ��ǰ����ָ��p
    p = head->next;//��ʼָ���һ�����
    printf("���  ����  �Ա�  �绰����\n");
    while(p!=0) //����Ϊ�գ��н��
    {
        printf("%s\t%s\t%s\t%s\n",p->account,p->name,p->sex,p->tel);//���pָ��ĵ�ǰ���������Ĵ�
        p = p->next;   //p���ڵ�ǰ����ָ���򣬾���ָ���������һ�����
    }
}
void prnCus(struct _Customer*p){//�����ǰ�ڵ����Ϣ
    if (p!=0){ //��㲻Ϊ�գ��н��
        printf("%s %s %s %s\n",p->account,p->name,p->sex,p->tel);//���pָ��ĵ�ǰ���������Ĵ�
    }
}
void saveCus(struct _Customer*head){//��������Ϣ����ļ�
    struct _Customer*p;
    FILE*fp;
    int i;
    if((fp = fopen("E:\\design\\Magzine.txt","w")==NULL)){
        printf("��־��Ϣ�ļ�Magzine.txt������\n");
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
void orderMag(){//¼��ͻ�������־��Ϣ
    struct _CMR *head,*p;
    float sum;
    head = CMRcreat();
    printf("-------------\n");
    printf("������пͻ�������־��Ϣ\n");
    p = head->next;//��ʼָ���һ�����

    while(p!=0) //����Ϊ�գ��н��
    {
        printf("�ͻ��ı��Ϊ:%s \n ��־��Ϊ:%s \n ��־����Ϊ:%d \n ��־�ܽ��Ϊ:%f\n",p->account,p->Mag_name,p->subsnum,p->allmoney);//���pָ��ĵ�ǰ���������Ĵ�
        p = p->next;   //p���ڵ�ǰ����ָ���򣬾���ָ���������һ�����
    }
}
void Count(){//ͳ��ÿ����־������������ʾ����ǰ�����ͺ�����
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
    printf("������ǰ������:\n");
    for(j=0;j<3;j++){
        printf("%s %s %f\n",out[j].magname,out[j].magtype,out[j].price);
    }
    printf("�����������λ��:\n");
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
        printf("����������ѡ��\n");
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
    printf("**********�װ��Ŀͻ�������***********\n");
    printf("        ���ã���ֻ�в�ѯȨ���\n");
    printf("        1������־���ֲ�ѯ\n");
    printf("        2������־�۸��ѯ\n");
    printf("        3������־���Ͳ�ѯ\n");
    printf("        4���˳�ϵͳ\n");
}

