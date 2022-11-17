#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
char English[] = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
int main(){
    FILE *passageg,*answer;
    srand(time(NULL));
    char pas[100],ans[100];
    int m,i,count = 0;
    for (i = 0; i < 100; i++) {
        m = rand()%52;
        pas[i] = English[m];
    }

    printf("随机生成的范文为：\n\t%s\n",pas);
    fflush(stdout);
    if ((passageg = fopen("E:\\design\\passage.txt", "w")) == NULL) {
        perror("FILE PAGES OPEN ERROR!");
    }else {
        fprintf(passageg, "%s", pas);
        fclose(passageg);
    }

    printf("现在准备打字训练，您还有三秒钟的准备时间\n");
    for (i = 3; i >0; i--) {
        printf("%d...\n",i);
        fflush(stdout);
        Sleep(1000);
    }
    printf("现在开始打字训练\n");
    fflush(stdout);
    time_t start = time(0);
    scanf("%s",ans);
    time_t end = time(0);
    time_t cost = end - start;
    if ((answer = fopen("E:\\design\\answer.txt", "w")) == NULL) {
        perror("FILE ANSWER OPEN ERROR!");
    }else {
        fprintf(answer, "%s", ans);
        fclose(answer);
    }
    for(i = 0;i < strlen(ans);i++){
        if(pas[i] == ans[i]){
            count++;
        }
    }
    float len= strlen(ans);
    printf("您的打字的正确率为：%.2f \% ,所用的时间为：%ds",(count/ len)*100,cost);
    return 0;
}

