#pragma once
#include <string>
#include <memory>
#include "QueryResult.h"
#include "TexTQuery.h"
#include "Query_base.h"
#include "WordQuery.h"
#include "NotQuery.h"
#include "AndQuery.h"
#include "OrQuery.h"

using namespace std;
class Query
{
	friend Query operator~(const Query &);
	friend Query operator|(const Query &, const Query &);
	friend Query operator&(const Query &, const Query &);
public:
	Query() = default;

	Query(const std::string&);
	QueryResult eval(const TexTQuery &t)const 
	{
		return q->eval(t);
	}
	std::string rep() const 
	{ 
		return q->rep(); 
	}
private:
	Query(std::shared_ptr<Query_base> query) :q(query) { }
	std::shared_ptr<Query_base> q;
};

inline
Query::Query(const std::string &s) :
	q(new WordQuery(s))
{
}
inline
std::ostream& operator<<(std::ostream &os, const Query &query)
{
	return os << query.rep();
}
inline
Query operator~(const Query &operand)
{
	return std::shared_ptr<Query_base>(new NotQuery(operand));
}
inline
Query operator&(const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new AndQuery(lhs,rhs));
}
inline
Query operator|(const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}
