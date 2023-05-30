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
#include "StrVec.h"

using namespace std;
class QueryResult {
	friend ostream &print(ostream& os, const QueryResult &qr);
public:
	/*QueryResult(string s, shared_ptr <set<TexTQuery::line_no>> p,
		shared_ptr <vector<string>> f) :
		sougth(s), lines(p), file(f)
	{
	}*/
	QueryResult(string s, shared_ptr <set<TexTQuery::line_no>> p,
		shared_ptr <StrVec> f) :
		sougth(s), lines(p), file(f)
	{
	}
	//vector<string>::iterator begin() {
	//	return file->begin();
	//}
	//vector<string>::iterator end() {
	//	return file->end();
	//}
	// ÐÐºÅµÄµü´úÆ÷
	set<TexTQuery::line_no>::iterator begin() {
		return lines->begin();
	}
	set<TexTQuery::line_no>::iterator end() {
		return lines->end();
	}
private:
	string sougth;
	shared_ptr<set<TexTQuery::line_no>> lines;
	//shared_ptr<vector<string>> file;
	shared_ptr<StrVec> file;
};

#endif // !QUERYRESULT_H_