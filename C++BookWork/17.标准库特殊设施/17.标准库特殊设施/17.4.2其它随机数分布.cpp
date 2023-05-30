#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <map>
#include <set>
#include <sstream>
#include <random>
#include <ctime>
using namespace std;

void par31() {
	int i = 0;
	do {
		default_random_engine e1;
		bernoulli_distribution ber1;
		cout << "vals:" << ber1(e1) << endl;
	} while (++i != 10);
}

const string& transform(const string& words, map<string, vector<string>>& ma) {
	static default_random_engine e1(time(0));
	static uniform_int_distribution<unsigned int> u1(0, 4);
	int index;
	auto map_it = ma.find(words);
	if (map_it != ma.end())
	{
		while ((index = u1(e1)) > (map_it->second.size() - 1));
		//cout << "size:" << map_it->second.size() <<"max:"<<u1.max() << endl;
		return map_it->second[index];
	}
	else {
		return words;
	}
}

map<string, vector<string>> buildMap(ifstream &map_file)
{
	map<string, vector<string>> ma;
	string key, values,value;
	while (map_file >> key && getline(map_file, values)) {
		if (values.size() >= 1) {
			//ma[key] = value.substr(1);// 跳过前导空格！！！
			istringstream is(values.substr(1));
			vector <string> ve;
			while (is>>value) {
				ve.push_back(value);
			}
			ma.insert({ key,ve });
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
	default_random_engine e1;
	uniform_real_distribution<double> u1(0, 1);
	for (size_t i = 0; i < 10; ++i)
		cout << u1(e1) << " ";

	cout << u1.max() << endl;
	cout << u1.min() << endl;
	u1.reset();// ??
	for (size_t i = 0; i < 10; ++i)
		cout << u1(e1) << " ";

	//
	cout << endl;
	uniform_real_distribution<> u2(0, 1);// 默认生成double值
	for (size_t i = 0; i < 10; ++i)
		cout << u2(e1) << " ";

	// 
	default_random_engine e3;
	normal_distribution<> n1(4,1.5);
	vector<unsigned> vals1(9);
	for (size_t i = 0; i != 200; ++i) {
		unsigned v = lround(n1(e3));
		if (v < vals1.size())
			++vals1[v];
	}
	for (size_t j = 0; j != vals1.size(); ++j) {
		cout << j << ":" << string(vals1[j], '*') << endl;
	}

	// 伯努利分布就是硬币的那个分布吧？
	default_random_engine e4;
	bernoulli_distribution b1;
	for (size_t j = 0; j != 10; ++j) {
		cout << "bernoulli :" << b1(e4) << endl;
	}
	bernoulli_distribution b2(.55);
	for (size_t j = 0; j != 10; ++j) {
		cout << "bernoulli2 :" << b2(e4) << endl;
	}

	//
	par31();
	//string resp;
	//do {
	//	cout << "press your yes or no" << endl;
	//} while (cin >> resp && resp[0] == 'y');
	
	//
	ifstream trans("11.3.6一个单词转换的map.txt");
	ifstream ins("11.3.6一个单词转换的输入.txt");
	word_transform(trans, ins);
	/*
	练习：
	17.31:重复第一个值 ok
	17.32:报错 ok
	17.33:ok
	*/
	cin >> a;
	return 0;
}
