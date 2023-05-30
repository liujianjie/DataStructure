#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

//void *operator new(size_t size)
//{
//	cout << "our indentity new" << endl;
//	if (void *mem = malloc(size))
//		return mem;
//	else
//		throw bad_alloc();// 内存不足 或者其它
//}
//void operator delete(void *mem) noexcept
//{
//	cout << "our indentity delete"  << endl;
//	free(mem);
//}

int main()
{
	int a;
	int *i1 = new int(10);
	cout << i1 << endl;
	cout << *i1 << endl;

	// 使用全局的，找不到才是标准库的
	int *i2 = ::new int(1);
	cout << *i2 << endl;

	delete i2;

	void *mem = malloc(1);// 分配内存，返回地址
	int *i3 = new (mem) int(2);// 指向地址 构造初始值
	cout << *i3 << endl;// 为2

	void *mem2 = malloc(2);
	int *i4 = new(mem2) int;
	cout << (*i4) << endl;

	string *sp = new string("a vale");
	sp->~string();

	/*
	练习：
	19.1
	ok
	19.2:
	额，不现实吧，alloc.allocate(e - b);这种新空间 开始的位置和拷贝的尾后的位置怎么办？？？？
	*/
	cin >> a;
	return 0;
}
