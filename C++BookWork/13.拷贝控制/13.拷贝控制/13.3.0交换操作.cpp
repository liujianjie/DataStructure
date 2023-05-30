#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <stdio.h>
#include <time.h> 
#include <algorithm>
#include "StrBlob.h"
#include "StrBloPtr.h"
#include "Sales_data.h"
#include "HasPtr.h"
#include "Foo.h"
using namespace std;
/*
开篇引出：
对于那些与重排元素顺序的算法一起使用的类，定义swap是重要的。
如果自己定义了swap就使用类自定义版本，否则，算法将使用标准定义的swap

标准定义的swap会处理一个对象，创建一个临时的副本，那么就会导致string拷贝两次？（这个应该要定义为像值才会把，难道默认的swap是处理为值吗）
我们可以自己定义swap来处理指针对象，一个个处理

swap并不是必要的。对于分配了资源的类(就是有指针类型的成员并且行为像值)，定义swap是一种很重要的优化手段

二、swap函数应该调用swap，而不是std：：swap
如果一个类的成员有自己的swap函数，使用std::swap是错误的，前置std：：swap是为了让成员没有自己的swap函数调用标准库的swap，
如果有自己的swap就调用成员自己的swap

匹配程度优先标准库的swap,210页

三、在赋值运算符中使用swap
拷贝并交换的技术：
将左侧与右侧的一个副本进行交换
保证异常安全的方法也与原来的赋值运算符实现一样的
自动是异常安全的，并且能正确处理自赋值
*/
// 13.3

inline
void swap(Foo &lhs, Foo &rhs) {
	cout << "swap(Foo &lhs, Foo &rhs)" << endl;
	using std::swap;
	swap(lhs.h, rhs.h);
	// 其它foo的成员
}
int main() {

	int aa;
	
	HasPtr hs1("hs1"),hs2("hs2"); 

	Foo f1(hs1), f2(hs2);
	swap(f1,f2);
	cout << "f1的pss：" << f1.getHas().getPss() << endl;
	cout << "f2的pss：" << f2.getHas().getPss() << endl;

	// 练习
	/*
	参数都不匹配，实现的方法都不一样
	*/
	/*
	当使用swap时，就开头说的，与重排元素顺序的算法使用的时候
	*/
	cout << "-------" << endl;
	vector<HasPtr> ve;
	ve.push_back((HasPtr)("123"));
	ve.push_back((HasPtr)("1234"));
	ve.push_back((HasPtr)("122323"));
	ve.push_back((HasPtr)("13"));
	ve.push_back((HasPtr)("1"));
	sort(ve.begin(), ve.end());// 不知道怎么写, 突然又可以了

	for (auto it : ve) {
		cout << it.getPss() << endl;
	}
	cout << endl;
	
	/*
	类指针版本 不会分配内存，因此不会
	*/

	std::cin >> aa;
	return 0;
}