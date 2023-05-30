#pragma once
#include "BinaryQuery.h"
#include "QueryResult.h"
#include "Query.h"
#include "TexTQuery.h"

class OrQuery : public BinaryQuery
{
	friend Query operator|(const Query&, const Query&);
	OrQuery(const Query &left, const Query &right) :
		BinaryQuery(left, right, "|") {}
	QueryResult eval(const TexTQuery &t) const;
};

