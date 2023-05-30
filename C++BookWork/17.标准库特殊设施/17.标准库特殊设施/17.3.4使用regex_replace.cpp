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
#include <sstream>
using namespace std;

using std::regex_constants::format_no_copy;
bool valid(const smatch& m)
{
	if (m[1].matched)
	{
		return m[3].matched
			&& (m[4].matched == 0 || m[4].str() == " ");
	}
	else {
		return !m[3].matched
			&&m[4].str() == m[6].str();// 分隔符必须相同
	}
}
int main()
{
	int a;
	string fmt1 = "$2.$5.$7 ";// 记住空格
	string phone1 = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
	regex r1(phone1);
	string number1 = "(908) 555-1800";
	cout << regex_replace(number1, r1, fmt1) << endl;

	//regex r2(phone1);
	//ifstream ifs2("8.3.2电话号码数据17.3.4.txt");
	//string line;
	//while (getline(ifs2, line)) {
	//	cout << regex_replace(line, r2, fmt1) << endl;
	//}
	// 3
	//regex r3(phone1);
	//ifstream ifs3("8.3.2电话号码数据17.3.4.txt");
	//string line;
	//while (getline(ifs3, line)) {
	//	cout << regex_replace(line, r3, fmt1, format_no_copy) << endl;
	//}
	//string fmt2 = "$2.$5.$7 ";// 记住空格
	//string phone2 = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
	//regex r2(phone2);
	//ifstream ifs2("8.3.2电话号码数据.txt");
	//string line, name, phone;
	//while (getline(ifs2, line)) {
	//	cout << regex_replace(line, r2, fmt2) << endl;
	//}
	// 25
	//regex r3(s3);
	//string fmt3("$2.$5.$7 ");
	//smatch sm3;
	//sm3.format(fmt3);
	//ifstream ifs3("8.3.2电话号码数据.txt");
	//string line3;
	//while (getline(ifs3, line3)) {
	//	if (regex_search(line3, sm3, r3)) {// 只找第一个
	//		cout << sm3.format(fmt3) << endl;
	//	}
	//}
	// 26,第一个不能有错误，就是第一个号码需要匹配才可以
	//string phone4 = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
	//regex r4(phone4);
	//ifstream ifs4("8.3.2电话号码数据26题.txt");
	//string line4, name4;
	//string fmt4("$2.$5.$7 ");
	//int i4;
	//while (getline(ifs4, line4)) {
	//	i4 = 0;
	//	istringstream is4(line4);
	//	ostringstream formatted;
	//	is4 >> name4;
	//	getline(is4, line4);
	//	for (sregex_iterator it(line4.begin(), line4.end(), r4), end_it;
	//		it != end_it; ++it)
	//	{
	//		if (i4 == 0) {
	//			i4 = 1;
	//			continue;
	//		}
	//		formatted << " " << it->format(fmt4);
	//	}
	//	cout << name4 << " " << formatted.str() << endl;
	//}
	string phone5 = "(\\d{5})([-])?(\\d{4})";
	regex r5(phone5);
	smatch m5;
	string s5;
	string fmt5("$1-$3");
	while (getline(cin,s5)) {
		cout << regex_replace(s5,r5,fmt5) << endl;
	}
	/*
	练习：
	17.24: ok
	17.25：ok，用原始的smatch
	17.26: ok,用迭代器，需要控制忽略第一个
	17.27: ok
	*/
	cin >> a;
	return 0;
}
