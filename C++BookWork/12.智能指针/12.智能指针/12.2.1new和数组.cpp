#include <iostream>
#include <vector>
#include <memory>
#include <list>
#include "Sales_data.h"
#include "StrBlob.h"
#include "StrBloPtr.h"
#include <sstream>
#include <string>
#include <fstream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;
/*
分配一个数组会得到一个元素类型的指针
1.叫 动态数组，并不是真的是数组类型

p只是指向一个对象数组的首元素

// 智能指针和动态数组
// 1.可以管理new分配的数组的unique_ptr版本
unique_ptr<int[]> up1(new int[10]);
//up1.release();// 会自动使用delete[]

// 并且可以用下标访问数组中的元素

shared_ptr
1.不直接支持管理动态数组，若想需要自定义删除器
2.不提供下标访问数组的元素，需用get先获取内置指针再操作
*/
char* lian1(const char *c1, const char *c2)
{
	
	// 用strcpy 与strcat才是标准答案
	int sizes1 = strlen(c1);
	int sizes2 = strlen(c2);;
	char *cptr1 = new char[sizes1 + sizes2 + 1];
	strcpy(cptr1, c1);
	strcat(cptr1, c2);
	cout << sizes1 << endl;
	cout << sizes2 << endl;
	//for (size_t i = 0; i != sizes1; ++i) {
	//	cptr1[i] = c1[i];
	//}
	//for (size_t i = 0; i != sizes2; ++i) {
	//	cptr1[sizes1 + i] = c2[i];
	//}
	//cout << *cptr1 << endl;
	return cptr1;
}
char* lian1load(string c1, string c2)
{
	int sizes1 = c1.length();
	int sizes2 = c2.length();
	char *cptr1 = new char[sizes1 + sizes2 + 1];
	strcpy(cptr1, (c1+c2).c_str());
	/*for (size_t i = 0; i != sizes1; ++i) {
		cptr1[i] = c1[i];
	}
	for (size_t i = 0; i != sizes2; ++i) {
		cptr1[sizes1 + i] = c2[i];
	}*/
	//cout << sizes1 << endl;
	//cout << sizes2 << endl;
	return cptr1;
}
int main()
{
	int a;
	int *pia1 = new int[4];// pia1指向第一个int，需要是整形大小，不一定要常量

	typedef int arrT[42];
	int *pia2 = new arrT;//new分配一个int数组，并且返回指向第一个int的指针

	// 初始化动态分配对象的数组，new分配的对象，可以默认初始化，值初始化
	int *pia3 = new int[10];
	int *pia4 = new int[10]();
		
	// 可以初始化列表
	int *pia5 = new int[10]{ 0,1,2,3,4,5,6 };
	// 初始化可以混合，前4个初始化器初始，剩下的值初始化
	string *pia6 = new string[10]{ "a","an","the",string(3,'x') };
	cout << *pia6 << endl;
	string *pia7 = pia6;
	// 不可大于声明大小

	//动态分配一个空数组是合法的并且可以使用下标为0的元素，但不能解引用
	//char arr[0];// 不能定义长度为0的数组
	char *cp1 = new char[0];//但可以一个动态分配一个空数组
	// 就像尾后指针一样，可以进行比较操作，可加减0；

	// 释放动态数组
	//delete pia6;//错误的 未定义的 报错，猜想：只删除第一个元素吧？ 或者销毁第一个元素并且不指向数组了所以会访问不到，但是数组依然存在除了第一个位置的

	//cout << pia7[3] << endl;
	//cout << pia4[0] << endl;
	// pia4只是指向一个对象数组的首元素
	delete []pia5;

	// 智能指针和动态数组
	// 1.可以管理new分配的数组的unique_ptr版本
	unique_ptr<int[]> up1(new int[10]);
	//up1.release();// 会自动使用delete[]

	// 并且可以用下标访问数组中的元素
	for (size_t i = 0; i != 10; ++i) {
		up1[i] = i;
	}

	shared_ptr<int> sp1(new int[10], [](int *p) {delete[] p; });
	for (size_t i = 0; i != 10; ++i) {
		*(sp1.get() + i) = i;
	}
	cout << "--------------" << endl;
	// 练习 不知道怎么弄。
	char *cp2 = lian1("12345678","1234567asdfazzz");
	//for (int i = 0; i != strlen(cp2)-2; ++i) {
	//	cout << cp2[i];
	//}
	cout << cp2 << endl;
	char *cp3 = lian1load("zvzxzx", "sadfasdfzzzzzzxcvxc");
	cout << cp3 << endl;
	//for (int i = 0; i != strlen(cp3); ++i) {
	//	cout << cp3[i];
	//}
	//cout << endl;
	delete[] cp2;
	delete[] cp3;

	char c1;
	int i = 0;
	char *cp4 = new char[10];
	//while (cin.get(c1)) {
	//	if (i < 10) {
	//		cp4[i] = c1;
	//	}
	//	else {
	//		cerr << "out range" << endl;
	//		break;
	//	}
	//	i++;
	//}
	//cp4[i] = 0;// 这是干啥的？
	//cout << cp4 << endl;

	delete[]cp4;

	int *pa = new int[10];
	 delete []pa;

	cin >> a;
	return 0;
}
