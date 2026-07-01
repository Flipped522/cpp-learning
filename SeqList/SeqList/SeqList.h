#define _CRT_SECURE_NO_WARNINGS 1 
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* arr;
	int size;		// 有效数据个数
	int capacity;	// 空间容量
}SL;

void SLPrint(SL* ps);
//初始化
void SLInit(SL* ps);
//销毁
void SLDestroy(SL* ps);

//尾插
void SLPushBack(SL* ps, SLDataType x);
//头插
void SLPushFront(SL* ps, SLDataType x);
//尾删
void SLPopBack(SL* ps);
//头删
void SLPopFront(SL* ps);

//指定位置之前插⼊数据
void SLInsert(SL* ps, int pos, SLDataType x);
// 删除POS位置的数据
void SLErase(SL* ps, int pos);
//查找
int SLFind(SL* ps, SLDataType x);