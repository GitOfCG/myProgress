#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//strtok  method 1
char * Strtok1(char * str1, const char * str2)
{
	static char * g_pos = NULL;  //��̬����������һ���˳���λ��
	if (NULL == str2)
	{
		printf("args err:check NULL == str2\n");
		return NULL;
	}

	char * pos = NULL;
	char * tmp = NULL;
	char * tmpCur = NULL;
	int lenStr2 = strlen(str2);
	int i = 0;
	int flag = 0; //0�ָ���������,  1 ����

	if (NULL != str1)
	{
		tmp = str1;
		pos = str1;
	}
	else
	{
		if (NULL == g_pos)
			return NULL;
		tmp = g_pos;
		pos = g_pos;
	}

	while (1)
	{
		if (0 == flag)
		{
			tmpCur = tmp;
		}

		for (i = 0; i < lenStr2; i++)
		{
			if (*pos == str2[i])
			{
				*pos = '\0';		
				//if (strlen(tmp))
				if (pos - tmp)
				{
					//flag = 0;
					g_pos = pos;  //ȫ�ֱ���������һ���˳���λ��
					g_pos++;
					return tmp;
				}

				flag = 1;
				tmp++;
				break;
			}
		}
		
		pos++;

		if (*pos == '\0')
		{
			g_pos = NULL;
			if (tmp - tmpCur)
			{
				return NULL;
			}
			return tmp;
		}
	}

	return NULL;
}

//method 2 -- strFind
char * strFind(char *str1, const char *str2)
{
	char *p1 = str1;
	int i;
	while (*p1)
	{
		for (i = 0; str2[i] != '\0'; i++)
		{
			if (*p1 == str2[i])
				return p1;
		}
		p1++;
	}

	return p1;
}

//method 2 -- strNFind
char * strNFind(char *str1, const char *str2)
{
	char *p1 = str1;
	int i;
	while (*p1)
	{
		for (i = 0; str2[i] != '\0'; i++)
		{
			if (*p1 == str2[i])
				break;
		}
		if (str2[i] == '\0')
			return p1;
		p1++;
	}

	return NULL;
}
// method 2 -- ���ú����� 
char * Strtok2(char * str1, const char * str2)
{
	static char * g_pos = NULL;
	if (NULL == str2)
	{
		printf("args err:check NULL == str2\n");
		return NULL;
	}
	if (NULL == str1)
		str1 = g_pos;
	if (str1 != NULL)
		g_pos = str1;

	char *pCur = strNFind(str1, str2);
	if (pCur == NULL)
		return NULL;

	char *pNext = strFind(pCur, str2);
	*pNext = '\0';

	g_pos = pNext + 1;

	return pCur;
}

//method 3 --  g_pos �����ָ���
char * Strtok3(char * str1, const char * str2)
{
	static char * g_pos = NULL;
	if (NULL == str2)
	{
		printf("args err:check NULL == str2\n");
		return NULL;
	}
	if (NULL == str1)
	{
		str1 = g_pos;
	}
	if (str1 != NULL)
	{
		g_pos = str1;
	}
	
	char *str1P = str1;
	int i;
	char *tmp = NULL;

	while (*str1P != '\0')
	{
		for (i = 0; str2[i] != '\0'; i++)
		{
			if (*str1P == str2[i])
			{
				if (str1P == g_pos)
				{
					g_pos++;
				}
				else
				{
					*str1P = '\0';
					str1P--;  // ָ�����, �պ�++ʱ, ����ѭ��
				}
				break;
			}
		}
		str1P++;
	}
	
	if (*g_pos == '\0')
		return NULL;

	tmp = g_pos;
	g_pos = str1P + 1;
	
	return tmp;
}


//strtok
// ��һ�ַ���, ���Ǻ�����, ���⺯��strtok�Ƚ�, ��һ��str1 = NULL���򲻻����
void test_strtok1()  
{
	char str1[] = "---------,,,x  ifd  a    ?? ---------oc....g---";
	char str2[] = ", .-";
	char *p = Strtok1(str1, str2);
	while (p != NULL)
	{
	printf("strstr: *%s*\n", p);
	p = Strtok1(NULL, str2);
	}
	
	// char *p = strtok(str1, str2);
	// printf("test_strtok1 p: *%s*\n", p);
	// printf("test_strtok1 str1: *%s*\n", str1);

	return;
}

// �ڶ��ַ���, ������, ������⺯��strtok��ͬ
void test_strtok2()
{
	char str1[] = "---------,,,x  ifd  a    ?? ---------oc....g---";
	char str2[] = ", .-";
	char *p = Strtok2(str1, str2);
	while (p != NULL)
	{
		printf("strstr: *%s*\n", p);
		p = Strtok2(NULL, str2);
	}
	//char *p = Strtok2(str1, str2);
	//printf("test_strtok2 p: *%s*\n", p);
	//printf("test_strtok2 str1: *%s*\n", str1);

	return;
}

// �����ַ���, ������, ������⺯��strtok��ͬ
void test_strtok3()
{
	char str1[] = "---------,,,x  ifd  a    ?? ---------oc....g---";
	char str2[] = ", .-";
	char *p = Strtok3(str1, str2);
	while (p != NULL)
	{
		printf("strstr: *%s*\n", p);
		p = Strtok3(NULL, str2);
	}
	/*char *p = Strtok3(str1, str2);
	printf("test_strtok3 p: *%s*\n", p);
	printf("test_strtok3 str1: *%s*\n", str1);*/

	return;
}

int main(void)
{
	
	test_strtok1();
	printf("==========================\n");
	test_strtok2();
	printf("==========================\n");
	test_strtok3();


	printf("\n");
	system("pause");
	return 0;
}
