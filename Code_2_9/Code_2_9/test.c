#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
}ListNode;

//����������Ĺ����ڵ�
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) 
{
    struct ListNode* tailA = headA;
    struct ListNode* tailB = headB;
    int tmp1 = 1, tmp2 = 1;
    //�ȼ�����������ĳ���
    while (tailA)
    {
        tailA = tailA->next;
        ++tmp1;
    }
    while (tailB)
    {
        tailB = tailB->next;
        ++tmp2;
    }
    //���û�й����ڵ��ֱ�ӷ���NULL
    while (tailA != tailB)
    {
        return NULL;
    }
    int sz = abs(tmp1 - tmp2);
    //���������longList
    struct ListNode* longList = headA;
    struct ListNode* shortList = headB;
    if (tmp1 < tmp2)
    {
        longList = headB;
        shortList = headA;
    }
    while (sz--)
    {
        longList = longList->next;
    }
    //��ͬ�ߵ������ڵ㣬��������һ������
    while (longList != shortList)
    {
        longList = longList->next;
        shortList = shortList->next;
    }
    return longlist;
}













