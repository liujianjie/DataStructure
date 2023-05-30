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
��Ա�� key_type mapped_type value_type
*/
int main()
{

	int a;
	// ������������
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
	// value_type ��pair���ͣ�first����const�ؼ��֣�second��ֵ�����Ըı�ֵ���ܸı�ؼ���

	// set�ĵ�������const�ģ�set�Ĺؼ���Ҳ��const�� �����޸�
	set<int> se1;
	set<int>::iterator it1 = se1.begin();
	//*it1 = 42;// ��Ȼ��iterator ������const��

	// ������������ �����õ�����
	//auto map_it = word_count2.cbegin();
	map<string, int>::const_iterator map_it = word_count2.cbegin();
	while (map_it != word_count2.cend()) {
		cout << map_it->first << " occurs " << map_it->second << "times" << endl;
		++map_it;
	}
	//�����������㷨
	/*��������ֻ������ֻ��ȡԪ�ص��㷨�������㷨��Ҫ�������У����������е�Ԫ�ز���ͨ�����ǵĹؼ��ֽ��в��ң����Բ���
	����find��һ��һ��������������������ר�õ�find��Ա����
	�ɵ�ԭ���л���Ŀ��λ��
	*/

	// ��ϰ
	map<int, vector<int>> map3;
	// mapped_type ��vector<int>
	// key_type ��const int
	// value_type ��pair

	map<int, int> map4{ {1,2} };
	int val = map4.begin()->second;
	cout << val << endl;

	multiset<string> c;
	vector<string> v;
	copy(v.begin(), v.end(), inserter(c, c.end()));
	//copy(v.begin(), v.end(), back_inserter(c));//���У���Ϊû��pushback

	copy(v.begin(), v.end(), inserter(v, v.end()));
	copy(v.begin(), v.end(), back_inserter(v));

	//
	multiset<Sales_data, decltype(compareIsbn)*> bookstore(compareIsbn);
	multiset<Sales_data, decltype(compareIsbn)*>::iterator it3 = bookstore.begin();


	cin >> a;
	return 0;
}