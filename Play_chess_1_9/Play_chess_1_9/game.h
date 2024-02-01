#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ROW 3
#define COL 3
#include <time.h>

//初始化棋盘声明
void InitBoard(char board[ROW][COL], int row, int col);

//打印棋盘声明
void DipiayBoard(char board[ROW][COL], int row, int col);

//玩家下棋声明
void player_down(char board[ROW][COL], int row, int col);

//电脑下棋声明
void PlayerMove(char board[ROW][COL], int row, int col);

//判断游戏是否结束
//1.假设游戏结束
//玩家赢返回-'*'
//电脑赢返回-'#'
//平局返回 - 'Q'
//2.假设游戏继续
//游戏继续返回 - 'C'
//
char Iiwin(char board[ROW][COL], int row, int col);


