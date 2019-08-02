// Visual Studio에서 작성된 코드입니다.

#include "common.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"
#include "screenOut.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"

// 신규 DVD 등록

void RegistDVD()
{
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int gerne;
	int check = 0; // 가입된 ISBN인지 확인하기 위한 변수

	fputs("ISBN 입력 : ", stdout);
	gets_s(ISBN, ISBN_LEN);

	check = IsRegistISBN(ISBN);
	if (check != 0)
	{
		puts("해당 ISBN은 사용 중에 있습니다.");
		getchar();
		return;
	}

	fputs("제목 입력 : ", stdout);
	gets_s(title, TITLE_LEN);

	fputs("장르 입력 (액션 1, 코믹 2, SF 3, 로맨틱 4) : ", stdout);
	scanf_s("%d", &gerne);
	getchar();

	AddDVDInfo(ISBN, title, gerne);

	puts("등록이 완료되었습니다.");
	getchar();
}

// ISBN을 통한 회원 정보 검색

void SearchDVDInfo()
{
	char ISBN[ISBN_LEN];
	dvdInfo* temp;

	fputs("찾는 ISBN 입력 : ", stdout);
	gets_s(ISBN, ISBN_LEN);

	temp = GetDVDPtrByISBN(ISBN);

	if (temp != (dvdInfo*)NULL)
	{
		ShowDVDInfo(temp);
	}
	else
	{
		puts("찾는 ISBN이 없습니다.");
		getchar();
	}
}

void RentalDVD()
{
	char ISBN[ISBN_LEN];
	char ID[ID_LEN];
	unsigned int date;
	int check1, check2;
	dvdInfo* temp;
	cusInfo* temp2;

	fputs("대여 DVD ISBN 입력 : ", stdout);
	gets_s(ISBN, ISBN_LEN);

	check1 = IsRegistISBN(ISBN);
	if (check1 == 0)
	{
		puts("등록되지 않은 DVD입니다.");
		getchar();
		return;
	}

	check2 = GetDVDRentState(ISBN);

	if (check2 == RENTED)
	{
		puts("대여중입니다.");
		getchar();
		return;
	}

	puts("대여가 가능합니다.");
	puts("대여 과정을 진행합니다.");

	fputs("대여 고객 ID 입력 : ", stdout);
	gets_s(ID, ID_LEN);

	temp2 = GetCusPtrByID(ID);
	if (temp2 == (cusInfo*)NULL)
	{
		puts("가입되지 않은 ID입니다. 대여를 진행할 수 없습니다.");
		getchar();
		return;
	}

	fputs("날짜 입력 : ", stdout);
	scanf_s("%u", &date);
	while (getchar() != '\n');

	SetDVDRented(ISBN, ID, date);
	
	puts("대여가 완료되었습니다.");
	getchar();
}

void ReturnDVD()
{
	char ISBN[ISBN_LEN];
	dvdInfo* ISBN_check;
	int return_check;

	fputs("반납할 DVD ISBN 입력 : ", stdout);
	gets_s(ISBN, ISBN_LEN);

	ISBN_check = IsRegistISBN(ISBN);
	if (ISBN_check == NULL)
	{
		puts("등록되지 않은 ISBN입니다.");
		getchar();
		return;
	}

	return_check = GetDVDRentState(ISBN);
	if (return_check == RETURNED)
	{
		puts("이미 반납된 DVD입니다.");
		getchar();
		return;
	}

	SetDVDReturned(ISBN);

	puts("반납이 완료되었습니다.");
	getchar();
}

void ShowDVDRentAllCusInfo()
{
	char ISBN[ISBN_LEN];
	dvdInfo* temp;
	dvdRentalInfo* temp2;
	cusInfo* pCus;
	int i, rent_people = 0;

	fputs("찾는 ISBN 입력 : ", stdout);
	gets_s(ISBN, ISBN_LEN);

	temp = GetDVDPtrByISBN(ISBN);
	if (temp == (dvdInfo*)NULL)
	{
		puts("등록되지 않은 ISBN입니다.");
		getchar();
		return;
	}

	rent_people = temp->numOfRentCus;
	temp2 = temp->rentList;

	for (i = 0; i < rent_people; i++)
	{
		printf("대여일 : %d\n", temp2[i].rentDay);
		pCus = GetCusPtrByID(temp2[i].cusID);
		ShowCustomerInfoContinue(pCus);
		puts("");
	}

	puts("조회가 완료되었습니다.");
	getchar();
}