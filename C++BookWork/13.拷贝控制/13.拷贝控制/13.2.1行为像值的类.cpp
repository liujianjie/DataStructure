#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <stdio.h>
#include <time.h> 
#include "StrBlob.h"
#include "StrBloPtr.h"
#include "Sales_data.h"
#include "HasPtr.h"

using namespace std;
/*
定义：
每个对象都应该拥有一份自己的拷贝

二、类值拷贝赋值运算符
组合了析构函数和构造函数的操作
因为需要删除左侧对象的指针,释放内存，而内置类型不需要理会
需注意自身赋值自身，需要临时对象，若删除左侧指针，右侧同样删除了就错了
*/
void fun(HasPtr h) {
	// 离开作用域会deletestring
}
class TestCl {
public:
	TestCl(const string& s = string()) :
		str(new string(s)) {
	}
	~TestCl() {
		delete str;
	}
	string* str;
};
int main() {

	int aa;
	HasPtr *hs = new HasPtr("hss");
	cout << hs->getPss() << endl;
	fun(*hs);// 会删除hs的str的指针
	//cout << hs->getPss() << endl;// 为空，内存泄漏
	//TestCl *t1 = new TestCl("12321");
	//auto s2 = t1->str;
	//delete t1;
	//cout << *s2 << endl;
	// 练习
	/*
	当类被销毁时，永远都不会执行释放pss所占的内存
	未定义拷贝构造函数，会多次删除pss所占的内存，导致内存泄漏
	*/
	/*
	strblob
	拷贝构造函数：将数据拷贝出一份出来给strblob
	拷贝赋值：先将左侧的删除，再拷贝右侧的
	strblobptr
	拷贝构造：差不多吧一样的拷贝
	拷贝赋值：一样的左侧删除，拷贝右侧的

	不用因为智能指针自动析构
	*/
	cin >> aa;
	return 0;
}