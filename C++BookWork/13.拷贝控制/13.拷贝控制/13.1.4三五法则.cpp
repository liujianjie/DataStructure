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
1.拷贝构造函数，拷贝赋值运算符，析构函数通常看成一个整体还有两个

需要析构函数的类也需要拷贝和赋值操作
结论：是否决定要拷贝控制成员，由是否需要一个析构函数决定，如果需要一个析构，则也明显要拷贝构造和赋值运算符
2.因为若类中有一个动态资源，需要显示delete，但如果默认的控制操作，会将地址传给新的对象，那么执行两个对象的析构会删除两次那个地址内存，那么就是不可取的

需要拷贝操作的类也需要赋值操作，反之亦然
1.某些类的所要完成的工作，只需要拷贝或赋值操作，不需要析构函数
结论：那么拷贝或赋值就绑定在一起，若一个类需要一个拷贝构造函数，那么也要拷贝赋值运算符
相反，若要赋值肯定要拷贝，但不一定要析构

1.如果需要一个析构，则也明显要拷贝构造和赋值运算符
2.若一个类需要一个拷贝构造函数，那么也要拷贝赋值运算符
相反，若要赋值肯定要拷贝，但不一定要析构
*/
class number {
public:
	number() :mysn(rand()) {}
	// 拷贝构造
	number(const number& rhs) :mysn(rand()) {

	}
public:
	int mysn;
};
void f(number s)
{
	cout << s.mysn << endl;
}
// 不会变
//void f(const number& s)
//{
//	cout << s.mysn << endl;
//}
int main() {

	int aa;
	srand((unsigned)time(NULL));

	number a, b = a, c = b;
	cout << a.mysn << endl;
	cout << b.mysn << endl;
	cout << c.mysn << endl;
	f(a);
	f(b);
	f(c);
	// 6个不同的数
	// 但是只有3个了 const &
	cin >> aa;
	return 0;
}