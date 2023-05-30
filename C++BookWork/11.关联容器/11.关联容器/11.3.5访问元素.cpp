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


count: ����
find:�������,���ص�����
equal_range�����ص�����pair������k��Ԫ�صķ�Χ
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

	// map�Ĳ�����find
	map<int, int> map1({ {1,1}, { 2,2 }, { 3,3 } });
	if (map1.find(4) == map1.end() ){
		cout << "not found" << endl;
	}
	// ��multimap multiset�в���Ԫ�أ��ж��Ԫ�ؾ��и�����Ӧһ���ؼ��֣���ЩԪ���������л����ڴ洢
	multimap<string, string> mulmap1({ {"liu","c"} ,{ "liu2","c" } ,{ "liu3","c" } ,{ "liu","a" } ,{ "liu","b" } });
	string search_item("liu");
	auto entries = mulmap1.count("liu");
	auto iter1 = mulmap1.find(search_item);
	while (entries) {
		cout << (*iter1).second << endl;
		++iter1;
		--entries;
	}
	// �ڶ��� lower_bound upper_bound�õ���������Χ
	auto beg = mulmap1.lower_bound("liu");
	auto end = mulmap1.upper_bound("liu");
	while (beg != end) {
		cout << (*beg).second << endl;
		++beg;
	}
	cout << "-----" << endl;
	// ������ equal_range
	// range1.firstҲ��pair���ͣ�value_type��������range1.first->second���ʣ�Ҳ������(*range1.first).second
	auto range1 = mulmap1.equal_range("liu");
	while (range1.first != range1.second) {
		cout << range1.first->second << endl;
		cout << (*range1.first).second << endl;
		++range1.first;
	}
	// ��ϰ
	map<string, int> map4({ {"no",1},{ "noes",2 },{ "nos",3 } });
	map<string, int>::iterator pa =  map4.find("no");
	cout << (*pa).first << " " << (*pa).second << endl;

	/*
	upper,lower_bound �ɲ����λ�ã�����β���������equal_range��pair������Ա��Ϊend����

	pair pos�ĵ�һ��first�õ����������������ٵõ�Ԫ��
	*/
	multimap<string,string> map5(
	{ { "liu","c" } ,{ "liu2","c" } ,{ "liu3","c" } ,{ "liu","a" } ,{ "liu","b" },{ "liu","b" }
	,{ "aliu","b" } ,{ "bliu","b" } ,{ "cliu","b" } ,{ "dliu","b" } ,{ "eliu","b" } ,{ "fliu","b" } });
	if (map5.find("liu") != map5.end()) {
		// Ӧ��Ҫһ����Χ ���ã�ɾ������ƥ���
		auto cous = map5.erase("liu");
		cout << "�Ѿ�ɾ��" << cous << endl;
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
	map6.insert({ "Arthur Conan Doyle", "The War in South Africa��Its Cause and Conduct" });
	map6.insert({ "Arthur Conan Doyle", "Silver Blaze" });
	map6.insert({ "Arthur Conan Doyle", "The Sign of Four" });
	map6.insert({ "Agatha Christie", "Murder on the Links" });
	map6.insert({ "Agatha Christie", "The ABC Murders" });
	map6.insert({ "Agatha Christie", "Murder in the Calais Coach" });
	// �����ֵ����ӡ ��set����ֵ��set�ᰴ�ֵ���
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