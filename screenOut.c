// Visual Studio���� �ۼ��� �ڵ��Դϴ�.

#include "common.h"
#include "cusInfo.h"
#include "dvdInfo.h"

void ShowMenu()
{
	system("cls"); // <stdlib.h>

	puts("------- �޴� -------");
	puts("1. �ű԰���");
	puts("2. ���˻�");
	puts("--------------------");
	puts("3. DVD ���");
	puts("4. DVD �˻�");
	puts("--------------------");
	puts("5. ����");
	puts("--------------------");

	fputs("���� >> ", stdout);
}

void ShowCustomerInfo(cusInfo* pCus)
{
	puts("����������������������������������������������������������");
	printf("�� �� ID : %s\n", pCus->ID);
	printf("�� �� �̸� : %s\n", pCus->name);
	printf("�� �� ��ȭ��ȣ : %s\n", pCus->phoneNum);
	puts("����������������������������������������������������������");

	getchar();
}

void ShowDVDInfo(dvdInfo* pDVD)
{
	puts("����������������������������������������������������������");
	printf("�� �� ISBN : %s\n", pDVD->ISBN);
	printf("�� �� ���� : %s\n", pDVD->title);
	printf("�� �� �帣 : %d\n", pDVD->gerne);
	puts("����������������������������������������������������������");

	getchar();
}