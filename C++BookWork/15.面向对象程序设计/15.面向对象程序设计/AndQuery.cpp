#include "AndQuery.h"


QueryResult AndQuery::eval(const TexTQuery &text) const
{
	auto right = rhs.eval(text), left = lhs.eval(text);
	// 初始化一个类型
	auto ret_lines = make_shared<set<line_no>>();
	set_intersection(left.begin(), left.end(),
		right.begin(), right.end(),
		inserter(*ret_lines, ret_lines->begin()));
	// 返回一个新的queryreulst
	return QueryResult(rep(), ret_lines, left.get_file());// left right指向同样的文件
}
//AndQuery::AndQuery()
//{
//}
//
//
//AndQuery::~AndQuery()
//{
//}
