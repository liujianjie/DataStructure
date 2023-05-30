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


count: 计数
find:不会计数,返回迭代器
equal_range，返回迭代器pair，等于k的元素的范围
*/
int main()
{

	int a;
	multiset<int> set1 = {0,1,2,3,4,4,4,8,4,8,2};
	cout << *set1.find(4) << endl;
	cout << set1.count(4) << endl;
	cout << *set1.lower_bound(4) << endl;
	cout << *set1.upper_bound(4) << endl;
	cout << *set1.equal_range(4).first<<" --"<< *set1.equal_range(4).second << endl;

	// map的查找用find
	map<int, int> map1({ {1,1}, { 2,2 }, { 3,3 } });
	if (map1.find(4) == map1.end() ){
		cout << "not found" << endl;
	}
	// 在multimap multiset中查找元素，有多个元素具有给定对应一个关键字，这些元素在容器中会相邻存储
	multimap<string, string> mulmap1({ {"liu","c"} ,{ "liu2","c" } ,{ "liu3","c" } ,{ "liu","a" } ,{ "liu","b" } });
	string search_item("liu");
	auto entries = mulmap1.count("liu");
	auto iter1 = mulmap1.find(search_item);
	while (entries) {
		cout << (*iter1).second << endl;
		++iter1;
		--entries;
	}
	// 第二种 lower_bound upper_bound得到迭代器范围
	auto beg = mulmap1.lower_bound("liu");
	auto end = mulmap1.upper_bound("liu");
	while (beg != end) {
		cout << (*beg).second << endl;
		++beg;
	}
	cout << "-----" << endl;
	// 第三种 equal_range
	// range1.first也是pair类型，value_type，可以用range1.first->second访问，也可以用(*range1.first).second
	auto range1 = mulmap1.equal_range("liu");
	while (range1.first != range1.second) {
		cout << range1.first->second << endl;
		cout << (*range1.first).second << endl;
		++range1.first;
	}
	// 练习
	map<string, int> map4({ {"no",1},{ "noes",2 },{ "nos",3 } });
	map<string, int>::iterator pa =  map4.find("no");
	cout << (*pa).first << " " << (*pa).second << endl;

	/*
	upper,lower_bound 可插入的位置，或者尾后迭代器，equal_range的pair两个成员都为end（）

	pair pos的第一个first得到迭代器，迭代器再得到元素
	*/
	multimap<string,string> map5(
	{ { "liu","c" } ,{ "liu2","c" } ,{ "liu3","c" } ,{ "liu","a" } ,{ "liu","b" },{ "liu","b" }
	,{ "aliu","b" } ,{ "bliu","b" } ,{ "cliu","b" } ,{ "dliu","b" } ,{ "eliu","b" } ,{ "fliu","b" } });
	if (map5.find("liu") != map5.end()) {
		// 应该要一个范围 不用，删除所有匹配的
		auto cous = map5.erase("liu");
		cout << "已经删除" << cous << endl;
	}
	else {
		cout << "no item" << endl;
	}
	auto begs = map5.begin();
	while (begs != map5.end()) {
		cout << begs->first << " " << begs->second << endl;
		++begs;
	}
	multimap<string, string> map6;
	map6.insert({ "Arthur Conan Doyle", "A Study in Scarlet" });
	map6.insert({ "Arthur Conan Doyle", "The War in South Africa：Its Cause and Conduct" });
	map6.insert({ "Arthur Conan Doyle", "Silver Blaze" });
	map6.insert({ "Arthur Conan Doyle", "The Sign of Four" });
	map6.insert({ "Agatha Christie", "Murder on the Links" });
	map6.insert({ "Agatha Christie", "The ABC Murders" });
	map6.insert({ "Agatha Christie", "Murder in the Calais Coach" });
	// 按照字典序打印 用set保存值，set会按字典序
	set<string> name, book;
	for (auto &ite : map6) {
		name.insert(ite.first);
	}
	for (auto &ite : name) {
		cout << ite << "'s books list:" << endl;
		for (auto pairs = map6.equal_range(ite); pairs.first != pairs.second; ++pairs.first) {
			book.insert(pairs.first->second);
		}
		for (auto &li : book) {
			cout << "\t" << li << endl;
		}
		book.clear();
	}
	cin >> a;
	return 0;
}