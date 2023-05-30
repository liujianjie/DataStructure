#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

/*
string������string����
*/

// ��ϰ8.1
istream& peightone(istream& i1)
{
	string v1;
	while (i1 >> v1 && !i1.eof()) {
		if (i1.bad()) {
			cerr << "run exception" << endl;
		}
		if (i1.fail()) {
			cerr << "Data wrong,please try again" << endl;
			i1.clear();//�ָ�
			i1.ignore(100, '\n');
			continue;
		}
		cout << v1 << endl;
	}
	cout << v1;// ���һ��ҲҪ��ӡ����
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

	ifstream if1("8.3string�����ļ�.txt");
	istringstream is1;// ������ϰ8.11
	while (getline(if1,line)) {
		//istringstream is1(line);// ��line�����ݷ���is1��
		is1.str(line);// ��line������is1�С�
		PersonInfo per;
		is1 >> per.name;
		while (is1 >> word) {
			per.phones.push_back(word);
		}
		ve.push_back(per);
		is1.clear();// ��Ҫ��is1�ָ���λ����Ϊ������һ�� Ҫ�ָ�
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
	
	//iss2��һ���ַ��������������Զ�ȡ���� ��>>�����
	string tempstr;
	while (iss2 >> tempstr) {
		cout << tempstr << " ";
	}
	cout << endl;

	string str3 = "need print data to control";
	istringstream iss3(str3);
	peightone(iss3);

	// ��ϰ2
	vector<string> ve2;
	ifstream if2("8.10��ϰ.txt");
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