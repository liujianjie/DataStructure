#pragma once
#include <memory>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

class TextQuerys {
	
public:
	class QueryResult;
public:
	using line_no = vector<string>::size_type;
	TextQuerys(ifstream&);
	QueryResult query(const string&) const;
private:
	// 每一行的文本？
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<line_no>>> wm;
	int val1 = 2;
};

class TextQuerys::QueryResult {
	friend ostream &print(ostream& os, const TextQuerys::QueryResult &qr);
public:
	QueryResult() = default;
	QueryResult(string s, shared_ptr <set<line_no>> p,
		shared_ptr <vector<string>> f);
	// 犯错了，是lines行号的begin
	set<TextQuerys::line_no>::iterator begin() {
		return lines->begin();
	}
	set<TextQuerys::line_no>::iterator end() {
		return lines->end();
	}
	shared_ptr<vector<string>>& get_file()
	{
		return file;
	}
	//void printval2() {
	//	cout << val1 << endl;
	//}
private:
	string sougth;
	shared_ptr<set<line_no>> lines;
	shared_ptr<vector<string>> file;

	static int static_men;
};