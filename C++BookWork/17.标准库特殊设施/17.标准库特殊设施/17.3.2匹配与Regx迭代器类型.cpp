#include <iostream>
#include <vector>
#include <tuple>
#include <list>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <map>
#include <set>
#include <regex>
using namespace std;

int main()
{
	int a;
	vector<string> vec{ "albeit","beige","feint","heir","reign","their",
		"counterfeit","foreign","inveigh","rein","veil","deign",
		"forfeit","inveigle","seize","veineiderdown","freight",
		"leisure","skein","weigheight","heifer","neigh","sleigh",
		"weighteither","height","neighbour","sleight","weirfeign",
		"heinous neither surfeit weird" };

	string pattern1("[^c]ei");
	pattern1 = "[[:alpha:]]*" + pattern1 + "[[:alpha:]]*";
	regex r1(pattern1);// 查找模式
	//smatch results1;// 结果
	string test_str1 = "receipt freind theif receipt reei recei reisdf rczei leiasdf oiei albeit neighbour cdefsd";
	for (sregex_iterator it(test_str1.begin(), test_str1.end(), r1), end_it;
		it != end_it; ++it) {
		if (find(vec.begin(), vec.end(), it->str()) != vec.end())
		{
			continue;
		}
		cout << it->str() << endl;
	}
	// 改变的是循环内部
	//for (sregex_iterator it(test_str1.begin(), test_str1.end(), r1), end_it;
	//	it != end_it; ++it) {
	//	auto pos = it->prefix().length();
	//	pos = pos > 40 ? pos - 40 : 0;
	//	cout << it->prefix().str().substr(pos)
	//		<< "\n\t\t>> " << it->str() << " <<\n"
	//		<< it->suffix().str().substr(0, 40)
	//		<< endl;
	//}
	/*
	练习：
	17.17:ok
	17.18:
	vector<string> vec{ "albeit","beige","feint","heir","reign","their",
	"counterfeit","foreign","inveigh","rein","veil","deign",
	"forfeit","inveigle","seize","veineiderdown","freight",
	"leisure","skein","weigheight","heifer","neigh","sleigh",
	"weighteither","height","neighbour","sleight","weirfeign",
	"heinous neither surfeit weird" };
	*/
	cin >> a;
	return 0;
}
