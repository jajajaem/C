#include <stdio.h>

void changeDouble(int* p){
    *p = *p * 2;
}

int main(void){
    int num;
    printf("���ڸ� �Է��ϼ��� : ");
    scanf_s("%d", &num);
    changeDouble(&num);
    printf("%d", num);
    return 0;
}