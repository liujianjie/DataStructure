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
��������� forward_list���ǵ���
˫������� ����forward_list ���ṩ

*/
int main()
{

	int a;
	vector<int> vec1(3);
	//istream_iterator<int> is_it1(cin),is_end1;
	//copy(is_it1, is_end1, vec1.begin());
	//prints(vec1);

	//list<int> fl{1,2,3,3,4,4,5,6,6,7,7,7,8,8,8},fl2(6);
	//list<int>::iterator fl_it1 = fl.begin();
	//list<int>::iterator fl_it2 = fl.end();
	//reverse(fl_it1, fl_it2);
	//prints(fl);
	//auto last = unique(fl_it1, fl_it2);
	//for (auto begin = fl.begin(); last != begin; ++begin) {
	//	cout << *begin << endl;
	//}
	forward_list<int> fl{ 1,2,3,3,4,4,5,6,6,7,7,7,8,8,8 }, fl2(6);
	forward_list<int>::iterator fl_it1 = fl.begin();
	forward_list<int>::iterator fl_it2 = fl.end();
	auto last = unique(fl_it1, fl_it2);
	for (auto begin = fl.begin(); last != begin; ++begin) {
		cout << *begin << endl;
	}
	// ��ϰ
	//copyӦ��ֻ��Ҫ���������,reverse��Ҫ˫������� unique��Ҫǰ�����������
	cin >> a;
	return 0;
}

