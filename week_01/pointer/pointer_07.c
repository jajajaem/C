#include <stdio.h>

void changeNum(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;

}

int main(void){
    int a, b;
    printf("���� 1 : ");
    scanf_s("%d",&a);
    printf("���� 2 : ");
    scanf_s("%d",&b);
    printf("�ٲٱ� ��\n���� 1 : %d, ���� 2 : %d\n", a, b);
    changeNum(&a, &b);
    printf("�ٲ� ��\n���� 1 : %d, ���� 2 : %d\n", a, b);

    return 0;
}