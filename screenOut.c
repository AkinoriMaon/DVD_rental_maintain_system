// Visual Studio���� �ۼ��� �ڵ��Դϴ�.

#include "common.h"
#include "cusInfo.h"
#include "dvdInfo.h"

void ShowMenu()
{
	system("cls"); // <stdlib.h>

	puts("---------- �޴� ----------");
	puts("1. �ű԰���");
	puts("2. ���˻�");
	puts("--------------------------");
	puts("3. DVD ���");
	puts("4. DVD �˻�");
	puts("--------------------------");
	puts("5. DVD �뿩");
	puts("6. DVD �ݳ�");
	puts("--------------------------");
	puts("7. DVD �뿩 �� ��ü ��ȸ");
	puts("8. ����");
	puts("--------------------------");

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
	switch (pDVD->gerne)
	{
		case ACTION:
			puts("�� �� �帣 : �׼�");
			break;
		case COMIC:
			puts("�� �� �帣 : �ڹ�");
			break;
		case SF:
			puts("�� �� �帣 : SF");
			break;
		case ROMANTIC:
			puts("�� �� �帣 : �θ�ƽ");
			break;
	}
	puts("����������������������������������������������������������");

	getchar();
}

void ShowCustomerInfoContinue(cusInfo* pCus)
{
	puts("����������������������������������������������������������");
	printf("�� �� ID : %s\n", pCus->ID);
	printf("�� �� �̸� : %s\n", pCus->name);
	printf("�� �� ��ȭ��ȣ : %s\n", pCus->phoneNum);
	puts("����������������������������������������������������������");
}