#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//strstr
const char * Strstr(const char * str1, const char * str2)
{
	if (NULL == str1 || NULL == str2)
	{
		printf("args err:check NULL == str1 || NULL == str2\n");
		return NULL;
	}
	const char *p1 = str1;
	const char *p2 = str2;
	const char *tmp = NULL;
	int lenStr2 = 0;

	while (*p1 != '\0')
	{
		tmp = p1;	
		while (*p2 != '\0')
		{
			if (*p1 == *p2)
			{
				lenStr2++;
				p1++;
				p2++;
			}
			else
			{
				tmp++;
				p1 = tmp;
				p2 = str2;
				lenStr2 = 0;
				break;
			}
		}
		if (strlen(str2) == lenStr2)
			break;
	}

	if (strlen(str2) != lenStr2)
	{
		return NULL;
	}
	else
	{
		return tmp;
	}
}


void test_strstr()
{
	char *str1 = "hlello xiaocg";
	char str2[] = "llo";
	//Strstr(str1, str2);

	printf("strstr: *%s*\n", Strstr(str1, str2));
	return;
}


int main(void)
{
	
	test_strstr();

	printf("\n");
	system("pause");
	return 0;
}
