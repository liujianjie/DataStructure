#include "TexTQuery.h"
#include "QueryResult.h"


TexTQuery::TexTQuery(ifstream &is) :file(make_shared<StrVec>()) {
	string text;
	while (getline(is, text)) {
		file->push_back(text);
		int n = file->size() - 1;//当前行号
		istringstream line(text);
		string word;
		while (line >> word) {
			auto &lines = wm[word];//lines是一个shader_ptr
			if (!lines) {//第一次遇到这个单词的指针为空
				lines.reset(new set<line_no>);//分配一个新的set
			}
			lines->insert(n);
		}
	}
}
QueryResult TexTQuery::query(const string& sought) const
{
	// 若未找到 返回
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
	{
		return QueryResult(sought, loc->second, file);
	}
}