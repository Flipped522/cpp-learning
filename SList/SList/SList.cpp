#pragma once
#include "SList.h"

SLTNode* SLTbuyNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (NULL == newnode)
	{
		perror("malloc failed");
		exit(1);
	}

	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void SLTPrint(SLTNode* phead)
{
	SLTNode* pcur = phead;
	while (NULL != pcur)
	{
		printf("%d ", pcur->data);
		pcur = pcur->next;
	}
	printf("\n");
}

void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = SLTbuyNode(x);
	if (NULL == *pphead)
	{
		*pphead = newnode;
	}
	else
	{
		SListNode* ptail = *pphead;
		while (ptail->next)
		{
			ptail = ptail->next;
		}
		ptail->next = newnode;
	}


}

void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = SLTbuyNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SLTPopBack(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	if (NULL == (*pphead)->next)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* tail = *pphead;
		SLTNode* prev = NULL;
		while (NULL != tail->next)
		{
			prev = tail;
			tail = tail->next;
		}
		prev->next = tail->next;
		free(tail);
		tail = NULL;
	}
}

void SLTPopFront(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	assert(NULL != phead);
	SLTNode* pos = phead;
	while (NULL != pos)
	{
		if (pos->data == x)
		{
			return pos;
		}
		else
		{
			pos = pos->next;
		}
	}
	return NULL;
}

void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(NULL != pphead);
	assert(NULL != *pphead);
	assert(NULL != pos);

	if (pos == *pphead)
	{
		SLTPushFront(pphead, x);
	}
	else
	{
		SLTNode* newnode = SLTbuyNode(x);
		SLTNode* pcur = *pphead;
		while (pcur->next != pos)
		{
			pcur = pcur->next;
		}
		pcur->next = newnode;
		newnode->next = pos;
	}
}

void SLTInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(NULL != pos);
	SLTNode* newnode = SLTbuyNode(x);
	SLTNode* next = pos->next;
	pos->next = newnode;
	newnode->next = next;
}

void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead);
	assert(*pphead);

	if (pos == *pphead)
	{
		SLTPopFront(pphead);
	}
	else
	{
		SLTNode* pcur = *pphead;
		while (pcur->next != pos)
		{
			pcur = pcur->next;
		}
		pcur->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

void SLTEraseAfter(SLTNode* pos)
{
	assert(NULL != pos);
	assert(NULL != pos->next);
	SLTNode* next = pos->next;
	pos->next = next->next;
	free(next);
	next = NULL;
}

void SListDestroy(SLTNode** pphead)
{
	assert(pphead);
	SLTNode* pcur = *pphead;
	while (NULL != pcur)
	{
		SLTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}
