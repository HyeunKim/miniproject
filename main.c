#include "product.h"
#include "manager.h"

// 함수 테스트 위한 메인 함수
int main(){
	Product plist[20]; 	// 20개 품목까지 관리
	int index = 0; 		// 데이터 번호
	int count = 0, menu;

#ifdef DEBUG
	printf("=> DEBUGMODE\n");
#endif

	while(1){
		menu = selectMenu();
		if(menu == 0) break;
		if(menu == 1 || menu == 3 || menu == 4)
			if(count == 0) continue;
		if(menu == 1){
			if(count > 0)
				listProduct(plist, index);
		}
		else if (menu == 2){
			int addok = createProduct(&plist[index]);
			if(addok == 1){
				index++;
				count++;
				printf("추가됨!\n");
			}
		}
		else if (menu == 3){
			int no = selectDataNo(plist, index);
			if(no == 0){
				printf("=> 취소됨!\n");
				continue;
			}
			updateProduct(&plist[no-1]);
		}
		else if (menu == 4){
			int no = selectDataNo(plist, index);
			if(no == 0){
				printf("=> 취소됨!\n");
				continue;
			}
			int deleteok;
			printf("정말로 삭제하시겠습니까?(삭제: 1)");
			scanf("%d", &deleteok);
			if(deleteok == 1){
				if(deleteProduct(&plist[no-1]))
					count--;
			}
		}
		else if(menu == 5){
			saveData(plist, index);
		}
		else if(menu == 6){
			int searchno;

			printf("검색할 방법\n\t1: 이름\n\t2: 중량\n\t3. 내용\n : ");
			scanf("%d", &searchno);
			if(searchno == 1){
				searchProduct(plist, index);
			}
			else if(searchno == 2){
				searchWeight(plist, index);
			}
			else if (searchno == 3){
				searchContents(plist, index);
			}
		}
	}
	printf("종료됨!\n");

	return 0;
}

