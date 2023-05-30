#include "OrQuery.h"

QueryResult OrQuery::eval(const TexTQuery &text) const
{
	auto right = rhs.eval(text), left = lhs.eval(text);
	// �Ƚ������кű���
	auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
	// �ٲ����Ҳ���к�
	ret_lines->insert(right.begin(),right.end());
	// ����һ���µ�queryreulst
	return QueryResult(rep(), ret_lines, left.get_file());// left rightָ��ͬ�����ļ�
}


