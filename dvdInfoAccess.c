// Visual Studio에서 작성된 코드입니다.

#include "common.h"
#include "dvdInfo.h"

#define MAX_DVD 100

static dvdInfo * dvdList[MAX_DVD];
static int numOfDVD = 0;

// dvdInfo 할당 및 저장, 성공 시 '등록된 정보의 개수', 실패 시 0을 반환

int AddDVDInfo(char* ISBN, char* title, int gerne)
{
	dvdInfo* pDVD = NULL;
	int check = 0;

	if (numOfDVD >= MAX_DVD)
	{
		puts("최대 등록 가능 DVD 수를 초과하였습니다. DVD를 등록할 수 없습니다.");
		return 0;
	}

	pDVD = (dvdInfo*)malloc(sizeof(dvdInfo));

	strcpy_s(pDVD->ISBN, ISBN_LEN, ISBN);
	strcpy_s(pDVD->title, TITLE_LEN, title);
	pDVD->gerne = gerne;
	pDVD->numOfRentCus = 0;
	pDVD->rentState = RETURNED;

	dvdList[numOfDVD] = pDVD;

	numOfDVD++;

	return numOfDVD;
}

// 해당 ISBN의 정보를 담고 있는 변수의 포인터 반환, 등록 안된 ISBN의 경우 NULL 포인터 반환

dvdInfo* GetDVDPtrByISBN(char* ISBN)
{
	int i = 0;

	for (i = 0; i < numOfDVD; i++)
	{
		if (strcmp(dvdList[i]->ISBN, ISBN) == 0)
		{
			return dvdList[i];
		}
	}

	return (dvdInfo*)NULL;
}

// 등록된 ISBN인지 확인, 등록되었으면 1, 아니면 0 반환

int IsRegistISBN(char* ISBN)
{
	int i;

	for (i = 0; i < numOfDVD; i++)
	{
		if (strcmp(dvdList[i]->ISBN, ISBN) == 0)
		{
			return 1;
		}
	}

	return 0;
}

int GetDVDRentState(char* ISBN)
{
	dvdInfo* temp;

	temp = GetDVDPtrByISBN(ISBN);

	return temp->rentState;
}

void SetDVDRented(char* ISBN, char* ID, unsigned int date)
{
	dvdInfo* temp;

	temp = GetDVDPtrByISBN(ISBN);

	strcpy_s(temp->rentList[temp->numOfRentCus].cusID, sizeof(temp->rentList[temp->numOfRentCus].cusID), ID);
	temp->rentList[temp->numOfRentCus].rentDay = date;

	temp->rentState = RENTED;
	temp->numOfRentCus++;
}

void SetDVDReturned(char* ISBN)
{
	dvdInfo* temp;

	temp = GetDVDPtrByISBN(ISBN);

	temp->rentState = RETURNED;
}