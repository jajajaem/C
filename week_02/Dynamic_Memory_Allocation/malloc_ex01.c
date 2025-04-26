#include <stdio.h>
#include <stdlib.h>

int main(){
    int *arr_m = (int*)malloc(sizeof(int)*5); //int형 5칸 동적 할당(malloc)
    int *arr_c = (int*)calloc(5, sizeof(int)); //int형 5칸 동적 할당(calloc)

    for(int i = 0; i < 5; i++){
        printf("%d\n", arr_m[i]);
        printf("%d\n", arr_c[i]);
    }

    arr_m = (int*)realloc(arr_m, sizeof(int)*7); //7칸으로 재할당 시도도

    for(int i = 0; i < 7; i++){
        printf("%d\n", arr_m[i]);
    }
    free(arr_m);
    free(arr_c);
}