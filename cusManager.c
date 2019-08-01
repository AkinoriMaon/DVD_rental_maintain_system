// Visual Studio���� �ۼ��� �ڵ��Դϴ�.

#include "common.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
#include "screenOut.h"

// �ű� ȸ�� ����

void RegistCustomer()
{
	char ID[ID_LEN];
	char name[NAME_LEN];
	char num[PHONE_LEN];
	int check = 0; // ���Ե� ID���� Ȯ���ϱ� ���� ����

	fputs("ID �Է� : ", stdout);
	gets_s(ID, ID_LEN);

	check = IsRegistID(ID);
	if (check != 0)
	{
		puts("�ش� ID�� ��� �߿� �ֽ��ϴ�.");
		puts("�ٸ� ID�� �������ּ���.");
		getchar();
		return;
	}

	fputs("�̸� �Է� : ", stdout);
	gets_s(name, NAME_LEN);

	fputs("��ȭ��ȣ �Է� : ", stdout);
	gets_s(num, PHONE_LEN);

	AddCusInfo(ID, name, num);

	puts("������ �Ϸ�Ǿ����ϴ�.");
	getchar();
}

// ID�� ���� ȸ�� ���� �˻�

void SearchCusInfo()
{
	char ID[ID_LEN];
	cusInfo* temp;

	fputs("ã�� ID �Է� : ", stdout);
	gets_s(ID, ID_LEN);

	temp = GetCusPtrByID(ID);
	
	if (temp != (cusInfo*)NULL)
	{
		strcpy_s(ID, sizeof(ID), temp->ID);
		ShowCustomerInfo(temp);
	}
	else
	{
		puts("ã�� ID�� �����ϴ�.");
		getchar();
	}
}