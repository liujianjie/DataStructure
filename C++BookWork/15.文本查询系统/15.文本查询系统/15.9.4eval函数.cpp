#include <iostream>
#include "QueryResult.h"
#include "AllClass.h"

using namespace std;
/*
OrQuery::eval
1.对于两个运算对象，调用eval得到它的查询结果。Query.eval会调用q.eval虚调用，得到QueryResult是运算对象出现的行号
2.再通过一些操作生成新的QueryResult对象
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

	// 练习
	/*

	*/
	cin >> a;
	return 0;
}
