#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void Reverse( char *left, char *right)
{
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
ReverseSentence(char * arr,int len)
{
	//������������
	char * left = arr;
	char * right = arr+len - 1;
	char*p = arr;
	Reverse(left, right);
	//����ÿ������
	while (*p != '\0')
	{
		char *start = p;//start��ָ��ÿһ�����ʵĿ�ʼ
		while (*p != ' '&&*p != '\0')
		{
			p++;
		}
		Reverse(start, p - 1);//�����ʵ�����ĸ��β��ĸ�������ú���
		if (*p == ' ')
		{
			p++;
		}
	}

}

int main()
{

	char arr[] = "i am a student";
	int len = strlen(arr);
	ReverseSentence(arr,len);
	printf("%s",arr);
	system("pause");
	return 0;
}