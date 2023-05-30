#pragma once
#include <iostream>
#include "TexTQuery.h"
#include "QueryResult.h"
#include "Query.h"// 不能少，虽然firend class Query有声明但是需要完整定义吧？

using namespace std;

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
