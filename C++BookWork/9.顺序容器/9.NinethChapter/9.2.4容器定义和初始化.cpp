#include <iostream>
#include <list>
#include <deque>
#include <vector>
#include <forward_list>
#include <array>
#include "Sales_data.h"
#include "noDefault.h"
#include <string>
using namespace std;

void print_vec(vector<int>::iterator &beg, vector<int>::iterator &end)
{
	for (;beg != end;++beg) 
	{
		cout << *beg;
	}
	cout << endl;
}
int main()
{
	int a;
	list<string> authors = { "Milton", "Shakespeare","Austen" };
	vector<const char*> articles = { "a", "an","the" };

	list<string> list2(authors);
	//deque<string> authList(authors); // 容器类型不匹配
	//vector<string> words(articles);// 元素类型不匹配
	forward_list<string> words(articles.begin(), articles.end());

	auto it = articles.end();
	deque<string> authListde(articles.begin(), it );// it 不能小于articles.begin();!!不然异常

	// 二 列表初始化
	// 三 与顺序容器大小相关的构造函数
	vector<int> ivec(10, -1); // 10个int元素 初始化为-1
	list<string> svec(10, "hi");
	forward_list<int> ivec2(10);
	deque<string> svecde(10); 
	// 注意上面的一个大小的参数的方法，若元素类型 没有默认构造函数，必须提供一个显示的元素的初始值

	// 标准库array具有固定大小
	array<int, 42> arra1;
	array<string, 10> arra2;
	//array<double> arra3;// 必须同时指定元素类型和大小
	
	array<int, 10> ia1;
	array<int, 10> ia2 = { 0,1,2,3,4,5,6 };
	array<int, 10> ia3 = { 42 };//ia3[0] = 42,其它为0

	// 不同内置数组类型可以进行拷贝或对象赋值操作
	int digs[10] = { 0,1,2,3 };
	//int cpy[10] = digs;// error
	array<int, 10> digits = {0,1,2,3};
	array<int, 10> copy = digits;
	// array<int, 5> copy2 = copy;// 大小不同不行

	// 练习9.11
	vector<int> lc1;
	vector<int> lc2(lc1);
	vector<int> lc3{2,3,4,5,6};
	vector<int> lc4(lc3.begin(), lc3.end());
	vector<int> lc5(3);
	vector<int> lc6(3, 5);
	
	print_vec(lc1.begin(), lc1.end());
	print_vec(lc2.begin(), lc2.end());
	print_vec(lc3.begin(), lc3.end());
	print_vec(lc4.begin(), lc4.end());
	print_vec(lc5.begin(), lc5.end());
	print_vec(lc6.begin(),lc6.end());

	// 练习9.13
	list<int> pli1;
	vector<double> pve1(pli1.begin(), pli1.end());
	vector<int> pve2(pli1.begin(), pli1.end());
	vector<int> pve3(pve2);

	cin >> a;
	return 0;
}