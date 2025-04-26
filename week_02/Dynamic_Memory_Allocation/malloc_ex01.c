#include <stdio.h>
#include <stdlib.h>

int main(){
    int *arr_m = (int*)malloc(sizeof(int)*5); //int�� 5ĭ ���� �Ҵ�(malloc)
    int *arr_c = (int*)calloc(5, sizeof(int)); //int�� 5ĭ ���� �Ҵ�(calloc)

    for(int i = 0; i < 5; i++){
        printf("%d\n", arr_m[i]);
        printf("%d\n", arr_c[i]);
    }

    arr_m = (int*)realloc(arr_m, sizeof(int)*7); //7ĭ���� ���Ҵ� �õ���

    for(int i = 0; i < 7; i++){
        printf("%d\n", arr_m[i]);
    }
    free(arr_m);
    free(arr_c);
}