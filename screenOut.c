// Visual Studio���� �ۼ��� �ڵ��Դϴ�.

#include "common.h"
#include "cusInfo.h"

void ShowMenu()
{
	system("cls"); // <stdlib.h>

	puts("------- �޴� -------");
	puts("1. �ű԰���");
	puts("2. ���˻�");
	puts("3. ����");
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