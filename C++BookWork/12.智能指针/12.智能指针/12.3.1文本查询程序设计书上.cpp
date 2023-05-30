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
QueryResult�ǽ�Ҫ������ݵĶ���������Դ��TextQuery
����file��wm��set��
*/
int main()
{
	int a;

	//ifstream ifs("12.3.1�ı���ѯ�������.txt");
	ifstream ifs("15.9�����ļ�.txt");
	TexTQuery tq(ifs);
	string words;
	while (cin>>words && words != "q") {
		print(cout, tq.query(words)) << endl;
	}

	// ��ϰ
	// set��ѽ�����vector��һ�г��ֲ�ѯ�������Σ�������ͬһ�У�����

	//
	cin >> a;
	return 0;
}
