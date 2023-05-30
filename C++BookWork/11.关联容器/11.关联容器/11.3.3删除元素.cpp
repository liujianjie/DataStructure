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

�����汾
�����汾����void
һ����������һ����������
һ���汾����key_type����������ɾ��������
*/
int main()
{

	int a;
	map<int, int> map1{ {1,1},{ 2,2 },{ 3,3 },{ 4,4 },{ 5,5 } };
	if (map1.erase(5)) {
		cout << "ok:" << 5 << "removed\n";
	}else {
		cout << "ok:" << 5 << "not found\n";
	}
	// ���Դ���1
	cin >> a;
	return 0;
}