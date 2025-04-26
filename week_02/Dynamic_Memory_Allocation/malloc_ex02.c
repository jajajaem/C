#include <stdio.h>
#include <stdlib.h>

int main(){
    int stu, sum = 0, avg = 0;

    printf("학생의 수 : ");
    scanf_s("%d", &stu);
    printf("\n");

    int *stuPtr1 = (int*)malloc(sizeof(int)*stu);

    for(int i = 0; i < stu; i++){
        printf("학생%d : ", i + 1);
        scanf_s("%d", &stuPtr1[i]);
        sum += stuPtr1[i];
    }
    
    avg = sum / stu;
    printf("평균 : %d\n", avg);
    free(stuPtr1);

    return 0;
}
