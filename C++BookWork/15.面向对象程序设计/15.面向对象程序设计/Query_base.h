#pragma once
#include <iostream>
#include "TexTQuery.h"
#include "QueryResult.h"
#include "Query.h"// �����٣���Ȼfirend class Query������������Ҫ��������ɣ�

using namespace std;

class Query_base
{
	friend class Query;
protected:
	using line_no = TexTQuery::line_no;
	virtual ~Query_base() = default;
private:
	// eval�����뵱ǰQueryƥ���QueryResult
	virtual QueryResult eval(const TexTQuery&) const = 0;
	virtual std::string rep() const = 0;
};
