#include <stdio.h>
#include <stdlib.h>
//����ü �迭 ���� �Ҵ�
typedef struct{
    char name[20];
    int score;
} Student;

int main(){
    int count = 3;
    Student *arr = (Student*)malloc(count * sizeof(Student));

    if(arr == NULL) printf("�Ҵ� ����");

    for(int i = 0; i < count; i++){
        printf("%d��° �л� �̸� �Է� : ", i + 1);
        scanf_s("%s", arr[i].name);
        printf("���� �Է� : ");
        scanf_s("%d", &arr[i].score);
    }

    printf("�Է��� �л��� ����:\n");
    for(int i = 0; i < count; i++){
        printf("%s, %d��\n", arr[i].name, arr[i].score);
    }

    free(arr);

    return 0;
}