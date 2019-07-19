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
#define LIST_DEFAULT 1  //ͨѶ¼�Ŀռ�
#define INC_SIZE 2

typedef struct person
{
	char name[NAME_SIZE];
	char sex;
	unsigned char age;
	char tlephone[TLE_SIZE];
	char address[ADDR_SIZE];
}person_t,*person_p,**person_pp;

//ͨѶ¼�ṹ��
typedef struct contact
{
	int cap;//������
	int size;//��ǰ�Ĵ�С
	person_t list[0];//������������
}contact_t, *contact_p,**contact_pp;


void InitContact(contact_pp _ctpp);//��ʼ��ͨѶ¼

void ShowContact(contact_p ct);//��ʾ
//void DestroyContact(contact_p ct);//��ʽ��
//void ClearContact();//���
//
//void Sort(contact_p ct);//������������

void AddPerson(contact_pp ct);//�����ϵ��

//void DelContact();//ɾ����ϵ��,�����һ��Ԫ�ظ��ǵ�ǰԪ�غ�--
//void SearchContact();//������ϵ��
//void ModContact();//�޸�



#endif