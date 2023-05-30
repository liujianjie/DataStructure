#include "TexTQuery.h"
#include "QueryResult.h"


TexTQuery::TexTQuery(ifstream &is) :file(make_shared<StrVec>()) {
	string text;
	while (getline(is, text)) {
		file->push_back(text);
		int n = file->size() - 1;//��ǰ�к�
		istringstream line(text);
		string word;
		while (line >> word) {
			auto &lines = wm[word];//lines��һ��shader_ptr
			if (!lines) {//��һ������������ʵ�ָ��Ϊ��
				lines.reset(new set<line_no>);//����һ���µ�set
			}
			lines->insert(n);
		}
	}
}
QueryResult TexTQuery::query(const string& sought) const
{
	// ��δ�ҵ� ����
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
	{
		return QueryResult(sought, loc->second, file);
	}
}