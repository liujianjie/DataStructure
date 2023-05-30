#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <iterator>
#include <list>
#include <functional>
#include <iterator>
#include <fstream>
#include <forward_list>
#include "Sales_item.h"
#include "Sales_data.h"
using namespace std;
using namespace std::placeholders;// 占位符空间


void prints(vector<int> con)
{
	for_each(con.begin(), con.end(),
		[](const int &s) {cout << s << " "; });
	cout << endl;
}
void prints(vector<string> con)
{
	for_each(con.begin(), con.end(),
		[](const string &s) {cout << s << " "; });
	cout << endl;
}
void prints(list<int> con)
{
	for_each(con.begin(), con.end(),
		[](const int &s) {cout << s << " "; });
	cout << endl;
}
void prints(forward_list<int> con)
{
	for_each(con.begin(), con.end(),
		[](const int &s) {cout << s << " "; });
	cout << endl;
}
bool pred1(int &vl)
{
	return vl == 5;
}
/*


unique() 并没有删除掉

特有算法与通用算法区别是
特有算法会改变底层容器，merge，remove unique

list forward_list优先使用特有算法
*/
int main()
{

	int a;
	forward_list<int> li1{1,2,3};
	forward_list<int> li2{4,5,6};
	li1.merge(li2);// li2的元素会删除
	li1.merge(li2);// li2的元素会删除
	prints(li1);
	prints(li2);
	forward_list<int> li3{ 4,5,6 };
	forward_list<int> li4{ 1,2,3,4,5,6 };
	li3.remove(4);
	prints(li3);
	li4.remove_if([](int &i) { return i % 2; });
	prints(li4);

	forward_list<int> li5{ 1,2,3,4,5,6 };
	li5.reverse();
	prints(li5);

	forward_list<int> li6{ 3,4,5,6,1,2 };
	li6.sort();
	prints(li6);

	forward_list<int> li7{ 3,4,5,6,1,2,1,1,2,2,3,4,4,4,5,6,7 };
	li7.unique();
	prints(li7);// 没有删除掉。。

	forward_list<int> li8{ 3,4,5,6,1,2,1,1,2,2,3,4,4,4,5,6,7 };
	li8.unique([](const int& v1, const int &v2) {return v1 == v2; });
	prints(li8);

	//二 splice
	list<int> li_1{ 1,2,3,4,5,6 };
	list<int> li_2{ 7,8,9 };

	forward_list<int> forli_9{ 1,2,3,4,5,6 };
	forward_list<int> forli_10{ 1,2,3,4,5,6 };
	
	li_1.splice(li_1.begin(), li_2);// 之前的位置
	auto it10 = ++forli_9.begin();
	forli_9.splice_after(it10, forli_10);//之后的位置
	prints(li_1);
	prints(li_2);

	prints(forli_9);
	prints(forli_10);

	// 可以是相同的链表
	list<int> li_3{ 1,2,3,4,5,6 };
	list<int> li_4{ 7,8,9 };

	forward_list<int> forli_11{ 1,2,3,4,5,6 };
	forward_list<int> forli_12{ 1,2,3,4,5,6 };

	li_3.splice(li_3.begin(), li_4, ++li_4.begin());// 一个元素吗
	auto it11 = ++forli_12.begin();
	forli_11.splice_after(forli_11.begin(), forli_12,it11);// 一个it11之后的元素
	prints(li_3);
	prints(li_4);

	prints(forli_11);
	prints(forli_12);

	// 可以是相同的链表，但是p不能指向b e的范围元素
	list<int> li_5{ 1,2,3,4,5,6 };
	list<int> li_6{ 7,8,9 };

	forward_list<int> forli_13{ 1,2,3,4,5,6 };
	forward_list<int> forli_14{ 1,2,3,4,5,6 };

	li_5.splice(li_5.begin(), li_6, ++li_6.begin(),li_6.end());// 一个范围
	forli_13.splice_after(forli_13.begin(), forli_14, ++++forli_14.begin(), forli_14.end());// 一个范围
	prints(li_5);
	prints(li_6);

	prints(forli_13);
	prints(forli_14);

	// 练习 
	list<string> li_par{ "the","quick", "red", "fox", "jumps", "over", "the", "slow", "red" ,"turtle" };
	// 先排序
	li_par.sort();
	// 再删除就完事
	li_par.unique([](const string& s1, const string& s2) {return s1.size() == s2.size(); });
	for_each(li_par.begin(), li_par.end(),
		[](const string &s) {cout << s << " "; });
	cout << endl;

	cin >> a;
	return 0;
}

