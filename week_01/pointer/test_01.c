#include <stdio.h>
#define PI 3

int main(){
    int a = 3;
    int* p = &a;

    printf("%d\n",*p);
    (*p)++;
    printf("%d\n",*p);
    printf("%d\n",*p + PI);
    

    return 0;
}