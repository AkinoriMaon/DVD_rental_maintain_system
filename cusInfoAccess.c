// Visual Studio에서 작성된 코드입니다.

#include "common.h"
#include "cusInfo.h"

#define MAX_CUSTOMER 100

static cusInfo* cusList[MAX_CUSTOMER];
static int numOfCustomer = 0;

// cusInfo 할당 및 저장, 성공 시 '등록된 정보의 개수', 실패 시 0을 반환

int AddCusInfo(char* ID, char* name, char* num)
{
	cusInfo* pcus=NULL;
	int check = 0;

	if (numOfCustomer >= MAX_CUSTOMER)
	{
		puts("가입자 최대 수를 초과했습니다. 가입할 수 없습니다.");
		return 0;
	}

	pcus = (cusInfo*)malloc(sizeof(cusInfo));
	
	strcpy_s(pcus->ID, ID_LEN, ID);
	strcpy_s(pcus->name, NAME_LEN, name);
	strcpy_s(pcus->phoneNum, PHONE_LEN, num);

	cusList[numOfCustomer] = pcus;

	numOfCustomer++;	

	return numOfCustomer;
}

// 해당 ID의 정보를 담고 있는 변수의 포인터 반환, 등록 안된 ID의 경우 NULL 포인터 반환

cusInfo* GetCusPtrByID(char* ID)
{
	int i = 0;

	for (i = 0; i < numOfCustomer; i++)
	{
		if (strcmp(cusList[i]->ID, ID) == 0)
		{
			return cusList[i];
		}
	}
	
	return (cusInfo*)NULL;
}

// 가입된 ID인지 확인, 가입되었으면 1, 아니면 0 반환

int IsRegistID(char* ID)
{
	int i ;

	for (i = 0; i < numOfCustomer; i++)
	{
		if (strcmp(cusList[i]->ID, ID) == 0)
		{
			return 1;
		}
	}

	return 0;
}