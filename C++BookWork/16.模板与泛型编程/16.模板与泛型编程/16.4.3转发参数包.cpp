#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <list>
#include <string> 
#include <memory>
#include <type_traits>
#include <climits>
#include "Blob.h"
#include "DebugDelete.h"
#include "StrVec.h"
#include "Vec.h"
#include "NoDefault.h"
using namespace std;


template <typename T = int>
void test1()
{
}

template <typename T, typename... Args>
shared_ptr<T> my_make_sharder(Args...args)
{
	 return make_shared<T>(std::forward<Args>(args)...);

}

int main()
{
	int a;
	test1();
	StrVec sv1;
	// 是只能传一个，emplace_back是构造一个对象，不是inli列表，通过转发保存参数的引用
	// 是要符合construct的构造函数
	sv1.emplace_back("asdf");
	sv1.emplace_back(10,'c');// construct有(dest，int,char)这个构造函数
	//sv1.emplace_back(1);// 自己的alloc只能确定一个类型。
	for (auto p1 = sv1.begin(); p1 != sv1.end(); p1++) {
		cout << *p1 << endl;
	}
	shared_ptr<string> sp1 = make_shared<string>(10,'c');
	cout << *sp1 << endl;

	shared_ptr<string> sp2 = my_make_sharder<string>(10,'a');
	cout << *sp2 << endl;

	cout << "-------------" << endl;
	Vec<int> vec1;
	vec1.emplace_back(3);
	vec1.emplace_back(5);
	vec1.emplace_back(12);
	vec1.emplace_back(6);
	vec1.printVec();
	cout << vec1 << endl;

	Vec<string> vec2;
	vec2.emplace_back(4,'c');
	vec2.emplace_back("value");

	cout << vec2 << endl;
	/*
	练习：
	16.58:放着，上一题都还没写
	16.59:叠加一个，s被转发
	16.60:接受可变参数模板，转发其参数初始化一个内存于内存空间，返回一个shared_ptr;
	16.61:放着，应该要用到转发参数包？？

	以前的需要：
	shared_ptr的实现需要显示模板实参，以及计数，以及析构调用的对象，等。
	*/
	cin >> a;
	return 0;
}


