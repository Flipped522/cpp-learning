#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

void Print(int n, int i)
{
	for (; i < n; ++i)
	{
		cout << this_thread::get_id() << " : " << i << endl;
	}
	cout << endl;
}

int main()
{
	std::mutex mtx;
	thread t1(Print, 10, 0);
	thread t2(Print, 5, 0);
	

	// ...
	t1.join();
	t2.join();

	return 0;
}