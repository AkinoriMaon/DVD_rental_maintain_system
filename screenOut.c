// Visual Studio에서 작성된 코드입니다.

#include "common.h"
#include "cusInfo.h"
#include "dvdInfo.h"

void ShowMenu()
{
	system("cls"); // <stdlib.h>

	puts("---------- 메뉴 ----------");
	puts("1. 신규가입");
	puts("2. 고객검색");
	puts("--------------------------");
	puts("3. DVD 등록");
	puts("4. DVD 검색");
	puts("--------------------------");
	puts("5. DVD 대여");
	puts("6. DVD 반납");
	puts("--------------------------");
	puts("7. DVD 대여 고객 전체 조회");
	puts("8. 종료");
	puts("--------------------------");

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
	switch (pDVD->gerne)
	{
		case ACTION:
			puts("│ ▶ 장르 : 액션");
			break;
		case COMIC:
			puts("│ ▶ 장르 : 코믹");
			break;
		case SF:
			puts("│ ▶ 장르 : SF");
			break;
		case ROMANTIC:
			puts("│ ▶ 장르 : 로맨틱");
			break;
	}
	puts("└────────────────────────────");

	getchar();
}

void ShowCustomerInfoContinue(cusInfo* pCus)
{
	puts("┌────────────────────────────");
	printf("│ ▶ ID : %s\n", pCus->ID);
	printf("│ ▶ 이름 : %s\n", pCus->name);
	printf("│ ▶ 전화번호 : %s\n", pCus->phoneNum);
	puts("└────────────────────────────");
}