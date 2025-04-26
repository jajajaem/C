#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *title; //구조체에서 동적으로 문자열 저장 가능하게 설계
    int pages;
} Book;

int main(){
    Book b;
    char temp[100]; //문자열을 입력받기 위한 임시 버퍼

    printf("책 제목 : ");
    fgets(temp, sizeof(temp), stdin); //scanf와 달리 공백 또한 받음

    size_t len = strlen(temp);
    if(temp[len - 1] == '\n') temp[len - 1] = '\0';

    b.title = (char*)malloc(len);
    strcpy(b.title, temp); //문자열 깊은복사 

    b.pages = 300;

    printf("책 제목 : %s\n페이지 수 : %d", b.title, b.pages);

    free(b.title);
    
    return 0;
}