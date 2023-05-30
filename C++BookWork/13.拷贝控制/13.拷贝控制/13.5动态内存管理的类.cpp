#include <iostream>
#include <vector>
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
#include "TexTQuery.h"
#include "QueryResult.h"
using namespace std;
/*
开篇引出：
某些类需要在运行时分配可变大小的内存空间，可以通过标准库容器来实现，但是可以自己进行内存管理，自己定义拷贝控制成员来管理

例子：
只管理string

实现：用allocator类来管理。

重要：
重新分配内存的过程中移动而不是拷贝元素
拷贝这些string是多余的

移动构造函数和std::move：
两种机制 
string都定义了移动构造函数，移动后仍保持有效的 可析构的状态
move标准库函数 utility头文件中
用move来表示希望使用string的移动构造函数，如果没用move就会用string的拷贝构造函数。
通常不为move提供一个using声明，而是直接调用std：：move


*/
ostream &print(ostream& os, const QueryResult &qr)
{
	os << qr.sougth << " occurs " << qr.lines->size() << " "
		" times " << endl;
	for (auto num : *qr.lines) {
		os << "\t(line " << num + 1 << ")"
			<< *(qr.file->begin() + num) << endl;
	}
	return os;
}

void func(StrVec sv)
{

}
int main() {

	int aa;
	//string *st1 = new string("1");
	//cout << st1 << endl;
	//cout << *st1 << endl;
	StrVec sv1;
	sv1.push_back("121");
	cout << *sv1.begin() << endl;
	func(sv1);
	//cout << "----------------" << endl;
	//ifstream ifs("12.3.1文本查询程序设计.txt");
	//TexTQuery tq(ifs);
	//string words;
	//while (cin >> words && words != "q") {
	//	print(cout, tq.query(words)) << endl;
	//}

	// 练习：
	// 13.39
	// 13.40 
	// 13.41:会 错误吧，当指向最后一个，那么下一个是不存在的位置 会错
	// 13.42
	std::cin >> aa;
	return 0;
}