#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void malloc_01(){
    //사이즈가 정해진 배열 복사
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
    //문자열 복사
    char str[] = "hello"; // char *str = "hello"; 도 사용가능. 대신 수정 불가
    char *copy = (char*)malloc(sizeof(str) + 1); //+1은 null문자 저장용

    if(copy == NULL){
        printf("malloc error");
    }

    strcpy(copy, str);
    printf("복사한 문자열 : %s\n", copy); //%s는 문자열 전체이기에 copy의 주소가 있으면 됨. %c일 경우 *copy를 사용하면 첫번째 글자인 h 출력

    free(copy);
}

void malloc_03(){
    //사용자의 입력을 받아 동적으로 문자열 저장
    char temp[100]; //임시 버퍼
    printf("문자열을 입력하세요 : ");
    fgets(temp, sizeof(temp), stdin); //문자열 입력 함수. stdin은 표준입력(키보드로 입력을 받음). 엔터를 치면 \n값이 들어가 나중에 제거 필요.

    size_t len = strlen(temp); //size_t는 메모리 크기나 인덱스용으로 사용하는 데이터타입. 메모리 관련 연산에 더 안정적이고 표준.
    if(temp[len - 1] == '\n'){
        temp[len - 1] = '\0'; //개행제거. 
        len--; //길이도 줄임임
    }

    char *input = (char*)malloc(len + 1);

    if(input == NULL){
        printf("메모리 할당 실패\n");
    }

    strcpy(input, temp);
    printf("입력된 문자열 : %s\n", input);

    free(input);
}

void malloc_04(){
    //문자열 배열(문자열 목록) 동적 할당
    size_t count = 3;
    const char *words[] = {"apple", "banana", "cherry"};
    char **list = (char**)malloc(count * sizeof(char*)); //문자열 배열을 다루기 위한 포인터. list[0], list[1] 등등을 가르키는 포인터

    if(list == NULL) printf("메모리 할당 실패\n");

    for(size_t i = 0; i < count; i++){
        list[i] =(char*)malloc(strlen(words[i]) + 1);//strlen으로 길이를 구하고 딱 맞는 크기의 메모리를 malloc에 할당.
        strcpy(list[i], words[i]);
        //동적 메모리의 문자열을 deep copy하는 과정
    }

    printf("복사된 문자열 목록:\n");
    for(size_t i = 0; i < count; i++){
        printf("- %s\n", list[i]);
        free(list[i]); //각각 해제
    }
    free(list); //전체 포인터 배열 해제

}

void malloc_05(){
    //문자열 연결(concat) + malloc
    const char *a = "hello "; //char *타입은 읽기 전용 메모리에 저장되므로 수정할 수 있는 포인터로 보임. const를 사용하면 수정하지 않겠다는 의도가 보이므로 경고 메세지가 안뜸. 재할당 불가가
    const char *b = "friend";

    size_t len = strlen(a) + strlen(b);
    char *result = (char*)malloc(len + 1);

    if(result == NULL) printf("메모리 할당 실패\n");

    strcpy(result, a);
    strcat(result, b);

    

    free(result);
}
int main(){
    malloc_05();
    return 0;
}