#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
typedef struct
{
	int year;
	int month;
	int day;
	int hour;
	int min;
	int sed;
	int wek;
}tm;
//Pirnt(tm * now_time)
//{
//	printf("%d %d %d %d:%d:%d %d\n", now_time->year, now_time->month, now_time->day, now_time->hour, now_time->min, now_time->sed, now_time->wek);
//}
int main()
{
	//time_t t = time(NULL)+8*3600;
	//tm now_time = { 0 };
	while (1)
	{
		time_t t = time(NULL) + 8 * 3600;
		tm now_time = { 0 };
		now_time.sed = t % 60;
		t = t / 60;
		now_time.min = t % 60;
		t /= 60;
		now_time.hour = t % 24;
		t /= 60;
		printf(" %02d:%02d:%02d\n", now_time.hour, now_time.min, now_time.sed);
		Sleep(1000);
		system("cls");
	}
	//now_time.sed = t % 60;
	//t=t/ 60;
	//now_time.min = t % 60;
	//t /= 60;
	//now_time.hour = t % 24;
	//t /= 60;
	//printf(" %d:%d:%d\n",now_time.hour,now_time.min,now_time.sed );
	//Pirnt(&now_time);
	system("pause");
	return 0;
}