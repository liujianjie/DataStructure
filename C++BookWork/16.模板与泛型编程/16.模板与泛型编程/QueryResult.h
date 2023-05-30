#ifndef QUERYRESULT_H_
#define QUERYRESULT_H_

#include <iostream>
#include <vector>
#include <memory>
#include <list>
#include <sstream>
#include <string>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>
#include "TexTQuery.h"

using namespace std;
class QueryResult {
	friend ostream &print(ostream& os, const QueryResult &qr);
public:
	QueryResult(string s, shared_ptr <set<TexTQuery::line_no>> p,
		shared_ptr <vector<string>> f) :
		sougth(s), lines(p), file(f)
	{

	}
	//vector<string>::iterator begin() {
	//	return file->begin();
	//}
	//vector<string>::iterator end() {
	//	return file->end();
	//}
private:
	string sougth;
	shared_ptr<set<TexTQuery::line_no>> lines;
	shared_ptr<vector<string>> file;
};




#endif // !QUERYRESULT_H_