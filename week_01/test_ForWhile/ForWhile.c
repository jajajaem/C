#include <stdio.h>
//�̰� ���� �� �ʿ䰡 ������.
void ex01(){
    //while ������
    int num, i = 1;
    printf("������ �� �Է� : ");
    scanf_s("%d", &num);
    while(i <= 9){
        printf("%d * %d = %d\n", num, i, num * i);
        i++;
    }
}

void ex02(){
    //������ while. ���ϴ°��� �𸣰���
    int num, i = 1;
    printf("������ �ʱ� �� : ");
    scanf_s("%d", &num);

    while(i <= 10){
        printf("%d�� ���� %d\n", num, num * num);
        i++;
        num++;
    }
}

void ex03(){
    //�Է��� �������� ������ ��.
    int num, i = 0, j = 1;
    printf("������ ���� �Է��ϼ��� : ");
    scanf_s("%d",&num);
    while(j <= num){
        printf("%d + %d = %d\n", i, j, i+j);
        i += j;
        j++;
    }
}

void ex04(){
    //¦�� ���ϱ�
    int i = 1, num, sum = 0;
    printf("���ڸ� �Է��ϼ��� : ");
    scanf_s("%d",&num);

    while(i <= num){
        if(i % 2 == 0) sum += i;
        printf("���� �� : %d\n", sum);
        i++;
    }
}

int main(){
    ex04();
    return 0;
}
