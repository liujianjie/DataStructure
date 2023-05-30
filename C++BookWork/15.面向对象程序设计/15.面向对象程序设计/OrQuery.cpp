#include "OrQuery.h"

QueryResult OrQuery::eval(const TexTQuery &text) const
{
	auto right = rhs.eval(text), left = lhs.eval(text);
	// 先将左侧的行号保存
	auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
	// 再插入右侧的行号
	ret_lines->insert(right.begin(),right.end());
	// 返回一个新的queryreulst
	return QueryResult(rep(), ret_lines, left.get_file());// left right指向同样的文件
}


