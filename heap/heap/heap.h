#define _CRT_SECURE_NO_WARNINGS 1 

#pragma once
#include <vector>
#include <algorithm>

template<class T, class Container = std::vector<T>, class Cmp = std::less<T>>
class Heap
{
public:
	void AdjustUp(int child)
	{
		Cmp cmp;
		int parent = (child - 1) / 2;
		while (parent >= 0)
		{
			if (cmp(_con[parent], _con[child]))
			{
				std::swap(_con[parent], _con[child]);
				child = parent;
				parent = (parent - 1) / 2;
			}
			else
			{
				break;
			}
		}
	}
	void AdjustDown(int parent)
	{
		Cmp cmp;
		int child = parent * 2 + 1;
		while (child < _con.size())
		{
			if (child + 1 < _con.size() && cmp(_con[child], _con[child + 1]))	++child;

			if (cmp(_con[parent], _con[child]))
			{
				std::swap(_con[parent], _con[child]);
				parent = child;
				child = child * 2 + 1;
			}
			else
			{
				break;
			}
		}
	}

	void Push(const T& x)
	{
		_con.push_back(x);
		AdjustUp(_con.size() - 1);
	}
	void Pop()
	{
		std::swap(_con[0], _con[_con.size() - 1]);
		_con.pop_back();
		AdjustDown(0);
	}
	//È¡¶Ñ¶¥Êý¾Ý
	T Top()
	{
		return _con[0];
	}

	// ÅÐ¿Õ
	bool Empty()
	{
		return _con.empty();
	}

private:
	Container _con;
};

