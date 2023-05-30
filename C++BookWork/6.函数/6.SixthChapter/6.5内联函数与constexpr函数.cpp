#include <iostream>
#include <string>
#include <cassert>
#include "Account.h"
#include "Record.h"
// but没有用
//#define NOEBUG
using namespace std;

// 一：内联函数，因为函数调用需要传入实参，需要在调用点保存在寄存器，返回时恢复，需要转向一个新位置执行
// 内联函数，意思为在调用点上内联地展开
inline const string&
shorterString(const string &s1,const string &s2)
{
	return s1.size() <= s2.size() ? s1 : s2;
}
// 关键字：inline，对象：优化规模较小、流程直接、频繁调用的函数，很多编译器不支持内联递归函数

// 二：constexpr函数，隐式的为内联函数，对constexpr函数的调用替换成其结果值。
// 1constexpr用于常量表达式的函数，1.函数的返回类型以及形参类型都嘚是字面值类型，2.有且只有一条return语句
// 2执行初始化任务时，编译器把对constexpr函数的调用替换成其结果值，为了在编译过程中展开，constexpr函数被隐式地指定为内联函数
// 3.允许constexpr函数的返回值并非一个常量
// 4.constexpr函数中科院有空语句、类型别名，using声明，但是不能有语句

int testreturn() {
	return 2;
	return 3;
}
// 1
int i = 2;
constexpr int new_sz()
{
	//if(i){}
	//3
	//return 2;
	return 42;
}
constexpr int new_sz2(int s)
{
	return s;
}
// 允许constexpr函数返回值并非一个常量：
constexpr size_t scale(size_t cnt) {
	return new_sz() * cnt;
}

int s;
int getintval() {

	return s;
}

//void assert(){
//
//	cout << "assert function" << endl;
//}

void print(const int ia[], size_t size) {
#ifndef NOEBUG
	//
	cerr << __func__ << "：array size is" << size << endl;
#endif
}

void f() {
	cout << "f()" << endl;
}
void f(int) {
	cout << "f(int)" << endl;
}
void f(int, int) {
	cout << "f(int,int)" << endl;
}
void f(double, double = 3.14) {
	cout << "f(double,double)" << endl;
}

int main() {
	int g;

	constexpr int foo = new_sz();//在编译时验证new_sz函数返回的是常量表达式，就是展开内联了 2.
	int i1 = getintval();
	//constexpr int foo2 = new_sz2(i1);// 不是常量值

	//4.
	int arr[scale(2)];//正确，实参是常量表达式，返回也是常量表达式
	int i2 = 2;
	scale(i);
	//int a2[scale(i)];// 不是常量

	// 二：内联与constexpr科院有多个定义，并且定义必须完全一致

	// 6.5.3调试帮组 一：assert预处理宏
	cout << "start debug()" << endl;
	assert(1 < 2);// 为真时什么也不做，
	//assert(3 < 2);// 为假时则输出信息并终止程序的执行
	cout << "end debug()" << endl;

	//不要用assert命名函数 变量没问题
	int assert = 3;
	assert(1 < 2);

	// 二：NOEBUG 预处理变量
	// 若定义了NOEBUG assert 什么也不做，但是没有用呀，这样

	//assert(3 < 2);

	// 可以用自己的调式代码
	#ifndef NOEBUG
	//__func__  编译器定义的一个局部静态变量，用于存放函数的名字。
	cerr << __func__ << "：array size is" << 3 << endl;
	#endif
	// 自己输出错误信息，并且不会终止
	#ifndef NOEBUG
	assert(1 < 2);
		cerr << "Error: " << __FILE__
			<< " : IN FUNCTION " << __func__
			<< " at line " << __LINE__ << endl
			<< "	compiled on " << __DATE__
			<< " AT " << __TIME__ << endl
			<< "	word read was \"" << 3
			<< "\":length too short" << endl;
	#endif
	cout << "end debug" << endl;
	// 6.6函数匹配

	f(2.56);// 
	// 二义性 不可
	//f(42, 2.56);
	
	// 6.6.1实参类型转换
	// 5个点

	// 二：函数匹配和const实参
	Record lookup(Account &);
	Record lookup(const Account &);
	const Account a;
	Account b;

	lookup(a);//第二个 
	lookup(b);//第一个 精确匹配不用转换的函数

	// 6.7函数指针



	cin >> g;
	return 0;

}