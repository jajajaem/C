#include <stdio.h>
#include <stdlib.h>

int main(){
    int stu, sum = 0, avg = 0;

    printf("�л��� �� : ");
    scanf_s("%d", &stu);
    printf("\n");

    int *stuPtr1 = (int*)malloc(sizeof(int)*stu);

    for(int i = 0; i < stu; i++){
        printf("�л�%d : ", i + 1);
        scanf_s("%d", &stuPtr1[i]);
        sum += stuPtr1[i];
    }
    
    avg = sum / stu;
    printf("��� : %d\n", avg);
    free(stuPtr1);

    return 0;
}
