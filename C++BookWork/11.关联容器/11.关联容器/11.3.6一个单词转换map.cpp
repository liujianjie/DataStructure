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

using namespace std;

const string& transform(const string& words, map<string, string>& ma) {
	auto map_it = ma.find(words);

	if (map_it != ma.end())
	{
		return map_it->second;
	}
	else {
		return words;
	}
}

map<string, string> buildMap(ifstream &map_file)
{
	map<string, string> ma;
	string key, value;
	while (map_file >> key && getline(map_file, value)) {
		if (value.size() >= 1) {
			//ma[key] = value.substr(1);// 跳过前导空格！！！
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
	// 输入文件的话
	string line;
	while (getline(input,line)) {
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
	ifstream trans("11.3.6一个单词转换的map.txt");
	ifstream ins("11.3.6一个单词转换的输入.txt");
	word_transform(trans,ins);

	// 练习
	// ma.insert({ key,value.substr(1) });只插入不存在的key，而原本的是保存最后一个key
	// 那么输出也会为空


	std::cin >> a;
	return 0;
}