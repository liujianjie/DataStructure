#include <iostream>
#include "String.h"
#include "Sales_data.h"
#include "StrVec.h"
#include "StrBlob.h"
#include "StrBloPtr.h"
#include "Employee.h"
#include <memory>
using namespace std;

/*
开篇：
定义了相等运算符的类通常也包含关系运算符，关联容器更需要小于运算符

关系运算符应该：
1.定义顺序关系，与关联容器中对关键字的要求一致
2.如果类同时也含有==运算符，定义一种关系令其余==保持一致。如果两个对象是！=的，那么一个对象应该<另外一个

Sales_data不应该定义<，不存在逻辑可靠的<定义，不定义<也许更好

因为比较isbn而后面两个成员不符合要求2
若定义isbn比较
编写了：isbn相同，但后面两个成员不同是不相等的，判定相等
实际情况中: 其中任何一个都不比另一个小则两个对象不相等

若排序比较也不行，因为实际需求会改变顺序

note：需要存在唯一一种可靠的<定义



*/
int main()
{
	int a;
	string s1("aa");
	string s2("aaa");
	cout << (s1 < s2) << endl;

	cout << "StrVec:" << endl;
	StrVec sv1, sv2;
	sv1.push_back("a");
	sv1.push_back("a");
	sv1.push_back("a");
	sv1.push_back("a");

	sv2.push_back("a");
	sv2.push_back("a");
	sv2.push_back("b");

	cout << (sv1 < sv2) << endl;
	cout << "StrVec:" << endl;

	String str1("a"), str2("aaa");
	cout << (str1 < str2) << endl;

	cout << endl;
	StrBlob sbb1, sbb2;
	sbb1.push_back("a");
	sbb1.push_back("a");
	sbb1.push_back("a");
	sbb1.push_back("a");
	//sbb1.push_back("a");

	sbb2.push_back("a");
	sbb2.push_back("a");
	sbb2.push_back("a");
	sbb2.push_back("b");
	cout << (sbb1 < sbb2) << endl;


	StrBloPtr sbp1(sbb1), sbp2(sbb2);
	cout << (sbp1 < sbp2) << endl;


	// 练习
	/*
	14.18 StrBlobPtr 不知道是不是这样 
	14.19 无法比，因为是 对象 不满足准则2
	*/
	cin >> a;
	return 0;
}