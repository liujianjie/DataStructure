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
添加一个元素，或者一个元素范围
*/
int main()
{

	int a;
	vector<int> ive1 = { 2,3,4,5,6,4,4,6,8,8,5 };
	set<int> set1;
	set1.insert(ive1.cbegin(), ive1.cend());
	set1.insert({ 1,3,4,5,7,1,3,7 });

	// 向map添加 元素类型是pair
	map<string, int> map1;
	map1.insert({"st", 1});
	map1.insert(make_pair("st", 1 ));
	map1.insert(pair<string,size_t> ( "st", 1 ));
	map1.insert(map<string, size_t>::value_type( "st", 1 ));

	// 检测insert返回值
	//map<string, int> word_count2;
	//string cinstr;
	//while (cin >> cinstr&& cinstr != "-1") {
	//	auto paisreturn = word_count2.insert({cinstr,1});
	//	if (!paisreturn.second) {// 插入失败，则递增
	//		++paisreturn.first->second;
	//	}
	//}
	//map<string, int>::const_iterator map_it = word_count2.cbegin();
	//while (map_it != word_count2.cend()) {
	//	cout << map_it->first << " occurs " << map_it->second << "times" << endl;
	//	++map_it;
	//}

	// 展开
	//pair<map<string, int>::iterator, bool> ret = word_count2.insert(make_pair("n",1));

	// multiset 或者 multimap
	multimap<string, string> mulmap1;
	mulmap1.insert({"liujianjie","c"});
	mulmap1.insert({ "liujianjie","t" });
	mulmap1.insert({ "liujianjie","b" });
	multimap<string, string>::const_iterator map_it2 = mulmap1.cbegin();
	while (map_it2 != mulmap1.cend()) {
		cout << map_it2->first << " occurs " << map_it2->second << "times" << endl;
		++map_it2;
	}
	// 练习
	map<string, int> word_count2;
	string cinstr;
	while (cin >> cinstr&& cinstr != "-1") {
		++word_count2.insert({ cinstr,0 }).first->second;
	}
	map<string, int>::const_iterator map_it = word_count2.cbegin();
	while (map_it != word_count2.cend()) {
		cout << map_it->first << " occurs " << map_it->second << "times" << endl;
		++map_it;
	}

	// 
	map<string, vector<int>> map3;
	pair<map<string, vector<int>>::iterator, bool> re_type =  map3.insert(pair<string, vector<int>>( "1",{1,2,3} ));
	
	cin >> a;
	return 0;
}