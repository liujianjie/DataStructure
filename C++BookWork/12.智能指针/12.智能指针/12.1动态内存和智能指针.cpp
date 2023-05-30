#include <iostream>
#include <vector>
#include <memory>
#include <list>
#include "Sales_data.h"
#include "StrBlob.h"
using namespace std;

/*
在程序中用堆来存放的对象
在程序运行时创建的对象
用new来实例化的

未删除 造成内存泄漏
删了但又引用 会非法

shared_ptr允许多个指针指向同一个对象
unique_ptr独占一个对象
weak_ptr 伴随类是弱引用
头文件 memory中
*/

void Foo() 
{
	shared_ptr<string> s = make_shared<string>("12");// 函数结束时自动销毁
}
shared_ptr<string> Foo2()
{
	shared_ptr<string> s = make_shared<string>("12");// 函数结束时自动销毁
	return s;// 还有引用 指向的内存不会释放，return 加1，离开 -1没有变
}
int main()
{
	int a;
	string str = "hi";
	shared_ptr<string> p1(new string("21"));
	shared_ptr<list<int>> p2;//空的
	
	if (p1 && p1->empty()) {
		//*p1 = "hi";// 指向新的 但是
		*p1 = str;
	}
	cout << p1 << endl;
	cout << p1.get() << endl;
	cout << p1.use_count() << endl;
	cout << p1.unique() << endl;

	// make_shared函数
	// 指向一个值为42的int的shared_ptr
	shared_ptr<int> p3 = make_shared<int>(42);
	shared_ptr<string> p4 = make_shared<string>(10,'9');
	// 指向一个值初始化的int 值为0
	shared_ptr<int> p5 = make_shared<int>();

	auto p6 = make_shared<vector<int>>();

	// shared_ptr的拷贝与赋值
	auto p7 = make_shared<int>(42);
	auto q1(p7);//q1与p7指向相同的对象// 会递增p7的计数器 引用计数吗,那么就是说 q1的引用计数=p7的引用计数的意思吧
	cout << p7.use_count() << endl;

	auto p8 = make_shared<int>(30);
	p8 = p7;
	/*
	p8指向p7指向的指针
	递增p7引用计数
	递减p8原来的引用计数为0
	销毁p8原来的指向的对象 自动释放
	*/
	cout << p8.use_count() << endl;

	// 析构函数

	// 自动释放动态对象

	// 使用动态生存期的资源的类
	// 原vector和副本vector中的元素是相互分离的，想有关联 得用 shared_ptr,这就造成只有最后一个对象的删除 这些元素才可以删除

	StrBlob b1;
	{
		StrBlob b2 = { "a","an","the" };
		b1 = b2;
		b2.push_back("about");
		cout << b2.data->size() << endl;
	}
	string st = "dd";
	b1.check(1, st);
	b1.pop_back();
	cout << b1.data->size() << endl;
	
	// 练习
	// 12.3不要把。不需要常量的strblob改不了对象
	// 12.4因为size_type的类型是无符号，当负号时会变得很大，铁定超范围
	// 12.5 不然就得创建一个vector<string>多麻烦
	cin >> a;
	return 0;
}
