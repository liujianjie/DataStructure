#include <iostream>
#include <vector>
#include <memory>
#include <list>
#include "Sales_data.h"
#include "StrBlob.h"
//#include <>
using namespace std;
/*
1.直接初始化方式，只有一个unique_ptr指向一个给定对象。
2.没有make_shared标准函数
3.不支持普通的拷贝或赋值操作
4.但是将要删除unique_ptr时编译器允许拷贝或者赋值操作
5.向unique_ptr传递删除器需要指定删除器类型
*/
unique_ptr<int> clone(int p)
{
	return unique_ptr<int>(new int(p));
}

unique_ptr<int> clone2(int p)
{
	unique_ptr<int> ret(new int(p));
	return ret;
}
void deletefun(int *p)
{
	cout << "deletefun" << endl;
	delete p;
}
int main()
{
	int a;
	unique_ptr<string> p1(new string("Stegosaurus"));
	//unique_ptr<string> p2(p1);// 错误
	//unique_ptr<string> p3;
	//p3 = p1;

	// 但可以用release或者reset 转移，但只能有一个指向给定对象
	unique_ptr<string> p2(p1.release());
	unique_ptr<string> p3(new string("Trex"));
	// 
	p2.reset(p3.release());//reset释放了p2原本指向的内存
	cout << *p2 << endl;

	unique_ptr<string> p4(new string("Steg"));
	//p4.release();// p4放弃了，但是不会释放内存，丢了了p4指针，不可释放两次
	//cout << *p4 << endl;
	auto p5 = p4.release();
	cout << *p5 << endl;
	delete p5;

	// 向unique_ptr传递删除器
	int *pp = new int(43);
	unique_ptr<int, decltype(deletefun)*> p6(pp, deletefun);
	p6.reset();

	// 练习
	unique_ptr<int> p7(new int(3));
	//unique_ptr<int> p8(p7);
	//unique_ptr<int> p9 = p8;

	// 
	int p8 = 12,*p9 = &p8;
	shared_ptr<int> sp2(p9);
	cout << *sp2 << endl;

	int ix = 1025, *pi = &ix, *pi2 = new int(2048);
	typedef unique_ptr<int> IntP;
	//IntP p0(ix);
	IntP p11(pi);
	IntP p22(pi2);
	IntP p33(&ix);
	IntP p44(new int(2019));
	IntP p55(p22.get());
	cout << *p22 << endl;
	cout << *p55 << endl;

	// 因为当一个shared_ptrrelease后，指向的内存就释放了，但允许多个shared_ptr指向同一个内存

	cin >> a;
	return 0;
}
