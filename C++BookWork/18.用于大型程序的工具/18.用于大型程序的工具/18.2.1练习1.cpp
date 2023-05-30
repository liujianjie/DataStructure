#include <iostream>
#include <vector>
#include <fstream>
#include "chapter15.h"
#include "chapter15_cpp.h"
using namespace std;

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

	// 
	ifstream ifs("15.9�����ļ�.txt");
	TexTQuery te(ifs);

	using chapter15::Query;
	Query q3 = Query("Daddy");
	print(cout, q3.eval(te));

	/*
	��ϰ��
	18.12:

	18.13:�붨�徲̬�������ڵĳ�Աʱ��

	18.14:
	*/
	cin >> a;
	return 0;
}
