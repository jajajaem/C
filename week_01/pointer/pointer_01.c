#include <stdio.h>

int main(){
    //포인터 예제 1
    int i = 3000;
    int* p = NULL; //포인터 변수 초기화
    p = &i; //변수 i의 주소가 포인터 p로 대입
    printf("i = %d\n", i); //변수의 값 출력
    printf("&i = %u\n\n", &i); //변수의 주소 출력
    printf("p = %u\n", p); //포인터의 값 출력
    printf("*p = %d\n\n", *p); //포인터를 통한 간접참조 값 출력
    return 0;
}