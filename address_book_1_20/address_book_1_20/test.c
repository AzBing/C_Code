#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"


void menu()
{
	printf("******************************\n");
	printf("*****  1.add    2.del    *****\n");
	printf("*****  3.search 4.modify *****\n");
	printf("*****  5.show   6.sort   *****\n");
	printf("*********  0.exit  ***********\n");
}

void test()
{
	int input = 0;

	Contact con;
	InitContact(&con);

	do
	{
		menu();
		printf("��ѡ��:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			SaveContact(&con);
			DestroyContact(&con);
			printf("�˳�����\n");
			break;
		default:
			printf("ѡ���������ѡ��:>\n");
			break;
		}
	} while (input);
}

int main()
{

	test();

	return 0;
}



