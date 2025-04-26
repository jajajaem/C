#include <stdio.h>

void changeDouble(int* p){
    *p = *p * 2;
}

int main(void){
    int num;
    printf("숫자를 입력하세요 : ");
    scanf_s("%d", &num);
    changeDouble(&num);
    printf("%d", num);
    return 0;
}