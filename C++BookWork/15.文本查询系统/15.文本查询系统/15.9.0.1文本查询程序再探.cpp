#include <iostream>
#include <vector>
#include <memory>
#include <regex>

using namespace std;
/*
我们应该将几种不同的查询建模成相互独立的类，这些类共享一个公共基类：
WordQuery //Daddy 单词查询
NoteQuery// ~Alice 逻辑非
OrQuery// hair | Alice 逻辑或
AndQuery // hair & Alice 逻辑与

只包含两个操作：
eval,接受一个TextQuery对象并返回一个QueryResult，eval函数使用给定的TextQuery对象查找与之匹配的行
rep,返回基础查询的string表示形式，eval函数使用rep创建一个表示匹配结果的QueryResult，输出运算符使用rep打印查询表达式

1.抽象基类
1) 抽象基类来表示接口，Query_base,eval rep定义纯虚函数
2）wordquery,notequery直接从query_base派生，AndQuery OrQuery需要一个BinaryQuery类来有两个运算对象，但也要基础Query_base

2.将层次关系隐藏在接口类中
1) 定义一个接口类Query负责隐藏整个继承体系。有一个Query_base指针，绑定到派生类对象
2）有eval，rep 有重载输出运算符
3）重载3个运算符，一个接受string的构造函数，这些函数动态分配一个新的Query_base派生类对象
(1) &运算符生成一个绑定到新的AndQuery对象上的Query对象
(2) |运算符生成一个绑定到新的OrQuery对象上的Query对象
(3) ~。。。。。。。。。。。。NotQuery。。。。。。。
(4) string构造函数。。。。。WordQuery对象

Query q = Query("fiery") & Query("bird") | Query("wind");

就是用query代表运算对象。

3.理解这些类的工作机理

*/
using namespace regex_constants;
int main()
{
	int a;
	// 练习
	/*
	15.31： ok
	   s1
a,b	|:
	      s2
	   &
	      ~ s3

		  s3
		&
		  s4
c   |
		  s2
		&
		  s1

	*/
	cin >> a;
	return 0;
}
