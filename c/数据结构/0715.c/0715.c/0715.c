#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int __main()
{
	int m = 1;
	int n = 7;
	int sum = 0;
	int tmp = 0;
	for (int i = 0; i < n; i++)
	{
		tmp = tmp * 10 + m;
		sum += tmp;
	}
	printf("%d\n", sum);
	system("pause");
	return 0;

}


#include<stdint.h>
int ___main()//����
{
	int n;
	int sum = 0;
	int m;
	int i;
	scanf("%d%d", &n, &m);
	for (i = n; i; i /= m)
	{
		sum = sum * m + i % m;
	}
	printf("%d��%d��������%d\n", n, m, sum);

	if (sum == n)
	{
		printf("%d��%d�������ǻ�����\n", n, m);
	}
	else
		printf("%d��%d�����²��ǻ�����\n", n, m);
	system("pause");
	return 0;
}


int main()
{
	int line, pos, count = 0;//Ŀ�������ǰһ�е�Ԫ�ظ���
	int n = 1;
	scanf("%d", &n);
	for (line = 1; count + line < n; line++)//count+line����Ŀ������������һ���ж��ٸ�Ԫ��
	{
		count += line;
	}
	pos = n - count;//��һ�еĵڼ���
	if (line % 2 == 0)
	{
		printf("��%d������%d/%d,�ڵ�%d�У���%d����\n", n, pos, (line + 1 - pos), line, pos);
	}
	else
		printf("��%d������%d/%d,�ڵ�%d�У���%d����\n", n, (line + 1 - pos), pos, line, pos);

	system("pause");
	return 0;
}