#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <memory>
#include <stdio.h>
#include <time.h> 
#include <fstream>
#include <algorithm>
#include "StrBlob.h"
#include "StrBloPtr.h"
#include "Sales_data.h"
#include "HasPtr.h"
#include "Foo.h"
#include "Folder.h"
#include "Message.h"
#include "String.h"
#include "TexTQuery.h"
#include "QueryResult.h"
#include "StrVec136.h"
#include "Foo136.h"
/*
开篇引出：
可以为成员函数提供拷贝和移动版本，能从中受益。
一个是const左值引用 const X&
一个是指向非const的右值引用  X&&

一般来说不需要定义相对的X&和const X&&
const X&&:我们希望从实参“窃取”数据，通常是右值引用，不是const右值引用
X&：     从一个对象进行拷贝的操作通常不改变该对象


二、右值和左值引用成员函数
右值和左值 对象都可以调用成员函数

不希望右值调用或者被赋值，我们可以阻止，强制左侧运算对象（this指向的对象）是一个左值

定义方式：在参数列表后放置一个引用限定符
如 只允许可修改的左值赋值需要在拷贝赋值运算符 添加& 限定

自己发现：
若都对成员函数没有限定符，则this可以表示左值或右值都可以，即可以为左值或右值赋值
若只对左值限定（拷贝赋值运算符），则只能对左值赋值，右值不可以
若只对右值限定 则相反
若对左值和右值都限定则都可以

一个函数可以同时用const和引用限定，引用限定跟随在const限定符之后

三、重载和引用函数
可以通过与const的结合重载

Foo136 someMem() const &;// 可用于任何类型的Foo但还是const的精确匹配 就是左值，& ，const &&都会转换为这个吧,是的，所以只要写一个就可

const && 不能修改

2.重载引用限定符，必须同时拥有限定符或者不拥有
*/
Foo136 retFoo()
{
	Foo136 f;
	return f;
}
Foo136 retVal()
{
	Foo136 f;
	f.data.push_back(2);
	f.data.push_back(3);
	f.data.push_back(1);
	return f;
}
void for_eachs(vector<int> &ve)
{
	for(auto a : ve)
	{
		cout << a << endl;
	} 
}
int main() {

	int aa;
	StrVec136 sv1,sv2;
	string s = "some";
	sv1.push_back(s);
	sv2.push_back("sv1");

	// 二
	string s1 = "a vaue", s2 = "anoth";
	auto n = (s1 + s2).find('a');
	cout << n << endl;
	cout << (s1 + s2 = "wow!") << endl;// 对一个右值进行了赋值

	cout << "---------" << endl;
	//Foo136 &retFoo();
	Foo136 f13;
	Foo136 &ret = f13;// 左值
	Foo136 retVal();// 右值
	Foo136 i, j;// 左值
	i = j; // 正确 左值可以给左值
	//retVal() = j;// 错误，右值可以赋值的 但是因为显式定义了左值赋值 让右值赋值给定义为删除的了吧
	ret = j;
	i = retVal();

	cout << "---------" << endl;
	// 三、重载和引用函数

	Foo136 fo1,fo2;
	Foo136 &ret2 = fo1;// 左值
	Foo136 &&rightfo = retVal();// retVal()右值 给rightfo是左值
	ret2.data.push_back(7);
	ret2.data.push_back(9);
	ret2.data.push_back(8);

	std::move(rightfo).someMem();
	for_eachs(ret2.someMem().data);
	for_eachs(rightfo.data);

	cout << "--------" << endl;
	Foo136 &leftfo3 = fo2;
	const Foo136 &leftfo2 = fo1;
	Foo136 &&rightfo1 = retVal();
	const Foo136 &&rightfo2 = retVal();

	leftfo3.someMem();
	leftfo2.someMem();
	std::move(rightfo1).someMem();
	std::move(rightfo2).someMem();

	// 练习
	// 13.56栈溢出
	Foo136 fo5;
	fo5.sorted();
	// 13.57 会调用右值，因为Foo136(*this)得到右值，将要销毁的对象为右值
	Foo136 fo6;
	fo6.sorted();


	std::cin >> aa;
	return 0;
}