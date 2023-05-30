#include <iostream>
#include "Query.h"
#include "QueryResult.h"

using namespace std;
/*
OrQuery::eval
1.��������������󣬵���eval�õ����Ĳ�ѯ�����Query.eval�����q.eval����ã��õ�QueryResult�����������ֵ��к�
2.ͷ�ļ��������� �ܶ����⡣

*/

ostream &print(ostream& os, const QueryResult &qr)
{
	os << qr.sougth << " occurs " << qr.lines->size() << " "
		" times " << endl;
	for (auto num : *qr.lines) {
		os << "\t(line " << num + 1 << ")"
			<< *(qr.file->begin() + num) << endl;
	}
	return os;
}
int main()
{
	int a;
	Query q = Query("fiery") & Query("bird") | Query("wind");
	cout << q;

	// ��ϰ
	/*

	*/
	cin >> a;
	return 0;
}
