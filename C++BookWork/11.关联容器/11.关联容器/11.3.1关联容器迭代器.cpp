#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>
#include "Sales_data.h"
#include <fstream>
#include <list>
#include <iterator>


using namespace std;

void prints(map<string, int> maps)
{
	for (auto &words : maps)
	{
		cout << words.first << " occurs " << words.second << "times" << endl;;
	}
}
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}
/*
成员有 key_type mapped_type value_type
*/
int main()
{

	int a;
	// 关联容器操作
	set<string>::value_type v1;
	set<string>::value_type v2;
	map<string, int>::value_type v3;
	map<string, int>::key_type v4;
	map<string, int>::mapped_type v5;

	map<string, int> word_count2;
	string cinstr;
	while (cin >> cinstr&& cinstr != "-1") {
		++word_count2[cinstr];
	}
	// value_type 是pair类型，first保存const关键字，second是值，可以改变值不能改变关键字

	// set的迭代器是const的，set的关键字也是const的 不能修改
	set<int> se1;
	set<int>::iterator it1 = se1.begin();
	//*it1 = 42;// 虽然是iterator 但是是const的

	// 遍历关联容器 可以用迭代器
	//auto map_it = word_count2.cbegin();
	map<string, int>::const_iterator map_it = word_count2.cbegin();
	while (map_it != word_count2.cend()) {
		cout << map_it->first << " occurs " << map_it->second << "times" << endl;
		++map_it;
	}
	//关联容器和算法
	/*关联容器只可用于只读取元素的算法，但又算法需要搜索序列，关联容器中的元素不能通过他们的关键字进行查找，所以不可
	泛型find是一个一个检索，关联容器定义专用的find成员更好
	可当原序列或者目的位置
	*/

	// 练习
	map<int, vector<int>> map3;
	// mapped_type 是vector<int>
	// key_type 是const int
	// value_type 是pair

	map<int, int> map4{ {1,2} };
	int val = map4.begin()->second;
	cout << val << endl;

	multiset<string> c;
	vector<string> v;
	copy(v.begin(), v.end(), inserter(c, c.end()));
	//copy(v.begin(), v.end(), back_inserter(c));//不行，因为没有pushback

	copy(v.begin(), v.end(), inserter(v, v.end()));
	copy(v.begin(), v.end(), back_inserter(v));

	//
	multiset<Sales_data, decltype(compareIsbn)*> bookstore(compareIsbn);
	multiset<Sales_data, decltype(compareIsbn)*>::iterator it3 = bookstore.begin();


	cin >> a;
	return 0;
}