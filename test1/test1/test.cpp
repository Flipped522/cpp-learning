#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//void f(int x)
//{
//	cout << "f(int x)" << endl;
//}
//void f(int* ptr)
//{
//	cout << "f(int* ptr)" << endl;
//}
//
//int main()
//
//{
//	f(0);
//	// 本想通过f(NULL)调⽤指针版本的f(int*)函数，但是由于NULL被定义成0，调⽤了f(int x)，因此与程序的初衷相悖。
//	f(NULL);
//	f((int*)NULL);
//	// f((void*)NULL);
//
//	f(nullptr);
//
//	return 0;
//}
#include<iostream>
using namespace std;

class A
{
private:
    static int _k;
    int _h = 1;
public:
    class B // B默认就是A的友元
    {
    public:
        void foo(const A& a)
        {
            cout << _k << endl;      //OK
            cout << a._h << endl;    //OK
        }

        int _b1;
    };
};

int A::_k = 1;

int main()
{
    cout << sizeof(A) << endl;

    A::B b;
    A aa;
    b.foo(aa);

    return 0;
}