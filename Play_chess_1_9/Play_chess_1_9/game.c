#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

//初始化棋盘实现
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';

		}
	}
}
//打印棋盘实现
void DipiayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < row; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}
//玩家下棋实现
void player_down(char board[ROW][COL], int row, int col)
{
	printf("玩家下棋:>\n");
	int x, y;
	while (1)
	{
		printf("请输入下棋坐标:>\n");
		scanf("%d %d", &x, &y);
		//判断坐标是否合法
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//坐标是否被占用
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标被占用，请重新输入\n");
			}
		}
		else
		{
			printf("输入的坐标无效，请重新输入\n");
		}
	}
}
//电脑下棋实现
void PlayerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋:>\n");
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		//判断坐标是否被占用
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}

	}
}



int InFin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;

}
//判断获胜方
char Iiwin(char board[ROW][COL], int row, int col)
{
	//判断三行三列
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
		{
			return board[0][j];
		}
	}
	//判断交叉线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][0] != ' ')
	{
		return board[0][2];
	}
	if (InFin(board,ROW,COL) == 1)
	{
		return 'Q';
	}
	return 'C';
}














