#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

/*
string流是向string操作
*/

// 练习8.1
istream& peightone(istream& i1)
{
	string v1;
	while (i1 >> v1 && !i1.eof()) {
		if (i1.bad()) {
			cerr << "run exception" << endl;
		}
		if (i1.fail()) {
			cerr << "Data wrong,please try again" << endl;
			i1.clear();//恢复
			i1.ignore(100, '\n');
			continue;
		}
		cout << v1 << endl;
	}
	cout << v1;// 最后一个也要打印出来
	i1.clear();
	return i1;
}

struct PersonInfo {
	string name;
	vector<string> phones;
};
int main()
{
	int a;
	string line, word;
	vector<PersonInfo> ve;

	ifstream if1("8.3string输入文件.txt");
	istringstream is1;// 这是练习8.11
	while (getline(if1,line)) {
		//istringstream is1(line);// 将line的数据放入is1中
		is1.str(line);// 将line拷贝到is1中。
		PersonInfo per;
		is1 >> per.name;
		while (is1 >> word) {
			per.phones.push_back(word);
		}
		ve.push_back(per);
		is1.clear();// 需要将is1恢复置位，因为读完了一次 要恢复
	}
	for (auto beg = ve.begin(); beg != ve.end(); ++beg) {
		PersonInfo psi = *beg;
		cout << psi.name << " ";
		for (auto beg2 = psi.phones.begin(); beg2 != psi.phones.end(); ++beg2) {
			cout << *beg2 << " ";
		}
		cout << endl;
	}
	string str2 = "need print data to control";
	istringstream iss2(str2);
	
	//iss2是一个字符串输入流，可以读取数据 用>>运算符
	string tempstr;
	while (iss2 >> tempstr) {
		cout << tempstr << " ";
	}
	cout << endl;

	string str3 = "need print data to control";
	istringstream iss3(str3);
	peightone(iss3);

	// 练习2
	vector<string> ve2;
	ifstream if2("8.10练习.txt");
	while (getline(if2, line)) {
		ve2.push_back(line);
	}
	for_each(ve2.begin(), ve2.end(),
		[](const string &s)->void { 
			istringstream iss3(s); 
			string str3;
			while (iss3 >> str3) {
				cout << str3<<" ";
			}
			cout << endl;
		});

	cin >> a;
	return 0;
}