#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <stdio.h>
#include <time.h> 
#include "StrBlob.h"
#include "StrBloPtr.h"
#include "Sales_data.h"

using namespace std;
/*
开篇引出：
对某些类来说拷贝赋值和拷贝构造没有合理的意义，必须采用某种机制阻止

如：iostream不能拷贝

二.定义删除的函数
删除函数：虽然声明了他们，但不能以任何方式使用它们
在函数参数列表后面加上=delete指明

=delete必须出现在第一次声明地方
适合所有函数

三、析构函数不能是删除的成员
只是规定，非要定义删除的话，不允许定义该类型的变量或创建该类的临时对象
但是可以动态分配，但是delete不掉。

四、合成的拷贝控制成员可能是删除的
引出：
编译器可能会将合成的成员定义为删除的

1.若类的某个成员的析构函数是删除的或者不可访问，这个类的析构函数被定义删除
2.若类的某个成员的拷贝构造函数或者析构函数是删除的或者不可访问，这个类的拷贝构造函数被定义删除
3.若类的某个成员的拷贝赋值运算符是删除的或者不可访问，或者有一个const或引用成员，则这个类合成的拷贝赋值运算符被定义删除的
4.若类的某个成员的析构函数是删除的或者不可访问，或类有一个引用成员它没有类内初始化器，或者const成员 它没有类内初始化器且其类型未显示定义默认构造函数
则该类的默认构造函数被定义为删除的。

本质：如果类的某个成员不能构造、拷贝 复制或销毁，则对应的成员函数被定义为删除

五、private控制拷贝
新标准之前，通过将拷贝构造 赋值声明为private来阻止拷贝

友元和成员函数仍旧可以拷贝对象，可以通过声明不定义方式，来让链接时错误
尽量用delete，而不是private
*/
class A {
public:
	A() { cout << "A()" << endl; }
	void func() {
		A();
	}
};
class NoDtor {
	~NoDtor() = delete;
public:
	int a;
};
class TestCl {

public:
	const int a;
};

class Employee {

public:
	Employee();
	Employee(const string& s);
	Employee(const Employee&) = delete;
	Employee& operator=(const Employee& rhs) = delete;
	string name;
	int idcard;
	static int startincr;
};
int Employee::startincr = 1000;
Employee::Employee() 
{
	idcard = ++startincr;
}
Employee::Employee(const string& s):
	name(s), idcard(++startincr) {

}
int main() {

	int aa;
	//NoDtor n1;
	//NoDtor *n2 = new NoDtor();
	//delete n2;
	//TestCl t1;
	A a;
	a.func();

	// 练习
	Employee e1("张三");
	cout << e1.idcard << endl;
	Employee e2("李四");
	cout << e2.idcard << endl;

	// 需要，唯一的idcard不能有两个，所以需要删除拷贝赋值 拷贝构造

	/*
	TextQuery
	拷贝构造：会多一个指针引用计数指向右侧运算对象
	拷贝赋值：将左侧的引用计数减1，再赋予右侧的data，并且+1
	析构：引用计数-1，是否为0 是就释放
	QueryResult
	拷贝构造: 若引用也指向指针
	拷贝赋值：释放左侧的指向指针，指向右侧的对象
	析构：释放绑定，不删除
	*/
	// 不需要，因为判断一个类是否需要拷贝控制先看需不需要析构，智能指针是类有自己析构方法，所以不需要

	cin >> aa;
	return 0;
}