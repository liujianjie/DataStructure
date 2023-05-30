#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <functional>
#include "TextQuerys.h"
using namespace std;

ostream &print(ostream& os, const TextQuerys::QueryResult &qr)
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
	ifstream ifs("15.9ÊäÈëÎÄ¼þ.txt");
	TextQuerys tq(ifs);
	string words;
	while (cin >> words && words != "q") {
		print(cout, tq.query(words)) << endl;
	}
	/*
	Á·Ï°£º
	19.20:ok
	*/
	cin >> a;
	return 0;
}
