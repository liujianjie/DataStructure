#include <iostream>
#include <vector>
#include <fstream>
#include "cplusplus_primer.h"
#include "cplusplus_primer_cpp.h"
#include "TestHeadAndUsing.h"
using namespace std;


namespace A {
	int i = 9, j = 8;
}
void f() {
	using namespace A;// 提升到最近的作用域中
	cout << i*A::j << endl;
}
namespace blip {
	int i = 16,j = 15, k = 23;
}
int j = 0;
void mainp() {
	using namespace blip;
	++i;
	//++j;// 不明确
	++::j;
	++blip::j;
	int k = 823;
	++k;
}

namespace Exercise {
	int ivar = 0;
	double dvar = 0;
	const int limit = 1000;
}
int ivar = 0;
//using Exercise::dvar;
//using Exercise::ivar;
//using Exercise::limit;
//using namespace Exercise;
void manip() {
	//using Exercise::dvar;
	//using Exercise::ivar;
	//using Exercise::limit;
	using namespace Exercise;
	double dvar = 3.1416;
	cout << dvar << endl;
	int iobj = limit + 1;
	//++ivar;
	++::ivar;
}
int main()
{
	int a;
	namespace cpl = cplusplus_primer;
	cout << cpl::outmember << endl;

	namespace cp2 = cplusplus_primer::QueryLib;
	cout << cp2::QueryLibmem << endl;

	// 
	f();
	//cout << v1 << endl;
	TestHeadAndUsing t1;
	t1.TestOutMsg();

	manip();
	/*
	练习：
	18.15:
	作用域不同
	声明是单个
	指示是所有
	18.16：
	声明
	位置1.
	ivar重定义吧,必须去掉一个
	iobj = 1001
	ivar 
	ivar为没有去掉的那个
	位置2
	ivar被内层隐藏
	iobj 
	dvar定义多次
	++::ivar使用全局的

	位置1.
	ivar没有重定义
	iobj = 1001
	ivar 不明确
	ivar是全局的不是命名空间的
	位置2
	ivar没有重定义
	dvar没有重定义，因为指示作用域提升了
	iobj = 1001
	++ivar; 不明确
	++::ivar使用全局的

	*/
	cin >> a;
	return 0;
}
