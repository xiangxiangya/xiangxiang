#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	int a[2][2][3] = { 0 };
	int i = 0;
	int j = 0;
	int arr[10] = { 0 };
	for (i = 0; i < 12; i++)
	{
		((int*)a)[5] = i + 1;//����ָ��
	}
	system("pause");
	return 0;

}








//int main()
//{
//	float num = 43;
//	float n = 10;
//	if ((int)num%(int)n == 0)
//	{
//		printf("yes\n");
//	}
//	system("pause");
//	return 0;
//}
//

//��ķ˹������
//int main()
//{
//	int i = 0;
//	int modflag = 1;
//	int num = 0;//λ��
//	int sum = 0;
//	int j = 0;
//	for (i = 0; i < 1000000000; i++)
//	{
//		if (i%modflag == 0)//�ж�������Ǽ�λ  ֻ��1��10��100...�����жϣ�modflag���ֲ���
//		{
//			num++;
//			modflag *= 10;
//		}
//		for (j = i; j; j /= 10)
//		{
//			sum += pow(j % 10, num);
//		}
//		if (sum == i)
//		{
//			printf("%d\n", i);
//		}
//		sum = 0;
//	}
//	system("pause");
//	return 0;
//}









//����
//int main()
//{
//	int i = 0;
//	int n = 0;
//	for (n = 100; n <= 200; n++)
//	{
//		for (i = 2; i <= sqrt(n); i++)
//		{
//			if (n%i == 0)
//			{
//				break;//��������
//			}
//		}
//		if (i>sqrt(n))
//			printf("%d\n", n);
//	}
//	system("pause");
//	return 0;
//}
