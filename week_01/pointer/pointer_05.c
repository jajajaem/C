#include <stdio.h>

int main(void){
    int num;
    int* numP = &num;
    printf("���ڸ� �Է��ϼ��� : ");
    scanf_s("%d", &num);
    printf("num : %d\n*numP : %d\n\n", num, *numP); // �� ���
    printf("&num : %d\nnumP : %d\n\n", &num, numP); // �ּ� ���
    return 0;
    
}