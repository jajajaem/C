#include <stdio.h>
#include <stdlib.h>
//����ü ������ �⺻ ���
typedef struct{
    int age;
    float height;
} Person;

int main(){
    Person *p = (Person*)malloc(sizeof(Person));

    if(p == NULL) printf("�Ҵ� ����");

    //����ü ����� ����
    p->age = 25;
    p->height = 175.5;

    printf("���� : %d\n", p->age);
    printf("Ű : %.1fcm\n", p->height);

    free(p);

    return 0;
    
}
