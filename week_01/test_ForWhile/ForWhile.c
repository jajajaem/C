#include <stdio.h>
//이건 굳이 할 필요가 없었다.
void ex01(){
    //while 구구단
    int num, i = 1;
    printf("구구단 단 입력 : ");
    scanf_s("%d", &num);
    while(i <= 9){
        printf("%d * %d = %d\n", num, i, num * i);
        i++;
    }
}

void ex02(){
    //제곱값 while. 왜하는건지 모르겠음
    int num, i = 1;
    printf("제곱값 초기 값 : ");
    scanf_s("%d", &num);

    while(i <= 10){
        printf("%d의 제곱 %d\n", num, num * num);
        i++;
        num++;
    }
}

void ex03(){
    //입력한 수까지의 숫자의 합.
    int num, i = 0, j = 1;
    printf("마지막 값을 입력하세요 : ");
    scanf_s("%d",&num);
    while(j <= num){
        printf("%d + %d = %d\n", i, j, i+j);
        i += j;
        j++;
    }
}

void ex04(){
    //짝수 더하기
    int i = 1, num, sum = 0;
    printf("숫자를 입력하세요 : ");
    scanf_s("%d",&num);

    while(i <= num){
        if(i % 2 == 0) sum += i;
        printf("현재 값 : %d\n", sum);
        i++;
    }
}

int main(){
    ex04();
    return 0;
}
