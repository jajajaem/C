#include <stdio.h>

int main(void){
    int num;
    int* numP = &num;
    printf("숫자를 입력하세요 : ");
    scanf_s("%d", &num);
    printf("num : %d\n*numP : %d\n\n", num, *numP); // 값 출력
    printf("&num : %d\nnumP : %d\n\n", &num, numP); // 주소 출력
    return 0;
    
}