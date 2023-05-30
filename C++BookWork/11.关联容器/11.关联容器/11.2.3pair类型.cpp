#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>
#include "Sales_data.h"
#include <fstream>
#include <list>
#include <iterator>
#include <utility>


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
ͷ�ļ� utility

*/
pair<string, int> process(vector<string> &v) {
	if (!v.empty()) {
		return{ v.back(),v.back().size() };// �б��ʼ��
	}
	else {
		return pair<string, int>();//��ʽһ���յ�
	}
}
int main()
{
	int a;
	pair<string, string> anon;
	pair<string, size_t> word_count;
	pair<string, vector<int>> line;

	// ��ʼ��
	pair<int, int> pa1(1, 2);
	pair<int, int> pa2 = { 3,4 };
	pair<int, int> pa3 = make_pair(5, 6);


	// ��ϰ
	map<string, int> map1({ {"1",1}, { "2",2 }, { "3",3 }, { "4",4 } });
	vector<pair<string, int>> ve1;
	for (auto &be1 : map1) {
		ve1.push_back(make_pair(be1.first, be1.second));
		ve1.push_back({ be1.first, be1.second });
		pair<string, int> p(be1.first, be1.second);
		ve1.push_back(p);
	}
	for (auto &be1 : ve1) {
		cout << be1.first << " " << be1.second << endl;
	}
	// ��һ��

	std::cin >> a;
	return 0;
}