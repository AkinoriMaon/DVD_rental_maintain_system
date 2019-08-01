// Visual Studio에서 작성된 코드입니다.

#ifndef __CUSINFO_H__

#define __CUSINFO_H__

#define ID_LEN 10
#define NAME_LEN 30
#define PHONE_LEN 30

typedef struct __cusInfo
{
	char ID[ID_LEN]; // 고객 정보를 구분 짓는 고객 ID
	char name[NAME_LEN];
	char phoneNum[PHONE_LEN];
}cusInfo;

#endif