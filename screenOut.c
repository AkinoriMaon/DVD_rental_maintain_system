// Visual Studio에서 작성된 코드입니다.

#include "common.h"
#include "cusInfo.h"
#include "dvdInfo.h"

void ShowMenu()
{
	system("cls"); // <stdlib.h>

	puts("------- 메뉴 -------");
	puts("1. 신규가입");
	puts("2. 고객검색");
	puts("--------------------");
	puts("3. DVD 등록");
	puts("4. DVD 검색");
	puts("--------------------");
	puts("5. 종료");
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

void ShowDVDInfo(dvdInfo* pDVD)
{
	puts("┌────────────────────────────");
	printf("│ ▶ ISBN : %s\n", pDVD->ISBN);
	printf("│ ▶ 제목 : %s\n", pDVD->title);
	printf("│ ▶ 장르 : %d\n", pDVD->gerne);
	puts("└────────────────────────────");

	getchar();
}