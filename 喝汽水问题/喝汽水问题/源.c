#define _CRT_SECURE_NO_WARNINGS 1

/*.����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ��
��20Ԫ�����Զ�����ˮ��
���ʵ�֡�*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int total = 20;  //��ˮ����
	int kps = 0;     //��ƿ��
	int sy = 0;     //ʣ���ƿ
	kps = 20;
	while (kps >= 1)
	{
		kps = kps + sy;
		total = total + kps / 2;
		sy = kps % 2;
		kps = kps / 2;
	}
	printf("total = %d\n", total);
	system("pause");
	return 0;
}
