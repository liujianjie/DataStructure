#include "AllClass.h"

QueryResult OrQuery::eval(const TexTQuery &text) const
{
	auto right = rhs.eval(text), left = lhs.eval(text);
	// �Ƚ������кű���
	auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
	// �ٲ����Ҳ���к�
	ret_lines->insert(right.begin(), right.end());
	// ����һ���µ�queryreulst
	return QueryResult(rep(), ret_lines, left.get_file());// left rightָ��ͬ�����ļ�
}
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

QueryResult NotQuery::eval(const TexTQuery &text) const
{
	// �õ�line�ļ���
	auto result = query.eval(text);
	// ��
	auto ret_lines = make_shared<set<line_no>>();
	auto beg = result.begin(), end = result.end();
	auto sz = result.get_file()->size();
	for (size_t n = 0; n != sz; ++n)
	{
		// beg == end�������м���ֵ����˶����ˣ������Ķ���û�г��ֵ�
		// *beg !=n, ��Ϊ�����Եģ�n >= *beg,���Աض���*beg == nΪ�ҵ��У���ô�����Ķ�û�г��ֵ�
		if (beg == end || *beg != n)
			ret_lines->insert(n);
		else if (beg != end)
			++beg;// ��ȡ��������һ����Ѱ���к�
	}
	return QueryResult(rep(), ret_lines, result.get_file());// left rightָ��ͬ�����ļ�
}

