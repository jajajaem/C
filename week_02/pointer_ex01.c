#include <stdio.h>
//배열 뒤집기문제. 포인터
void reverseArray(int *arr, int size){
    int *start = arr;
    int *end = arr + size - 1;
    int temp;
    while(start < end){
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main(){
    int nums[] = {10, 20, 30, 40, 50};
    reverseArray(nums, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d ", nums[i]);
    }
    return 0;
}