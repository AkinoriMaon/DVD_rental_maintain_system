// Visual Studio���� �ۼ��� �ڵ��Դϴ�.

#include "common.h"
#include "cusInfo.h"

#define MAX_CUSTOMER 100

static cusInfo* cusList[MAX_CUSTOMER];
static int numOfCustomer = 0;

// cusInfo �Ҵ� �� ����, ���� �� '��ϵ� ������ ����', ���� �� 0�� ��ȯ

int AddCusInfo(char* ID, char* name, char* num)
{
	cusInfo* pcus=NULL;
	int check = 0;

	if (numOfCustomer >= MAX_CUSTOMER)
	{
		puts("������ �ִ� ���� �ʰ��߽��ϴ�. ������ �� �����ϴ�.");
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

// �ش� ID�� ������ ��� �ִ� ������ ������ ��ȯ, ��� �ȵ� ID�� ��� NULL ������ ��ȯ

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

// ���Ե� ID���� Ȯ��, ���ԵǾ����� 1, �ƴϸ� 0 ��ȯ

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