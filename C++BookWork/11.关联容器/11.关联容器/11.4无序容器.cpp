#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>
#include "Sales_data.h"
#include <fstream>
#include <list>
#include <sstream>
#include <iterator>
#include <utility>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void prints(map<string, int> maps)
{
	for (auto &words : maps)
	{
		cout << words.first << " occurs " << words.second << "times" << endl;;
	}
}
void prints(unordered_map<string, int> maps)
{
	for (auto &words : maps)
	{
		cout << words.first << " occurs " << words.second << "times" << endl;;
	}
}
/*
�ù�ϣ������Ԫ��ӳ�䵽Ͱ�����ȼ���ؼ��ֵĹ�ϣֵ
Ͱ����������߶��Ԫ��

�Զ������
�ؼ�����Ҫ==������ȽϺ���
��Ҫhash<key_type>����������ÿ��Ԫ�صĹ�ϣֵ
*/

size_t hasher(const Sales_data &sd)
{
	return hash<string>()(sd.isbn());
}
bool eqOp(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() == rhs.isbn();
}

const string& transform(const string& words, unordered_map<string, string>& ma) {
	auto map_it = ma.find(words);

	if (map_it != ma.end())
	{
		return map_it->second;
	}
	else {
		return words;
	}
}

unordered_map<string, string> buildMap(ifstream &map_file)
{
	unordered_map<string, string> ma;
	string key, value;
	while (map_file >> key && getline(map_file, value)) {
		if (value.size() >= 1) {
			//ma[key] = value.substr(1);// ����ǰ���ո񣡣���
			ma.insert({ key,value.substr(1) });
		}
		else {
			cout << "no trans" << endl;
		}
	}
	return ma;
}

void word_transform(ifstream& map_file, ifstream& input)
{
	auto trans_map = buildMap(map_file);
	// �����ļ��Ļ�
	string line;
	while (getline(input, line)) {
		istringstream is1(line);
		string words;
		bool firstword = true;
		while (is1 >> words) {
			if (firstword)
				firstword = false;
			else
				cout << " ";
			cout << transform(words, trans_map);
		}
		cout << endl;
	}
}
int main()
{
	int a;
	//unordered_map<string, int> word_count;
	//string cinstr;
	//while (cin>>cinstr&& cinstr != "-1") {
	//	++word_count[cinstr];
	//}
	//prints(word_count);
	
	// ����Ͱ
	unordered_map<string, int> word_count2{ {"1",1},{ "2",2 },{ "3",3 },{ "4",4 },{ "5",5 },{ "5",5 } };
	cout<< word_count2.bucket_count()<<endl;
	cout << word_count2.max_bucket_count() << endl;
	cout << word_count2.bucket_size(4) << endl;
	cout << word_count2.bucket("1") << endl;

	cout << word_count2.load_factor() << endl;
	cout << word_count2.max_load_factor() << endl;
	word_count2.rehash(12);
	cout << word_count2.bucket_count() << endl;
	word_count2.reserve(10);

	// unordered_multiset
	using SD_multiset = unordered_multiset<Sales_data, decltype(hasher)*, decltype(eqOp)*>;
	// ������Ͱ��С����ϣ������������ж������ָ�룡��
	SD_multiset bookstore(42, hasher, eqOp);

	// �����ǵ��ඨ����==���������ֻ��Ҫǰ���������� �����ϣֵ�ú�������Ҫ �����١�

	// ��ϰ
	ifstream trans("11.3.6һ������ת����map.txt");
	ifstream ins("11.3.6һ������ת��������.txt");
	word_transform(trans, ins);
	cin >> a;
	return 0;
}