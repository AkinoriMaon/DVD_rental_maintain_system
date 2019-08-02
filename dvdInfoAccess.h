// Visual Studio에서 작성된 코드입니다.

#ifndef __DVDACCESS_H__

#define __DVDACCESS_H__

#include "dvdInfo.h"

int AddDVDInfo(char* ISBN, char* title, int gerne);
dvdInfo* GetDVDPtrByISBN(char* ISBN);
int IsRegistISBN(char* ISBN);

int GetDVDRentState(char* ISBN);
void SetDVDRented(char* ISBN, char* ID, unsigned int date);
void SetDVDReturned(char* ISBN);

#endif