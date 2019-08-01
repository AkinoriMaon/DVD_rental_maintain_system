// Visual Studio에서 작성된 코드입니다.

#include "common.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
#include "screenOut.h"

// 신규 회원 가입

void RegistCustomer()
{
	char ID[ID_LEN];
	char name[NAME_LEN];
	char num[PHONE_LEN];
	int check = 0; // 가입된 ID인지 확인하기 위한 변수

	fputs("ID 입력 : ", stdout);
	gets_s(ID, ID_LEN);

	check = IsRegistID(ID);
	if (check != 0)
	{
		puts("해당 ID는 사용 중에 있습니다.");
		puts("다른 ID를 선택해주세요.");
		getchar();
		return;
	}

	fputs("이름 입력 : ", stdout);
	gets_s(name, NAME_LEN);

	fputs("전화번호 입력 : ", stdout);
	gets_s(num, PHONE_LEN);

	AddCusInfo(ID, name, num);

	puts("가입이 완료되었습니다.");
	getchar();
}

// ID를 통한 회원 정보 검색

void SearchCusInfo()
{
	char ID[ID_LEN];
	cusInfo* temp;

	fputs("찾는 ID 입력 : ", stdout);
	gets_s(ID, ID_LEN);

	temp = GetCusPtrByID(ID);
	
	if (temp != (cusInfo*)NULL)
	{
		strcpy_s(ID, sizeof(ID), temp->ID);
		ShowCustomerInfo(temp);
	}
	else
	{
		puts("찾는 ID가 없습니다.");
		getchar();
	}
}