#pragma once
#include "Query_base.h"
#include "Query.h"
#include <string>

class NotQuery : public Query_base
{
	friend Query operator~(const Query &);

	NotQuery(const Query &q) :query(q) {}

	QueryResult eval(const TexTQuery &t) const;
	std::string rep() const  
	{ 
		cout << "NotQuery::rep()" << endl;
		std::string s = " ";
		std::string s2 = s+"~(" + query.rep() + ")"+s;
		return s2;
	}
	Query query;
};


