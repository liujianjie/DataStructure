#pragma once
#include <algorithm>
#include <iterator>
#include <string>
#include "QueryResult.h"
#include "TexTQuery.h"

namespace chapter15 {
	class Query_base
	{
		friend class Query;
	protected:
		using line_no = TexTQuery::line_no;
		virtual ~Query_base() = default;
	private:
		// eval返回与当前Query匹配的QueryResult
		virtual QueryResult eval(const TexTQuery&) const = 0;
		virtual std::string rep() const = 0;
	};

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

	class WordQuery :public Query_base
	{
		friend class Query;
		WordQuery(const std::string &s) :query_word(s)
		{
			//cout << "WordQuery构造函数:" << query_word << endl;
		}
		// 
		QueryResult eval(const TexTQuery &t) const
		{
			return t.query(query_word);
		}
		std::string rep() const
		{
			//cout << "WordQuery::rep(" << query_word <<")"<< endl;
			return query_word;
		}
		std::string query_word;
	};

	class NotQuery : public Query_base
	{
		friend Query operator~(const Query &);

		NotQuery(const Query &q) :query(q)
		{
			//cout << "NotQuery构造函数:" << "" << endl;
		}

		QueryResult eval(const TexTQuery &t) const;
		std::string rep() const
		{
			//cout << "NotQuery::rep()" << endl;
			std::string s = "~(" + query.rep() + ")";
			return s;
		}
		Query query;
	};

	class BinaryQuery : public Query_base
	{
	protected:
		BinaryQuery(const Query &l, const Query &r, std::string s)
			:lhs(l), rhs(r), opSym(s)
		{
			//cout << "BinaryQuery构造函数:" << opSym << endl;
		}
		// 没有eval
		std::string rep() const
		{
			//cout << "BinaryQuery::rep(" << opSym << ")" << endl;
			std::string s = "(" + lhs.rep() + " "
				+ opSym + " "
				+ rhs.rep() + ")";
			return s;
		}
		Query lhs, rhs;
		std::string opSym;
	};

	class AndQuery :public BinaryQuery
	{
		friend Query operator&(const Query&, const Query&);
		AndQuery(const Query &left, const Query &right) :
			BinaryQuery(left, right, "&")
		{
			//cout << "AndQuery构造函数:" << "&"<< endl;
		}
		QueryResult eval(const TexTQuery &t) const;
	};

	class OrQuery : public BinaryQuery
	{
		friend Query operator|(const Query&, const Query&);
		OrQuery(const Query &left, const Query &right) :
			BinaryQuery(left, right, "|")
		{
			//cout << "OrQuery构造函数:" << "|" << endl;
		}
		QueryResult eval(const TexTQuery &t) const;
	};

}