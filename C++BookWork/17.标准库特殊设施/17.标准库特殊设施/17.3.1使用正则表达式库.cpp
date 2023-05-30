#include <iostream>
#include <vector>
#include <tuple>
#include <list>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <regex>
using namespace std;

int main()
{
	int a;
	//string pattern("[^c]ei");// 不在字符c之后的字符串ei
	////改造包括ei的单词，空格隔开
	//pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	//regex r(pattern);// 查找模式
	//smatch results;// 结果
	//string test_str = "receipt freind theif receipt";
	//if (regex_search(test_str, results, r))
	//	cout << results.str() << endl;

	// 模式
	// 一个或多个字母或数字字符后接一个'.' 再接cpp 或 cxx cc
	string pattern2 = "[[:alnum:]]+\\.(cpp|cxx|cc)$";// 第一个\去掉c+特殊，第二个\去掉正则表达式.的特殊函数
	regex r2(pattern2,regex::icase);// 查找模式
	smatch results2;// 结果
	string test_str2 = "adsf you.CPP";
	if (regex_search(test_str2, results2, r2))
		cout << results2.str() << endl;

	try {
		regex r3("[[:alnum:]+\\.(cpp|cxx|cc)$", regex::icase);
	}
	catch (regex_error e) {
		cout << e.what() << "\ncode: " << e.code() << endl;
	}

	string pattern3 = "[[:alnum:]]+\\.(cpp|cxx|cc)$";// 第一个\去掉c+特殊，第二个\去掉正则表达式.的特殊函数
	regex r3(pattern3, regex::icase);// 查找模式
	//smatch results3;// 结果// 错误，输入为char*,函数不匹配，需要用cmatch
	cmatch results3;
	if (regex_search("adsf you.CPP", results3, r3))
		cout << results3.str() << endl;

	// 17.16
	//string pattern4("i[^e]|[^e]c");
	string pattern4("[^c]ei");
	pattern4 = "[[:alpha:]]*" + pattern4 + "[[:alpha:]]*";
	regex r4(pattern4);// 查找模式
	smatch results4;// 结果
	string test_str4;
	cout << "press your word" << endl;
	while (cin >> test_str4) {
		if (regex_search(test_str4, results4, r4)) {
			cout << results4.str()<<"找到了" << endl;
		}
		else {
			cout << "不违反" << endl;
		}
	}
	
	//string pattern("[^c]ei");
	//pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	//try {
	//	regex r(pattern);
	//	smatch results;
	//	string test_str;
	//	cout << "please input a word: ";
	//	while (cin >> test_str) {
	//		if (regex_search(test_str, results, r))
	//			cout << results.str() << " violates the rule " << endl;
	//		else
	//			cout << "it doesn't violate the rule" << endl;
	//		cout << "please input a word: ";
	//	}
	//}
	//catch (regex_error e) {
	//	cout << e.what() << "\ncode: " << e.code() << endl;
	//}
	//
	/*try {
		regex r4("[[:alnums:]]+\\.(cpp|cxx|cc)$", regex::icase);
	}
	catch (regex_error e) {
		cout << e.what() << "\ncode: " << e.code() << endl;
	}
	try {
		regex r5("[[:alnum:]]+\\.cpp|cxx|cc)$", regex::icase);
	}
	catch (regex_error e) {
		cout << e.what() << "\ncode: " << e.code() << endl;
	}
	try {
		regex r6("[[:alnum:]]++\\.(cpp|cxx|cc)$", regex::icase);
	}
	catch (regex_error e) {
		cout << e.what() << "\ncode: " << e.code() << endl;
	}*/
	/*
	练习：
	17.14：ok
	17.15：ok，好拗口的说法，违反："i在e之前，除非在c之后？"，是：i除非在c之后，否则必须在e之前！就是[^c]ei
	17.16：就是用这个，网上说输出匹配部分？
	*/
	cin >> a;
	return 0;
}
