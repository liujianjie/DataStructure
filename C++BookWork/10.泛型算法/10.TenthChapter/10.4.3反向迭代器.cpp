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
using namespace std::placeholders;// ռλ���ռ�


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
/*
��������û�з��������
forward_listҲû�з��������
find �ĵ�����������Ҫ��ת���ɵ�����
*/
int main()
{

	int a;
	vector<int> vec1 = { 0,1,2,3,4,5,6,7,8,9 };
	for (auto r_iter = vec1.crbegin();
		r_iter != vec1.crend(); ++r_iter) {
		cout << *r_iter << " ";
	}
	cout << endl;

	sort(vec1.begin(), vec1.end());
	prints(vec1);
	sort(vec1.rbegin(), vec1.rend());
	prints(vec1);

	//istream_iterator<string> ist1(cin);

	forward_list<int> fl{1,2,3,4};
	//fl.b

	string str1 = "FIRST,MIDDLE,LAST";
	auto it1 = find(str1.cbegin(),str1.cend(),',');// ���Ų���д��"",��Ϊ����ת��Ϊ ==��ֻ��char����''==��stringƥ��
	cout << string(str1.cbegin(), it1) << endl;

	auto it2 = find(str1.crbegin(), str1.crend(), ',');
	cout << string(str1.crbegin(), it2) << endl;

	cout << string(it2.base(),str1.cend()) << endl;

	// it �� it.base() ָ�����ڵ�ֵ
	cout << *it2 << endl;
	cout << *(it2.base()) << endl;

	// ��ϰ
	vector<int> v2{ 1,2,3,4,5 };
	vector<int>::reverse_iterator r_it1 = v2.rbegin();
	vector<int>::reverse_iterator r_it2 = v2.rend();
	for (; r_it1 != r_it2; ++r_it1) {
		cout << *r_it1 << endl;
	}
	vector<int>::iterator r_it3 = v2.begin();
	vector<int>::iterator r_it4 = v2.end();
	for (; (r_it3) != r_it4; ) {
		cout << *(--r_it4) << endl;
	}

	vector<int> li{ 0,1,2,3,4,5,6,0,9,83,3 };
	auto it4 = find(li.rbegin(), li.rend(), 0);
	cout << (it4.base() - li.begin()) << endl;

	vector<int> v5{1,2,3,4,5,6,7,8,9,10};
	list<int> li2(5);
	cout << *(v5.rbegin() + 3) << endl;
	copy(v5.rbegin() + 2, v5.rbegin() + 7, li2.begin());// Ҫbegin(),λ��
	prints(li2);
	cin >> a;
	return 0;
}

