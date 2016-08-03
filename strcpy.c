#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//strcpy method 1  “ª∞„ÀºœÎ
char * Strcpy1(char * des, const char * src)
{
	if (NULL == des || NULL == src)
	{
		printf("args err: check NULL == des || NULL == src\n");
		return NULL;
	}

	const char *pSrc = src;
	char *pDes = des;
	while (*pSrc != '\0')
	{
		*pDes = *pSrc;
		pDes++;
		pSrc++;
	}
	des[pDes - des] = '\0';

	return des;
}

//strcpy method 2  ºÚΩ‡
char * Strcpy1(char * des, const char * src)
{
	if (NULL == des || NULL == src)
	{
		printf("args err: check NULL == des || NULL == src\n");
		return NULL;
	}

	const char *pSrc = src;
	char *pDes = des;
	while ((*pSrc++ = *pDes++) != '\0')
	{
	}

	return des;
}

void test_strcpy()
{
	char *src = "hello xiaocg";
	char des[100] = { 0 };
	Strcpy1(des, src);

	printf("des: *%s*\n", des);
	printf("Strcpy: *%s*\n", Strcpy1(des, src));

	return;
}


int main(void)
{
	
	test_strcpy();

	printf("\n");
	system("pause");
	return 0;
}
