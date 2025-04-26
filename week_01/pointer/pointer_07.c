#include <stdio.h>

void changeNum(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;

}

int main(void){
    int a, b;
    printf("숫자 1 : ");
    scanf_s("%d",&a);
    printf("숫자 2 : ");
    scanf_s("%d",&b);
    printf("바꾸기 전\n숫자 1 : %d, 숫자 2 : %d\n", a, b);
    changeNum(&a, &b);
    printf("바꾼 후\n숫자 1 : %d, 숫자 2 : %d\n", a, b);

    return 0;
}