#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>



char*Mystrstr(const char*str1,const char *str2)
{
	while (*str1 != '\0')
	{
		while (*str1 != '0'&&*str2 != '0'&&*str1 == *str2)
		{
			str1++;
			str2++;
		}
	}
}

int main()
{
	char dest[20] = "abbcedf";
	char src[] = "bbc";
	Mystrstr(dest, src);
	printf("%s", dest);
	system("pause");
	return 0;
}





//char *Mystrcat(char*dest, const char* src)
//{
//	//char*p = dest;
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	while (*dest++ = *src++){}
//	//return p;
//}
//int main()
//{
//	char dest[20] = "abcdef";
//		char src[] = "hello";
//		Mystrcat(dest,src);
//		printf("%s", dest);
//	system("pause");
//	return 0;
//}




//char * Mystrcpy(char * dest,const char *src)//�����ͷ���ֵ������ԭ�������Ӧ
//{
//	//char*p = dest;
//	//while (*src != '\0')
//	//{
//	//	*dest = *src;
//	//	dest++;
//	//	src++;
//	//}
//	//*dest = '\0';
//	//return p;
//
//	//�Ż�����
//	char *p = dest;
//	while (*dest++ = *src++)
//	{
//
//	}
//	return p;
//
//}
//int main()
//{
//	char dest[20] = "abcdef";
//	char src[] = "hello";
//	Mystrcpy(dest,src);
//	printf("%s", dest);
//	system("pause");
//	return 0;
//}





//int main()
//{
//
//
//
//
//	//int x = 0;
//	//int y = 0;
//	//int arr[] = { 2, 4, 3, 6, 3, 2, 5, 5 };
//	//int len = sizeof(arr) / sizeof(arr[0]);
//	//int i = 0;
//	//int num = 0;
//	//int pos = 0;
//	//for (i = 0; i < len; i++)
//	//{
//	//	num = num^arr[i];
//	//}
//	////�ҵ�num�����ƴ��������һ��Ϊ1��λ��
//	////pos�Ǳ����iλΪ1��λ��
//	////ʱ�临�Ӷȣ�
//	//for (i = 0; i < 32; i++)
//	//{
//	//	if (((num>>i)&1)==1)
//	//	{
//	//		pos = i;
//	//		break;
//	//	}
//	//}
//	//for (i = 0; i < len; i++)//�������飬��Ϊ����������
//	//{
//	//	if (((arr[i] >> pos) & 1) == 1)
//	//	{
//	//		x = x^arr[i];
//	//	}
//	//	else
//	//	{
//	//		y = y^arr[i];
//	//	}
//	//}
//	//printf("%d ", x);
//	//printf("%d", y);
//
//
//
//
//	system("pause");
//	return 0;
//}