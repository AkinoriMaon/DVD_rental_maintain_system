// Visual Studio���� �ۼ��� �ڵ��Դϴ�.

#include "common.h"
#include "dvdInfo.h"

#define MAX_DVD 100

static dvdInfo * dvdList[MAX_DVD];
static int numOfDVD = 0;

// dvdInfo �Ҵ� �� ����, ���� �� '��ϵ� ������ ����', ���� �� 0�� ��ȯ

int AddDVDInfo(char* ISBN, char* title, int gerne)
{
	dvdInfo* pDVD = NULL;
	int check = 0;

	if (numOfDVD >= MAX_DVD)
	{
		puts("�ִ� ��� ���� DVD ���� �ʰ��Ͽ����ϴ�. DVD�� ����� �� �����ϴ�.");
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

// �ش� ISBN�� ������ ��� �ִ� ������ ������ ��ȯ, ��� �ȵ� ISBN�� ��� NULL ������ ��ȯ

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

// ��ϵ� ISBN���� Ȯ��, ��ϵǾ����� 1, �ƴϸ� 0 ��ȯ

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