#include "product.h"
#include "manager.h"

// 등록된 전체 제품 리스트 출력
void listProduct(Product *p, int count){
	for(int i = 0; i<count; i++){
		if(p[i].price == -1) continue;
		printf("- %2d -\n", i+1);
		readProduct(p[i]);
	}
	printf("\n");
}

// 제품이름 검색
void searchProduct(Product *p, int count){
	int scnt = 0;
	char search[20];

	printf("검색할 이름? ");
	scanf("%s", search);

	for(int i = 0; i<count; i++){
		if(p[i].price == -1) continue;
		if(strstr(p[i].name, search)){
			printf("%2d ", i+1);
			readProduct(p[i]);
			scnt ++;
		}
	}
	if(scnt == 0)
		printf("=> 검색된 데이터 없음! \n");
}

// 제품 중량 검색
void searchWeight(Product *p, int count){
	int scnt = 0;
	char search[20];

	printf("검색할 중량? ");
	scanf("%s", search);

	for(int i = 0; i<count; i++){
		if(p[i].price == -1) continue;
		if(strstr(p[i].weight, search)){
			printf("%2d ", i+1);
			readProduct(p[i]);
			scnt ++;
		}
	}
	if(scnt == 0)
		printf("=> 검색된 데이터 없음! \n");
}

// 제품 내용 검색
void searchContents(Product *p, int count){
	int scnt = 0;
	char search[20];

	printf("검색할 내용? ");
	scanf("%s", search);

	for(int i = 0; i<count; i++){
		if(p[i].price == -1) continue;
		if(strstr(p[i].contents, search)){
			printf("%2d ", i+1);
			readProduct(p[i]);
			scnt ++;
		}
	}
	if(scnt == 0)
		printf("=> 검색된 데이터 없음! \n");
}

// 제품 데이터 파일에 저장하는 함수
void saveData(Product *p, int count){
	FILE *fp;
	fp = fopen("product.txt", "wt");

#ifdef DEBUG
	printf("저장할 데이터의 수 : %d\n",count);
#endif

	for(int i = 0; i<count; i++){
		if(p[i].price == -1) continue;
		fprintf(fp, "%s %s %s %d %d\n", p[i].name, p[i].contents, p[i].weight, p[i].price, p[i].delivery);
	}

	fclose(fp);
	printf("=> 저장됨!\n");
}

// 파일로부터 데이터 불러오는 함수
void readData(int count){
	char buffer[100];

	printf("%s\n", buffer);
	FILE *fp;
	fp = fopen("product.txt", "wt");

	for(int i = 0; i<count; i++){
		fgets(buffer, sizeof(buffer), fp); 	// product.txt에서 문자열을 읽음
		printf("%s\n", buffer);
	}

	fclose(fp);
}

// 메뉴 고르는 함수
int selectMenu(){
	int menu;

	printf("1. 조회\n");
	printf("2. 추가\n");
	printf("3. 수정\n");
	printf("4. 삭제\n");
	printf("5. 파일저장\n");
	printf("6. 검색\n");
	printf("0. 종료\n\n");

	printf("=> 원하는 메뉴는? ");
	scanf("%d", &menu);

#ifdef DEBUG
        printf("고른 번호는 : %d\n", menu);
#endif
	return menu;
}

// 데이터 번호 고르는 함수
int selectDataNo(Product *p, int count){
	int no;
	listProduct(p, count);

	printf("번호는 (취소: 0)? ");
	scanf("%d", &no);

	return no;
}
