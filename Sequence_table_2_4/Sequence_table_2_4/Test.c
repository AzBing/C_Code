#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"

void test1()
{
	SL s;
	SLInit(&s);
	SLEndAdd(&s, 1);
	SLEndAdd(&s, 2);
	SLEndAdd(&s, 3);
	SLEndAdd(&s, 4);
	SLEndAdd(&s, 5);
	SLEndAdd(&s, 6);
	SLEndAdd(&s, 6);
	SLEndAdd(&s, 6);
	SLEndAdd(&s, 6);
	SLPrint(&s);

	SLDestroy(&s);
}
void test2()
{
	SL s;
	SLInit(&s);
	SLEndAdd(&s, 1);
	SLEndAdd(&s, 2);
	SLEndAdd(&s, 3);
	SLEndAdd(&s, 4);
	SLHeadAdd(&s, 5);
	SLHeadAdd(&s, 6);
	SLHeadAdd(&s, 7);
	SLHeadAdd(&s, 8);
	SLHeadAdd(&s, 6);
	SLPrint(&s);

	SLDestroy(&s);
}

void test3()
{
	SL s;
	SLInit(&s);
	SLEndAdd(&s, 1);
	SLEndAdd(&s, 2);
	SLEndAdd(&s, 3);
	SLEndAdd(&s, 4);
	SLEndAdd(&s, 5);
	SLEndAdd(&s, 6);
	SLEndAdd(&s, 7);
	SLPrint(&s);

	SLPopBack(&s);
	SLPopBack(&s);
	SLPopBack(&s);
	SLPrint(&s);

	SLPopBack(&s);
	SLPopBack(&s);
	SLPopBack(&s);
	SLPrint(&s);

	SLDestroy(&s);
}

void test4()
{
	SL s;
	SLInit(&s);
	SLEndAdd(&s, 1);
	SLEndAdd(&s, 2);
	SLEndAdd(&s, 3);
	SLEndAdd(&s, 4);
	SLEndAdd(&s, 5);
	SLEndAdd(&s, 6);
	SLEndAdd(&s, 7);
	SLPrint(&s);

	SLPopFront(&s);
	SLPopFront(&s);
	SLPopFront(&s);
	SLPrint(&s);

	SLPopFront(&s);
	SLPopFront(&s);
	SLPopFront(&s);
	SLPrint(&s);


	SLDestroy(&s);
}

int main()
{
	test1();
	return 0;
}



