#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//#include<stdlib.h>
//Fun(int *arr,int  len)
//{
//	int *left = arr;
//	int *right = (arr + len - 1);
//	int tmp = 0;
//	while (left < right)
//	{
//		while (left < right && (*left % 2) == 1)
//		{
//			left++;
//		}
//		while (left < right && (*right% 2) == 0)
//		{
//			right--;
//		}
//		tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//
//Show(int *arr,int len)
//{
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		printf("%d", *(arr + i));
//	}
//}
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6 };
//	int len = sizeof(arr) / sizeof((arr[0]));
//	Fun(arr, len);
//	Show(arr,len);
//	system("pause");
//	return 0;
//}

void left_move(char*arr, int k)//�����ַ���
{
	char tmp = 0;
	char*p = arr;
	while (k!=0)
	{
		tmp =*p;
		while (*(p+1) != '\0')
		{
			*p = *(p + 1);
			p++;
		}
		*p = tmp;
		k--;
	}
}

void left_move2(char*arr, int k)//���Žⷨ
//Ҫ��ת���η�����abcdef==��defabc
//1.����תǰ��k��==��cbadef
//2.��ת�����ʣ�ಿ��==��cbafed
//3.������ת==��defabc
{
	int len = strlen(arr);
	void Reverse(left, right);
	Reverse(arr, arr + k - 1);
	Reverse(arr + k, arr + len - 1);
	Reverse(arr, arr + len - 1);
}

void Reverse(char*left, char*right)
{
	char tmp = 0;
	while (left < right)
	{
		tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}


int main()
{
	int k = 2;
	char arr[] = "abcd";
	int len = strlen(arr);
	/*left_move(arr, 2);*/
	int left = arr;
	int right = arr + len - 1;
	left_move2(arr, k);
	printf("%s", arr);

	system("pause");
	return 0;
}
//}
//
//
////ȷ���ַ��������Ƿ�Ϊ������������
//int Sure(char arr[], const char arr2[])
//{
//	if (strlen(arr) != strlen(arr2))
//	{
//		return 0;
//	}
//	strncat(arr, arr, strlen(arr));//ƴ��ʱҪע��Ҫ��������ռ䲻Ȼ�ᷢ������
//	if (strstr(arr, arr2) == NULL)
//	{
//		return 0;
//	}
//	else
//	{
//		return 1;
//	}
//}
//int main()
//{
//	char arr[20] = "abcdef";
//	char arr2[] = "cdefab";
//	int ret = Sure(arr, arr2);
//	if (ret == 1)
//	{
//		printf("�ǵ�ѽ");
//	}
//	else
//	{
//		printf("����ѽ");
//	}
//	system("pause");
//	return 0;
//}