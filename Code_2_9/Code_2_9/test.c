#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
}ListNode;

//找两个链表的公共节点
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) 
{
    struct ListNode* tailA = headA;
    struct ListNode* tailB = headB;
    int tmp1 = 1, tmp2 = 1;
    //先计算两个链表的长度
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
    //如果没有公共节点就直接返回NULL
    while (tailA != tailB)
    {
        return NULL;
    }
    int sz = abs(tmp1 - tmp2);
    //假设最长的是longList
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
    //共同走到公共节点，返回其中一个即可
    while (longList != shortList)
    {
        longList = longList->next;
        shortList = shortList->next;
    }
    return longlist;
}













