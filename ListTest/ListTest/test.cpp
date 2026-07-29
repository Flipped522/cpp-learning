#define _CRT_SECURE_NO_WARNINGS 1 
#include "List.h"

int main()
{
	cgc::list<int> list;
	list.push_back(5);
	list.push_back(6);

	cgc::list<int>::const_iterator it = list.begin();
}