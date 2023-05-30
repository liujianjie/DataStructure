#include <iostream>
#include <string>
#include <fstream>
#include "QueryResult.h"
#include "AllClass.h"

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

/*
写个总结，怕忘记：
就是继承体系，一元运算符，二元运算符，实际查询运算对象
每个运算对象都是一个Query。
一元运算符有一个Query运算对象
二元运算符有两个Query运算对象
像：~(Query("adf")),~是一元运算符，运算对象是里面的Query

Query里面有一个Query_base保存基类指针，用来保存运算。。。
Query q = Query("fiery") & Query("bird") | Query("wind");
重载运算符来控制使用哪个派生类来结合组合计算Query对象
1.
  (Query运算对象)OrQuery(Query运算对象)
2.再慢慢计算通过Query的指针Query_base 得到具体的类
  (Query运算对象 AndQuery Query运算对象)OrQuery(WordQuery)
  (WordQuery AndQuery WordQuery)OrQuery(WordQuery)
  (WordQuery AndQuery WordQuery)OrQuery (QueryResult)
  (QueryResult)OrQuery (QueryResult)
  QueryResult
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
	//BinaryQuery b1 = Query("a") | Query("b");
	//AndQuery b1 = Query("a") & Query("b");
	//OrQuery b1 = Query("a") | Query("b");

	ifstream ifs("15.9输入文件.txt");
	TexTQuery te(ifs);
	
	Query q = Query("fiery") & Query("bird") | Query("wind");
	//cout << q << endl;
	//print(cout, q.eval(te));
	cout << "------" << endl;
	Query q2 = ~Query("Alice");
	
	//print(cout, q2.eval(te));

	Query q3 = Query("Daddy");
	//print(cout, q3.eval(te));

	Query q4 = Query("hair")|Query("Alice");
	print(cout, q4.eval(te));
	// 练习
	/*
	Query q = Query("fiery") & Query("bird") | Query("wind");
	15.34：
	(a).先OrQuery | left：为AndQuery &
							left： Query(string)构造函数 WordQuery(s)   3
							right： Query(string)构造函数 WordQuery(s)   2
							BinaryQuery构造函数   4
							AndQuery构造函数   5
					right:为Query(string)构造函数 WordQuery(s)   1
					BinaryQuery构造函数  6
					OrQuery构造函数  7
	(b).同a的很像
		|的BinaryQuery的rep，|left&的BinaryQuery的rep，&leftWordQuer的，&rightWordQuery的，|rightWordQuery的
	(c).也是差不多吧 q.eval()
	就是先|的Query展开,因为binaryQuery没有eval所以省略了
			     rhs.eval调用word真正的查询返回QueryResult
	|Query eval:
							rhs.eval
				&Query eval:
							lfs.eval
				

	15.35:ok
	15.36:ok
	15.37:实例化的方式不一样，赋值方式也不一样，就是会改动很多吧。感觉很困难需要~(new WordQuery(".."))不知道，不会写
	15.38：ok

	15.39:ok
	15.40:ok
	15.41:需要手动delete对象
	15.42：

	(a)：这一小问感觉有点问题，描述不清楚。个人理解：将文件读入之后，每行保存在一个vector<string>中，根据输入单词，每行查询，输出对应单词

	(b)：重新定义一个类，将每次的查询结果用一个map<int,map>保存起来就好了，int为编号，map为查询结果

	(c)：指定文本范围，根据输入限制一下vector<string> 的内容即可
	---------------------
	作者：MISAYAONE
	来源：CSDN
	原文：https://blog.csdn.net/misayaaaaa/article/details/61925162
	版权声明：本文为博主原创文章，转载请附上博文链接！

	*/
	cin >> a;
	return 0;
}
