#define _CRT_SECURE_NO_WARNINGS 1 
#include "SeqList.h"

void SLPrint(SL* ps)
{
	assert(NULL != ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}

void SLInit(SL* ps)
{
	ps->size = 0;
	ps->capacity = 0;
	ps->arr = NULL;
}

void SLDestroy(SL* ps)
{
	assert(ps);
	if (ps->arr)
		free(ps->arr);
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}

void SLCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType* tmp = realloc(ps->arr, newCapacity * sizeof(SLDataType));
		if (NULL == tmp)
		{
			perror("realloc error");
			exit(1);
		}
		ps->arr = tmp;
		ps->capacity = newCapacity;
	}
}

void SLPushBack(SL* ps, SLDataType x)
{
	assert(NULL != ps);

	SLCheckCapacity(ps);

	ps->arr[ps->size++] = x;
}

void SLPushFront(SL* ps, SLDataType x)
{
	assert(NULL != ps);

	SLCheckCapacity(ps);

	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[0] = x;
	++ps->size;
}

void SLPopBack(SL* ps)
{
	assert(NULL != ps);
	assert(ps->size);

	--ps->size;
}

void SLPopFront(SL* ps)
{
	assert(NULL != ps);
	assert(ps->size);

	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	--ps->size;
}

void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(NULL != ps);
	assert(pos >= 0 && pos <= ps->size);

	SLCheckCapacity(ps);

	for (int i = ps->size; i > pos ; --i)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[pos] = x;
	++ps->size;
}

void SLErase(SL* ps, int pos)
{
	assert(NULL != ps);
	assert(pos >= 0 && pos < ps->size);

	SLCheckCapacity(ps);

	for (int i = pos; i < ps->size - 1; ++i)
	{
		ps->arr[i] = ps->arr[i + 1];
	}

	--ps->size;
}

int SLFind(SL* ps, SLDataType x)
{
	assert(NULL != ps);
	for (int i = 0; i < ps->size; ++i)
	{
		if (ps->arr[i] == x)
		{
			return i;
		}
	}

	return -1;
}




