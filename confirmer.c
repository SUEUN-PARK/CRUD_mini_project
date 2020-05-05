#include <stdio.h>
#include "corona.h"

// 코로나 확진자 명단 한 칸 추가
int createCorona(Corona* c)
{
    printf("이름: ");
    scanf(" %s", c->name);

    printf("나이: ");
    scanf(" %d", &c->age);

    do{
        printf("성별[M/F]: ");
        scanf(" %c", &c->gender);

        if(!(c->gender == 'M' || c->gender == 'F'))
            printf("Error : 잘못된 입력입니다!\n");
    }while(!(c->gender == 'M' || c->gender == 'F'));

    printf("거주지: ");
    scanf(" %s", c->residence);

    printf("확진날짜: ");
    scanf(" %s", c->date);

    printf("격리시설: ");
    scanf(" %[^\n]s", c->hospital);

    do{
        printf("국내감염[Y/N]: ");
        scanf(" %c", &c->domestic);

        if(!(c->domestic == 'Y' || c->domestic == 'N'))
            printf("Error : 잘못된 입력입니다!\n");
    }while(!(c->domestic == 'Y' || c->domestic == 'N'));

    printf("\n=> 추가 성공!\n");

    return 1;
}

// 코로나 확진자 명단 조회(단일 데이터)
void readCorona(Corona c){
	printf("%s %s %c   %2d세 %s %s %c\n", c.residence, c.name, c.gender, c.age, c.date, c.hospital, c.domestic);
}

// 코로나 확진자 명단 수정 (selectIndex 활용)
void updateCorona(Corona* c){
    printf("이름: ");
    scanf(" %s", c->name);

    printf("나이: ");
    scanf(" %d", &c->age);

    do{
        printf("성별[M/F]: ");
        scanf(" %c", &c->gender);

        if(!(c->gender == 'M' || c->gender == 'F'))
            printf("Error : 잘못된 입력입니다!\n");
    }while(!(c->gender == 'M' || c->gender == 'F'));

    printf("거주지: ");
    scanf(" %s", c->residence);

    printf("확진날짜: ");
    scanf(" %s", c->date);

    printf("격리시설: ");
    scanf(" %[^\n]s", c->hospital);

    do{
        printf("국내감염[Y/N]: ");
        scanf(" %c", &c->domestic);

        if(!(c->domestic == 'Y' || c->domestic == 'N'))
            printf("Error : 잘못된 입력입니다!\n");
    }while(!(c->domestic == 'Y' || c->domestic == 'N'));

    printf("\n=> 수정 성공!\n");
}

// 코로나 확진자 명단 삭제 (selectIndex 활용)
// 삭제 방식은 해당 memory를 free() 후 NULL
int deleteCorona(Corona* c[], int no){ 
    int deleteok;

    printf("정말로 삭제하시겠습니까? (삭제:1) ");
	scanf(" %d", &deleteok);

    if(deleteok == 1){
        free(c[no]);
        c[no] = NULL;
        printf("=> 삭제됨!\n");
    }
    else{
        printf("=> 취소됨!\n");
    }
    
    return 1;
}

// 명단 저장
void saveData(Corona* c[], int count){
	FILE *fp = fopen(CORONA, "wt");

	for(int i = 0; i < count; i++){
		if(c[i] != NULL){
			fprintf(fp, "%s %s %c %d %s %c %s\n", c[i]->residence, c[i]->name, c[i]->gender, c[i]->age, c[i]->date, c[i]->domestic, c[i]->hospital);
        	}
    	}

    	fclose(fp);

	printf("=> 저장됨!\n");	
}

// 명단 로딩
int loadData(Corona* c[])
{ 
    int i = 0;
    FILE* fp = fopen(CORONA, "rt");
    if(fp == NULL)
    {
        printf("저장된 데이터 없음!\n");
        return 0;
    }

    while(!feof(fp))
    {
	c[i]=(Corona*)malloc(sizeof(Corona));
        fscanf(fp, "%s %s %c %d %s %c %[^\n]s", c[i]->residence, c[i]->name, &(c[i]->gender),&(c[i]->age), c[i]->date, &(c[i]->domestic), c[i]->hospital);
        i++;
    }

    fclose(fp);
    printf("로딩 성공!\n");    

    return --i;
}
