#define _CRT_SECURE_NO_WARNINGS
#include "List.h"

void Test1()
{
	ListNode* plist = LTInit();
	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushFront(plist, 4);
	ListPrint(plist);

	ListNode* pos = ListFind(plist, 3);
	if (pos)
	{
		ListInsert(pos, 7);
	}
	ListPrint(plist);

	ListDestory(plist);

}


int main()
{
	Test1();


	return 0;
}











