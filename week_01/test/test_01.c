#include <stdio.h>
void ex_01(){
    //�� �� ����. ������
    int num;
    printf("�ʸ� �Է��ϼ��� : ");
    scanf_s("%d",&num);
    int Min, Resec;
    Min = num / 60;
    Resec = num % 60;
    printf("%d�ʴ� %d�� %d���Դϴ�.\n",num, Min, Resec); // printf�� ������ ������ int������ ��ȯ
}

void ex_02(){
    //�Ž����� ���. ������
    int num1, num2;
    int *p1, *p2;
    int change, change_1, change_2, change_3, change_4;
    
    p1 = &num1;
    p2 = &num2;
    printf("���� �� : ");
    scanf_s("%d", p1);
    printf("���� �� : ");
    scanf_s("%d", p2);
    change = *p2 - *p1;
    change_1 = change / 5000;
    change = change % 5000;
    change_2 = change / 1000;
    change = change % 1000;
    change_3 = change / 500;
    change = change % 500;
    change_4 = change / 100;
    change = change % 100;

    printf("�Ž����� : ��õ���� %d��, õ���� %d��, ������� %d��, ����� %d��, ������ %d�� �Դϴ�.\n",change_1, change_2, change_3, change_4, change);
}

void ex_03(){
    //������ �Է��� �������� ���. ���ǹ�
    int year;
    int *p = &year;
    printf("������ �Է��ϼ��� : ");
    scanf_s("%d", p);
    int result = ((*p % 100 != 0) && (*p % 4 == 0) || (*p % 400 == 0));
    if(result) printf("%d�� �����Դϴ�.", *p);
    else printf("%d�� ������ �ƴմϴ�.", *p);
}

void ex_04(){
    //���ڸ� �Է��� �� ���ڰ� � �������� �ν�. ���ǹ�
    char ch;
    printf("���ڸ� �Է��ϼ��� : ");
    scanf_s("%c", &ch);
    if(ch >= 'A' || ch <= 'Z') printf("%c�� �빮���Դϴ�.\n", ch);
    else if(ch >= 'a' || ch <= 'z') printf("%c�� �ҹ����Դϴ�.\n", ch);
    else if(ch >= '0' || ch <= '9') printf("%c�� �����Դϴ�.\n", ch);
    else printf("%c�� ��Ÿ �����Դϴ�.\n", ch);
}

void ex_05(){
    //�ֻ��� 3���� ���� �Է��� �� ������ ���� �ٸ� ��� ����. ���ǹ�
    int a,b,c,mon;
    printf("�ֻ��� ���� ������� �Է��ϼ��� : ");
    scanf_s("%d", &a);
    scanf_s("%d", &b);
    scanf_s("%d", &c);

    if(a == b && b == c) mon = 10000 + a * 1000;
    
    else if(a == b || a == c) mon = 1000 + a * 100;
    else if(b == c) mon = 1000 + b * 100;

    else{
        if(a > b && a > c) mon = a * 100;
        else if(b > a && b > c) mon = b * 100;
        else if(c > a && c > b) mon = c * 100;
    }
    printf("��� : %d\n", mon);
}

void ex_06(){
    //1���� 5���� ���ϱ�. �ݺ���
    int sum = 0;
    for(int i = 1; i <= 5; i++){
        sum += i;
        printf("%d��° a = %d\n",i ,sum);
    }
}

void ex_07(){
    //ex_06 while ���. �ݺ���
    int num = 1, sum = 0;
    while(num <= 5){
        printf("%d + %d = ", sum, num);
        sum += num;
        num++;
        printf("%d\n", sum);
    }
}

void ex_08(){
    //�� ���. �ݺ���
    for(int i = 0; i <= 7; i++){
        printf("\n");
        for(int k = 6; k >= i; k--) printf(" ");
        for(int j = 1; j <= i; j ++) printf("*");
    }
    printf("\n");
}

int main(void){
    //ex_01();
    //ex_02();
    //ex_03();
    //ex_04();
    //ex_05();
    //ex_06();
    //ex_07();
    //ex_08();
    return 0;
}