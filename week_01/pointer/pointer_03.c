#include <stdio.h>

int main(void){
    int i = 10;
    int* p = &i;
    printf("i = %d\n", i);
    *p = 20; // 포인터를 통한 변수의 값 변경
    printf("i = %d\n", i);
    return 0;
}