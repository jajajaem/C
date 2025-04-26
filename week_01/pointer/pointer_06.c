#include <stdio.h>

void changeDouble(int* p){
    *p *= *p;
}

int main(void){
    int num;
    printf("숫자를 입력하세요 : ");
    scanf_s("%d", &num);
    changeDouble(&num);
    printf("제곱 : %d\n", num);

    return 0;
}