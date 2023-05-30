#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>
#include "Sales_data.h"
#include <fstream>
#include <list>


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
int main()
{

	int a;
	// 提供此操作额类型，所以是函数指针
	// 当我们创建一个容器对象时，才会以构造函数参数的形式提供真正的比较操作（其类型必须与在尖括号中指定的类型想吻合）
	// 通过compareIsbn初始化bookstore对象，表示向bookstore添加元素时通过调用compareIsbn来为这些元素排序
	multiset<Sales_data, decltype(compareIsbn)*> bookstore(compareIsbn);
	
	// 练习
	map<string, list<size_t>> map1;
	int line = 1;
	string word;
	ifstream ifs1("11.9练习.txt");
	while (getline(ifs1, word)) {
		map1[word].push_back(line);// 用push_back 叠加出现的行号
		++line;
	}
	for (auto &words : map1) {
		cout << words.first << " ";
		for (auto &lines : words.second) {
			cout << lines <<" ";
		}
		cout << endl;
	}
	// 
	vector<int> ve2{ 12,43,12 };
	vector<int>::iterator be = ve2.begin();
	vector<int>::iterator ed = ve2.end();
	cout << (be < ed) << endl;

	list<int> li1{ 12,43,12 };
	list<int>::iterator be2 = li1.begin();
	list<int>::iterator ed2 = li1.end();
	//cout << (be2 < ed2) << endl;

	map<vector<int>::iterator, int> map2;//
	//map<list<int>::iterator, int> map3;// 不行，因为list没有比较运算符

	// 函数指针的定义
	multiset<Sales_data, bool(*) (const Sales_data &lhs, const Sales_data &rhs)> bookstore(compareIsbn);
	cin >> a;
	return 0;
}