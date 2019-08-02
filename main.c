// Visual Studio���� �ۼ��� �ڵ��Դϴ�.

#include "common.h"
#include "cusManager.h"
#include "dvdManager.h"
#include "screenOut.h"

enum {CUS_REG = 1, CUS_SERACH, DVD_REG, DVD_SERACH, DVD_RENT, DVD_RETURN, DVD_CUS_SERACH, QUIT};

int main()
{
	int inputMenu = 0;

	while (1)
	{
		ShowMenu();
		scanf_s("%d", &inputMenu);
		getchar();

		switch (inputMenu)
		{
			case CUS_REG:
				RegistCustomer();
				break;
			case CUS_SERACH:
				SearchCusInfo();
				break;
			case DVD_REG:
				RegistDVD();
				break;
			case DVD_SERACH:
				SearchDVDInfo();
				break;
			case DVD_RENT:
				RentalDVD();
				break;
			case DVD_RETURN:
				ReturnDVD();
				break;
			case DVD_CUS_SERACH:
				ShowDVDRentAllCusInfo();
				break;
		}

		if (inputMenu == QUIT)
		{
			puts("�̿��� �ּż� �����մϴ�.");
			break;
		}
	}

	return 1;
}