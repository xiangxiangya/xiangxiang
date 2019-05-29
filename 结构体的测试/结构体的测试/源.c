#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef struct STU
{
	int a;
	struct STU *b;
	int c;
}SELF_REF3;


int main()
{
	return 0;
}


//typedef struct Stu
//{
//	char name[20];
//	int age;
//}stu_t,*stu_p;
//void print(stu_p ps)
//{
//	printf("name = %s   age = %d\n", (*ps).name, (*ps).age);
//	//使用结构体指针访问指向对象的成员
//	printf("name = %s   age = %d\n", ps->name, ps->age);
//}
//int main()
//{
//	stu_t s = { "zhangsan",20 };
//	print(&s);//结构体地址传参
//	system("pause");
//	return 0;
//}











	//typedef struct Stu
	//{
	//	char name[20];
	//	int age;
	//}stu;
	//void print(struct Stu* ps)
	//{
	//	printf("name = %s   age = %d\n", (*ps).name, (*ps).age);
	//	//使用结构体指针访问指向对象的成员
	//	printf("name = %s   age = %d\n", ps->name, ps->age);
	//}
	//int main()
	//{
	//	struct Stu s = { "zhangsan", 20 };
	//	print(&s);//结构体地址传参
	//	system("pause");
	//	return 0;
	//}
