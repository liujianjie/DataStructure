#include "NotQuery.h"


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
//NotQuery::NotQuery()
//{
//}
//NotQuery::~NotQuery()
//{
//}
