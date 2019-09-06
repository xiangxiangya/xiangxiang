#define _CRT_SECURE_NO_WARNINGS 1
#include"ThreeChess.h"

void ShowUI()
{
	printf("*******************************\n");
	printf("*    1、GAME       2、EXIT    *\n");
	printf("*******************************\n");
	printf("请选择：\n");
}

void Game()
{
	char board[ROW][COL];
	memset(board, ' ', sizeof(board));
	char result = 0;//o电脑赢    x玩家赢    n继续    e平局
	srand((unsigned long)time(NULL));//有可能的bug，没有指定time的类型
	while (1)
	{
		ComputerMove(board[ROW][COL], ROW, COL);
		ShowBoard(board[ROW][COL], ROW, COL);
		char result = Judge(board[ROW][COL], ROW, COL);
		if (result != 'N')
		{
			break;
		}
		else
			PlayerMove(board[ROW][COL], ROW, COL);
		ShowBoard(board[ROW][COL], ROW, COL);
		result = Judge(board[ROW][COL], ROW, COL);
		if (result != 'N')
		{
			break;
		}


		switch (result)
		{
		case 'X':
			printf("恭喜你你赢了！\n");
			break;
		case'O':
			printf("你输了！\n");
			break;
		case'E':
			printf("平局\n");
			break;
		}
	}
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = 'O';
			break;
		}
	}
	return;
}


void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x; 
	int y;
	while (1)
	{
		printf("请输入坐标！\n");
		scanf("%d %d", &x, &y);
		if ((x >= 1 && x < row) && (y >= 1 && y < col))
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'X';
			}
			else
			{
				printf("输入错误请重新输入！\n");
			}
		}
		else
		{
			printf("格式有误请重新输入！\n");
		}
	}
}

char Judge(char board[ROW][COL], int row, int col)//判断函数
{
	int i = 0; 
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] != ' ')//判断横行是否连城3
		{
			return board[i][0];
		}
	}
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] != ' ')//判断纵行是否连城3
		{
			return board[0][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != ' ')//判断斜线
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] != ' ')//判断斜线
	{
		return board[0][2];
	}

	for (i = 0; i < row; i++)//判断是否棋盘放满了
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 'N';           //继续游戏
			}
		}
	}
	//平局
	return 'E';

}


void ShowBoard(char board[ROW][COL], int row, int col)
{
	system("cls");               //清屏
	printf("    1   2   3\n");    //行标志
	printf("---------------\n");
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		printf("%d |", i + 1);   //列标志
		for (j = 0; j < col; j++)
		{
			printf(" %c |", board[i][j]);
		}
		printf("\n---------------\n");
	}
	printf("\n");
}