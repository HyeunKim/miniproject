#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef struct{
	char name[100]; 	// 제품명
	char contents[100];	// 설명
	char weight[50];	// 중량
	int price;		// 판매가격
	int delivery;		// 배송방법 (1: 새벽배송, 2: 택배배송)
} Product;

int createProduct(Product *p);
int readProduct(Product p);
int updateProduct(Product *p);
int deleteProduct(Product *p);
