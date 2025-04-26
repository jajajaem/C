#include <stdio.h>
#include <stdlib.h>
//구조체 포인터 기본 사용
typedef struct{
    int age;
    float height;
} Person;

int main(){
    Person *p = (Person*)malloc(sizeof(Person));

    if(p == NULL) printf("할당 실패");

    //구조체 멤버에 접근
    p->age = 25;
    p->height = 175.5;

    printf("나이 : %d\n", p->age);
    printf("키 : %.1fcm\n", p->height);

    free(p);

    return 0;
    
}
