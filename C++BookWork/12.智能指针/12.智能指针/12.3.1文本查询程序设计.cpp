#include <iostream>
#include <vector>
#include <memory>
#include <list>
#include "Sales_data.h"
#include "StrBlob.h"
#include "StrBloPtr.h"
#include <sstream>
#include <string>
#include <fstream>
#include <map>
#include <set>

using namespace std;

class TextQuery {
public:
	void buildMap(string ifsname);
	void QueryWords(string &words);
private:
	// ÿһ�е��ı���
	vector<string> linesve;
	map<string, set<int>> savemap;
};
void TextQuery::QueryWords(string &words)
{
	auto it1 = savemap.find(words);
	string strline;
	if (it1 != savemap.end()) {
		auto &set = savemap[words];
		cout << words << " occurs " << set.size() << "times" << endl;
		for (auto li : set) {
			strline = linesve[li - 1];
			cout << "\t(line " << li << " )" << strline << endl;
		}
	}
	else {
		cout << "���ʲ������ļ���" << endl;
	}
}
void TextQuery::buildMap(string ifsname)
{
	ifstream ifs1(ifsname);
	string line;
	string words;
	int lineint = 1;
	while (getline(ifs1,line)) {
		linesve.push_back(line);
		istringstream is(line);
		while (is>>words) {
			// ��ȡ�治����
			auto &setget = savemap[words];
			if (!setget.size()) {// Ϊ0����û�����ݣ���Ҫ����
				set<int> se{ lineint };
				savemap[words] = se;
			}
			else {
				setget.insert(lineint);
			}
		}
		++lineint;
	}
}
/*
�Լ�д�ģ����Ǻܺã�û�кܺõ������
*/
int main()
{
	int a;

	/*map<string, set<int>> savemap;
	auto &sets = savemap["1"];
	cout << sets.size() << endl;*/

	TextQuery tq1;
	tq1.buildMap("12.3.1�ı���ѯ�������.txt");
	string words;
	while (cin>>words) {
		tq1.QueryWords(words);
	}
	cin >> a;
	return 0;
}
