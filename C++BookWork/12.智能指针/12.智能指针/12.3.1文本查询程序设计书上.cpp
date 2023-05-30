#include <iostream>
#include <vector>
#include <memory>
#include <list>
#include "StrBlob.h"
#include "StrBloPtr.h"
#include <sstream>
#include <string>
#include <fstream>
#include <map>
#include <set>
#include "TexTQuery.h"
#include "QueryResult.h"

using namespace std;

ostream &print(ostream& os,const QueryResult &qr)
{
	os << qr.sougth << " occurs " << qr.lines->size() << " "
		" times " << endl;
	for (auto num : *qr.lines) {
		os << "\t(line " << num + 1 << ")"
			<< *(qr.file->begin() + num) << endl;
	}
	return os;
}
/*
QueryResult是将要输出数据的对象，数据来源于TextQuery
共享file，wm的set行
*/
int main()
{
	int a;

	//ifstream ifs("12.3.1文本查询程序设计.txt");
	ifstream ifs("15.9输入文件.txt");
	TexTQuery tq(ifs);
	string words;
	while (cin>>words && words != "q") {
		print(cout, tq.query(words)) << endl;
	}

	// 练习
	// set好呀，如果vector若一行出现查询单词两次，则会放入同一行，不好

	//
	cin >> a;
	return 0;
}
