#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"


void test1()
{
	SLTNode* plist = NULL;

	/*SLTPushFront(&plist,1);
	SLTPushFront(&plist,2);
	SLTPushFront(&plist,3);
	SLTPushFront(&plist,4);*/

	//SLTPrint(plist);
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPrint(plist);

	SLTNode* pos = SListFind(plist, 3);
	if (pos)
	{
		SLTInsert(&plist,pos,7);
	}
	SLTPrint(plist);

	/*pos = SListFind(plist, 4);
	if (pos)
	{
		SLTErase(&plist,pos);
	}
	SLTPrint(plist);*/
	SLTDestroy(&plist);

}


int main()
{
	test1();

	return 0;
}


