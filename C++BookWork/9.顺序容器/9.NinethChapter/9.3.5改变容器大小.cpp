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

int main()
{
	int a;

	//
	list<int> ilist(10, 42);// 10��int��ÿ��ֵ����42
	ilist.resize(15);// ���5��0
	for (auto beg = ilist.begin(), end = ilist.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;
	ilist.resize(25, -1);// ���10��ֵ�ٺ���
	for (auto beg = ilist.begin(), end = ilist.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;
	ilist.resize(5);// ɾ��20��Ԫ��
	for (auto beg = ilist.begin(), end = ilist.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;

	// array��֧��
	//array<int, 10> arr1;
	//arr1.resize(15);

	deque<int> li1(10, 42);// 10��int��ÿ��ֵ����42
	auto it1 = li1.begin() + 7;
	cout << *it1 << endl;
	li1.resize(5);
	//cout << *it1 << endl;// ��ʧЧ

	// ��ϰ
	// 9.29
	vector<int> ve2(25);
	for (auto beg = ve2.begin(), end = ve2.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;
	ve2.resize(100);
	for (auto beg = ve2.begin(), end = ve2.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;
	cout << ve2.size() << endl;
	ve2.resize(10);
	for (auto beg = ve2.begin(), end = ve2.end();
		beg != end; ++beg) {
		cout << *beg;
	}
	cout << endl;

	// ��ϰ9.30 
	cin >> a;
	return 0;
}