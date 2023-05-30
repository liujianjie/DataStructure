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
	// �ṩ�˲��������ͣ������Ǻ���ָ��
	// �����Ǵ���һ����������ʱ���Ż��Թ��캯����������ʽ�ṩ�����ıȽϲ����������ͱ������ڼ�������ָ�����������Ǻϣ�
	// ͨ��compareIsbn��ʼ��bookstore���󣬱�ʾ��bookstore���Ԫ��ʱͨ������compareIsbn��Ϊ��ЩԪ������
	multiset<Sales_data, decltype(compareIsbn)*> bookstore(compareIsbn);
	
	// ��ϰ
	map<string, list<size_t>> map1;
	int line = 1;
	string word;
	ifstream ifs1("11.9��ϰ.txt");
	while (getline(ifs1, word)) {
		map1[word].push_back(line);// ��push_back ���ӳ��ֵ��к�
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
	//map<list<int>::iterator, int> map3;// ���У���Ϊlistû�бȽ������

	// ����ָ��Ķ���
	multiset<Sales_data, bool(*) (const Sales_data &lhs, const Sales_data &rhs)> bookstore(compareIsbn);
	cin >> a;
	return 0;
}