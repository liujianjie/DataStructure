#include <iostream>
#include <vector>
#include <memory>
#include <list>
#include "Sales_data.h"
#include "StrBlob.h"
using namespace std;

vector<int>* twelvesix()
{
	return new vector<int>();
}
vector<int>* cinfun()
{
	vector<int>* ve = twelvesix();// 动态内存
	int val;
	while (cin >> val && val != -1) {
		(*ve).push_back(val);
	}
	return ve;
}
void outfun()
{
	vector<int>* ve = cinfun();
	for (const auto &i : *ve) {
		cout << i << endl;
	}
	delete ve;// 释放了twelvesix cinfun outfun创建的vector动态内存，并且指针都在函数结束时删除
}


shared_ptr<vector<int>> twelvesix2()
{
	return make_shared<vector<int>>();
}
shared_ptr<vector<int>>  cinfun2()
{
	shared_ptr<vector<int>> ve = twelvesix2();// 动态内存
	int val;
	while (cin >> val && val != -1) {
		(*ve).push_back(val);
	}
	return ve;
}
void outfun2()
{
	shared_ptr<vector<int>> ve = cinfun2();
	for (const auto &i : *ve) {
		cout << i << endl;
	}
	// ve离开作用域，指向的内存会被自动释放
}

bool b()
{
	int* p = new int;
	return p;
}
/*
new 与delete
不能依赖类对象拷贝 赋值和销毁操作的任何默认定义

动态内存的管理容易出错
1.内存泄漏，当内存很多未delete
2.使用已经释放掉的对象
3.同一个内存释放两次
*/
int main()
{
	int a;

	// 在堆空间中 内存是无名的
	int *p1 = new int;// p1指向一个动态分配的未初始化的无名对象
	// 动态分配的对象默认情况下是默认初始化的 
	// 内置类型或组合类型的对象的值将是未定义的，类类型对象用默认构造函数初始化，string是类
	string *pstr = new string;// 初始化为空的string
	int *p2 = new int;// p2指向一个未初始化的int

	// 可以用直接初始化 列表初始化，传统的构造方式
	int *p3 = new int(10);
	string *pstr2 = new string(10, '9');
	vector<int> *pv1 = new vector<int>{ 1,2,3 };

	//值初始化，类型名之后跟一堆括号
	string *pstr3 = new string();// 与默认构造函数的默认初始化一样
	int *p4 = new int();// 内置类型 有区别，默认初始化为未定义，值初始化良好定义的值

	//auto推断类型，只有单一初始化器时才可以
	auto p5 = new auto(4);
	//auto p6 = new auto{12, 32};

	// 动态分配的const对象 返回指向const的指针
	const int *p7 = new const int;// 未定义 也可以？14？
	const string *p8 = new const string;// 隐式初始化

	// 定位new 允许我们向new传递额外的参数
	int *p9 = new (nothrow) int;

	// 释放动态内存 将内存归还给系统，两个动作，销毁给定的指针指向的对象，释放对应的内存
	delete p9;// 指向的可以是空指针 或者 动态分配的对象

	// 指针值和delete 删除的对象空指针 或者 动态分配的内存，若多次删除同一个指针值或不是new分配的内存，未定义
	// 编译通过，但是却是错误的
	int i1, *p10 = &i1, *p11 = nullptr;
	double *pd1 = new double(33), *pd2 = pd1;
	//delete i1;
	//delete p10;// 局部变量
	delete pd1;
	//delete pd2;// 重复删除 ，但内存已经释放不可
	delete p11;//可以

	// const 对象的值不能改变，但是他本身可以销毁
	const int *p12 = new int(34);
	//*p12 = 43;
	delete p12;
	int *p13 = new int(34);
	*p13 = 43;

	// 内置指针管理的动态对象，直到被显式释放之前都是存在的 
	/*
	即：即使所在作用域的函数结束了，指针会销毁 但是指针所值得内存不会销毁不会自动释放
	*/

	// 空悬指针
	int *p14 = new int(22);
	delete p14;
	//cout << *p14 << endl; 还是保留着已经释放了的动态内存的地址空悬指针，具有未初始化指针所有缺点
	// 可以置位nullptr
	p14 = nullptr;

	// 但是可能有多个指针指向同一内存，删除其一指针释放内存，再赋为nullptr使其安全，但是其它指针却还是未定义的
	int *p15 = new int(12);
	int *p16 = p15;// 指向相同的内存
	delete p15;// p
	p15 = nullptr;// 指出p不再绑定到任何对象,但p16并不为nullptr为空悬指针，也需要指向nullptr

	// test
	int *p17 = new int(12);
	int &pref1 = *p17;
	cout << p17 << endl;
	delete p17;
	p17 = nullptr;
	cout << p17 << endl;
	cout << &pref1 << endl;
	cout << pref1 << endl;// 引用指向的内存为未定义，但是还是指向那个地址

	// 练习
	//outfun();

	// 
	//outfun2();
	// 不会报错？好奇怪，p是一个地址，不是*p?，地址可以转换为bool吧？
	cout << b() << endl;

	cout << ((bool)-1) << endl;// 只要不是0的都能转换为true

	//
	int *p20 = new int(42), *r = new int(199);
	r = p20;// 让r指向与p20同指向的内存
	cout << *r << endl;

	auto p21 = make_shared<int>(42), r2 = make_shared<int>(100);
	r2 = p21;
	/*让p21的引用计数递增
		r2的引用递减为0 并且销毁内存
		r2指向p21指向的内存了
	*/
	cout << *r2 << endl;
	cout << p21.use_count() << endl;
		

	// test
	int *p19 = new int;// 未定义的
	cout << *p19 << endl;// 值会未确定
	cout << p19 << endl;// 但是地址还是有


	cin >> a;
	return 0;
}
