#define _CRT_SECURE_NO_WARNINGS 1 
#include "SList.h"

void TestSList()
{
    SLTNode* plist = NULL;

    printf("1. 测试空链表\n");
    SLTPrint(plist);

    printf("\n2. 测试尾插：1 2 3\n");
    SLTPushBack(&plist, 1);
    SLTPushBack(&plist, 2);
    SLTPushBack(&plist, 3);
    SLTPrint(plist);

    printf("\n3. 测试头插：在链表头部依次插入10、20\n");
    SLTPushFront(&plist, 10);
    SLTPushFront(&plist, 20);
    SLTPrint(plist);

    printf("\n4. 测试查找元素2\n");
    SLTNode* pos = SLTFind(plist, 2);
    if (pos != NULL)
    {
        printf("找到元素：%d\n", pos->data);
    }
    else
    {
        printf("没有找到元素2\n");
    }

    printf("\n5. 测试在元素2之前插入100\n");
    pos = SLTFind(plist, 2);
    if (pos != NULL)
    {
        SLTInsert(&plist, pos, 100);
    }
    SLTPrint(plist);

    printf("\n6. 测试在元素2之后插入200\n");
    pos = SLTFind(plist, 2);
    if (pos != NULL)
    {
        SLTInsertAfter(pos, 200);
    }
    SLTPrint(plist);

    printf("\n7. 测试删除元素100\n");
    pos = SLTFind(plist, 100);
    if (pos != NULL)
    {
        SLTErase(&plist, pos);
    }
    SLTPrint(plist);

    printf("\n8. 测试删除元素2之后的结点\n");
    pos = SLTFind(plist, 2);
    if (pos != NULL && pos->next != NULL)
    {
        SLTEraseAfter(pos);
    }
    SLTPrint(plist);

    printf("\n9. 测试头删\n");
    SLTPopFront(&plist);
    SLTPrint(plist);

    printf("\n10. 测试尾删\n");
    SLTPopBack(&plist);
    SLTPrint(plist);

    printf("\n11. 测试删除头结点\n");
    pos = plist;
    if (pos != NULL)
    {
        SLTErase(&plist, pos);
    }
    SLTPrint(plist);

    printf("\n12. 测试在头结点之前插入500\n");
    pos = plist;
    if (pos != NULL)
    {
        SLTInsert(&plist, pos, 500);
    }
    SLTPrint(plist);

    printf("\n13. 测试查找不存在的元素999\n");
    pos = SLTFind(plist, 999);
    if (pos != NULL)
    {
        printf("找到元素：%d\n", pos->data);
    }
    else
    {
        printf("没有找到元素999\n");
    }

    printf("\n14. 测试销毁链表\n");
    SListDestroy(&plist);

    if (plist == NULL)
    {
        printf("链表销毁成功，plist == NULL\n");
    }
    else
    {
        printf("链表销毁失败\n");
    }

    SLTPrint(plist);
}

int main()
{
    TestSList();

	return 0;
}