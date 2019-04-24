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
	//逆置整个句子
	char * left = arr;
	char * right = arr+len - 1;
	char*p = arr;
	Reverse(left, right);
	//逆置每个单词
	while (*p != '\0')
	{
		char *start = p;//start会指向每一个单词的开始
		while (*p != ' '&&*p != '\0')
		{
			p++;
		}
		Reverse(start, p - 1);//将单词的首字母和尾字母传入逆置函数
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