#define _CRT_SECURE_NO_WARNINGS 1 
#include "SeqList.h"

void test1()
{
	SL s1;
	SLInit(&s1);

	SLPushBack(&s1, 1);
	SLPushBack(&s1, 2);
	SLPushBack(&s1, 3);
	SLPushBack(&s1, 4);
	SLPushFront(&s1, 5);
	SLPrint(&s1);
	SLPopFront(&s1);
	SLPopBack(&s1);
	SLPrint(&s1);
	SLInsert(&s1, 1, 4);
	SLPrint(&s1);
	SLErase(&s1, 1);
	SLPrint(&s1);
	SLDestroy(&s1);
	SLPrint(&s1);
}

int main()
{
	test1();

	return 0;
}