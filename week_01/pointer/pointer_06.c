#include <stdio.h>

void changeDouble(int* p){
    *p *= *p;
}

int main(void){
    int num;
    printf("���ڸ� �Է��ϼ��� : ");
    scanf_s("%d", &num);
    changeDouble(&num);
    printf("���� : %d\n", num);

    return 0;
}