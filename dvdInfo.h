// Visual Studio에서 작성된 코드입니다.

#ifndef __DVDINFO_H__

#define __DVDINFO_H__

#include "cusInfo.h"

#define ISBN_LEN 30
#define TITLE_LEN 30
#define RENT_LEN 100

enum {ACTION = 1, COMIC, SF, ROMANTIC}; // 장르 정보
enum {RENTED, RETURNED};

typedef struct __dvdRentaInfo
{
	char cusID[ID_LEN]; // 대여 고객 ID
	unsigned int rentDay; // 대여일
}dvdRentalInfo;

typedef struct __dvdInfo
{
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int gerne; // 장르

	int rentState; // 대여 상태 정보
	int numOfRentCus; // 등록된 대여 정보의 개수
	dvdRentalInfo rentList[RENT_LEN]; // 대여 정보가 저장되는 배열
}dvdInfo;

#endif