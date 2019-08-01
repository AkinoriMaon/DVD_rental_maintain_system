// Visual Studio에서 작성된 코드입니다.

#include "common.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"
#include "screenOut.h"

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