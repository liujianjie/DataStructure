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
/*
开篇引出：
1.新的引用类型-右值引用，必须绑定到右值得引用
2.用&&，只能绑定到一个将要销毁的对象
3.左值和右值是表达式的属性，一个左值表示的是一个对象的身份，一个右值表示对象的值
4.右值引用也是某个对象的另一个名字而已
5.绑定到要求转换的表达式、字面常量、返回右值得表达式

二、左值持久；右值短暂
右值只能绑定到临时对象
1.所引用的对象将要被销毁
2.该对象没有其它用户

右值引用的代码可以自由的接管所引用的对象的资源

三、变量是左值
变量表达式都是左值，一个右值引用是左值，所以不能讲一个右值引用绑定到一个右值引用类型的变量上

四、标准库move函数
utility头文件中
move显式的将一个左值转换为对象的右值引用类型。
用move承诺：除了对移后源对象赋值或销毁它外，不再使用它，不能对值做任何假设使用，但是却可以?c+14?

void fun(int &&ci) {
cout << " fun(int &&ci)" << endl;

}
void fun(int ci) {
cout << " fun(int ci)" << endl;

}
int it = 12;
const int &ci1 = std::move(it);
int &&ci2 = std::move(it);
int ci3 = std::move(it);// 可以用一个左值接收右值引用！
// ci2 与ci3对于移动 是同等的 会冲突
fun(it);
//fun(std::move(it));
*/
int f();
int f() 
{
	return 23;
}
int main() {

	int aa;
	
	int i = 42;
	int &r1 = i;
	//int &&rr1 = i;
	//int &r2 = i * 42;
	const int &r3 = i * 42;// 这个可以
	int &&rr2 = i * 42;

	// 二、左值持久；右值短暂

	// 三
	int &&rr3 = 42;
	//int &&rr4 = rr3;

	// 四
	int &&rr4 = std::move(rr3);
	rr3 = 41;
	rr4 = 40;
	cout << rr3 << endl;
	cout << rr4 << endl;

	int f();
	vector<int> vi(100);

	int &&r5 = f();
	int &r6 = vi[0];
	int &r7 = r5;
	int &&r8 = vi[0] * f();

	cout << "拷贝初始化时调用的拷贝构造函数" << endl;
	String s1("you and me,sdfasdf,adf");
	String s2 = s1,s3 = s2;
	//cout << s1.c_str() << endl;
	//cout << s1.c_str2() << endl;

	// 练习
	/*
	右值引用能绑定到要求转换的表达式、字面常量、返回右值得表达式
	左值引用不能

	右值短暂，表示表达式的身份
	左值持久，表示表达式的值
	*/
	cout << "------------" << endl;
	cout << "当vector不够内存时将执行vector的分配内存并且拷贝每一个元素，调用String的拷贝构造函数" << endl;
	vector<String> ve;
	ve.push_back(s1);
	ve.push_back(s2);
	//ve.push_back(s3);
	//ve.push_back((String)"ab");
	//ve.push_back((String)"cd");
	//ve.push_back((String)"ef");
	//ve.push_back((String)"gh");

	/*
		因为会重新分配内存，将旧空间的元素拷贝到新空间中 所以会发生很多次
	*/
	std::cin >> aa;
	return 0;
}