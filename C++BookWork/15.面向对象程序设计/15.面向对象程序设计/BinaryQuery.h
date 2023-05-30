#pragma once
#include "Query_base.h"
#include "Query.h"
#include <string>

class BinaryQuery : public Query_base
{
protected:
	BinaryQuery(const Query &l, const Query &r,std::string s)
		:lhs(l),rhs(r),opSym(s){ }
	// Ã»ÓÐeval
	std::string rep() const  
	{ 
		cout << "BinaryQuery::rep()" << endl;
		std::string s = " ";
		/*std::string s2 = s + "(" + lhs.rep() + " "
			+ opSym + " "
			+ rhs.rep() + ")" + s;*/
		return s;
	}

	Query lhs, rhs;
	std::string opSym;
};

