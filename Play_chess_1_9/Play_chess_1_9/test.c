#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

//�˵�����
void meun()
{
	printf("**************************\n");
	printf("******* ��������Ϸ *******\n");
	printf("****** 1.play 2.exit *****\n");
	printf("**************************\n");
}
//ʵ����Ϸ����
void game()
{
	//��ʼ������
	char board[ROW][COL] = { 0 };
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ��������
	DipiayBoard(board, ROW, COL);

	//��ʼ��Ϸ
	char ret = 0;
	while (1)
	{
		//1.����²���ӡ������
		player_down(board, ROW, COL);
		DipiayBoard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ����Ϸ
		ret = Iiwin(board, ROW, COL);

		//2.�����²���ӡ������
		PlayerMove(board, ROW, COL);
		DipiayBoard(board, ROW, COL);
		//�жϵ����Ƿ�Ӯ����Ϸ
		ret = Iiwin(board, ROW, COL);

		if (ret == '*')
		{
			printf("��һ�ʤ\n");
			break;
		}
		if (ret == '#')
		{
			printf("���Ի�ʤ\n");
			break;
		}
		else if (ret == 'Q')
		{
			printf("ƽ��\n");
			break;
		}
	}
	DipiayBoard(board, ROW, COL);
}
//������
int main()
{
	//��ӡ�˵�
	meun();
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		printf("��ѡ��1/0�Ƿ������Ϸ\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��������Ϸ��ʼ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	
	return 0;
}

