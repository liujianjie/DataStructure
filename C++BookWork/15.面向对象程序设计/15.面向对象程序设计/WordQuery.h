#pragma once
#include "Query_base.h"
//#include "WordQuery.h"
#include "Query.h"
#include <string>

class WordQuery :public Query_base
{
	friend class Query;
	WordQuery(const std::string &s) :query_word(s) {}
	// 
	QueryResult eval(const TexTQuery &t) const 
	{
		return t.query(query_word);
	}
	std::string rep() const   
	{ 
		cout << "WordQuery::rep()" << endl;
		return query_word; 
	}
	std::string query_word;
};

