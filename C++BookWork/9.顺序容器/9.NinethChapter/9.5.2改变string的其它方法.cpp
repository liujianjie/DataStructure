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
// 一开始的做法
//for (auto i = 0; i < s.length(); ++i) {
//	if (s[i] == oldVal[0]) {
//		string s2;
//		for (int j = 0; j < oldVal.length() && j + i < s.length(); j++) {
//			s2 += s[j + i];
//		}
//		if (s2 == oldVal) {
//			s.erase(i, oldVal.length());
//			s.insert(i, newVal);
//		}
//	}
//}
void pninefourthree(string &s, string &oldVal, string &newVal) 
{
	int pos = 0;
	for (auto beg = s.begin(); beg != s.end(); ++beg,++pos) {
		if (*beg == oldVal[0]) {
			string s2;
			auto beg2 = beg;// 以防到底
			for (auto j = oldVal.begin(); j != oldVal.end() && beg2 != s.end(); j++,beg2++) {
				s2 += *beg2;
			}
			if (s2 == oldVal) {
				s.erase(pos,oldVal.length());
				beg = s.insert(beg, newVal.begin(), newVal.end());// 不用跳过当前迭代器，只需要，beg=，在循环体外有++
			}
		}
	}
}
void pninefourfour(string &s, string &oldVal, string &newVal)
{
	int pos = 0;
	for (auto beg = s.begin(); beg != s.end(); ++beg, ++pos) {
		if (*beg == oldVal[0]) {
			string s2;
			auto beg2 = beg;// 以防到底
			for (auto j = oldVal.begin(); j != oldVal.end() && beg2 != s.end(); j++, beg2++) {
				s2 += *beg2;
			}
			if (s2 == oldVal) {
				s.replace(pos, oldVal.length(), newVal);
				//s.erase(pos, oldVal.length());
				//beg = s.insert(beg, newVal.begin(), newVal.end());// 不用跳过当前迭代器，只需要，beg=，在循环体外有++
			}
		}
	}
}
void pninefourfive(string &s, string &pre, string &after)
{
	// 使用迭代版本的insert，args也要只使用迭代器
	s.insert(s.begin(), pre.begin(), pre.end());
	s.append(after);
}
void pninefoursix(string &s, string &pre, string &after)
{
	s.insert(0, pre);
	s.insert(s.size(), after);// 之前位置
}
int main()
{
	int a;
	string teststr("thasdfasdfthlll");
	teststr.erase(10,2);
	teststr.insert(10, "thong");// insert 是pos之前的位置添加元素

	cout << teststr << endl;
	// 添加删除，string自己的操作 用下标
	string s1("12321312");
	s1.insert(s1.size(), 5, '!');
	cout << s1 << endl;
	s1.erase(s1.size() - 5, 5);
	cout << s1 << endl;
	// 还支持接收c风格字符数组的insert和assign
	const char *cp = "Stately, plump Buck";
	s1.assign(cp, 7);// 复制7个字符
	cout << s1 << endl;
	s1.insert(s1.size(), cp + 7);// 加上,plump。。。直至末尾
	cout << s1 << endl;
	// 也可以用string来获取
	string s2 = "some string";
	string s3 = "some other string";
	//s2.insert(0, s3);//
	cout << s2 << endl;
	s2.insert(0, s3, 4, 8);// 后面指定s3的小标和几个
	cout << s2 << endl;
	
	// append 和repalce
	string s4("C++ Primer"), s5 = s4;
	s4.insert(s4.size(), "4th Ed.");
	s5.append("4th Ed.");

	s4.erase(11,3);
	s4.insert(11, "5th");

	// 从位置11开始，删除3个字符并插入5th
	s5.replace(11, 3, "5th");//可以不对等，字符串 不等3
	s4.replace(11, 3, "Fifth");
	// 练习
	string s6("thasdfastdfthllt");
	pninefourthree(s6,string("th"),string("thong"));
	cout << s6 << endl;
	string s7("thasdfastdfthllt");
	pninefourfour(s7, string("th"), string("thong"));
	cout << s7 << endl;
	
	string s8("liujianjie");
	string sprev("Mr.");
	string safter("Jr.");
	pninefourfive(s8, sprev, safter);
	cout << s8 << endl;

	string s9("liujianjie");
	pninefoursix(s9, sprev, safter);
	cout << s9 << endl;
	cin >> a;
	return 0;
}