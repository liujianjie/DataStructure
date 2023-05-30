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
	//string pattern("[^c]ei");// �����ַ�c֮����ַ���ei
	////�������ei�ĵ��ʣ��ո����
	//pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	//regex r(pattern);// ����ģʽ
	//smatch results;// ���
	//string test_str = "receipt freind theif receipt";
	//if (regex_search(test_str, results, r))
	//	cout << results.str() << endl;

	// ģʽ
	// һ��������ĸ�������ַ����һ��'.' �ٽ�cpp �� cxx cc
	string pattern2 = "[[:alnum:]]+\\.(cpp|cxx|cc)$";// ��һ��\ȥ��c+���⣬�ڶ���\ȥ��������ʽ.�����⺯��
	regex r2(pattern2,regex::icase);// ����ģʽ
	smatch results2;// ���
	string test_str2 = "adsf you.CPP";
	if (regex_search(test_str2, results2, r2))
		cout << results2.str() << endl;

	try {
		regex r3("[[:alnum:]+\\.(cpp|cxx|cc)$", regex::icase);
	}
	catch (regex_error e) {
		cout << e.what() << "\ncode: " << e.code() << endl;
	}

	string pattern3 = "[[:alnum:]]+\\.(cpp|cxx|cc)$";// ��һ��\ȥ��c+���⣬�ڶ���\ȥ��������ʽ.�����⺯��
	regex r3(pattern3, regex::icase);// ����ģʽ
	//smatch results3;// ���// ��������Ϊchar*,������ƥ�䣬��Ҫ��cmatch
	cmatch results3;
	if (regex_search("adsf you.CPP", results3, r3))
		cout << results3.str() << endl;

	// 17.16
	//string pattern4("i[^e]|[^e]c");
	string pattern4("[^c]ei");
	pattern4 = "[[:alpha:]]*" + pattern4 + "[[:alpha:]]*";
	regex r4(pattern4);// ����ģʽ
	smatch results4;// ���
	string test_str4;
	cout << "press your word" << endl;
	while (cin >> test_str4) {
		if (regex_search(test_str4, results4, r4)) {
			cout << results4.str()<<"�ҵ���" << endl;
		}
		else {
			cout << "��Υ��" << endl;
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
	��ϰ��
	17.14��ok
	17.15��ok�����ֿڵ�˵����Υ����"i��e֮ǰ��������c֮��"���ǣ�i������c֮�󣬷��������e֮ǰ������[^c]ei
	17.16�����������������˵���ƥ�䲿�֣�
	*/
	cin >> a;
	return 0;
}
