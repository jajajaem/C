#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *title; //����ü���� �������� ���ڿ� ���� �����ϰ� ����
    int pages;
} Book;

int main(){
    Book b;
    char temp[100]; //���ڿ��� �Է¹ޱ� ���� �ӽ� ����

    printf("å ���� : ");
    fgets(temp, sizeof(temp), stdin); //scanf�� �޸� ���� ���� ����

    size_t len = strlen(temp);
    if(temp[len - 1] == '\n') temp[len - 1] = '\0';

    b.title = (char*)malloc(len);
    strcpy(b.title, temp); //���ڿ� �������� 

    b.pages = 300;

    printf("å ���� : %s\n������ �� : %d", b.title, b.pages);

    free(b.title);
    
    return 0;
}