#define _CRT_SECURE_NO_WARNINGS 1
#include"ThreeChess.h"

void ShowUI()
{
	printf("*******************************\n");
	printf("*    1��GAME       2��EXIT    *\n");
	printf("*******************************\n");
	printf("��ѡ��\n");
}

void Game()
{
	char board[ROW][COL];
	memset(board, ' ', sizeof(board));
	char result = 0;//o����Ӯ    x���Ӯ    n����    eƽ��
	srand((unsigned long)time(NULL));//�п��ܵ�bug��û��ָ��time������
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
			printf("��ϲ����Ӯ�ˣ�\n");
			break;
		case'O':
			printf("�����ˣ�\n");
			break;
		case'E':
			printf("ƽ��\n");
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
		printf("���������꣡\n");
		scanf("%d %d", &x, &y);
		if ((x >= 1 && x < row) && (y >= 1 && y < col))
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'X';
			}
			else
			{
				printf("����������������룡\n");
			}
		}
		else
		{
			printf("��ʽ�������������룡\n");
		}
	}
}

char Judge(char board[ROW][COL], int row, int col)//�жϺ���
{
	int i = 0; 
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] != ' ')//�жϺ����Ƿ�����3
		{
			return board[i][0];
		}
	}
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] != ' ')//�ж������Ƿ�����3
		{
			return board[0][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != ' ')//�ж�б��
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] != ' ')//�ж�б��
	{
		return board[0][2];
	}

	for (i = 0; i < row; i++)//�ж��Ƿ����̷�����
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 'N';           //������Ϸ
			}
		}
	}
	//ƽ��
	return 'E';

}


void ShowBoard(char board[ROW][COL], int row, int col)
{
	system("cls");               //����
	printf("    1   2   3\n");    //�б�־
	printf("---------------\n");
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		printf("%d |", i + 1);   //�б�־
		for (j = 0; j < col; j++)
		{
			printf(" %c |", board[i][j]);
		}
		printf("\n---------------\n");
	}
	printf("\n");
}