#include <iostream>
#include "Query.h"

using namespace std;
/*
派生类
1.最有趣的部分是实现真实的查询功能
2.除了WordQuery类其它类都有一个或两个运算对象可以是任意派生类
3.运算对象必须以query_base指针的形式存储，但是实际上是用Query对象接口来简化

2.WordQuery类
1.没有public成员，Query需为友元
2.eval调用TextQuery执行实际的查找

3.NoteQuery类及~运算符
1.要把~运算符设定为友元。
2.在输出的结果加上括号，知道查询的优先级
3.rep是调用Query的rep再执行最终的派生类的rep
4.return std::shared_ptr<Query_base>(new NotQuery(operand));隐式的使用接受shader...的构造函数

4.BinaryQuery类
1.两个运算对象，一个运算符的名字
2.没有eval也是抽象虚类

5.AndQuery类、Orquery类及相应的运算符
1.这两个类差不多，继承了父类的rep方法，有自己的eval
2.运算符也是调用sharder_的构造函数
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
int main()
{
	int a;
	Query q = Query("fiery") & Query("bird") | Query("wind");
	cout << q;

	// 练习
	/*
	Query q = Query("fiery") & Query("bird") | Query("wind");
	15.34：
	(a).先OrQuery | left：为AndQuery &
							left： Query(string)构造函数 WordQuery(s)
							right： Query(string)构造函数 WordQuery(s)
							BinaryQuery构造函数
							AndQuery构造函数
					right:为Query(string)构造函数 WordQuery(s)
					BinaryQuery构造函数
					OrQuery构造函数
	(b).|的BinaryQuery的rep，&的BinaryQuery的rep，WordQuer的，WordQuery的，WordQuery的
	(c).emmm

	15.35:
	15.36:
	15.37:实例化的方式不一样，赋值方式也不一样
	15.38：

	*/
	cin >> a;
	return 0;
}
