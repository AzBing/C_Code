#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ROW 3
#define COL 3
#include <time.h>

//��ʼ����������
void InitBoard(char board[ROW][COL], int row, int col);

//��ӡ��������
void DipiayBoard(char board[ROW][COL], int row, int col);

//�����������
void player_down(char board[ROW][COL], int row, int col);

//������������
void PlayerMove(char board[ROW][COL], int row, int col);

//�ж���Ϸ�Ƿ����
//1.������Ϸ����
//���Ӯ����-'*'
//����Ӯ����-'#'
//ƽ�ַ��� - 'Q'
//2.������Ϸ����
//��Ϸ�������� - 'C'
//
char Iiwin(char board[ROW][COL], int row, int col);


