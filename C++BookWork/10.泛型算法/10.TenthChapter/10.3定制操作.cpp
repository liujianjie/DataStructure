#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <iterator>
#include <list>
#include "Sales_data.h"
using namespace std;

// ������Ԫ�ص�ֵ������ת��Ϊ����Ĳ���
bool isShorter(const string &s1, const string &s2) 
{
	return s1.size() < s2.size();
}
void elimDups(vector<string> &words)
{
	// ��Ϊ�㷨�ǶԵ��������������������������㷨����ֱ����ӻ�ɾ��Ԫ��
	// ���ֵ�������words
	sort(words.begin(), words.end());
	// �����ظ���
	auto thewei = unique(words.begin(), words.end());
	cout << words.size() << endl;
	// ����ɾ��
	words.erase(thewei, words.end());
	cout << words.size() << endl;
}

bool compareIsbn(Sales_data &s1, Sales_data &s2) 
{
	return s1.isbn().length() < s2.isbn().length();
}

bool tenonthree(const string& s1) {
	return s1.length() < 5;
}
int main()
{
	int a;
	vector<string> v1{ "the","quick", "red", "fox", "jumps", "over", "the", "slow", "red" ,"turtle" };
	//sort(v1.begin(), v1.end(), isShorter);
	elimDups(v1);
	for (auto beg = v1.begin(); beg != v1.end(); ++beg) {
		cout << *beg << " ";
	}
	cout << endl;
	stable_sort(v1.begin(), v1.end(), isShorter);// ����ͬ�ȴ�С������ֵ���
	for (auto beg = v1.begin(); beg != v1.end(); ++beg) {
		cout << *beg << " ";
	}
	cout << endl;

	// ��ϰ
	vector<Sales_data> v2{Sales_data("123"),Sales_data("8756") ,Sales_data("8") ,Sales_data("789") };
	sort(v2.begin(), v2.end(), compareIsbn);
	for (auto beg = v2.begin(); beg != v2.end(); ++beg) {
		cout << (*beg).isbn() << " ";
	}
	cout << endl;

	vector<string> v3{ "the","quick", "red", "fox", "jumps", "overdfsdf", "the", "slow", "red" ,"turtle" };
	auto trueiter = partition(v3.begin(), v3.end(), tenonthree);
	for (auto beg = v3.begin(); beg != v3.end(); ++beg) {
		cout << (*beg) << " ";
	}
	cout << endl;
	cout << v3.end() - trueiter << endl;
	cin >> a;
	return 0;
}