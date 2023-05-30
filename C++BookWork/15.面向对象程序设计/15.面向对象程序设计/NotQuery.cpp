#include "NotQuery.h"


QueryResult NotQuery::eval(const TexTQuery &text) const
{
	// 得到line的集合
	auto result = query.eval(text);
	// 空
	auto ret_lines = make_shared<set<line_no>>();
	auto beg = result.begin(), end = result.end();
	auto sz = result.get_file()->size();
	for (size_t n = 0; n != sz; ++n)
	{
		// beg == end，代表中间出现的两端读完了，其它的都是没有出现的
		// *beg !=n, 因为是线性的，n >= *beg,所以必定会*beg == n为找到行，那么其它的都没有出现的
		if (beg == end || *beg != n)
			ret_lines->insert(n);
		else if (beg != end)
			++beg;// 读取集合中下一个搜寻的行号
	}
	return QueryResult(rep(), ret_lines, result.get_file());// left right指向同样的文件
}
//NotQuery::NotQuery()
//{
//}
//NotQuery::~NotQuery()
//{
//}
