#ifndef TEXTQUERY_H_
#define TEXTQUERY_H_

#include <iostream>
#include <vector>
#include <memory>
#include <list>
#include <sstream>
#include <string>
#include <fstream>
#include <map>
#include <set>
#include "StrVec.h"
using namespace std;

class QueryResult;
class TexTQuery {
public:
	using line_no = vector<string>::size_type;
	TexTQuery(ifstream&);
	QueryResult query(const string&) const;
private:
	// 每一行的文本？
	//shared_ptr<vector<string>> file;
	shared_ptr<StrVec> file;
	map<string, shared_ptr<set<line_no>>> wm;
};


#endif // !TEXTQUERY_H_