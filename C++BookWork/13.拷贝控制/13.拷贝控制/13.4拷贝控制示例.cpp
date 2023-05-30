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
#include "Folder.h"
#include "Message.h"
using namespace std;
/*
开篇引出：
分配资源的类更需要拷贝控制，但有的类也需要拷贝控制进行工作


*/

int main() {

	int aa;

	//练习
	/*
	Folder 会拷贝啊
	const Folder 修改不了啊
	*/

	/*
	拷贝构造函数:不会将右侧所在的floder集合添加左侧
	拷贝赋值：不会讲右侧所在的floder集合添加左侧，并且只是拷贝，不释放左侧所在的floder集合
	析构：不会删除floder集合中本msg对象
	*/

	string *s1 = new string("12");
	string &s2 = *s1;
	cout << &s2 << endl;

	Folder f1,f2;
	Message m1("abc"), m2("def"), m3("ghi"), m4("jkl"), m5("mon");
	m1.save(f1);
	m2.save(f1);
	m3.save(f1);
	m4.save(f2);
	m5.save(f2);
	//f1.addMsg(&m1);
	//f1.addMsg(&m2);
	//f1.addMsg(&m3);
	//f1.addMsg(&m4);
	//f1.addMsg(&m5);
	f1.debug_print();
	f2.debug_print();
	// 练习
	/*
	13.38拷贝并交换的话
	 交换循环4次，拷贝构造一次的循环1次，共5次，普通的就两次就好 自己想的，不准确 
	没有动态分配的内存
	*/


	std::cin >> aa;
	return 0;
}