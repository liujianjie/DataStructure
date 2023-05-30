#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>
using namespace std;

struct PersonInfo {
	string name;
	vector<string> phones;
};
bool valid(const string& str) 
{
	for (string::size_type beg = 0; beg != str.size(); ++beg) {
		if (isalpha(str[beg])) {
			return false;
		}
	}
	return true;
}
// 8.3.2string����ļ�.txt
int main()
{
	int a;
	ofstream ifs1("8.3.2string����ļ�.txt");
	vector<PersonInfo> ve1;
	ve1.push_back(PersonInfo{ "morgan",{"23123 112312312"} });
	ve1.push_back(PersonInfo{ "drew",{ "adf1231232 12312 adsfa12312 sdaf12" } });
	ve1.push_back(PersonInfo{ "lee",{ "12912daf91232 234adfa23324 423234" } });
	ve1.push_back(PersonInfo{ "lee2",{ "12234" } });
	for (const auto &entry : ve1) {
		ostringstream formatted, badNums;
		for (const auto &nums : entry.phones) {
			if (!valid(nums)) {
				badNums << " " << nums;
			}
			else {
				formatted << " " << nums;
			}
		}
		if (badNums.str().empty()) {// û������
			ifs1 << entry.name << " " << formatted.str() << endl;
		}
		else {
			cout << "error:" << badNums.str() << endl;
		}
	}
	cout << "----------" << endl;
	// ��ϰ
	//
	ifstream ifs2("8.3.2�绰��������.txt");
	string line,name,phone;
	while (getline(ifs2, line)) {
		istringstream is1(line);
		ostringstream formatted, badNums;
		is1 >> name;
		while(is1 >> phone) {
			if (!valid(phone)) {
				badNums << " " << phone;
			}
			else {
				formatted << " " << phone;
			}
		}
		if (badNums.str().empty()) {// û������
			cout << name << " " << formatted.str() << endl;
		}
		else {
			cerr << "error:" << badNums.str() << endl;
		}
	}
	// 1.Ӧ�ò���ı�stringֵ���淶���⡣
	cin >> a;
	return 0;
}