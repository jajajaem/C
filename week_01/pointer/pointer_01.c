#include <stdio.h>

int main(){
    //������ ���� 1
    int i = 3000;
    int* p = NULL; //������ ���� �ʱ�ȭ
    p = &i; //���� i�� �ּҰ� ������ p�� ����
    printf("i = %d\n", i); //������ �� ���
    printf("&i = %u\n\n", &i); //������ �ּ� ���
    printf("p = %u\n", p); //�������� �� ���
    printf("*p = %d\n\n", *p); //�����͸� ���� �������� �� ���
    return 0;
}