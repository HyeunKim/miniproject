#include "product.h"

// 제품을 추가하는 함수
int createProduct(Product *p){
	printf("제품명은? ");
	scanf("%s", p->name);
	getchar();

	printf("해당 제품의 설명은? ");
	scanf("%s", p->contents);
	getchar();
	
	printf("중량은? ");
	scanf("%s", p->weight);
	getchar();

	printf("판매가격은? ");
	scanf("%d", &p->price);
	getchar();

	printf("배송방법은? (1: 새벽배송, 2: 택배배송) ");
	scanf("%d", &p->delivery);
	getchar();

	return 1;
}

// 하나의 제품 출력 함수
int readProduct(Product p){
	printf("%s %s\n%s\n%d원\n\n배송 방법", p.name, p.weight,  p.contents, p.price);
	if (p.delivery == 1)
		printf("\t새벽 배송\n");
	else
		printf("\t택배 배송\n");

	return 1;
}

// 제품 업데이트하는 함수
int updateProduct(Product *p){
	printf("제품명은? ");
	scanf("%s", p->name);
	getchar();

	printf("해당 제품의 설명은? ");
	scanf("%s", p->contents);
	getchar();

	printf("중량은? ");
	scanf("%s", p->weight);
	getchar();

	printf("판매가격은? ");
	scanf("%d", &p->price);

	printf("배송방법은? (1: 새벽배송, 2: 택배배송) ");
	scanf("%d", &p->delivery);

	printf("=> 수정됨!\n");

	return 1;	
}

// 제품을 삭제하는 함수
int deleteProduct(Product *p){
	p->price = -1;

	printf("=> 삭제됨!\n");

	return 1;
}
