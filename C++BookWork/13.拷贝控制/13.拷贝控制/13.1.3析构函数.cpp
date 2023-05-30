#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "StrBlob.h"
#include "StrBloPtr.h"
#include "Sales_data.h"

using namespace std;



/*
定义：是一个成员函数，由波浪号接类名构成，没有返回值

作用：释放对象使用的资源，销毁对象的非static数据成员

是一个成员函数，由波浪号接类名构成，没有返回值，不接受参数

不能被重载，只有一个

首先执行函数体，然后销毁成员，是初始化顺序的逆序销毁的

不存在初始化列表的东西控制成员如何销毁，析构部分是隐式的

完成依赖于成员的类型，类类型的成员需要执行成员自己的析构函数

内置类型没有析构函数，所以说都不需做

所以需要显示销毁一个指针，智能指针是类类型，有析构函数，会自动析构

什么时候析构：
1.离开作用域
2.对象被销毁，其成员被销毁
3.容器被销毁，其元素被销毁
4.动态分配的对象，delete时
5.临时对象，表达式结束

析构函数体自身并不直接销毁成员。成员是在析构函数体之后隐含的析构阶段中被销毁的，在整个对象销毁过程中，析构函数体是作为
成员销毁步骤之外的另一部分而进行的
*/
bool fcn(const Sales_data *trans, Sales_data accum)
{
	Sales_data item1(*trans), item2(accum);
	return item1.isbn() != item2.isbn();
}

struct X {
	X() 
	{
		cout << "X();" << endl; 
	}
	X(const string& st):str(st) 
	{ 
		cout << "X(const string& st):str(st);" << endl; 
	}

	X(const X&) 
	{
		cout << "X(const X&):"<<str << endl;
	}
	X& operator=(const X& rhs) 
	{ 
		str = rhs.str; 
		cout << "X& operator=(const X& rhs)" << endl; 
		return *this;
	}
	~X() 
	{ 
		cout << "~X():" << str << endl; 
	}
	string str;
};
void testKaobei(X x1) {
	cout << "testKaobei(X x1);" << endl;
}
// 引用不会拷贝
void testKaobei2(X& x1) {
	cout << "testKaobei2(X& x1);" << endl;
}
// 返回类型为为非引用
X testKaobei3(X& x1)
{
	cout << "testkaobei3(X& x1);" << endl;
	return x1;
}
X& testKaobei4(X& x1)
{
	cout << "testkaobei4(X& x1);" << endl;
	return x1;
}
int main() {

	int a;
	{
		Sales_data *p = new Sales_data;
		auto p2 = make_shared<Sales_data>();
		Sales_data item(*p);
		vector<Sales_data> vec;
		vec.push_back(*p2);
		delete p;
	}
	cout << "-----------------" << endl;
	auto p1 = make_shared<int>(42);
	weak_ptr<int> wp1(p1);// wp弱共享p，p引用计数未改变
	//wp1.reset();// 这个好像就是释放
	//cout << (wp1.lock()) << endl; 
	/*
	p2 item vec 析构方式1
	p 析构方式4
	*/
	// 练习
	/*
	当一个StrBlob对象销毁时会发生什么？StrBlobPtr呢？
	data成员是智能指针，所以会执行这个智能指针的析构函数，判断引用计数减1后是否为0 是就删除，
	StrBlobPtr不知道会不会执行释放弱指针指向的资源
	*/
	// 
	Sales_data *s1 = new Sales_data();
	Sales_data s2;
	fcn(s1, s2);
	// 3次，指针不会自动，accum，item1,item2结束会析构

	// 练习
	// 123 调用构造，再执行拷贝构造
	X x1 = X("123");


	testKaobei(x1);
	testKaobei2(x1);
	testKaobei3(x1);
	testKaobei4(x1);
	X x2;
	x2 = x1;// 调用拷贝赋值
	X *x3 = new X("13421");//绕过拷贝初始化，直接初始化
	delete x3;// 析构
	cin >> a;
	return 0;
}