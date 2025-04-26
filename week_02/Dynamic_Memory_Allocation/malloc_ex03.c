#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void malloc_01(){
    //����� ������ �迭 ����
    int arr[4] = {4, 3, 2, 1};
    int *pArr = (int*)malloc(sizeof(int) * 4);

    if(pArr == NULL){
        printf("malloc error");
    }

    for(int i = 0; i < 4; i++){
        pArr[i] = arr[i];
        printf("%d \n", pArr[i]);
    }

    free(pArr);
}

void malloc_02(){
    //���ڿ� ����
    char str[] = "hello"; // char *str = "hello"; �� ��밡��. ��� ���� �Ұ�
    char *copy = (char*)malloc(sizeof(str) + 1); //+1�� null���� �����

    if(copy == NULL){
        printf("malloc error");
    }

    strcpy(copy, str);
    printf("������ ���ڿ� : %s\n", copy); //%s�� ���ڿ� ��ü�̱⿡ copy�� �ּҰ� ������ ��. %c�� ��� *copy�� ����ϸ� ù��° ������ h ���

    free(copy);
}

void malloc_03(){
    //������� �Է��� �޾� �������� ���ڿ� ����
    char temp[100]; //�ӽ� ����
    printf("���ڿ��� �Է��ϼ��� : ");
    fgets(temp, sizeof(temp), stdin); //���ڿ� �Է� �Լ�. stdin�� ǥ���Է�(Ű����� �Է��� ����). ���͸� ġ�� \n���� �� ���߿� ���� �ʿ�.

    size_t len = strlen(temp); //size_t�� �޸� ũ�⳪ �ε��������� ����ϴ� ������Ÿ��. �޸� ���� ���꿡 �� �������̰� ǥ��.
    if(temp[len - 1] == '\n'){
        temp[len - 1] = '\0'; //��������. 
        len--; //���̵� ������
    }

    char *input = (char*)malloc(len + 1);

    if(input == NULL){
        printf("�޸� �Ҵ� ����\n");
    }

    strcpy(input, temp);
    printf("�Էµ� ���ڿ� : %s\n", input);

    free(input);
}

void malloc_04(){
    //���ڿ� �迭(���ڿ� ���) ���� �Ҵ�
    size_t count = 3;
    const char *words[] = {"apple", "banana", "cherry"};
    char **list = (char**)malloc(count * sizeof(char*)); //���ڿ� �迭�� �ٷ�� ���� ������. list[0], list[1] ����� ����Ű�� ������

    if(list == NULL) printf("�޸� �Ҵ� ����\n");

    for(size_t i = 0; i < count; i++){
        list[i] =(char*)malloc(strlen(words[i]) + 1);//strlen���� ���̸� ���ϰ� �� �´� ũ���� �޸𸮸� malloc�� �Ҵ�.
        strcpy(list[i], words[i]);
        //���� �޸��� ���ڿ��� deep copy�ϴ� ����
    }

    printf("����� ���ڿ� ���:\n");
    for(size_t i = 0; i < count; i++){
        printf("- %s\n", list[i]);
        free(list[i]); //���� ����
    }
    free(list); //��ü ������ �迭 ����

}

void malloc_05(){
    //���ڿ� ����(concat) + malloc
    const char *a = "hello "; //char *Ÿ���� �б� ���� �޸𸮿� ����ǹǷ� ������ �� �ִ� �����ͷ� ����. const�� ����ϸ� �������� �ʰڴٴ� �ǵ��� ���̹Ƿ� ��� �޼����� �ȶ�. ���Ҵ� �Ұ���
    const char *b = "friend";

    size_t len = strlen(a) + strlen(b);
    char *result = (char*)malloc(len + 1);

    if(result == NULL) printf("�޸� �Ҵ� ����\n");

    strcpy(result, a);
    strcat(result, b);

    

    free(result);
}
int main(){
    malloc_05();
    return 0;
}