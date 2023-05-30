#include "AllClass.h"

QueryResult OrQuery::eval(const TexTQuery &text) const
{
	auto right = rhs.eval(text), left = lhs.eval(text);
	// 先将左侧的行号保存
	auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
	// 再插入右侧的行号
	ret_lines->insert(right.begin(), right.end());
	// 返回一个新的queryreulst
	return QueryResult(rep(), ret_lines, left.get_file());// left right指向同样的文件
}
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

