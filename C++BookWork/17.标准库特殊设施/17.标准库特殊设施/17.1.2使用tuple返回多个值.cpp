#include <iostream>
#include <vector>
#include <tuple>
#include <list>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include "Sales_data.h"
using namespace std;

// ���ʹ��vector�����ۼ�¼����ͬһ�飬�����ݻ����

// �ҵ���ͬ��isbn,�˷��˺ö�ʱ�䣬��Ϊ��string�Ĺ��캯��Ϊexplicit�ˣ���Ϊbook��Ҫת��Ϊsales_data����compareISbn������
bool compareIsbn(const Sales_data &lhs,const Sales_data &rhs) {
	return lhs.isbn() < rhs.isbn();
}
typedef tuple < vector<Sales_data>::size_type,
	vector<Sales_data>::const_iterator,
	vector<Sales_data>::const_iterator> matches;
vector<matches> 
findBook(const vector<vector<Sales_data>> &files, const string &book)
{
	vector<matches> ret;
	for (auto it = files.cbegin(); it != files.cend(); ++it)
	{
		// equal_range ֻ�Ե�ͬһ������ã���ͬ�鲻���ȡ����
		auto found = std::equal_range(it->cbegin(), it->cend(), book, compareIsbn);
		if (found.first != found.second) {
			ret.push_back(make_tuple(it - files.cbegin(), found.first,found.second));
		}
	}
	return ret;
}

void reportResults(istream &in, ostream &os,
	const vector <vector<Sales_data>> &files)
{
	string s;
	while (in >> s)
	{
		auto trans = findBook(files, s);
		if (trans.empty()) {
			cout << s << "not found in any stores" << endl;
			continue;
		}
		for (const auto &store : trans) {
			// get<1>(store)�Ƕ���accumulate���Ի�ȡ����ģ�������ɣ����ǵ�ַ������accumulate���Ի�ȡ��ַ�����ӵ�ַһ��
			auto a = (accumulate(get<1>(store), get<2>(store), Sales_data(s)));
			os << "store: " << get<0>(store) << "sales: " << a << endl;
		}
	}
}

typedef pair<vector<Sales_data>::size_type,
	pair<vector<Sales_data>::const_iterator, vector<Sales_data>::const_iterator>> matches2;

vector<matches2>
findBook2(const vector<vector<Sales_data>> &files, const string &book)
{
	vector<matches2> ret;
	for (auto it = files.cbegin(); it != files.cend(); ++it)
	{
		// equal_range ֻ�Ե�ͬһ������ã���ͬ�鲻���ȡ����
		auto found = std::equal_range(it->cbegin(), it->cend(), book, compareIsbn);
		if (found.first != found.second) {
			ret.push_back(make_pair(it - files.cbegin(), make_pair(found.first, found.second)));
		}
	}
	return ret;
}
void reportResults2(istream &in, ostream &os,
	const vector <vector<Sales_data>> &files)
{
	string s;
	while (in >> s)
	{
		auto trans = findBook2(files, s);
		if (trans.empty()) {
			cout << s << "not found in any stores" << endl;
			continue;
		}
		for (const auto &store : trans) {
			// get<1>(store)�Ƕ���accumulate���Ի�ȡ����ģ�������ɣ����ǵ�ַ������accumulate���Ի�ȡ��ַ�����ӵ�ַһ��
			auto a = (accumulate(store.second.first, store.second.second, Sales_data()));
			os << "store: " << get<0>(store) << "sales: " << a << endl;
		}
	}
}
int main()
{
	int a;
	vector<vector<Sales_data>> files;
	vector<Sales_data> v1;
	v1.push_back(Sales_data("001",1,1));
	v1.push_back(Sales_data("001", 1, 1));
	v1.push_back(Sales_data("001", 1, 1));
	v1.push_back(Sales_data("001", 1, 1));
	v1.push_back(Sales_data("002", 1, 1));
	v1.push_back(Sales_data("003", 1, 1));
	v1.push_back(Sales_data("003", 1, 1));

	vector<Sales_data> v2;
	v2.push_back(Sales_data("001", 1, 1));
	v2.push_back(Sales_data("001", 1, 1));
	v2.push_back(Sales_data("001", 1, 1));
	v2.push_back(Sales_data("002", 1, 1));
	v2.push_back(Sales_data("002", 1, 1));
	v2.push_back(Sales_data("002", 1, 1));
	v2.push_back(Sales_data("003", 1, 1));
	files.push_back(v1);
	files.push_back(v2);

	//reportResults(cin,cout,files);
	reportResults2(cin, cout, files);
	/*
	��ϰ��
	17.4:ok
	17.5:ok
	17.6:������pair��tuple����Ҫһ�������洢
	17.7:������tuple�汾������
	17.8:�������ݴ�������ʱ����һ�������ʼ��ԱΪ0
	*/

	// ��������м�������Ԫ�� Ҳ���ӡ����
	/*vector<string> ma1;
	ma1.push_back("a");
	ma1.push_back("b");
	ma1.push_back("b");
	ma1.push_back("b");
	ma1.push_back("dddd");
	ma1.push_back("b");
	ma1.push_back("b");
	ma1.push_back("b");
	ma1.push_back("c");
	ma1.push_back("b");
	auto ret = equal_range(ma1.cbegin(), ma1.cend(), "b");
	cout << *ret.first << " " << *ret.second << endl;
	for (auto pos = equal_range(ma1.cbegin(), ma1.cend(), "b"); pos.first != pos.second; ++pos.first) {
		cout << *pos.first << endl;
	}*/
	//multiset<string> ma1;
	/*ma1.insert("a");
	ma1.insert("b");
	ma1.insert("b");
	ma1.insert("b");
	ma1.insert("d");
	ma1.insert("b");
	ma1.insert("b");
	ma1.insert("b");
	ma1.insert("c");
	ma1.insert("b");*/
	//ret = ma1.equal_range("b");
	//auto test = ma1.equal_range("b");
	//cout << *(test.first) << " => " << *(test.second) << endl;
	//for (auto b = test.first; b != test.second; b++) {
	//	cout << *b << endl;
	//}
	//cout << ret.first->first << " => " << ret.first->second << endl;

	//cout << ret.second->first << " => " << ret.second->second << endl;
	
	cin >> a;
	return 0;
}
