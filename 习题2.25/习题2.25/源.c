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

void left_move(char*arr, int k)//左旋字符串
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

void left_move2(char*arr, int k)//更优解法
//要旋转三次分三步abcdef==》defabc
//1.先旋转前面k个==》cbadef
//2.再转后面的剩余部分==》cbafed
//3.整体旋转==》defabc
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
////确定字符串数组是否为其左旋的数组
//int Sure(char arr[], const char arr2[])
//{
//	if (strlen(arr) != strlen(arr2))
//	{
//		return 0;
//	}
//	strncat(arr, arr, strlen(arr));//拼接时要注意要给足数组空间不然会发生错误
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
//		printf("是的呀");
//	}
//	else
//	{
//		printf("不是呀");
//	}
//	system("pause");
//	return 0;
//}