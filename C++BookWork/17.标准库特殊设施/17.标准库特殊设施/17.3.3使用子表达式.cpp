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


bool valid(const smatch& m)
{
	if (m[1].matched)
	{
		return m[3].matched
			&& (m[4].matched == 0 || m[4].str() == " ");
	}
	else {
		return !m[3].matched
			&&m[4].str() == m[6].str();// �ָ���������ͬ
	}
}

bool valid3(const smatch& m)
{
	if (m[2].matched)
	{
		return m[3].matched;
	}
	else {
		if (m[2].str() != "") {
			return false;//ֱ��GG
		}
		return m[1].matched;// ��Ҫ�յ�m[2]
	}
}

// û��-���ӷ���ֻ�пո�
bool valid22(const smatch& m)
{
	if (m[1].matched)
	{
		return m[3].matched;
	}
	else {
		return !m[3].matched;
	}
}
int main()
{
	int a;
	string pattern1 = "[[:alnum:]]+\\.(cpp|cxx|cc)$";
	regex r0(pattern1);
	smatch results1;// ���
	string test_str1 = "foo.cpp";
	if (regex_search(test_str1, results1, r0)) {
		cout << results1.str(0) << endl;
		cout << results1.str(1) << endl;
		cout << results1.str(2) << endl;
	}
	//for (sregex_iterator it(test_str1.begin(), test_str1.end(), r1), end_it;
	//	it != end_it; ++it) {
	//	cout << it->str() << endl;
	//	cout << it->str(2) << endl;
	//	cout << it->str(1) << endl;
	//}
	//string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
	//regex r1(phone);
	//smatch m1;
	//string s1;
	//while (getline(cin,s1)) {
	//	for (sregex_iterator it(s1.begin(), s1.end(), r1), end_it;
	//		it != end_it; ++it)
	//	{
	//		if (valid(*it)) {
	//			cout << "valid: " << it->str() << endl;
	//		}
	//		else
	//		{
	//			cout << "not valid: " << it->str() << endl;
	//		}
	//	}
	//}

	// 21��
	string phone1 = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
	regex r2(phone1);
	ifstream ifs2("8.3.2�绰��������.txt");
	string line, name, phone;
	while (getline(ifs2, line)) {
		istringstream is1(line);
		ostringstream formatted, badNums;
		is1 >> name;
		getline(is1, line);
		for (sregex_iterator it(line.begin(), line.end(), r2), end_it;
			it != end_it; ++it)
		{
			if (valid(*it)) {
				formatted << " " << it->str();
			}
			else
			{
				badNums << " " << it->str();
			}
		}
		if (!formatted.str().empty()) {// û������
			cout << name << " " << formatted.str() << endl;
		}
		if (!badNums.str().empty()) {
			cerr << "error:" << badNums.str() << endl;
		}
	}

	// 22
	//string phone2 = "(\\()?(\\d{3})(\\))?([ ]*)?(\\d{3})([ ]*)?(\\d{4})([ ]*)?";
	//regex r2(phone2);
	//ifstream ifs2("8.3.2�绰��������22��.txt");
	//string line, name, phone;
	//while (getline(ifs2, line)) {
	//	istringstream is1(line);
	//	ostringstream formatted, badNums;
	//	is1 >> name;
	//	getline(is1, line);
	//	for (sregex_iterator it(line.begin(), line.end(), r2), end_it;
	//		it != end_it; ++it)
	//	{
	//		if (valid22(*it)) {
	//			formatted << " " << it->str();
	//		}
	//		else
	//		{
	//			badNums << " " << it->str();
	//		}
	//	}
	//	if (!formatted.str().empty()) {// û������
	//		cout << name << " " << formatted.str() << endl;
	//	}
	//	if (!badNums.str().empty()) {
	//		cerr << "error:" << badNums.str() << endl;
	//	}
	//}

	// �Լ�д�� 23�� 
	/*string phone3 = "(\\d{5})([-])?(\\d{4})?";
	regex r3(phone3);
	smatch m3;
	string s3;
	while (getline(cin,s3)) {
		for (sregex_iterator it(s3.begin(), s3.end(), r3), end_it;
			it != end_it; ++it)
		{
			if (valid3(*it)) {
				cout << "valid: " << it->str() << endl;
			}
			else
			{
				cout << "not valid: " << it->str() << endl;
			}
		}
	}*/
	/*
	17.19: ���û��ҲҪƥ��m[6]
	17.20��ok
	17.21: ok
	17.22: 
	һ�ж������ ������sregex_iterator	��������Ĭ�϶��Ƿ�������ģ������Ͼͺ����ˣ���ϸ���Ƿ�ƥ��
	����ˣ�
	string phone2 = "(\\()?(\\d{3})(\\))?([ ]*)?(\\d{3})([ ]*)?(\\d{4})([ ]*)?";��ֻ�ſո񣬾Ͳ����ж�-���ӷ�ƥ����
	ԭ����
	��ok,�ý�����������3������֮����ö���ַ�����Ҫ��һ�еĺ����ж������[ ]*?�𣬲�֪����ô����
	17.23:ok
	*/
	cin >> a;
	return 0;
}
