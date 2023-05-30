#include <iostream>
#include <list>
#include <deque>
#include <vector>
#include <forward_list>
#include <array>
#include "Sales_data.h"
#include "noDefault.h"
#include <string>
using namespace std;

// 练习
class dataDel{

public:
	dataDel(string &s1) {
		// 处理格式 遇到空格，‘，’，‘/’都需要截取
		s1.append(" ");//先加一个空格分3段
		string sign = " ,/";
		string::size_type pos = 0;
		string::size_type prev_pos = 0;
		string tempstr;
		string numberstr("0123456789");
		// 处理1/1/1990 没有字符
		bool no_alpha = true;
		auto beg1 = s1.begin();
		while (beg1 != s1.end()) {
			if (isalpha(*beg1)) {
				no_alpha = false;
				break;
			}
			++beg1;
		}
		while ((pos = s1.find_first_of(sign,pos)) != string::npos) {
			tempstr = s1.substr(prev_pos, pos - prev_pos);
			// 是年份
			if (tempstr.length() == 4) {
				year = stoi(tempstr);
			}
			else {
				// 1/1/1990形式
				if (no_alpha) {
					// 第一个数字是日
					if (prev_pos == 0) {
						day = stoi(tempstr);
					}
					else {
						month = stoi(tempstr);// 月
					}
				}
				else {// jan 1, 1900 等形式
					if (tempstr.find_first_of(numberstr) == string::npos) {// 是月份
						str_month = tempstr;
					}
					else {
						day = stoi(tempstr);;
					}
				}
			}
			pos++;
			prev_pos = pos;// 进级
			//cout << tempstr << endl;
		}
	}
public:
	unsigned year;
	unsigned month;
	string str_month;
	unsigned day;
};
int main()
{
	string teststring("ajczvxzcv");
	cout << teststring.substr(2, 5) << endl;
	int a;
	int v1 = 42;
	string s1 = to_string(v1);
	double d1 = stod(s1);
	cout << s1 << endl;
	cout << d1 << endl;

	// 第一个非空白符必须是数值中可能出现的字符
	string s2 = "pi = 3.14";
	d1 = stod(s2.substr(s2.find_first_of("+-.01234567890")));
	cout << d1 << endl;

	string s3 = "pi = 3.14";
	//d1 = stod(s3);// 异常，无法转换
	cout << d1 << endl;
	string s4 = "123123213123213123123123123123213123123123123123213123123124367546451312312312312312321312312312312312321312312312312";
	//cout << stoi(s4) << endl;// 若数值太大会抛出out_of_range异常
	// stoi,stol,stoul....

	// 练习
	vector<string> ve1{"12312","2","45","12","87","98","12","56"};
	int sum = 0;
	auto beg = ve1.begin();
	while (beg != ve1.end()) {
		sum += stoi(*beg);
		++beg;
	}
	cout << sum << endl;
	float sum2 = 0;
	string pstr1 = "123.12 4.12 31.242";
	int prepos = 0;
	for (int i = 0; i < pstr1.length(); ++i) {
		if (pstr1[i] == ' '||i==pstr1.length() - 1) {
			// 截取这个前面的值
			sum2 += stof(pstr1.substr(prepos, i));
			prepos = i;
		}
	}
	cout << sum2 << endl;
	// 练习：
	string date = "1 1 1900";
	dataDel date1(date);
	cout << date << endl;
	cout << "year:"<< date1.year << endl;
	cout << "month:" << date1.month << endl;
	cout << "str_month:" << date1.str_month << endl;
	cout << "day:" << date1.day << endl;
	cin >> a;
	return 0;
}