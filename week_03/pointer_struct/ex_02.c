#include <stdio.h>
#include <stdlib.h>
//구조체 배열 동적 할당
typedef struct{
    char name[20];
    int score;
} Student;

int main(){
    int count = 3;
    Student *arr = (Student*)malloc(count * sizeof(Student));

    if(arr == NULL) printf("할당 실패");

    for(int i = 0; i < count; i++){
        printf("%d번째 학생 이름 입력 : ", i + 1);
        scanf_s("%s", arr[i].name);
        printf("점수 입력 : ");
        scanf_s("%d", &arr[i].score);
    }

    printf("입력한 학생의 정보:\n");
    for(int i = 0; i < count; i++){
        printf("%s, %d점\n", arr[i].name, arr[i].score);
    }

    free(arr);

    return 0;
}