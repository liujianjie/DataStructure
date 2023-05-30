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

map���±� ���±�����Ͷ�Ӧ��at
mult�Ĳ����±꣬��Ϊ�п����ж��ֵ��һ���ؼ������
setû���±�

��ͬ���ǣ�����ؼ��ֲ���map�л������Ӳ���map�У����ҹ���ֵ����ֵ��ʼ��

ֻ�ʺ��÷�const��map��unordered_map
*/
int main()
{

	int a;
	map<int, int> map1{ { 1,1 },{ 2,2 },{ 3,3 },{ 4,4 },{ 5,5 } };
	int a1 = map1.at(2);
	cout << a1 << endl;

	// map���±�����(mapped_type)�������һ�����������ص����Ͳ�ͬ��value_type��
	// mapped_type �ɶ���д
	cout << map1[1];
	++map1[1];
	cout << map1[1];

	vector<int> v1;
	//v1[0] = 1;//error

	// ��ϰ
	/*
	map�Ĺؼ�������,���߿���ת��map�Ĺؼ������� key_type,
	���ص���mapped_typed
	*/

	cin >> a;
	return 0;
}