#include "TexTQuery.h"
#include "QueryResult.h"


TexTQuery::TexTQuery(ifstream &is) :file(new vector<string>, DebugDelete()) {
//TexTQuery::TexTQuery(ifstream &is) :strblo() {
	string text;
	while (getline(is, text)) {
		file->push_back(text);
		//strblo.push_back(text);
		int n = file->size() - 1;//��ǰ�к�
		//int n = strblo.size() - 1;//��ǰ�к�
		istringstream line(text);
		string word;
		while (line >> word) {
			auto &lines = wm[word];//lines��һ�� shared_ptr<set<line_no>>
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
		//return QueryResult(sought, nodata, strblo.data);
	else
	{
		return QueryResult(sought, loc->second, file);
		//return QueryResult(sought, loc->second, strblo.data);
	}
}