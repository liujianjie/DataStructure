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
// һ��ʼ������
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
			auto beg2 = beg;// �Է�����
			for (auto j = oldVal.begin(); j != oldVal.end() && beg2 != s.end(); j++,beg2++) {
				s2 += *beg2;
			}
			if (s2 == oldVal) {
				s.erase(pos,oldVal.length());
				beg = s.insert(beg, newVal.begin(), newVal.end());// ����������ǰ��������ֻ��Ҫ��beg=����ѭ��������++
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
			auto beg2 = beg;// �Է�����
			for (auto j = oldVal.begin(); j != oldVal.end() && beg2 != s.end(); j++, beg2++) {
				s2 += *beg2;
			}
			if (s2 == oldVal) {
				s.replace(pos, oldVal.length(), newVal);
				//s.erase(pos, oldVal.length());
				//beg = s.insert(beg, newVal.begin(), newVal.end());// ����������ǰ��������ֻ��Ҫ��beg=����ѭ��������++
			}
		}
	}
}
void pninefourfive(string &s, string &pre, string &after)
{
	// ʹ�õ����汾��insert��argsҲҪֻʹ�õ�����
	s.insert(s.begin(), pre.begin(), pre.end());
	s.append(after);
}
void pninefoursix(string &s, string &pre, string &after)
{
	s.insert(0, pre);
	s.insert(s.size(), after);// ֮ǰλ��
}
int main()
{
	int a;
	string teststr("thasdfasdfthlll");
	teststr.erase(10,2);
	teststr.insert(10, "thong");// insert ��pos֮ǰ��λ�����Ԫ��

	cout << teststr << endl;
	// ���ɾ����string�Լ��Ĳ��� ���±�
	string s1("12321312");
	s1.insert(s1.size(), 5, '!');
	cout << s1 << endl;
	s1.erase(s1.size() - 5, 5);
	cout << s1 << endl;
	// ��֧�ֽ���c����ַ������insert��assign
	const char *cp = "Stately, plump Buck";
	s1.assign(cp, 7);// ����7���ַ�
	cout << s1 << endl;
	s1.insert(s1.size(), cp + 7);// ����,plump������ֱ��ĩβ
	cout << s1 << endl;
	// Ҳ������string����ȡ
	string s2 = "some string";
	string s3 = "some other string";
	//s2.insert(0, s3);//
	cout << s2 << endl;
	s2.insert(0, s3, 4, 8);// ����ָ��s3��С��ͼ���
	cout << s2 << endl;
	
	// append ��repalce
	string s4("C++ Primer"), s5 = s4;
	s4.insert(s4.size(), "4th Ed.");
	s5.append("4th Ed.");

	s4.erase(11,3);
	s4.insert(11, "5th");

	// ��λ��11��ʼ��ɾ��3���ַ�������5th
	s5.replace(11, 3, "5th");//���Բ��Եȣ��ַ��� ����3
	s4.replace(11, 3, "Fifth");
	// ��ϰ
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