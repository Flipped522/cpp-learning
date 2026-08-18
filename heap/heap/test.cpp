#define _CRT_SECURE_NO_WARNINGS 1 
#include "heap.h"
#include <iostream>
using namespace std;

template<class Container, class Cmp = std::less<typename Container::value_type>>
void AdjustDown(Container& _con, int parent, int end,Cmp cmp)
{
    int child = parent * 2 + 1;
    while (child < end)
    {
        if (child + 1 < end && cmp(_con[child], _con[child + 1]))	++child;

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

template<class Container, class Cmp = std::less<typename Container::value_type>>
void HeapSort(Container& _con)
{
    Cmp cmp;
    // 向下调整建堆
    for (int i = (_con.size() - 1 - 1) / 2; i >= 0; --i)
    {
        AdjustDown(_con, i, _con.size(), cmp);
    }
    int end = _con.size() - 1;
    while (end > 0)
    {
        swap(_con[0], _con[end]);
        AdjustDown(_con, 0, end, cmp);
        end--;
    }
}

int main()
{
    //// 测试数据
    //vector<int> arr = { 4, 2, 7, 1, 5, 8, 3 };
    //Heap<int> hp;
    //for (auto x : arr)
    //{
    //    hp.Push(x);
    //}

    //cout << "依次取出堆顶（大堆，从大到小）：" << endl;
    //while (!hp.Empty())
    //{
    //    cout << hp.Top() << " ";
    //    hp.Pop();
    //}
    //cout << "\n\n";

    //// 单独测试Push
    //Heap<int> hp2;
    //hp2.Push(6);
    //hp2.Push(2);
    //hp2.Push(9);
    //hp2.Push(1);
    //cout << "新堆弹出顺序：";
    //while (!hp2.Empty())
    //{
    //    cout << hp2.Top() << " ";
    //    hp2.Pop();
    //}
    //cout << endl;

    vector<int> v = { 9,7,8,3,5 };
    HeapSort(v);

    return 0;
}