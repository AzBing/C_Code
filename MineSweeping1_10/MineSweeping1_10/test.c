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
	//������������
	char mine[ROWS][COLS];//���ú��׵�
	char show[ROWS][COLS];//����Ų���׵���Ϣ
	//��ʼ��������Ϣ
	Initboard(mine, ROWS, COLS, '0');//mine��ʼ��ȫ��'0'
	Initboard(show, ROWS, COLS, '*');//show��ʼ��ȫ��'*'
	//��ӡ����
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//������
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	//�Ų���
	FindMine(mine, show, ROW, COL);
}

int main()
{
	meun();
	int input = 0;
	srand((unsigned int)rand(NULL));
	do
	{
		printf("��ѡ��:>\n");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
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

