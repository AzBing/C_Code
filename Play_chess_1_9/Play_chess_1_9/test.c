#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

//菜单内容
void meun()
{
	printf("**************************\n");
	printf("******* 三子棋游戏 *******\n");
	printf("****** 1.play 2.exit *****\n");
	printf("**************************\n");
}
//实现游戏内容
void game()
{
	//初始化数组
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘内容
	DipiayBoard(board, ROW, COL);

	//开始游戏
	char ret = 0;
	while (1)
	{
		//1.玩家下并打印出棋盘
		player_down(board, ROW, COL);
		DipiayBoard(board, ROW, COL);
		//判断玩家是否赢得游戏
		ret = Iiwin(board, ROW, COL);

		//2.电脑下并打印出棋盘
		PlayerMove(board, ROW, COL);
		DipiayBoard(board, ROW, COL);
		//判断电脑是否赢得游戏
		ret = Iiwin(board, ROW, COL);

		if (ret == '*')
		{
			printf("玩家获胜\n");
			break;
		}
		if (ret == '#')
		{
			printf("电脑获胜\n");
			break;
		}
		else if (ret == 'Q')
		{
			printf("平局\n");
			break;
		}
	}
	DipiayBoard(board, ROW, COL);
}
//主函数
int main()
{
	//打印菜单
	meun();
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		printf("请选择1/0是否进入游戏\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("三子棋游戏开始\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
	
	return 0;
}

