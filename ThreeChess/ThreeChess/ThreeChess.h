#define _CRT_SECURE_NO_WARNINGS 1

#ifndef _THREE_CHESS_H_
#define _THREE_CHESS_H_

#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<time.h>
#pragma warning(disable:4996)

#define ROW 3
#define COL 3

void ShowUI();
void Game();
void ComputerMove(char board[ROW][COL], int row, int col);
void PlayerMove(char board[][COL], int row, int col);
void ShowBoard(char board[][COL], int row, int col);
char Judge(char board[][COL], int row, int col);

#endif