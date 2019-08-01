// Visual Studio���� �ۼ��� �ڵ��Դϴ�.

#include "common.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"
#include "screenOut.h"

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