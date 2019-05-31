 #define _CRT_SECURE_NO_WARNINGS 1
#ifndef _contact_h_
#define _contact_h_
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>


#define NAME_SIZE 64
#define TLE_SIZE 16
#define ADDR_SIZE 128  
#define LIST_DEFAULT 1
#define INC_SIZE 2

typedef struct person
{
	char name[NAME_SIZE];
	char sex;
	unsigned char age;
	char tlephone[TLE_SIZE];
	char address[ADDR_SIZE];
}person_t,*person_p,**person_pp;

//通讯录结构体
typedef struct contact
{
	int cap;//总容量
	int size;//当前的大小
	person_t list[0];

}contact_t, *contact_p,**contact_pp;


void InitContact(contact_pp _ctpp);//初始化通讯录

void ShowContact(contact_p ct);//显示
//void DestroyContact(contact_p ct);//格式化
//void ClearContact();//清空
//
//void Sort(contact_p ct);//根据姓名排序

void AddPerson(contact_pp ct);//添加联系人

//void DelContact();//删除联系人,用最后一个元素覆盖当前元素后--
//void SearchContact();//查找联系人
//void ModContact();//修改



#endif