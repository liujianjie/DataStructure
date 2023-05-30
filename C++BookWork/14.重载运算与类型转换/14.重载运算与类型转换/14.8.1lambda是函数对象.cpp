#include <iostream>
#include "String.h"
#include "Sales_data.h"
#include "StrVec.h"
#include "StrBlob.h"
#include "StrBloPtr.h"
#include "Employee.h"
#include <memory>
#include "NewClass1432.h"
using namespace std;


class st_sort {
public:
	bool operator()(const string& s1, const string& s2)
	{
		return s1.size() < s2.size();
	}
};
class fd_if {
public:
	fd_if(vector<string>::size_type t):sz(t){}
	bool operator()(const string& s1)
	{
		return s1.size() >= sz;
	}
private:
	vector<string>::size_type sz;
};
void elimDups(vector<string> &words)
{
	// 因为算法是对迭代器而不是容器操作，所以算法不能直接添加或删除元素
	// 按字典序排序words
	sort(words.begin(), words.end());
	// 消除重复的
	auto thewei = unique(words.begin(), words.end());
	// 真正删除
	words.erase(thewei, words.end());
}
void biggieslambda(vector<string> &words, vector<string>::size_type sz) {
	elimDups(words);
	stable_sort(words.begin(), words.end(), 
		st_sort());
	auto firstit = find_if(words.begin(), words.end(),
		fd_if(sz));
	for (auto beg = firstit; beg != words.end(); ++beg) {
		cout << (*beg) << " ";
	}
	cout << endl;
	// for - each
	for_each(firstit, words.end(),
		[](const string &s) {cout << s << " "; });
	cout << endl;
}
/*
引出：
lambda是函数对象，编译器将lambda表达式翻译成一个未命名类的未命名对象。具有一个重载的函数调用运算符
1.因为不能改变捕获的变量，所以函数调用运算符是一个const成员函数

二、表达式lambda以及相应捕获行为的类
可以捕获引用的成员并且使用

值捕获的变量被拷贝到lambda中，所以产生的类必须为每个值捕获的变量建立对应的数据成员，同时创建构造函数初始化

lambda表达式产生的类不含默认构造函数、赋值运算符及默认析构函数，它是否函数默认的拷贝、移动构造函数通常要视
捕获的数据成员类型而定

*/
class Par1 {
public:
	Par1():countve(11){}
	void operator()(const string &s1)
	{
		if (s1.length() > 10) {
			return;
		}
		++countve[s1.length()];
	}
	vector<int> countve;
};
class Par2 {
public:
	Par2() :countve(2) {}
	void operator()(const string &s1)
	{
		if (s1.length() >= 10) {
			++countve[1];
		}
		else if (s1.length() < 10) {
			++countve[0];
		}
	}
	vector<int> countve;
};
int main()
{
	string st1("asdfasdf");
	cout << st1.size() << endl;
	cout << st1.length() << endl;
	int a;
	//vector<int> ve1(10);
	//cout << ve1.size() << endl;
	Par1 p1;
	vector<string> ve2{ "123","123" ,"12asdf3" ,"12df3" ,"d123" ,"1sd23" ,"12asdfasdf3" ,"1sdfa23" ,"1sdfsd23" };
	for(auto s : ve2) {
		p1(s);
	}
	int i = 0;
	for (auto s : p1.countve) {
		cout << "单词数 = " << i << "的数目有:" << s << endl;
		i++;
	}
	Par2 p2;
	vector<string> ve3{ "123","123adsfadsfadfa" ,"12asdfsfsd3" ,"12df3" ,"d123" ,"1sd23" ,"12asdfasdf3" ,"1sdfa23" ,"1sdfsd23" };
	for (auto s : ve3) {
		p2(s);
	}
	i = 0;
	for (auto s : p2.countve) {
		cout << "单词数 = " << i << "的数目有:" << s << endl;
		i++;
	}

	vector<string> v1{ "the","quick", "red", "fox", "jumps", "over", "the", "slow", "red" ,"turtle" };
	biggieslambda(v1, 5);

	// 练习
	/*
	14.38 ok
	14.39 ok
	14.40 ok
	14.41:因为为了隐式，缩小代码吧，lambda精简时 只使用一次，使用类使用多次定义出来，并且可以定义多个一组不同参数的调用对象
	*/

	cin >> a;
	return 0;
}