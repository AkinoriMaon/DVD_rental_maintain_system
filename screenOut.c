// Visual Studio에서 작성된 코드입니다.

#include "common.h"
#include "cusInfo.h"

void ShowMenu()
{
	system("cls"); // <stdlib.h>

	puts("------- 메뉴 -------");
	puts("1. 신규가입");
	puts("2. 고객검색");
	puts("3. 종료");
	puts("--------------------");

	fputs("선택 >> ", stdout);
}

void ShowCustomerInfo(cusInfo* pCus)
{
	puts("┌────────────────────────────");
	printf("│ ▶ ID : %s\n", pCus->ID);
	printf("│ ▶ 이름 : %s\n", pCus->name);
	printf("│ ▶ 전화번호 : %s\n", pCus->phoneNum);
	puts("└────────────────────────────");

	getchar();
}