// Visual Studio에서 작성된 코드입니다.

#ifndef __SCREENOUT_H__

#define __SCREENOUT_H__

#include "cusInfo.h"
#include "dvdInfo.h"

void ShowMenu();
void ShowCustomerInfo(cusInfo* pCus);
void ShowDVDInfo(dvdInfo* pDVD);
void ShowCustomerInfoContinue(cusInfo* pCus);

#endif