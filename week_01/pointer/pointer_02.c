#include <stdio.h>

int main(){
    int x = 10, y = 20;
    int* p = &x; //포인터 변수 선언, 변수 x의 주소를 포인터 p에 대입
    printf("p = %d\n", p); //포인터의 값 출력
    printf("*p = %d\n\n", *p); //포인터를 통한 간접 참조 값 출력

    p = &y; //변수 y의 주소를 포인터 p에 대입입
    printf("p = %d\n", p); //포인터의 값 출력
    printf("*p = %d\n\n", *p); //포인터를 통한 간접 참조 값 출력
    return 0;
}