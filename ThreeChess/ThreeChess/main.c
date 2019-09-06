#define _CRT_SECURE_NO_WARNINGS 1
#include"ThreeChess.h"
int main()
{
	int select = 0;
	int quit = 0;
	while (!quit)
	{
		ShowUI();
		scanf("%d", &select);
		switch(select)
		{
		case 1:
			Game();
				break;
		case 2:
		
					quit = 1;
					printf("游戏结束！\n");
					break;
		default:
					printf("输入错误请重新输入！\n");
					break;
		}	
	}
	system("pause");
	return 0;
}