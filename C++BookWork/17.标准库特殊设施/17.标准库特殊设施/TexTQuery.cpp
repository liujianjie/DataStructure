#include "TexTQuery.h"
#include "QueryResult.h"


TexTQuery::TexTQuery(ifstream &is) :file(new vector<string>) {
	string text;
	while (getline(is, text)) {
		file->push_back(text);
		int n = file->size() - 1;//��ǰ�к�
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
TexTQuery::TUP TexTQuery::query(const string& sought) const
{
	// ��δ�ҵ� ����
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return make_tuple(sought, nodata, file);
	else
	{
		return make_tuple(sought, loc->second, file);
	}
}