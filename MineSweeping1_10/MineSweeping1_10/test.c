#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void meun()
{
	printf("*********************\n");
	printf("*** 1.play 0.exit ***\n");
	printf("*********************\n");

}
void game()
{
	//创建两个数组
	char mine[ROWS][COLS];//布置好雷的
	char show[ROWS][COLS];//存放排查出雷的信息
	//初始化棋盘信息
	Initboard(mine, ROWS, COLS, '0');//mine初始化全是'0'
	Initboard(show, ROWS, COLS, '*');//show初始化全是'*'
	//打印棋盘
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//布置雷
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	//排查雷
	FindMine(mine, show, ROW, COL);
}

int main()
{
	meun();
	int input = 0;
	srand((unsigned int)rand(NULL));
	do
	{
		printf("请选择:>\n");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
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

