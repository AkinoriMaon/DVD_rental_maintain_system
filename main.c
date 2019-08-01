// Visual Studio에서 작성된 코드입니다.

#include "common.h"
#include "cusManager.h"
#include "screenOut.h"

enum {CUS_REG = 1, CUS_SERACH, QUIT};

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
		}

		if (inputMenu == QUIT)
		{
			puts("이용해 주셔서 감사합니다.");
			break;
		}
	}

	return 1;
}