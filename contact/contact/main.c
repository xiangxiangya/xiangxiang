#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"


void Menu()
{
	printf("########################\n");
	printf("## 1.Show       2.Add  ##\n");
	printf("## 3.Del        4.Mod  ##\n");
	printf("## 5.Search     6.Sort ##\n");
	printf("## 7.Clear      8.Save ##\n");
	printf("##       9.Exit        ##\n");
	printf("########################\n");
	printf("Please select -> \n");
}




int main()
{
	contact_p ct;
	
	volatile int quit = 0;//保持内存的可见性,防止内存和寄存器中的数据不一样
	int select = 0;
	InitContact(&ct);//为通讯录开辟空间
	while (!quit)
	{
		Menu();
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			Show(ct);
			break;
		case 2:
			AddContact(&ct);
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
	/*		Sort(ct);*/
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			quit = 1;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}