#include <iostream>
#include <vector>
#include <tuple>
#include <list>
#include "TexTQuery.h"

using namespace std;

// tuple第一个不能传引用，因为可能局部变量会销毁。
ostream &print(ostream& os, TexTQuery::TUP tup)
{
	os << get<0>(tup) << " occurs " << get<1>(tup)->size() << " "
		" times " << endl;
	for (auto num : *get<1>(tup)) {
		os << "\t(line " << num + 1 << ")"
			<< *(get<2>(tup)->begin() + num) << endl;
	}
	return os;
}

string& testr(string &s1) 
{
	return s1;
}
int main()
{
	int a;

	string st = "aad";
	string s3 = testr(st);
	cout << s3 << endl;
	// 可以是引用吗
	string s1 = "asdf";
	string &s2 = s1;
	tuple<const string&, string> tu1{ s2,"sfa" };
	cout << (get<0>(tu1)) << endl;


	tuple<size_t, size_t, size_t> threeD;
	tuple<string, vector<double>, int, list<int>>
		someVal("cons", { 3.12,32 }, 12, { 4,3,12 });

	// explicit,14又变了？
	tuple<size_t, size_t, size_t> threeD21 = { 1,2,3 };
	tuple<size_t, size_t, size_t> threeD2{ 1,2,3 };

	auto mak1 = make_tuple("000", 3, 20.00);

	auto val1 = get<0>(mak1);
	auto val2 = get<1>(mak1);
	auto val3 = get<2>(mak1);
	cout << val1 << " " << val2 << " " << val3 << endl;
	get<2>(mak1) *= 0.8;
	cout << val3 << endl;
	cout << get<2>(mak1) << endl;

	typedef decltype(mak1) trans;
	size_t sz = tuple_size<trans>::value;
	tuple_element<1, trans>::type cnt = get<2>(mak1);
	cout << sz << endl;
	cout << cnt << endl;

	// 关系
	tuple<string, string> duo("1", "2");
	tuple<size_t, size_t> twoD(1, 2);
	//bool b = (duo == twoD);
	/*tuple<size_t, size_t, size_t> threeD2();*/
	//bool b = (twoD < threeD);
	tuple<size_t, size_t> twoD2(0, 0);
	bool b = (twoD < twoD2);
	cout << b << endl;
	bool b1 = twoD2 < twoD;
	cout << b1 << endl;

	tuple<int, int, int> t1{ 10,20,30 };
	tuple < string, vector<string>, pair<string, int>> t2{
		"adf",{"asdf","sdf","zxcv"},{"asdf",1}
	};
	cout << "---" << endl;
	ifstream ifs("12.3.1文本查询程序设计.txt");
	TexTQuery tq(ifs);
	string words;
	while (cin >> words && words != "q") {
		print(cout, tq.query(words)) << endl;
	}
	/*
	练习：
	17.1:ok
	17.2:ok
	17.3:ok,tuple简单，不用一个类但是可读性差
	*/
	cin >> a;
	return 0;
}


