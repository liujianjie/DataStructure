#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>

using namespace std;

void prints(map<string, int> maps)
{
	for (auto &words : maps)
	{
		cout << words.first << " occurs " << words.second << "times" << endl;;
	}
}
int main()
{

	int a;
	// ����ֵ��ʼ���������б��ʼ��
	map<string, size_t> map1;
	set<string> set1 = { "the","but","an" };
	map<string, string> authors = { {"1","11"},
	{ "2","22" },
	{ "3","33" },
	{ "4","44" }, };

	// �� ��ʼ��multimap �� multiset
	vector<int> ivec;
	for (vector<int>::size_type i = 0; i != 20; ++i) {
		ivec.push_back(i);
		ivec.push_back(i);
	}
	set<int> set2(ivec.begin(), ivec.end());// 20��Ԫ��
	multiset<int> set3(ivec.begin(), ivec.end());// 40��Ԫ��
	cout << set2.size() << endl;
	cout << set3.size() << endl;

	// ��ϰ
	/*
	1.��û�йؼ���ӳ��Ԫ�ؾ�ʹ��set�򵥱�ݣ������йؼ�����Ԫ���ظ������ǹؼ��ֲ�ͬ��������map
	2.list�����ظ���set�������ظ���list������ģ���������ɾ�Ŀ죬
	3.
	4.�Զ��׼���������set�ò��ң�find������
	*/
	vector<string> ve3(20);


	cin >> a;
	return 0;
}