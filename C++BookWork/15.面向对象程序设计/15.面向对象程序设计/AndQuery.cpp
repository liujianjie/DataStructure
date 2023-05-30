#include "AndQuery.h"


QueryResult AndQuery::eval(const TexTQuery &text) const
{
	auto right = rhs.eval(text), left = lhs.eval(text);
	// ��ʼ��һ������
	auto ret_lines = make_shared<set<line_no>>();
	set_intersection(left.begin(), left.end(),
		right.begin(), right.end(),
		inserter(*ret_lines, ret_lines->begin()));
	// ����һ���µ�queryreulst
	return QueryResult(rep(), ret_lines, left.get_file());// left rightָ��ͬ�����ļ�
}
//AndQuery::AndQuery()
//{
//}
//
//
//AndQuery::~AndQuery()
//{
//}
