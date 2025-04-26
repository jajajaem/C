#include <stdio.h>
void ex_01(){
    //초 분 계산기. 연산자
    int num;
    printf("초를 입력하세요 : ");
    scanf_s("%d",&num);
    int Min, Resec;
    Min = num / 60;
    Resec = num % 60;
    printf("%d초는 %d분 %d초입니다.\n",num, Min, Resec); // printf는 문자의 개수를 int형으로 반환
}

void ex_02(){
    //거스름돈 계산. 연산자
    int num1, num2;
    int *p1, *p2;
    int change, change_1, change_2, change_3, change_4;
    
    p1 = &num1;
    p2 = &num2;
    printf("물건 값 : ");
    scanf_s("%d", p1);
    printf("지불 값 : ");
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

    printf("거스름돈 : 오천원권 %d장, 천원권 %d장, 오백원권 %d개, 백원권 %d개, 나머지 %d원 입니다.\n",change_1, change_2, change_3, change_4, change);
}

void ex_03(){
    //연도를 입력해 윤년인지 계산. 조건문
    int year;
    int *p = &year;
    printf("연도를 입력하세요 : ");
    scanf_s("%d", p);
    int result = ((*p % 100 != 0) && (*p % 4 == 0) || (*p % 400 == 0));
    if(result) printf("%d는 윤년입니다.", *p);
    else printf("%d는 윤년이 아닙니다.", *p);
}

void ex_04(){
    //문자를 입력해 그 문자가 어떤 형태인지 인식. 조건문
    char ch;
    printf("문자를 입력하세요 : ");
    scanf_s("%c", &ch);
    if(ch >= 'A' || ch <= 'Z') printf("%c는 대문자입니다.\n", ch);
    else if(ch >= 'a' || ch <= 'z') printf("%c는 소문자입니다.\n", ch);
    else if(ch >= '0' || ch <= '9') printf("%c는 숫자입니다.\n", ch);
    else printf("%c는 기타 문자입니다.\n", ch);
}

void ex_05(){
    //주사위 3개의 값을 입력해 각 값마다 각기 다른 상금 적용. 조건문
    int a,b,c,mon;
    printf("주사위 값을 순서대로 입력하세요 : ");
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
    printf("상금 : %d\n", mon);
}

void ex_06(){
    //1부터 5까지 더하기. 반복문
    int sum = 0;
    for(int i = 1; i <= 5; i++){
        sum += i;
        printf("%d번째 a = %d\n",i ,sum);
    }
}

void ex_07(){
    //ex_06 while 사용. 반복문
    int num = 1, sum = 0;
    while(num <= 5){
        printf("%d + %d = ", sum, num);
        sum += num;
        num++;
        printf("%d\n", sum);
    }
}

void ex_08(){
    //별 찍기. 반복문
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