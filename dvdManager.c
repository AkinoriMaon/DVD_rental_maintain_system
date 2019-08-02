// Visual Studio���� �ۼ��� �ڵ��Դϴ�.

#include "common.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"
#include "screenOut.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"

// �ű� DVD ���

void RegistDVD()
{
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int gerne;
	int check = 0; // ���Ե� ISBN���� Ȯ���ϱ� ���� ����

	fputs("ISBN �Է� : ", stdout);
	gets_s(ISBN, ISBN_LEN);

	check = IsRegistISBN(ISBN);
	if (check != 0)
	{
		puts("�ش� ISBN�� ��� �߿� �ֽ��ϴ�.");
		getchar();
		return;
	}

	fputs("���� �Է� : ", stdout);
	gets_s(title, TITLE_LEN);

	fputs("�帣 �Է� (�׼� 1, �ڹ� 2, SF 3, �θ�ƽ 4) : ", stdout);
	scanf_s("%d", &gerne);
	getchar();

	AddDVDInfo(ISBN, title, gerne);

	puts("����� �Ϸ�Ǿ����ϴ�.");
	getchar();
}

// ISBN�� ���� ȸ�� ���� �˻�

void SearchDVDInfo()
{
	char ISBN[ISBN_LEN];
	dvdInfo* temp;

	fputs("ã�� ISBN �Է� : ", stdout);
	gets_s(ISBN, ISBN_LEN);

	temp = GetDVDPtrByISBN(ISBN);

	if (temp != (dvdInfo*)NULL)
	{
		ShowDVDInfo(temp);
	}
	else
	{
		puts("ã�� ISBN�� �����ϴ�.");
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

	fputs("�뿩 DVD ISBN �Է� : ", stdout);
	gets_s(ISBN, ISBN_LEN);

	check1 = IsRegistISBN(ISBN);
	if (check1 == 0)
	{
		puts("��ϵ��� ���� DVD�Դϴ�.");
		getchar();
		return;
	}

	check2 = GetDVDRentState(ISBN);

	if (check2 == RENTED)
	{
		puts("�뿩���Դϴ�.");
		getchar();
		return;
	}

	puts("�뿩�� �����մϴ�.");
	puts("�뿩 ������ �����մϴ�.");

	fputs("�뿩 �� ID �Է� : ", stdout);
	gets_s(ID, ID_LEN);

	temp2 = GetCusPtrByID(ID);
	if (temp2 == (cusInfo*)NULL)
	{
		puts("���Ե��� ���� ID�Դϴ�. �뿩�� ������ �� �����ϴ�.");
		getchar();
		return;
	}

	fputs("��¥ �Է� : ", stdout);
	scanf_s("%u", &date);
	while (getchar() != '\n');

	SetDVDRented(ISBN, ID, date);
	
	puts("�뿩�� �Ϸ�Ǿ����ϴ�.");
	getchar();
}

void ReturnDVD()
{
	char ISBN[ISBN_LEN];
	dvdInfo* ISBN_check;
	int return_check;

	fputs("�ݳ��� DVD ISBN �Է� : ", stdout);
	gets_s(ISBN, ISBN_LEN);

	ISBN_check = IsRegistISBN(ISBN);
	if (ISBN_check == NULL)
	{
		puts("��ϵ��� ���� ISBN�Դϴ�.");
		getchar();
		return;
	}

	return_check = GetDVDRentState(ISBN);
	if (return_check == RETURNED)
	{
		puts("�̹� �ݳ��� DVD�Դϴ�.");
		getchar();
		return;
	}

	SetDVDReturned(ISBN);

	puts("�ݳ��� �Ϸ�Ǿ����ϴ�.");
	getchar();
}

void ShowDVDRentAllCusInfo()
{
	char ISBN[ISBN_LEN];
	dvdInfo* temp;
	dvdRentalInfo* temp2;
	cusInfo* pCus;
	int i, rent_people = 0;

	fputs("ã�� ISBN �Է� : ", stdout);
	gets_s(ISBN, ISBN_LEN);

	temp = GetDVDPtrByISBN(ISBN);
	if (temp == (dvdInfo*)NULL)
	{
		puts("��ϵ��� ���� ISBN�Դϴ�.");
		getchar();
		return;
	}

	rent_people = temp->numOfRentCus;
	temp2 = temp->rentList;

	for (i = 0; i < rent_people; i++)
	{
		printf("�뿩�� : %d\n", temp2[i].rentDay);
		pCus = GetCusPtrByID(temp2[i].cusID);
		ShowCustomerInfoContinue(pCus);
		puts("");
	}

	puts("��ȸ�� �Ϸ�Ǿ����ϴ�.");
	getchar();
}